//2021CSB043_DIPMAY_BISWAS
#include <stdio.h>

int sum(int n)
{
    if (n == 1)
        return n;
    else
        return n + sum(n - 1);
}

int main()
    {

        int n;
        printf("Enter a positive integer: ");
        scanf("%d", &n);
        printf("Sum = %d", sum(n));
        return 0;
    }