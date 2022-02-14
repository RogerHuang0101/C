#include <math.h>
#include <float.h> /* defines DBL_EPSILON */
#include <assert.h>
#include "complex.h"
#include "typed_array.h"
#include "gtest/gtest.h"

namespace {

    TEST(Examples,Complex) {
        Complex x(1,2), y(3);
    }

    template<typename T>
    int compare(const T& x, const T& y) {
        if ( x < y ) {
            return -1;
        } else if ( y < x ) {
            return 1;
        } else {
            return 0;
        }
    }    

    TEST(Examples,Templates) {
        EXPECT_EQ(compare(1.0, 2.0), -1);
        EXPECT_EQ(compare(Complex(5,4), Complex(-3,4)), 1);
    }

    TEST(Examples,Magnitude) {
        Complex x(1,2), y(3);
        EXPECT_EQ(x.magnitude(), sqrt(5));
        EXPECT_EQ(y.magnitude(), 3);
    }

    TEST(Examples,Conjugate) {
        Complex x(1,2), y(3);
        EXPECT_EQ(x.conjugate().real(), 1);
        EXPECT_EQ(x.conjugate().imaginary(), -2);
        EXPECT_EQ(y.conjugate().real(), 3);
    }

    TEST(Examples,AddComplex) {
        Complex x(1,2), y(3,-1);
        Complex result = x + y;
        EXPECT_EQ(result.real(), 4);
        EXPECT_EQ(result.imaginary(), 1);
    }

    TEST(Examples,MultiplyComplex) {
        Complex x(1,2), y(3,-1);
        Complex result = x * y;
        EXPECT_EQ(result.real(), 5);
        EXPECT_EQ(result.imaginary(), 5);
    }
    
    TEST(Examples,EqualComplex) {
        Complex x(1,2), y(3,-1), z(1,2);
        bool result1 = (x == y);
        EXPECT_EQ(result1, 0);
        bool result2 = (x == z);
        EXPECT_EQ(result2, 1);
    }


    TEST(TypedArray, Pop) {
        TypedArray<int> b;
        double result = 0.0;
        b.set(0, 100);
        b.set(1, 202);
        b.set(2, 399);

        result = b.pop();
        EXPECT_EQ(b.get(0), 100);
        EXPECT_EQ(b.get(1), 202);
        EXPECT_EQ(result, 399);
        result = b.pop();
        EXPECT_EQ(result, 202);

        result = b.pop();
        EXPECT_EQ(result, 100);
        EXPECT_EQ(b.size(), 0);
    }

    
    TEST(TypedArray, Push) {
        TypedArray<int> b;
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

    TEST(TypedArray, PopFront) {
        TypedArray<int> b;
        double result = 0.0;
        b.set(0, 100);
        b.set(1, 202);
        b.set(2, 399);

        EXPECT_EQ(b.get(0), 100);
        EXPECT_EQ(b.get(1), 202);
        result = b.pop_front();
        EXPECT_EQ(result, 100);
        result = b.pop_front();
        EXPECT_EQ(result, 202);

        result = b.pop_front();
        EXPECT_EQ(result, 399);
        EXPECT_EQ(b.size(), 0);
    }

    TEST(TypedArray, PushFront) {
        TypedArray<int> b;
        double value = 65.0;
        b.set(0, 100);
        b.set(1, 202);
        b.set(2, 399);

        EXPECT_EQ(b.get(0), 100);
        EXPECT_EQ(b.get(1), 202);
        b.push_front(value);
        EXPECT_EQ(b.get(0), 65.0);
        b.push_front(37.0);
        EXPECT_EQ(b.get(0), 37.0);
        EXPECT_EQ(b.get(1), 65.0);
        EXPECT_EQ(b.size(), 5);

    }

    
    TEST(TypedArray, Concat) {
        TypedArray<int> a;
        a.set(0,0);
        a.set(1,1);
        TypedArray<int> b = a.concat(a).concat(a);

        EXPECT_EQ(b.get(0), 0);
        EXPECT_EQ(b.get(1), 1);
        EXPECT_EQ(b.get(2), 0);
        EXPECT_EQ(b.get(3), 1);
        EXPECT_EQ(b.get(4), 0);
        EXPECT_EQ(b.get(5), 1);
        EXPECT_EQ(b.size(), 6);

    }

    TEST(TypedArray, Reverse) {
        TypedArray<int> b;
        b.set(0, 5);
        b.set(1, 6);
        b.set(2, 7);
        b.set(3, 8);
        b.set(4, 9);

        b.reverse();
        EXPECT_EQ(b.get(0), 9);
        EXPECT_EQ(b.get(1), 8);
        EXPECT_EQ(b.get(2), 7);
        EXPECT_EQ(b.get(3), 6);
        EXPECT_EQ(b.get(4), 5);
        EXPECT_EQ(b.size(), 5);

    }

    TEST(TypedArray, Add) {
        TypedArray<int> a;
        a.set(0,0);
        a.set(1,1);
        TypedArray<int> b = a + a + a;

        EXPECT_EQ(b.get(0), 0);
        EXPECT_EQ(b.get(1), 1);
        EXPECT_EQ(b.get(2), 0);
        EXPECT_EQ(b.get(3), 1);
        EXPECT_EQ(b.get(4), 0);
        EXPECT_EQ(b.get(5), 1);
        EXPECT_EQ(b.size(), 6);

    }
    

    



}


