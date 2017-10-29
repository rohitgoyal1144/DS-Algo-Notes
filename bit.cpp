#include<bits/stdc++.h>
using namespace std;
int array[17]={0,4,2,2,2,1,2,3,15,4,2,22,12,33,16,7,9};
int BIT[17];
int GetSum(int num){
	int Sum=0;
	while(num!=0)
	{
		Sum+=BIT[num];
		num=num-(num&(-num));
	}
	return Sum;
}
void Update(int num,int val)
{
	if(num<=16)
	{
		BIT[num]+=val;
		Update(num+(num&(-num)),val);
	}
}
int main()
{
	int q;
	cin>>q;
	//basic bit array given number queries given
	int i;
	memset(BIT,0,sizeof(BIT));
	//To construct just use n updates
	for(i=1;i<=16;i++){
		cout<<array[i]<<' '<<endl;
		Update(i,array[i]);
	}
	cout<<endl;
	for(i=1;i<=16;i++)
	{
		cout<<BIT[i]<<endl;
	}
	cout<<endl;
	
	for(i=0;i<q;i++)
	{
		char op;
		int in,val;
		cin>>op>>in>>val;
		if(op=='R')
		{
			cout<<GetSum(val)-GetSum(in-1)<<endl;
		}
		else if(op=='U')
		{
			Update(in,val);
		}
	}
	return 0;
}
