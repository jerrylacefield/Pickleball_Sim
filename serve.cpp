//
//  serve.cpp
//  
//
//  Created by Jerry Lacefield on 3/27/18.
//

#include "point.h"

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
