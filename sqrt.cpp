#include<bits/stdc++.h>
using namespace std;
int val[100005];
int update[100005][320];
int a[200005],b[200005];
int n,u;
void nupdate(int a1,int b1)
{
	//cout<<"*"<<a<<' '<<b<<'\n';
	for(int i=b1;i<=n;i+=a1)
	{
		//cout<<i<<' '<<'*';
		val[i]++;
	}
	//cout<<'\n';
	return;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	memset(val,0,sizeof(val));
	memset(update,0,sizeof(update));
	int i;
	cin>>n>>u;
	int sqn=sqrt(n);
	//cout<<sqn<<'\n';
	for(i=0;i<u;i++){
		cin>>a[i]>>b[i];
		if(a[i]>sqn)
		{
			//cout<<i<<' ';
			nupdate(a[i],b[i]);
		}
		else
		{
			update[b[i]][a[i]]++;
		}
	}

	for(i=1;i<320;i++)
	{
		for(int j=1;j<=n;j++)
		{
			//cout<<update[j][i]<<' ';
			if(j-i>=1)
				update[j][i]+=update[j-i][i];
			val[j]+=update[j][i];
		}
		//cout<<'\n';
	}
	for(i=1;i<=n;i++)
		cout<<val[i]<<' ';
	cout<<'\n';
	return 0;
}
