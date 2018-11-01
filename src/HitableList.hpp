#pragma once

#include "Hitable.hpp"

class HitableList: public Hitable {
    public:
        Hitable **list;
        int listSize;

        HitableList(Hitable **l, int n);

        bool hit(Ray& ray, float tMin, float tMax, HitRecord& hitRecord);
};
