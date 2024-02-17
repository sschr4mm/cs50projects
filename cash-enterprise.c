#include <cs50.h>
#include <stdio.h>

// Global constant and variable definitions
const int quarter = 25;
const int dime = 10;
const int nickel = 5;
const int penny = 1;

int numQuarters = 0;
int numDimes = 0;
int numNickels = 0;
int numPennys = 0;

int totQuarters = 0;
int totDimes = 0;
int totNickels = 0;
int totPennys = 0;

int numCoins;
int totCoins;
int rem; // Remainder to keep track of remaining total after each function
int changeOwed;

//////////////////////////////////
bool checkCoins(int coin) // Check if a coin is required
{
    if ((rem / coin) >= 1)
    {
        return true;
    }
    else
        return false;
}

// Functions that calculate the number of coins, and their total sum.
int calcNumCoins(coinType)
{
    numCoins = rem / coinType;
    return numCoins;
}
int calcTotCoins(coinType)
{
    totCoins = (numCoins * coinType);
    return totCoins;
}

// Process remaining amount
int calcRem(remCoins)
{
    rem = rem - remCoins;
    return rem;
}

// This function checks which coins and respective functions will be needed. If needed, will then return total # of coins, the sum
// of the coins, and a working remainder total for downstream calculations.
int calcCoins(int amountToCalculate)
{
    if (checkCoins(quarter) == true)
    {
        numQuarters = calcNumCoins(quarter);
        totQuarters = calcTotCoins(quarter);
        calcRem(totQuarters);
    }

    if (checkCoins(dime) == true)
    {
        numDimes = calcNumCoins(dime);
        totDimes = calcTotCoins(dime);
        calcRem(totDimes);
    }

    if (checkCoins(nickel) == true)
    {
        numNickels = calcNumCoins(nickel);
        totNickels = calcTotCoins(nickel);
        calcRem(totNickels);
    }

    if (checkCoins(penny) == true)
    {
        numPennys = calcNumCoins(penny);
        totPennys = calcTotCoins(penny);
        calcRem(totPennys);
    }

    changeOwed = numQuarters + numDimes + numNickels + numPennys;
    return changeOwed;
}

void printChangeOwed()
{
    if (numQuarters != 0)
    {
        printf("%i x quarters = %i\n", numQuarters, totQuarters);
    }

    if (numDimes != 0)
    {
        printf("%i x dimes = %i\n", numDimes, totDimes);
    }

    if (numNickels != 0)
    {
        printf("%i x nickels = %i\n", numNickels, totNickels);
    }

    if (numPennys != 0)
    {
        printf("%i x pennys = %i\n", numPennys, totPennys);
    }
    printf("---------------\n= %i total # of coins\n", changeOwed);
}
//////////////////////////////////////
int main(void)
{
    // function definitions
    int calcCoins(int amountToCalculate);
    int initialAmount;

    // logic
    do
    {
        initialAmount = get_int("Change owed: ");
    }
    while (initialAmount < 0);

    rem = initialAmount; // remainder: used to keep track of the working total after each function calculation. Separate from
                         // initialAmount so as not to corrupt the original value.

    calcCoins(initialAmount);
    printChangeOwed();
}
