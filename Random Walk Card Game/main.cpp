/*
	Random Walk Card Game:
		- Consider the following game. Beginning with a deck of even size N cards that are half red and half green.
		- You begin drawing cards. For each red card, you win $1 and for each green card, you lose $1.
		- You may stop at any time. What is the value of this game to you assuming you play optimally?
*/

#include <iostream>
#include<cstdlib>
#include <vector>

using namespace std;

// Function Prototypes
void getNumberofCards(int& N);
void checkEven(int N);
vector<bool> getRandomCards(int N);

int main() {

	int N;				 // Number or cards
	vector<bool> cards;  // Random green and red cards

	getNumberofCards(N);		 // Here we get number of cards from the user
	cards = getRandomCards(N);   // Here we create number of random green and red cards
	
	for (bool card : cards)
		cout << (card ? "Red" : "Green") << endl;

	return 0;
}

void checkEven(int N) // Throws exceptions
{

	if (N % 2 == 1)
		throw out_of_range("Odd number passed in!");
	else 
		cout << "You have " << N << " cards!" << endl;


}

void getNumberofCards(int& N)	 // Rethrows exceptions
{
	cout << "Please enter even number for the amount of cards!" << endl;
	cin >> N;

	try
	{
		checkEven(N);
	}
	catch (const out_of_range& err)
	{
		cout << err.what() << endl;
		getNumberofCards(N);

	}
}


vector<bool> getRandomCards(int N)
{
	vector<bool> cards; // Here we store 1 as red and 0 as green
	// Providing a seed value
	srand((unsigned)time(NULL));

	// Get random cards 
	for (int i = 0; i < N; i++)
		cards.push_back(rand() % 2);

	return cards;
}