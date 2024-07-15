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
	vector<string> Ewords = { "Cat", "Dog", "Sun", "Fish", "Tree", "Bird", "Milk", "Cake", "Book", "Duck" };
	vector<string> Mwords = { "Planet", "Ocean", "Winter", "Rocket", "Flower", "Guitar", "Castle", "Pirate", "Garden", "Monster" };
	vector<string> Hwords = { "Zephyr", "Quizzical", "Jigsaw", "Crypt", "Oxygen", "Phantom", "Vortex", "Twilight", "Labyrinth", "Gargoyle" };

	srand(static_cast<unsigned int>(time(0)));       //Seed the random number generator 

	bool replay = true;

	//REPLAY SYSTEM
	while (replay)
	{
		vector<string> words;
		string difficulty;
		bool valid_difficulty_level = false;

		cout << "HANGMAN" << '\n';
		cout << "Pick a difficulty" << '\n';
		cout << "Easy\n";
		cout << "Medium\n";
		cout << "Hard\n";

		//Loop over until a valid difficulty has been chosen
		while (!valid_difficulty_level) {
			cin >> difficulty;

			for (auto& c : difficulty) c = tolower(c);

			if (difficulty == "easy")
			{
				cout << "You selected Easy difficulty.\n";
				words = Ewords;
				valid_difficulty_level = true;
			}
			else if (difficulty == "medium")
			{
				cout << "You selected Medium difficulty.\n";
				words = Mwords;
				valid_difficulty_level = true;
			}
			else if (difficulty == "hard")
			{
				cout << "You selected Hard difficulty.\n";
				words = Hwords;
				valid_difficulty_level = true;
			}
			else
			{
				cout << "Invalid difficulty.\n";
			}
		}

		string word = words[rand() % words.size()];    //Randomly select a word from the word list 
		for (auto& c : word) c = tolower(c);

		string displayed_word(word.length(), '_');
		char guess;
		int tries = 0;
		int lives = 7;
		set <char> used_letters;

		while (displayed_word != word && lives > 0)
		{
			cout << "Current word: " << displayed_word << '\n';
			cout << "Number of tries: " << tries << '\n';
			cout << "Used letters: " << '\n';

			//STICK MAN BASE FOR THE LIVES
			if (lives == 7)
			{
				cout << "-----" << '\n';
				cout << "     |" << '\n';
				cout << "      " << '\n';
				cout << "      " << '\n';
				cout << "      " << '\n';
				cout << "======" << '\n';
			}

			for (char letters : used_letters) {         //this will display all the users guessed letters
				cout << letters << " " << '\n';
			}
			cout << "Guess a letter" << '\n';
			cin >> guess;

			//CHARACTER VALIDATION
			if (!isalpha(guess)) {                      //if the character inputed isnt part of the alphabeth 
				cout << "IVALID CHARACTER!\n";          //display invalid character
				guess = tolower(guess);
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

			//CHANGES TO THE STICKMAN IF THE USERS GUESS IS INCORRECT

			if (lives == 6) {
				cout << "-----" << '\n';
				cout << "     |" << '\n';
				cout << "     O " << '\n';
				cout << "      " << '\n';
				cout << "      " << '\n';
				cout << "======" << '\n';
			}
			else if (lives == 5) {
				cout << "-----" << '\n';
				cout << "     |" << '\n';
				cout << "     O" << '\n';
				cout << "     |" << '\n';
				cout << "      " << '\n';
				cout << "======" << '\n';
			}
			else if (lives == 4) {
				cout << "-----" << '\n';
				cout << "     |" << '\n';
				cout << "     O" << '\n';
				cout << "    \|" << '\n';
				cout << "      " << '\n';
				cout << "======" << '\n';
			}
			else if (lives == 3) {
				cout << "-----" << '\n';
				cout << "     |" << '\n';
				cout << "     O" << '\n';
				cout << "    \|/" << '\n';
				cout << "      " << '\n';
				cout << "======" << '\n';
			}
			else if (lives == 2) {
				cout << "-----" << '\n';
				cout << "     |" << '\n';
				cout << "     O" << '\n';
				cout << "    \|/" << '\n';
				cout << "    / " << '\n';
				cout << "======" << '\n';
			}
			else if (lives == 1) {
				cout << "-----" << '\n';
				cout << "     |" << '\n';
				cout << "     O" << '\n';
				cout << "    \|/" << '\n';
				cout << "    / \ " << '\n';
				cout << "======" << '\n';
			}

			if (lives < 1)
			{
				cout << "GAME OVER" << '\n';
				break;
			}
		}

		cout << "The word was: " << word << '\n';

		string replay_input;
		cout << "Do you want to replay?(yes/no)";
		cin >> replay_input;

		for (auto& d : replay_input) d = tolower(d);

		if (replay_input != "yes")
		{
			replay = false;
		}
	}

	return 0;
}
