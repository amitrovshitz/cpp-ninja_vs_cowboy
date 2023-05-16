#pragma once
#include "Character.hpp"
using namespace std;
namespace ariel
{

    class Cowboy:public Character
    {
        protected:
            int amount_of_bulets;

        public:
            Cowboy(string name, const Point& point):Character(point, 110, name), amount_of_bulets(6){};
            void shoot(Character * enemy);
            bool hasboolets()const{return (amount_of_bulets>0);}
            void reload(){amount_of_bulets+=6;}
            virtual string print()const override;
    };
    
}