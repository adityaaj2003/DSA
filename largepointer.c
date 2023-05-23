//Program to find largest of two numbers using pointers
#include<stdio.h>
void large(int *a,int *b)
{
  if(*a>*b)
  printf("Largest is %d",*a);
  else
  printf("largest is %d",*b);
}
main()
{
  int a,b;
  printf("Enter two numbers\n");
  scanf("%d%d",&a,&b);
  large(&a,&b);
}