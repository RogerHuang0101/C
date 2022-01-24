#include "complex.h"
#include "gtest/gtest.h"
#include "math.h"

namespace {

    TEST(Complex, Basics) {
        Complex a = (Complex) { 2, 2},
                 b = (Complex) { -4, 5 };
        EXPECT_EQ(add(a,b).real,-2);
        EXPECT_EQ(add(a,b).imaginary,7);
        EXPECT_EQ(negate(b).real,4);
        EXPECT_EQ(negate(b).imaginary,-5);
        EXPECT_EQ(multiply(a,b).real,-18);
        EXPECT_EQ(multiply(a,b).imaginary,2);
        EXPECT_EQ(magnitude(a),sqrt(8));
    }

    

}