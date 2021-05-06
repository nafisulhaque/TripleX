#include <iostream>
#include <ctime>

void PrintInstruction(int Difficulty)
{
    //Welcome message of the game
    std::cout << "\nYou're a mathemagician trying to get into a level " << Difficulty <<" magic vault." <<std::endl;
    std::cout << "You must enter the correct number rune to continue..." << std::endl;
}

bool PlayWithDifficulty(int Difficulty)
{
    //Printing welcome message
    PrintInstruction(Difficulty);
    //Declaring 3 variables
    const int CodeA = rand() % (2 + Difficulty) + 1;
    const int CodeB = rand() % (2 + Difficulty) + 1;
    const int CodeC = rand() % (2 + Difficulty) + 1;
    std::cout << "the answer is " << CodeA << CodeB << CodeC;
    //Sum and product of the codes
    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;
    //Printing the sum and product
    std::cout << std::endl;
    std::cout << "There are 3 numbers in the rune\n";
    std::cout << "The sum of the numbers are: " << CodeSum;
    std::cout << "\nThe product of the numbers are: " << CodeProduct;
    std::cout << "\n\nPlease enter the 3 numbers separated by spaces: ";

    //Player's guess
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA;
    std::cin >> GuessB;
    std::cin >> GuessC;
    std::cout << "You entered: " << GuessA << GuessB << GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "\n\nYou have opened the entrance\n";
        return true;
    }
    else
    {
        std::cout << "\n\nYou have failed to open the entrance\n";
        return false;
    }
}

int main()
{   
    srand(time(NULL));

    int Difficulty = 1;
    const int MaxLevel = 5;

    while (Difficulty <= MaxLevel)
    {       
        bool bLevelComplete;
        bool bGameComplete = (Difficulty == MaxLevel);
        bLevelComplete = PlayWithDifficulty(Difficulty);
        std::cin.clear(); //Clears any errors
        std::cin.ignore();//Discards the buffer

        if (bLevelComplete)
        {
            Difficulty++;
        }
        if (bGameComplete)
        {
            std::cout << "\nYou have entered the magic vault. Unseen treasure awaits.\n";
        }
    }
    
    return 0;
}