#include <bits/stdc++.h>

using namespace std;

typedef long long int 	LL;
#define din(n) scanf("%d",&n)
#define dout(n) printf("%d\n",n)
#define llin(n) scanf("%lld",&n)
#define llout(n) printf("%lld\n",n)
#define strin(n) scanf(" %s",n)
#define strout(n) printf("%s\n",n)


#define TRACE

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif
LL mod=1000000007;
LL weig[100001],u[300001],v[300001],cnt[100001]={0},vis[100001],rcnt[100001]={0},rvis[100001];
LL *arr[100001],*fin[100001],*rarr[100001],*rfin[100001];
LL mini,cmini;
stack<LL> order;

void dfs(LL vert){
	vis[vert]=1;
	for(int i=0;i<cnt[vert];i++){
		if(vis[fin[vert][i]]==0)
			dfs(fin[vert][i]);
	}
	order.push(vert);
}

void dfs2(LL vert){
	rvis[vert]=1;
	if(weig[vert]<mini){
		mini=weig[vert];
		cmini=1;
		//trace(mini,cmini);
	}
	else if(weig[vert]==mini){
		cmini++;
	}
	for(int i=0;i<rcnt[vert];i++){
		if(rvis[rfin[vert][i]]==0)
			dfs2(rfin[vert][i]);
	}
}

int main(){
	LL n,m,fcost=0,fways=1;
	llin(n);
	for(int i=1;i<=n;i++){
		llin(weig[i]);
	}
	llin(m);
	for(int i=1;i<=m;i++){
		llin(u[i]);llin(v[i]);
		cnt[u[i]]++;
		rcnt[v[i]]++;
	}
	for(int i=1;i<=n;i++){
			arr[i]=(LL*)malloc((cnt[i])*sizeof(LL));
			fin[i]=arr[i];
			rarr[i]=(LL*)malloc((rcnt[i])*sizeof(LL));
			rfin[i]=rarr[i];
	}
	for(int i=1;i<=m;i++){
		*arr[u[i]]++ = v[i];
		*rarr[v[i]]++ = u[i];
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			dfs(i);
		}
	}
	while(!order.empty()){
		if(rvis[order.top()]==0){
			mini=10000000000;cmini=0;
			dfs2(order.top());
			fcost+=mini;
			fways=(fways*cmini)%mod;
		}
		order.pop();
	}
	printf("%lld %lld\n",fcost,fways);

}
