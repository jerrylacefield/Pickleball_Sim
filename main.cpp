//
//  main.cpp
//  Pickleball_Sim
//
//  Created by Jerry Lacefield on 2/15/18.
//  Copyright © 2018 Jerry Lacefield. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <time.h>
#include "randomizer.cpp"
#include "player.h"
#include "team.h"
#include "point.h"

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
    std::cout << pm->getServerName() << " vs. " << pm->getReturnerName() << "\n" << std::endl;
    
//    bool keepPlaying = true;
    while (!pm->gameOver(t1, t2)) {
        
        // Server calls the score
        if (pm->attacker == t1) {
            std::cout << t1->getPoints() << "-" << t2->getPoints() << "-" << pm->getServerNumber();
        }
        else {
            std::cout << t2->getPoints() << "-" << t1->getPoints() << "-" << pm->getServerNumber();
        }
        std::cout << ", " << pm->getServerName() << std::endl;
        std::cout << "===========================================" << std::endl;
        
        if (pm->serveBall()) {
            std::cout << pm->getServerName() << " successfully serves the ball over the net" << std::endl;
            pm->incrementServes(true);  // increment number of serve attempts and good serves
            
            bool keepReturning = true;
            while(keepReturning == true) {
                if (pm->returnBall()) {
                    std::cout << pm->getReturnerName() << " sends the ball back cleanly over the net" << std::endl;
                    pm->incrementReturns(true);
                    pm->moveReturner();
                }
                else {
                    // Attempt to Return Shot failed
                    std::cout << pm->getReturnerName() << " failed on their return shot" << std::endl;
                    pm->incrementReturns(false);
                    
                    if (pm->returner == pm->defender) {
                        std::cout << pm->getReturnerName() << " gave up a point to the " << pm->getServerName() << std::endl;
                        pm->scorePoint();
                    }
                    else {
                        std::cout << pm->getServerName() << " lost control of their return shot";
                        pm->incrementServes(false);
                        if (pm->getServerNumber() == 2) {
                            std::cout << ", SIDE OUT"<< std::endl;
                            pm->changePossession(t1, t2);
                        }
                        else {
                            std::cout << ", ball goes to 2nd server" << std::endl;
                            pm->changeServerNumber();
                        }
                    }
                    keepReturning = false;
                }
            }
        }
        else {
            std::cout << pm->getServerName() << " lost control of their serve";
            pm->incrementServes(false);
            if (pm->getServerNumber() == 2) {
                std::cout << ", SIDE OUT" << std::endl;
                pm->changePossession(t1, t2);
            }
            else {
                std::cout << ", ball goes to 2nd server" << std::endl;
                pm->changeServerNumber();
            }
        }
        std::cout << "-------------------------------------------\n";
    }
    
    if (t1->getPoints() > t2->getPoints()) {
        std::cout << t1->getTeamName() << " won the game, " << t1->getPoints() << "-" << t2->getPoints() << std::endl;
    }
    else {
        std::cout << t2->getTeamName() << " won the game, " << t2->getPoints() << "-" << t1->getPoints() << std::endl;
    }
    
    std::cout << "\n\nGame Statistics\n";
    std::cout << "==============================================\n";
    std::cout << "Team Name\tServes\tRate\tReturns\tRate\n" << std::endl;
    
    double serveRateT1 = (double(t1->getGoodServes()) / t1->getServes());
    double serveRateT2 = (double(t2->getGoodServes()) / t2->getServes());
    double returnRateT1 = (double(t1->getGoodReturns()) / t1->getReturns());
    double returnRateT2 = (double(t2->getGoodReturns()) / t2->getReturns());
    
    std::cout << std::fixed << std::setprecision(3) << std::endl;
    
    std::cout << t1->getTeamName() << "\t\t";
    std::cout << t1->getServes() << "\t" << serveRateT1 << "\t";
    std::cout << t1->getReturns() << "\t" << returnRateT1 << std::endl;
    
    std::cout << t2->getTeamName() << "\t";
    std::cout << t2->getServes() << "\t" << serveRateT2 << "\t";
    std::cout << t2->getReturns() << "\t" << returnRateT2 << std::endl;
    
    return 0;
}
