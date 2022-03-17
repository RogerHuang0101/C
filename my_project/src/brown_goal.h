/*
This class is for brown goal net, if the ball hit the brown net, the brown team score one point, no matter which player score it.
*/
#ifndef __BROWNGOAL_AGENT__H
#define __BROWNGOAL_AGENT__H 

#include "enviro.h"

using namespace enviro;

class BrownGoalController : public Process, public AgentInterface {

    public:
    BrownGoalController() : Process(), AgentInterface(), counter(0) {}

    void init() {
        //show the current point
        label("Current point: " + std::to_string((int) counter),-30,-60);             
    }

    void start() {}

    void update() {
        //if the ball hit the goal net, score 1 point
        notice_collisions_with("Ball", [&](Event &e) {
            counter += 1;
            label("Current point: " + std::to_string((int) counter),-30,-60);
            
        }); 
        //if score 3 point first, the brown team win
        if (counter >= 3) {
            label("Brown team win!!",270,160);
        }
    }
    void stop() {}

    double counter;

};

class BrwonGoal : public Agent {
    public:
    BrwonGoal(json spec, World& world) : Agent(spec, world) {
        add_process(c);
    }
    private:
    BrownGoalController c;
};

DECLARE_INTERFACE(BrwonGoal)

#endif