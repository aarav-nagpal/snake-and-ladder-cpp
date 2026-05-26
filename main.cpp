#include <iostream>
#include <string>
#include <cstdio>
#include <random>
#include <thread>
#include <chrono>

class SnakesLadders
{
    int player1 = 0;
    int computer = 0;
    bool isladder = false;
    bool issnake = false;
    public:
    bool game = true;
    int turn = 0;
    std::string play(int die1, int die2)
    {
        int score;
        score = newscore(die1 + die2);
        // Check if player landed on a ladder
        laddercheck(score);
        if(isladder)
        {
            isladder = false;
            std::cout<<"ladder found!!\n";
        }
        // Check if player landed on a snake
        snakecheck(score);
        if(issnake)
        {
            issnake = false;
            std::cout<<"snake found!!\n";
        }
        if (turn)
            computer = score;
        else
            player1 = score;
        char buf[100];
        turn ? std::snprintf(buf, sizeof(buf), "Computer is on square %d", computer) : std::snprintf(buf, sizeof(buf), "Player is on square %d", player1);
        std::string s(buf);
        if (turn ? computer == 100 : player1 == 100)
        {
            game = false;
            return turn ? s + "\nComputer wins" : s + "\nPlayer wins";
        }
        if (die1 != die2)
            turn = turn == 1 ? 0 : 1;
        s = s + "\n";
        return s;
    }

    int newscore(int die)
    {
        if(turn) return computer + die <= 100 ? computer + die : computer;
        return player1 + die <= 100 ? player1 + die : player1;
    }
    void laddercheck(int &score)
    {
        switch (score)
        {
        case 2:
            score = 38;
            isladder = true;
            break;
        case 7:
            score = 14;
            isladder = true;
            break;
        case 8:
            score = 31;
            isladder = true;
            break;
        case 15:
            score = 26;
            isladder = true;
            break;
        case 21:
            score = 42;
            isladder = true;
            break;
        case 28:
            score = 84;
            isladder = true;
            break;
        case 36:
            score = 44;
            isladder = true;
            break;
        case 51:
            score = 67;
            isladder = true;
            break;
        case 71:
            score = 91;
            isladder = true;
            break;
        case 78:
            isladder = true;
            score = 98;
            break;
        case 87:
            isladder = true;
            score = 94;
            break;
        }
    }
    void snakecheck(int &score)
    {
        switch (score)
        {
        case 99:
            score = 10;
            issnake = true;
            break;
        case 95:
            score = 75;
            issnake = true;
            break;
        case 92:
            score = 88;
            issnake = true;
            break;
        case 89:
            score = 68;
            issnake = true;
            break;
        case 74:
            score = 53;
            issnake = true;
            break;
        case 64:
            score = 60;
            issnake = true;
            break;
        case 62:
            score = 19;
            issnake = true;
            break;
        case 49:
            score = 11;
            issnake = true;
            break;
        case 46:
            score = 25;
            issnake = true;
            break;
        case 16:
            score = 6;
            issnake = true;
            break;
        }
    }
};

int diceroll()
{
    std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(1, 6);
    return distrib(gen);
}

void delayOneSecond()
{
    std::this_thread::sleep_for(std::chrono::seconds(1));
}

int main()
{
    SnakesLadders g;
    std::cout<<"Lets Start Snakes and Ladders Game!!\nAre you ready?\ninput 1 to start 0 if you are afraid\ninput = ";
    int input;
    std::cin>>input;
    if(input != 1 && input != 0) printf("Invalid input!");
    else if(input == 0) printf("Good luck!!");
    while(g.game && input == 1)
    {
        if(!g.turn)
        {
            std::string userInput;
            std::cout<<"Should we roll your dice = ";
            std::cin>>userInput;
        }
        std::cout<<"lets roll both the dices!!\n";
        delayOneSecond();
        int dice1 = diceroll();
        int dice2 = diceroll();
        g.turn ? std::cout << "Computer got " << dice1 << " and " << dice2 << std::endl : std::cout << "You got " << dice1 << " and " << dice2 << std::endl;
        delayOneSecond();
        std::cout<<"Calculating..";
        delayOneSecond();
        std::cout<<"..\n";
        delayOneSecond();
        std::cout<<g.play(dice1, dice2);
        delayOneSecond();
    }
    delayOneSecond();
    delayOneSecond();
    delayOneSecond();
    delayOneSecond();
    delayOneSecond();
    delayOneSecond();
    return 0;
}