#include <fstream>
#include <ShlObj.h>

#include "json/json.h"

#include "Config.h"

Config::Config(const std::string_view name)
{
    PWSTR pathToDocuments;
    if (SUCCEEDED(SHGetKnownFolderPath(FOLDERID_Documents, 0, NULL, &pathToDocuments))) {
        path = pathToDocuments;
        path /= name;
        CoTaskMemFree(pathToDocuments);
    }
    load();
}

void Config::load()
{
    std::ifstream in{ path };

    if (!in.is_open())
        return;

    Json::Value config;
    in >> config;
    in.close();

    aimbot.enabled = config["aimbot"]["enabled"].asBool();
    aimbot.silent = config["aimbot"]["silent"].asBool();
    aimbot.fov = config["aimbot"]["fov"].asFloat();
    aimbot.smooth = config["aimbot"]["smooth"].asFloat();

    triggerbot.enabled = config["triggerbot"]["enabled"].asBool();
    triggerbot.onKey = config["triggerbot"]["onKey"].asBool();
    triggerbot.key = config["triggerbot"]["key"].asInt();
    triggerbot.shotDelay = config["triggerbot"]["shotDelay"].asInt();

    glow.enabled = config["glow"]["enabled"].asBool();
    glow.thickness = config["glow"]["thickness"].asFloat();
    glow.alpha = config["glow"]["alpha"].asFloat();
    glow.style = config["glow"]["style"].asInt();

    glow.allies = config["glow"]["allies"].asBool();
    glow.alliesColor[0] = config["glow"]["alliesColor"][0].asFloat();
    glow.alliesColor[1] = config["glow"]["alliesColor"][1].asFloat();
    glow.alliesColor[2] = config["glow"]["alliesColor"][2].asFloat();

    glow.enemies = config["glow"]["enemies"].asBool();
    glow.enemiesColor[0] = config["glow"]["enemiesColor"][0].asFloat();
    glow.enemiesColor[1] = config["glow"]["enemiesColor"][1].asFloat();
    glow.enemiesColor[2] = config["glow"]["enemiesColor"][2].asFloat();

    glow.weapons = config["glow"]["weapons"].asBool();
    glow.weaponsColor[0] = config["glow"]["weaponsColor"][0].asFloat();
    glow.weaponsColor[1] = config["glow"]["weaponsColor"][1].asFloat();
    glow.weaponsColor[2] = config["glow"]["weaponsColor"][2].asFloat();

    glow.C4 = config["glow"]["C4"].asBool();
    glow.C4Color[0] = config["glow"]["C4Color"][0].asFloat();
    glow.C4Color[1] = config["glow"]["C4Color"][1].asFloat();
    glow.C4Color[2] = config["glow"]["C4Color"][2].asFloat();

    glow.plantedC4 = config["glow"]["plantedC4"].asBool();
    glow.plantedC4Color[0] = config["glow"]["plantedC4Color"][0].asFloat();
    glow.plantedC4Color[1] = config["glow"]["plantedC4Color"][1].asFloat();
    glow.plantedC4Color[2] = config["glow"]["plantedC4Color"][2].asFloat();

    glow.chickens = config["glow"]["chickens"].asBool();
    glow.chickensColor[0] = config["glow"]["chickensColor"][0].asFloat();
    glow.chickensColor[1] = config["glow"]["chickensColor"][1].asFloat();
    glow.chickensColor[2] = config["glow"]["chickensColor"][2].asFloat();

    chams.enabled = config["chams"]["enabled"].asBool();
    chams.alpha = config["chams"]["alpha"].asFloat();
    chams.flat = config["chams"]["flat"].asBool();
    chams.wireframe = config["chams"]["wireframe"].asBool();

    chams.visibleAllies = config["chams"]["visibleAllies"].asBool();
    chams.visibleAlliesColor[0] = config["chams"]["visibleAlliesColor"][0].asFloat();
    chams.visibleAlliesColor[1] = config["chams"]["visibleAlliesColor"][1].asFloat();
    chams.visibleAlliesColor[2] = config["chams"]["visibleAlliesColor"][2].asFloat();

    chams.occludedAllies = config["chams"]["occludedAllies"].asBool();
    chams.occludedAlliesColor[0] = config["chams"]["occludedAlliesColor"][0].asFloat();
    chams.occludedAlliesColor[1] = config["chams"]["occludedAlliesColor"][1].asFloat();
    chams.occludedAlliesColor[2] = config["chams"]["occludedAlliesColor"][2].asFloat();

    chams.occludedEnemies = config["chams"]["occludedEnemies"].asBool();
    chams.occludedEnemiesColor[0] = config["chams"]["occludedEnemiesColor"][0].asFloat();
    chams.occludedEnemiesColor[1] = config["chams"]["occludedEnemiesColor"][1].asFloat();
    chams.occludedEnemiesColor[2] = config["chams"]["occludedEnemiesColor"][2].asFloat();

    chams.visibleEnemies = config["chams"]["visibleEnemies"].asBool();
    chams.visibleEnemiesColor[0] = config["chams"]["visibleEnemiesColor"][0].asFloat();
    chams.visibleEnemiesColor[1] = config["chams"]["visibleEnemiesColor"][1].asFloat();
    chams.visibleEnemiesColor[2] = config["chams"]["visibleEnemiesColor"][2].asFloat();

    misc.bunnyHop = config["misc"]["bunnyHop"].asBool();
    misc.clanTag = config["misc"]["clanTag"].asString();
    misc.disablePostProcessing = config["misc"]["disablePostProcessing"].asBool();
    misc.flashReduction = config["misc"]["flashReduction"].asInt();
    misc.inverseRagdollGravity = config["misc"]["inverseRagdollGravity"].asBool();
    misc.fastDuck = config["misc"]["fastDuck"].asBool();
    misc.noSmoke = config["misc"]["noSmoke"].asBool();
    misc.wireframeSmoke = config["misc"]["wireframeSmoke"].asBool();
    misc.skybox = config["misc"]["skybox"].asInt();
    misc.viewmodelFov = config["misc"]["viewmodelFov"].asInt();
    misc.worldColor[0] = config["misc"]["worldColor"][0].asFloat();
    misc.worldColor[1] = config["misc"]["worldColor"][1].asFloat();
    misc.worldColor[2] = config["misc"]["worldColor"][2].asFloat();
    misc.autoPistol = config["misc"]["autoPistol"].asBool();
}

