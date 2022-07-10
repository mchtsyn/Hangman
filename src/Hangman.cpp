#include <iostream>
#include <string>
#include <iomanip>
#include <random>
#include <fstream>
#include <conio.h>
#include <clocale> //Turkish letters
using namespace std;
void Clear()
{
#if defined _WIN32
	system("cls");
	//clrscr(); // including header file : conio.h
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
	system("clear");
	//std::cout<< u8"\033[2J\033[1;1H"; //Using ANSI Escape Sequences 
#elif defined (__APPLE__)
	system("clear");
#endif
}

int unlockedLetterNum = 0;
string hintAndEnteredCorrectChar="               ";
char guess;
int tries = 6;
bool gameClose = false;

void welcomeScreen();
void stage6();
void stage5();
void stage4();
void stage3();
void stage2();
void stage1();
void stage0();
void generateWord(string& str);
void initializeHint(string& word);
void gameLoop(string& word);
void checkTries();
void closeGame();

int main()
{
	setlocale(LC_ALL, "Turkish");
	system("color f1");

	string chosenWord = "";
	generateWord(chosenWord);
	welcomeScreen();
	initializeHint(chosenWord);

	while (tries >= 0)
	{
		switch (tries)
		{
			case 6:
			{
				stage6();
				gameLoop(chosenWord);
				break;
			}
			case 5:
			{
				stage5();
				gameLoop(chosenWord);
				break;
			}
			case 4:
			{
				stage4();
				gameLoop(chosenWord);
				break;
			}
			case 3:
			{
				stage3();
				gameLoop(chosenWord);
				break;
			}
			case 2:
			{
				stage2();
				gameLoop(chosenWord);
				break;
			}
			case 1:
			{
				stage1();
				gameLoop(chosenWord);
				break;
			}
			case 0:
			{
				stage0();
				gameLoop(chosenWord);
				if (tries == -1)
				{
					cout << "You've failed to find the word. The word was "<<chosenWord<<".\n\n";
				}
				break;
			}
			
			case 11:
			{
				cout << "Congrats! You've found the word " << chosenWord <<"." << endl;
				return 0;
				break;
			}
			default:
				break;
		}
	}
}					
void welcomeScreen()
{
	string a;
	cout << "Enter a key to start: ";
	cin >> a;
}
void generateWord(string& str)
{
	cout << setw(20) << "------- Hangman By Mucahit Sayin -------\n" << endl;
	cout << "Selecting a random word from database, please be patient! \n";
	srand(time(0));
	string fileName = "words.txt";
	ifstream in(fileName.c_str());
	//Select a word
	while (!(str.size() <= 7 && str.size() >= 3))
	{
		int randWordIndex = rand() % 186930; //randomly selected line
		//Skip to the randWordIndex line
		for (int i = 0; i < randWordIndex; ++i)
			getline(in, str);
		//Select the randWordIndex line
		getline(in, str);
		//Start from beginning
		in.clear();
		in.seekg(0);
	}
	cout << "A random word is selected!\n\n\n";
}
void initializeHint(string& word)
{
	for (int i = 0; i<word.size(); i++)
	{
		hintAndEnteredCorrectChar[i] = '*'; //Print * as much as word.size
	}
}

void gameLoop(string& word)
{
	cout << "Enter your guess (a letter or whole word): ";
	cin >> guess;

	int correctCount = 0;
	//Guess handling
	for (int i = 0; i < word.size(); i++)
	{
		if (word[i] == guess && hintAndEnteredCorrectChar[i] == '*') //If guess is in word
		{
			hintAndEnteredCorrectChar[i] = guess; //Unlock and display guess from hint 
		}
		if (word[i] == guess)
		{
			correctCount++;
		}
	}

	if (correctCount == 0) tries--; //Wrong guess

	int lastCorrectCount = 0;
	for (int i = 0; i < word.size(); i++)
	{
		if (hintAndEnteredCorrectChar[i] == word[i])
		{
			lastCorrectCount++;
		}
	}
	if (lastCorrectCount == word.size())
	{
		gameClose = true;
	}
}

