#include "obiect2D.h"

#include <vector>


#include "core/engine.h"
#include "utils/gl_utils.h"


Mesh* obiect2D::CreateSquare(
    const std::string& name,
    glm::vec3 leftBottomCorner,
    float length,
    glm::vec3 color,
    bool fill)
{
    glm::vec3 corner = leftBottomCorner;

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(corner, color),
        VertexFormat(corner + glm::vec3(length, 0, 0), color),
        VertexFormat(corner + glm::vec3(length, length, 0), color),
        VertexFormat(corner + glm::vec3(0, length, 0), color)
    };

    Mesh* square = new Mesh(name);
    std::vector<unsigned int> indices = { 0, 1, 2, 3 };

    if (!fill) {
        square->SetDrawMode(GL_LINE_LOOP);
    }
    else {
        // Draw 2 triangles. Add the remaining 2 indices
        indices.push_back(0);
        indices.push_back(2);
    }

    square->InitFromData(vertices, indices);
    return square;
}

Mesh* obiect2D::CreateTriangle(
    const std::string& name,
    glm::vec3 leftBottomCorner,
    float length,
    glm::vec3 color,
    bool fill)
{
    glm::vec3 corner = leftBottomCorner;

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(corner, color),
        VertexFormat(corner + glm::vec3(length, 0, 0), color),
        VertexFormat(corner + glm::vec3(length/2, length*2, 0), color),

    };
    Mesh* triangle = new Mesh(name);
    std::vector<unsigned int> indices = { 0,1,2 };
    if (!fill) {
        triangle->SetDrawMode(GL_LINE_LOOP);
    }
    else {
        // Draw 2 triangles. Add the remaining 2 indices
        indices.push_back(0);
        indices.push_back(2);
    }
    triangle->InitFromData(vertices, indices);
    return triangle;
}


Mesh* obiect2D::CreateCircle(
    const std::string& name,
    glm::vec3 leftBottomCorner,
    float length,
    glm::vec3 color,
    bool fill)
{
    int numberOfPoints = 360;
    float angleUnit = 2 * M_PI / numberOfPoints;
    float thetha = 0;

    std::vector<VertexFormat> points;
    points.push_back(VertexFormat(glm::vec3(0, 0, 0), color));
    for (int i = 0; i < numberOfPoints; i++)
    {
        points.push_back(VertexFormat(glm::vec3(length * cos(thetha), length * sin(thetha), 0), color));
        thetha += angleUnit;
    }

    std::vector<unsigned int> indices;
    for (int i = 1; i < numberOfPoints; i++)
    {
        indices.push_back(0);
        indices.push_back(i);
        indices.push_back(i + 1);
    }
    indices.push_back(0);
    indices.push_back(numberOfPoints);
    indices.push_back(1);

    Mesh* circle = new Mesh(name);
    circle->InitFromData(points, indices);
    return circle;
}

Mesh* obiect2D::CreateRectangle(
    const std::string& name,
    glm::vec3 leftBottomCorner,
    float length,float height,
    glm::vec3 color,
    bool fill)
{
    glm::vec3 corner = leftBottomCorner;

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(corner, color),
        VertexFormat(corner + glm::vec3(length, 0, 0), color),
        VertexFormat(corner + glm::vec3(length, height, 0), color),
        VertexFormat(corner + glm::vec3(0, height, 0), color)

    };
    Mesh* grass = new Mesh(name);
    std::vector<unsigned int> indices = { 0,1,2,3 };
    if (!fill) {
        grass->SetDrawMode(GL_LINE_LOOP);
    }
    else {
        // Draw 2 triangles. Add the remaining 2 indices
        indices.push_back(0);
        indices.push_back(2);
    }
    grass->InitFromData(vertices, indices);
    return grass;
}

Mesh* obiect2D::CreateHeart(
    const std::string& name,
    glm::vec3 leftBottomCorner,
    float length,
    glm::vec3 color,
    bool fill)
{
    glm::vec3 corner = leftBottomCorner;

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(corner, color),
        VertexFormat(corner + glm::vec3(length, 0, 0), color),
        VertexFormat(corner + glm::vec3(length / 2, length / sqrt(2), 0), color),

    };
    Mesh* triangle = new Mesh(name);
    std::vector<unsigned int> indices = { 0,1,2 };
    if (!fill) {
        triangle->SetDrawMode(GL_LINE_LOOP);
    }
    else {
        // Draw 2 triangles. Add the remaining 2 indices
        indices.push_back(0);
        indices.push_back(2);
    }
    triangle->InitFromData(vertices, indices);
    return triangle;
}

Mesh* obiect2D::CreateBullet(
    const std::string& name,
    glm::vec3 leftBottomCorner,
    float height, float wide,
    glm::vec3 color,
    bool fill)
{
    glm::vec3 corner = leftBottomCorner;

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(corner, color),
        VertexFormat(corner + glm::vec3(wide, 0, 0), color),
        VertexFormat(corner + glm::vec3(wide / 2, height, 0), color),

    };
    Mesh* triangle = new Mesh(name);
    std::vector<unsigned int> indices = { 0,1,2 };
    if (!fill) {
        triangle->SetDrawMode(GL_LINE_LOOP);
    }
    else {
        // Draw 2 triangles. Add the remaining 2 indices
        indices.push_back(0);
        indices.push_back(2);
    }
    triangle->InitFromData(vertices, indices);
    return triangle;
}

