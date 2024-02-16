#include <cs50.h>
#include <stdio.h>

const int quarter = 25;
const int dime = 10;
const int nickel = 5;
const int penny = 1;

int numQuarters;
int numDimes;
int numNickels;
int numPennys;
int totQuarters;
int totDimes;
int totNickels;
int totPennys;

int rem;
//////////////////////////////////////
int main(void)
{
    int calcCoins(int amountToCalculate);
    int initialAmount;
    int changeOwed;

    do
    {
        initialAmount = get_int("Change owed: ");
    }
    while (initialAmount < 0);
    printf("---------------\n");

    int coins = calcCoins(initialAmount);

    printf("%i x quarters = %i\n", numQuarters, totQuarters);
    printf("%i x dimes = %i\n", numDimes, totDimes);
    printf("%i x nickels = %i\n", numNickels, totNickels);
    printf("%i x pennys = %i\n", numPennys, totPennys);
    printf("---------------\n= %i total # of coins\n", coins);
}

// Functions to calculate the number of coins, and total sum of respective coins.
int calcNumQuarters(int amountToCalculate)
{
    numQuarters = amountToCalculate / quarter;
    return numQuarters;
}
int calcTotQuarters(int amountToCalculate)
{
    totQuarters = (numQuarters * quarter);
    return totQuarters;
}
int calcNumDimes(int amountToCalculate)
{
    numDimes = rem / dime;
    return numDimes;
}
int calcTotDimes(int amountToCalculate)
{
    totDimes = (numDimes * dime);
    return totDimes;
}
int calcNumNickels(int amountToCalculate)
{
    numNickels = rem / nickel;
    return numNickels;
}
int calcTotNickels(int amountToCalculate)
{
    totNickels = (numNickels * nickel);
    return totNickels;
}
int calcNumPennys(int amountToCalculate)
{
    numPennys = rem / penny;
    return numPennys;
}
int calcTotPennys(int amountToCalculate)
{
    totPennys = (numPennys * penny);
    return totPennys;
}

// Process remaining amount
int calcRem(int amountToCalculate, int totCoins)
{
    rem = amountToCalculate - totCoins;
    return rem;
}

// This would have been useful for arrays/switch loops to save processing time for amounts like 1, 4, 5, 19, 51 where not all coins need to be processed.
// int divideCoins(int amountToCalculate, int coin)
// {
//     return amountToCalculate / coin;
// }

// This function calls each function to get the total number of coins required. It also ensures other functions run to get the sum of the coins.
int calcCoins(int amountToCalculate)
{
    calcNumQuarters(amountToCalculate);
    calcTotQuarters(amountToCalculate);
    calcRem(amountToCalculate, totQuarters);

    calcNumDimes(rem);
    calcTotDimes(rem);
    calcRem(rem, totDimes);

    calcNumNickels(rem);
    calcTotNickels(rem);
    calcRem(rem, totNickels);

    calcNumPennys(rem);
    calcTotPennys(rem);
    calcRem(rem, totPennys);

    return numQuarters + numDimes + numNickels + numPennys;
}
