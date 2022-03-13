#include <iostream>
#include "stopwatch.h"
#include <ratio>

using namespace elma;
using namespace std;
using namespace std::chrono;

void Stopwatch::start() {

    time_now = high_resolution_clock::now();
    start_button = true;
}

void Stopwatch::stop() {
    double time_difference = (high_resolution_clock::now() - time_now).count();
    if(start_button) {
        seconds += time_difference;
    }
    start_button = false;
}

void Stopwatch::reset() {

    seconds = 0;
    start_button = false;

}

double Stopwatch::get_minutes() {
    typedef std::chrono::duration<double,std::ratio<1,1>> seconds_type;
    typedef duration<double,std::ratio<60,1>> minute_type;
    return minute_type(seconds_type(nanoseconds_type(seconds))).count();

}

double Stopwatch::get_seconds() {
    typedef std::chrono::duration<double,std::ratio<1,1>> seconds_type;
    return seconds_type(nanoseconds_type(seconds)).count();

}

double Stopwatch::get_milliseconds() {
    typedef std::chrono::duration<double,std::milli> milliseconds_type;
    return milliseconds_type(nanoseconds_type(seconds)).count();
}

double Stopwatch::get_nanoseconds() {

    return nanoseconds_type(seconds).count();

}