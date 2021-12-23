#include<stdio.h>
#include<math.h>
void main()
{
	int request[20],n,current,i,j,k,seekTime=0,difference,minimum;
	printf("Enter size of requests :");
	scanf("%d",&n);
	printf("Enter requests:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&request[i]);
	}
	printf("Enter current head position:");
	scanf("%d",&current);
	printf("From\tTo\tSeek Time\n");
	for(i=0;i<n;i++)
	{
		minimum=999;
		k=-1;
		for(j=0;j<n;j++)
		{
			if(current!=request[j] && request[j]!=999)
			{
				difference=abs(current-request[j]);
				if(difference<minimum)
				{
					minimum=difference;
					k=j;
				}
			}
		}
		printf("%d\t%d\t%d\n",current,request[k],minimum);
		current=request[k];
		seekTime+=minimum;
		request[k]=999;
	}
	printf("Total seek time is %d\n",seekTime);
}

