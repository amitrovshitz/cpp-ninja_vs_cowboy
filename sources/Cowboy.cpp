#include <iostream>
#include "Cowboy.hpp"
using namespace std;
using namespace ariel;

void Cowboy::shoot(Character * enemy)
{
    if(isAlive() && hasboolets())
    {
        amount_of_bulets--;
        enemy->hit(10);
    }
}

 string Cowboy::print()const 
{
    string result = "";
    if(isAlive())
    {
        result +=  ("C " + getName() + "  hit count is " + to_string(hit_count) + " and the location is " + getLocation().print() + "\n");
    }
    else
    {
        result +=  ("C (" + getName() + ") and the location is " + getLocation().print() + "\n");
    }
    return result;
}
