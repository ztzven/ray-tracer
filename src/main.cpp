#include <iostream>
#include <chrono>
using namespace std;

#include "glm/glm.hpp"
using namespace glm;

#include "HitableList.hpp"
#include "Ray.hpp"
#include "Sphere.hpp"
#include "Camera.hpp"

vec3 randomInUnitSphere() {
    vec3 p;
    do {
        p = 2.0f * vec3(drand48(), drand48(), drand48()) - vec3(1, 1, 1);
    } while (length(p * p) >= 1.0);
    return p;
}

vec3 color(Ray& ray, Hitable *world) {
    HitRecord rec;

    if (world->hit(ray, 0.0, MAXFLOAT, rec)) {
        vec3 target = rec.position + rec.normal + randomInUnitSphere();
        Ray newRay = Ray(rec.position, target - rec.position);
        return 0.5f * color(newRay, world);
    } else {
        vec3 unitDirection = normalize(ray.direction());
        float t = 0.5f * (unitDirection.y + 1.0);
        return ((1.0f - t) * vec3(1.0f, 1.0f, 1.0f)) +
                (t * vec3(0.5f, 0.7f, 1.0f));
    }
}

typedef chrono::high_resolution_clock Time;

int main() {
    static auto startTime = Time::now();

    static int nx = 500;
    static int ny = 500;
    static int nz = 10;

    Hitable *list[2];
    list[0] = new Sphere(vec3(0, -100.5, -1.0), 100.0f);
    list[1] = new Sphere(vec3(0, 0, -1), 0.5f);
    // list[2] = new Sphere(vec3(1, 0, -1), 0.5f);
    // list[3] = new Sphere(vec3(-1, 0, -1), 0.5f);

    Hitable *world = new HitableList(list, 2);

    cout << "P3\n" << nx << " " << ny << "\n255\n";

    Camera* camera = new Camera(nx, ny);

    for (int y = ny - 1; y >= 0; y--) {
        for (int x = 0; x < nx; x++) {
            vec3 col(0,0,0);

            for (int z = 0; z < nz; z++) {
                float u = float(x + drand48()) / float(nx);
                float v = float(y + drand48()) / float(ny);
                Ray ray = camera->getRay(u, v);
                vec3 p = ray.pointAtParameter(2.0);
                col += color(ray, world);
            }

            col /= float(nz);

            int ir = int(255.99 * col[0]);
            int ig = int(255.99 * col[1]);
            int ib = int(255.99 * col[2]);

            cout << ir << " " << ig << " " << ib << "\n";
        }
    }

    auto endTime = Time::now();
    auto duration = chrono::duration<float, chrono::seconds::period>(endTime - startTime).count();
    // cout << "\ntook " << duration << "s\n";
}
