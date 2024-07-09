#include <iostream>
#include <string>

using namespace std;

int main()
{

    string word = "keys";
    string displayed_word(word.length(), '_');
    char guess;

    cout << "HANGMAN" << '\n';

    while (displayed_word != word)
    {
        cout << "Current word: " << displayed_word << '\n';
        cout << "Guess a letter" << '\n';
        cin >> guess;

        for (int i = 0; i < word.length(); i++)
        {
            if (guess == word[i]) {
                displayed_word[i] = guess;
            }
        }

    }





    return 0;
}