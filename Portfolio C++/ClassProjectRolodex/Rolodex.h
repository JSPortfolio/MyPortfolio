//Rolodex.h
//author:Jeff Springwater
//header file for Rolodex class object

#ifndef  ROLODEX_H
#define ROLODEX_H
#include "Card.h"
#include <list>
#include <iterator>

class Rolodex {
public:
	
	//definition of add function
	void add(Card);

	//definition of flip function
	Card flip();

	//definition of print function
	void print();
	
	//definition of get current card function
	Card getCurrentCard();

	//definition of remove function
	void remove();

	//definition of search function
	bool search(std::string&, std::string&);


private:
	std::list<Card>cardRoll;

	std::list<Card>::iterator currentCard;

};

#endif // ! ROLODEX_H

