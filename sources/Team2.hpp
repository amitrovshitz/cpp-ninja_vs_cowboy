#pragma once
#include "Team.hpp"
using namespace std;
namespace ariel
{
    class Team2: public Team
    {
        public:
            Team2(Character* leader):Team(leader){}          
            virtual void attack(Team* enemy);
            virtual int stillAlive()const;
            virtual double the_enemy_distance(Team* enemy);
            virtual Character** the_victim(Team* enemy);// always return the victims and if not have return null.
            virtual void print()const;

    };
}
