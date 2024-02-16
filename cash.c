#include <cs50.h>
#include <stdio.h>

int numQuarters;
int numDimes;
int numNickels;
int numPennys;
int totQuarters;
int totDimes;
int totNickels;
int totPennys;

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

    printf("%i x quarters = %i\n",numQuarters, totQuarters);
    printf("%i x dimes = %i\n", numDimes, totDimes);
    printf("%i x nickels = %i\n", numNickels, totNickels);
    printf("%i x pennys = %i\n", numPennys, totPennys);
    printf("---------------\n= %i total # of coins\n", coins);

}

int calcCoins(int amountToCalculate)
{
    const int quarter = 25;
    const int dime = 10;
    const int nickel = 5;
    const int penny = 1;
    int rem;

    numQuarters = amountToCalculate / quarter;
    totQuarters = (numQuarters * quarter);
    rem = amountToCalculate - totQuarters;

    numDimes = rem / dime;
    totDimes = (numDimes * dime);
    rem = rem - totDimes;

    numNickels = rem / nickel;
    totNickels = (numNickels * nickel);
    rem = rem - totNickels;

    numPennys = rem / penny;
    totPennys = (numPennys * penny);
    rem = rem - totPennys;

    return numQuarters + numDimes + numNickels + numPennys;
}
