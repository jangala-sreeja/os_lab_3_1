#include<stdio.h>
int philosopher[20],semaphore[20],n;
void main()
{
	int i;
	printf("Welcome to the Dining Philosophers Problem");
	printf("enter the number of philosophers");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		semaphore[i]=1;
	}
	printf("Solution of Dining Problem using Semaphores");
	while(1)
	{
		thinking();
		for(i=0;i<n-1;i++)
		{
			wait(take_fork(i));
		}
		wait(take_fork((i+1)%n));
		for(i=0i<n;i++)
		{
			if(semaphore[i]==0)
			{
				printf("philosopher %d is eating",i+1);
				
			}
		}
		
	}
}
