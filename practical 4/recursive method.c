#include <stdio.h>
int recursive(int n)
{
    if (n == 0 || n == 1)
        return 1;
    return n * recursive(n - 1);
}
int main()
{
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("Factorial = %d", recursive(n));
    return 0;
}
