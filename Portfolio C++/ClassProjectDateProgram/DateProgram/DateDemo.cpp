//DateDemo.cpp
//Author:
//test of Date class

#include <iostream>
#include <string>
#include <iomanip>
#include "Date.h"

using namespace std;

int main() {
    
    //print to console of introduction to demo
    cout << "DateDemo starting ..." << endl << endl;
    
    //declaration of class-objects
    Date d1(2,30,1876);
    Date d2(4, 30, 1999);
    Date d3(0, 32, 2026);
    
    //functions to print shorthand and longhand of d1 object date
    d1.print();
    d1.printLong();
    cout << endl;
    
    //functions to print shorthand and longhand of d2 object date
    //to console
    d2.print();
    d2.printLong();
    cout << endl;
    
    //function to print shorthand and longhand of d3 object date
    //to console
    d3.print();
    d3.printLong();
    cout << endl;
    
    //seperate printing of d2's day, month, month name and year to console
    cout << "object d2's day is " << d2.getDay() << endl;
    cout << "object d2's month is "  << d2.getMonth() << " which is " << d2.getMonthName() << endl;
    cout << "object d2's year is " << d2.getYear() << endl;
}
