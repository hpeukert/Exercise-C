//exponentation with different loops.

#include <stdio.h>
#include <math.h>

int expoRec(int x, int y)
{
    return y > 0 ? x * expoRec(x, y - 1) : (y < 0 ? x * expoRec(x, y + 1) : 1);
}

int expoWhile(int x, int y)
{
    int result = 1;
    while (y > 0)
    {
        result *= x;
        y--;
    }
    while (y < 0)
    {
        result *= x;
        y++;
    }
    return result;
}

int expoFor(int x, int y)
{
    int result = 1;
    for (int i = 0; i < y; i++)
    {
        result *= x;
    }
    for (int i = 0; i > y; i--)
    {
        result *= x;
    }
    return result;
}

int expoIf(int x, int y)
{
    int result = 1;
    if (y > 0)
    {
        return result = x * expoIf(x, y - 1);
    }
    else if (y < 0)
    {
        return result = x * expoIf(x, y + 1);
    }
    return result;
}

double expoPow(int x, int y)
{
    double result = 1;
    result = pow(x, y);
    return result;
}


int main()
{
    int x, y;
    printf("enter values for exponentation to be calculated (x^y):\n");
    scanf("%d^%d", &x, &y);
    printf("recursive: %d^%d = %d\n", x, y, expoRec(x, y));
    printf("while: %d^%d = %d\n", x, y, expoWhile(x, y));
    printf("for: %d^%d = %d\n", x, y, expoFor(x, y));
    printf("if: %d^%d = %d\n", x, y, expoIf(x, y));
    printf("pow: %d^%d = %f\n", x, y, expoPow(x, y));
    return 0;
}
