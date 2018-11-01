#include <iostream>
using namespace std;

#include "glm/glm.hpp"
using namespace glm;

#include "Ray.hpp"

vec3 color(Ray& ray) {
    vec3 unitDirection = normalize(ray.direction());
    float t = 0.5f * (unitDirection.y + 1.0);
    return ((1.0f - t) * vec3(1.0f, 1.0f, 1.0f)) +
            (t * vec3(0.5f, 0.7f, 1.0f));
}

// bool hitSphere(vec3& center, float radius, Ray& ray) {
//     vec3 oc = ray.origin() - center;
//     float a = dot(ray.direction(), ray.direction());
// }

int main() {
    int nx = 500;
    int ny = 300;
    cout << "P3\n" << nx << " " << ny << "\n255\n";

    vec3 lowerLeftCorner = { -(nx/100), -(ny/100), -(ny/100) };
    vec3 horizontal = { ((nx * 2)/100), 0.0, 0.0 };
    vec3 vertical = { 0.0, ((ny * 2)/100), 0.0 };
    vec3 origin = { 0.0, 0.0, 0.0 };

    for (int j = ny - 1; j >= 0; j--) {
        for (int i = 0; i < nx; i++) {
            float u = float(i) / float(nx);
            float v = float(j) / float(ny);

            Ray ray = Ray(origin, lowerLeftCorner + u * horizontal + v * vertical);
            vec3 col = color(ray);

            int ir = int(255.99 * col[0]);
            int ig = int(255.99 * col[1]);
            int ib = int(255.99 * col[2]);

            cout << ir << " " << ig << " " << ib << "\n";
        }
    }
}
