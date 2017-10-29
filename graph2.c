#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n,i,j,e,u[100],v[100],cnt[100]={0};
	scanf("%d%d",&n,&e);
	for(i=0;i<e;i++)
	{
		scanf("%d%d",&u[i],&v[i]);
		cnt[u[i]]++;
		cnt[v[i]]++;
	}
	int * g[100];
	int pt[100]={0};
	
	for(i=1;i<=n;i++)
	{
		g[i] = (int*)(malloc(cnt[i]*sizeof(int)));
	}
	for(i=0; i<e; i++)
	{
		g[u[i]][pt[u[i]]++] = v[i];
		g[v[i]][pt[v[i]]++] = u[i];
	}
	for(i=1;i<=n;i++)
	{
		for(j=0;j<cnt[i];j++)
		{
			printf("%d ",g[i][j]);
		}
		printf("\n");
	}
	return 0;
}
