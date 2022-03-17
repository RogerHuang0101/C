/*
This class is for the player 1 (brown), we can control the player by w, s, a, d key.
*/
#ifndef __PLAYER_AGENT__H
#define __PLAYER_AGENT__H 

#include "enviro.h"
#include "styles.h"

using namespace enviro;

class PlayerController : public Process, public AgentInterface {

    public:
    PlayerController() : Process(), AgentInterface(), v(0), omega(0), firing(false) {}

    void init() {
        watch("keydown", [&](Event &e) {
            auto k = e.value()["key"].get<std::string>();
            if ( k == "w" ) {
                  v = v_m;              
            } else if ( k == "s" ) {
                  v = -v_m;  
            } else if ( k == "a" ) {
                  omega = -omega_m;
            } else if ( k == "d" ) {
                  omega = omega_m;
            } 
        });        
        watch("keyup", [&](Event &e) {
            auto k = e.value()["key"].get<std::string>();
            if ( k == " " ) {
                firing = false;
            } else if ( k == "w" || k == "s" ) {
                  v = 0;               
            } else if ( k == "a" ) {
                  omega = 0;
            } else if ( k == "d" ) {
                  omega = 0;
            } 
        });
        center(x(), y());
        zoom(1.5);
    }
    void start() { }
    void update() {
        track_velocity(v,omega,10,400);
        center(x(), y());
    }
    void stop() {}

    double v, omega;
    double const v_m = 50, omega_m = 1;
    bool firing;

};

class Player : public Agent {
    public:
    Player(json spec, World& world) : Agent(spec, world) {
        add_process(c);
    }
    private:
    PlayerController c;
};

DECLARE_INTERFACE(Player)

#endif