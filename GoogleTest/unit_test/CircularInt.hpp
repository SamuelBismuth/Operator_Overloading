#ifndef UNIT_TEST_CIRCULARINT_H
#define UNIT_TEST_CIRCULARINT_H

/** Includes */
#include <iostream>
#include <math.h> //Use of the ceil function.
#include <iostream>
#include <stdexcept>
#include <sstream>

using namespace std;

/**
 * \brief this class implements all the operators of the object CircularInt.
 * To implement the operators the number is first modified as the operator works, then, replace in his definition space.
 * \author Johann and Samuel.
 */
class CircularInt {
    public:
        CircularInt(const int minimum, const int maximum);
        CircularInt& operator+= (const int increment);
        CircularInt operator++ (const int increment); //a++ postfix.
        CircularInt operator- ();
        CircularInt& operator*= (const int multiplier);
        CircularInt operator/(const int divisor);

        CircularInt& operator++ (); //++a prefix.
        CircularInt& operator-= (const int decrement);
        CircularInt operator-- (const int decrement); //a-- postfix.
        CircularInt& operator-- (); //--a prefix.
        CircularInt operator%= (const int divisor);
        CircularInt operator+ (const int increment);
        CircularInt operator- (const int decrement);
        CircularInt operator* (const int multiplier);
        bool operator ==(CircularInt const& circularInt);
        bool operator !=(CircularInt const& circularInt);

        CircularInt& operator= (CircularInt circularInt);
        bool operator> (CircularInt const& circularInt) const; //Only worried about currentNumber.
        bool operator< (CircularInt const& circularInt) const; //Only worried about currentNumber.
        bool operator<= (CircularInt const& circularInt) const; //Only worried about currentNumber.
        bool operator>= (CircularInt const& circularInt) const; //Only worried about currentNumber.


        int getCurrentNumber() const;
        int getMinimum() const;
        int getMaximum() const;
        void setCurrentNumber(int numb);


    private:
        int currentNumber,
            minimum,
            maximum,
            circle;
        friend ostream& operator<< (ostream& os, const CircularInt& circularInt);
        friend CircularInt operator- (const int decrement, const CircularInt& circularInt);
        friend CircularInt operator+ (const CircularInt& circularInt1, const CircularInt& circularInt2);
        inline int moduloOperation();
        int gcdExtended(int number, int divisor, int *x, int *y);
        int modInverse(int divisor);
};

/**
 * \brief this class implements an exception of the object CircularInt.
 * \author Johann and Samuel.
 */
class NotDivisible : public runtime_error {
    public :
        NotDivisible(CircularInt circularInt, int divisor);
};

#endif // CIRCULARINT_H
