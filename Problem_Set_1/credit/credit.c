#include <cs50.h>
#include <stdio.h>
int NumCheck(long CardClone)
{
    int Digits = 0;
    while (CardClone != 0)
    {
        CardClone = CardClone / 10;
        Digits++;
    }
    return Digits;
}
bool CardCheck(long CardClone)
{
    int rem1 = 0;
    int rem2 = 0;
    int sum1 = 0;
    int sum2 = 0;
    int total = 0;
    int x1 = 0;
    int x2 = 0;
    while (CardClone != 0)
    {
        rem1 = CardClone % 10;
        CardClone = CardClone / 10;
        sum1 = sum1 + rem1;
        rem2 = CardClone % 10;
        CardClone = CardClone / 10;
        rem2 = rem2 * 2;
        x1 = rem2 % 10;
        x2 = rem2 / 10;
        sum2 = sum2 + x1 + x2;
        total = sum1 + sum2;
    }
    if (total % 10 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int FirstTwoDigits(long CardClone)
{
    do
    {
        CardClone = CardClone / 10;
    }
    while (CardClone > 100);
    return CardClone;
}
int main(void)
{
    long CardNum = get_long("Enter Card Num:");
    int First2dig;
    int Digits = NumCheck(CardNum);
    if (Digits != 13 && Digits != 15 && Digits != 16)
    {
        printf("INVALID\n");
        return 0;
    }
    First2dig = FirstTwoDigits(CardNum);
    bool tester = CardCheck(CardNum);
    if (tester == true)
    {
        if (Digits == 15)
        {
            if (First2dig == 34 || First2dig == 37)
            {
                printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else if (Digits == 16 || Digits == 13)
        {
            if (First2dig >= 51 && First2dig <= 55)
            {
                printf("MASTERCARD\n");
            }
            else if (Digits == 13 || Digits == 16)
            {
                if (First2dig >= 40 && First2dig <= 49)
                {
                    printf("VISA\n");
                }
                else
                {
                    printf("INVALID\n");
                }
            }
            else
            {
                printf("INVALID\n");
            }
        }
    }
    else
    {
        printf("INVALID\n");
    }
}
