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
    
    // Getters
    int getPoints();
    int getStrategy();
    std::string getTeamName();
    
    // Setters
    void setStrategy(int);
    void incrementPoints();
    void setTeamName(std::string name);
};

/* Constructors */
Team::Team() {
    points = 0;
}

Team::Team(int p) {
    points = p;
}

/* Destructors */
Team::~Team() {
    // team object destructed
}

/* Return Team Points to calling function */
int Team::getPoints() {
    return points;
}

int Team::getStrategy() {
    return strategy;
}

std::string Team::getTeamName() {
    return teamName;
}

// set paddle value
void Team::setStrategy(int s) {
    strategy = s;
}

// increment point total
void Team::incrementPoints() {
    points++;
}

// set team name
void Team::setTeamName(std::string name) {
    teamName = name;
    std::cout << "Team Name is " << getTeamName() << std::endl;
}

#endif /* team_h */
