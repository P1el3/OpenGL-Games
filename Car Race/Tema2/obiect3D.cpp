#include "obiect3D.h"

#include <vector>


#include "core/engine.h"
#include "utils/gl_utils.h"

Mesh* obiect3D::CreateTree(
    const std::string& name,
    glm::vec3 spawnPoint,
    glm::vec3 trunchi,
    glm::vec3 frunze,
    bool fill)
{
    glm::vec3 pos = spawnPoint;
    std::vector<VertexFormat> vertices = {
        //trunchi
        VertexFormat(pos + glm::vec3(0.275,0,0.275),trunchi),
        VertexFormat(pos + glm::vec3(0.275,0,-0.275),trunchi),
        VertexFormat(pos + glm::vec3(-0.275,0,-0.275),trunchi),
        VertexFormat(pos + glm::vec3(-0.275,0,0.275),trunchi),
        VertexFormat(pos + glm::vec3(0.275,3.5,0.275),trunchi),
        VertexFormat(pos + glm::vec3(0.275,3.5,-0.275),trunchi),
        VertexFormat(pos + glm::vec3(-0.275,3.5,-0.275),trunchi),
        VertexFormat(pos + glm::vec3(-0.275,3.5,0.275),trunchi),
        //frunze
        VertexFormat(pos + glm::vec3(1.5,3.5,1.5),frunze),
        VertexFormat(pos + glm::vec3(1.5,3.5,-1.5),frunze),
        VertexFormat(pos + glm::vec3(-1.5,3.5,-1.5),frunze),
        VertexFormat(pos + glm::vec3(-1.5,3.5,1.5),frunze),
        VertexFormat(pos + glm::vec3(1.5,6.5,1.5),frunze),
        VertexFormat(pos + glm::vec3(1.5,6.5,-1.5),frunze),
        VertexFormat(pos + glm::vec3(-1.5,6.5,-1.5),frunze),
        VertexFormat(pos + glm::vec3(-1.5,6.5,1.5),frunze),
    };
    Mesh* tree = new Mesh(name);
    std::vector<unsigned int> indices{
    0,1,2,2,3,0, //base
    1,2,6,6,5,1,//side
    0,3,7,7,4,0,//side
    2,6,7,7,3,2,//side
    0,1,5,5,4,0,//side
    8,9,10,10,11,8,//leaves_base
    12,13,14,14,15,12,//leaves_top
    9,10,14,14,13,9,//side
    10,14,15,15,11,10,//side
    8,11,15,15,12,8,//side
    8,9,13,13,12,8//side
    };
    tree->InitFromData(vertices, indices);
    return tree;
}

Mesh* obiect3D::CreateGrass(
    const std::string& name,
    glm::vec3 centru,
    glm::vec3 color,
    bool fill)
{
    {
        glm::vec3 center = centru;
        std::vector<VertexFormat> corners =
        {
            VertexFormat(center + glm::vec3(160,0,100),color),
            VertexFormat(center + glm::vec3(160,0,-80),color),
            VertexFormat(center + glm::vec3(-140,0,-80),color),
            VertexFormat(center + glm::vec3(-140,0,100),color)
        };
        Mesh* grass = new Mesh(name);
        std::vector<unsigned int> indices = { 0,1,2,2,3,0 };


        grass->InitFromData(corners, indices);
        return grass;
    }
}

