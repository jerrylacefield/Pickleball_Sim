//
//  main.cpp
//  Pickleball_Sim
//
//  Created by Jerry Lacefield on 2/15/18.
//  Copyright © 2018 Jerry Lacefield. All rights reserved.
//

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <term.h>

#include "player.h"
#include "team.h"
#include "serve.h"

//function prototypes
void ClearScreen();
int coinToss();
void throwDownTheGauntlet(Player *p1, Player *p2);
bool gameOver(Player *p1, Player *p2);
void chooseStrategy(Player *p1, Player *p2, int coinSide);
void setStrategy(Player *first, Player *second);
void callFirstServe(Player *first, Player *second);
bool payoff_Mixed(Player *p1, Player *p2);
bool payoff_Matched(Player *p1, Player *p2);

void pregameRoutine(Team *t1, Team *t2, Point *pm);

int main() {
    srand (time(NULL));
    
    Team Team1, Team2;  // Team objects created
    Team *t1, *t2;      // Pointers for Team1 and Team2
    
    Point PointManager;    // Serve object to track server status
    Point *pm;             // Pointer for ServerManager
    
    pregameRoutine(t1, t2, pm);
    
    
//    int turns = 0;
//    while (!gameOver(p1, p2)) {
//        throwDownTheGauntlet(p1, p2);
//        turns++;
//    }
    
    
    return 0;
}

// Pregame Routine: set attacker, defender, returner
void pregameRoutine(Team *t1, Team *t2, Point *pm) {
    int toss = coinToss();
    if (toss == 1) {
        pm->attacker = t1;
        pm->defender = t2;
        pm->returner = t2;
    }
    else {
        pm->attacker = t2;
        pm->defender = t1;
        pm->returner = t1;
    }
    std::cout << pm->attacker << " " << pm->defender << " " << pm->returner << std::endl;
}

void ClearScreen() {
    system("clear");
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

/* Coin Toss Function */
int coinToss() {
    return rand() % 2 + 1;
}

/*  */
void throwDownTheGauntlet(Player *p1, Player *p2) {
    int firstServe = coinToss();
    
    if (firstServe == 1) {
        callFirstServe(p1, p2);
    }
    else {
        callFirstServe(p2, p1);
    }
    
    if (payoff_Mixed(p1, p2) || payoff_Matched(p1, p2)) {
        p1->points += 1;
    }
    else {
        p2->points += 1;
    }
}

//// check payoff for mixed strategy
//bool payoff_Mixed(Player *p1, Player *p2) {
//    return p1->getStrategy() == 1 && p1->coinToss != p2->coinToss;
//}
//
//// check payoff for matched strategy
//bool payoff_Matched(Player *p1, Player *p2) {
//    return p1->getStrategy() != 1 && p1->coinToss == p2->coinToss;
//}
//
//void chooseStrategy(Player *p1, Player *p2, int coinSide) {
//    if (coinSide == 1) { setStrategy(p1, p2); }
//    else { setStrategy(p2, p1); }
//}
//
//void setStrategy(Player *first, Player *second) {
//    first->setStrategy(1);
//    second->setStrategy(2);
//}
//
////
//void callFirstServe(Player *first, Player *second) {
//    first->coinToss = coinToss();
//    second->coinToss = coinToss();
}
