#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

//Prototypes of user-defined functions
int comp_letters (char paragraph[]);
int comp_words (char paragraph[]);
int comp_sentence (char paragraph[]);

int main ()
{
    char text[500];

    //Prompting the user to input their texts
    printf("Type in your text \n");
    fgets(text, sizeof(text), stdin);

    //Counting the number of letters in the user input
    int letters = comp_letters(text);

    //Coounting the number of words in the user input
    int words = comp_words(text);

    //Counting the number of sentences in the user input
    int sentence = comp_sentence(text);

    //Calculating the number of letters and sentences in 100 words
    float l = ((float)letters / words) * 100;
    float s = ((float)sentence / words) * 100;

    //Calculating grade
    float index = 0.0588 * l - 0.296 * s -15.8;
    int grade = (int)round(index);

    //Deciding what to print for grade < 1 and grade >=16
    if(grade < 1)
    {
        printf("Before grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", grade);
    }

}

//User_defined function for calculating the number of letters  in user's input
int comp_letters (char paragraph[])
{
    int l = 0;
    for(int i = 0, len = strlen(paragraph); i < len; i++)
    {
        if(isalpha(paragraph[i]))
        {
            l++;
        }

    }
    return l ;
}


//User_defined function for calculating the number of words in users input
int comp_words (char paragraph[])
{
    int words = 0;
    int inword = 0;
    for(int i =0;paragraph[i] != '\0'; i++)
    {
        if(isspace(paragraph[i]))
        {
            inword = 0;
        }
        else if(inword==0)
        {
            inword = 1;
            words++;
        }
    }
    return words;
}

//Calculating the number of sentences inn user's input
int comp_sentence (char paragraph[])
{
    int sent = 0;
    for(int i = 0; paragraph[i] != '\0'; i++)
    {
        if(paragraph[i] == '.'|| paragraph[i] == '?' || paragraph[i] == '!')
        {
            sent++;
        }
    }
    return sent;
}
