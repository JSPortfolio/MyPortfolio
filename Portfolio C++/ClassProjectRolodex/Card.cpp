//Card.cpp
//author: Jeff Springwater
//file to initialize functions in Card class
#include "pch.h"
#include "Card.h"
using namespace std;

//constructor for card object
Card::Card(string fN, string lN, string occ, string addr, string pNum)
{
	setFirstName(fN);

	setLastName(lN);

	setOccupation(occ);

	setAddress(addr);

	setPhoneNumber(pNum);
}

//functions for setting and returning the last name
void Card::setLastName(string lName)
{
	lastName = lName;
}

string Card::getLastName()
{
	return lastName;
}

//functions for setting and returning the first name
void Card::setFirstName(string fName)
{
	firstName = fName;
}

string Card::getFirstName()
{
	return firstName;
}

//functions for setting and returning the occupation
void Card::setOccupation(string occPat)
{
	occupation = occPat;
}

string Card::getOccupation()
{
	return occupation;
}

//functions for setting and returning the address
void Card::setAddress(string addrss)
{
	address = addrss;
}

string Card::getAddress()
{
	return address;
}

//fuctions for seting and returning the phone number
void Card::setPhoneNumber(string phnNum)
{
	phoneNumber = phnNum;
}

string Card::getPhoneNumber()
{
	return phoneNumber;
}

//function for displaying all information
void Card::show(ostream &os)
{
	os << getFirstName() << ", " << getLastName() << ", " << getOccupation() <<
		", " << getAddress() << ", " << getPhoneNumber() << endl;
}
