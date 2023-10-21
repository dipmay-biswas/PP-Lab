//2021CSB043_DIPMAY_BISWAS
#include <stdio.h>
#include <string.h>

//len is string length, give index as 0
int check_palindrome_recur(char *s, int len, int index)
{  
    if (2 * index > len)
        return 1;

    if (s[index] == s[len - 1 - index])         // index and (len -1 - index) will be same in palindrome
        return check_palindrome_recur(s, len, index + 1);
    else
        return 0;
}

void main()
{
    char str[100];
    printf("Enter the string : ");
    fgets(str, 100, stdin);
    str[strcspn(str,"\n")] = '\0';
    //strcspn() calculates the length of the number of characters before the 1st occurrence of character present in both the string.

    printf("Output: %d \n", check_palindrome_recur(str, strlen(str), 0));
}

    if (s[i] == c1)
        s[i] = c2;
    i++;
    replaceChar(s, s_length - 1, c1, c2);
}

int main()
{

    char s[100], c1, c2;

    printf("Enter  the string : ");
    gets(s); // gets() is a pre-defined function in C which is used to read a string

    printf("Enter a character replace: ");
    c1 = getchar(); // getchar()take the input of a single character
    getchar();
    printf("\nEnter character to replace  with  %c : ", c1);
    c2 = getchar();
    printf("\n before replace:%s", s);

    replaceChar(s, strlen(s), c1, c2);

    printf("\n String after replace:%s", s);

    return 0;
}