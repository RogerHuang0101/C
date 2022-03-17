/*
This class is for the player 2 (red), we can control the player by i, j, k, l key.
*/
#ifndef __GAMER_AGENT__H
#define __GAMER_AGENT__H 

#include "enviro.h"
#include "styles.h"

using namespace enviro;

class GamerController : public Process, public AgentInterface {

    public:
    GamerController() : Process(), AgentInterface(), v(0), omega(0), firing(false) {}

    void init() {
        watch("keydown", [&](Event &e) {
            auto k = e.value()["key"].get<std::string>();
            if ( k == "i" ) {
                  v = v_m;              
            } else if ( k == "k" ) {
                  v = -v_m;  
            } else if ( k == "j" ) {
                  omega = -omega_m;
            } else if ( k == "l" ) {
                  omega = omega_m;
            } 
        });        
        watch("keyup", [&](Event &e) {
            auto k = e.value()["key"].get<std::string>();
            if ( k == " " ) {
                firing = false;
            } else if ( k == "i" || k == "k" ) {
                  v = 0;               
            } else if ( k == "j" ) {
                  omega = 0;
            } else if ( k == "l" ) {
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

class Gamer : public Agent {
    public:
    Gamer(json spec, World& world) : Agent(spec, world) {
        add_process(c);
    }
    private:
    GamerController c;
};

DECLARE_INTERFACE(Gamer)

#endif