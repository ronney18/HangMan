/*
 * Name: Ronney Sanchez
 * Course: CIS 240 C++ Programming Language
 * Date: 9/26/16
 * Program: Hang Man
 * Description: This program generates a secret word from a text file and the
 * user needs to figure out what the secret word is by guessing letters to the
 * empty array before the complete hangman is drawn. Once the hangman is fully
 * drawn, Game Over! 
 */
//Include the standard input/output stream library
#include <iostream>
//Include the standard library
#include <cstdlib>
//Include the time library
#include <ctime>
//Include the string library
#include <string>
//Include the file stream library
#include <fstream>
//Using standard name space
using namespace std;

//Include the functions' prototype
void printMenu();
void drawNooseFirstPart();
void drawNoose();
void drawHead();
void drawOneEye();
void drawTwoEyes();
void drawFace();
void drawBody();
void drawBodyWithOneHand();
void drawBodyWithBothHands();
void drawLeftLeg();
void drawBothLegs();
void printInstructions();
void playGame(string wordArr[]);

int main()
{
    //Declare an input file variable
    ifstream inFS;
    //Initialize the size of the array to 44
    const int ARR_SIZE = 44;
    //Declare a word array
    string wordArr[ARR_SIZE];
    //Open the input file
    inFS.open("HangManWords.txt");
    
    //Display an error and exit the program if the file does not exist
    if(!inFS.is_open())
    {
        //Display an error
        cerr << "ERROR: Cannot open file!" << endl;
        //Exit the program
        return EXIT_FAILURE;
    }
    
    for(int i = 0; i < ARR_SIZE; i++)
    {
        //Store the 20 words from the file to the word array
        getline(inFS, wordArr[i]);
    }
    //Close the text file when done reading
    inFS.close();
    //Initialize the user input option to ' '
    char option = ' ';
    //Seed the random number generator
    srand(time(NULL));
    //Display the welcome game to the user
    cout << "Welcome to Hangman!" << endl;
    do
    {
        //Print the menu to the user
        printMenu();
        //Prompt the user for an input option
        cin >> option;
        if(option != '1' && option != '2' && option != '3')
        {
            //Display an error if the input is invalid
            cout << "Sorry! Your input is invalid!" << endl;
        }
    }while(option != '1' && option != '2' && option != '3');
    
    //Loop through the hangman game until the user presses 3 to exit
    while(option != '3')
    {
        //Branch based on the user's input
        switch(option)
        {
            //Display the instruction if the user input is a 1
            case '1':
                printInstructions();
                break;
            //Play the hangman game if the user's input is a 2
            default:
                playGame(wordArr);
                break;
        }
        do
        {
            //Print the menu to the user
            printMenu();
            //Prompt the user for an input option
            cin >> option;
            if(option != '1' && option != '2' && option != '3')
            {
                //Display an error if the input is invalid
                cout << "Sorry! Your input is invalid!" << endl;
            }
        }while(option != '1' && option != '2' && option != '3');
    }
    //Program ended
    return 0;
}

void printMenu()
{
    //Display the menu to the screen
    cout << "What would you like to do?" << endl;
    cout << "1-Get Help" << endl;
    cout << "2-Play Game" << endl;
    cout << "3-Quit" << endl;
}
void drawNooseFirstPart()
{
    cout << "-------" <<  endl;
}

void drawNoose()
{
    cout << "-------" <<  endl;
    cout << "      | " << endl;
    cout << "      | " << endl;
    cout << "      | " << endl;
}
void drawHead()
{
    //Display a circular head to the screen
    cout << "   -----" << endl;
    cout << "  /      \\" << endl;
    cout << " |       |" << endl;
    cout << "  \\     /" << endl;
    cout << "   -----" << endl;
}

void drawOneEye()
{
    //Display a circular head with one eye to the screen
    cout << "   -----" << endl;
    cout << " / o     \\" << endl;
    cout << "|         |" << endl;
    cout << " \\       /" << endl;
    cout << "   -----" << endl;
}

void drawTwoEyes()
{
    //Display a circular head with two eyes to the screen
    cout << "   -----" << endl;
    cout << " / o   o \\" << endl;
    cout << "|         |" << endl;
    cout << " \\       /" << endl;
    cout << "   -----" << endl;
}

