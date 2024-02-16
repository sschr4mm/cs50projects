#include <cs50.h>
#include <stdio.h>
//////////////////////////////////////
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
//////////////////////////////////////
int calcNumQuarters(int amountToCalculate)
{
    numQuarters = amountToCalculate / quarter;
    return numQuarters;
}
int calcTotQuarters(int amountToCalculate)
{
    totQuarters = (numQuarters * quarter);
    rem = amountToCalculate - totQuarters;
    return totQuarters;
}
//////////////////////////////////////
int calcNumDimes(int amountToCalculate)
{
    numDimes = rem / dime;
    return numDimes;
}
int calcTotDimes(int amountToCalculate)
{
    totDimes = (numDimes * dime);
    rem = rem - totDimes;
    return totDimes;
}
//////////////////////////////////////
int calcNumNickels(int amountToCalculate)
{
    numNickels = rem / nickel;
    return numNickels;
}
int calcTotNickels(int amountToCalculate)
{
    totNickels = (numNickels * nickel);
    rem = rem - totNickels;
    return totNickels;
}
//////////////////////////////////////
int calcNumPennys(int amountToCalculate)
{
    numPennys = rem / penny;
    return numPennys;
}
int calcTotPennys(int amountToCalculate)
{
    totPennys = (numPennys * penny);
    rem = rem - totPennys;
    return totPennys;
}
//////////////////////////////////////
int calcCoins(int amountToCalculate)
{
    int new = amountToCalculate / quarter;

    if (new >= 1)
    {
        calcNumQuarters(amountToCalculate);
        calcTotQuarters(amountToCalculate);
    }
    else
    new = amountToCalculate / dime;
        if (new >= 1)
        {
            calcNumDimes(amountToCalculate);
            calcTotDimes(amountToCalculate);
        }
        else
        new = amountToCalculate / nickel;
            if (new >= 1)
            {
                calcNumNickels(amountToCalculate);
                calcTotNickels(amountToCalculate);
            }
            else
            new = amountToCalculate / penny;
                if (new >= 1)
                {
                    calcNumPennys(amountToCalculate);
                    calcTotPennys(amountToCalculate);
                }
    return numQuarters + numDimes + numNickels + numPennys;
}
