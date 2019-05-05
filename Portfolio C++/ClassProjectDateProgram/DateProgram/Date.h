//  Date.h
// Author: Jeff Springwater
// For: DateDemo.cpp
//  Header file to hold definition of class Date

#include <iostream>
#include <string>
#include <iomanip>


#ifndef Date_h
#define Date_h

//definition of class Date
class Date
{
public:
    //Default constructor
    explicit Date(int = 1, int = 1, int = 2000);
    
    //definition of functions to return month, day and year
    int getMonth();
    
    int getDay();
    
    int getYear();
    
    //definition of function to print full date
    void print();
    
    //definition of function to retrieve name of date's month
    std::string getMonthName();
    
    //definition of function to print long version of date
    void printLong();
    
private:
    //declaration of variables used in class
    int month;
    
    int day;
    
    int year;
};

#endif
