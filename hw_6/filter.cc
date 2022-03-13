#include <iostream>
#include "filter.h"
#include <random>
#include <iomanip>
#include <vector>
using namespace std;
using std::vector;

using namespace elma;

double pop_front(std::vector<double> &v)
{
    double pop_item = v[0];
    if (v.size() > 0) {
        v.erase(v.begin());                 
    }
    return pop_item;
}


void Filter::update() {
    

    if ( channel("link").nonempty() ) {
        current_number = channel("link").latest();
        number_vector.push_back(current_number);
    }
    
    if (current_element < 10) {
        running_sum += current_number;
        current_element += 1;
    }
    else {
        running_sum += current_number;
        front_number = pop_front(number_vector);
        running_sum -= front_number;
    }

    
    std::cout << " front_number: " << front_number;
    std::cout << " current_element: " << current_element;
    std::cout << " running_average: " << running_sum / current_element << "\n";

    
}

double Filter::value() {
    

    if ( channel("link").nonempty() ) {
        current_number = channel("link").latest();
        number_vector.push_back(current_number);
    }
    
    if (current_element < 10) {
        running_sum += current_number;
        current_element += 1;
    }
    else {
        running_sum += current_number;
        front_number = pop_front(number_vector);
        running_sum -= front_number;
    }


    return running_sum / current_element;
}
