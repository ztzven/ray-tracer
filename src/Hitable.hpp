#pragma once

#include "glm/glm.hpp"
using namespace glm;

#include "Ray.hpp"
#include "Material.hpp"

struct HitRecord {
    float t;
    vec3 position;
    vec3 normal;
    Material* pMaterial;
};

class Hitable {
    public:
        virtual bool hit(Ray& ray, float tMin, float tMax, HitRecord& hitRecord) = 0;
};
