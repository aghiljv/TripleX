#include <iostream>
#include <ctime>

void PrintIntroduction(int LevelDifficulty)
{
    std::cout << "\n\nYou are breaking into a Level " << LevelDifficulty << " server room!";
    std::cout << std::endl;
    std::cout << "Guess the code!";
    std::cout << std::endl;
}

bool PlayGame(int LevelDifficulty)
{
    PrintIntroduction(LevelDifficulty);

    int CodeA = rand() % LevelDifficulty + LevelDifficulty;
    int CodeB = rand() % LevelDifficulty + LevelDifficulty;
    int CodeC = rand() % LevelDifficulty + LevelDifficulty;

    int CodeSum = CodeA + CodeB + CodeC;
    int CodeProduct = CodeA * CodeB * CodeC;

    std::cout << "\nThere are 3 numbers in the code\n";
    std::cout << "The add up to : " << CodeSum << "\n";
    std::cout << "The multiply to : " << CodeProduct << "\n";

    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;
    std::cout << "You entered: " << GuessA << " " << GuessB << " " << GuessC << "\n";

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "You win";
        return true;
    }
    else
    {
        std::cout << "You lose";
        return false;
    }
}

int main()
{
    srand(time(NULL));

    bool bLevelComplete;
    int LevelDifficulty = 1;
    const int MaxDifficulty = 5;
    while (LevelDifficulty <= MaxDifficulty)
    {
        bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear();  //Clears any errors
        std::cin.ignore(); //Discards the buffer
        if (bLevelComplete)
        {
            std::cout << "\nLevel " << LevelDifficulty << " complete!";
            LevelDifficulty++;
        }
    }
    std::cout << "\n\nYou have broke down the entire system. Congratulations";

    return 0;
}