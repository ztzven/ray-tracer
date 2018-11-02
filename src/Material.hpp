#pragma once

#include "Ray.hpp"
#include "Hitable.hpp"

class Material {
    public:
        virtual bool scatter(Ray& ray, HitRecord& rec, vec3& attenuation, Ray& scattered) = 0;
        vec3 randomInUnitSphere() {
            vec3 p;
            do {
                p = 2.0f * vec3(drand48(), drand48(), drand48()) - vec3(1, 1, 1);
            } while (pow(length(p), 2) >= 1.0);
            return p;
        };
};
