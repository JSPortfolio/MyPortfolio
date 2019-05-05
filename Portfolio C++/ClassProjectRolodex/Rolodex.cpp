//Rolodx.cpp
//author: Jeff Springwater
//file to initialize functions of Rolodex
//class object
#include "pch.h"
#include "Rolodex.h"
#include <algorithm>
using namespace std;

//function to add new card/contact to rolodex
void Rolodex::add(Card newCard)
{

	currentCard = cardRoll.begin();

	//while loop to sort and organize 
	//new card alphabetically
	while (currentCard != cardRoll.end())
	{
		//if/else statement to continue or stop
		//while loop after finding alphabetically correct
		//place for new card
		if (currentCard->getLastName() > newCard.getLastName())
		{
			break;
		}

		else
		{
			currentCard++;
		}
	}
	
	//set new card and insert new card into place
	//current card points to.
	currentCard = cardRoll.insert(currentCard, newCard);
}


//function to flip through
//rolodex
Card Rolodex::flip()
{
	//increment or "flip" current card
	currentCard++;

	//if statement to change wrap-around
	//to beginning of rolodex if user
	//reaches last card.
	if (currentCard == cardRoll.end())
	{
		currentCard = cardRoll.begin();
	}

	//return current card
	return *currentCard;
}

//function to print entire list
//of contacts contained in rolodex
void Rolodex::print()
{

	std::list<Card>::iterator printCard;

	//for loop using iterator to print each card to display
	for (printCard = cardRoll.begin(); 
		printCard != cardRoll.end(); printCard++)
	{
		printCard->show(cout);

		cout << "\n";
	}
}

//function to return contact
//current card is pointing to.
Card Rolodex::getCurrentCard()
{
	return *currentCard;
}

//function to remove card/contact from
//rolodex
void Rolodex::remove()
{

	currentCard = cardRoll.erase(currentCard);

	//if statement to wrap-around if card
	//erased was last card in rolodex.
	if (currentCard == cardRoll.end())
	{

		currentCard = cardRoll.begin();
	}
}

//function to return true/false if rolodex
//contains person searched for
bool Rolodex::search(std::string &lastName, std::string &firstName)
{
	std::list<Card>::iterator searchParamter;

	searchParamter = cardRoll.begin();

	//while loop to have search iterator go through
	//entire rolodex
	while (searchParamter != cardRoll.end())
	{

		//if/else statements to check for correct
		//name of contact and move through rolodex if
		//name not found
		if (searchParamter->getLastName() == lastName)
		{
			if (searchParamter->getFirstName() == firstName)
			{
				currentCard = searchParamter;

				return true;
			}

			else
			{
				searchParamter++;
			}
		}

		else
		{
			searchParamter++;
		}
	}

	return false;
}