void drawFace()
{
    //Display an entire face to the screen
    cout << "   -----" << endl;
    cout << " / o   o \\" << endl;
    cout << "|         |" << endl;
    cout << " \\  ---   /" << endl;
    cout << "   -----" << endl;
}

void drawBody()
{
   //Display a stick body to the screen
   cout << "     |  " << endl;
   cout << "     |  " << endl;
   cout << "     |  " << endl;
   cout << "     |  " << endl;
}

void drawBodyWithOneHand()
{
   //Display a stick body with one hand to the screen
   cout << "     |  " << endl;
   cout << "     |------  " << endl;
   cout << "     |  " << endl;
   cout << "     |  " << endl;
}

void drawBodyWithBothHands()
{
   //Display a stick body with both hands to the screen
   cout << "     |  " << endl;
   cout << "-----|------  " << endl;
   cout << "     |  " << endl;
   cout << "     |  " << endl;
}

void drawLeftLeg()
{
   //Display a left leg to the screen
   cout << "    /  " << endl;
   cout << "   /  " << endl;
   cout << "  /  " << endl;
   cout << " /  " << endl;
}

void drawBothLegs()
{
   //Display both legs to the screen
   cout << "     /\\" << endl;
   cout << "    /  \\" << endl;
   cout << "   /    \\" << endl;
   cout << "  /      \\" << endl;
}

void printInstructions()
{
    //Display the rules and instructions to the screen
    cout << "The game starts with an empty character array." << endl;
                cout << "You need to guess which letters go in the array " <<
                        "to find out what is the secret word." << endl;
                cout << "If you guess wrong, the hang man will slowly " <<
                        "be drawn." << endl;
                cout << "You need to guess the right letter to buy some " <<
                        "time from getting the man drawn." << endl;
                cout << "One the computer draws the whole body, game over! " <<
                        "You Lose!" << endl;
}

