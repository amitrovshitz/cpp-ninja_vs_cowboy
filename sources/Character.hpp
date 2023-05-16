#pragma once
#include "Point.hpp"
#include <string>
using namespace std;
namespace ariel
{
    class Character
    {
        protected:
            Point index;
            int hit_count;
            string name;
            bool have_a_team;

        public:
            Character(const Point& index, int hit, string name);
            virtual ~Character() {}//check
            bool isAlive()const{return (hit_count > 0)? true : false;}
            double distance(const Character* other)const{return index.distance(other->index);}
            void hit(int value);
            string getName()const{return name;}
            Point getLocation()const{return index;}
            bool inTeam(){return have_a_team;}
            void setTeam(bool team){have_a_team = team;}
            virtual string print()const=0;
    };
}