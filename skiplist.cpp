//Tags:LCA,binary lifting
#include<bits/stdc++.h>
using namespace std;
vector<pair<long long int,long long int>> edges[10005];
long long int par[15][10005];
long long int depth[10005];
long long int cost[10005];
vector<long long int> dq;
long long int start=0;
bool visited[10005];
long long int walk(long long int curr,long long int jump)
{
	long long int i;
	for(i=0;i<=14 && curr!=-1;i++)
		if((1<<i) & jump)
			curr=par[i][curr];
	return curr;
}
long long int lca(long long int i,long long int j)
{
	if(depth[i]>depth[j])
		i=walk(i,depth[i]-depth[j]);
	if(depth[j]>depth[i])
		j=walk(j,depth[j]-depth[i]);
	if(i==j)
		return i;
	long long int d;
	for(d=14;d>=0;d--)
	{
		if(par[d][i]!=par[d][j])
		{
			i=par[d][i];
			j=par[d][j];		
		}	
	}
	return par[0][i];
}
long long int costq(long long int i,long long int j)
{
	return cost[i]+cost[j]-2*cost[lca(i,j)];
}
long long int dis(long long int i,long long int j)
{
	return depth[i]+depth[j]-2*depth[lca(i,j)];
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	long long int t;
	cin>>t;
	while(t--)
	{
		long long int n,i,j;
		cin>>n;
		for(i=1;i<=n;i++)
			edges[i].clear();
		dq.clear();
		memset(visited,0,sizeof(visited));
		memset(par,-1,sizeof(par));
		start=0;
		long long int u,v,c;
		for(i=1;i<n;i++)
		{
			cin>>u>>v>>c;
			edges[u].push_back(make_pair(v,c));
			edges[v].push_back(make_pair(u,c));
		}
		dq.push_back(1);
		depth[1]=0;
		cost[1]=0;
		while(start!=dq.size())
		{
			long long int curr=dq[start];
			visited[curr]=true;
			for(i=0;i<edges[curr].size();i++)
			{
				if(!visited[edges[curr][i].first])
				{
					dq.push_back(edges[curr][i].first);
					par[0][edges[curr][i].first]=curr;
					depth[edges[curr][i].first]=depth[curr]+1;
					cost[edges[curr][i].first]=cost[curr]+edges[curr][i].second;
				}
			}
			start++;
		}
		//for(i=1;i<=n;i++)
		//	cout<<depth[i]<<' '<<cost[i]<<'\n';
		for(i=1;i<=14;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(par[i-1][j]!=-1)
				{
					par[i][j]=par[i-1][par[i-1][j]];
				}
			}
		}
		string temp;
		long long int a,b,k,temp1;
		while(1)
		{
			cin>>temp;
			if(temp=="DIST")
			{
				cin>>a>>b;
				cout<<costq(a,b)<<'\n';
			}
			else if(temp=="KTH")
			{
				cin>>a>>b>>k;
				k--;
				temp1=-depth[lca(a,b)]+depth[a];
				if(temp1>=k)
				{
					cout<<walk(a,k)<<'\n';
				}
				else
				{
					cout<<walk(b,dis(a,b)-k)<<'\n';
				}
			}
			else if(temp=="DONE")
			{
				break;
			}
		}
		cout<<'\n';
	}
	return 0;
}
