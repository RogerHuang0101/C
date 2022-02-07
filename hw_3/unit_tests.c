#include <math.h>
#include <float.h> /* defines DBL_EPSILON */
#include "dynamic_array.h"
#include "gtest/gtest.h"

#define X 1.2345

namespace {

    TEST(DynamicArray, CreateAndDestroy) {
        DynamicArray * a = DynamicArray_new();
        DynamicArray_destroy(a);
    }

    TEST(DynamicArray, DeathTests) {
        DynamicArray * a = DynamicArray_new();
        ASSERT_DEATH(DynamicArray_pop(a), ".*Assertion.*");
        ASSERT_DEATH(DynamicArray_pop_front(a), ".*Assertion.*");
        DynamicArray_destroy(a);
        ASSERT_DEATH(DynamicArray_size(a), ".*Assertion.*");
    }    

    TEST(DynamicArray, SmallIndex) {
        DynamicArray * da = DynamicArray_new();
        ASSERT_EQ(DynamicArray_size(da),0);
        DynamicArray_set(da, 0, -X);        
        DynamicArray_set(da, 3, X);
        ASSERT_EQ(DynamicArray_size(da),4);
        ASSERT_EQ(DynamicArray_get(da,0), -X);
        ASSERT_EQ(DynamicArray_get(da,3), X);
        DynamicArray_destroy(da);
    }

    TEST(DynamicArray, BigIndex) {
        DynamicArray * da = DynamicArray_new();
        DynamicArray_set(da, 8, X);
        ASSERT_EQ(DynamicArray_get(da,8), X);
        DynamicArray_destroy(da);              
    }

    TEST(DynamicArray, ReallyBig) {
        DynamicArray * da = DynamicArray_new();
        DynamicArray_set(da, 400, X);
        DynamicArray_set(da, 200, X/2);        
        ASSERT_EQ(DynamicArray_get(da,200), X/2);
        ASSERT_EQ(DynamicArray_get(da,400), X);
        DynamicArray_destroy(da);              
    }  

    TEST(DynamicArray, Push) {
        DynamicArray * da = DynamicArray_new();
        double x = 0;
        while ( x < 10 ) {
            DynamicArray_push(da, x);  
            x += 0.25;
        }
        ASSERT_EQ(DynamicArray_size(da),40);
        printf("Push test Intermediate Result: %s\n", 
               DynamicArray_to_string(da));
        while ( DynamicArray_size(da) > 0 ) {
            DynamicArray_pop(da);
        }
        ASSERT_EQ(DynamicArray_size(da),0);
        DynamicArray_destroy(da);          
    }

    TEST(DynamicArray, PushFront) {
        DynamicArray * da = DynamicArray_new();
        double x = 0;
        while ( x < 10 ) {
            DynamicArray_push_front(da, x);  
            x += 0.25;
        }
        ASSERT_EQ(DynamicArray_size(da),40);
        while ( DynamicArray_size(da) > 0 ) {
            DynamicArray_pop_front(da);
        }
        ASSERT_EQ(DynamicArray_size(da),0);
        DynamicArray_destroy(da);          
    } 

    TEST(DynamnicArray,ToString) {
        DynamicArray * da = DynamicArray_new();
        double x = 1.0;
        while ( x <= 5 ) {
            DynamicArray_push(da, x);  
            x += 1.0;
        }
        char * str = DynamicArray_to_string(da);
        printf("ToString Example: %s\n", str);
        ASSERT_STREQ(
            str,
            "[1.00000,2.00000,3.00000,4.00000,5.00000]"
        );
        DynamicArray_destroy(da);
        free(str);
    }

    TEST(DynamicArray, Pop) {
        DynamicArray * da = DynamicArray_new();
        double x;
        DynamicArray_push(da, X);  
        DynamicArray_push(da, X);  
        x = DynamicArray_pop(da);  
        ASSERT_EQ(DynamicArray_size(da),1);
        ASSERT_EQ(x,X);
        ASSERT_EQ(DynamicArray_get(da,1), 0.0);
        DynamicArray_destroy(da);          
    }

    TEST(DynamicArray, Map) {
        DynamicArray * t = DynamicArray_new(),
                     * y;
        double s = 0.0;
        for ( int i=0; i<628; i++ ) {
            DynamicArray_set(t, i, s);
            s = s + 0.1;
        }
        y = DynamicArray_map(t,sin);
        for (int i=0; i<DynamicArray_size(t); i++) {
            ASSERT_NEAR(
                DynamicArray_get(y,i),sin(0.1*i), 0.0001
            );
        }
        DynamicArray_destroy(t);    
        DynamicArray_destroy(y);                    
    }    

    TEST(DynamicArray, Min) {
        DynamicArray * da = DynamicArray_new();
        DynamicArray_push(da, 1);  
        DynamicArray_push(da, 2);  
        DynamicArray_push(da, 3);  
        DynamicArray_push(da, 4);
        DynamicArray_push(da, 6);  
        DynamicArray_push(da, 7);
 
        ASSERT_EQ(DynamicArray_size(da),6);
        ASSERT_EQ(DynamicArray_min(da), 1.0);
        DynamicArray_destroy(da);          
    }

