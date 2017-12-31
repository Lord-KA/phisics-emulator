#include "universe.hpp"

#include <stdio.h>

void universe :: addBody(body b)
{
    this->bodies.push_back(b);
}

void universe :: addForce(forceFunction f)
{
    this->forces.push_back(f);
}

void universe :: update(double time)
{
    for(forceFunction f : this->forces)
    for(body a : this->bodies)
    {
        for(body b : this->bodies)
        {
            if(&a != &b)
            {
                a.applicateForce(b, f);
                b.applicateForce(a, f);
            }
        }
    }

    for(body a : this->bodies)
        a.move(time);
}

vector<body> universe :: getBodies()
{
    return this->bodies;
}

void universe :: print()
{
    for(body b : this->bodies)
    {
        vector2d pos = b.getPosition();
        vector2d vel = b.getVelocity();
        printf("position %lf %lf\n", pos.getX(), pos.getY());
        printf("velocity %lf %lf\n", vel.getX(), vel.getY());
    }
}