//
//  randomizer.cpp
//  Pickleball_Sim
//
//  Created by Jerry Lacefield on 3/10/18.
//  Copyright © 2018 Jerry Lacefield. All rights reserved.
//

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// coin toss, simple 50/50 probability
int coinToss() {
    return rand() % 2 + 1;
}

// dice roll takes number of sides on the dice
int diceRoll(int n) {
    return rand() % n + 1;
}
