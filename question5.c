#include<stdio.h>
int main()
{
  int a[20];
  int i=0;
  printf("Keep entering numbers and when you are done press some character -");
  while((scanf("%d",&a[i])) == 1)
  {   
     printf("%d\n",a[i]);
     i++;
  }   
  printf("User has ended giving inputs\n");
  return 0;
}