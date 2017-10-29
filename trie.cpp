#include <bits/stdc++.h>
#include<string.h>

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

LL arr[31],ans,N;

map< pair<LL,LL>, LL > memo;

LL myfunc(LL K,LL pos){
	if(K==0){
		//printf("0\n");
		return 0;
	}
	else if(pos==N){
		//printf("1\n");
		return 1;
	}
	else{
		//map< pair < LL, LL > , LL >::iterator itr1=memo.find(make_pair(K,pos+1));
		auto itr1=memo.find(make_pair(K,pos+1));
		//map< pair < LL, LL > , LL >::iterator itr2=memo.find(make_pair(K/arr[pos],pos+1));
		auto itr2=memo.find(make_pair(K/arr[pos],pos+1));

		if(itr1==memo.end()){
			LL one= myfunc(K,pos+1);
			memo.insert(make_pair(make_pair(K, pos+1), one));
			itr1=memo.find(make_pair(K,pos+1));

		}
		if(itr2==memo.end()){
			LL two= myfunc(K/arr[pos],pos+1);
			memo.insert(make_pair(make_pair(K/arr[pos], pos+1), two));
			itr2=memo.find(make_pair(K/arr[pos],pos+1));

		}
		//printf("%lld %lld\n",(*itr1).second,(*itr2).second);
		return (*itr1).second + (*itr2).second;
	}
}

int main(){
	LL K,ans,num=0,temp,var,on=0;
	llin(N);
	llin(K);
	temp=N;

	for(int i=0;i<temp;i++){
		llin(var);
		if(var!=1){
			arr[num++]=var;
		}
		else{
			on++;
		}
	}
	N=num;
	LL xz=pow(2,on);
	ans=myfunc(K,0)*xz-1;
	llout(ans);
}
