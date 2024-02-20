#include <cs50.h>
#include <stdio.h>

long card;
long workingCard;
int num;
int rem = 0;
long cardLengthCardNumber;
int creditcheck;

long calcMod(long calcModVal)
{
    return calcModVal % 10;
}

int sumDoubleDigits(doubDigits)
{
    return (calcMod(doubDigits) + (doubDigits / 10));
}

int getCardLength(cardNumber)
{
    int count = 0;
    cardLengthCardNumber = card;
    while (cardLengthCardNumber > 0)
    {
        cardLengthCardNumber = cardLengthCardNumber / 10;
        count = count + 1;
    }
    return count;
}

long getCardNumber()
{
    do
    {
        card = get_long("Number: ");
    }
    while (card < 0);
    return card;
}

bool checkCardLength(cardNumber)
{
    if (getCardLength(card) == 13)
    {
        return true;
    }
    else if (getCardLength(card) == 15)
    {
        return true;
    }
    else if (getCardLength(card) == 16)
    {
        return true;
    }
    else
        return false;
}

void checkVisa()
{
    creditcheck = 4;
    if (getCardLength(card) == 13)
    {
        cardLengthCardNumber = card;
        do
        {
            cardLengthCardNumber = cardLengthCardNumber / 10;
        }
        while (cardLengthCardNumber > creditcheck);
        if (cardLengthCardNumber == creditcheck)
        {
            printf("VISA\n");
        }
    }
    else if (getCardLength(card) == 16)
    {
        cardLengthCardNumber = card;
        do
        {
            cardLengthCardNumber = cardLengthCardNumber / 10;
        }
        while (cardLengthCardNumber > creditcheck);
        if (cardLengthCardNumber == creditcheck)
        {
            printf("VISA\n");
        }
    }
}

void checkMastercard51()
{
    creditcheck = 51;
    if (getCardLength(card) == 16)
    {
        cardLengthCardNumber = card;
        do
        {
            cardLengthCardNumber = cardLengthCardNumber / 10;
        }
        while (cardLengthCardNumber > creditcheck);
        if (cardLengthCardNumber == creditcheck)
        {
            printf("MASTERCARD\n");
        }
    }
}
void checkMastercard52()
{
    creditcheck = 52;
    if (getCardLength(card) == 16)
    {
        cardLengthCardNumber = card;
        do
        {
            cardLengthCardNumber = cardLengthCardNumber / 10;
        }
        while (cardLengthCardNumber > creditcheck);
        if (cardLengthCardNumber == creditcheck)
        {
            printf("MASTERCARD\n");
        }
    }
}
void checkMastercard53()
{
    creditcheck = 53;
    if (getCardLength(card) == 16)
    {
        cardLengthCardNumber = card;
        do
        {
            cardLengthCardNumber = cardLengthCardNumber / 10;
        }
        while (cardLengthCardNumber > creditcheck);
        if (cardLengthCardNumber == creditcheck)
        {
            printf("MASTERCARD\n");
        }
    }
}
void checkMastercard54()
{
    creditcheck = 54;
    if (getCardLength(card) == 16)
    {
        cardLengthCardNumber = card;
        do
        {
            cardLengthCardNumber = cardLengthCardNumber / 10;
        }
        while (cardLengthCardNumber > creditcheck);
        if (cardLengthCardNumber == creditcheck)
        {
            printf("MASTERCARD\n");
        }
    }
}
void checkMastercard55()
{
    creditcheck = 55;
    if (getCardLength(card) == 16)
    {
        cardLengthCardNumber = card;
        do
        {
            cardLengthCardNumber = cardLengthCardNumber / 10;
        }
        while (cardLengthCardNumber > creditcheck);
        if (cardLengthCardNumber == creditcheck)
        {
            printf("MASTERCARD\n");
        }
    }
}
void checkAmex34()
{
    creditcheck = 34;
    if (getCardLength(card) == 15)
    {
        cardLengthCardNumber = card;
        do
        {
            cardLengthCardNumber = cardLengthCardNumber / 10;
        }
        while (cardLengthCardNumber > creditcheck);
        if (cardLengthCardNumber == creditcheck)
        {
            printf("AMEX\n");
        }
    }
}
void checkAmex37()
{
    creditcheck = 37;
    if (getCardLength(card) == 15)
    {
        cardLengthCardNumber = card;
        do
        {
            cardLengthCardNumber = cardLengthCardNumber / 10;
        }
        while (cardLengthCardNumber > creditcheck);
        if (cardLengthCardNumber == creditcheck)
        {
            printf("AMEX\n");
        }
    }
}

// TODO:////////////////////////////////////////////////////////////////////////////////
// 1. Consolidate CARDTYPE functions into 1 cascading
// 2. Consolidate checks to determine if INVALID is first response or not BEFORE other checks
// 3. Move checkSum logic from main(void) to function(s)

bool checkNumValid(remSum)
{
    if (checkCardLength(remSum) == true)
    {
        if (remSum % 10 == 0)
        {
            return true;
        }
        else
            return false;
    }
    else
        return false;
}

int main(void)
{
    // card = 4003600000000014; //4222222222222 //4003600000000014 // 4012888888881881 // 378282246310005 // 5199999999999991 //
    // 5299999999999990 // 5555555555554444
    getCardNumber();
    if (checkNumValid(rem) == false)
    {
        printf("INVALID\n");
    }
    else
    {
        checkVisa();
        checkMastercard51();
        checkMastercard52();
        checkMastercard53();
        checkMastercard54();
        checkMastercard55();
        checkAmex34();
        checkAmex37();

        workingCard = card;
        // card = get_long("Enter credit card number: "); //TODO do not allow string or negative, and immediately do validity checks

        //    int test = 12 % 2;
        //    printf("%i\n",test);

        // printf("[0] card: %lu -- rem: %i\n", workingCard, rem);

        for (int i = 1; workingCard > 0; i++)
        {
            if (i % 2 == 1) // for every ODD [i]
            {
                rem = calcMod(workingCard) + rem; // get the remainder of the current card number and add it to the remainder
            }

            else // for every EVEN [i]
            {
                num = (calcMod(workingCard) * 2); // double every even remainder
                if (num > 9)                      // if double digits...
                {
                    rem = sumDoubleDigits(num) + rem;
                }
                else
                {
                    rem = rem + num; // else add the single digit remainder to the current rem sum
                }
                //  printf("==%i==", num);
            }
            // printf("[%i] card: %lu -- rem: %i\n", i, workingCard, rem);
            workingCard = workingCard / 10;
        }
        // printf("Num Valid? %d\n", checkNumValid(rem));
        // printf("Card Length: %i\n", getCardLength(card));
    }
}

// REFERENCE
// Visa:
// 13: 4XXXXXXXXXXXX
//     4222222222222
// 16: 4XXXXXXXXXXXXXXX
//     4012888888881881

// Amex:
// 15: 34XXXXXXXXXXXXX
// 15: 37XXXXXXXXXXXXX
//     378282246310005
//     348282246310085

// MasterCard:
// 16: 51XXXXXXXXXXXXXX
//     5199999999999991
// 16: 52XXXXXXXXXXXXXX
//     5299999999999990

// 16: 53XXXXXXXXXXXXXX
// 16: 54XXXXXXXXXXXXXX
// 16: 55XXXXXXXXXXXXXX
//     5555555555554444
