#include <stdio.h>

int main()
{
    int height;
    int i, j, k;

    //Prompting the user for a height value
    do
    {
        printf("Enter the height of the pyramid: \n");
        scanf("%d", &height);
    } while (height<1 || height>8);

    //Print the pyramids
    for(i = 1; i <= height;i++ ) //loop for printing rows
    {  
        for(j = 0;j < height-i;j++) //loop for printing the left spaces
        {
           printf(" "); 
        }
        for(k = 0;k < i; k++) //loop for printing the left hashes
        {
            printf("#");
        }
        printf("  ");
        for(k = 0; k < i;k++) //loop for printing the right hashes
        {
            printf("#");
        }
        printf("\n");
    }
return 0;

    
}