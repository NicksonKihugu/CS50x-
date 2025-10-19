#include <ctype.h>
#include <stdio.h>
#include <string.h>

int comp_score(char *player); //Prototype of user_defined function

int points[]={1,3,3,2,1,4,2,4,1,8,5,1,3,1,1,3,10,1,1,1,1,4,4,8,4,10};

int main()
{
    char player1[50];
    char player2[50];

    //Prompting the players for their words
    printf("First player type in your word: \n");
    fgets(player1, sizeof(player1), stdin);
    printf("Second player type in your world: \n");
    fgets(player2, sizeof(player2), stdin);

    //Convert lower case chars to uppercase
    toupper(player1[50]);
    toupper(player2[50]);
    
    //Computing the score
    int score1 = comp_score(player1);
    int score2 = comp_score(player2);

    //Finding the winner
    if(score1 > score2)
    {
        printf("Player1 wins!\n");
    }
    else if(score2 > score1)
    {
        printf("PLayer2 wins!");
    }
    else
    {
        printf("Tie!\n");
    }
    printf("\n");
}




//The user_defined function
int comp_score(char player[50])
{
    int score = 0;
    for(int i = 0, len = strlen(player); i < len; i++)
    {
      score += points[i];
    }
    return score;
}