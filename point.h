//
//  point.h
//  Pickleball_Sim
//
//  Created by Jerry Lacefield on 2/23/18.
//  Copyright © 2018 Jerry Lacefield. All rights reserved.
//

#ifndef point_h
#define point_h

#include "team.h"
#include "randomizer.h"
#include <time.h>

class PointManager {
private:
    int serverNumber;
public:
    // Constructors, Destructors
    PointManager();
    ~PointManager();
    
    void setup(Team *t1, Team *t2);
    
    bool gameOver(Team *t1, Team *t2);
    bool minScoreMet(Team *t);
    bool minScoreDiff(Team *t1, Team *t2);
    
    bool serveBall();
    bool serveCheck();
    void incrementServes(bool success);
    
    bool returnBall();
    bool hitCheck();
    void incrementReturns(bool success);
    void moveReturner();
    
    void scorePoint();
    
    Team *attacker;
    Team *defender;
    Team *returner;
    
    void changeServerNumber();
    int getServerNumber();
    void changePossession(Team *t1, Team *t2);
    std::string getServerName();
    std::string getReturnerName();
};

#endif /* point_h */
