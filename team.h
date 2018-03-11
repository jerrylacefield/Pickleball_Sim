//
//  team.h
//  Pickleball_Sim
//
//  Created by Jerry Lacefield on 2/20/18.
//  Copyright © 2018 Jerry Lacefield. All rights reserved.
//

#ifndef team_h
#define team_h

#include <stdlib.h>
#include <string>

class Team {
private:
    int points;
    int coinToss;
    int strategy;
    int numberServes;
    int numberGoodServes;
    int numberReturns;
    int numberGoodReturns;
    
public:
    // Constructors and Destructor
    Team();
    Team(int);
    ~Team();
    
    std::string teamName;
    
    // overloaded postfix ++ operator
    Team operator++ (int) {
        Team T(points);
        
        ++points;
        
        return T;
    }
    
    void incrementPoints();
    int getPoints();
    
    void setStrategy(int);
    int getStrategy();

    void incrementServes(bool);
    int getServes();
    int getGoodServes();

    void incrementReturns(bool);
    int getReturns();
    
    void incrementGoodReturns();
    int getGoodReturns();
    
    void setTeamName(std::string name);
    std::string getTeamName();
};

/* Constructors */
Team::Team() {
    points = 0;
    numberGoodServes = numberServes = 0;
    numberGoodReturns = numberReturns = 0;
}

Team::Team(int p) {
    points = p;
}

/* Destructors */
Team::~Team() {
    // team object destructed
}

/* 
 Method:  Points Handler
 */
void Team::incrementPoints() {
    points++;
}

int Team::getPoints() {
    return points;
}

/*
 Method:  Strategy Handler
 */
void Team::setStrategy(int s) {
    strategy = s;
}

int Team::getStrategy() {
    return strategy;
}

/*
 Method:  Serves Counter
 */
void Team::incrementServes(bool success) {
    numberServes++;
    if (success) { numberGoodServes++; }
}

int Team::getServes() {
    return numberServes;
}

int Team::getGoodServes() {
    return numberGoodServes;
}

/*
 Method:  Returns Counter
 */
void Team::incrementReturns(bool success) {
    numberReturns++;
    if (success) { numberGoodReturns++; }
}

int Team::getReturns() {
    return numberReturns;
}

int Team::getGoodReturns() {
    return numberGoodReturns;
}

/*
 Method:  Team Name Handler
 */
std::string Team::getTeamName() {
    return teamName;
}

// set team name
void Team::setTeamName(std::string name) {
    teamName = name;
}

#endif /* team_h */
