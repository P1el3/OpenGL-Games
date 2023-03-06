#pragma once

#include "components/simple_scene.h"
#define KILLED 0
#define ALIVE 1
#define ESCAPE 2
#define WINNER 3

namespace m1
{
    class Tema1 : public gfxc::SimpleScene
    {
    public:
        Tema1();
        ~Tema1();

        void Init() override;

    private:
        void FrameStart() override;
        void Update(float deltaTimeSeconds) override;
        void FrameEnd() override;

        void OnInputUpdate(float deltaTime, int mods) override;
        void OnKeyPress(int key, int mods) override;
        void OnKeyRelease(int key, int mods) override;
        void OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY) override;
        void OnMouseBtnPress(int mouseX, int mouseY, int button, int mods) override;
        void OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods) override;
        void OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY) override;
        void OnWindowResize(int width, int height) override;

    protected:
        float cx, cy;
        glm::mat3 modelMatrix;
        glm::mat3 modelMatrix2;
        glm::mat3 modelMatrix3;
        glm::mat3 score;
        glm::mat3 heart;
        glm::mat3 bullet;
        glm::mat3 gameOver;

        glm::ivec2 resolution;
        float duck_posX, duck_posY, duck_angle;

        float eye_posX, eye_posY;

        float head_posX, head_posY;

        float beak_posX, beak_posY;

        float body_posX, body_posY;
        
        float wing_posX, wing_posY;

        float feet_posX, feet_posY;

        float mouse_posX, mouse_posY;

        float hit_BoxX, hit_BoxY;
        
        int state, speed, speed_stop, no_lives, no_bullets, your_score;
        float timer, duck_escape, respawn, magic;
        float angularStep;
        float rotate;

        float auxX, auxY;
        

    };
}   // namespace m1
