#include<stdio.h>
void main()
{	int n,at[20],bt[20],ct[20],tat[20],wt[20],i,j,avgtat,avgwt,sum1=0,sum2=0,temp;
	printf("enter the number of processes");
	scanf("%d",&n);
	//taking arrival time and burst time as inputs
	for(i=0;i<n;i++)
	{
		printf("enter the arrival time and burst time of %d process",i+1);
		scanf("%d %d",&at[i],&bt[i]);
	}
	//sorting based on the arrival time
	/*for(i=1;i<n;i++)
	{
		for(j=i;j>=0;j--)
		{
			if(at[j]<at[j-1])
			{
				temp=at[j];
				
			}
		}
	}*/
	//calculating complete time
	ct[0]=at[0]+bt[0];
	for(i=1;i<n;i++)
	{
		if(at[i]>ct[i-1])
			ct[i]=at[i]+bt[i];  
		else
		  ct[i]=ct[i-1]+bt[i]; 
	}
	//calculating turn around  time
	for(i=0;i<n;i++)
	{	tat[i]=ct[i]-at[i]; }
	//calculating waiting time
	for(i=0;i<n;i++)
	{	wt[i]=tat[i]-bt[i];    }
	printf("p  at  bt  ct  tat  wt  rt \n");
	for(i=0;i<n;i++)
	{	printf("%d  %d  %d  %d  %d  %d  %d \n",i+1,at[i],bt[i],ct[i],tat[i],wt[i],wt[i]);   }
	for(i=0;i<n;i++)
	{  sum1=sum1+tat[i]; }
	avgtat=sum1/n;
	printf("average turn around time = %d \n",avgtat);
	for(i=0;i<n;i++)
	{  sum2=sum2+wt[i]; }
	avgwt=sum2/n;
	printf("average waiting time = %d",avgwt);
}

