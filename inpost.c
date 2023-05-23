//Program to convert the expression from infix to post fix
#include<stdio.h>
#include<string.h>
#include<ctype.h>
int precedence(int a)
{
    if(a=='^'||a=='*'||a=='/')
    return 1;
    else if(a=='+'||a=='-')
    return 2;
    else 
    return -1;
}
// void push(char ch,int *top)
// {
//   *top++;
  
// }
main()
{
    int stk[20],top=-1,post[20],infi[20],i,j=0;
    printf("Enter infix expression\n");
    scanf("%s",infi);
    for(i=0;i<strlen(infi);i++)
    {
        if(isalnum(infi[i]))
        {
         post[j]=infi[i];
         j++; 
        }
        else if(infi[i]=='(')
        {
            top++;
            stk[top]=infi[i];
        }
        else if(infi[i]==')')
        {
            post[j]=stk[top];
            top--;
            j++;
        }
        else 
        {
            if(precedence(stk[top])<=infi[i])
            {
                post[j]=stk[top];
                stk[top]=infi[i];
                j++;
            }
            else
            {
                top++;
                stk[top]=infi[i];
            }
        }

    }

printf("Postfix %s",post);
}