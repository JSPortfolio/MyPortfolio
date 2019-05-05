using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TestDeck
{

    class Program
    {
        //Lists to represent the deck, the player's hand and 
        //the discard pile
        public static List<string> TheHand = new List<string>();

        public static List<string> DiscardPile = new List<string>();

        public static List<string> TheDeck = new List<string>()
        {
            "Ace.Spade", "Ace.Club", "Ace.Diamond", "Ace.Heart",
            "2.Spade", "2.Club", "2.Diamond", "2.Heart",
            "3.Spade", "3.Club", "3.Diamond", "3.Heart",
            "4.Spade", "4.Club", "4.Diamond", "4.Heart",
            "5.Spade", "5.Club", "5.Diamond", "5.Heart",
            "6.Spade", "6.Club", "6.Diamond", "6.Heart",
            "7.Spade", "7.Club", "7.Diamond", "7.Heart",
            "8.Spade", "8.Club", "8.Diamond", "8.Heart",
            "9.Spade", "9.Club", "9.Diamond", "9.Heart",
            "10.Spade", "10.Club", "10.Diamond", "10.Heart",
            "Jack.Spade", "Jack.Club", "Jack.Diamond", "Jack.Heart",
            "Queen.Spade", "Queen.Club", "Queen.Diamond", "Queen.Heart",
            "King.Spade", "King.Club", "King.Diamond", "King.Heart"
        };
    
    static public class TheDealer
    {
            //**********************************************
            //Method:DealCards
            //Input:
            //numOfCards-The number of cards to take out of the deck
            //and place in the player's hand.
            //Process:Take specified number of cards from deck. 
            //Place in players hand.
            //Output:none.
            //**********************************************
            static public void DealCards(int numOfCards)
            {
                //for loop to add cards from deck to hand.
                for (int X = 0; X < numOfCards; X++)
                {
                    TheHand.Add(TheDeck[0]);

                    TheDeck.RemoveAt(0);
                }

                //Display number of cards taken from deck.
                Console.WriteLine($"You took {numOfCards} cards from " +
                    $"the deck and placed them in your hand");

                //Display remaining cards in deck.
                TheDealer.CountCards();
            }

            static public void DiscardCards()
            {
                bool cont = true;

                int cardsDiscarded = 0;

                char continueDiscarding;
                
                if (TheHand.Count == 0)
                {
                    Console.WriteLine("You have no cards to discard!");

                    cont = false;
                }

                else
                {
                    while (cont == true)
                    {
                        int compareCard = 0;

                        Console.WriteLine($"Please enter a card you hold to discard:");

                        string discardedCard = Console.ReadLine();

                        foreach(var Card in TheHand)
                        {
                            compareCard = string.Compare(discardedCard.ToLower(), Card.ToLower());

                            if (compareCard == 0)
                            {
                                Console.WriteLine($"The {Card} was discarded!");

                                DiscardPile.Add(Card);

                                TheHand.Remove(Card);

                                break;
                            }
                        }

                        if (compareCard != 0)
                        {
                            Console.WriteLine($"Card inputted does not exist in hand!");
                        }

                        else if (compareCard == 0)
                        {
                            cardsDiscarded++;
                        }

                        //FIGURE OUT HOW TO WORK THIS
                        while (continueDiscarding != 'Y' || continueDiscarding != 'N')
                        {
                            Console.WriteLine("Do you wish to continue discarding cards?Y/N?");

                            char.TryParse(Console.ReadLine(), out continueDiscarding);

                            if (continueDiscarding == 'Y')
                            {
                                cont = true;
                            }

                            else if (continueDiscarding == 'N')
                            {
                                cont = false;
                            }

                            else
                            {
                                Console.WriteLine("Please answer Y/N!");
                            }
                        }

                        
                    }

                }

                Console.WriteLine($"You discarded {cardsDiscarded} cards.");


            }

            //***************************************************
            //Method:CountCards
            //Inputs:None.
            //Processing:
            //      The method counts the cards within the hand, the deck 
            //      and the deck and prints the results to the console.
            //output:None.
            //***************************************************
            static public void CountCards()
            {
                //variables to hold totals for discard, deck and hand
                int deckTotal = 0;

                int handTotal = 0;

                int discardTotal = 0;

                //foreach to count each card in the deck.
                foreach (var Card in TheDeck)
                    deckTotal++;

                //print total cards in deck to console.
                Console.WriteLine($"There are {deckTotal} cards in the deck!");

                //foreach to count each card in the hand.
                foreach (var Card in TheHand)
                    handTotal++;

                //print total cards in hand to console.
                Console.WriteLine($"There are {handTotal} cards in your hand!");

                //foreach to count each card in the discard pile.
                foreach (var Car in DiscardPile)
                    discardTotal++;
                
                //print total cards in discard pile to console.
                Console.WriteLine($"Ther are {discardTotal} cards in the discard pile!");
            }

            //*******************************************
            //Method:ShowDeck
            //Inputs: none.
            //Processing:
            //      Prints each card in deck to console.
            //Output: none.
            //*******************************************
            static public void ShowDeck()
            {
                //foreach statement to print each card to console.
                foreach (var Card in TheDeck)
                    Console.WriteLine($"{Card}\n");
            }

            //*******************************************
            //Method:ShowHand
            //Inputs: none.
            //Processing:
            //      Prints each card in hand to console.
            //Output: none.
            //*******************************************
            static public void ShowHand()
            {
                //foreach statement to print each card to console.
                foreach (var Card in TheHand)
                    Console.WriteLine($"{Card}\n");
            }

            //*******************************************
            //Method:Shuffle
            //Inputs: none.
            //Processing:
            //     Checks for any cards in TheHand or DiscardPile
            //     then adds them to the deck. Then randomly rearranges
            //     the position of each card in the deck.
            //Output: none.
            //******************************************
            static public void shuffle()
            {
                //Else/if statements to check for any cards within the
                //player's hand or the discard pile
                if (TheHand.Count == 0)
                {
                    //for loop to simulate shuffling the deck
                    for (int x = 0; x < TheDeck.Count - 1; x++)
                    {
                        //instance of Random object to generate
                        //numerical positions for instances of cards.
                        Random random_placement = new Random();

                        //insert a new instance of the card from the deck
                        //and remove the original instance.
                        TheDeck.Insert(random_placement.Next(0, 52), TheDeck[x]);

                        TheDeck.RemoveAt(x);
                    }
                }

                else if (TheHand.Count > 0)
                {
                    //for loop to add an instance from the hand
                    //to the deck and remove the original instance
                    //from the hand.
                    for (int x = 0; x < TheHand.Count - 1; x++)
                    {
                        TheDeck.Add(TheHand[0]);

                        TheHand.RemoveAt(0);
                    }

                    //for loop to simulate shuffling the deck
                    for (int x = 0; x < TheDeck.Count - 1; x++)
                    {
                        //instance of Random object to generate
                        //numerical positions for instances of cards.
                        Random random_placement = new Random();

                        //insert a new instance of the card from the deck
                        //and remove the original instance.
                        TheDeck.Insert(random_placement.Next(0, 52), TheDeck[x]);

                        TheDeck.RemoveAt(x);
                    }

                }

                else if (DiscardPile.Count > 0)
                {
                    //for loop to add an instance from the discard
                    //pile and remove the original instance from the 
                    //discard pile.
                    for (int x = 0; x < DiscardPile.Count - 1; x++)
                    {
                        TheDeck.Add(DiscardPile[0]);

                        DiscardPile.RemoveAt(0);
                    }

                    //for loop to simulate shuffling the deck
                    for (int x = 0; x < TheDeck.Count - 1; x++)
                    {
                        //instance of Random object to generate
                        //numerical positions for instances of cards.
                        Random random_placement = new Random();

                        //insert a new instance of the card from the deck
                        //and remove the original instance.
                        TheDeck.Insert(random_placement.Next(0, 52), TheDeck[x]);

                        TheDeck.RemoveAt(x);
                    }
                }

                else if (DiscardPile.Count > 0 && TheHand.Count > 0)
                {
                    //for loop to add an instance from the hand
                    //to the deck and remove the original instance
                    //from the hand.
                    for (int x = 0; x < TheHand.Count - 1; x++)
                    {
                        TheDeck.Add(TheHand[0]);

                        TheHand.RemoveAt(0);
                    }

                    //for loop to add an instance from the discard
                    //pile and remove the original instance from the 
                    //discard pile.
                    for (int x = 0; x < DiscardPile.Count - 1; x++)
                    {
                        TheDeck.Add(DiscardPile[0]);

                        DiscardPile.RemoveAt(0);
                    }

                    //for loop to simulate shuffling the deck
                    for (int x = 0; x < TheDeck.Count - 1; x++)
                    {
                        //instance of Random object to generate
                        //numerical positions for instances of cards.
                        Random random_placement = new Random();

                        //insert a new instance of the card from the deck
                        //and remove the original instance.
                        TheDeck.Insert(random_placement.Next(0, 52), TheDeck[x]);

                        TheDeck.RemoveAt(x);
                    }
                }

                Console.WriteLine("Deck Shuffled...");
            }
    }

    static void Main(string[] args)
        {
            //bool variable to keep program running
            bool gameInPlay = true;

            //int variable to input for command
            int command = 0;

            //while statement to keep program running
            while (gameInPlay == true)
            {
                //print list of commands and proper input to console
                Console.WriteLine("Please input a number to activate the corresponding command");

                Console.WriteLine("1)Count cards");

                Console.WriteLine("2)Show deck");

                Console.WriteLine("3)Take card");

                Console.WriteLine("4)Show hand");

                Console.WriteLine("5)Shuffle Deck");

                Console.WriteLine("6)Discard cards");

                //TryParse integer value inputted into console.
                int.TryParse(Console.ReadLine(), out command);

                //else/if statements for commands and corresponding functions

                //count cards in hand, deck and discard
                if (command == 1)
                {
                    Console.WriteLine("**********Counting Cards**********");

                    TheDealer.CountCards();

                    Console.WriteLine("**********************************");

                }

                //display cards in deck
                else if (command == 2)
                {
                    Console.WriteLine("******Showing cards in deck******");

                   TheDealer.ShowDeck();

                    Console.WriteLine("*********************************");
                }

                //take cards from the deck
                else if (command == 3)
                {
                    Console.WriteLine("******Take cards from deck*******");

                    //variable to hold amount of cards to take from deck.
                    int cardsFromDeck = 0;

                    //while statement to repeat until amount of cards asked for
                    //is acceptable.
                    while (cardsFromDeck == 0 || cardsFromDeck > TheDeck.Count())
                    {
                        //print enquiry as to how many cards user desires.
                        Console.WriteLine("How many cards do you wish to take from the deck?");

                        //Convert string to integer value for amount of cards
                        //to take from deck.
                        int.TryParse(Console.ReadLine(), out cardsFromDeck);

                        //if else statements to check that amount of cards
                        //asked for is within range of cards held by the deck.
                        if (cardsFromDeck == 0)
                        {
                            Console.WriteLine("Ask for actual cards!");
                        }

                        else if (cardsFromDeck > TheDeck.Count())
                        {
                            Console.WriteLine("The deck does not contain enough cards!");
                        }
                    }

                    //run dealcards function
                    TheDealer.DealCards(cardsFromDeck);

                    Console.WriteLine("*********************************");
                }

                else if (command == 4)
                {
                    Console.WriteLine("**************Show hand**********");

                    TheDealer.ShowHand();

                    Console.WriteLine("*********************************");
                }

                else if (command == 5)
                {
                    Console.WriteLine("************Shuffle Deck*********");

                    TheDealer.shuffle();

                    Console.WriteLine("*********************************");
                }

                else if (command == 6)
                {
                    Console.WriteLine("**********Discard Card(s)********");

                    TheDealer.DiscardCards();

                    Console.WriteLine("*********************************");
                }

            }

        }
    }
}
