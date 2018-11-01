#include "Ray.hpp"

Ray::Ray() { };
Ray::Ray(const vec3& a, const vec3 b) {
    A = a;
    B = b;
};

vec3 Ray::origin() {
    return A;
};

vec3 Ray::direction() {
    return B;
};

vec3 Ray::pointAtParameter(float t) {
    return A + (t*B);
};