void playGame(string wordArr[])
{
    //Assign the random listed word to the secret word
    string secretWord = wordArr[rand() % 44];
    //Assign the length of the secret word to size
    int size = secretWord.length() - 1;
    //Declare a secret word box array with the size of the secret word
    char wordPlay[size];
    //Declare a no letter box with eleven elements
    char noBox[11];
    //Initialize the counter to 0
    int counter = 0;
    //Initialize the letter count to 0
    int letterCount = 0;
    //Initialize the letter to an empty character
    char letter = ' ';
    //Initialize i to 0
    int i = 0;
    //Initialize the word box full to false
    bool wordBoxFull = false;
    //Loop through the no letter box
    for(i = 0; i < 11; i++)
    {
        //Initialize each elements to an underscore
        noBox[i] = '_';
    }
    //Initialize the number of guesses to 0
    int guesses = 0;
    //Loop through the secret word box array
    for(i = 0; i < size; i++)
    {
        if(secretWord.at(i) != ' ')
        {
            /*Initialize each elements to an underscore if the character is not
             * a space.
             */ 
            wordPlay[i] = '_';
        }
        else
        {
            wordPlay[i] = ' ';
            letterCount++;
        }
    }
    /* Play the hangman game until the number of guesses reaches 11 or the user
     * correctly notify the secret word
     */
    while((guesses < 11) && (wordBoxFull == false))
    {
        //Display the NO LETTER box
        cout << "NO LETTER BOX" << endl;
        for(i = 0; i < 11; i++)
        {
            //Display each elements to the user
            cout << noBox[i] << " ";
        }
        //Display a new line
        cout << endl;
        //Display the secret word box
        cout << "SECRET WORD" << endl;
        for(i = 0; i < size; i++)
        {
            //Display each elements to the user
            cout << wordPlay[i] << " ";
        }
        //Display two new lines
        cout << endl << endl;
        
        //Prompt the user for a letter to play
        cout << "Enter a letter to play: " << endl;
        cin >> letter;
        letter = tolower(letter);
            
        //Display an error if the user enters a punctuation marks or symbols
        while(((letter < 97 )|| (letter > 122)) && ((letter < 65 ) || 
                (letter > 90)))
        {
            //Display the error
            cout << "No punctuation marks, numbers, nor symbols!!" << endl;
            cout << "Enter a letter to play: " << endl;
            //Prompt the user again for a letter to play
            cin >> letter;
            letter = tolower(letter);
        }
        //Loop through the secret word box array
        for(i = 0; i < size; i++)
        {
            //Display an error if the user enters a letter already played
            while((letter == wordPlay[i]) || (letter == noBox[i]) || 
                    (toupper(letter) == wordPlay[i]))
            {
                //Display the error
                cout << "You already tried " << letter << "." << endl;
                //Reinitialize i to 0
                i = 0;
                //Prompt the user again for a letter to play 
                cin >> letter;
            }
        }
        //Loop through the secret word box array
        for(i = 0; i < size; i++)
        {
            if(secretWord.at(i) == letter)
            {
                /* Assign the letter played to the current element of the secret 
                 * word box array if the user guesses the right letter
                 */
                wordPlay[i] = letter;
                //Increment the letter counter by 1
                letterCount = letterCount + 1;
            }
            
            if(secretWord.at(i) == toupper(letter))
            {
                /* Assign the letter played to the current element of the secret 
                 * word box array if the user guesses the right letter
                 */
                wordPlay[i] = toupper(letter);
                //Increment the letter counter by 1
                letterCount = letterCount + 1;
            }
        }
        if(secretWord.find(letter) == string::npos && 
                secretWord.find(toupper(letter)) == string::npos)
        {
            /*Display a sorry message to the user if the letter is not found on 
             * the secret word
             */
            cout << "Sorry! No " << letter << "!" << endl;
            /* Assign the letter to the current element of the no letter box 
             * array
             */
            letter = tolower(letter);
            noBox[counter] = letter;
            //Increment the number of guesses by 1
            guesses = guesses + 1;
            //Increment the counter by 1
            counter = counter + 1;
            if(guesses == 1)
            {
                //Display the first part of the noose if this is the first guess
                drawNooseFirstPart();
            }
            else if(guesses == 2)
            {
                //Display a full noose if this is the second guess
                drawNoose();
            }
            else if(guesses == 3)
            {
                //Display a circular head if this is the third guess
                drawNoose();
                drawHead();
            }
            else if(guesses == 4)
            {
                /* Display a circular head with a stick body if this is the 
                 * fourth guess
                 */
                drawNoose();
                drawHead();
                drawBody();
            }
            else if(guesses == 5)
            {
                /* Display a circular head with a stick body and a left leg 
                 * if this is the fifth guess
                 */
                drawNoose();
                drawHead();
                drawBody();
                drawLeftLeg();
            }
            else if(guesses == 6)
            {
                /* Display a circular head with a stick body and both legs 
                 * if this is the sixth guess
                 */
                drawNoose();
                drawHead();
                drawBody();
                drawBothLegs();
            }
            else if(guesses == 7)
            {
                /* Display a circular head with a one-handed stick body and
                 * both legs if this is the seventh guess
                 */
                drawNoose();
                drawHead();
                drawBodyWithOneHand();
                drawBothLegs();
            }
            else if(guesses == 8)
            {
                /* Display a circular head with a full stick body and both legs 
                 * if this is the eighth guess
                 */
                drawNoose();
                drawHead();
                drawBodyWithBothHands();
                drawBothLegs();
            }
            else if(guesses == 9)
            {
                /* Display a one-eyed head with a full stick body and both legs 
                 * if this is the seventh guess
                 */
                drawNoose();
                drawOneEye();
                drawBodyWithBothHands();
                drawBothLegs();
            }
            else if(guesses == 10)
            {
                /* Display a two-eyed head with a full stick body and both legs 
                 * if this is the tenth guess
                 */
                drawNoose();
                drawTwoEyes();
                drawBodyWithBothHands();
                drawBothLegs();
            }
            else
            {
                //Display a full stick figure if this is the final guess
                drawNoose();
                drawFace();
                drawBodyWithBothHands();
                drawBothLegs();
                //Display a lose message to the user
                cout << "You Lose!" << endl;
                //Display the secret word to the user
                cout << "This was the word!" << endl;
                for(i = 0; i < size; i++)
                {
                    //Display each letter of the secret word
                    cout << secretWord.at(i) << " ";
                }
                //Display a new line
                cout << endl;
            }
        }
        if(letterCount == size)
        {
            /*Display a winning message to the user if the secret word box is
            * full
            */
            cout << "Congratulations! You found the secret word!" << endl;
            for(i = 0; i < size; i++)
            {
                //Display the secret word to the user
                cout << secretWord.at(i) << " ";
            }
            //Display a new line
            cout << endl;
            //Assign the secret word box full to true
            wordBoxFull = true;
        }
    }
}