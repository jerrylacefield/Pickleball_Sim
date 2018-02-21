//
//  player.h
//  MatchingPennies
//
//  Created by Jerry Lacefield on 2/20/18.
//  Copyright © 2018 Jerry Lacefield. All rights reserved.
//

#ifndef player_h
#define player_h

struct Player {
    int points;     // points scored
    int strategy;   // 1 - mixed, 2 - matched
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
