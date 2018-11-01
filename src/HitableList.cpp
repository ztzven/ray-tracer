#include "HitableList.hpp"

HitableList::HitableList(Hitable **l, int n): list(l), listSize(n) { };

bool HitableList::hit(Ray& ray, float tMin, float tMax, HitRecord& hitRecord) {
    HitRecord tempRecord;

    bool hitAnything = false;
    double closestSoFar = tMax;

    for (int i = 0; i < listSize; i++) {
        if (list[i]->hit(ray, tMin, closestSoFar, tempRecord)) {
            hitAnything = true;
            closestSoFar = tempRecord.t;
            hitRecord = tempRecord;
        }
    }

    return hitAnything;
};