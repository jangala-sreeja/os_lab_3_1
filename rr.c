#include<stdio.h>
//First we create the Process table  using structure
struct procs
{
	int at,bt,ct,tat,wt,rt,tbt;	
}p[20];
//Gant chart using structure with index and work completion time.
struct gant
{
	int ind,wct;
}g[20];
void main()
{
	int n,i,pid=0,rq[20],tq,r=-1,f=-1,j,gi=0;
	float avg_tat,avg_wt,sum=0;
	printf("enter the number of process and time quantum");
	scanf("%d %d",&n,&tq);
	for(i=0;i<n;i++)
	{
		printf("enter the arrival time and burst time %d  :",i+1);
		scanf("%d %d",&p[i].at,&p[i].bt);
		p[i].tbt=p[i].bt;
	}
	r++;
	rq[r]=pid;//this is the ready queue //adding 0 th process to the queue pid=0
	while(r!=f)
	{
		f++;
		if(gi==0)
		{
			if(p[rq[f]].tbt>tq)
			{
				g[gi].ind=rq[f];
				g[gi].wct=tq;
				p[gi].tbt=p[gi].tbt-tq;
			}
			else
			{
				g[gi].ind=rq[f];
				g[gi].wct=p[gi].tbt;
				p[gi].tbt=0;
			}	
		}
		else
		{
			if(p[rq[f]].tbt>tq)
			{
				g[gi].ind=rq[f];
				g[gi].wct=g[gi-1].wct+tq;
				p[rq[f]].tbt=p[rq[f]].tbt-tq;
			}
			else
			{
				g[gi].ind=rq[f];
				g[gi].wct=g[gi-1].wct+p[rq[f]].tbt;
				p[rq[f]].tbt=0;	
			}
		}
		int max=g[gi].wct;
		gi++;
		for(i=pid+1;i<n;i++) // now from the remaining process if the arrival time is less than the 
		{
			if(pid<n)
			{
				if(p[i].at<=max)
				{
					r++;
					pid++;
					rq[r]=pid;
				}
			}
		}
		if(p[rq[f]].tbt>0)
		{
			r++;
			rq[r]=rq[f];
		}	
	}
	pid=0;
	while(pid<n)
	{
		for(i=0;i<gi;i++)
		{
			if(g[i].ind==pid)
				p[pid].ct=g[i].wct;
		}pid++;
	}
	for(i=0;i<n;i++)
	{
		p[i].tat=p[i].ct-p[i].at;
		p[i].wt=p[i].tat-p[i].bt;
	}
	pid=0;
	while(pid<n)
	{
		for(i=0;i<gi;i++)
		{
			if(g[i].ind==pid)
			{
				p[pid].rt=g[i-1].wct-p[pid].at;
				break;
			}	
		}pid++;
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