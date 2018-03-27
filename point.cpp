//
//  point.cpp
//  Pickleball_Sim
//
//  Created by Jerry Lacefield on 3/26/18.
//  Copyright © 2018 Jerry Lacefield. All rights reserved.
//

#include "point.h"
#include "randomizer.cpp"

// Default Constructor
PointManager::PointManager() {
    serverNumber = 2;
}

// Destructor
PointManager::~PointManager() {
    
}

/*
 Method:  Game Setup
 -------------------------------------------
 Sides are chosen, teams split up
 
 Attacker is defined as the team that is serving the ball
 and is the only team that can score a point.
 
 Defender is defined as the team that wants to be the
 Attacker and must prevent the current Attacker from scoring
 to cause a change of possession
 */
void PointManager::setup(Team *t1, Team *t2) {
    int toss = coinToss();
    if (toss == 1) {
        attacker = t1;
        returner = defender = t2;
    }
    else {
        attacker = t2;
        returner = defender = t1;
    }
}

/*
 Method:  Game Over Test
 -------------------------------------------
 After running through a serve and any number of n-returns,
 following a point that has been awarded, the game is checked
 to see if a winner is determined.  To win a game, a team must
 reach a minimum of 11 points AND win by at least 2 points.
 */
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


/*
 Method:  Serving Ball
 -------------------------------------------
 Team defined as the attacker attempts to serve the ball
 to the other team.  Serve Strategy is defined before
 doing a serve check to determine success of serve
 */
bool PointManager::serveBall() {
    //    attacker->setStrategy(coinToss());    // server swings paddle
    //    attacker->setStrategy(diceRoll(7));
    attacker->setStrategy(1);
    
    return (serveCheck());
}

bool PointManager::serveCheck() {
    //    int serve = coinToss();
    //    if (attacker->getStrategy() == 1) { return coinToss() != serve; }
    //    else { return coinToss() == serve; }
    
    //    int serve = diceRoll(6);
    //    if (attacker->getStrategy() < 4) { return diceRoll(6) < serve; }
    //    else if (attacker->getStrategy() > 4) { return diceRoll(6) > serve; }
    //    else { return diceRoll(6) == serve; }
    
    int serve = diceRoll(8);
    return diceRoll(100) >= serve;
}

void PointManager::incrementServes(bool success) {
    attacker->incrementServes(success);
}

/*
 Method:  Returning Ball
 -------------------------------------------
 Team with ball in possession attempts to hit the ball back
 to the other side of the net.  Return Strategy is defined
 before doing a hit check to determine success of return
 */
bool PointManager::returnBall() {
    //    returner->setStrategy(coinToss());
    returner->setStrategy(1);
    
    return (hitCheck());
}

bool PointManager::hitCheck() {
    //    int hit = coinToss();
    //    if (returner->getStrategy() == 1) { return coinToss() != hit; }
    //    else { return coinToss() == hit; }
    
    int hit = diceRoll(25);
    return diceRoll(50) >= hit;
}

void PointManager::incrementReturns(bool success) {
    returner->incrementReturns(success);
    if (returner != defender) {
        returner->incrementOffensiveReturns(success);
    }
    //    std::cout << "TROUBLESHOOTING " << getReturnerName() << std::endl;
}

void PointManager::moveReturner() {
    if (returner == defender) { returner = attacker; }
    else { returner = defender; }
}


/*
 Method:  Server Number Management
 -------------------------------------------
 There are only 2 possible servers; server numbers are changed
 when there is a possession change or when a serve/return by
 the attacking team fails
 */
// Changing Server Number, 1->2 or 2->1
void PointManager::changeServerNumber() {
    if (serverNumber == 1) { serverNumber = 2; }
    else { serverNumber = 1; }
}

int PointManager::getServerNumber() {
    return serverNumber;
}

/*
 Method:  Scoring A Point
 -------------------------------------------
 A simple method of giving a point to the attacker
 */
void PointManager::scorePoint() {
    //    if (attacker == t1) { t1->incrementPoints(); }
    //    else { t2->incrementPoints(); }
    attacker->incrementPoints();
}

/*
 Method:  Possession Management
 -------------------------------------------
 Change of Possession occurs when the attacking team
 fails on a serve or return AND server number is 2.
 */
void PointManager::changePossession(Team *t1, Team *t2) {
    if (attacker == t1) {
        attacker = t2;
        returner = defender = t1;
    }
    else {
        attacker = t1;
        returner = defender = t2;
    }
    serverNumber = 1;
}


// Simple name return functions
std::string PointManager::getServerName() {
    return attacker->getTeamName();
}

std::string PointManager::getReturnerName() {
    return returner->getTeamName();
}
