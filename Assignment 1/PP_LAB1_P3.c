//2021CSB043_DIPMAY_BISWAS
#include <stdio.h>
#include <string.h>

// compare strings s1, and s2
// len1 is the length of s1, len2 is the length of s2
int string_comp_recur(char *s1, int len1, char *s2, int len2)
{
    // CASE --> 1 , BOTH ARE EMPTY STRING
    if (len1 == 0 && len2 == 0)
        return 0;
    // CASE -->2 , STR1 IS EMPTY , STR2 IS NOT
    else if (len1 == 0 && len2 > 0)
        return -1;
    // CASE --> 3 , STR2 IS EMPTY , STR1 ISN'T
    else if (len1 > 0 && len2 == 0)
        return 1;
    // CASE -->4 , BOTH THE STRINGS ARE NOT EMPTY
    if (*s1 == *s2)
        return string_comp_recur(++s1, len1 - 1, ++s2, len2 - 1);
    else
    {
        int diff = *s1 - *s2;
        if (diff < 0)
            return -1;
        else
            return 1;
    }
}

void main()
{
    char str1[100];
    printf("Enter str1 : ");
    fgets(str1, 100, stdin);

    char str2[100];
    printf("Enter str2 : ");
    fgets(str2, 100, stdin);

    printf("Output: %d ", string_comp_recur(str1, strlen(str1), str2, strlen(str2)));
    printf("(0 if str1 and str2 is same, 1 if str1>str2, else -1)\n");
}