    TEST(DynamicArray, Max) {
        DynamicArray * da = DynamicArray_new();
        DynamicArray_push(da, 1);  
        DynamicArray_push(da, 2);  
        DynamicArray_push(da, 3);  
        DynamicArray_push(da, 4);
        DynamicArray_push(da, 6);  
        DynamicArray_push(da, 7);
 
        ASSERT_EQ(DynamicArray_size(da),6);
        ASSERT_EQ(DynamicArray_max(da), 7.0);
        DynamicArray_destroy(da);          
    }

    TEST(DynamicArray, Mean) {
        DynamicArray * da = DynamicArray_new();
        DynamicArray_push(da, 1);  
        DynamicArray_push(da, 2);  
        DynamicArray_push(da, 3);  
        DynamicArray_push(da, 4);
        DynamicArray_push(da, 5);  
        DynamicArray_push(da, 6);
 
        ASSERT_EQ(DynamicArray_size(da),6);
        ASSERT_EQ(DynamicArray_mean(da), 3.5);
        DynamicArray_destroy(da);          
    }
    
    TEST(DynamicArray, Median) {
        DynamicArray * da = DynamicArray_new();
        DynamicArray_push(da, 1);  
        DynamicArray_push(da, 2);  
        DynamicArray_push(da, 3);  
        DynamicArray_push(da, 4);
        DynamicArray_push(da, 5);  
        DynamicArray_push(da, 6);
 
        ASSERT_EQ(DynamicArray_size(da),6);
        ASSERT_EQ(DynamicArray_median(da), 3.5);
        DynamicArray_destroy(da);          
    }
    

    TEST(DynamicArray, Sum) {
        DynamicArray * da = DynamicArray_new();
        DynamicArray_push(da, 1);  
        DynamicArray_push(da, 2);  
        DynamicArray_push(da, 3);  
        DynamicArray_push(da, 4);
        DynamicArray_push(da, 5);  
        DynamicArray_push(da, 6);
 
        ASSERT_EQ(DynamicArray_size(da),6);
        ASSERT_EQ(DynamicArray_sum(da), 21);
        DynamicArray_destroy(da);          
    }

    TEST(DynamicArray, Last) {
        DynamicArray * da = DynamicArray_new();
        DynamicArray_push(da, 1);  
        DynamicArray_push(da, 2);  
        DynamicArray_push(da, 3);  
        DynamicArray_push(da, 4);
        DynamicArray_push(da, 5);  
        DynamicArray_push(da, 7);
 
        ASSERT_EQ(DynamicArray_size(da),6);
        ASSERT_EQ(DynamicArray_last(da), 7);
        DynamicArray_destroy(da);          
    }

    TEST(DynamicArray, First) {
        DynamicArray * da = DynamicArray_new();
        DynamicArray_push(da, 5);  
        DynamicArray_push(da, 2);  
        DynamicArray_push(da, 3);  
        DynamicArray_push(da, 4);
        DynamicArray_push(da, 5);  
        DynamicArray_push(da, 7);
 
        ASSERT_EQ(DynamicArray_size(da),6);
        ASSERT_EQ(DynamicArray_first(da), 5);
        DynamicArray_destroy(da);          
    }

    TEST(DynamicArray, Copy) {
        DynamicArray * da = DynamicArray_new();
        DynamicArray_push(da, 1.00000);  
        DynamicArray_push(da, 2.00000);  
        DynamicArray_push(da, 3.00000);  
        DynamicArray_push(da, 4.00000);
        DynamicArray_push(da, 5.00000);  
        DynamicArray_push(da, 7.00000);

        printf("copy test Intermediate Result: %s\n", 
               DynamicArray_to_string(DynamicArray_copy(da)));
        for (int i = 0; i < DynamicArray_size(da); i++) {
            EXPECT_DOUBLE_EQ(DynamicArray_get(da, i), DynamicArray_get(DynamicArray_copy(da), i));
        }
        ASSERT_EQ(DynamicArray_size(DynamicArray_copy(da)),6);
        DynamicArray_destroy(da);          
    }

    TEST(DynamicArray, Range) {
        DynamicArray * da = DynamicArray_new();
        DynamicArray_push(da, 0.0);  
        DynamicArray_push(da, 0.1);  
        DynamicArray_push(da, 0.2);  
        DynamicArray_push(da, 0.3);
        DynamicArray_push(da, 0.4);  
        DynamicArray_push(da, 0.5);
        DynamicArray_push(da, 0.6);  
        DynamicArray_push(da, 0.7);  
        DynamicArray_push(da, 0.8);  
        DynamicArray_push(da, 0.9);
        DynamicArray_push(da, 1.0);  
 
        printf("range test Intermediate Result: %s\n", 
               DynamicArray_to_string(DynamicArray_range(0.0, 1.0, 0.1)));
        for (int i = 0; i < DynamicArray_size(da); i++) {
            
            EXPECT_DOUBLE_EQ(DynamicArray_get(da, i), DynamicArray_get(DynamicArray_range(0.0, 1.0, 0.1), i));
        }
        ASSERT_EQ(DynamicArray_size(DynamicArray_range(0.0, 1.0, 0.1)), 11);
        DynamicArray_destroy(da);          
    }

