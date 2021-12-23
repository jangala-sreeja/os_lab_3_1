#include<stdio.h>
struct procs
{
	int at,bt,ct,tat,wt,rt,f;
}p[20];
struct Gant
{
	int ind,wct;
}g[20];
void gant(int n)
{
	int l=0,i,j,k,mct;
	g[l].ind=0;
	g[l].wct=p[0].ct;
	while(l<n)
	{
		mct=g[l].wct;
		l++;
		int a[10];
		k=0;
		for(i=1;i<n;i++)
		{
			if(p[i].at<=mct&&p[i].f==0)
			{
				a[k]=i;
				k++;	
			}
		}
		int mi=a[0],max=p[a[0]].bt;
		for(j=1;j<k;j++)
		{
			if(p[a[j]].bt<max)
			{
				mi=a[j];
			}
		}
		g[l].ind=mi;
		g[l].wct=g[l-1].wct+p[mi].bt;
		p[mi].f=1;
	}
}
void main()
{
	int n,i,k=1;
	float avg_tat,avg_wt,sum=0;
	printf("enter the number of process");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("enter the arrival time and burst time %d  :",i+1);
		scanf("%d %d",&p[i].at,&p[i].bt);
		p[i].f=0;
	}
	p[0].ct=p[0].at+p[0].bt;
	p[0].f=1;
	gant(n);
	while(k<n)
	{
		for(i=1;i<n;i++)
		{
			if(g[i].ind==k)
				p[k].ct=g[i].wct;
		}
		k++;
	}
	for(i=0;i<n;i++)
	{
		p[i].tat=p[i].ct-p[i].at;
		p[i].wt=p[i].tat-p[i].bt;
		p[i].rt=p[i].wt;
	}
	printf("\npid\tat\tbt\tct\ttat\twt\trt");
	for(i=0;i<n;i++)
	{
		printf("\np%d \t%d \t%d \t%d \t%d \t%d \t%d",i+1,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt,p[i].rt);
	}
	for(i=0;i<n;i++)
	{ 
	 	sum=sum+p[i].tat;
    }
	avg_tat=sum/n;
	printf("\naverage turn around time = %f ",avg_tat);
	sum=0;
	for(i=0;i<n;i++)
	{ 
	 sum=sum+p[i].wt;
    }
	avg_wt=sum/n;
	printf("\naverage waiting time = %f",avg_wt);
}
