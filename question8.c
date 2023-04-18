#include <stdio.h>

void concat(char *str1, char *str2) {
    int i = 0;
    int j = 0;
    while (str1[i] != '\0') {
        i++;
    }
    while (str2[j] != '\0') {
        str1[i++] = str2[j++];
    }
    str1[i] = '\0';
}

int main() {
    char str1[100], str2[50];
    printf("Enter the first string: ");
    gets(str1);
    printf("Enter the second string: ");
    gets(str2);
    printf("Concatenated string: %s\n", str1);
    concat(str1, str2);
    printf("%s\n", str1);
    return 0;
}