    TEST(DynamicArray, Concat) {
        DynamicArray * da = DynamicArray_new();
        DynamicArray_push(da, 1.00000);  
        DynamicArray_push(da, 2.00000);  
        DynamicArray_push(da, 3.00000);  

        DynamicArray * db = DynamicArray_new();
        DynamicArray_push(db, 4.00000);
        DynamicArray_push(db, 5.00000);  
        DynamicArray_push(db, 7.00000);

        DynamicArray * concat = DynamicArray_new();
        DynamicArray_push(concat, 1.00000);  
        DynamicArray_push(concat, 2.00000);  
        DynamicArray_push(concat, 3.00000);  
        DynamicArray_push(concat, 4.00000);
        DynamicArray_push(concat, 5.00000);  
        DynamicArray_push(concat, 7.00000);

        printf("copy test Intermediate Result: %s\n", 
               DynamicArray_to_string(DynamicArray_concat(da, db)));
        for (int i = 0; i < DynamicArray_size(concat); i++) {
            EXPECT_DOUBLE_EQ(DynamicArray_get(concat, i), DynamicArray_get(DynamicArray_concat(da, db), i));
        }
        ASSERT_EQ(DynamicArray_size(DynamicArray_concat(da, db)), 6);
        DynamicArray_destroy(da);   
        DynamicArray_destroy(db); 
        DynamicArray_destroy(concat);        
    }

    TEST(DynamicArray, Take) {
        DynamicArray * da = DynamicArray_range(1, 5, 1);

        DynamicArray * test1 = DynamicArray_new();
        DynamicArray_push(test1, 1.00000);  
        DynamicArray_push(test1, 2.00000);  

        DynamicArray * test2 = DynamicArray_new();
        DynamicArray_push(test2, 4.00000);  
        DynamicArray_push(test2, 5.00000); 

        DynamicArray * test3 = DynamicArray_new();
        DynamicArray_push(test3, 1.00000);  
        DynamicArray_push(test3, 2.00000); 
        DynamicArray_push(test3, 3.00000); 
        DynamicArray_push(test3, 4.00000);  
        DynamicArray_push(test3, 5.00000); 
        DynamicArray_push(test3, 0.00000);  
        DynamicArray_push(test3, 0.00000);

        printf("take test1 Intermediate Result: %s\n", 
               DynamicArray_to_string(DynamicArray_take(da, 2)));
        printf("take test1 Intermediate Result: %s\n", 
               DynamicArray_to_string(DynamicArray_take(da, -2)));
        printf("take test3 Intermediate Result: %s\n", 
               DynamicArray_to_string(DynamicArray_take(da, 7)));

        for (int i = 0; i < DynamicArray_size(test1); i++) {
            EXPECT_DOUBLE_EQ(DynamicArray_get(test1, i), DynamicArray_get(DynamicArray_take(da, 2), i));
        }

        for (int i = 0; i < DynamicArray_size(test2); i++) {
            EXPECT_DOUBLE_EQ(DynamicArray_get(test2, i), DynamicArray_get(DynamicArray_take(da, -2), i));
        }

        for (int i = 0; i < DynamicArray_size(test3); i++) {
            EXPECT_DOUBLE_EQ(DynamicArray_get(test3, i), DynamicArray_get(DynamicArray_take(da, 7), i));
        }

        ASSERT_EQ(DynamicArray_size(DynamicArray_take(da, 2)), 2);
        ASSERT_EQ(DynamicArray_size(DynamicArray_take(da, -2)), 2);
        ASSERT_EQ(DynamicArray_size(DynamicArray_take(da, 7)), 7);
        DynamicArray_destroy(da);   
        DynamicArray_destroy(test1);   
        DynamicArray_destroy(test2); 
        DynamicArray_destroy(test3);        
    }

    TEST(DynamicArray, IsValid) {
        DynamicArray * da = DynamicArray_new();
        DynamicArray_push(da, 1);  
        DynamicArray_push(da, 2);  
        DynamicArray_push(da, 3);  
        DynamicArray_push(da, 4);
        DynamicArray_push(da, 5);  
        DynamicArray_push(da, 7);
 
        ASSERT_EQ(DynamicArray_is_valid(da), 1);
        DynamicArray_destroy(da);
        ASSERT_EQ(DynamicArray_is_valid(da), 0);
        free(da);          
    }
     

}
