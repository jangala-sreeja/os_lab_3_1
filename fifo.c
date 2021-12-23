#include<stdio.h>
void main()
{
	int nf,frames[10],npg,pg_refer[50],i,j,frame_f=0,frame_r=0;
	int front=-1,ready_ele;
	printf("enter the number of frames");
	scanf("%d",&nf);
	for(i=0;i<nf;i++)
	{
		frames[i]=-1;
	}
	printf("enter the number of pages");
	scanf("%d",&npg);
	printf("enter the page reference numbers");
	for(i=0;i<npg;i++)
	{
		scanf("%d",&pg_refer[i]);
	}
	while(front<npg-1)
	{
		front++;
		int c;
		ready_ele=pg_refer[front];
		for(j=0;j<nf;j++)
		{
			if(ready_ele==frames[j])
				{
					printf("Hit  ");
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
			if(frame_f<nf)
			{
				printf("Miss ");
				frames[frame_f]=ready_ele;
				frame_f++;
			}
			else
			{
				frame_f=0;
			}
		}
		printf("%d  : ",ready_ele);
		for(i=0;i<nf;i++)
		{
			printf("%d ",frames[i]);
		}
		printf("\n");
	}
}
