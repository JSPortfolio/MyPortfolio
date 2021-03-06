// main.cpp
//author: Jeff Springwater
//main fie

#include "pch.h"
#include "Card.h"
#include "Rolodex.h"
#include <iostream>
using namespace std;

void split(const std::string& in, std::vector<std::string>& out, const char* delim = " \r\n\t")
{
	std::string::size_type firstPos = in.find_first_not_of(delim);
	std::string::size_type secondPos = in.find_first_of(delim, firstPos);
	out.clear();

	if (firstPos != std::string::npos)
		out.push_back(in.substr(firstPos, secondPos - firstPos));

	while (secondPos != std::string::npos)
	{
		firstPos = in.find_first_not_of(delim, secondPos);
		if (firstPos == std::string::npos)
			break;
		secondPos = in.find_first_of(delim, firstPos);
		out.push_back(in.substr(firstPos, secondPos - firstPos));
	}
}

int main()
{
	//delcaration of rolodex object and string for user input.
	Rolodex rolo;
	
	string userInput;

	//use of add function to add starting info to 
	//rolodex
	rolo.add(Card("Tony", "Hansen", "Writer", "12 E. St. NY, NY 33333", "555-9999"));
	rolo.add(Card("Jon", "Smyth", "Computer Hardware", "CMU Computer Services Pittsburgh, PA", "555-1324"));
	rolo.add(Card("Alonza", "Heard", "Mechanic", "123 Anyplace Ave Malden, MA", "555-5678"));
	rolo.add(Card("Jen", "Reyes", "Graphic artist", "325 Oak Rd Wilmington, MA", "555-4950"));
	rolo.add(Card("Alan", "Lupine", "Vet", "1 Bigelow Ave. Lawrence, MA", "555-7654"));
	rolo.add(Card("Jewel", "Proverb", "Landscaper", "34 Washington St. Waltham, MA", "555-3333"));
	rolo.add(Card("Paul", "Revere", "Radical Revolutionary", "45 Commonwealth Ave. Boston, MA", "555-1776"));
	rolo.add(Card("Adolf", "Coors", "Beer Manufacturer", "Boston MA", "555-2337"));
	rolo.add(Card("Seymour", "Papert", "Lego Professor", "MIT", "555-1111"));
	rolo.add(Card("Fred", "Milton", "Sales", "12 Freedom Way Nashua, NH", "555-9981"));

	cout << "Welcome to your personal virtual rolodex!\n";

	//while loop to repeat command menu until 
	//user exits program
	while (userInput != "quit")
	{
		//listing of command words
		cout << "1)type 'list' to view all contacts\n"
			<< "2)type 'view' to view current contact\n"
			<< "3)type 'flip' to flip to view another contact\n"
			<< "4)type 'add' to add a new contact\n"
			<< "5)type 'remove' to remove current contact\n"
			<< "6)type 'search' to search for a contact\n"
			<< "7)type 'exit' to exit rolodex\n"
			<< endl;

		cin >> userInput;

		//if statements for each command inputted

		//command to display all contacts
		if (userInput == "list")
		{
			cout << endl;

			rolo.print();
		}

		//command to view current card
		else if (userInput == "view")
		{
			Card viewCard = rolo.getCurrentCard();

			viewCard.show(cout);

			cout << endl;
		}

		//command to flip through rolodex
		else if (userInput == "flip")
		{
			Card flippedCard = rolo.flip();

			flippedCard.show(cout);

			cout << endl;
		}

		//command to add new card to rolodex
		else if (userInput == "add")
		{
			string lN;

			string fN;

			string adr;

			string occu;

			string phNm;

			cout << "\nfirst name: ";

			cin >> fN;

			cout << "\nlast name: ";

			cin >> lN;

			cout << "\noccupation: ";

			cin >> occu;

			cout << "\naddress: ";

			cin.ignore();
			
			getline(cin, adr);

			cout << "\nphone number: ";

			cin >> phNm;

			rolo.add(Card(fN, lN, occu, adr, phNm));

			cout << "new contact added." << endl;

		}

		//command to remove card from rolodex
		else if (userInput == "remove")
		{
			Card cardToDelete = rolo.getCurrentCard();

			cardToDelete.show(cout);

			cout << endl;

			cout << "do you want to delete this contact?yes/no" << endl;

			string deleteCard;

			cin >> deleteCard;

			if (deleteCard == "yes")
			{
				rolo.remove();

				cout << "contact deleted!" << endl;
			}

			else if (deleteCard == "no")
			{
				cout << "contact not deleted." << endl;
			}
		}

		//command to search through rolodex
		//for specific contact
		else if (userInput == "search")
		{
			string firstNameSearch;

			string lastNameSearch;

			cout << "Enter first name: ";

			cin >> firstNameSearch;

			cout << endl;

			cout << "Enter last name: ";

			cin >> lastNameSearch;

			cout << endl;

			bool search = rolo.search(lastNameSearch, firstNameSearch);

			if (search == true)
			{
				cout << "card found!" << endl;

				Card cardFound = rolo.getCurrentCard();

				cardFound.show(cout);
			}

			else if (search == false)
			{
				cout << "card not found!" << endl;
			}
		}

		//command to exit program
		else if (userInput == "exit")
		{
			return 0;
		}

	}

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
