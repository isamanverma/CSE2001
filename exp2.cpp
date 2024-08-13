#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void playGame()
{
    int number, guess;
    char playAgain;

    do
    {
        srand(time(0));
        number = rand() % 1000 + 1;

        cout << "I have a number between 1 and 1000.\n";
        cout << "Can you guess my number?\n";
        cout << "Please type your first guess: ";

        do
        {
            cin >> guess;
            if (guess > number)
            {
                cout << "Too high. Try again.\n";
            }
            else if (guess < number)
            {
                cout << "Too low. Try again.\n";
            }
            else
            {
                cout << "Excellent! You guessed the number!\n";
                cout << "Would you like to play again (y or n)? ";
                cin >> playAgain;
            }
        } while (guess != number);

    } while (playAgain == 'y' || playAgain == 'Y');
}

int main()
{
    playGame();
    return 0;
}