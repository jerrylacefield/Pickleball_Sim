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
    int strategy;
    
public:
    // Constructors and Destructor
    Team();
    ~Team();
    
    // overloaded prefix ++ operator
    Team operator++ (int) {
        ++points;
        
        return Team();
    }
    
    // Getters
    int getPoints();
    int getCoinToss();
    
    // Setters
    void tossCoin(int coinSide);
    void setStrategy(int);
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
int Team::getPoints() {
    return points;
}


/* Toss coin function */
//void Team::tossCoin() {
//    tossCoin = rand() % 2 + 1;
//}

#endif /* team_h */
