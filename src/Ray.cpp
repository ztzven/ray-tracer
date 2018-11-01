#include "Ray.hpp"

Ray::Ray() { };

Ray::Ray(const glm::vec3& a, const glm::vec3 b) {
    A = a;
    B = b;
};

glm::vec3 Ray::origin() {
    return A;
};

glm::vec3 Ray::direction() {
    return B;
};

glm::vec3 Ray::pointAtParameter(float t) {
    return A + (t*B);
};
