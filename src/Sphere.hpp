#pragma once

#include "Hitable.hpp"
#include "Material.hpp"

class Sphere: public Hitable {
    public:
        vec3 center;
        float radius;
        Material* pMaterial;

        Sphere(vec3 center, float radius, Material* m);

        bool hit(Ray& ray, float tMin, float tMax, HitRecord& hitRecord);
};
