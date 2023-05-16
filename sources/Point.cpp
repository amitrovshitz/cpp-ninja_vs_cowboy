#include <iostream>
#include <cmath>
#include "Point.hpp"
using namespace std;
using namespace ariel;

    
double Point::distance(Point other)const {
    return sqrt(pow(this->x - other.x, 2) + pow(this->y - other.y, 2));
}
    
string Point::print()const {
    string result = "(" + to_string(x) + "," + to_string(y) + ")\n";
    return result;
}
 