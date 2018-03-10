//
//  main.cpp
//  Pickleball_Sim
//
//  Created by Jerry Lacefield on 2/15/18.
//  Copyright © 2018 Jerry Lacefield. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "randomizer.cpp"
#include "player.h"
#include "team.h"
#include "serve.h"

//function prototypes
void throwDownTheGauntlet(Player *p1, Player *p2);
bool gameOver(Player *p1, Player *p2);
void chooseStrategy(Player *p1, Player *p2, int coinSide);
void setStrategy(Player *first, Player *second);
void callFirstServe(Player *first, Player *second);
bool payoff_Mixed(Player *p1, Player *p2);
bool payoff_Matched(Player *p1, Player *p2);

int main() {
    srand (time(NULL));
    
    Team Team1, Team2;  // Team objects created
    Team *t1;
    Team *t2;      // Pointers for Team1 and Team2
    
    t1 = &Team1;
    t2 = &Team2;
    
    PointManager Manager;    // Serve object to track server status
    PointManager *pm;             // Pointer for ServerManager
    pm = &Manager;
    
    std::cout << t1 << "\t" << t2 << std::endl;
    pm->setup(t1, t2, coinToss());
    std::cout << pm->attacker << "\t" << pm->defender << "\t" << pm->returner << std::endl;
    
    
    t1->setStrategy(coinToss());
    t2->setStrategy(coinToss());
    
    
    
//    int turns = 0;
//    while (!gameOver(p1, p2)) {
//        throwDownTheGauntlet(p1, p2);
//        turns++;
//    }
    
    
    return 0;
}

/*
 Check if "Game Over" criteria is met
 First to 11, must win by at least 2 points
 */
//bool gameOver(Player *p1, Player *p2) {
//    if (p1->points >= 11 || p2->points >= 11) {
//        if (abs(p1->points - p2->points) >= 2) { return true; }
//    }
//    
//    return false;
//}

///*  */
//void throwDownTheGauntlet(Player *p1, Player *p2) {
//    int firstServe = coinToss();
//    
//    if (firstServe == 1) {
//        callFirstServe(p1, p2);
//    }
//    else {
//        callFirstServe(p2, p1);
//    }
//    
//    if (payoff_Mixed(p1, p2) || payoff_Matched(p1, p2)) {
//        p1->points += 1;
//    }
//    else {
//        p2->points += 1;
//    }
//}
