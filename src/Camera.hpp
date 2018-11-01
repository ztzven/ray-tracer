#pragma once

#include "glm/glm.hpp"
using namespace glm;

#include "Ray.hpp"

class Camera {
    private:
        int viewportWidth;
        int viewportHeight;

        vec3 origin;
        vec3 lowerLeftCorner;
        vec3 horizontal;
        vec3 vertical;
    public:
        Camera();
        Camera(int vW, int vH);
        Ray getRay(float u, float v);
};
