#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int heap[100005];
int heap2[100005];
int tail2;
int tail=1;
void insertdown(int data)
{
	int temp,var;
	var=tail2;
	heap2[var]=data;
	while(heap2[var/2] > heap2[var] && var>=1)
	{
		temp=heap2[var/2];
		heap2[var/2]=heap2[var];
		heap2[var]=temp;
		var=var/2;
	}
	tail2++;
	return;
}
void buildup(int arry[],int N)
{
	int t,i,temp,var,j,count=0;
	t=N-(int)pow(2,(int)(log(N)/log(2)))+1;
	for(i=0;i<t;i++)
		heap2[N-i]=arry[i];
	while(i!=N)
	{
		heap2[N-i]=arry[i];
		temp=N-i;
		count=0;
		while(((2*temp))<=N && (heap2[temp*2]<heap2[temp] || heap2[(temp*2)+1]<heap[temp]))
		{
			if((2*temp)+1<=N)
				j=heap2[2*temp]<=heap2[(2*temp)+1]?(2*temp):((2*temp)+1);
			else
				j=2*temp;
			var=heap2[temp];
			heap2[temp]=heap2[j];
			heap2[j]=var;
			temp=j;
			count++;
		}
		i++;
	}
	tail2=i+1;
	return;
}
void delete()
{
	int temp,var,j;
	heap2[1]=heap2[tail2-1];
	temp=1;
	tail2--;
	while(((2*temp))<=tail2 && (heap2[temp*2]<heap2[temp] || heap2[(temp*2)+1]<heap2[temp]))
	{
		if((2*temp)+1<=tail2)
			j=heap2[2*temp]<=heap2[(2*temp)+1]?(2*temp):((2*temp)+1);
		else
			j=2*temp;
		var=heap2[temp];
		heap2[temp]=heap2[j];
		heap2[j]=var;
		temp=j;
	}
	return;
}
int main()
{
	int N,M;
	printf("No. of initial entries\n");
	scanf("%d",&N);
	int i,j,t,arry[N];
	for(i=0;i<N;i++)
		scanf("%d",&arry[i]);	
	buildup(arry,N);
	for(i=1;i<tail2;i++)
		printf("%d ",heap2[i]);
	printf("\n");
	printf("No. of additional entries\n");
	scanf("%d",&M);
	for(i=0;i<M;i++)
	{
		scanf("%d",&j);
		insertdown(j);
		for(t=1;t<tail2;t++)
			printf("%d ",heap2[t]);
		printf("\n");
	}
		delete();
		for(i=1;i<tail2;i++)
			printf("%d ",heap2[i]);
		printf("\n");
	return 0;
}
