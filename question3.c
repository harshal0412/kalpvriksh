//input
//1 2 3 4 5 : 6 7 8 9 
//output
//1 2 3 4 5 
// 6 7 8 9
#include<stdio.h>

int main()
{
    char input[200];
    printf("Enter a the string: ");
    fgets(input, sizeof(input), stdin);

    for(int i=0; input[i]!='\0';i++)
    {
        if(input[i]==':')
        {
            printf("\n");
        }
        else{
            printf("%c",input[i]);
        }
    }

    
return 0;
}