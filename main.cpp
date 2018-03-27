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

#include "player.h"
#include "team.h"
#include "point.cpp"

//function prototypes
//void runGameLong(Team *t1, Team *t2, PointManager *pm) {
//    while (!pm->gameOver(t1, t2)) {
//        if (pm->attacker == t1) {
//            std::cout << t1->getPoints() << "-" << t2->getPoints() << "-" << pm->getServerNumber();
//        }
//        else {
//            std::cout << t2->getPoints() << "-" << t1->getPoints() << "-" << pm->getServerNumber();
//        }
//        std::cout << ", " << pm->getServerName() << std::endl;
//        std::cout << "===========================================" << std::endl;
//
//        if (pm->serveBall()) {
//            std::cout << pm->getServerName() << " successfully serves the ball over the net" << std::endl;
//            pm->incrementServes(true);  // increment number of serve attempts and good serves
//
//            bool keepReturning = true;
//            while(keepReturning == true) {
//                if (pm->returnBall()) {
//                    std::cout << pm->getReturnerName() << " sends the ball back cleanly over the net" << std::endl;
//                    pm->incrementReturns(true);
//                    pm->moveReturner();
//                }
//                else {
//                    // Attempt to Return Shot failed
//                    std::cout << pm->getReturnerName() << " failed on their return shot" << std::endl;
//                    pm->incrementReturns(false);
//
//                    if (pm->returner == pm->defender) {
//                        std::cout << pm->getReturnerName() << " gave up a point to the " << pm->getServerName() << std::endl;
//                        pm->scorePoint();
//                    }
//                    else {
//                        std::cout << pm->getServerName() << " lost control of their return shot";
//                        pm->incrementServes(false);
//                        if (pm->getServerNumber() == 2) {
//                            std::cout << ", SIDE OUT"<< std::endl;
//                            pm->changePossession(t1, t2);
//                        }
//                        else {
//                            std::cout << ", ball goes to 2nd server" << std::endl;
//                            pm->changeServerNumber();
//                        }
//                    }
//                    keepReturning = false;
//                }
//            }
//        }
//        else {
//            std::cout << pm->getServerName() << " lost control of their serve";
//            pm->incrementServes(false);
//            if (pm->getServerNumber() == 2) {
//                std::cout << ", SIDE OUT" << std::endl;
//                pm->changePossession(t1, t2);
//            }
//            else {
//                std::cout << ", ball goes to 2nd server" << std::endl;
//                pm->changeServerNumber();
//            }
//        }
//        std::cout << "-------------------------------------------\n";
//    }
//}

//void runGameShort(Team *t1, Team *t2, PointManager *pm) {
//    while (!pm->gameOver(t1, t2)) {
//        if (pm->attacker == t1) {
//            std::cout << t1->getPoints() << "-" << t2->getPoints() << "-" << pm->getServerNumber();
//        }
//        else {
//            std::cout << t2->getPoints() << "-" << t1->getPoints() << "-" << pm->getServerNumber();
//        }
//        std::cout << ", " << pm->getServerName() << std::endl;
//
//        if (pm->serveBall()) {
//            pm->incrementServes(true);  // increment number of serve attempts and good serves
//
//            bool keepReturning = true;
//            while(keepReturning == true) {
//                if (pm->returnBall()) {
//                    pm->incrementReturns(true);
//                    pm->moveReturner();
//                }
//                else {
//                    // Attempt to Return Shot failed
//                    pm->incrementReturns(false);
//
//                    if (pm->returner == pm->defender) {
//                        pm->scorePoint();
//                    }
//                    else {
//                        pm->incrementServes(false);
//                        if (pm->getServerNumber() == 2) {
//                            pm->changePossession(t1, t2);
//                        }
//                        else {
//                            pm->changeServerNumber();
//                        }
//                    }
//                    keepReturning = false;
//                }
//            }
//        }
//        else {
//            pm->incrementServes(false);
//            if (pm->getServerNumber() == 2) {
//                pm->changePossession(t1, t2);
//            }
//            else {
//                pm->changeServerNumber();
//            }
//        }
//    }
//}

