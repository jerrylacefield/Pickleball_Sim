//
//  point.h
//  Pickleball_Sim
//
//  Created by Jerry Lacefield on 2/23/18.
//  Copyright © 2018 Jerry Lacefield. All rights reserved.
//

#ifndef point_h
#define point_h

#include <time.h>
#include "team.h"


class PointManager {
private:
public:
    // Constructors, Destructors
    PointManager();
    ~PointManager();
    
    void setup(Team *t1, Team *t2, int toss);
    bool gameOver(Team *t1, Team *t2);
    bool minScoreMet(Team *t);
    bool minScoreDiff(Team *t1, Team *t2);
    
    Team *attacker;
    Team *defender;
    Team *returner;
};

// Default Constructor
PointManager::PointManager() {

}

// Destructor
PointManager::~PointManager() {
    
}

// game setup
void PointManager::setup(Team *t1, Team *t2, int toss) {
    if (toss == 1) {
        attacker = t1;
        defender = t2;
        returner = t2;
    }
    else {
        attacker = t2;
        defender = t1;
        returner = t1;
    }
}

// check if game over conditions apply, returns boolean value
bool PointManager::gameOver(Team *t1, Team *t2) {
    if ((minScoreMet(t1) || minScoreMet(t2)) && minScoreDiff(t1, t2)) { return true; }
    return false;
}

bool PointManager::minScoreMet(Team *t) {
    return (t->getPoints() >= 11);
}

bool PointManager::minScoreDiff(Team *t1, Team *t2) {
    return (abs(t1->getPoints() - t2->getPoints()) >= 2);
}

#endif /* point_h */
