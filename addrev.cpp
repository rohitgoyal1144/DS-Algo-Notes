#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define f(i,a,b) for(long long int i = (a); i < (b); i++)
#define fd(i,a,b) for(long long int i = (a); i >= (b); i--)

typedef long long int   ll;
typedef pair<ll,ll>   ii;
typedef vector< ii >    vii;
typedef vector<ll>     vi;
typedef vector< vi >    vvi;

#define pb push_back
#define mp make_pair
#define F first
#define S second
#define sz(a) (int)(a.size())
#define all(a) a.begin(),a.end()
#define SET(a,b) memset(a,b,sizeof(a))
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
/**** Harshit Mahajan (ash0904) ******/

#define nscan(n) scanf("%d",&n)
#define nscan2(n,m) scanf("%d%d",&n,&m)
#define nprint(n) printf("%d\n",n)
#define scan(n) scanf("%lld",&n)
#define scan2(n,m) scanf("%lld%lld",&n,&m)
#define print(n) printf("%lld\n",n)
#define print2(n,m) printf("%lld %lld\n",n,m)
#define br printf("\n");
#define strin(s) scanf("%s",s)
#define strout(n) printf("%s\n",n)
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

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

ll reverse(ll num)
{
  ll ans=0;
  while(num>0)
  {
    ans*=10;
    ans+=num%10;
    num/=10;
  }
  return ans;
}

int main()
{
  ll arr[100010]={0};
  ll m,n;
  ll test;
  scan(test);
  while(test--)
  {
    cin>>m>>n;
    m = reverse(m);
    n = reverse(n);
    cout<<reverse(m+n)<<"\n";
  }
  return 0;
}
