//"random" number generation

#include <stdio.h>
int randomNumberGenerator()
{
    static int x = 15;
    static int a = 39;
    static int c = 7;
    static int m = 100;
    x = (a * x + c) % m;
    return x;
}
int loop(int i)
{
    printf("%i ", randomNumberGenerator());
    return i > 0 ? loop(i - 1) : 0;
}
int main()
{
    loop(100);
    return 0;
}
