#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char usertext[], int key);//Prototype of the user defined function

int main (int argc, char *argv[])
{
    //Restricting number of arguments to 2
    if (argc != 2)
    {
        printf("Usage: ./caesar key \n");
        return 1;
    }
    
    //Check that every character in argv[1] is not a letter
    for(int i = 0; argv[1][i] != '\0' ; i++)
    {
        if(isalpha(argv[1][i]))
        {
            printf("Usage: ./caesar key \n");
            return 1;
        }
    }
    
    //Converting the string to interger
    int key = atoi(argv[1]);

    //Prompting the user for plaintextt
    char plaintext[100];

    printf("Plaintext: \n");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0';//Replacing the '\n' with a terminator '\0'

    //Calling the user defined function
    encrypt(plaintext, key);

}

//The user defined function
void encrypt(char usertext[], int key)
{
    char ciphertext[strlen(usertext) + 1];

    for(int j = 0;usertext[j] != '\0'; j++)
    {
        if(isalpha(usertext[j]))
        {
            if(isupper(usertext[j]))
            {
                ciphertext[j] = (((usertext[j] - 'A') + key) % 26) + 'A';
            }
            else if(islower(usertext[j]))
            {
                ciphertext[j] = (((usertext[j] - 'a')+ key) % 26) + 'a';
            }
        }
        else
        {
           ciphertext[j] = usertext[j];//Deals with non letters   
        }

    }

    ciphertext[strlen(usertext)] = '\0';
    printf("Ciphertext: %s\n", ciphertext);
    
}