//
//  test.cpp
//  Assignement3
//
//  Created by SAMUEL & JOHANN on 02/04/2018.
//  Copyright © 2018 SAMUEL & JOHANN. All rights reserved.
//

/*
 test.cpp do Unitesting in several way on the functions of CircularInt.hpp.
 here we included the gtest/gtest.h header that allow us to execute Google Tests.
*/
#include <iostream>
#include "CircularInt.hpp"
#include "gtest/gtest.h"
namespace {


/**
 * hour is the object that we used for testing.
 * note that we are initialize the value of 'currentNumber' to 1 when we need it for the tests(via: hour.setCurrentNumber(1);)
 */

CircularInt hour  {1, 12};



/**
 *Testing the Arithmetic operator +,-,*,/(Addition,substraction,multiplication and division)
 */
TEST(Arithmetic,Addition)
{
    hour = hour + 4 ;
    int result = hour.getCurrentNumber();
    hour = hour + 16 ;
    int result2 = hour.getCurrentNumber();
    
    EXPECT_EQ(5, result);
    EXPECT_EQ(9, result2);
}
TEST(Arithmetic,Substraction)
{
    hour.setCurrentNumber(1);
    hour = hour - 4 ;
    int result = hour.getCurrentNumber();
    hour = hour - 16 ;
    int result2 = hour.getCurrentNumber();
    
    EXPECT_EQ(9, result);
    EXPECT_EQ(5, result2);
}
TEST(Arithmetic,UnaryMinus)
{
    hour.setCurrentNumber(4);
    hour = -hour ;
    int result = hour.getCurrentNumber();
    hour = 2 - hour ;
    int result2 = hour.getCurrentNumber();
    
    EXPECT_EQ(8, result);
    EXPECT_EQ(6, result2);
}

TEST(Arithmetic,Multiplication)
{
    hour.setCurrentNumber(1);
    hour = hour * 4 ;
    int result = hour.getCurrentNumber();
    hour = hour * 5 ;
    int result2 = hour.getCurrentNumber();
    
    EXPECT_EQ(4, result);
    EXPECT_EQ(8, result2);
}

TEST(Arithmetic,Division)
{
    hour.setCurrentNumber(10);
    hour = hour / 2 ;
    int result = hour.getCurrentNumber();
    EXPECT_EQ(5, result);
}


/**
 *Testing the operator a+= (Addition assignment)
 */
TEST(AdditionAssignment, positiveNum)
{
    hour.setCurrentNumber(1);
    hour += 4 ;
    int result = hour.getCurrentNumber();
    hour += 20 ;
    int result2 = hour.getCurrentNumber();

   EXPECT_EQ(5, result);
    EXPECT_EQ(1, result2);
}

TEST(AdditionAssignment, negativeNum)
{
    hour += -4 ;
    int result = hour.getCurrentNumber();
    hour += -20 ;
    int result2 = hour.getCurrentNumber();
    EXPECT_EQ(9, result);
    EXPECT_EQ(1, result2);
}
TEST(AdditionAssignment, DoubleNum)
{
    hour += 4.5 ;
    double result = hour.getCurrentNumber();
    hour += 20.6 ;
    double result2 = hour.getCurrentNumber();
    EXPECT_EQ(5, result);
    EXPECT_EQ(1, result2);
}
/**
 *Testing the operator a-= (Subtraction assignment)
 */
TEST(SubstractionAssignment, positiveNum)
{
    hour -= 4 ;
    int result = hour.getCurrentNumber();
    hour -= 20 ;
    int result2 = hour.getCurrentNumber();
    
    EXPECT_EQ(9, result);
    EXPECT_EQ(1, result2);
}

TEST(SubstractionAssignment, negativeNum)
{
    hour -= -4 ;
    int result = hour.getCurrentNumber();
    hour -= -20 ;
    int result2 = hour.getCurrentNumber();
    EXPECT_EQ(5, result);
    EXPECT_EQ(1, result2);
}
TEST(SubstractionAssignment, DoubleNum)
{
    hour -= 4.5 ;
    double result = hour.getCurrentNumber();
    hour -= 20.6 ;
    double result2 = hour.getCurrentNumber();
    EXPECT_EQ(9, result);
    EXPECT_EQ(1, result2);
}

/**
 *Testing the operator ++ (Increment)
 */
TEST(Increment, postfix)
{
    hour.setCurrentNumber(1);
    int result = hour++.getCurrentNumber();
    int result2 = hour.getCurrentNumber();
    
    EXPECT_EQ(1, result);
    EXPECT_EQ(2, result2);
}

TEST(Increment, prefix)
{
    hour.setCurrentNumber(1);
    CircularInt hour2 = ++hour;
    int result = hour.getCurrentNumber();
    int result2 = hour2.getCurrentNumber();
    
    EXPECT_EQ(2, result);
    EXPECT_EQ(2, result2);
}

/**
 *Testing the operator -- (decrement)
 */
TEST(Decrement, postfix)
{
    hour.setCurrentNumber(1);
    int result = hour--.getCurrentNumber();
    int result2 = hour.getCurrentNumber();
    EXPECT_EQ(1, result);
    EXPECT_EQ(12, result2);
}

TEST(Decrement, prefix)
{
    hour.setCurrentNumber(1);
    CircularInt hour2 = --hour;
    int result = hour.getCurrentNumber();
    int result2 = hour2.getCurrentNumber();

    EXPECT_EQ(12, result);
    EXPECT_EQ(12, result2);

}



/**
 *Testing the operator a*= (Multiplication assignment)
 */
TEST(MultiplicationAssignment, positiveNum)
{
    hour.setCurrentNumber(1);
    hour *= 4 ;
    int result = hour.getCurrentNumber();
    hour *= 13 ;
    int result2 = hour.getCurrentNumber();
    
    EXPECT_EQ(4, result);
    EXPECT_EQ(4, result2);
}
 // to check
TEST(MultiplicationAssignment, negativeNum)
{
    hour.setCurrentNumber(1) ;
    hour *= -4 ;
    int result = hour.getCurrentNumber();
    hour.setCurrentNumber(1) ;
    hour *= -20 ;
    int result2 = hour.getCurrentNumber();
    EXPECT_EQ(8, result);
    EXPECT_EQ(4, result2);
}
// to check
TEST(MultiplicationAssignment, DoubleNum)
{
    hour.setCurrentNumber(1) ;
    hour *= 4.5 ;
    double result = hour.getCurrentNumber();
    hour.setCurrentNumber(1) ;
    hour *= 20.6 ;
    double result2 = hour.getCurrentNumber();
    EXPECT_EQ(4, result);
    EXPECT_EQ(8, result2);
}
/**
 *Testing the operator / (division)
 */
TEST(Division, positiveNum)
{
    hour.setCurrentNumber(10) ;
     hour = hour / 2;
    int result = hour.getCurrentNumber();
    ASSERT_TRUE( result == 11 || result == 5);
}
    
