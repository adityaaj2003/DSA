//Program to swap two numbers using pointers
#include<stdio.h>
void swap(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
main()
{
    int a,b;
    printf("Enter two numbers\n");
    scanf("%d%d",&a,&b);
    swap(&a,&b);
    printf("Numbers after swaping\n%d\n%d",a,b);
}