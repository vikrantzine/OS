#include<math.h>
#include<stdio.h>
#include<stdlib.h>
int main()
{
 int i,n,req[50],mov=0,cp;
 printf("Enter the Current Position:\n");
 scanf("%d",&cp);
 printf("Enter the No of Requests:\n");
 scanf("%d",&n);
 printf("Enter the Request Order:\n");
 for(i=0;i<n;i++)
 {
  scanf("%d",&req[i]);
 }
 mov=mov+abs(cp-req[0]);
 printf("%d->%d",cp,req[0]);
 for(i=1;i<n;i++)
 {
  mov=mov+abs(req[i]-req[i-1]);
  printf("->%d",req[i]);
 }
 printf("\n");
 printf("Total Head Movement = %d\n",mov);
}

/*
bcs@bcs-HCL-Desktop:~$ gcc FCFSD.c 
bcs@bcs-HCL-Desktop:~$ ./a.out 
Enter the Current Position:
53
Enter the No of Requests:
8
Enter the Request Order:
98
183
41
122
14
124
65
67
53->98->183->41->122->14->124->65->67
Total Head Movement = 632
bcs@bcs-HCL-Desktop:~$ 
*/
