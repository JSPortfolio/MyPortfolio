//Card.h
//author: Jeff Springwater
//header file to define functions for Card class
#ifndef  CARD_H
#define CARD_H
#include <string>
#include <vector>
#include <iostream>

class Card
{
public:

	//definition of constructor 
	Card(std::string, std::string, std::string, std::string, std::string);
	
	//definition of set/get functions for last name value
	void setLastName(std::string);

	std::string getLastName();

	//definitio of set/get functions for first name value
	void setFirstName(std::string);

	std::string getFirstName();

	//defintion of set/get functions for occupation value
	void setOccupation(std::string);

	std::string getOccupation();

	//definition of set/get functions for address value
	void setAddress(std::string);

	std::string getAddress();

	//definition of set/get functions for phone number value
	void setPhoneNumber(std::string);

	std::string getPhoneNumber();

	//definitionof show function
	void show(std::ostream&);

//values to hold info for cards
private:
	std::string lastName;

	std::string firstName;

	std::string occupation;

	std::string address;

	std::string phoneNumber;


};


#endif // ! CARD_H

