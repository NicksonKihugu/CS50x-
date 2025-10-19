#include <ctype.h>
#include <stdio.h>
#include <string.h>

void encrypt(char message[], char *argv[]);

int main (int argc, char *argv[])
{
    //Enssures the command only recieves 2 arguments
    if(argc != 2)
    {
        printf("Usage: ./substitution key\n");
    }

    //Ensures the argument contains 26 characters
    if(strlen(argv[1]) != 26)
    {
        printf("The key must contain 26 characters\n");
        return 1;
    }

    //Ensures the argument is not a digit
    for(int i = 0;argv[1][i] != '\0'; i++ )
    {
        if(isdigit(argv[1][i]))
        {
            printf("Usage: ./substitution key\n");
            return 1;
        }
    }

    //Preventing duplicate letters in the key
    int seen[26] = {0}; // '0' means not seen

    for(int k = 0; argv[1][k] != '\0'; k++)
    {
        int position = toupper(argv[1][k] - 'A');
        if(argv[1][k] > 1)
        {
            printf("Key must not contain duplicate letters!\n");
            return 1;
        }
    }

    //Prompt the user for message/plaintext
    char plaintext[50];

    printf("Plaintext: \n");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0';//Replaces the '\n' with '\0'

    encrypt(plaintext, argv);
}

//The user defined function
void encrypt(char message[], char *argv[])
{
    char ciphertext[strlen(message) + 1];
    
    for(int j = 0; message[j] != '\0'; j++)
    {
        if(isalpha(message[j]))
        {
            if(isupper(message[j]))
            {
                int index = message[j] - 'A';
                ciphertext[j] = toupper(argv[1][index]);//Maintaining the case of the original text
            }
            if(islower(message[j]))
            {
                int index = message[j] - 'a';
                ciphertext[j] = tolower(argv[1][index]);//Maintaining the case of the original text
            }
        }
        else 
        {
            ciphertext[j] = message[j];
        }
        
    }
    ciphertext[strlen(message)] = '\0';
    printf("Ciphertext: %s\n", ciphertext);
    
}
