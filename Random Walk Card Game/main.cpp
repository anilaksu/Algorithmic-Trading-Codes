/*
	Random Walk Card Game:
		- Consider the following game. Beginning with a deck of even size N cards that are half red and half green.
		- You begin drawing cards. For each red card, you win $1 and for each green card, you lose $1.
		- You may stop at any time. What is the value of this game to you assuming you play optimally?
*/

#include <iostream>
#include<cstdlib>
#include <vector>
#include <algorithm>  // this header file contains next_permutation function

using namespace std;

// Function Prototypes
void getNumberofCards(int& N);
void checkEven(int N);
int factorial(int n);
void getRandomCards(int* cards, int N);
int getMaxPayoff(int* cards, int N);

int main() {

	int N;						 // Number or cards
	getNumberofCards(N);		 // Here we get number of cards from the user

	int* cards = new int[N];     // Random green and red cards
	getRandomCards(cards, N);    // Here we create number of random green and red cards
	
	//for ( int i = 0; i < N ; i++)
	//	cout << (cards[i] ? "Red" : "Green") << endl;

	cout << "Your maximum payoff is: " << getMaxPayoff(cards, N) << endl;

	return 0;
}

void checkEven(int N) // Throws exceptions
{

	if (N % 2 == 1)
		throw out_of_range("Odd number passed in!");
	else 
		cout << "You have " << N << " cards!" << endl;


}

void getNumberofCards(int& N)		// Rethrows exceptions
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