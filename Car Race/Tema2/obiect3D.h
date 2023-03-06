#pragma once

#include <string>

#include "core/gpu/mesh.h"
#include "utils/glm_utils.h"


namespace obiect3D
{
    // Create square with given bottom left corner, length and color
   
    Mesh* CreateGrass(const std::string &name, glm::vec3 center, glm::vec3 color, bool fill = false);
    Mesh* CreateRoad(const std::string &name, glm::vec3 center, glm::vec3 color, bool fill = false);
    Mesh* CreateTree(const std::string &name, glm::vec3 spawnPoint, glm::vec3 color1, glm::vec3 color2, bool fill = false);
    Mesh* CreateCar(const std::string& name, glm::vec3 spawnPoint, glm::vec3 color, bool fill = false);
}
