#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
int Points[27] = {0, 1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
char Alphabets[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int Alphabet_Postion(char letter)
{
    letter = toupper(letter);
    if (isalpha(letter))
    {
        for (int i = 0; i < strlen(Alphabets); i++)
        {
            if (Alphabets[i] == letter)
            {
                return i + 1;
            }
        }
    }
    return 0;
}
int ScoreChecker(string word)
{
    int sum = 0;
    int position = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        position = Alphabet_Postion(word[i]);
        sum += Points[position];
    }
    return sum;
}
int main(void)
{
    int Score1;
    int Score2;
    string word1 = get_string("Player 1 Enter Word: ");
    string word2 = get_string("Player 2 Enter Word: ");
    Score1 = ScoreChecker(word1);
    Score2 = ScoreChecker(word2);
    if (Score1 < Score2)
    {
        printf("Player 2 wins!\n");
    }
    else if (Score1 > Score2)
    {
        printf("Player 1 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
    printf("\n");
}
