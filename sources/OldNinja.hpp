#pragma once
#include "Ninja.hpp"

namespace ariel
{
    class OldNinja:public Ninja
    {
        public:
            OldNinja(string name,  const Point& point):Ninja(point, 150, name, 8){};
    };
}