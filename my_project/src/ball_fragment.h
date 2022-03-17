/*
This class is for an effect of ball fragment showing. If the ball hit the goal net, destroy the ball and show the effect.
*/
#ifndef __BALL_FRAGMENT_AGENT__H
#define __BALL_FRAGMENT_AGENT__H 

#include "enviro.h"
#include <math.h>

using namespace enviro;

class BallFragmentController : public Process, public AgentInterface {

    public:
    BallFragmentController() : Process(), AgentInterface() {}

    void init() {
        counter = rand() % 8;
    }
    void start() {}
    void update() {

        if ( counter-- <= 0 ) {
            remove_agent(id());
        }
    }
    void stop() {}
    int counter;
    const int fmax = 10;

};

class BallFragment : public Agent {
    public:
    BallFragment(json spec, World& world) : Agent(spec, world) {
        add_process(c);
    }
    private:
    BallFragmentController c;
};

DECLARE_INTERFACE(BallFragment)

#endif