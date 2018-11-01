#pragma once

#include "Hitable.hpp"

class Sphere: public Hitable {
    public:
        vec3 center;
        float radius;

        Sphere();
        Sphere(vec3 center, float radius);

        bool hit(Ray& ray, float tMin, float tMax, HitRecord& hitRecord);
};
