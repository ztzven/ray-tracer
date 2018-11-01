#include "Sphere.hpp"

Sphere::Sphere() {};
Sphere::Sphere(vec3 center, float radius): center(center), radius(radius) { }

bool Sphere::hit(Ray& ray, float tMin, float tMax, HitRecord& hitRecord) {
    vec3 oc = (ray.origin() - center);

    float a = dot(ray.direction(), ray.direction());
    float b = 2.0 * dot(oc, ray.direction());
    float c = dot(oc, oc) - radius * radius;
    float discriminant = b*b - a*c;

    if (discriminant > 0) {
        float temp = (-b - sqrt(discriminant)) / a;
        if (temp < tMax && temp > tMin) {
            hitRecord.t = temp;
            hitRecord.position = ray.pointAtParameter(hitRecord.t);
            hitRecord.normal = (hitRecord.position - center) / radius;
            return true;
        }
        temp = (-b + sqrt(discriminant)) / a;
        if (temp < tMax && temp > tMin) {
            hitRecord.t = temp;
            hitRecord.position = ray.pointAtParameter(hitRecord.t);
            hitRecord.normal = (hitRecord.position - center) / radius;
            return true;
        }
    }

    return false;
}
