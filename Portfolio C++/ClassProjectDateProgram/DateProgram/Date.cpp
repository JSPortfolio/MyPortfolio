//
//Date.cpp
//Author: Jeff Springwater
//For: DateDemo.cpp
// implementation of member functions of class Date

#include <stdio.h>
#include <iostream>
#include <string>
#include <iomanip>

#include "Date.h"

using namespace std;

//Constructor to check parameters of date
//and acceptable apply value if necessary
Date::Date(int m, int d, int y)
{
    //if/else statements to check month is between
    //1-12 and default value if conditions are not met
    if (m >= 1 && m <= 12)
    {
        month = m;
    }
    
    else
    {
        month = 1;
    }
    
    //if/else statements to check day is within
    //proper range of the month assigned to date
    //and to set a default value if conditions are
    //not met
    if (month == 2)
    {
        if (d <= 28 && d >= 1)
        {
            day = d;
        }
        
        else
        {
            day = 1;
        }
    }
    
    else if (month == 4 || month == 6 || month == 9
            || month == 11)
    {
        if (d >= 1 && d <= 30)
        {
            day = d;
        }
        
        else
        {
            day = 1;
        }
    }
    else if (month == 1 || month == 3 || month == 5
            || month == 7 || month == 8 || month == 10
            || month == 12 )
    {
        if (d <= 31 && d >= 1)
        {
            day = d;
        }
        
        else
        {
            day = 1;
        }
    }
    
    //if/else statement to check if year is
    //after 1900 and set it to 1900 if
    //it is not.
    if (y >= 1900)
    {
        year = y;
    }
    
    else
    {
        year = 1900;
    }
}

//function to return month value
int Date::getMonth()
{
    return month;
}

//function to return day value
int Date::getDay()
{
    return day;
}

//function to return year value
int Date::getYear()
{
    return year;
}

//function to print shorthand version of date to console.
void Date::print()
{
    cout << setfill('0') << setw(2) << getMonth() <<
    "/" << setfill('0') << setw(2) << getDay() << "/"
    << getYear() << endl;
}

//function to return date's month in name form
std::string Date::getMonthName()
{
    //string object to hold name of month
    string monthName;
    
    //if/else statement to compare month value to
    //appropriate name.
    if (month == 1)
    {
        string monthName = "January";
        
        return monthName;
    }
    
    else if (month == 2)
    {
        string monthName = "February";
        
        return monthName;
    }
    
    else if (month == 3)
    {
        string monthName = "March";
        
        return monthName;
    }
    
    else if (month == 4)
    {
        string monthName = "April";
        
        return monthName;
    }
    
    else if (month == 5)
    {
        string monthName = "May";
        
        return monthName;
    }
    
    else if (month == 6)
    {
        string monthName = "April";
        
        return monthName;
    }
    
    else if (month == 7)
    {
        string monthName = "July";
        
        return monthName;
    }
    
    else if (month == 8)
    {
        string monthName = "August";
        
        return monthName;
    }
    
    else if (month == 9)
    {
        string monthName = "September";
        
        return monthName;
    }
    
    else if (month == 10)
    {
        string monthName = "October";
        
        return monthName;
    }
    
    else if (month == 11)
    {
        string monthName = "November";
        
        return monthName;
    }
    
    else if (month == 12)
    {
        string monthName = "December";
        
        return monthName;
    }
    return monthName;
    
}

//function to print longhand version of date to console
void Date::printLong()
{
    cout << getDay() << " " << getMonthName()
    << " " << getYear() << endl;
}

