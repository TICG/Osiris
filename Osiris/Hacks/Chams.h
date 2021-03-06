#pragma once

#include "../SDK/ModelRender.h"

class Chams {
public:
    Chams() noexcept;
    void render(void*, void*, const ModelRenderInfo&, matrix3x4*) noexcept;
    void renderPlayers(void*, void*, const ModelRenderInfo&, matrix3x4*) noexcept;
    void renderWeapons(int) noexcept;
private:
    Material* normal;
    Material* flat;
};
