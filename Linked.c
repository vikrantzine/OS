#include<stdio.h>
#include<stdlib.h>
void main()
{
 int f[50],p,i,st,len,j,c,k,a;
 for(i=0;i<50;i++)
 f[i]=0;
 printf("Enter How Many Blocks already Allocated:");
 scanf("%d",&p);
 printf("Enter Blocks already Allocated:");
 for(i=0;i<p;i++)
 {
  scanf("%d",&a);
  f[a]=1;
 }
 x:printf("Enter Index Starting block and length:");
 scanf("%d%d",&st,&len);
 k=len;
 if(f[st]==0)
 {
  for(j=st;j<(st+k);j++)
  {
   if(f[j]==0)
   {
    f[j]=1;
    printf("%d----->%d\n",j,f[j]);
   }
   else
   {
    printf("%d Block is Already Allocated \n",j);
    k++;
   }
  }
 }
 else
 printf("%d Starting Block is Already allocated \n",st);
 printf("Do you want to Enter More File(Yes-1/No-0)");
 scanf("%d",&c);
 if(c==1)
 goto x;
 exit(0);
}
/*
bcs@bcs-HCL-Desktop:~$ gcc Linked.c
bcs@bcs-HCL-Desktop:~$ ./a.out
Enter How Many Blocks already Allocated:5
Enter Blocks already Allocated:2
7
8
6
4
Enter Index Starting block and length:2
1
2 Starting Block is Already allocated 
Do you want to Enter More File(Yes-1/No-0)1
Enter Index Starting block and length:10
5
10----->1
11----->1
12----->1
13----->1
14----->1
Do you want to Enter More File(Yes-1/No-0)1
Enter Index Starting block and length:12
2
12 Starting Block is Already allocated 
Do you want to Enter More File(Yes-1/No-0)1
Enter Index Starting block and length:14
3
14 Starting Block is Already allocated 
Do you want to Enter More File(Yes-1/No-0)0 
bcs@bcs-HCL-Desktop:~$ 
*/
