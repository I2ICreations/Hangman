#include <iostream>
#include <string>   
#include <vector>
#include <ctime>
#include <cstdlib>
#include <set>
#include <cctype>

using namespace std;

int main()
{
    vector<string> words = { "apple", "banana", "cherry", "dragonfruit", "elderberry", "fig", "grape", "honeydew", "kiwi", "lemon",
                            "mango", "nectarine", "orange", "papaya", "quince", "raspberry", "strawberry", "tangerine", "ugli", "watermelon" }; //A list of random words that could be chosen for the guessing game

    srand(static_cast<unsigned int>(time(0)));       //Seed the random number generator 

    string word = words[rand() % words.size()];    //Randomly select a word from the word list 
    string displayed_word(word.length(), '_');
    char guess;
    int tries = 0;
    int lives = 4;
    set <char> used_letters;

    cout << "HANGMAN" << '\n';

    while (displayed_word != word && lives > 0)
    {
        cout << "Current word: " << displayed_word << '\n';
        cout << "Number of tries: " << tries << '\n';
        cout << "LIVES: " << lives << '\n';
        cout << "Used letters: " << '\n';

        for (char letters : used_letters) {         //this will display all the users guessed letters
            cout << letters << " " << '\n';
        }
        cout << "Guess a letter" << '\n';
        cin >> guess;

        guess = tolower(guess);

        //CHARACTER VALIDATION
        if (!isalpha(guess)) {                      //if the character inputed isnt part of the alphabeth 
            cout << "IVALID CHARACTER!\n";          //display invalid character
            continue;
        }

        //CHECKS IF THE LETTERS HAS ALREADY BEEN GUESSED 
        if (used_letters.find(guess) != used_letters.end()) {
            cout << "You have already guessed that letter. Try again." << '\n';
            continue;
        }

        used_letters.insert(guess);                 //This will add the guessed letter to the set

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
            cout << "GAME OVER" << '\n';
            cout << "The word was: " << word;
            break;
        }
    }

    return 0;
}