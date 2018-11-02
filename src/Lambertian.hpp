#pragma once

#include "Material.hpp"

class Lambertian: public Material {
    private:
        vec3 albedo;
    public:
        Lambertian(vec3& a);
        bool scatter(Ray& ray, HitRecord& rec, vec3& attenuation, Ray& scattered);
};
