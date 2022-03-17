/*
This class is an obstacle, when the ball hit the obstacle, the ball will pop, disappear and generate another one in a random place.
At the same time, the obstacle will change to another color.
*/
#ifndef __CELL_AGENT__H
#define __CELL_AGENT__H 

#include "enviro.h"
#include "styles.h"
#include <math.h>

using namespace enviro;

class CellController : public Process, public AgentInterface {

    public:
    CellController() : Process(), AgentInterface(), infected(false), counter(0) {}

    void init() {
        //when hit the ball, ready to vanish to another color, and destroy the ball.
        notice_collisions_with("Ball", [&](Event &e) {
            int ball_id = e.value()["id"];
            Agent &ball = find_agent(ball_id);
            ball_ids.push_back(ball_id);
            attach_to(ball);
            if ( ! infected ) {
                counter = 0;
                infected = true;
            }
        });        
    }

    void start() {}

    void update() {
        double d = sqrt(x()*x() + y()*y()),
               vx = -x() / ( 1 + d ),
               vy = -y() / ( 1 + d );
        omni_apply_force(
            (rand() % fmax) - fmax/2 + 5*vx, 
            (rand() % fmax) - fmax/2 + 5*vy
        );
        //if crash with the ball, change the style of the obstacles to another color.
        if ( infected ) {
            counter++;
            set_style(infected_style());
            damp_movement();
        }
        
    }

    void stop() {
    
    }
    //determine another color
    std::string interpolate_colors(int r1,int g1,int b1,int r2,int g2,int b2) {
        char buffer[256];
        double f = 1 - ( (double) counter ) / counter_max;
        sprintf(buffer, 
          "rgb(%d,%d,%d)", 
          (int) ( r1*f + r2*(1-f) ),
          (int) ( g1*f + g2*(1-f) ),
          (int) ( b1*f + b2*(1-f) )
        );   
        return buffer;      
    }


    //use this class to change the color 
    json infected_style() {
        char buffer[256];
        double f = 1 - (double) counter / counter_max;
        return {  {"fill", interpolate_colors(144,238,144,255,255,255) }, 
                  {"stroke", "#888"}, 
                  {"strokeWidth", "10px"},
                  {"strokeOpacity", "0.25"}
              };
    }

    const int fmax = 100.0;
    int counter;
    const int counter_max = 100;
    bool infected;
    vector<int> ball_ids;
    const double rad = 8;

};

class Cell : public Agent {
    public:
    Cell(json spec, World& world) : Agent(spec, world) {
        add_process(c);
    }
    private:
    CellController c;
};

DECLARE_INTERFACE(Cell)

#endif