//
// Created by Aviv on 08/07/2021.
//

#include "DummyGrenade.h"
#include <cmath>
#include "Grenade.h"

#ifndef M_PI
#define M_PI (3.14159265359)
#endif

void DummyBullet::Simulate() {
    auto& sMap = Game::GetInstance().BOARD_SECURITY;
    auto& board = Game::GetInstance().BOARD;
    bool simulate = true;
    while(simulate){
        int x = (int)round(location.x);
        int y = (int)round(location.y);
        if(dynamic_cast<Wall*>(board[x][y])){
            simulate = false;
        }else{
            sMap[x][y] += power;
            location += Point2D(std::cos(angle),std::sin(angle));
        }
    }
}

void DummyGrenade::Simulate() {
    for(int i = 0 ; i < GRENADE_NUM_OF_BULLETS ; i++){
        auto bullet = DummyBullet(location,(i*2*M_PI)/GRENADE_NUM_OF_BULLETS,bulletPower);
        bullet.Simulate();
    }
}
