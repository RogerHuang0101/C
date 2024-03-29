#include "complex.h"
#include "gtest/gtest.h"
#include "math.h"

namespace {

    TEST(Complex, Basics) {
        Complex a = (Complex) { 3, 4 },
                 b = (Complex) { 4, 5 };
        EXPECT_EQ(add(a,b).real,7);
        EXPECT_EQ(add(a,b).imaginary,9);
        EXPECT_EQ(negate(a).real,-3);
        EXPECT_EQ(negate(a).imaginary,-4);
        EXPECT_EQ(multiply(a,b).real,-8);
        EXPECT_EQ(multiply(a,b).imaginary,31);
        EXPECT_EQ(magnitude(a),5);
    }

    

}