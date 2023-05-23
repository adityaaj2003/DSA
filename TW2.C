//Program to print book details
#include<stdio.h>
int n;
struct book
{
    char title[10];
    int edition;
    float price;
}b[10];
void read(struct book *b)
{
  int i;
  printf("Enter total number of books\n");
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    printf("Enter %d book details\n",i+1);
    scanf("%s%d%f",(b+i)->title,&(b+i)->edition,&(b+i)->price);
  }
}
void display(struct book b[])
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("Details of %d book\n",i+1);
        printf("Title:%s\nEdition%d\nPrice=%f\n",b[i].title,b[i].edition,b[i].price);
    }
}
void compute(struct book b[])
{
    int i=0,j=0;
    float large;
    large=b[0].price;
    for(i=0;i<n;i++)
    {
        if(b[i].price>large)
        {
            large=b[i].price;
            j=i;
        }
    }
    printf("Book with highest price\n");
    printf("Name:%s\nEdition:%d\nPrice:%f",b[j].title,b[j].edition,b[j].price);
}
main()
{
    read(b);
    display(b);
    compute(b);
}