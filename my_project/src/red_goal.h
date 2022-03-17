/*
This class is for red goal net, if the ball hit the red net, the red team score one point, no matter which player score it.
*/
#ifndef __REDGOAL_AGENT__H
#define __REDGOAL_AGENT__H 

#include "enviro.h"

using namespace enviro;

class RedGoalController : public Process, public AgentInterface {

    public:
    RedGoalController() : Process(), AgentInterface(), counter(0) {}

    void init() {
        //show the current point
        label("Current point: " + std::to_string((int) counter),-20,60);           
    }

    void start() {}

    void update() {
        //if the ball hit the net, score one point
        notice_collisions_with("Ball", [&](Event &e) {
            counter += 1;
            label("Current point: " + std::to_string((int) counter),-20,60);
            
        }); 
        //if score 3 point first, the red team win
        if (counter >= 3) {
            label("Red team win!!",-350,-160);
        }
    }
    void stop() {}

    double counter;

};

class RedGoal : public Agent {
    public:
    RedGoal(json spec, World& world) : Agent(spec, world) {
        add_process(c);
    }
    private:
    RedGoalController c;
};

DECLARE_INTERFACE(RedGoal)

#endif