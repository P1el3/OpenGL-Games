#include "lab_m1/Tema2/tema2.h"
#include <lab_m1/Tema2/cameraman.h>
#include "lab_m1/Tema2/obiect3D.h"

#include <vector>
#include <string>
#include <iostream>


using namespace std;
using namespace m1;


/*
 *  To find out more about `FrameStart`, `Update`, `FrameEnd`
 *  and the order in which they are called, see `world.cpp`.
 */


Tema2::Tema2()
{
}


Tema2::~Tema2()
{
}


void Tema2::Init()
{
    {
        pct =
        {
            glm::vec3(8.91,0,38.55),
            glm::vec3(20,0,43.54),
            glm::vec3(28.04,0,50.75),
            glm::vec3(37.19,0,61.84),
            glm::vec3(48.01,0,69.89),
            glm::vec3(63.53,0,74.88),
            glm::vec3(84.33,0,74.88),
            glm::vec3(101.52,0,68.78),
            glm::vec3(112.06,0,57.13),
            glm::vec3(120,0,40),
            glm::vec3(120.1,0,23.3),
            glm::vec3(118.72,0,2.78),
            glm::vec3(108.46,0,-9.15),
            glm::vec3(100,0,-20),
            glm::vec3(89.05,0,-27.45),
            glm::vec3(72.96,0,-33.83),
            glm::vec3(56.88,0,-38.82),
            glm::vec3(41.63,0,-42.98),
            glm::vec3(24.43,0,-45.2),
            glm::vec3(7.24,0,-46.03),
            glm::vec3(-18.27,0,-43.81),
            glm::vec3(-36.02,0,-43.25),
            glm::vec3(-51.55,0,-34.66),
            glm::vec3(-66.8,0,-27.17),
            glm::vec3(-80,0,-20),
            glm::vec3(-88.71,0,-8.59),
            glm::vec3(-93.42,0,9.16),
            glm::vec3(-95.64,0,22.74),
            glm::vec3(-94.81,0,36.06),
            glm::vec3(-92.03,0,47.98),
            glm::vec3(-83.44,0,59.35),
            glm::vec3(-72.07,0,68.22),
            glm::vec3(-59.87,0,71.55),
            glm::vec3(-46.83,0,70.72),
            glm::vec3(-37.13,0,61.57),
            glm::vec3(-25.2,0,51.03),
            glm::vec3(-14.94,0,42.16),
            glm::vec3(-4.41,0,37.44),
        };
    }
    glm::vec3 center = glm::vec3(0, 0, 0);
    glm::vec3 above_center = glm::vec3(0, 0.5f, 0);
    glm::vec3 camera_pos = glm::vec3(0.1f, 5.5, 0);
    enemy_car_pos = glm::vec3(0,0.5f,0);
    enemy_car_pos1 = glm::vec3(0,0.5f,0);
    enemy_car_pos2 = glm::vec3(0,0.5f,0);
    enemy_car_pos3 = glm::vec3(0,0.5f,0);
    enemy_car_pos4 = glm::vec3(0,0.5f,0);
    enemy_car_pos5 = glm::vec3(0,0.5f,0);

    count = 0; count1 = 0; count2 = 0; count3 = 0; count4 = 0; count5 = 0;
    speed = 50.0f; accident = 1.0f, crashed = 0;
    rotate_car = 0.0f;
    renderCameraTarget = true;
    state = 1;
    ENEMY_IN = 0; ENEMY_OUT = 1;
    loop = 0;
    
    deplasare = 0;
    

    cameraman = new implemented::Cameraman();
    cameraman->Set(camera_pos, normalize(glm::vec3(1, -0.573f, 0)), normalize(glm::vec3(0.5f, 1, 0)));
    glm::vec3 car_pos = glm::vec3(0, 0, 0);
    //Create the grass
    Mesh* grass = obiect3D::CreateGrass("grass", center, glm::vec3(0.07, 0.9, 0.21), true);
    AddMeshToList(grass);
    //Create the road
    Mesh* road = obiect3D::CreateRoad("road", above_center, glm::vec3(0.36, 0.37, 0.37), true);
    AddMeshToList(road);
    //Create the tree
    Mesh* tree = obiect3D::CreateTree("tree", above_center, glm::vec3(0.27, 0.11, 0.02), glm::vec3(0.02, 0.27, 0.13), true);
    AddMeshToList(tree);
    //Create the car
    Mesh* car = obiect3D::CreateCar("car", car_pos, glm::vec3(0.97, 0.01, 0.93), true);
    AddMeshToList(car);
    //Create the test car
    Mesh* enemy_car = obiect3D::CreateCar("enemy_car", enemy_car_pos, glm::vec3(1, 1, 0), true);
    AddMeshToList(enemy_car);
    //Create the enemy car1
    Mesh* enemy_car1 = obiect3D::CreateCar("enemy_car1", enemy_car_pos1, glm::vec3(1, 1, 0), true);
    AddMeshToList(enemy_car1);
    //Create the enemy car2
    Mesh* enemy_car2 = obiect3D::CreateCar("enemy_car2", enemy_car_pos2, glm::vec3(1, 0, 0), true);
    AddMeshToList(enemy_car2);
    //Create the enemy car3
    Mesh* enemy_car3 = obiect3D::CreateCar("enemy_car3", enemy_car_pos3, glm::vec3(0, 0, 1), true);
    AddMeshToList(enemy_car3);
    //Create the enemy car1
    Mesh* enemy_car4 = obiect3D::CreateCar("enemy_car4", enemy_car_pos4, glm::vec3(1, 0, 1), true);
    AddMeshToList(enemy_car4);
    //Create the enemy car5
    Mesh* enemy_car5 = obiect3D::CreateCar("enemy_car5", enemy_car_pos5, glm::vec3(0, 1, 1), true);
    AddMeshToList(enemy_car5);

    //crete viewport
    glm::ivec2 resolution = window->GetResolution();
    miniViewportArea = ViewportArea(50, 50, resolution.x / 5.f, resolution.y / 5.f);





    // TODO(student): After you implement the changing of the projection
    // parameters, remove hardcodings of these parameters
    projectionMatrix = glm::perspective(RADIANS(60), window->props.aspectRatio, 0.01f, 200.0f);

}


