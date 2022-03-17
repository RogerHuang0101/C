/*
This class is for the style of the ball, ball fragment.
*/
#ifndef __BALL_STYLES__H
#define __BALL_STYLES__H

#include "enviro.h"

using namespace enviro;

const json  NEW_BALL_STYLE = { 
                {"fill", "lightblue"}, 
                {"stroke", "black"}, 
                {"strokeWidth", "10px"},
                {"strokeOpacity", "0.25"}
            },  

            BALL_FRAGMENT_STYLE = { 
                {"fill", "lightblue"}, 
                {"stroke", "black"}, 
                {"strokeWidth", "5px"},
                {"strokeOpacity", "0.25"}
            };

#endif