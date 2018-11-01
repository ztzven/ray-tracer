#pragma once

#include "glm/glm.hpp"

class Ray {
    private:
        glm::vec3 A;
        glm::vec3 B;
    public:
        Ray();
        Ray(const glm::vec3& a, const glm::vec3 b);
        glm::vec3 origin();
        glm::vec3 direction();
        glm::vec3 pointAtParameter(float t);
};
