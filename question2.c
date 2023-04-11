//{[1 2 3 4 5 6]}
#include<stdio.h>

int main()
{
    char input[200];
    printf("Enter a the string: ");
    fgets(input, sizeof(input), stdin);
    printf("you entered ");
    for(int i=0; input[i]!='\0';i++)
    {
        if(input[i]=='{'||input[i]=='}'||input[i]=='['||input[i]==']')
        {

        }
        else{
            printf("%c",input[i]);
        }
    }

    
return 0;
}