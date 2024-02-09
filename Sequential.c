#include<stdio.h>
#include<stdlib.h>
void main()
{
 int f[50],i,st,len,j,c,k,count=0;
 for(i=0;i<50;i++)
 f[i]=0;
 printf("Files Allocated are:\n");
 x:count=0;
 printf("Enter Starting Block and Length of File:");
 scanf("%d%d",&st,&len);
 for(k=st;k<(st+len);k++)
 if(f[k]==0)
 count++;
 if(len=count)
 {
  for(j=st;j<(st+len);j++)
  if(f[j]==0)
  {
   f[j]=1;
   printf("%d\t%d\n",j,f[j]);
  }
  if(j!=(st+len-1))
  printf("The Files Allocated to Disk:\n");
 }
 else
 printf("The File is Not Allocated\n");
 printf("Do you Want to Enter More File(Yes-1/No-0)");
 scanf("%d",&c);
 if(c==1)
 goto x;
 else
 exit(1);  
}
/*
bcs@bcs-HCL-Desktop:~$ gcc Sequential.c
bcs@bcs-HCL-Desktop:~$ ./a.out
Files Allocated are:
Enter Starting Block and Length of File:5
3
5	1
6	1
7	1
The Files Allocated to Disk:
Do you Want to Enter More File(Yes-1/No-0)1
Enter Starting Block and Length of File:8 
2
8	1
9	1
The Files Allocated to Disk:
Do you Want to Enter More File(Yes-1/No-0)1
Enter Starting Block and Length of File:1
6
1	1
2	1
3	1
4	1
The Files Allocated to Disk:
Do you Want to Enter More File(Yes-1/No-0)0
bcs@bcs-HCL-Desktop:~$ 
\*
