#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>


using namespace std;

int main()
{
    vector<string> words = { "apple", "banana", "cherry", "dragonfruit", "elderberry", "fig", "grape", "honeydew", "kiwi", "lemon",
                            "mango", "nectarine", "orange", "papaya", "quince", "raspberry", "strawberry", "tangerine", "ugli", "watermelon" }; //A list of random words that could be chosen for the guessing game

    srand(static_cast<unsigned int>(time(0)));  //Seed the random number generator 

    string word = words[rand() % words.size()]; //Randomly select a word from the word list 
    string displayed_word(word.length(), '_');
    char guess;
    int tries = 0;
    int lives = 4;

    cout << "HANGMAN" << '\n';

    while (displayed_word != word)
    {
        cout << "Current word: " << displayed_word << '\n';
        cout << "Number of tries: " << tries << '\n';
        cout << "LIVES: " << lives << '\n';
        cout << "Guess a letter" << '\n';
        cin >> guess;

        bool correct_guess = false;

        for (int i = 0; i < word.length(); i++)
        {
            if (guess == word[i]) {
                displayed_word[i] = guess;
                correct_guess = true;
            }
        }

        if (!correct_guess)
        {
            lives--;
        }
        tries++;

        if (lives < 1)
        {
             cout << "GAME OVER";
             break;

        }
    }





    return 0;
}