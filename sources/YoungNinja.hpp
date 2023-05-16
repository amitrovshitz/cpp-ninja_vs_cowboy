#pragma once
#include "Ninja.hpp"

namespace ariel
{
    class YoungNinja:public Ninja
    {
        public:
            YoungNinja(string name, const Point& point):Ninja(point, 100, name, 14){};

    };
}