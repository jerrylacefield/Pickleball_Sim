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

int main() {
    srand (time(NULL));
    
    Player player1, player2;
    Player *p1, *p2;
    
    int coinSide = coinToss();  // perform coin toss to set strategies (mix or match) for each player
    
    p1 = &player1;
    p2 = &player2;
    
    chooseStrategy(p1, p2, coinSide);
    
    int turns = 0;
    while (!gameOver(p1, p2)) {
        throwDownTheGauntlet(p1, p2);
//        ClearScreen();
        turns++;
    }
    
    if (p1->points > p2->points) {
        std::cout << "1 " << p1->points << " " >> p2->points << std::endl;
//        printf("Final Score: %d-%d, Player 1 wins the game\n", p1->points, p2->points);
    }
    else {
        std::cout << "2 " << p1->points << " " << p2->points << std::endl;

//        printf("Final Score: %d-%d, Player 2 wins the game\n", p2->points, p1->points);
    }
    
    return 0;
}

void ClearScreen() {
    system("clear");
}

/*
 Check if "Game Over" criteria is met
 First to 11, must win by at least 2 points
 */
bool gameOver(Player *p1, Player *p2) {
    if (p1->points >= 11 || p2->points >= 11) {
        if (abs(p1->points - p2->points) >= 2) { return true; }
    }
    
    return false;
}

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

// check payoff for mixed strategy
bool payoff_Mixed(Player *p1, Player *p2) {
    return p1->getStrategy() == 1 && p1->coinToss != p2->coinToss;
}

// check payoff for matched strategy
bool payoff_Matched(Player *p1, Player *p2) {
    return p1->getStrategy() != 1 && p1->coinToss == p2->coinToss;
}

void chooseStrategy(Player *p1, Player *p2, int coinSide) {
    if (coinSide == 1) { setStrategy(p1, p2); }
    else { setStrategy(p2, p1); }
}

void setStrategy(Player *first, Player *second) {
    first->setStrategy(1);
    second->setStrategy(2);
}

//
void callFirstServe(Player *first, Player *second) {
    first->coinToss = coinToss();
    second->coinToss = coinToss();
}
