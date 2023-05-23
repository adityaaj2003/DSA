//Program to find sum of principal diagonal elements
#include<stdio.h>
void diagonal(int *a[6][6],int n)
{
    int i,sum=0;
  for(i=0;i<n;i++)
  {
    
    sum=sum+*(*(a+i)+i);
  }
  printf("Sum of principal diagonal elements %d\n",sum);
}
main()
{
  int j,a[6][6],i,n;
  printf("Enter order of square matrix\n");
  scanf("%d",&n);
  printf("Enter elements of matrix\n");
  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
        scanf("%d",&a[i][j]);
    }
  }
  diagonal(&a,n);
}