    /**
     *Testing the operator = (equal assignment)
     */
TEST(Equal_Assignment, sameCircle)
{
    CircularInt hour {1, 12}, hour2 {1,12};
    hour2.setCurrentNumber(12);
    hour = hour2 ;
    int result = hour.getCurrentNumber();
    ASSERT_TRUE( hour == hour2);
    EXPECT_EQ(12, result);
}
    TEST(Equal_Assignment, differentCircle)
    {
        CircularInt hour {1, 12}, hour2 {1,24};
        hour = hour2 ;
        int result = hour.getMaximum();
        ASSERT_TRUE( hour == hour2);
        EXPECT_EQ(24, result);
    }

    /**
     *Testing the operators >,<,<=,>= (Boolean)
     */
    TEST(Bool, bigger)
    {
        CircularInt hour {1, 12}, hour2 {1,12};
        hour2.setCurrentNumber(12);
        ASSERT_TRUE( hour2 > hour);
    }
    TEST(Bool, smaller)
    {
        CircularInt hour {1, 12}, hour2 {1,12};
        hour2.setCurrentNumber(12);
        ASSERT_TRUE( hour < hour2);
    }
    TEST(Bool, Bigger_or_Equal)
    {
        CircularInt hour {1, 12}, hour2 {1,12}, hour3 {1,12};
        hour3.setCurrentNumber(12);
        ASSERT_TRUE( hour2 >= hour);
        ASSERT_TRUE( hour3 >= hour);
    }
    
    TEST(Bool, Smaller_or_Equal)
    {
        CircularInt hour {1, 12}, hour2 {1,12}, hour3 {1,12};
        hour3.setCurrentNumber(12);
        ASSERT_TRUE( hour <= hour2);
        ASSERT_TRUE( hour <= hour3);
    }
} // namespace

/**
// this main method is run under src>gtest_main.cc
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
*/

