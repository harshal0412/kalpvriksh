#include<stdio.h>

int main()
{
    char s[100],temp;
    int flag=0;
    printf("enter a string=");
    gets(s);
    for(int i=0;s[i]!='\0';i++)
    { temp=s[i];
        for(int j=i+1;s[j]!='\0';j++)
        {
            if(temp==s[j])
            {
                printf("first repitetive char is %c at index %d",s[j],j+1);
                flag=1;
                return 0;
            }
            
        }
    }
    if(!flag)
    {
        printf("Their is no repitetive char in the string");
    }
return 0;    
}
// -----------------------------------------------------------


#include <stdio.h>

int main() {
    char str[128];
    int count[128] = {0};

    printf("Enter a string: ");
    fgets(str, 128, stdin);

    // count each character in the string
    for (int i = 0; str[i]!='\0'; i++) {
        count[(int) str[i]]++;
    }

    // print the count of each character
    printf("The count of each character in the string %s is\n", str);
    for (int i = 0; i < 128; i++) {
        if (count[i] > 0 && (char) i != '\n') {
            printf("%c\t%d\n", (char) i, count[i]);
        }
    }

    return 0;
}

//---------------------------------------------
// Write a C program to convert vowels into uppercase characters in a string. Go to the editor

// Test Data :
// Input a string : w3resource
// Expected Output:

// Input a sentence: The original string:
// w3resource
// After converting vowels into upper case the sentence becomes:
// w3rEsOUrcE

#include <stdio.h>

int main()
{
    char s[100];
    printf("Input a sentence: The original string:");
    gets(s);
    
    for(int i=0;s[i]!='\0';i++)
    {
        if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
        {
            s[i]=s[i]-' ';
        }
    }
    printf("After converting vowels into upper case the sentence becomes\n %s",s);
return 0;

}

//----------------------------------------------------
#include <stdio.h>
#include <string.h>

int lengthOfLongestSubstring(char* str) {
    int n = strlen(str);
    int maxLength = 0;
    int currLength = 0;
    int visited[256];
    memset(visited, 0, sizeof(visited));

    for(int i=0, j=0; i<n; i++) {
        while(visited[str[i]]) {
            visited[str[j]] = 0;
            j++;
            currLength--;
        }
        visited[str[i]] = 1;
        currLength++;
        if(currLength > maxLength) {
            maxLength = currLength;
        }
    }

    return maxLength;
}

int main() {
    char str[100];
    printf("Input a string: ");
    scanf("%s", str);
    printf("Length of the longest substring without repeating characters: %d\n", lengthOfLongestSubstring(str));
    return 0;
}
//---------------------------------------------------------
#include<stdio.h>


#define MAX_LEN 100

int main() {
   char input[MAX_LEN];
   int stack[MAX_LEN];
   int top = -1;  
   int ans=1;
   
   printf("Enter a string with parentheses: ");
   fgets(input, MAX_LEN, stdin);
   
   // process input string
   for (int i = 0; input[i]!='\0'; i++) {
       if (input[i] == '(' || input[i] == '<'||input[i] == '{'  ||input[i] == '[') 
       {
           stack[++top] = '(';
       } 
       else if (input[i] == ')' || input[i] == '>'||input[i] == '}'  ||input[i] == ']') 
            {
           if (top >= 0 && stack[top] == '(') 
           {
               top--;
           } 
           else 
           {
               ans=0;
               printf("Check bracket in the said string is valid or not?.%d",ans);
               
               return 0;
           }
       }
   }
   
   if (top == -1) {
       printf("Check bracket in the said string is valid or not?.%d",ans);
   } else {
       ans=0;
       printf("Check bracket in the said string is valid or not?.%d",ans);
   }
   
   return 0;
}