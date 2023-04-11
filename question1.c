#include<stdio.h>

//harshal   jain
int main()
{
    char input[200];
    printf("Enter a string with tabs: ");
    fgets(input, sizeof(input), stdin);
    printf("You entered: %s\n", input);
    
return 0;
}