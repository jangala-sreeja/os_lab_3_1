#include<stdio.h>
void main()
{
	int size,request[50],cur_posn,i,sum=0,seek_time;
	printf("enter the Size of requests");
	scanf("%d",&size);
	printf("enter the requests");
	for(i=0;i<size;i++)
	{
		scanf("%d",&request[i]);
	}	
	printf("enter the current position");
	scanf("%d",&cur_posn);
	printf("From\tTo\tSeek_time");
	printf("\n");
	for(i=0;i<size;i++)
	{
		if(cur_posn>request[i])
			seek_time=cur_posn-request[i];
		else
			seek_time=request[i]-cur_posn;
		printf("%d\t%d\t%d",cur_posn,request[i],seek_time);
		printf("\n");
		cur_posn=request[i];
		sum=sum+seek_time;
	}
	printf("the sum of seek time is %d",sum);
}
