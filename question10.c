#include <stdio.h>

int countc(char *str, char c) {
    int count = 0;
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == c) {
            count++;
        }
        i++;
    }
    return count;
}

int main() {
    char str[100];
    char c;
    printf("Enter a string: ");
    gets(str);
    printf("Enter a character to count: ");
    scanf("%c", &c);
    int count = countc(str, c);
    printf("Number of occurrences of '%c' in the string: %d\n", c, count);
    return 0;
}
