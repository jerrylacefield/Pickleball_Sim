//
//  serve.h
//  Pickleball_Sim
//
//  Created by Jerry Lacefield on 2/23/18.
//  Copyright © 2018 Jerry Lacefield. All rights reserved.
//

#ifndef serve_h
#define serve_h

class Serve {
private:
    int servingTeam;
    int currentServer;
public:
    // Constructors, Destructors
    Serve();
    ~Serve();
    
    // Getters
    int getServingTeam();
    int getCurrentServer();
    
    // Setters
    void setServingTeam(int team);
    void setCurrentServer(int server);
};

Serve::Serve() {
    servingTeam = 0;
}

Serve::~Serve() {
    
}

int Serve::getServingTeam() {
    return servingTeam;
}

int Serve::getCurrentServer() {
    return currentServer;
}

void Serve::setServingTeam(int team) {
    servingTeam = team;
}

void Serve::setCurrentServer(int server) {
    currentServer = server;
}

#endif /* serve_h */