void Tema2::FrameStart()
{
    // Clears the color buffer (using the previously set color) and depth buffer
    glClearColor(0.07, 0.9, 0.86, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glm::ivec2 resolution = window->GetResolution();
    // Sets the screen area where to draw
    glViewport(0, 0, resolution.x, resolution.y);
}

void Tema2::RenderAmbiance() {
    road = glm::mat4(1);
    RenderMesh(meshes["road"], shaders["VertexColor"], road);
    grass = glm::mat4(1);
    RenderMesh(meshes["grass"], shaders["VertexColor"], grass);
    tree = glm::mat4(1);
    tree *= glm::translate(tree, glm::vec3(8.91, 0, 51.05));
    RenderMesh(meshes["tree"], shaders["VertexColor"], tree); {
        tree = glm::mat4(1);
        tree *= glm::translate(tree, glm::vec3(20, 0, 32.04));
        RenderMesh(meshes["tree"], shaders["VertexColor"], tree);
        tree = glm::mat4(1);
        tree *= glm::translate(tree, glm::vec3(48.01, 0, 82.39));
        RenderMesh(meshes["tree"], shaders["VertexColor"], tree);
        tree = glm::mat4(1);
        tree *= glm::translate(tree, glm::vec3(63.53, 0, 59.38));
        RenderMesh(meshes["tree"], shaders["VertexColor"], tree);
        tree = glm::mat4(1);
        tree *= glm::translate(tree, glm::vec3(98.52, 0, 81.28));
        RenderMesh(meshes["tree"], shaders["VertexColor"], tree);
        tree = glm::mat4(1);
        tree *= glm::translate(tree, glm::vec3(92.06, 0, 57.13));
        RenderMesh(meshes["tree"], shaders["VertexColor"], tree);
        tree = glm::mat4(1);
        tree *= glm::translate(tree, glm::vec3(133.1, 0, 43.3));
        RenderMesh(meshes["tree"], shaders["VertexColor"], tree);
        tree = glm::mat4(1);
        tree *= glm::translate(tree, glm::vec3(103.72, 0, 12.78));
        RenderMesh(meshes["tree"], shaders["VertexColor"], tree);
        tree = glm::mat4(1);
        tree *= glm::translate(tree, glm::vec3(124.46, 0, -9.15));
        RenderMesh(meshes["tree"], shaders["VertexColor"], tree);
        tree = glm::mat4(1);
        tree *= glm::translate(tree, glm::vec3(89.05, 0, -12.45));
        RenderMesh(meshes["tree"], shaders["VertexColor"], tree);
        tree = glm::mat4(1);
        tree *= glm::translate(tree, glm::vec3(89.05, 0, -12.45));
        RenderMesh(meshes["tree"], shaders["VertexColor"], tree);
        tree = glm::mat4(1);
        tree *= glm::translate(tree, glm::vec3(69.88, 0, -47.82));
        RenderMesh(meshes["tree"], shaders["VertexColor"], tree);
        tree = glm::mat4(1);
        tree *= glm::translate(tree, glm::vec3(29.43, 0, -30.2));
        RenderMesh(meshes["tree"], shaders["VertexColor"], tree);
        tree = glm::mat4(1);
        tree *= glm::translate(tree, glm::vec3(12.24, 0, -61.03));
        RenderMesh(meshes["tree"], shaders["VertexColor"], tree);
        tree = glm::mat4(1);
        tree *= glm::translate(tree, glm::vec3(-31.02, 0, -28.25));
        RenderMesh(meshes["tree"], shaders["VertexColor"], tree);
        tree = glm::mat4(1);
        tree *= glm::translate(tree, glm::vec3(-51.55, 0, -46.66));
        RenderMesh(meshes["tree"], shaders["VertexColor"], tree);
        tree = glm::mat4(1);
        tree *= glm::translate(tree, glm::vec3(-70, 0, -10));
        RenderMesh(meshes["tree"], shaders["VertexColor"], tree);
        tree = glm::mat4(1);
        tree *= glm::translate(tree, glm::vec3(-103.71, 0, 2.59));
        RenderMesh(meshes["tree"], shaders["VertexColor"], tree);
        tree = glm::mat4(1);
        tree *= glm::translate(tree, glm::vec3(-80.64, 0, 34.74));
        RenderMesh(meshes["tree"], shaders["VertexColor"], tree);
        tree = glm::mat4(1);
        tree *= glm::translate(tree, glm::vec3(-102.03, 0, 49.98));
        RenderMesh(meshes["tree"], shaders["VertexColor"], tree);
        tree = glm::mat4(1);
        tree *= glm::translate(tree, glm::vec3(-80.07, 0, 79.22));
        RenderMesh(meshes["tree"], shaders["VertexColor"], tree);
        tree = glm::mat4(1);
        tree *= glm::translate(tree, glm::vec3(-57.87, 0, 58.55));
        RenderMesh(meshes["tree"], shaders["VertexColor"], tree);
        tree = glm::mat4(1);
        tree *= glm::translate(tree, glm::vec3(-22.13, 0, 65.57));
        RenderMesh(meshes["tree"], shaders["VertexColor"], tree);
        tree = glm::mat4(1);
        tree *= glm::translate(tree, glm::vec3(-14.94, 0, 32.16));
        RenderMesh(meshes["tree"], shaders["VertexColor"], tree);
    }
}

void Tema2::Update(float deltaTimeSeconds)
{
    glm::ivec2 resolution = window->GetResolution();
    glViewport(0, 0, resolution.x, resolution.y);
   
    RenderAmbiance();
    //my car
    {
        float angle = acosf(glm::dot(normalize(glm::vec3(cameraman->forward.x, 0, cameraman->forward.z)), glm::vec3(0, 0, -1)))
            * ((cameraman->right.z < 0) ? 1 : -1);
        angle -= M_PI / 2;
        car = glm::mat4(1);
        car = glm::translate(car, cameraman -> GetTargetPosition()); //asta e pozitia masinii
        car = glm::rotate(car, angle, glm::vec3(0, 1, 0));
        RenderMesh(meshes["car"], shaders["VertexColor"], car);

    }
    //test car
    /* {
        dest_pos = pct[count + 1].position - enemy_car_pos;
        enemy_car_pos += deltaTimeSeconds * speed * 0.5f * normalize(dest_pos); // asta

        enemy_car = glm::mat4(1);
        if (glm::distance(enemy_car_pos, pct[count + 1].position) <= 0.5f) {
            enemy_car_pos = pct[count + 1].position;
            count++;
            if (count >= 37) count = 0;
        }
        float angle_enemy_car = acosf(glm::dot(normalize(glm::vec3(dest_pos.x, 0, dest_pos.z)), glm::vec3(0, 0, -1)))
            * ((dest_pos.x < 0) ? 1 : -1);
        angle_enemy_car -= M_PI / 2;
        enemy_car = glm::translate(enemy_car, enemy_car_pos);
        enemy_car = glm::rotate(enemy_car, angle_enemy_car, glm::vec3(0, 1, 0));
        RenderMesh(meshes["enemy_car"], shaders["VertexColor"], enemy_car);
        if (glm::distance(enemy_car_pos, cameraman->GetTargetPosition()) <= 2) accident = 0;
        if (accident == 0) {
            crashed += deltaTimeSeconds * 0.5f;
            cout << crashed << endl;
            if (crashed > 0.5) {
                accident = 1;
                crashed = 0;
            }
        }
    }*/


    //cout << loop << endl;
    if ( state == ENEMY_IN) {
        //cout << "ALOOOO" << endl;
        loop += 0.005f;
        //enemy car 1
        {
            dest_pos1 = (pct[count1 + 1].position + +glm::vec3(0, 0, 6)) - enemy_car_pos1;
            enemy_car_pos1 += deltaTimeSeconds * speed * 0.5f * normalize(dest_pos1); // asta

            enemy_car1 = glm::mat4(1);
            if (glm::distance(enemy_car_pos1, pct[count1 + 1].position + glm::vec3(0, 0, 6)) <= 0.5f) {
                enemy_car_pos1 = pct[count1 + 1].position + glm::vec3(0, 0, 6);
                count1++;
                if (count1 >= 37) count1 = 0;
            }
            float angle_enemy_car1 = acosf(glm::dot(normalize(glm::vec3(dest_pos1.x, 0, dest_pos1.z)), glm::vec3(0, 0, -1)))
                * ((dest_pos1.x < 0) ? 1 : -1);
            angle_enemy_car1 -= M_PI / 2;


            enemy_car1 = glm::translate(enemy_car1, enemy_car_pos1);
            enemy_car1 = glm::rotate(enemy_car1, angle_enemy_car1, glm::vec3(0, 1, 0));
            RenderMesh(meshes["enemy_car1"], shaders["VertexColor"], enemy_car1);
            if (glm::distance(enemy_car_pos1, cameraman->GetTargetPosition()) <= 2) accident = 0;
            if (accident == 0) {
                crashed += deltaTimeSeconds * 0.5f;
                
                if (crashed > 1) {
                    accident = 1;
                    crashed = 0;
                }
            }
        }
        //enemy car 2
        if (loop > 1) {
            dest_pos2 = (pct[count2 + 1].position + glm::vec3(6, 0, 1)) - enemy_car_pos2;
            enemy_car_pos2 += deltaTimeSeconds * speed * 0.5f * normalize(dest_pos2); // asta

            enemy_car2 = glm::mat4(1);
            if (glm::distance(enemy_car_pos2, (pct[count2 + 1].position + glm::vec3(6, 0, 1))) <= 0.5f) {
                enemy_car_pos2 = pct[count2 + 1].position + glm::vec3(6, 0, 1);
                count2++;
                if (count2 >= 37) count2 = 0;
            }
            float angle_enemy_car2 = acosf(glm::dot(normalize(glm::vec3(dest_pos2.x, 0, dest_pos2.z)), glm::vec3(0, 0, -1)))
                * ((dest_pos2.x < 0) ? 1 : -1);
            angle_enemy_car2 -= M_PI / 2;


            enemy_car2 = glm::translate(enemy_car2, enemy_car_pos2);
            enemy_car2 = glm::rotate(enemy_car2, angle_enemy_car2, glm::vec3(0, 1, 0));
            RenderMesh(meshes["enemy_car2"], shaders["VertexColor"], enemy_car2);
            if (glm::distance(enemy_car_pos2, cameraman->GetTargetPosition()) <= 2) accident = 0;
            if (accident == 0) {
                crashed += deltaTimeSeconds * 0.5f;
                
                if (crashed > 1) {
                    accident = 1;
                    crashed = 0;
                }
            }
        }
        //enemy car 3
        if (loop > 2) {
            dest_pos3 = pct[count3 + 1].position - enemy_car_pos3;
            enemy_car_pos3 += deltaTimeSeconds * speed * 0.5f * normalize(dest_pos3); // asta

            enemy_car3 = glm::mat4(1);
            if (glm::distance(enemy_car_pos3, pct[count3 + 1].position) <= 0.5f) {
                enemy_car_pos3 = pct[count3 + 1].position;
                count3++;
                if (count3 >= 37) count3 = 0;
            }
            float angle_enemy_car3 = acosf(glm::dot(normalize(glm::vec3(dest_pos3.x, 0, dest_pos3.z)), glm::vec3(0, 0, -1)))
                * ((dest_pos3.x < 0) ? 1 : -1);
            angle_enemy_car3 -= M_PI / 2;


            enemy_car3 = glm::translate(enemy_car3, enemy_car_pos3);
            enemy_car3 = glm::rotate(enemy_car3, angle_enemy_car3, glm::vec3(0, 1, 0));
            RenderMesh(meshes["enemy_car3"], shaders["VertexColor"], enemy_car3);
            if (glm::distance(enemy_car_pos3, cameraman->GetTargetPosition()) <= 2) accident = 0;
            if (accident == 0) {
                crashed += deltaTimeSeconds * 0.5f;
                
                if (crashed > 1) {
                    accident = 1;
                    crashed = 0;
                }
            }
        }
        
        //enemy car 4
        if (loop > 3) {

            dest_pos4 = (pct[count4 + 1].position + glm::vec3(2, 0, 4)) - enemy_car_pos4;
            enemy_car_pos4 += deltaTimeSeconds * speed * 0.5f * normalize(dest_pos4); // asta

            enemy_car4 = glm::mat4(1);
            if (glm::distance(enemy_car_pos4, pct[count4 + 1].position + glm::vec3(2, 0, 4)) <= 0.5f) {
                enemy_car_pos4 = pct[count4 + 1].position + glm::vec3(2, 0, 4);
                count4++;
                if (count4 >= 37) count4 = 0;
            }
            float angle_enemy_car4 = acosf(glm::dot(normalize(glm::vec3(dest_pos4.x, 0, dest_pos4.z)), glm::vec3(0, 0, -1)))
                * ((dest_pos4.x < 0) ? 1 : -1);
            angle_enemy_car4 -= M_PI / 2;


            enemy_car4 = glm::translate(enemy_car4, enemy_car_pos4);
            enemy_car4 = glm::rotate(enemy_car4, angle_enemy_car4, glm::vec3(0, 1, 0));
            RenderMesh(meshes["enemy_car4"], shaders["VertexColor"], enemy_car4);
            if (glm::distance(enemy_car_pos4, cameraman->GetTargetPosition()) <= 2) accident = 0;
            if (accident == 0) {
                crashed += deltaTimeSeconds * 0.5f;
                
                if (crashed > 1) {
                    accident = 1;
                    crashed = 0;
                }
            }
        }
        //enemy car 5
        if (loop > 4) {

            dest_pos5 = pct[count5 + 1].position - enemy_car_pos5;
            enemy_car_pos5 += deltaTimeSeconds * speed * 0.5f * normalize(dest_pos5); // asta

            enemy_car5 = glm::mat4(1);
            if (glm::distance(enemy_car_pos5, pct[count5 + 1].position) <= 0.5f) {
                enemy_car_pos5 = pct[count5 + 1].position;
                count5++;
                if (count5 >= 37) count5 = 0;
            }
            float angle_enemy_car5 = acosf(glm::dot(normalize(glm::vec3(dest_pos5.x, 0, dest_pos5.z)), glm::vec3(0, 0, -1)))
                * ((dest_pos5.x < 0) ? 1 : -1);
            angle_enemy_car5 -= M_PI / 2;


            enemy_car5 = glm::translate(enemy_car5, enemy_car_pos5);
            enemy_car5 = glm::rotate(enemy_car5, angle_enemy_car5, glm::vec3(0, 1, 0));
            RenderMesh(meshes["enemy_car5"], shaders["VertexColor"], enemy_car5);
            if (glm::distance(enemy_car_pos5, cameraman->GetTargetPosition()) <= 2) accident = 0;
            if (accident == 0) {
                crashed += deltaTimeSeconds * 0.5f;
               
                if (crashed > 1) {
                    accident = 1;
                    crashed = 0;
                }
            }
        }

    }

    glViewport(miniViewportArea.x, miniViewportArea.y, miniViewportArea.width, miniViewportArea.height);
}


void Tema2::FrameEnd()
{
    DrawCoordinateSystem(cameraman->GetViewMatrix(), projectionMatrix);
}


void Tema2::RenderMesh(Mesh * mesh, Shader * shader, const glm::mat4 & modelMatrix)
{
    if (!mesh || !shader || !shader->program)
        return;

    // Render an object using the specified shader and the specified position
    shader->Use();
    glUniformMatrix4fv(shader->loc_view_matrix, 1, GL_FALSE, glm::value_ptr(cameraman->GetViewMatrix()));
    glUniformMatrix4fv(shader->loc_projection_matrix, 1, GL_FALSE, glm::value_ptr(projectionMatrix));
    glUniformMatrix4fv(shader->loc_model_matrix, 1, GL_FALSE, glm::value_ptr(modelMatrix));

    mesh->Render();
}


/*
 *  These are callback functions. To find more about callbacks and
 *  how they behave, see `input_controller.h`.
 */


void Tema2::OnInputUpdate(float deltaTime, int mods)
{
    // move the camera only if MOUSE_RIGHT button is pressed
    if (window->MouseHold(GLFW_MOUSE_BUTTON_RIGHT))
    {
        float cameraSpeed = 2.0f;
        if (window->KeyHold(GLFW_KEY_W) && accident == 1.0f) {
            cameraman->MoveForward((deltaTime * cameraSpeed + 0.05 + 1));
        }

        if (window->KeyHold(GLFW_KEY_A)) {
            cameraman->RotateThirdPerson_OY(deltaTime * cameraSpeed);
            rotate_car -= deltaTime * cameraSpeed - 0.05 - 1;
            
        }

        if (window->KeyHold(GLFW_KEY_S)) {
            cameraman->MoveForward(-deltaTime * cameraSpeed - 0.05 -1);
           
        }

        if (window->KeyHold(GLFW_KEY_D)) {
            cameraman->RotateThirdPerson_OY(-deltaTime * cameraSpeed);
            rotate_car += deltaTime * cameraSpeed - 0.05 - 1;
        }
        if (window->KeyHold(GLFW_KEY_Q)) {
            cameraman->TranslateUpward(deltaTime * cameraSpeed + 1);
        }
        if (window->KeyHold(GLFW_KEY_E)) {
            cameraman->TranslateUpward(-deltaTime * cameraSpeed - 1);
        }
    
    }

    // TODO(student): Change projection parameters. Declare any extra
    // variables you might need in the class header. Inspect this file
    // for any hardcoded projection arguments (can you find any?) and
    // replace them with those extra variables.

}


void Tema2::OnKeyPress(int key, int mods)
{
    // Add key press event
    if (key == GLFW_KEY_O) {
        cout << key << " " << "CPLM" << endl;
        if (state == ENEMY_IN)
            state = ENEMY_OUT;
        else if (state == ENEMY_OUT){
            state = ENEMY_IN;
            loop = 0;
        }
    }



}


void Tema2::OnKeyRelease(int key, int mods)
{
    // Add key release event
}


void Tema2::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY)
{
    // Add mouse move event
    //if (window->MouseHold(GLFW_MOUSE_BUTTON_RIGHT))
    //{
    //    float sensivityOX = 0.001f;
    //    float sensivityOY = 0.001f;

    //    if (window->GetSpecialKeyState() == 0) {
    //        renderCameraTarget = false;
    //        // TODO(student): Rotate the camera in first-person mode around
    //        // OX and OY using `deltaX` and `deltaY`. Use the sensitivity
    //        // variables for setting up the rotation speed.
    //        cameraman->RotateFirstPerson_OX(-2 * sensivityOX * deltaY);
    //        cameraman->RotateFirstPerson_OY(-2 * sensivityOY * deltaX);
    //    }

    //    if (window->GetSpecialKeyState() & GLFW_MOD_CONTROL) {
    //        renderCameraTarget = true;
    //        // TODO(student): Rotate the camera in third-person mode around
    //        // OX and OY using `deltaX` and `deltaY`. Use the sensitivity
    //        // variables for setting up the rotation speed.
    //        cameraman->RotateThirdPerson_OX(-2 * sensivityOX * deltaY);
    //        cameraman->RotateThirdPerson_OY(-2 * sensivityOY * deltaX);
    //    }

    //}


}


void Tema2::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
{
    // Add mouse button press event
    
}


void Tema2::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
{
    // Add mouse button release event
}


void Tema2::OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY)
{
}


void Tema2::OnWindowResize(int width, int height)
{
}
