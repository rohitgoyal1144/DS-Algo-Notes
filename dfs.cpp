#include <bits/stdc++.h>
#include <iomanip>

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

LL u[300001],v[300001],cnt[300001]={0},vis[300001];
LL *arr[300001],*fin[300001];
double ans=0;

void dfs(LL vert,LL len,double pro){
	vis[vert]=1;
	for(int i=0;i<cnt[vert];i++){
		if(vis[fin[vert][i]]==0){
			if(vert!=1)
				dfs(fin[vert][i],len+1,pro/(cnt[vert]-1));
			else
				dfs(fin[vert][i],len+1,pro/(cnt[vert]));

		}
	}
	if(cnt[vert]==1){
		ans+=pro*len;
		//trace(vert,pro,len);
	}
}

int main(){
	LL n;
	llin(n);
	for(int i=0;i<n-1;i++){
		llin(u[i]);
		llin(v[i]);
		cnt[u[i]]++;
		cnt[v[i]]++;
	}
	for(int i=1;i<=n;i++){
			arr[i]=(LL*)malloc((cnt[i])*sizeof(LL));
			fin[i]=arr[i];

	}
	for(int i=0;i<n-1;i++){
		*arr[u[i]]++ = v[i];
		*arr[v[i]]++ = u[i];
	}
	dfs(1,0,1);
	std::cout << std::setprecision(15) << ans << '\n';
}
