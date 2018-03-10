//
//  player.h
//  Pickleball_Sim
//
//  Created by Jerry Lacefield on 2/20/18.
//  Copyright © 2018 Jerry Lacefield. All rights reserved.
//

#ifndef player_h
#define player_h

struct Player {
    int points;     // points scored
    int strategy;   // Value between 0-99, determines failure probability
    int coinToss;   // holds value for current coin toss
    void setStrategy(int coinToss);
    int getStrategy();
    Player();
    ~Player();
};

Player::Player() {
    points = 0;
}

Player::~Player() {
    
}

void Player::setStrategy(int coinToss) {
    strategy = coinToss;
}

int Player::getStrategy() {
    return strategy;
}

#endif /* player_h */
