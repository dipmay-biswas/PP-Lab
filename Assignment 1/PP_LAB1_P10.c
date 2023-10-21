//2021CSB043_DIPMAY_BISWAS
#include <stdio.h>

// sort arr in incresing order
//  n is the number of elements in arr
void sort_arr_recur(int *arr, int n)
{
    if (n == 0)
        return;

    int num = 6969; // num is one arbitrary big number that is larger than input numbers
                    // num is used to compare array elements , will be updated during the process
    int index = 0;  // here index will point out the index of largest element
                    // index is initiated with 0
    for (int i = 0; i < n; i++)
        if (arr[i] < num)
        {
            index = i;
            num = arr[i];
        }

    arr[index] = arr[0];
    arr[0] = num;

    sort_arr_recur(++arr, n - 1);
}

void main()
{
    int n;
    printf("Enter number of elements of the array: ");
    scanf("%d", &n);

    int A[n]; // 'A' is the input array , n is the array size
    printf("Enter the Array: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &A[i]);

    sort_arr_recur(A, n);

    printf("The Sorted Array is -->  ");
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
    printf("\n");
}