Mesh* obiect3D::CreateRoad(
    const std::string& name,
    glm::vec3 centru,
    glm::vec3 color,
    bool fill)
{
    glm::vec3 center = centru;

    std::vector<VertexFormat> points =
    {
        VertexFormat(center + glm::vec3(8.91,0,38.55), color),
        VertexFormat(center + glm::vec3(20,0,43.54), color),
        VertexFormat(center + glm::vec3(28.04,0,50.75), color),
        VertexFormat(center + glm::vec3(37.19,0,61.84), color),
        VertexFormat(center + glm::vec3(48.01,0,69.89), color),
        VertexFormat(center + glm::vec3(63.53,0,74.88), color),
        VertexFormat(center + glm::vec3(84.33,0,74.88), color),
        VertexFormat(center + glm::vec3(101.52,0,68.78), color),
        VertexFormat(center + glm::vec3(112.06,0,57.13), color),
        VertexFormat(center + glm::vec3(120,0,40), color),
        VertexFormat(center + glm::vec3(120.1,0,23.3), color),
        VertexFormat(center + glm::vec3(118.72,0,2.78), color),
        VertexFormat(center + glm::vec3(108.46,0,-9.15), color),
        VertexFormat(center + glm::vec3(100,0,-20), color),
        VertexFormat(center + glm::vec3(89.05,0,-27.45), color),
        VertexFormat(center + glm::vec3(72.96,0,-33.83), color),
        VertexFormat(center + glm::vec3(56.88,0,-38.82), color),
        VertexFormat(center + glm::vec3(41.63,0,-42.98), color),
        VertexFormat(center + glm::vec3(24.43,0,-45.2), color),
        VertexFormat(center + glm::vec3(7.24,0,-46.03), color),
        VertexFormat(center + glm::vec3(-18.27,0,-43.81), color),
        VertexFormat(center + glm::vec3(-36.02,0,-43.25), color),
        VertexFormat(center + glm::vec3(-51.55,0,-34.66), color),
        VertexFormat(center + glm::vec3(-66.8,0,-27.17), color),
        VertexFormat(center + glm::vec3(-80,0,-20), color),
        VertexFormat(center + glm::vec3(-88.71,0,-8.59), color),
        VertexFormat(center + glm::vec3(-93.42,0,9.16), color),
        VertexFormat(center + glm::vec3(-95.64,0,22.74), color),
        VertexFormat(center + glm::vec3(-94.81,0,36.06), color),
        VertexFormat(center + glm::vec3(-92.03,0,47.98), color),
        VertexFormat(center + glm::vec3(-83.44,0,59.35), color),
        VertexFormat(center + glm::vec3(-72.07,0,68.22), color),
        VertexFormat(center + glm::vec3(-59.87,0,71.55), color),
        VertexFormat(center + glm::vec3(-46.83,0,70.72), color),
        VertexFormat(center + glm::vec3(-37.13,0,61.57), color),
        VertexFormat(center + glm::vec3(-25.2,0,51.03), color),
        VertexFormat(center + glm::vec3(-14.94,0,42.16), color),
        VertexFormat(center + glm::vec3(-4.41,0,37.44), color)
    };

    glm::vec3 UP = glm::vec3(0, 1, 0);
    std::vector<VertexFormat> vertices;
    for (int i = 0; i < 37; i++) {
        glm::vec3 D = points[i + 1].position - points[i].position;
        glm::vec3 P = normalize(cross(D, UP));
        glm::vec3 R = points[i].position + (P * 10.0f);
        glm::vec3 A = points[i].position - (P * 10.0f);
        vertices.push_back(VertexFormat(R, color));
        vertices.push_back(VertexFormat(A, color));
    }

    Mesh* road = new Mesh(name);
    std::vector<unsigned int> indices;
    for (int i = 0; i < 72; i++) {
        indices.push_back(i);
        indices.push_back(i + 1);
        indices.push_back(i + 2);
    }
    indices.push_back(73);
    indices.push_back(0);
    indices.push_back(1);
    indices.push_back(73);
    indices.push_back(72);
    indices.push_back(0);

    road->InitFromData(vertices, indices);
    return road;
}

Mesh* obiect3D::CreateCar(
    const std::string& name,
    glm::vec3 centru,
    glm::vec3 color,
    bool fill)
{
    glm::vec3 spawnPoint = centru;
    std::vector<VertexFormat> vertices = {
         VertexFormat(spawnPoint + glm::vec3(1.75, 0, 1),color),
         VertexFormat(spawnPoint + glm::vec3(1.75, 0, -1),color),
         VertexFormat(spawnPoint + glm::vec3(-1.75, 0, -1),color),
         VertexFormat(spawnPoint + glm::vec3(-1.75, 0, 1),color),
         VertexFormat(spawnPoint + glm::vec3(1.75, 1.75, 1),color),
         VertexFormat(spawnPoint + glm::vec3(1.75, 1.75, -1),color),
         VertexFormat(spawnPoint + glm::vec3(-1.75, 1.75, -1),color),
         VertexFormat(spawnPoint + glm::vec3(-1.75, 1.75, 1),color),
    };
    Mesh* car = new Mesh(name);
    std::vector<unsigned int> indices{
        0,1,2,2,3,0,//bottom   
        4,5,6,6,7,4,//top
        3,2,6,6,7,3,//front
        0,1,5,5,4,0,//back
        0,3,7,7,4,0,//left
        1,2,6,6,5,1//right
    };
    car->InitFromData(vertices, indices);
    return car;
}



