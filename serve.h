//
//  point.h
//  Pickleball_Sim
//
//  Created by Jerry Lacefield on 2/23/18.
//  Copyright © 2018 Jerry Lacefield. All rights reserved.
//

#ifndef point_h
#define point_h
#include "team.h"


class Point {
private:
public:
    // Constructors, Destructors
    Point();
    ~Point();
    
    Team *attacker;
    Team *defender;
    Team *returner;
};

Point::Point() {

}

Point::~Point() {
    
}

#endif /* point_h */
