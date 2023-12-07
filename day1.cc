#include <iostream>
#include <string>
#include <fstream>

typedef struct 
{
    std::string str;
    int digit;
} string_digit;

string_digit string_digit_table[9] =
{
    {std::string("one"), 1},
    {std::string("two"), 2},
    {std::string("three"), 3},
    {std::string("four"), 4},
    {std::string("five"), 5},
    {std::string("six"), 6},
    {std::string("seven"), 7},
    {std::string("eight"), 8},
    {std::string("nine"), 9},
};

int part1()
{
    std::ifstream myfile;
    std::string line;
    myfile.open("input.txt");

    int sum = 0;
    while ( getline (myfile,line) ) 
    {
        int first = -1, last;
        for(int i = 0; i < line.length(); i++)
        {
            if(line[i] >= '0' and line[i] <= '9')
            {
                int number  = line[i] - 48;
                if(first == -1)
                {
                    first = number;
                }
                last = number;
            }
        }
        sum+= (first*10)+last;
    }
    return sum;
}

int part2()
{
    std::ifstream myfile;
    std::string line;
    myfile.open("input.txt");
    std::string letter_word = "";
    int sum = 0;
    while ( getline (myfile,line) ) 
    {
        int first = -1, last;
        for(int i = 0; i < line.length(); i++)
        {
            if(line[i] >= '0' and line[i] <= '9')
            {
                letter_word.clear();
                int number  = line[i] - 48;
                if(first == -1)
                {
                    first = number;
                }
                last = number;
            }
            else 
            {
                letter_word += line[i];
                int max_index = -1;
                int index;
                for(int j = 0; j < 9; j++)
                {
                    if( (index = letter_word.rfind(string_digit_table[j].str)) != std::string::npos)
                    {
                        if(index <= max_index)
                            continue;
                        max_index = index;
                        if(first == -1)
                        {
                            first = string_digit_table[j].digit;
                        }
                        last = string_digit_table[j].digit;
                    } 
                }
            }

        }
        sum+= (first*10)+last;
        letter_word.clear();
    }
    return sum;
}

int main()
{
    std::cout << "Part 1: " << part1() << std::endl;
    std::cout << "Part 2: " << part2() << std::endl;
}
