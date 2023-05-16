#pragma once
#include "Cowboy.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include "OldNinja.hpp"
using namespace std;
namespace ariel
{
    class Team
    {
        protected:
            Character* team[10];
            Character* leader; 
            int size;


        public:
            Team(Character* leader);
            ~Team();
            int getSize(){return size;}
            void add(Character* some);// the same player in 2 group.
            virtual void attack(Team* enemy);
            virtual int stillAlive()const;
            void new_leader();
            virtual double the_enemy_distance(Team* enemy);
            virtual Character** the_victim(Team* enemy);// always return the victims and if not have return null.
            virtual void print()const;
    };
}
//////////////////////chrck the casting////////////////////////////
