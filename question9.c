#include <stdio.h>

int compare(char *str1, char *str2) {
    int i = 0;
    while (str1[i] != '\0' || str2[i] != '\0') {
        if (str1[i] < str2[i]) {
            return -1;
        } else if (str1[i] > str2[i]) {
            return 1;
        }
        i++;
    }
    return 0;
}

int main() {
    char str1[100], str2[100];
    printf("Enter the first string: ");
    gets(str1);
    printf("Enter the second string: ");
    gets(str2);
    int result = compare(str1, str2);
    if (result == -1) {
        printf("String 1 is less than String 2\n");
    } else if (result == 1) {
        printf("String 1 is greater than String 2\n");
    } else {
        printf("String 1 is equal to String 2\n");
    }
    return 0;
}
