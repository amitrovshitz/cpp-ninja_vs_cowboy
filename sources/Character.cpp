#include "Character.hpp"
#include <iostream>
using namespace ariel;

Character::Character(const Point& index, int hit, string name):index(index), hit_count(hit), name(name), have_a_team(false)
{
    if(hit < 0)
    {
        throw invalid_argument("not ilegal.");
    }
}

void Character::hit(int value)
{
    if(value < 0)
    {
        throw invalid_argument("not ilegal.");
    }
    else
    {
        hit_count-=value;
    }
}