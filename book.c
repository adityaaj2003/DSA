//Program to store book details
#include<stdio.h>
#include<stdlib.h>
struct book
{
    char title[20];
    int edition,price;
}b[19];
void read(int n)
 {
    int i;
    for(i=0;i<n;i++)
     {
        printf("Enter the title of book%d\n",i+1);
        scanf("%s",b[i].title);
        printf("Enter edition of book%d\n",i+1);
        scanf("%d",&b[i].edition);
        printf("Enter price of book%d\n",i+1);
        scanf("%d",&b[i].price);
     }
 }
 void display(int n)
 {
    int i;
    for(i=0;i<n;i++)
    {
        printf("Title:%s\n",b[i].title);
        printf("Edition:%d\n",b[i].edition);
        printf("Price:%d\n",b[i].price);
    }
 }
 void compute(int n)
 {
    int i,h,highest=b[0].price;
    for(i=1;i<n;i++)
    {
        if(b[i].price>highest)
         { 
            h=i;
            highest=b[i].price;
         }
    }
    printf("Title of the book with highest price is:%s\n",b[h].title);
 }
 main()
 {
    int n;
    printf("Enter number of books\n");
    scanf("%d",&n);
    read(n);
    display(n);
    compute(n);
 }