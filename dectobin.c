#include<stdio.h>
int main()
{
    int num,i=0,a[100]={0};
    printf("Enter the number\n");
    scanf("%d",&num);    
    while(num>0)
    {
        a[i]=num%2;
        num=num/2;
        i++;
    }
    printf("Binary equivalent is: ");
    for(i;i>=0;i--)
    printf("%d",a[i]);
    return 0;
}