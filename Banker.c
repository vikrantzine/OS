#include<stdio.h>
#include<stdlib.h>
int allocation[20][20],max[20][20],available[20],need[20][20],safe[10],s=0;
int finish[10],work[10],cnt=0,flag=0,temp=0;
int p,r,i,j,ch,ind,req[10];
void check()
{
 temp=0;
 s=0;
 for(i=0;i<p;i++)
 for(j=0;j<r;j++)
 need[i][j]=max[i][j]-allocation[i][j];
 printf("\nNeed Table:\n");
 for(i=0;i<p;i++)
 {
  for(j=0;j<r;j++)
  printf("%d\t",need[i][j]);
  printf("\n");
 }
 for(i=0;i<p;i++)
 finish[i]=0;
 for(i=0;i<r;i++)
 work[i]=available[i];
 while(temp<2)
 {
  for(i=0;i<p;i++)
  {
   for(j=0;j<r;j++)
   {
    if(finish[i]==0 && need[i][j]<=work[j])
    flag=1;
    else
    {
     flag=0;
     break;
    }
   }
   if(flag==1)
   {
    for(j=0;j<r;j++)
    work[j]=work[j]+allocation[i][j];
    finish[i]=1;
    safe[s++]=i;
   }
  }
  temp++;
 }
 flag=0;
 for(i=0;i<p;i++)
 {
  if(finish[i]==0)
  {
   flag=1;
   break;
  }
 }
 if(flag==1)
 {
  printf("\nSystem is in DeadLock State");
 }
 else
 {
  printf("\nSystem is in Safe State");
  printf("\nSafe Sequence is:");
  for(i=0;i<p;i++)
  printf("P%d\t",safe[i]);
 }
}
int main()
{
 system("clear");
 printf("\n----------Banker's Algorithm----------");
 printf("\n\nEnter the NO of Resources and Processes:");
 scanf("%d%d",&r,&p);
 printf("\nEnter The Allocation Table:\n");
 for(i=0;i<p;i++)
 for(j=0;j<r;j++)
 scanf("%d",&allocation[i][j]);
 printf("\nEnter The Max Table:\n");
 for(i=0;i<p;i++)
 for(j=0;j<r;j++)
 scanf("%d",&max[i][j]);
 printf("Enter The Vector Available:");
 for(i=0;i<r;i++)
 scanf("%d",&available[i]);
 check();
 printf("\nDo you want to Add New Request:(0/1)");
 scanf("%d",&ch);
 if(ch==0)
 exit(1);
 printf("\nEnter The Process No:");
 scanf("%d",&ind);
 printf("\nEnter The Requests:");
 for(i=0;i<r;i++)
 scanf("%d",&req[i]);
 flag=0;
 for(i=0;i<r;i++)
 if(req[i]<=need[ind][i])
 flag=1;
 else
 flag=0;
 if(flag==0)
 {
  printf("\nRequest Cannot be Satisfied...:");
  exit(1);
 }
 for(i=0;i<r;i++)
 if(req[i]<=available[i])
 flag=1;
 else
 flag=0;
 if(flag==0)
 {
  printf("\nRequest Can not be Satisfied...:");
  exit(1);
 }
 for(i=0;i<r;i++)
 {
  allocation[ind][i]=allocation[ind][i]+req[i];
  available[i]=available[i]-req[i];
 }
 check();
 return 0;
}


/*----------Banker's Algorithm----------

Enter the NO of Resources and Processes:3 
5

Enter The Allocation Table:
0 1 0
2 0 0
3 0 2
2 1 1 
0 0 2

Enter The Max Table:
7 5 3
3 2 2
9 0 2
2 2 2
4 3 3 
Enter The Vector Available:3 
3
2

Need Table:
7	4	3	
1	2	2	
6	0	0	
0	1	1	
4	3	1	

System is in Safe State
Safe Sequence is:P1	P3	P4	P0	P2	
Do you want to Add New Request:(0/1)1

Enter The Process No:1

Enter The Requests:1 1 1

Need Table:
7	4	3	
0	1	1	
6	0	0	
0	1	1	
4	3	1	

System is in Safe State
Safe Sequence is:P1	P3	P4	P0	P2	bcs@bcs-HCL-Desktop:~$ 
*/
