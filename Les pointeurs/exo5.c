#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void) {
    char *palindrome = "aad";
    char *p1, *p2;

    p1 = palindrome;
    p2 = palindrome + strlen(palindrome) - 1;
    while(p1 < p2) {
        if(*p1 != *p2) {
            printf("pas un palindrome\n");
        }
        p1++;
        p2--;
    }

    printf("fin");


    return 0;
}