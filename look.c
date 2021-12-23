#include<stdio.h>
void main()
{
	int n,a[20],i,max1=0,min2=99,sum=0;
	int head=50;
	printf("Enter the length of the Array");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter the %d element  :",i+1);
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++)
	{
		if(a[i]>50&&a[i]>max1)
			max1=a[i];
		if(a[i]<50&&a[i]<min2)
			min2=a[i];
	}
	printf("max1-%d \n",max1);
	printf("min2-%d \n",min2);
	sum=(max1-head)+(max1-min2);
	printf("The sum is %d",sum);
}
