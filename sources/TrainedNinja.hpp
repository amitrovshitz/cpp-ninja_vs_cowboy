#pragma once
#include "Ninja.hpp"

namespace ariel
{
    class TrainedNinja:public Ninja
    {
        public:
            TrainedNinja(string name,  const Point& point):Ninja(point, 120, name, 12){};

    };
}