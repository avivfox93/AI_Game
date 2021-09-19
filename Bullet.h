//
// Created by Aviv on 29/06/2021.
//

#ifndef TEST_BULLET_H
#define TEST_BULLET_H


#include "Entity.h"
static const int BULLET_SPEED = 3;
static const int BULLET_POWER = 8;

using namespace std;

class Bullet : public Entity{
public:
    explicit Bullet(int x = 0, int y = 0, int team = 0, int power = BULLET_POWER) :
        Entity(x,y,BULLET_SPEED,team),power(power){}
    void SetAngle(double angle){this->angle = angle;}

protected:
    void _Tick(vector<Entity *> &entities) override;
private:
    int power;
    double angle = 0;
};


#endif //TEST_BULLET_H
