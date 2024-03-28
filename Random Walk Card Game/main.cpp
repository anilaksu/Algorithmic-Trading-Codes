/*
	Random Walk Card Game:
		- Consider the following game. Beginning with a deck of even size N cards that are half red and half green.
		- You begin drawing cards. For each red card, you win $1 and for each green card, you lose $1.
		- You may stop at any time. What is the value of this game to you assuming you play optimally?
*/

#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>  // this header file contains next_permutation function

using namespace std;

// Function Prototypes
void getNumberofCards(int& N);
void checkEven(int N);
void checkAnswer(string& answer);
void continuePlaying(string& answer);
int factorial(int n);
void getRandomCards(int* cards, int N);
int getMaxPayoff(int* cards, int N);

int main() {

	int N;						 // Number or cards
	bool keepPlaying = true;     // Here we enable the end user keep playing
	string answer;				 // It is the answer from the user to choose to play or not to play 


	
	//for ( int i = 0; i < N ; i++)
	//	cout << (cards[i] ? "Red" : "Green") << endl;

	while (keepPlaying)
	{
		getNumberofCards(N);		 // Here we get number of cards from the user
		int* cards = new int[N];     // Random green and red cards
		getRandomCards(cards, N);    // Here we create number of random green and red cards

		cout << "Your maximum payoff is: " << getMaxPayoff(cards, N) << endl; // Maximum payoff output
		delete[] cards;				// Here we delete the cards array so that the end user can set the number of cards again
		cards = nullptr;			// Here we set it to null pointer to avoid memory leakage

		continuePlaying(answer);	// Here we check if the user wants to keep playing

		if( answer == "Yes")
			keepPlaying = true;
		else
			keepPlaying = false;
	}
	

	return 0;
}

void checkEven(int N)				// Throws exceptions for the number of cards
{

	if (N % 2 == 1)
		throw invalid_argument("Odd number passed in!");
	else 
		cout << "You have " << N << " cards!" << endl;


}

void getNumberofCards(int& N)		// Checks how many cards the user wants to play with
{
	cout << "Please enter even number for the amount of cards!" << endl;
	cin >> N;

	try
	{
		checkEven(N);
	}
	catch (const invalid_argument& err)
	{
		cout << err.what() << endl;
		getNumberofCards(N);
	}
}

void checkAnswer(string& answer) // Throws exceptions for the user deciding to play or not
{

	if (answer == "Yes")
		cout << "Here you go!" << endl;
	else if (answer == "No")
		cout << "Too bad! you could have earned more, see you later!" << endl;
	else
		throw invalid_argument("Please say Yes or No!");
}

void continuePlaying(string& answer)		// Checks if the user wants to play again
{
	cout << "Do you want to continue playing? (Yes/No)" << endl;
	cin >> answer;

	try
	{
		checkAnswer(answer);
	}
	catch (const invalid_argument& err)
	{
		cout << err.what() << endl;
		continuePlaying(answer);
	}
}

int factorial(int n)
{
	// single line to find factorial 
	return (n == 1 || n == 0) ? 1 : n * factorial(n - 1);
}


void getRandomCards(int* cards, int N)
{	
	// Providing a seed value
	srand((unsigned)time(NULL));

	// Here we store 1 as red and 0 as green
	for (int i = 0; i < N; i++)
		cards[i] = (i < N/2 ? false : true); 
	
	// Here we randomly shuffle the cards
	random_shuffle(cards, cards + N);        
}

int getMaxPayoff(int* cards, int N)
{
	int maxPayoff = 0;
	int Payoff = 0;

	// Here we check payoff at each step and keep the maximum
	for (int i = 0; i < N; i++)
	{
		Payoff += (cards[i] ? 1 : -1);
		maxPayoff = max(Payoff, maxPayoff);
	}
		
	return maxPayoff;
}