void runGameStatsOnly(Team *t1, Team *t2, PointManager *pm) {
    while (!pm->gameOver(t1, t2)) {
        if (pm->serveBall()) {
            pm->incrementServes(true);  // increment number of serve attempts and good serves
            
            bool keepReturning = true;
            while(keepReturning == true) {
                if (pm->returnBall()) {
                    pm->incrementReturns(true);
                    pm->moveReturner();
                }
                else {
                    pm->incrementReturns(false);
                    
                    if (pm->returner == pm->defender) { pm->scorePoint(); }
                    else {
                        pm->incrementServes(false);
                        if (pm->getServerNumber() == 2) { pm->changePossession(t1, t2); }
                        else { pm->changeServerNumber(); }
                    }
                    keepReturning = false;
                }
            }
        }
        else {
            pm->incrementServes(false);
            if (pm->getServerNumber() == 2) { pm->changePossession(t1, t2); }
            else { pm->changeServerNumber(); }
        }
    }
}


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
    
    
    pm->setup(t1, t2);
    std::cout << "\n" << std::endl;
    std::cout << pm->getServerName() << " vs. " << pm->getReturnerName() << "\n" << std::endl;
    
    runGameStatsOnly(t1, t2, pm);
    
    if (t1->getPoints() > t2->getPoints()) {
        std::cout << t1->getTeamName() << " won the game, " << t1->getPoints() << "-" << t2->getPoints() << std::endl;
    }
    else {
        std::cout << t2->getTeamName() << " won the game, " << t2->getPoints() << "-" << t1->getPoints() << std::endl;
    }
    
    std::cout << "\n\nGame Statistics\n";
    std::cout << "==============================================\n";
    std::cout << "Team Name\tPoints\tServes\tRate\tReturns\tRate\tO-Ret\tRate\tD-Ret\tRate" << std::endl;
    
    double serveRateT1 = (double(t1->getGoodServes()) / t1->getServes());
    double serveRateT2 = (double(t2->getGoodServes()) / t2->getServes());
    double returnRateT1 = (double(t1->getGoodReturns()) / t1->getReturns());
    double returnRateT2 = (double(t2->getGoodReturns()) / t2->getReturns());
    
    double offReturnRateT1 = double(t1->getGoodOffensiveReturns()) / double(t1->getOffensiveReturns());
    double offReturnRateT2 = double(t2->getGoodOffensiveReturns()) / double(t2->getOffensiveReturns());
    
    double defReturnRateT1 = double(t1->getGoodReturns() - t1->getGoodOffensiveReturns()) / double(t1->getReturns() - t1->getOffensiveReturns());
    
    double defReturnRateT2 = double(t2->getGoodReturns() - t2->getGoodOffensiveReturns()) / double(t2->getReturns() - t2->getOffensiveReturns());
    
    std::cout << std::fixed << std::setprecision(3) << std::endl;
    
    std::cout << t1->getTeamName() << "\t\t";
    std::cout << t1->getPoints() << "\t";
    std::cout << t1->getServes() << "\t" << serveRateT1 << "\t";
    std::cout << t1->getReturns() << "\t" << returnRateT1 << "\t";
    std::cout << t1->getOffensiveReturns() << "\t" << offReturnRateT1 << "\t";
    std::cout << (t1->getReturns() - t1->getOffensiveReturns()) << "\t" << defReturnRateT1 << std::endl;
    
    std::cout << t2->getTeamName() << "\t";
    std::cout << t2->getPoints() << "\t";
    std::cout << t2->getServes() << "\t" << serveRateT2 << "\t";
    std::cout << t2->getReturns() << "\t" << returnRateT2 << "\t";
    std::cout << t2->getOffensiveReturns() << "\t" << offReturnRateT2 << "\t";
    std::cout << (t2->getReturns() - t2->getOffensiveReturns()) << "\t" << defReturnRateT2 << std::endl;
    
    return 0;
}