void Config::save() const
{
    Json::Value config;

    config["aimbot"]["enabled"] = aimbot.enabled;
    config["aimbot"]["silent"] = aimbot.silent;
    config["aimbot"]["fov"] = aimbot.fov;
    config["aimbot"]["smooth"] = aimbot.smooth;

    config["triggerbot"]["enabled"] = triggerbot.enabled;
    config["triggerbot"]["onKey"] = triggerbot.onKey;
    config["triggerbot"]["key"] = triggerbot.key;
    config["triggerbot"]["shotDelay"] = triggerbot.shotDelay;

    config["glow"]["enabled"] = glow.enabled;
    config["glow"]["thickness"] = glow.thickness;
    config["glow"]["alpha"] = glow.alpha;
    config["glow"]["style"] = glow.style;

    config["glow"]["allies"] = glow.allies;
    config["glow"]["alliesColor"][0] = glow.alliesColor[0];
    config["glow"]["alliesColor"][1] = glow.alliesColor[1];
    config["glow"]["alliesColor"][2] = glow.alliesColor[2];

    config["glow"]["enemies"] = glow.enemies;
    config["glow"]["enemiesColor"][0] = glow.enemiesColor[0];
    config["glow"]["enemiesColor"][1] = glow.enemiesColor[1];
    config["glow"]["enemiesColor"][2] = glow.enemiesColor[2];

    config["glow"]["weapons"] = glow.weapons;
    config["glow"]["weaponsColor"][0] = glow.weaponsColor[0];
    config["glow"]["weaponsColor"][1] = glow.weaponsColor[1];
    config["glow"]["weaponsColor"][2] = glow.weaponsColor[2];

    config["glow"]["C4"] = glow.C4;
    config["glow"]["C4Color"][0] = glow.C4Color[0];
    config["glow"]["C4Color"][1] = glow.C4Color[1];
    config["glow"]["C4Color"][2] = glow.C4Color[2];

    config["glow"]["plantedC4"] = glow.plantedC4;
    config["glow"]["plantedC4Color"][0] = glow.plantedC4Color[0];
    config["glow"]["plantedC4Color"][1] = glow.plantedC4Color[1];
    config["glow"]["plantedC4Color"][2] = glow.plantedC4Color[2];

    config["glow"]["chickens"] = glow.chickens;
    config["glow"]["chickensColor"][0] = glow.chickensColor[0];
    config["glow"]["chickensColor"][1] = glow.chickensColor[1];
    config["glow"]["chickensColor"][2] = glow.chickensColor[2];

    config["chams"]["enabled"] = chams.enabled;
    config["chams"]["alpha"] = chams.alpha;
    config["chams"]["flat"] = chams.flat;
    config["chams"]["wireframe"] = chams.wireframe;

    config["chams"]["visibleAllies"] = chams.visibleAllies;
    config["chams"]["visibleAlliesColor"][0] = chams.visibleAlliesColor[0];
    config["chams"]["visibleAlliesColor"][1] = chams.visibleAlliesColor[1];
    config["chams"]["visibleAlliesColor"][2] = chams.visibleAlliesColor[2];

    config["chams"]["occludedAllies"] = chams.occludedAllies;
    config["chams"]["occludedAlliesColor"][0] = chams.occludedAlliesColor[0];
    config["chams"]["occludedAlliesColor"][1] = chams.occludedAlliesColor[1];
    config["chams"]["occludedAlliesColor"][2] = chams.occludedAlliesColor[2];

    config["chams"]["visibleEnemies"] = chams.visibleEnemies;
    config["chams"]["visibleEnemiesColor"][0] = chams.visibleEnemiesColor[0];
    config["chams"]["visibleEnemiesColor"][1] = chams.visibleEnemiesColor[1];
    config["chams"]["visibleEnemiesColor"][2] = chams.visibleEnemiesColor[2];

    config["chams"]["occludedEnemies"] = chams.occludedEnemies;
    config["chams"]["occludedEnemiesColor"][0] = chams.occludedEnemiesColor[0];
    config["chams"]["occludedEnemiesColor"][1] = chams.occludedEnemiesColor[1];
    config["chams"]["occludedEnemiesColor"][2] = chams.occludedEnemiesColor[2];

    config["misc"]["bunnyHop"] = misc.bunnyHop;
    config["misc"]["clanTag"] = misc.clanTag;
    config["misc"]["disablePostProcessing"] = misc.disablePostProcessing;
    config["misc"]["flashReduction"] = misc.flashReduction;
    config["misc"]["inverseRagdollGravity"] = misc.inverseRagdollGravity;
    config["misc"]["fastDuck"] = misc.fastDuck;
    config["misc"]["noSmoke"] = misc.noSmoke;
    config["misc"]["wireframeSmoke"] = misc.wireframeSmoke;
    config["misc"]["skybox"] = misc.skybox;
    config["misc"]["viewmodelFov"] = misc.viewmodelFov;
    config["misc"]["worldColor"][0] = misc.worldColor[0];
    config["misc"]["worldColor"][1] = misc.worldColor[1];
    config["misc"]["worldColor"][2] = misc.worldColor[2];
    config["misc"]["autoPistol"] = misc.autoPistol;

    std::ofstream{ path } << config;
}

