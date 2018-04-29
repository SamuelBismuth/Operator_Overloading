#ifndef CIRCULARINT_H
#define CIRCULARINT_H

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

        // Constructor

        CircularInt(const int minimum, const int maximum);

        // Arithmetic operators.

        void operator= (CircularInt circularInt);
        void operator= (int number);
        CircularInt operator+ (const CircularInt circularInt);
        CircularInt operator+ (const int increment);
        CircularInt operator- (const CircularInt circularInt);
        CircularInt operator- (const int decrement);
        CircularInt operator+ ();
        CircularInt operator- ();
        CircularInt operator* (const CircularInt circularInt);
        CircularInt operator* (const int multiplier);
        CircularInt operator/ (const CircularInt circularInt);
        CircularInt operator/ (const int divisor);
        CircularInt operator% (const CircularInt circularInt);
        CircularInt operator% (const int modulo);
        CircularInt& operator++ (); //++a prefix.
        CircularInt operator++ (const int increment); //a++ postfix.
        CircularInt& operator-- (); //--a prefix.
        CircularInt operator-- (const int decrement); //a-- postfix.

        // Comparison operators/relational operators.

        bool operator== (const CircularInt& circularInt);
        bool operator== (const int& number); //Only worried about currentNumber.
        bool operator!= (const CircularInt& circularInt);
        bool operator!= (const int& number); //Only worried about currentNumber.
        bool operator> (const CircularInt& circularInt) const; //Only worried about currentNumber.
        bool operator> (const int& number) const; //Only worried about currentNumber.
        bool operator< (const CircularInt& circularInt) const; //Only worried about currentNumber.
        bool operator< (const int& number) const; //Only worried about currentNumber.
        bool operator>= (const CircularInt& circularInt) const; //Only worried about currentNumber.
        bool operator>= (const int& number) const; //Only worried about currentNumber.
        bool operator<= (const CircularInt& circularInt) const; //Only worried about currentNumber.
        bool operator<= (const int& number) const; //Only worried about currentNumber.

        // Logical operators.

        bool operator! () const;
        bool operator&& (const CircularInt circularInt);
        bool operator&& (const int number);
        bool operator|| (const CircularInt circularInt);
        bool operator|| (const int number);

        // Bitwise operators.

        CircularInt operator~ ();
        CircularInt operator& (const CircularInt circularInt);
        CircularInt operator& (const int number);
        CircularInt operator| (const CircularInt circularInt);
        CircularInt operator| (const int number);
        CircularInt operator^ (const CircularInt circularInt);
        CircularInt operator^ (const int number);
        CircularInt operator<< (const CircularInt circularInt);
        CircularInt operator<< (const int number);
        CircularInt operator>> (const CircularInt circularInt);
        CircularInt operator>> (const int number);

        // Compound assignment operators.

        CircularInt& operator+= (const CircularInt circularInt);
        CircularInt& operator+= (const int increment);
        CircularInt& operator-= (const CircularInt circularInt);
        CircularInt& operator-= (const int decrement);
        CircularInt& operator*= (const CircularInt circularInt);
        CircularInt& operator*= (const int multiplier);
        CircularInt& operator/= (const CircularInt circularInt);
        CircularInt& operator/= (const int divisor);
        CircularInt& operator%= (const CircularInt circularInt);
        CircularInt& operator%= (const int divisor);
        CircularInt& operator&= (const CircularInt circularInt);
        CircularInt& operator&= (const int number);
        CircularInt& operator|= (const CircularInt circularInt);
        CircularInt& operator|= (const int number);
        CircularInt& operator^= (const CircularInt circularInt);
        CircularInt& operator^= (const int number);
        CircularInt& operator<<= (const CircularInt circularInt);
        CircularInt& operator<<= (const int number);
        CircularInt& operator>>= (const CircularInt circularInt);
        CircularInt& operator>>= (const int number);

        // Getters and setter.

        int getCurrentNumber() const;
        int getMinimum() const;
        int getMaximum() const;
        void setCurrentNumber(int numb);

    private:

        // Friend operators.

        friend CircularInt operator+ (const int increment, const CircularInt& circularInt);
        friend CircularInt operator- (const int decrement, const CircularInt& circularInt);
        friend CircularInt operator/ (const int divisor, const CircularInt& circularInt);
        friend bool operator== (const int& number, const CircularInt& circularInt); //Only worried about currentNumber.
        friend bool operator!= (const int& number, const CircularInt& circularInt); //Only worried about currentNumber.
        friend bool operator> (const int& number, const CircularInt& circularInt); //Only worried about currentNumber.
        friend bool operator< (const int& number, const CircularInt& circularInt); //Only worried about currentNumber.
        friend bool operator>= (const int& number, const CircularInt& circularInt); //Only worried about currentNumber.
        friend bool operator<= (const int& number, const CircularInt& circularInt); //Only worried about currentNumber.
        friend ostream& operator<< (ostream& os, const CircularInt& circularInt);
        friend istream& operator>> (istream& is, CircularInt& circularInt);

        // Variables.

        int currentNumber,
            minimum,
            maximum,
            circle;

        // Help function.

        inline int moduloOperation();
        inline void isDivisible(int divisor);
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
