//Program to check the number is pallindrome
#include<stdio.h>
void palindrome(int *num)
{
    int dig,rev=0,temp;
    temp=*num;
    while(temp!=0)
    {
        dig=temp%10;
        temp=temp/10;
        rev=rev*10+dig;
    }
    if(rev==*num)
    printf("%d is palindrome\n",*num);
    else
    printf("%d is not palindrome\n",*num);
}
main()
{
    int num;
    printf("Enter the number\n");
    scanf("%d",&num);
    palindrome(&num);
}