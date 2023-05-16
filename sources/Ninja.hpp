#pragma once
#include "Character.hpp"
using namespace std;
namespace ariel
{
    class Ninja:public Character
    {
        protected:
            int speed;
        public:
            Ninja(const Point& point, int hit, string name, int speed);
            void move(const Character * enemy);
            void slash(Character * enemy)const;
            virtual string print()const override;
            //check operator =
    };
    
}