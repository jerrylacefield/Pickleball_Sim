//
//  team.h
//  Pickleball_Sim
//
//  Created by Jerry Lacefield on 2/20/18.
//  Copyright © 2018 Jerry Lacefield. All rights reserved.
//

#ifndef team_h
#define team_h

#include <stdlib.h>

class Team {
private:
    int points;
    int coinToss;
public:
    // Constructors and Destructor
    Team();
    ~Team();
    
    // Getters
    int getPoints();
    int getCoinToss();
    
    // Setters
    void incrementPoints(int p);
    void tossCoin(int coinSide);
};

/* Constructors */
Team::Team() {
    points = 0;
}

/* Destructors */
Team::~Team() {
    // team object destructed
}

/* Return Team Points to calling function */
Team::getPoints() {
    return points;
}

/* Return current coin toss to calling function */
Team::getCoinToss {
    return coinToss;
}

/* Increment Team Points by 1 */
Team::incrementPoints(int p) {
    points += p;
}

/* Toss coin function */
Team::tossCoin() {
    tossCoin = rand() % 2 + 1;
}

#endif /* team_h */
