#include<stdio.h>


#define MAX_LEN 100

int main() {
   char input[MAX_LEN];
   int stack[MAX_LEN];
   int top = -1;  
   
   printf("Enter a string with parentheses: ");
   fgets(input, MAX_LEN, stdin);
   
   // process input string
   for (int i = 0; input[i]!='\0'; i++) {
       if (input[i] == '(') 
       {
           stack[++top] = '(';
       } 
       else if (input[i] == ')') 
            {
           if (top >= 0 && stack[top] == '(') 
           {
               top--;
           } 
           else 
           {
               printf("Parentheses are not balanced.\n");
               return 0;
           }
       }
   }
   
   if (top == -1) {
       printf("Parentheses are balanced.\n");
   } else {
       printf("Parentheses are not balanced.\n");
   }
   
   return 0;
}