void Config::reset()
{
    aimbot.enabled = false;
    aimbot.silent = false;
    aimbot.fov = 0.0f;
    aimbot.smooth = 1.0f;

    triggerbot.enabled = false;
    triggerbot.onKey = false;
    triggerbot.key = 0;
    triggerbot.shotDelay = 0;

    glow.enabled = false;
    glow.thickness = 1.0f;
    glow.alpha = 1.0f;
    glow.style = 0;

    glow.allies = false;
    glow.alliesColor[0] = 0.0f;
    glow.alliesColor[1] = 1.0f;
    glow.alliesColor[2] = 0.0f;

    glow.enemies = false;
    glow.enemiesColor[0] = 1.0f;
    glow.enemiesColor[1] = 0.0f;
    glow.enemiesColor[2] = 0.0f;

    glow.weapons = false;
    glow.weaponsColor[0] = 1.0f;
    glow.weaponsColor[1] = 1.0f;
    glow.weaponsColor[2] = 1.0f;

    glow.C4 = false;
    glow.C4Color[0] = 1.0f;
    glow.C4Color[1] = 1.0f;
    glow.C4Color[2] = 0.0f;

    glow.plantedC4 = false;
    glow.plantedC4Color[0] = 1.0f;
    glow.plantedC4Color[1] = 0.27f;
    glow.plantedC4Color[2] = 0.0f;

    glow.chickens = false;
    glow.chickensColor[0] = 1.0f;
    glow.chickensColor[1] = 0.08f;
    glow.chickensColor[2] = 0.58f;

    chams.enabled = false;
    chams.alpha = 1.0f;
    chams.flat = false;
    chams.wireframe = false;

    chams.visibleAllies = false;
    chams.visibleAlliesColor[0] = 0.0f;
    chams.visibleAlliesColor[1] = 1.0f;
    chams.visibleAlliesColor[2] = 0.0f;

    chams.occludedAllies = false;
    chams.occludedAlliesColor[0] = 0.0f;
    chams.occludedAlliesColor[1] = 1.0f;
    chams.occludedAlliesColor[2] = 0.0f;

    chams.visibleEnemies = false;
    chams.visibleEnemiesColor[0] = 1.0f;
    chams.visibleEnemiesColor[1] = 0.0f;
    chams.visibleEnemiesColor[2] = 0.0f;

    chams.occludedEnemies = false;
    chams.occludedEnemiesColor[0] = 1.0f;
    chams.occludedEnemiesColor[1] = 0.0f;
    chams.occludedEnemiesColor[2] = 0.0f;

    misc.bunnyHop = false;
    misc.clanTag = "";
    misc.disablePostProcessing = false;
    misc.flashReduction = 0;
    misc.inverseRagdollGravity = false;
    misc.fastDuck = false;
    misc.noSmoke = false;
    misc.wireframeSmoke = false;
    misc.skybox = 0;
    misc.viewmodelFov = 0;
    misc.worldColor[0] = 0.0f;
    misc.worldColor[1] = 0.0f;
    misc.worldColor[2] = 0.0f;
    misc.autoPistol = false;
};
