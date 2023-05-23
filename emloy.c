//Program for employree details 
#include<stdio.h>
struct  employee
{
    int eid;
    float salary;
    char ename[20];
};
main()
{
    struct  employee e1;
    char choice;
     printf("Enter R or r for reading input and D or d for displaying output\n");
     scanf(" %c",&choice);
     switch (choice)
     {
     case 'R':
     case 'r':read(e1);
         break;
     case 'D':
     case 'd':display(e1);
             break;
    default:printf("Invalid choice");
         break;
     }
}
void read(struct employee e1)
{
    printf("Enter employee detail;s;\n");
    scanf("%d%f%s",&e1.eid,&e1.salary,e1.ename);
}
void display(struct employee e1)
{ 
    printf("Employee details:");
    printf("Id=%d,Salary=%f,name=%s",e1.eid,e1.salary,e1.ename);
}
