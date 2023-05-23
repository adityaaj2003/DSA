//Program to print player details
#include<stdio.h>
int n;
struct player
{
  char name[20];
  int score1,score2,score3;
}p[20];
void read(struct player p[])
{
  int i;
  printf("Enter the number of players\n");
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    printf("Enter %d player details\n",i+1);
    scanf("%s%d%d%d",p[i].name,&p[i].score1,&p[i].score2,&p[i].score3);
  }
}
void display(struct player p[])
{
  int i;
  for(i=0;i<n;i++)
  {
    printf("Player %d\n",i+1);
    printf("  Name:%s\n  Score1:%d\n  Score2:%d\n  Score3:%d\n",p[i].name,p[i].score1,p[i].score2,p[i].score3);
  }
}
void compute(struct player p[])
{
  for(int i=0;i<n;i++)
  {
    float avg=p[i].score1+p[i].score2+p[i].score3;
    printf("Average marks of %d student=%f\n",i+1,avg);
  }
}
main()
{
  read(p);
  display(p);
  compute(p);
}