void closeGame()
{
	if (gameClose)
	{
		tries = 11;
	}
}


void stage6()
{
	Clear();
	cout << "_______________\n";
	cout << "|				\n";
	cout << "|				\n";
	cout << "|				\n";
	cout << "|				\n";
	cout << "|				\n";
	cout << "|				\n";
	cout << "|				\n";
	cout << "|				\n";
	cout << "|______________\n";
	cout << endl;
	cout <<"Hint: "<< hintAndEnteredCorrectChar << endl;
	//Display how many tries left
	cout << "You have " << tries << " tries left." << endl;
	closeGame();
	
}
void stage5()
{
	Clear();
	cout << "_______________\n";
	cout << "|      }		\n";
	cout << "|				\n";
	cout << "|				\n";
	cout << "|				\n";
	cout << "|				\n";
	cout << "|				\n";
	cout << "|				\n";
	cout << "|				\n";
	cout << "|______________\n";
	cout << endl;
	cout << "Hint: " << hintAndEnteredCorrectChar << endl;
	//Display how many tries left
	cout << "You have " << tries << " tries left." << endl;
	closeGame();
}

void stage4()
{
	Clear();
	cout << "_______________\n";
	cout << "|      }		\n";
	cout << "|      O		\n";
	cout << "|				\n";
	cout << "|				\n";
	cout << "|				\n";
	cout << "|				\n";
	cout << "|				\n";
	cout << "|				\n";
	cout << "|______________\n";
	cout << endl;
	cout << "Hint: " << hintAndEnteredCorrectChar << endl;
	closeGame();
	//Display how many tries left
	cout << "You have " << tries << " tries left." << endl;
}
void stage3()
{
	Clear();
	cout << "_______________\n";
	cout << "|      }		\n";
	cout << "|      O		\n";
	cout << "|      |		\n";
	cout << "|      |		\n";
	cout << "|      |		\n";
	cout << "|				\n";
	cout << "|				\n";
	cout << "|				\n";
	cout << "|______________\n";
	cout << endl;
	cout << "Hint: " << hintAndEnteredCorrectChar << endl;
	closeGame();
	//Display how many tries left
	cout << "You have " << tries << " tries left." << endl;
}
void stage2()
{
	Clear();
	cout << "_______________\n";
	cout << "|      }		\n";
	cout << "|      O		\n";
	cout << "|      |		\n";
	cout << "|    / | \\	\n";
	cout << "|   /  |  \\	\n";
	cout << "|				\n";
	cout << "|				\n";
	cout << "|				\n";
	cout << "|______________\n";
	cout << endl;
	cout << "Hint: " << hintAndEnteredCorrectChar << endl;
	//Display how many tries left
	cout << "You have " << tries << " tries left." << endl;
	closeGame();
}
void stage1()
{
	Clear();
	cout << "_______________\n";
	cout << "|      }		\n";
	cout << "|      O		\n";
	cout << "|      |		\n";
	cout << "|    / | \\	\n";
	cout << "|   /  |  \\	\n";
	cout << "|     /		\n";
	cout << "|    /			\n";
	cout << "|				\n";
	cout << "|______________\n";
	cout << endl;
	cout << "Hint: " << hintAndEnteredCorrectChar << endl;
	//Display how many tries left
	cout << "You have " << tries << " tries left." << endl;
	closeGame();
}
void stage0()
{
	Clear();
	cout << "_______________\n";
	cout << "|      }		\n";
	cout << "|      O		\n";
	cout << "|      |		\n";
	cout << "|    / | \\	\n";
	cout << "|   /  |  \\	\n";
	cout << "|     / \\		\n";
	cout << "|    /   \\	\n";
	cout << "|				\n";
	cout << "|______________\n";
	cout << endl;
	cout << "Hint: " << hintAndEnteredCorrectChar << endl;
	//Display how many tries left
	cout << "You have " << tries << " tries left." << endl;
	closeGame();
}