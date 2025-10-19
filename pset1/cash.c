#include <stdio.h>
#include <math.h>

int count_coins(int amount, int coins); // prototype for user-defined function

int main ()
{
    float change;
    int cents;

    // Prompt user for change owed
    do
    {
        printf("Change owed in $: \n");
        scanf("%f", &change);
    } while (change < 0);
    
    // Convert dollars to cents
    cents = (change)*(100);
    round(cents);// round to nearest cent
    printf("Change in cents is: %d\n", cents);

    int total_coins = 0;

    // Calculate the number of each coin type
    // Calculate number of quarters
    int quarters = count_coins(cents, 25);
    total_coins += quarters;
    cents = cents % 25;

    // Calculate number of dimes
    int dimes = count_coins(cents, 10);
    total_coins += dimes;
    cents = cents % 10;

    // Calculate number of nickels
    int nickels = count_coins(cents, 5);
    total_coins += nickels;// add nickels to total coins
    cents = cents % 5;

    // Calculate number of pennies
    int pennies = count_coins(cents, 1);
    total_coins += pennies;
    cents = cents % 1;

    // Output the total number of coins
    printf("The total coins for the change is: %d\n", total_coins);

    return 0;

     
    
    
}

    

    int count_coins(int amount, int coins)
    {
        return amount / coins;
    }