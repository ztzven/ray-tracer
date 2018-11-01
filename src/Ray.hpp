#pragma once

#include "glm/glm.hpp"
using namespace glm;

class Ray {
    private:
        vec3 A;
        vec3 B;
    public:
        Ray();
        Ray(const vec3& a, const vec3 b);
        vec3 origin();
        vec3 direction();
        vec3 pointAtParameter(float t);
};
