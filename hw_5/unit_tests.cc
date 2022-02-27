#include <math.h>
#include <float.h> /* defines DBL_EPSILON */
#include <assert.h>
#include "utilities.h"
#include <vector>
#include <map>
#include "gtest/gtest.h"

using namespace std;

namespace {

    TEST(Problem1,SortByMagnitude) {
        vector<double> Input = {-2,3.3, -5, -7, 1, 100, -20};
        vector<double> Expect = {1,-2,3.3, -5, -7, -20, 100};

        vector<double> Result = sort_by_magnitude(Input);

        for (auto data : Result) {
            cout << data <<",";
        }

        cout << endl;
        ASSERT_EQ(Result, Expect);
    }

    TEST(TypedArray, Push) {
        TypedArray<double> b;
        double value = 65.0;
        b.set(0, 100);
        b.set(1, 202);
        b.set(2, 399);

        b.push(value);
        EXPECT_EQ(b.get(0), 100);
        EXPECT_EQ(b.get(1), 202);
        EXPECT_EQ(b.get(3), 65.0);
        b.push(37.0);
        EXPECT_EQ(b.get(4), 37.0);
        EXPECT_EQ(b.size(), 5);

    }

    TEST(TypedArray, ReadCSV) {
        TypedArray<TypedArray<double>> result;

        result = read_matrix_csv("test.csv");
        EXPECT_EQ(result.get(0).get(1), 5.3);
        EXPECT_EQ(result.get(1).get(1), 6.0);

        EXPECT_EQ(result.get(2).get(2), 3.2);

        for (int i = 0; i<result.size(); ++i)
        {
           for (int j = 0; j<result.get(i).size(); ++j)
           {
               cout << result.get(i).get(j) << " ";
           }
           cout << " ";
        }

    }

    TEST(TypedArray, WriteCSV) {
        TypedArray<TypedArray<double>> matrix;

        TypedArray<double> array1;                 
        array1.push (4.2);  
        array1.push (5.3);
        array1.push (6.4);
        matrix.push (array1);
        TypedArray<double> array2;                 
        array2.push (5.5);  
        array2.push (6.0);
        array2.push (3.5);
        matrix.push (array2);
        TypedArray<double> array3;                 
        array3.push (7.8);  
        array3.push (9.8);
        array3.push (3.2);
        matrix.push (array3);

        write_matrix_csv(matrix, "output.csv");

    }

    TEST(TypedArray, OccurrenceMap) {
        map<string, int> result;

        result = occurrence_map("ascii.txt");
        

        for (auto& it : result) {
            cout << it.first << ' ' << it.second << '\n';
        }

    }

}