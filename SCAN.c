#include<stdio.h>
#include<stdlib.h>
int main()
{
 int RQ[100],i,j,n,TotalHeadMoment=0,initial,size,move;
 printf("Enter the No of Requests:\n");
 scanf("%d",&n);
 printf("Enter the Requests Sequence:\n");
 for(i=0;i<n;i++)
 scanf("%d",&RQ[i]);
 printf("Enter Initial head Position:\n");
 scanf("%d",&initial);
 printf("Enter total Disk Size:\n");
 scanf("%d",&size);
 printf("Enter the Head movement direction for High 1 and for Low 0:\n");
 scanf("%d",&move);
 for(i=0;i<n;i++)
 {
  for(j=0;j<n-i-1;j++)
  {
   if(RQ[j]>RQ[j+1])
   {
    int temp;
    temp=RQ[j];
    RQ[j]=RQ[j+1];
    RQ[j+1]=temp;
   }
  }
 }
 int index;
 for(i=0;i<n;i++)
 {
  if(initial<RQ[i])
  {
   index=i;
   break;
  }
 }
 if(move==1)
 {
  for(i=index;i<n;i++)
  {
   TotalHeadMoment=TotalHeadMoment+abs(RQ[i]-initial);
   initial=RQ[i];
  }
  TotalHeadMoment=TotalHeadMoment+abs(size-RQ[i-1]-1);
  initial = size-1;
  for(i=index-1;i>=0;i--)
  {
   TotalHeadMoment=TotalHeadMoment+abs(RQ[i]-initial);
   initial=RQ[i];
  }
 }
 else
 {
  for(i=index-1;i>=0;i--)
  {
   TotalHeadMoment=TotalHeadMoment+abs(RQ[i]-initial);
   initial=RQ[i];
  }
  TotalHeadMoment=TotalHeadMoment+abs(RQ[i+1]-0);
  initial =0;
  for(i=index;i<n;i++)
  {
   TotalHeadMoment=TotalHeadMoment+abs(RQ[i]-initial);
   initial=RQ[i];            
  }
 }
 printf("Total Head Movement is: %d",TotalHeadMoment);
 return 0;
}

/*
bcs@bcs-HCL-Desktop:~$ gcc SCAN.c 
bcs@bcs-HCL-Desktop:~$ ./a.out 
Enter the No of Requests:
8
Enter the Requests Sequence:
98
183
41
122
14
124
65
67
Enter Initial head Position:
53
Enter total Disk Size:
200
Enter the Head movement direction for High 1 and for Low 0:
1
Total Head Movement is: 331bcs@bcs-HCL-Desktop:~$ 
*/

