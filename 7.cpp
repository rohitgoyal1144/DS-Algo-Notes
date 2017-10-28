//Tags: Flipping Coins,Segment Tree,Lazy Propogation
#include<bits/stdc++.h>
using namespace std;
int hi[400005],lo[400005],heads[400005],delta[400005];
void init(int i,int a,int b)
{
    lo[i]=a;
    hi[i]=b;
    if(a==b)
        return;
    int m=(a+b)/2;
    init(2*i,a,m);
    init(2*i+1,m+1,b);
}
void prop(int i)
{
    delta[2*i]=(delta[2*i]+delta[i])%2;
    delta[2*i+1]=(delta[2*i+1]+delta[i])%2;
    delta[i]=0;
}
void update(int i)
{
    heads[i]=0;
    if(delta[2*i]==0)
        heads[i]+=heads[2*i];
    else
        heads[i]+=(hi[2*i]-lo[2*i]+1-heads[2*i]);
    if(delta[2*i+1]==0)
        heads[i]+=heads[2*i+1];
    else
        heads[i]+=(hi[2*i+1]-lo[2*i+1]+1-heads[2*i+1]);
}
void flip(int i,int a,int b)
{
    if(b<lo[i] || a>hi[i])
        return;
    if(a<=lo[i] && b>=hi[i])
    {
        delta[i]=(delta[i]+1)%2;
        return;
    }
    prop(i);
    flip(2*i,a,b);
    flip(2*i+1,a,b);
    update(i);
    return;
}
int nheads(int i,int a,int b)
{
    if(b<lo[i] || a>hi[i])
        return 0;
    if(a<=lo[i] && b>=hi[i])
    {
        if(delta[i]==0)
            return heads[i];
        else
            return (hi[i]-lo[i]+1-heads[i]);
    }
    prop(i);
    int ret=nheads(2*i,a,b)+nheads(2*i+1,a,b);
    update(i);
    return ret;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    memset(heads,0,sizeof(heads));
    memset(delta,0,sizeof(delta));
    int n,k;
    cin>>n>>k;
    init(1,0,n-1);
    int i,t,u,v;
    for(i=0;i<k;i++)
    {
        cin>>t>>u>>v;
        if(t)
        {
            cout<<nheads(1,u,v)<<'\n';
        }
        else
            flip(1,u,v);
    }
    return 0;
}
