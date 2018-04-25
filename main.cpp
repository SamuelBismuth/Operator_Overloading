/** Include */
#include <iostream>

#include "CircularInt.hpp"

using namespace std;

int main() {

    CircularInt hour {1, 12}, hour2 {6,18};   // <hour is an integer between 1 and 12, like an hour on the clock>
	cout << hour << endl;                     // 1
	hour += 4;  cout << hour << endl;         // 5
	(hour += 2)++;  cout << hour << endl;     // 8
	hour += 18;   cout << hour << endl;       // 2   (18 hours after 8)
	cout << -hour << endl;                    // 10  (2 hours before midnight)
	hour = 1 - hour; cout << hour << endl;    // 11  (2 hours before 1)
	cout << hour + hour << endl;              // 10 (11 hours after 11)
	hour *= 2;   cout << hour << endl;        // 10 (11*2 = 11+11)
	cout << hour / 2 << endl;                 // TWO OPTIONS: 11 (since 11*2=10) or 5 (since 5*2=10 too).
	try {
		cout << hour / 3;
	} catch (const string& message) {
		cout << message << endl;     	      // "There is no number x in {1,12} such that x*3=10"
	}

	// RIDDLES (not for submission):
	//  * when is there exactly one answer to a/b?
	//  -> when a/b is an integer and there only one x such that
	// currentNumber + (ceil(b - currentNumber) / (b - a + 1)) * (b - a + 1) is included in the definition space.
	//  * when are there two or more answers to a/b?
    	//  -> when a/b is an integer and and there two x such that
	// currentNumber + (ceil(b - currentNumber) / (b - a + 1)) * (b - a + 1) is included in the definition space..
	//	* when is there no answer to a/b?
	//  -> when a/b is not an integer.

    cout << hour << endl;                      // 10
    ++hour;   cout << hour << endl;            // 11
    hour -= 5; cout << hour << endl;           // 6
    hour -= 7; cout << hour << endl;           // 11
    --hour; cout << hour << endl;              // 10
    hour--; cout << hour << endl;              // 9
    hour %= 7; cout << hour << endl;           // 3
    cout << hour + 7 << endl;                  // 10
    cout << hour - 9 << endl;                  // 6
    cout << hour * 2 << endl;                  // 3
    if (hour == hour) {
        cout << "hour == hour" << endl;        // "hour == hour"
    }
    if (!(hour != hour)) {
        cout << "!hour != hour" << endl;       // "!hour != hour"
    }
    try {
        hour %= 4; cout << hour << endl;
    } catch (const string& message) {
		cout << message << endl;               // "There is no number x in {1,12} such that x*4=3"
    }
    hour.setCurrentNumber(5);
    hour2.setCurrentNumber(10);
    cout<< "hour before equal assignment:\n" << hour << endl;  // 5
    cout<<hour.getMinimum()<<endl;              //1
    cout<<hour.getMaximum()<<endl;              //12
    hour = hour2 ;
    cout<< "hour after equal assignment:\n" <<hour << endl;                     // 10
    cout<<hour.getMinimum()<<endl;              //6
    cout<<hour.getMaximum()<<endl;              //18
    hour2.setCurrentNumber(15);
    cout << "hour:" << hour <<" "<< "hour2:" << hour2 <<endl ;
    if (hour < hour2) {
        cout << "hour < hour2" << endl;         // "hour < hour2"
    }
    if (hour <= hour2) {
        cout << "hour <= hour2" << endl;        // "hour <= hour2"
    }
    if (hour2 > hour) {
        cout << "hour2 > hour" << endl;         // "hour < hour2"
    }
    if (hour2 >= hour) {
        cout << "hour2 >= hour" << endl;        // "hour <= hour2"
    }
}
