#include <stdio.h>

int highestPowerOfTen(int i)
{
    int result = 1;
    while (i >= 10)
    {
        result *= 10;
        i /= 10;
    }
    return result;
}

void printAsText(int i)
{
    if (i < 0)
    {
        printf("minus ");
        i = -i;
    }
    for (int highestDigit = highestPowerOfTen(i); highestDigit > 0; highestDigit = highestDigit/10)
    {
        printDigit(i/highestDigit);
        printf(" ");
        i = i % highestDigit;
    }
    printf("\n");
}

void printDigit(int x)
{
    switch (x)
    {
        case 1: printf("one "); break;
        case 2: printf("two "); break;
        case 3: printf("three "); break;
        case 4: printf("four "); break;
        case 5: printf("five "); break;
        case 6: printf("six "); break;
        case 7: printf("seven "); break;
        case 8: printf("eight "); break;
        case 9: printf("nine "); break;
        case 0: printf("zero "); break;
        default: printf("no numeral"); break;
    }
}

int main()
{
    int i;
    printf("Enter number: ");
    scanf("%d", &i);
    printAsText(i);
    return 0;
}