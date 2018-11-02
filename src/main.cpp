#include <iostream>
#include <chrono>
using namespace std;

#include "glm/glm.hpp"
using namespace glm;

#include "HitableList.hpp"
#include "Ray.hpp"
#include "Sphere.hpp"
#include "Camera.hpp"
#include "Lambertian.hpp"

vec3 color(Ray& ray, Hitable *world, int depth) {
    HitRecord rec;

    if (world->hit(ray, 0.001f, MAXFLOAT, rec)) {
        Ray scattered;
        vec3 attenuation;
        if (depth < 50 && rec.pMaterial->scatter(ray, rec, attenuation, scattered)) {
            return attenuation * color(scattered, world, depth + 1);
        } else {
            return vec3(0, 0, 0);
        }
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
    static int ny = 300;
    static int nz = 100;

    Hitable *list[4];
    list[0] = new Sphere(vec3(0, -100.5, -1.0), 100.0f, new Lambertian(vec3(0.5f,0.5f,0.5f)));
    list[1] = new Sphere(vec3(0, 0, -1), 0.5f, new Lambertian(vec3(0.5f,0.5f,0.5f)));
    list[2] = new Sphere(vec3(1, 0, -1), 0.5f, new Lambertian(vec3(0.5f,0.5f,0.5f)));
    list[3] = new Sphere(vec3(-1, 0, -1), 0.5f, new Lambertian(vec3(0.5f,0.5f,0.5f)));

    Hitable *world = new HitableList(list, 4);

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
                col += color(ray, world, 0);
            }

            col /= float(nz);
            col = sqrt(col);

            int ir = ceil(255.99 * col[0]);
            int ig = ceil(255.99 * col[1]);
            int ib = ceil(255.99 * col[2]);

            cout << ir << " " << ig << " " << ib << "\n";
        }
    }

    auto endTime = Time::now();
    auto duration = chrono::duration<float, chrono::seconds::period>(endTime - startTime).count();
    // cout << "\ntook " << duration << "s\n";
}
