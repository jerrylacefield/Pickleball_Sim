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
    
    Team *attacker;
    Team *defender;
    Team *returner;
};

PointManager::PointManager() {

}

PointManager::~PointManager() {
    
}

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

#endif /* point_h */
