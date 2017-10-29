#include<stdio.h>
int vis[1000],g[100][100];
int n,m;

void dfs(int a,int num)
{
	int i;
	if(vis[a]==0)
		vis[a]=num;
	for(i=1;i<=n;i++)
	{
		if(g[a][i]==1 && vis[i]==0)
		{
			dfs(i,num);
		}

	}
	return;
}

int main()
{
	scanf("%d%d",&n,&m);
	int no=0,u,v,i;
	for(i=0;i<m;i++)
	{
		scanf("%d%d",&u,&v);
		g[u][v]=1;
	}
	for(i=1;i<=n;i++)
	{
		if(vis[i]==0)
		{
			no++;
		dfs(i,no);
		}
	}
	for(i=1;i<=n;i++)
	{
		printf("%d ",vis[i]);
	}
	printf("\n");
return 0;

}



