#include <stdio.h>

int main()
{
int height;
int i;
int j;
int k;

//Prompting the user for the height of the pyramid
do
{
    printf("Enter the height of the triangle: \n");
    scanf("%d", &height);
}while (height < 1 || height > 8);
//Printing the pyramd
for(i = 0; i <= height; i++)
{
    for(j = 0; j < height - i; j++)
    {
       printf(" ");
    }
    for(k = 0; k < i; k++)
    {
        printf("#");
    }
    printf("\n");
}
}
