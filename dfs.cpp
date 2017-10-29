#include<bits/stdc++.h>
#define s(a) scanf("%d",&a)
#define p(a) printf("%d\n",a)
using namespace std;
//Adjacency list first vertex and second contain weight
vector<int> edges[1001];
int visited[1001];
void dfs(int curr)
{
	cout<<curr<<endl;
	visited[curr]=1;
	vector<int>::iterator it;
	for(it=(edges[curr]).begin();it!=(edges[curr]).end();it++)
	{
		if(visited[*it]==0)
			dfs(*it);
	}
}
int main()
{
	memset(visited,0,sizeof(visited));
	int n,m;
	cout<<"number of vertices\n";
	cin>>n;
	cout<<"number of edges\n";
	cin>>m;
	int i;
	//directed edges
	int u,v;
	for(i=0;i<m;i++)
	{
		cin>>u>>v;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	dfs(3);
	return 0;	
}
