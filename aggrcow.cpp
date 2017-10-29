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
#define sz(a) (ll)(a.size())
#define all(a) a.begin(),a.end()
#define allrev(a) a.rbegin(),a.rend()
#define SET(a,b) memset(a,b,sizeof(a))
#define tr(c,i) for(auto i = (c).begin(); i != (c).end(); i++)
/**** Harshit Mahajan (ash0904) ******/

#define nscan(n) scanf("%d",&n)
#define nscan2(n,m) scanf("%d%d",&n,&m)
#define nprint(n) printf("%d\n",n)
#define scan(n) scanf("%lld",&n)
#define scan2(n,m) scanf("%lld%lld",&n,&m)
#define scan3(n,m,o) scanf("%lld%lld%lld",&n,&m,&o)
#define print(n) printf("%lld\n",n)
#define print2(n,m) printf("%lld %lld\n",n,m)
#define print3(n,m,o) printf("%lld%lld%lld",&n,&m,&o)
#define br() printf("\n");
#define strin(s) scanf("%s",s)
#define strout(n) printf("%s\n",n)
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
ll mod=1000000007;
double PI = 3.14159265358979323846264338327950288;

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

ll arr[100010],n,c;

bool possible(ll ans)
{
  ll cnt=1,last=1;
  f(i,2,n+1)
  {
    if(arr[i]-arr[last]>=ans)
      last=i,cnt++;
    if(cnt==c)
      return true;
  }
  return false;
}

ll search(ll low, ll up)
{
  ll ans=1,mid;
  while(low<=up)
  {
    mid = low+(up-low)/2;
    if(possible(mid))
    {
      ans = mid;
      low = mid+1;
    }
    else
      up = mid-1;
  }
  return ans;
}

int main()
{
  ll test,ans;
  scan(test);
  arr[0]=0;
  while(test--)
  {
    scan2(n,c);
    f(i,1,n+1)
      scan(arr[i]);
    sort(arr+1,arr+n+1);
    ans = search(1,1000000000);
    print(ans);
  }
  return 0;
}
