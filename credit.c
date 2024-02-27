#include <cs50.h>
#include <stdio.h>

long card;
long workingCard;
int num;
int rem = 0;
long cardLengthCardNumber;
int creditPrefix;
bool checkCardLengthResult;
bool checkSumResult;
bool checkNumValidResult;
int getCardLengthResult;
int getCardLength(long cardNumber);

// START FUNCTION DEFINITIONS
long getCardNumber() // TESTED WORKS prompts the user to enter a card number
{
    do
    {
        card = get_long("Number: ");
    }
    while (card < 0);
    return card;
}

int getCardLength(long cardNumber) // returns the number of digits the user has entered
{
    int count = 0;
    cardLengthCardNumber = cardNumber;
    while (cardLengthCardNumber > 0)
    {
        cardLengthCardNumber = cardLengthCardNumber / 10;
        count = count + 1;
    }
    getCardLengthResult = count;
    return count;
}

bool checkCardLength(cardLengthNumber) // validates getCardLength to ensure it is either 13, 15, or 16 digits
{
    if (cardLengthNumber == 13 || cardLengthNumber == 15 || cardLengthNumber == 16)
    {
        checkCardLengthResult = true;
        return true;
    }
    else
    {
        checkCardLengthResult = false;
        return false;
    }
}

long calcMod(long calcModVal) // called in checkSum(), returns the remainder of a number by modulo % 10
{
    return calcModVal % 10;
}

int sumDoubleDigits(doubDigits) // called in checkSum(), adds double digits (numbers 5 through 9, multiplied by 2) together)
{
    return (calcMod(doubDigits) + (doubDigits / 10));
}

bool checkSum() // checks Luhn's algorithm, returns true if mod % 10 = 0
{
    workingCard = card;
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
    if (calcMod(rem) % 10 == 0)
    {
        checkSumResult = true;
        return true;
    }
    else
    {
        checkSumResult = false;
        return false;
    }
}

bool checkNumValid(long cardNumber) // returns true if the number meets card length requirements and Luhn's algorithm
{
    getCardLength(cardNumber);
    checkCardLength(getCardLengthResult);
    if (checkCardLengthResult == true)
    {
        checkSum();
        if (checkSumResult == true)
        {
            checkNumValidResult = true;
            return true;
        }
        else
        {
            checkNumValidResult = false;
            return false;
        }
    }
    else
    {
        checkNumValidResult = false;
        return false;
    }
}

bool checkVisa() // returns true if the first digit is 4, for both 13 and 16 length card numbers
{
    creditPrefix = 4;
    if (getCardLengthResult == 13)
    {
        cardLengthCardNumber = card;
        do
        {
            cardLengthCardNumber = cardLengthCardNumber / 10;
        }
        while (cardLengthCardNumber > creditPrefix);

        if (cardLengthCardNumber == creditPrefix)
        {
            printf("VISA\n");
            return true;
        }
        else
            return false;
    }
    if (getCardLengthResult == 16)
    {
        cardLengthCardNumber = card;
        do
        {
            cardLengthCardNumber = cardLengthCardNumber / 10;
        }
        while (cardLengthCardNumber > creditPrefix);

        if (cardLengthCardNumber == creditPrefix)
        {
            printf("VISA\n");
            return true;
        }
        else
            return false;
    }
    else
        return false;
}

bool checkMastercard() // returns true if the first digit are 51 through 55, for 16 length card numbers
{
    creditPrefix = 55;
    if (getCardLengthResult == 16)
    {
        cardLengthCardNumber = card;
        do
        {
            cardLengthCardNumber = cardLengthCardNumber / 10;
        }
        while (cardLengthCardNumber > creditPrefix);
        if (cardLengthCardNumber == 55 || cardLengthCardNumber == 54 || cardLengthCardNumber == 53 || cardLengthCardNumber == 52 ||
            cardLengthCardNumber == 51)
        {
            printf("MASTERCARD\n");
            return true;
        }
        else
            return false;
    }
    else
        return false;
}

bool checkAmex() // returns true if the first digits are 37 or 34, for 15 length card numbers
{
    creditPrefix = 37;
    if (getCardLengthResult == 15)
    {
        cardLengthCardNumber = card;
        do
        {
            cardLengthCardNumber = cardLengthCardNumber / 10;
        }
        while (cardLengthCardNumber > creditPrefix);

        if (cardLengthCardNumber == 37 || cardLengthCardNumber == 34)
        {
            printf("AMEX\n");
            return true;
        }
        else
            return false;
    }
    else
        return false;
}

void checkCards() // checks if a card is Visa, Mastercard, or Amex
{
    if (checkVisa() == true)
    {
        return;
    }
    else if (checkMastercard() == true)
    {
        return;
    }
    else if (checkAmex() == true)
    {
        return;
    }
    else
    {
        printf("INVALID\n");
        return;
    }
}

// END FUNCTION DEFINITIONS

int main(void)
{
    getCardNumber();
    checkNumValid(card);

    if (checkNumValidResult == false)
    {
        printf("INVALID\n");
    }
    else if (checkNumValidResult == true)
    {
        checkCards();
    }
}

// REFERENCE NUMBERS TO TEST
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
//     5105105105105100
// 16: 52XXXXXXXXXXXXXX
//     5299999999999990

// 16: 53XXXXXXXXXXXXXX
// 16: 54XXXXXXXXXXXXXX
// 16: 55XXXXXXXXXXXXXX
//     5555555555554444
