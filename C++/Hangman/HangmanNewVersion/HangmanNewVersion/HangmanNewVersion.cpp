// HangmanNewVersion.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <ctime>
#include <string>

int main()
{
    //START SCREEN
    char start{};

    std::system("CLS"); //you really shouldn't do this

    std::cout << " Hangman " << std::endl;
    std::cout << "By Two Neurons Tutorial" << std::endl;
    std::cout << "_____________   " << std::endl;
    std::cout << "|        }      " << std::endl;
    std::cout << "|        O      " << std::endl;
    std::cout << "|        |      " << std::endl;
    std::cout << "|      / | \\    " << std::endl;
    std::cout << "|     /  |  \\   " << std::endl;
    std::cout << "|      /   \\    " << std::endl;
    std::cout << "|     /     \\  " << std::endl;
    std::cout << "|               " << std::endl;
    std::cout << "|_____________  " << std::endl;
    std::cout << "\nPress Any Key (and Enter) to Start\n";
    std::cin >> start;

    //CLEAR SCREEN
    std::system("CLS");


    //GAME
    //Set variables used throughout the game

    int Tries{ 6 }; //the number of attempts to guess correctly
    char Guess; // the letter guessed
    bool CorrectGuess = false;
    char PreviousGuesses[ 7 ]; //An array of 7 guesses, needs to be longer than the user can guess
    PreviousGuesses[0] = '\0';
    for (int i = 1; i < 6; i++)
    {
        PreviousGuesses[i] = '_';
    }
    PreviousGuesses[6] = '\0';
    std::string Word; //The word the player has to guess
    std::string WordList[99]; //an array of 100 strings
    

    //Get random word
    srand(time(NULL)); //creates a random seed used to get a random word from the array above
    std::ifstream RandomWord; //this file stream reads in the variable
    RandomWord.open("Words.txt"); //reads in this file (list of words)

    for (int i = 0; i < 99; i++)
    {
        RandomWord >> WordList[i]; //filling the array with words from the list
        //std::cout << WordList[i] << std::endl; //FOR TESTING PURPOSES ONLY
    }
    int RandomNum = rand() % 100; // returns a random number 0 and 99
    Word = WordList[RandomNum];
    //std::cout << Word << std::endl;  //For testing purposes
    RandomWord.close();

    //Make word a mystery
    std::string MysteryWord(Word.length(), '*'); //replaces each letter of the word for * and stores it in MysteryWord
    //std::cout << MysteryWord << std::endl; // test the word (though we will use this later on)


    while (Tries >= 0)  
    {
        //Reset our bool 
        CorrectGuess = false;
        
        //Display information related to the word for the player 
        std::cout << "The word you have to guess is: \n\n";
        std::cout << MysteryWord << std::endl;
        std::cout << "\nThere are " << MysteryWord.length() << " letters in the word\n\n";
        std::cout << "You have " << Tries << " guesses left\n";
        if (PreviousGuesses[0] == '\0')
        {
            std::cout << std::endl;
        }
        else
        {
            std::cout << "You've guessed: " << PreviousGuesses << std::endl;
        }

        //get player guess
        std::cout << "\nGuess a letter: ";
        std::cin >> Guess;
        Guess = std::tolower(Guess);

        //Check is guess correct?
        for (int i = 0; i < MysteryWord.length(); i++) // for the lenght of the word (usinf mystery) do the following:
        {
            if (Word[i] == Guess) //Check does the word (actual) have guess in it
            {
                MysteryWord[i] = Guess;
                CorrectGuess = true; 
            }
        }
        if (Word == MysteryWord)
        {
            std::cout << "\n\n\nCongratulations!! You've got the word correct: " << MysteryWord << std::endl;
            std::cout << "\n\n\n"; 
            break;
        }
        if (CorrectGuess == false)
        {
            Tries--; 
            std::cout << "\n\n\nWroooong... " << Guess << " is not part of the word dummy" << std::endl;
        }
        else
        {
            std::cout << "Great! " << Guess << " is one of the letters!" << std::endl;
        }

        switch(Tries)
        {
            case 6:
            {
                std::cout << "_____________   " << std::endl;
                std::cout << "|        }      " << std::endl;
                std::cout << "|              " << std::endl;
                std::cout << "|               " << std::endl;
                std::cout << "|               " << std::endl;
                std::cout << "|               " << std::endl;
                std::cout << "|               " << std::endl;
                std::cout << "|               " << std::endl;
                std::cout << "|               " << std::endl;
                std::cout << "|_____________  " << std::endl;
                std::cout << "\n\n\n\n\n\n" << std::endl;
                break;
            }
            case 5:
            {
                std::cout << "_____________   " << std::endl;
                std::cout << "|        }      " << std::endl;
                std::cout << "|        O      " << std::endl;
                std::cout << "|               " << std::endl;
                std::cout << "|               " << std::endl;
                std::cout << "|               " << std::endl;
                std::cout << "|               " << std::endl;
                std::cout << "|               " << std::endl;
                std::cout << "|               " << std::endl;
                std::cout << "|_____________  " << std::endl;
                std::cout << "\n\n\n\n\n\n" << std::endl;
                if (CorrectGuess == false)
                {
                    PreviousGuesses[0] = Guess;
                }
                break;
            }
            case 4:
            {
                std::cout << "_____________   " << std::endl;
                std::cout << "|        }      " << std::endl;
                std::cout << "|        O      " << std::endl;
                std::cout << "|        |      " << std::endl;
                std::cout << "|               " << std::endl;
                std::cout << "|               " << std::endl;
                std::cout << "|               " << std::endl;
                std::cout << "|               " << std::endl;
                std::cout << "|               " << std::endl;
                std::cout << "|_____________  " << std::endl;
                std::cout << "\n\n\n\n\n\n" << std::endl;
                PreviousGuesses[1] = Guess;
                break;
            }
            case 3:
            {
                std::cout << "_____________   " << std::endl;
                std::cout << "|        }      " << std::endl;
                std::cout << "|        O      " << std::endl;
                std::cout << "|        |      " << std::endl;
                std::cout << "|      / |      " << std::endl;
                std::cout << "|     /  |      " << std::endl;
                std::cout << "|               " << std::endl;
                std::cout << "|               " << std::endl;
                std::cout << "|               " << std::endl;
                std::cout << "|_____________  " << std::endl;
                std::cout << "\n\n\n\n\n\n" << std::endl;
                PreviousGuesses[2] = Guess;
                break;
            }
            case 2:
            {
                std::cout << "_____________   " << std::endl;
                std::cout << "|        }      " << std::endl;
                std::cout << "|        O      " << std::endl;
                std::cout << "|        |      " << std::endl;
                std::cout << "|      / | \\   " << std::endl;
                std::cout << "|     /  |  \\  " << std::endl;
                std::cout << "|               " << std::endl;
                std::cout << "|               " << std::endl;
                std::cout << "|               " << std::endl;
                std::cout << "|_____________  " << std::endl;
                std::cout << "\n\n\n\n\n\n" << std::endl;
                PreviousGuesses[3] = Guess;
                break;
            }
            case 1:
            {
                std::cout << "_____________   " << std::endl;
                std::cout << "|        }      " << std::endl;
                std::cout << "|        O      " << std::endl;
                std::cout << "|        |      " << std::endl;
                std::cout << "|      / | \\   " << std::endl;
                std::cout << "|     /  |  \\  " << std::endl;
                std::cout << "|      /        " << std::endl;
                std::cout << "|     /         " << std::endl;
                std::cout << "|               " << std::endl;
                std::cout << "|_____________  " << std::endl;
                std::cout << "\n\n\n\n\n\n" << std::endl;
                PreviousGuesses[4] = Guess;
                break;
            }
            case 0:
            {
                std::cout << "\n\n\nGAME OVER!!! You murderer" << std::endl;
                std::cout << "_____________   " << std::endl;
                std::cout << "|        }      " << std::endl;
                std::cout << "|        O      " << std::endl;
                std::cout << "|        |      " << std::endl;
                std::cout << "|      / | \\    " << std::endl;
                std::cout << "|     /  |  \\   " << std::endl;
                std::cout << "|      /   \\    " << std::endl;
                std::cout << "|     /     \\  " << std::endl;
                std::cout << "|               " << std::endl;
                std::cout << "|_____________  " << std::endl;
                Tries == 1;
                break;
            }
            default:
            {
                std::cout << "If you are seeing this line, then there is an error." << std::endl;
            }
        }
    }

    return 0;
}


