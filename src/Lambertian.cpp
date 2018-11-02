#include "Lambertian.hpp"

Lambertian::Lambertian(vec3& a): albedo(a) {};

bool Lambertian::scatter(Ray& ray, HitRecord& rec, vec3& attenuation, Ray& scattered) {
    vec3 target = rec.position + rec.normal + randomInUnitSphere();
    scattered = Ray(rec.position, target - rec.position);
    attenuation = albedo;
    return true;
};
