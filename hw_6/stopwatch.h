#ifndef _STOPWATCH_H
#define _STOPWATCH_H

#include "elma/elma.h"
#include <stdio.h>

using namespace elma;
using namespace std::chrono;

class Stopwatch{

    public:

        Stopwatch(){};
        void start();              // starts the timer
        void stop();               // stops the timer
        void reset();              // sets stopwatch to zero
        double get_minutes();      // number of minutes counted, as a double
        double get_seconds();      // number of seconds counted, as a double
        double get_milliseconds(); // number of milliseconds counted, as a double
        double get_nanoseconds();  // number of nanoseconds counted, as a double

    private:
        typedef std::chrono::duration<double,std::nano> nanoseconds_type;
        bool start_button = false;
        double seconds = 0;
        high_resolution_clock::time_point time_now;

};

#endif
