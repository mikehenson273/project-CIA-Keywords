/*
 Michael Henson
CSC215
assignment Keywords
 */

#include "pch.h"
#include <string>
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

//sets up how many guesses
int tries1 = 0;
int tries2 = 0;
int tries3 = 0;


int main()
{
	char again = 'Y';
	while (again == 'Y' || again == 'y')
		do
		{
			//resets guess amount
			tries1 = 0;
			tries2 = 0;
			tries3 = 0;
			system("cls");
			//sets up color scheme and title
			system("color 0A");
			system("title Code Breaking Training Sim");

			enum fields { WORD, HINT, NUM_FIELDS };
			const int NUM_WORDS = 10;
			const string WORDS[NUM_WORDS][NUM_FIELDS] =
			{
				{"person", "\nSomeone is a _____?" },
				{"computer", "\nWhat are you currently using."},
				{"canine", "\nMan's best friend."},
				{"yourself", "\nDo it _______"},
				{"time", "\nYou're running out of it."},
				{"exception", "\nSomething not following a rule."},
				{"universe", "\nWhat is a galaxy inside of?"},
				{"movie", "\nA common name for a motion picture."},
				{"towel", "\nWhat gets wetter as it dries?"},
				{"chocolate", "\nSweet made from cacao."},
			};

			enum difficulty { EASY, MEDIUM, HARD, NUM_DIFF_LEVELS };
			srand(static_cast<unsigned int>(time(0)));

			int choice1 = (rand() % NUM_WORDS); //sets up 3 choices for words
			int choice2 = (rand() % NUM_WORDS); //^
			int choice3 = (rand() % NUM_WORDS); //^
			string theWord1 = WORDS[choice1][WORD]; //word # 1 to guess
			string theHint1 = WORDS[choice1][HINT]; //hint for word # 1
			string theWord2 = WORDS[choice2][WORD]; //word # 2 to guess
			string theHint2 = WORDS[choice2][HINT]; //hint for word # 2
			string theWord3 = WORDS[choice3][WORD]; //word # 3 to guess
			string theHint3 = WORDS[choice3][HINT]; //hint for word # 3

			string jumble1 = theWord1; //jumbled version of word
			int length1 = jumble1.size();
			for (int i = 0; i < length1; ++i)
			{
				int index1 = (rand() % length1);
				int index2 = (rand() % length1);
				char temp = jumble1[index1];
				jumble1[index1] = jumble1[index2];
				jumble1[index2] = temp;
			}
			string jumble2 = theWord2; //jumbled version of word 2
			int length2 = jumble2.size();
			for (int i = 0; i < length2; ++i)
			{
				int index1 = (rand() % length2);
				int index2 = (rand() % length2);
				char temp = jumble2[index1];
				jumble2[index1] = jumble2[index2];
				jumble2[index2] = temp;
			}
			string jumble3 = theWord3; //jumbled version of word 3
			int length3 = jumble3.size();
			for (int i = 0; i < length3; ++i)
			{
				int index1 = (rand() % length3);
				int index2 = (rand() % length3);
				char temp = jumble3[index1];
				jumble3[index1] = jumble3[index2];
				jumble3[index2] = temp;
			}

			//actual start of program
			cout << "\t\t\tWelcome to  the Code Breaking Training Sim!\n\n";
			//cout << "There are " << NUM_DIFF_LEVELS << " difficulty levels.\n";
			cout << "The goal of this training simulator\n";
			cout << "is to prepare you for action against\n";
			cout << "groups that have downgraded to simple\n";
			cout << "methods of communication to send orders.\n";
			cout << "Your job in this simulation is to guess\n";
			cout << "3 random words to solve.\n";
			cout << "Good luck!\n\n";
			cout << "Enter 'hint' for a hint.\n";
			cout << "Enter 'quit' to quit the game.\n\n";
			cout << "The jumbled words are: \n";
			cout << jumble1 << endl;


			//sets up a guess for character
			string guess1;
			string guess2;
			string guess3;

			//starts while loop
			while ((guess1 != theWord1) && (guess1 != "quit"))
			{
				cout << "\n\nYour Guess: \n";
				cin >> guess1;

				//asks for hint and gives hint
				if (guess1 == "hint")
				{
					cout << theHint1 << endl;
					system("pause");
				}

				//adds one to try if wrong
				else if ((guess1 != theWord1) && (guess1 != "quit"))
				{
					++tries1;
					cout << "\nSorry that's not the correct word.\n";
					cout << "Here it is again\n" << jumble1 << endl << endl;
					//system("pause");
				}

				//sets up condition for correct guess
				else if (guess1 == theWord1)
				{
					++tries1;
					cout << "\nThat's it! You guessed it in " << tries1 << " attempts!\n";
					system("pause");

					//starts next word
					cout << "\n\nHere is the second word: \n";
					cout << jumble2;

					while ((guess2 != theWord2) && (guess2 != "quit"))
					{
						cout << "\n\nYour Guess: \n";
						cin >> guess2;

						if (guess2 == "hint")
						{
							cout << theHint2 << endl;
							system("pause");
						}

						//adds one to try if wrong
						else if ((guess2 != theWord2) && (guess2 != "quit"))
						{
							++tries2;
							cout << "\nSorry that's not the correct word.\n";
							cout << "Here it is again\n" << jumble2 << endl << endl;
							//system("pause");
						}

						//sets up winning condition
						else if (guess2 == theWord2)
						{
							++tries2;
							cout << "\nThat's it! You guessed it in " << tries2 << " attempts!\n";
							system("pause");

							//starts third word
							cout << "\n\nHere is the third word: \n";
							cout << jumble3;
							while ((guess3 != theWord3) && (guess3 != "quit"))
							{
								cout << "\n\nYour Guess: \n";
								cin >> guess3;
								if (guess3 == "hint")
								{
									cout << theHint3 << endl;
									system("pause");
								}

								//adds one to try if wrong
								else if ((guess3 != theWord3) && (guess3 != "quit"))
								{
									++tries3;
									cout << "\nSorry that's not the correct word.\n";
									cout << "Here it is again\n" << jumble3 << endl << endl;
									//system("pause");
								}

								//sets up winning condition
								else if (guess3 == theWord3)
								{
									++tries3;
									cout << "\nThat's it! You guessed it in " << tries3 << " attempts!\n";
									system("pause");
									cout << "\nIt took you a total of " << tries1 + tries2 + tries3 << " to get all of them correct.\n\n";
									cout << "\n\nWould you like to go again? Y/N: \n";
									cin >> again;
								}

								//sets up exit factor for loop
								else if (guess3 == "quit")
								{
									cout << "\nWould you like to restart Y/N: \n";
									cin >> again;
								}

								//sets up warning for wrong guess
								else
								{
									cout << "\nSorry that's not it.";
									system("pause");
								}
							}
						}

						//sets up exit factor for loop
						else if (guess2 == "quit")
						{
							cout << "\nWould you like to restart Y/N: \n";
							cin >> again;
						}

						//sets up warning for wrong guess
						else
						{
							cout << "\nSorry that's not it.\n";
							system("pause");
						}
					}

				}
				 
				//sets up exit factor for loop
				else if (guess1 == "quit")
				{
					cout << "\nWould you like to restart Y/N: \n";
					cin >> again;
				}

				//sets up fail-safe
				else
				{
					cout << "\nSorry that's not it.";
					system("pause");
				}
			}
		} while (again == 'Y' || again == 'y'); //conditional to replay
		return 0;
}
