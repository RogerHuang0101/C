#ifndef _FILTER_H
#define _FILTER_H

#include "elma/elma.h"

using namespace elma;

class Filter : public Process {

    public:

        Filter(std::string name) : Process(name) {}
        void init() {};
        void start(){};
        void update();
        void stop() {};
        double value();

    private:
        int current_element = 0.0;
        double running_sum = 0.0;
        double current_number = 0.0;
        vector<double> number_vector; 
        double front_number = 0.0;



};  

#endif