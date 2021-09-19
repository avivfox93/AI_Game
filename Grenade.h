//
// Created by Aviv on 29/06/2021.
//

#ifndef TEST_GRENADE_H
#define TEST_GRENADE_H


#include "Entity.h"
#include "Bullet.h"
#include <cmath>

const int GRENADE_NUM_OF_BULLETS = 16;
const int GRENADE_SPEED = 2;
const int GRENADE_MAX_DISTANCE = 25;

class Grenade : public Entity{
public:
    explicit Grenade(int x = 0, int y = 0, const Point2D& target = Point2D(0,0), int team = 0) :
    Entity(x,y,GRENADE_SPEED,team), startLocation(x,y), target(target){
        UpdateAngle();
    }
    void UpdateAngle(){
        angle = Point2D::AngleBetweenPoints(location,target);
    }
protected:
    void _Tick(vector<Entity *> &entities) override;
private:
    Point2D startLocation;
    void Explode();
    Point2D target;
    double angle = 0;
};


#endif //TEST_GRENADE_H
