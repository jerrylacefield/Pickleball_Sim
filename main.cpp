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

int main() {
    srand (time(NULL));
    
    Team Team1, Team2;  // Team objects created
    Team *t1;
    Team *t2;      // Pointers for Team1 and Team2
    
    Team1.setTeamName("Dinkers");
    Team2.setTeamName("Slammers");
    
    t1 = &Team1;
    t2 = &Team2;
    
    PointManager Manager;    // Serve object to track server status
    PointManager *pm;             // Pointer for ServerManager
    pm = &Manager;
    
    std::cout << t1 << "\t" << t2 << std::endl;
    pm->setup(t1, t2, coinToss());
    std::cout << pm->attacker << "\t" << pm->defender << "\t" << pm->returner << std::endl;
    
//    int i = 0;
    while (!pm->gameOver(t1, t2)) {
        if (pm->serveBall()) {
            std::cout << pm->getServerName() << " with successful serve!" << std::endl;
            
            while(pm->returnBall()) {
                std::cout << pm->getReturnerName() << " with successful return" << std::endl;
                
                if (pm->returner == pm->defender) { pm->returner = pm->attacker; }
                else { pm->returner = pm->defender; }
            }

            std::cout << pm->getReturnerName() << " with failed return" << std::endl;
            if (pm->returner == pm->defender) {
                if (pm->attacker == t1) { t1->incrementPoints(); }
                else { t2->incrementPoints(); }
                pm->returner = pm->attacker;
            }
            else { pm->returner = pm->defender; }
            

        }
        else {
            std::cout << pm->getServerName() << " with failed serve." << std::endl;
            if (pm->getServerNumber() == 2) {
                pm->changePossession(t1, t2);
            }
            else {
                pm->changeServerNumber();
            }
        }
        
        //temporary terminator
//        if (i < 12) {
//            i++;
//            t1->incrementPoints();
//        }
    }
    
    if (t1->getPoints() > t2->getPoints()) {
        std::cout << t1->getTeamName() << " won the game, " << t1->getPoints() << "-" << t2->getPoints() << std::endl;
    }
    else {
        std::cout << t2->getTeamName() << " won the game, " << t2->getPoints() << "-" << t1->getPoints() << std::endl;
    }
    
    
    
//    int turns = 0;
//    while (!gameOver(p1, p2)) {
//        throwDownTheGauntlet(p1, p2);
//        turns++;
//    }
    
    
    return 0;
}

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
