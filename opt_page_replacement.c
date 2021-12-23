#include<stdio.h>
int min(int occ[],int nf)
{
	int min=occ[0];
	int minind=0;
	int i;
	for(i=0;i<nf;i++)
	{
		if(occ[i]<min)
		{
			min=occ[i];
			minind=i;
		}
	}
	return minind;
}
int main()
{
	int nf,frames[10],npg=14,i,j,occ[10],k=0,min_occ_ind,hit=0,frame_r=0;
	int front=-1,ready_ele;
	printf("enter the number of frames");
	scanf("%d",&nf);
	for(i=0;i<nf;i++)
	{
		frames[i]=-1;
		occ[i]=0;
	}
	int pg_refer[14]={7,0,1,2,0,3,0,4,2,3,0,3,2,3};
	//int pg_refer[14]={7,0,1,2,0,3,0,4,2,3,0,3,2,3};
	while(front<npg-1)
	{
		front++;
		ready_ele=pg_refer[front];
		int c=0;
		for(j=0;j<nf;j++)
		{
			if(ready_ele==frames[j])
				{
					c++;
				}
		}
		if(c==0 && frame_r<nf)
		{
				printf("Miss ");
				frames[frame_r]=ready_ele;
				frame_r++;
		}
		else
		{
			for(i=0;i<nf;i++)
			{
				if(ready_ele==frames[i])
				{
					printf("Hit  ");
					break;
				}		
			}
			if(i==nf)
			{
				for(i=0;i<nf;i++)
				{
					for(j=front+1;j<npg;j++)
					{
						if(frames[i]==pg_refer[j])
							//occ[i]=j; //for least recently used
							occ[i]++; //for opr
					}
				}
				min_occ_ind=min(occ,nf);
				frames[min_occ_ind]=ready_ele;
				printf("Miss  ");
			}
		}
		printf("%d : ",ready_ele);
		for(i=0;i<nf;i++)
			{
				printf("%d ",frames[i]);
			}
		printf("\n");
	}
	return 0;
}
