#pragma once

#include "components/simple_scene.h"
#include "lab_m1/Tema2/cameraman.h"


namespace m1
{
    class Tema2 : public gfxc::SimpleScene
    {
     public:
         struct ViewportArea
         {
             ViewportArea() : x(0), y(0), width(1), height(1) {}
             ViewportArea(int x, int y, int width, int height)
                 : x(x), y(y), width(width), height(height) {}
             int x;
             int y;
             int width;
             int height;
         };
        Tema2();
        ~Tema2();
        float orthoRight = 8.0f, orthoUp = 4.5f, orthoDown = -4.5f, orthoLeft = -8.0f;
        bool isOrtho = false;

        void Init() override;
     private:
        void FrameStart() override;
        void Update(float deltaTimeSeconds) override;
        void FrameEnd() override;

        void RenderMesh(Mesh *mesh, Shader *shader, const glm::mat4 &modelMatrix) override;

        void OnInputUpdate(float deltaTime, int mods) override;
        void OnKeyPress(int key, int mods) override;
        void OnKeyRelease(int key, int mods) override;
        void OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY) override;
        void OnMouseBtnPress(int mouseX, int mouseY, int button, int mods) override;
        void OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods) override;
        void OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY) override;
        void OnWindowResize(int width, int height) override;
        void RenderScene();
        void RenderAmbiance();
     protected:
        implemented::Cameraman *cameraman;
        glm::mat4 projectionMatrix;
        bool renderCameraTarget;

        ViewportArea miniViewportArea;
        glm::mat4 grass;
        glm::mat4 road;
        glm::mat4 tree;
        glm::mat4 car;
        glm::mat4 enemy_car;
        glm::mat4 enemy_car1;
        glm::mat4 enemy_car2;
        glm::mat4 enemy_car3;
        glm::mat4 enemy_car4;
        glm::mat4 enemy_car5;

        glm::vec3 enemy_car_pos;
        glm::vec3 curent_pos;
        glm::vec3 dest_pos;
        int count;

        glm::vec3 enemy_car_pos1;
        glm::vec3 curent_pos1;
        glm::vec3 dest_pos1;
        int count1;
        glm::vec3 enemy_car_pos2;
        glm::vec3 curent_pos2;
        glm::vec3 dest_pos2;
        int count2;
        glm::vec3 enemy_car_pos3;
        glm::vec3 curent_pos3;
        glm::vec3 dest_pos3;
        int count3;
        glm::vec3 enemy_car_pos4;
        glm::vec3 curent_pos4;
        glm::vec3 dest_pos4;
        int count4;
        glm::vec3 enemy_car_pos5;
        glm::vec3 curent_pos5;
        glm::vec3 dest_pos5;
        int count5;
        
        int state, ENEMY_IN, ENEMY_OUT;
        
        //glm::vec3 curent_pos;
        
        float rotate_car, speed,deplasare, loop, accident, crashed;
       
        std::vector<VertexFormat> pct;
        
    };
}   // namespace m1
