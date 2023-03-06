#include "lab_m1/Tema1/tema1.h"

#include <vector>
#include <iostream>

#include "lab_m1/Tema1/transform2D.h"
#include "lab_m1/Tema1/obiect2D.h"

using namespace std;
using namespace m1;


/*
 *  To find out more about `FrameStart`, `Update`, `FrameEnd`
 *  and the order in which they are called, see `world.cpp`.
 */


Tema1::Tema1()
{
}


Tema1::~Tema1()
{
}


void Tema1::Init()
{
    resolution = window->GetResolution();
    auto camera = GetSceneCamera();
    camera->SetOrthographic(0, (float)resolution.x, 0, (float)resolution.y, 0.01f, 400);
    camera->SetPosition(glm::vec3(0, 0, 50));
    camera->SetRotation(glm::vec3(0, 0, 0));
    camera->Update();
    GetCameraInput()->SetActive(false);

    glm::vec3 corner = glm::vec3(0, 0, 0);
    float squareSide = 100;
    float bodySide = 69;
    float circleRadius = 30;
    float beakSide = 15;
    float wingSide = 34;
    float irisSide = 3.75;
    float pupilSide = 7.5;
    float feetSide = 7.5;
    float hitBoxSide = 69;//90;

    //duck direction & position
    int random = rand() % 10;
    if (random <= 5)
        duck_posX = -25 + (std::rand() % (1080 + 25 + 1));
    else
        duck_posX = rand() % 360;
    
    duck_posY = 0;

    duck_angle = static_cast <float> (rand()) / static_cast <float> (15.5);
    //body positions
    eye_posX = 80, eye_posY = 25.5;

    body_posX = -34.5; body_posY = -110.78f;

    beak_posX = 35; beak_posY = 135;

    head_posX = 10; head_posY = -10;

    wing_posX = 34.5; wing_posY = 34.5;

    feet_posX = 10; feet_posY = -145;

    hit_BoxX = 17.5, hit_BoxY = 85;

    rotate = 0;
    
    //variables
    speed = 500; 
    speed_stop = 1;
    timer = 0; duck_escape = 0, respawn = 0;;
    state = ALIVE;
    no_bullets = 3;
    no_lives = 3;
    your_score = 1;
    magic = 0;
    // Initialize angularStep
    angularStep = 0;


    //Create the shapes for the body.
    Mesh* iris = obiect2D::CreateCircle("iris", corner, irisSide, glm::vec3(0, 0, 0), true);
    AddMeshToList(iris);
    Mesh* pupil = obiect2D::CreateCircle("pupil", corner, pupilSide, glm::vec3(1, 1, 1), true);
    AddMeshToList(pupil);
    Mesh* head = obiect2D::CreateCircle("head", corner, circleRadius, glm::vec3(0.11, 0.44, 0.18), true);
    AddMeshToList(head);
    Mesh* beak = obiect2D::CreateTriangle("beak", corner, beakSide, glm::vec3(0.84, 0.59, 0.04), true);
    AddMeshToList(beak);
    Mesh* body = obiect2D::CreateTriangle("body", corner, bodySide, glm::vec3(0.11, 0.44, 0.18), true);
    AddMeshToList(body);    
    Mesh* wing1 = obiect2D::CreateTriangle("wing1", corner, wingSide, glm::vec3(0.11, 0.44, 0.18), true);
    AddMeshToList(wing1);
    Mesh* wing2 = obiect2D::CreateTriangle("wing2", corner, wingSide, glm::vec3(0.11, 0.44, 0.18), true);
    AddMeshToList(wing2);
    Mesh* feet = obiect2D::CreateTriangle("feet", corner, feetSide, glm::vec3(0.84, 0.59, 0.04), true);
    AddMeshToList(feet);

    //Creeating the gras from where the monster appear
    Mesh* grass = obiect2D::CreateRectangle("grass", corner, resolution.x,100, glm::vec3(0.33, 0.74, 0.29),true);
    AddMeshToList(grass);

    //Creating the scoreboard
    Mesh* score_board = obiect2D::CreateRectangle("score_board",corner,  201, 50, glm::vec3(1, 1, 1), false);
    AddMeshToList(score_board);
    Mesh* score_board1 = obiect2D::CreateRectangle("score_board1", corner, 9, 48, glm::vec3(1, 0, 0), true);
    AddMeshToList(score_board1);

    //Creating the heart for the lives
    Mesh* heart1 = obiect2D::CreateCircle("heart1", corner, 10, glm::vec3(1, 0, 0), true);
    AddMeshToList(heart1);
    Mesh* heart2 = obiect2D::CreateHeart("heart2", corner, 30, glm::vec3(1, 0, 0), true);
    AddMeshToList(heart2);
    //Creating the shapes for the bullets
    Mesh* bullet1 = obiect2D::CreateRectangle("bullet1", corner, 25, 40, glm::vec3(0.82, 0.65, 0.04), true);
    AddMeshToList(bullet1);
    Mesh* bullet2 = obiect2D::CreateBullet("bullet2", corner, 20, 25, glm::vec3(0.82, 0.65, 0.04), true);
    AddMeshToList(bullet2);

    //Creating game over screen
    Mesh* game_over1 = obiect2D::CreateRectangle("game_over1", corner, 30, 100, glm::vec3(1, 0, 0), true);
    AddMeshToList(game_over1);
    Mesh* game_over2 = obiect2D::CreateRectangle("game_over2", corner, 50, 30, glm::vec3(1, 0, 0), true);
    AddMeshToList(game_over2);
    Mesh* game_over3 = obiect2D::CreateRectangle("game_over3", corner, 15, 40, glm::vec3(1, 0, 0), true);
    AddMeshToList(game_over3);
    Mesh* game_over4 = obiect2D::CreateRectangle("game_over4", corner, 10, 60, glm::vec3(1, 0, 0), true);
    AddMeshToList(game_over4);
    Mesh* game_over5 = obiect2D::CreateRectangle("game_over5", corner, 30, 130, glm::vec3(1, 0, 0), true);
    AddMeshToList(game_over5);
    Mesh* game_over6 = obiect2D::CreateRectangle("game_over6", corner, 30, 60, glm::vec3(1, 0, 0), true);
    AddMeshToList(game_over6);
    Mesh* game_over7 = obiect2D::CreateRectangle("game_over7", corner, 30, 25, glm::vec3(1, 0, 0), true);
    AddMeshToList(game_over7);
    //Creating gg screen
    Mesh* gg = obiect2D::CreateRectangle("gg", corner, 30, 90, glm::vec3(1, 0, 0), true);
    AddMeshToList(gg);
}


