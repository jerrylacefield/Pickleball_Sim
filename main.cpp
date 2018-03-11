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
    
    
    pm->setup(t1, t2, coinToss());
    std::cout << pm->getServerName() << " vs. " << pm->getReturnerName() << std::endl;
    
    
    while (!pm->gameOver(t1, t2)) {
        // call the score
        std::cout << pm->getServerName() << " serving, ";
        if (pm->attacker == t1) {
            std::cout << t1->getPoints() << "-" << t2->getPoints() << ", Server " << pm->getServerNumber() << std::endl;
        }
        else {
            std::cout << t2->getPoints() << "-" << t1->getPoints() << ", Server " << pm->getServerNumber() << std::endl;
        }
        
        if (pm->serveBall()) {
            std::cout << pm->getServerName() << " successfully serves the ball over the net!" << std::endl;
            
            while(pm->returnBall()) {
                std::cout << pm->getReturnerName() << " sends the ball back" << std::endl;
                
                if (pm->returner == pm->defender) { pm->returner = pm->attacker; }
                else { pm->returner = pm->defender; }
            }

            std::cout << pm->getReturnerName() << " fails to defend the attacker, giving up a point" << std::endl;
            if (pm->returner == pm->defender) {
                pm->scorePoint(t1, t2);
                pm->returner = pm->attacker;
            }
            else { pm->returner = pm->defender; }
            

        }
        else {
            std::cout << pm->getServerName() << " lost control of their serve" << std::endl;
            if (pm->getServerNumber() == 2) {
                pm->changePossession(t1, t2);
                std::cout << "Side-out, ball goes to other side" << std::endl;
            }
            else {
                std::cout << "Attack failed, server change to second server" << std::endl;
            }
            pm->changeServerNumber();
        }
        std::cout << "-------------------------------------------\n";
    }
    
    if (t1->getPoints() > t2->getPoints()) {
        std::cout << t1->getTeamName() << " won the game, " << t1->getPoints() << "-" << t2->getPoints() << std::endl;
    }
    else {
        std::cout << t2->getTeamName() << " won the game, " << t2->getPoints() << "-" << t1->getPoints() << std::endl;
    }
    
    return 0;
}
