#include <math.h>
#include "utilities.h"
#include <vector>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <iostream>
#include <map>
using namespace std;
using std::vector;


vector<double> sort_by_magnitude(vector<double> inputVector) {
    std::sort(inputVector.begin(),inputVector.end(), [](const double& a,const double& b) {return abs(a) < abs(b);});

    std::vector<double> result;
    for ( auto x : inputVector ) {
        result.push_back(x);
    }

    return result;
    
}


TypedArray<TypedArray<double>> read_matrix_csv(const string path) {

    ifstream input(path);

    string line;
    string val;                  
    TypedArray<TypedArray<double>> result;    

    while (getline (input, line)) {        
        TypedArray<double> array;                 
        stringstream s (line);         
        while (getline (s, val, ','))       
            array.push (stod(val));  
        result.push (array);                
    }

    return result;
}


void write_matrix_csv(const TypedArray<TypedArray<double>> &matrix, const string path) {
    ofstream output;
    output.open(path);
    
    for (int i = 0; i < matrix.size(); ++i)
    {
        for (int j = 0; j < matrix.safe_get(i).size(); ++j) {
            if (j < (matrix.safe_get(i).size() - 1)) {
                output << matrix.safe_get(i).safe_get(j) << ",";
            }
            else if (j == (matrix.safe_get(i).size() - 1)) {
                output << matrix.safe_get(i).safe_get(j) << "\n";
            }
        }
    }
}

map<string, int> occurrence_map(const string path) {
    ifstream input(path);
    map<string, int> occurrence;

    string s;

    char invalid_char = '_';

    const char replaced = '^';
    

    while (getline (input, s, ' ')) {      
        // Check if string contains the character or not
        std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c){ return std::tolower(c); });
        
        if (s.back() == '"' || s.back() == ')') {
            s.pop_back();
        }

        for (int i = 1; i < s.length() - 1; i++) {
            if (s[i] == '%' || s[i] == '!' || s[i] == '?' || s[i] == ':' || s[i] == '.' || s[i] == ',' || s[i] == '#' || s[i] == '$' || s[i] == '@'
            || s[i] == '^' || s[i] == '&' || s[i] == '*' || s[i] == ')' || s[i] == '+' || s[i] == '-' || s[i] == '=' || s[i] == '~' || s[i] == '_' ) {
                replace(s.begin(), s.end(), s[i], replaced);
                continue;
            }
        }

        if (s.find(replaced) != string::npos ) {
            continue;
        }

        static int single_quote_count = 0;
        static int double_quote_count = 0;
        static string temp_string;
        if (s[0] == '\'') {
            single_quote_count += 1;
        }

        if (single_quote_count % 2 != 0) {
            
            if (s.back() == '\'') {
                
                
                temp_string += s;
                if (occurrence.find(temp_string) == occurrence.end()) {
                    occurrence[temp_string] = 1;
                }
        
                // else update the frequency
                else {
                    occurrence[temp_string]++;
                }  
                single_quote_count = 2;
                break;
            }
            temp_string += s;
            temp_string += ' ';
        }
        else {
            s.erase(remove(s.begin(), s.end(), '"'), s.end());
            s.erase(remove(s.begin(), s.end(), '('), s.end());
            s.erase(remove(s.begin(), s.end(), ')'), s.end());
            s.erase(remove(s.begin(), s.end(), '!'), s.end());
            s.erase(remove(s.begin(), s.end(), ','), s.end());
            s.erase(remove(s.begin(), s.end(), '.'), s.end());
            s.erase(remove(s.begin(), s.end(), ':'), s.end());
            s.erase(remove(s.begin(), s.end(), '?'), s.end());
            if (occurrence.find(s) == occurrence.end()) {
                occurrence.insert(make_pair(s, 1));
            }
    
            // else update the frequency
            else {
                occurrence[s]++;
            }              
        }
           
    }

    return occurrence;
}




