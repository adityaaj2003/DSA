//Program to check pasllindrome
#include<stdio.h>
#include<string.h>
int ispallindrome(char str[])
{
    int i,top=-1;
    char s[20],stkitem;
    for(i=0;i<strlen(str);i++)
    {
        if(str[i]=='A'||str[i]=='B'||str[i]=='a'||str[i]=='b')
          s[++top]=str[i];
        else if(str[i]=='C')
          break;
    }
    if(i==strlen(str))
     return 0;
     i++;
     while(i<strlen(str))
     {
        stkitem=s[top--];
        if(stkitem!=str[i])
          return 0;
        i++;
     }
     if(top==-1)
      return 1;
     return 0;
}

main()
{
   char str[300];
   printf("Enter string\n");
   scanf("%s",str);
   if(ispallindrome(str))
    printf("Pallindrome\n");
    else 
    printf("NOT");
}