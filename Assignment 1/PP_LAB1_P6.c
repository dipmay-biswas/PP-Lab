//2021CSB043_DIPMAY_BISWAS
#include <stdio.h>

// searchs num in L
// n is the number of elements in L
int num_search_recur(int *L, int n, int num) // *L is the address pointer to the array
{                                            // pointing to the first element of the array
    if (n == 0)
    {
        printf(" element not found !!");
        return 0;
    }

    if (*L == num)
    {
        printf(" we have found our desired number  'num' !!");
        return 1;
    }
    else
        return num_search_recur(++L, n - 1, num); // pre increment because it increases the
} // value of L before assigning it

void main()
{
    int n;
    printf("Enter number of elements  of the list: ");
    scanf("%d", &n);

    int arr[n]; // here n is the length of the array
    printf("Enter the Array: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int num;
    printf("Enter number to be searched: ");
    scanf("%d", &num);

    printf("Output is : %d \n", num_search_recur(arr, n, num));
    printf("\n");
    printf("\n");
}