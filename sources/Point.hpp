#pragma once
#include <string>
#include <cmath>
#include <stdexcept>
using namespace std;

namespace ariel
{
    class Point
    {
        private:
            double x;
            double y;
    
        public:
            Point(double x, double y):x(x), y(y){};
            double getX(){return x;}
            double getY(){return y;}
            double distance(const Point other)const;
            string print()const;
            static Point moveTowards(const Point source, const Point destination, double distance)
            {///check this function.
                if(distance< 0.0)
                {
                    throw invalid_argument("the distance is always positive.");
                }
                double dx = destination.x - source.x;
                double dy = destination.y - source.y;
                double dist = sqrt(pow(dx, 2) + pow(dy, 2));
                if (dist <= distance) {
                    return destination;
                } else {
                    double ratio = distance / dist;
                    double newX = source.x + dx * ratio;
                    double newY = source.y + dy * ratio;
                    return Point(newX, newY);
                }
            }
    };
}