void Tema1::FrameStart()
{
    // Clears the color buffer (using the previously set color) and depth buffer
    glClearColor(0.2, 0.79, 0.79, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glm::ivec2 resolution = window->GetResolution();
    // Sets the screen area where to draw
    glViewport(0, 0, resolution.x, resolution.y);
}


void Tema1::Update(float deltaTimeSeconds)
{



    if (no_lives >= 1) {
        heart = glm::mat3(1);
        heart *= transform2D::Translate(15, resolution.y - 25);
        RenderMesh2D(meshes["heart1"], shaders["VertexColor"], heart);
        heart *= transform2D::Translate(15, 0);
        RenderMesh2D(meshes["heart1"], shaders["VertexColor"], heart);
        heart *= transform2D::Scale(1, -1);
        heart *= transform2D::Translate(-22.5, 6);
        RenderMesh2D(meshes["heart2"], shaders["VertexColor"], heart);
    }
    if (no_lives >= 2) {
        heart = glm::mat3(1);
        heart *= transform2D::Translate(55, resolution.y - 25);
        RenderMesh2D(meshes["heart1"], shaders["VertexColor"], heart);
        heart *= transform2D::Translate(15, 0);
        RenderMesh2D(meshes["heart1"], shaders["VertexColor"], heart);
        heart *= transform2D::Scale(1, -1);
        heart *= transform2D::Translate(-22.5, 6);
        RenderMesh2D(meshes["heart2"], shaders["VertexColor"], heart);
    }
    if (no_lives == 3) {
        heart = glm::mat3(1);
        heart *= transform2D::Translate(95, resolution.y - 25);
        RenderMesh2D(meshes["heart1"], shaders["VertexColor"], heart);
        heart *= transform2D::Translate(15, 0);
        RenderMesh2D(meshes["heart1"], shaders["VertexColor"], heart);
        heart *= transform2D::Scale(1, -1);
        heart *= transform2D::Translate(-22.5, 6);
        RenderMesh2D(meshes["heart2"], shaders["VertexColor"], heart);
    }

    if (no_bullets >= 1) {
    bullet = glm::mat3(1);
    bullet *= transform2D::Translate(10, resolution.y - 115);
    RenderMesh2D(meshes["bullet1"], shaders["VertexColor"], bullet);
    bullet *= transform2D::Translate(0, 40);
    RenderMesh2D(meshes["bullet2"], shaders["VertexColor"], bullet);
    }
    if (no_bullets >= 2) {
        bullet = glm::mat3(1);
        bullet *= transform2D::Translate(50, resolution.y - 115);
        RenderMesh2D(meshes["bullet1"], shaders["VertexColor"], bullet);
        bullet *= transform2D::Translate(0, 40);
        RenderMesh2D(meshes["bullet2"], shaders["VertexColor"], bullet);
    }
    if (no_bullets == 3) {
        bullet = glm::mat3(1);
        bullet *= transform2D::Translate(90, resolution.y - 115);
        RenderMesh2D(meshes["bullet1"], shaders["VertexColor"], bullet);
        bullet *= transform2D::Translate(0, 40);
        RenderMesh2D(meshes["bullet2"], shaders["VertexColor"], bullet);
    }

    score = glm::mat3(1);
    score *= transform2D::Translate(resolution.x - 225, resolution.y - 75);
    RenderMesh2D(meshes["score_board"], shaders["VertexColor"], score);
    score *= transform2D::Translate(1, 1);
    score *= transform2D::Scale(your_score, 1);       
    RenderMesh2D(meshes["score_board1"], shaders["VertexColor"], score);

    if (state == WINNER) {
        magic += deltaTimeSeconds;
        if (magic > 0.5) {
            gameOver = glm::mat3(1);
            gameOver *= transform2D::Translate(resolution.x / 2 - 200, 300);
            RenderMesh2D(meshes["game_over1"], shaders["VertexColor"], gameOver);
            gameOver *= transform2D::Rotate(-M_PI_2);
            gameOver *= transform2D::Translate(0, 0);
            RenderMesh2D(meshes["game_over1"], shaders["VertexColor"], gameOver);
            gameOver *= transform2D::Translate(30, 70);
            gameOver *= transform2D::Rotate(M_PI_2);
            RenderMesh2D(meshes["game_over6"], shaders["VertexColor"], gameOver);
            gameOver *= transform2D::Translate(30, 50);
            gameOver *= transform2D::Rotate(M_PI_2);
            RenderMesh2D(meshes["game_over6"], shaders["VertexColor"], gameOver);
            gameOver *= transform2D::Translate(50, 0);
            RenderMesh2D(meshes["game_over1"], shaders["VertexColor"], gameOver);

            gameOver = glm::mat3(1);
            gameOver *= transform2D::Translate(resolution.x / 2 - 70, 300);
            RenderMesh2D(meshes["game_over1"], shaders["VertexColor"], gameOver);
            gameOver *= transform2D::Rotate(-M_PI_2);
            gameOver *= transform2D::Translate(0, 0);
            RenderMesh2D(meshes["game_over1"], shaders["VertexColor"], gameOver);
            gameOver *= transform2D::Translate(30, 70);
            gameOver *= transform2D::Rotate(M_PI_2);
            RenderMesh2D(meshes["game_over6"], shaders["VertexColor"], gameOver);
            gameOver *= transform2D::Translate(30, 50);
            gameOver *= transform2D::Rotate(M_PI_2);
            RenderMesh2D(meshes["game_over6"], shaders["VertexColor"], gameOver);
            gameOver *= transform2D::Translate(50, 0);
            RenderMesh2D(meshes["game_over1"], shaders["VertexColor"], gameOver);

            gameOver = glm::mat3(1);
            gameOver *= transform2D::Translate(resolution.x / 2 + 60, 310);
            RenderMesh2D(meshes["gg"], shaders["VertexColor"], gameOver);
            gameOver *= transform2D::Translate(0, -40);
            RenderMesh2D(meshes["game_over7"], shaders["VertexColor"], gameOver);

            if (magic > 1) magic = 0;
        }
    }

    if (no_lives > 0 && state != WINNER) {
        duck_posX += -sin(duck_angle) * deltaTimeSeconds * speed * speed_stop;
        duck_posY += cos(duck_angle) * deltaTimeSeconds * speed * speed_stop;

        if (duck_posX < 0) {
            duck_angle = -duck_angle;
            duck_posX = 0;
        }
        if (duck_posX > resolution.x) {
            duck_angle = -duck_angle;
            duck_posX = resolution.x;
        }
        if (duck_posY < 0) {
            duck_angle = M_PI - duck_angle;
            duck_posY = 0;
        }
        if (duck_posY > resolution.y && state != ESCAPE) {
            duck_angle = M_PI - duck_angle;
            duck_posY = resolution.y;
        }

        modelMatrix = glm::mat3(1);
        RenderMesh(meshes["grass"], shaders["VertexColor"], modelMatrix);

        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(eye_posX + duck_posX, eye_posY + duck_posY);
        modelMatrix *= transform2D::Rotate(duck_angle);
        RenderMesh2D(meshes["iris"], shaders["VertexColor"], modelMatrix);
        RenderMesh2D(meshes["pupil"], shaders["VertexColor"], modelMatrix);

        modelMatrix *= transform2D::Translate(head_posX, head_posY);
        RenderMesh2D(meshes["head"], shaders["VertexColor"], modelMatrix);

        modelMatrix *= transform2D::Translate(body_posX, body_posY);
        RenderMesh2D(meshes["body"], shaders["VertexColor"], modelMatrix);
        rotate += deltaTimeSeconds;

        if (rotate > 0.5f) rotate = -0.25f;

        modelMatrix2 = modelMatrix;
        modelMatrix3 = modelMatrix;

        modelMatrix2 *= transform2D::Translate(wing_posX, wing_posY);
        modelMatrix2 *= transform2D::Rotate(M_PI_2 + rotate);
        RenderMesh2D(meshes["wing1"], shaders["VertexColor"], modelMatrix2);

        modelMatrix3 *= transform2D::Scale(-1, 1);
        modelMatrix3 *= transform2D::Translate(wing_posX - 68, wing_posY);
        modelMatrix3 *= transform2D::Rotate(M_PI_2 + rotate);
        RenderMesh2D(meshes["wing2"], shaders["VertexColor"], modelMatrix3);

        modelMatrix *= transform2D::Translate(beak_posX, beak_posY);
        RenderMesh2D(meshes["beak"], shaders["VertexColor"], modelMatrix);

        modelMatrix *= transform2D::Translate(feet_posX, feet_posY);
        RenderMesh2D(meshes["feet"], shaders["VertexColor"], modelMatrix);

        modelMatrix *= transform2D::Translate(-27.5f, 0);
        RenderMesh2D(meshes["feet"], shaders["VertexColor"], modelMatrix);

        duck_escape += deltaTimeSeconds;
        if (duck_escape < 5) {
            if (state == KILLED) {
                no_bullets = 3;
                duck_escape = 0;
                if (duck_posY < 1) {//duck is down
                    speed_stop = 0;
                    duck_angle = 0;
                    timer += deltaTimeSeconds;

                    if (timer > 2) {
                        int random = rand() % 10;
                        if (random <= 5)
                            duck_posX = -25 + (std::rand() % (1080 + 25 + 1));
                        else
                            duck_posX = rand() % 360;

                        duck_posY = 0;

                        duck_angle = static_cast <float> (rand()) / static_cast <float> (15.5);
                        state = ALIVE;
                        speed += 25;
                        timer = 0;
                        speed_stop = 1;

                    }
                }
            }
        }

        else {
            duck_angle = 0;
            state = ESCAPE;
            respawn += deltaTimeSeconds;

            if (respawn > 2) {
                duck_escape = 0;
                int random = rand() % 10;
                if (random <= 5)
                    duck_posX = -25 + (std::rand() % (1080 + 25 + 1));
                else
                    duck_posX = rand() % 360;

                duck_posY = 0;
                duck_angle = static_cast <float> (rand()) / static_cast <float> (15.5);
                state = ALIVE;
                no_lives--;
                duck_escape = 0;
                respawn = 0;
                speed += 25;
                no_bullets = 3;
            }
        }
    }

    if (no_lives <= 0 && state != WINNER) {
        magic += deltaTimeSeconds;
        if (magic > 0.5) {
            // G
            {
                gameOver = glm::mat3(1);
                gameOver *= transform2D::Translate(100, 300);
                RenderMesh2D(meshes["game_over1"], shaders["VertexColor"], gameOver);
                gameOver = glm::mat3(1);
                gameOver *= transform2D::Translate(130, 300);
                RenderMesh2D(meshes["game_over2"], shaders["VertexColor"], gameOver);
                gameOver *= transform2D::Translate(50, 0);
                gameOver *= transform2D::Rotate(M_PI_2);
                RenderMesh2D(meshes["game_over2"], shaders["VertexColor"], gameOver);
                gameOver *= transform2D::Translate(50, 0);
                RenderMesh2D(meshes["game_over3"], shaders["VertexColor"], gameOver);
                gameOver = glm::mat3(1);
                gameOver *= transform2D::Translate(100, 400);
                gameOver *= transform2D::Scale(20, 1);
                RenderMesh2D(meshes["game_over2"], shaders["VertexColor"], gameOver);
            }
            // A
            {
                gameOver = glm::mat3(1);
                gameOver *= transform2D::Translate(200, 300);
                RenderMesh2D(meshes["game_over1"], shaders["VertexColor"], gameOver);
                gameOver = glm::mat3(1);
                gameOver *= transform2D::Translate(250, 300);
                RenderMesh2D(meshes["game_over1"], shaders["VertexColor"], gameOver);
                gameOver = glm::mat3(1);
                gameOver *= transform2D::Translate(200, 350);
                RenderMesh2D(meshes["game_over2"], shaders["VertexColor"], gameOver);
            }
            // M 
            {
                gameOver = glm::mat3(1);
                gameOver *= transform2D::Translate(300, 300);
                RenderMesh2D(meshes["game_over1"], shaders["VertexColor"], gameOver);
                gameOver = glm::mat3(1);
                gameOver *= transform2D::Translate(360, 360);
                gameOver *= transform2D::Rotate(M_PI_4);
                RenderMesh2D(meshes["game_over4"], shaders["VertexColor"], gameOver);
                gameOver = glm::mat3(1);
                gameOver *= transform2D::Translate(360, 360);
                gameOver *= transform2D::Rotate(-M_PI_4);
                RenderMesh2D(meshes["game_over4"], shaders["VertexColor"], gameOver);
                gameOver = glm::mat3(1);
                gameOver *= transform2D::Translate(400, 300);
                RenderMesh2D(meshes["game_over1"], shaders["VertexColor"], gameOver);
            }
            // E
            {
                gameOver = glm::mat3(1);
                gameOver *= transform2D::Translate(450, 300);
                RenderMesh2D(meshes["game_over1"], shaders["VertexColor"], gameOver);
                gameOver *= transform2D::Translate(10, 0);
                RenderMesh2D(meshes["game_over2"], shaders["VertexColor"], gameOver);
                gameOver *= transform2D::Translate(0, 50);
                RenderMesh2D(meshes["game_over2"], shaders["VertexColor"], gameOver);
            }
            // O
            {
                gameOver = glm::mat3(1);
                gameOver *= transform2D::Translate(580, 300);
                RenderMesh2D(meshes["game_over1"], shaders["VertexColor"], gameOver);
                gameOver *= transform2D::Translate(10, 0);
                RenderMesh2D(meshes["game_over2"], shaders["VertexColor"], gameOver);
                gameOver = glm::mat3(1);
                gameOver *= transform2D::Translate(630, 300);
                RenderMesh2D(meshes["game_over1"], shaders["VertexColor"], gameOver); 
            }
            // V
            {
                gameOver = glm::mat3(1);
                gameOver *= transform2D::Translate(730, 300);
                gameOver *= transform2D::Rotate(0.16666*M_PI);
                RenderMesh2D(meshes["game_over5"], shaders["VertexColor"], gameOver);
                gameOver = glm::mat3(1);
                gameOver *= transform2D::Translate(725, 315);
                gameOver *= transform2D::Rotate(-0.16666 * M_PI);
                RenderMesh2D(meshes["game_over5"], shaders["VertexColor"], gameOver);
            }
            // E
            {
                gameOver = glm::mat3(1);
                gameOver *= transform2D::Translate(820, 300);
                RenderMesh2D(meshes["game_over1"], shaders["VertexColor"], gameOver);
                gameOver *= transform2D::Translate(10, 0);
                RenderMesh2D(meshes["game_over2"], shaders["VertexColor"], gameOver);
                gameOver *= transform2D::Translate(0, 50);
                RenderMesh2D(meshes["game_over2"], shaders["VertexColor"], gameOver);
            }
            // R
            {
                gameOver = glm::mat3(1);
                gameOver *= transform2D::Translate(900, 300);
                RenderMesh2D(meshes["game_over1"], shaders["VertexColor"], gameOver);
                gameOver *= transform2D::Translate(10, 50);
                RenderMesh2D(meshes["game_over2"], shaders["VertexColor"], gameOver);
                gameOver *= transform2D::Rotate(M_PI_2);
                gameOver *= transform2D::Translate(0, -70);
                RenderMesh2D(meshes["game_over2"], shaders["VertexColor"], gameOver);
                gameOver = glm::mat3(1);
                gameOver *= transform2D::Translate(966, 300);
                gameOver *= transform2D::Rotate(M_PI_4);
                RenderMesh2D(meshes["game_over4"], shaders["VertexColor"], gameOver);
            }
            // !
            {
                gameOver = glm::mat3(1);
                gameOver *= transform2D::Translate(1050, 340);
                RenderMesh2D(meshes["game_over6"], shaders["VertexColor"], gameOver);
                gameOver = glm::mat3(1);
                gameOver *= transform2D::Translate(1050, 300);
                RenderMesh2D(meshes["game_over7"], shaders["VertexColor"], gameOver);
            }
            if (magic > 1) magic = 0;
        }
    }
    
 
}


void Tema1::FrameEnd()
{
}

void Tema1::OnInputUpdate(float deltaTime, int mods)
{
}

void Tema1::OnKeyPress(int key, int mods)
{
    // Add key press event
    if (key == GLFW_KEY_R) {
        no_lives = 3;
        no_bullets = 3;
        speed = 500;
        your_score = 1;
        state = ALIVE;
        respawn = 0;

        int random = rand() % 10;
        if (random <= 5)
            duck_posX = -25 + (std::rand() % (1080 + 25 + 1));
        else
            duck_posX = rand() % 360;

        duck_posY = 0;

        duck_angle = static_cast <float> (rand()) / static_cast <float> (15.5);
    }
}

void Tema1::OnKeyRelease(int key, int mods)
{
    // Add key release event
}

void Tema1::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY)
{
    // Add mouse move event
}

void Tema1::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
{
    // Add mouse button press event
    glm::mat3 aux = glm::mat3(1);

    aux *= transform2D::Translate(-10, 50);
    aux *= transform2D::Rotate(-duck_angle);
    aux *= transform2D::Translate(-eye_posX - duck_posX, -eye_posY - duck_posY);
    glm::vec3 v = {(float)mouseX, (float)resolution.y - (float)mouseY, 1};
    v = aux * v;
    
    
    //(x-center_x)^2 + (y - center_y)^2 < radius^2
    if(no_bullets > 0) {
        if ((v.x) * (v.x) + (v.y) * (v.y) <= 69 * 69) {
            duck_angle = M_PI;
            state = KILLED;
            if (your_score <= 22) your_score += 1;
                
            if (your_score > 21) state = WINNER;
                
        }
        if ((v.x) * (v.x) + (v.y) * (v.y) > 69 * 69) no_bullets -= 1;
    }
}

void Tema1::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
{
    // Add mouse button release event
}

void Tema1::OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY)
{
}

void Tema1::OnWindowResize(int width, int height)
{
}
