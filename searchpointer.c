//Program to search a element using pointer
#include<stdio.h>
void read(int *a[20],int k,int n)
{ 
  int i;
  printf("Enter number of elements of an array\n");
  scanf("%d",&n);
  printf("Enter the elements of array\n");
  for(i=0;i<n;i++)
  scanf("%d",(a+i));
  printf("Enter the searching element\n");
  scanf("%d",&k);
}
void compute(int a[20],int k,int n)
{
  int flag=0;
  for(int i=0;i<n;i++)
  {
    if(k==a[i])
    flag=1;
  }
  if(flag==0)
  printf("Search is successful\n");
  else
  printf("Search is unsuccessful\n");
}
void display(int a[20],int n)
{
  printf("Array is\n");
  for(int i=0;i<n;i++)
  printf("%d",a[i]);
}
main()
{
  int a[20],n,k;
  read(&a,k,n);
  display(a,n);
  compute(a,k,n);
}
