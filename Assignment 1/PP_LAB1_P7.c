//2021CSB043_DIPMAY_BISWAS
#include <stdio.h>
#include<math.h>

//print L in reverse
//n is the no. of elements in L
void print_reverse_recur(int *L, int n)    // here we are taking the address of the array L (*L) 
{                                          // and the size of the array 'n' as input 
    if (n == 0)
        return;

    int reverseArray = *L;               // pointer to the array points to the 0th (first) element of the array
    print_reverse_recur(++L, n - 1);
    printf("%d ", reverseArray);
}

// here's the main function to demonstrate the work of the function

void main()
{   int n;
    printf("Enter number of elements of the array: ");
    scanf("%d", &n);

    int arr[n];     //  where n is the size of the array
    printf("Enter Array: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Reverse Array of the input array is :\n ");
    print_reverse_recur(arr, n);      // here we are calling the recursive function 
    printf("\n");

}
