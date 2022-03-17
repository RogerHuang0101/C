/*
This class is for the ball generating.
If the ball hit the brown net, score one point for brown team and destroy the ball, there're some fragment of the ball showing as an effect. The ball will be generated in a random place after destroyed.
If the ball hit the red net, score one point for red team and destroy the ball, there're some fragment of the ball showing as an effect. The ball will be generated in a random place after destroyed.
If the ball hit the obstacles cell, it will destroy the ball. The ball will be generated in a random place after destroyed.
*/
#ifndef __BALL_AGENT__H
#define __BALL_AGENT__H 

#include "enviro.h"
#include "styles.h"
#include <math.h>

using namespace enviro;

class BallController : public Process, public AgentInterface {

    public:
    BallController() : Process(), AgentInterface(), hit(false) {}

    void init() {
        notice_collisions_with("BrownGoal", [&](Event &e) {
            Agent& BrownGoal = find_agent(e.value()["id"]);
            vx = BrownGoal.velocity().x;
            vy = BrownGoal.velocity().y;
            ignore_collisions_with("BrownGoal");
            hit = true;
        }); 
        notice_collisions_with("Cell", [&](Event &e) {
            Agent& Cell = find_agent(e.value()["id"]);
            ignore_collisions_with("Cell");
            hit = true;
        });  
        notice_collisions_with("RedGoal", [&](Event &e) {
            Agent& RedGoal = find_agent(e.value()["id"]);
            vx = RedGoal.velocity().x;
            vy = RedGoal.velocity().y;
            ignore_collisions_with("RedGoal");
            hit = true;
        });         
    }

    void start() {}

    void pop() {
        for ( double theta=0; theta < 2 * M_PI; theta += M_PI / 4) {
            Agent& frag = add_agent("BallFragment", x(), y(), theta, BALL_FRAGMENT_STYLE);
            frag.omni_apply_force(
                50*cos(theta+M_PI/8) + vx, 
                50*sin(theta+M_PI/8) + vy
            );
        }  
        remove_agent(id());
    }    

    void update() {
        double d = sqrt(x()*x() + y()*y()),
               vx = -x() / ( 1 + d ),
               vy = -y() / ( 1 + d );        
        omni_apply_force(
            (rand() % fmax) - fmax/2 + 2*vx, 
            (rand() % fmax) - fmax/2 + 2*vy
        );
        if ( hit ) {
            pop();
            Agent& newAgent = add_agent("Ball", -300 + rand() % ( 600 ),  -150 + rand() % ( 300 ), 0, NEW_BALL_STYLE);

        } 
    }

    void stop() {}

    const int fmax = 100.0;
    bool hit;
    double vx, vy;         

};

class Ball : public Agent {
    public:
    Ball(json spec, World& world) : Agent(spec, world) {
        add_process(c);
    }
    private:
    BallController c;
};

DECLARE_INTERFACE(Ball)

#endif