#include<stdio.h>
#include<stdlib.h>

int main()
{
	long long n,m,k,p,q,r,i;
	for(i=0;i<15;i++)
	while(1)
	{
		char c;
		long long a[100006],f1,f2;
		scanf("%c",&c);
		scanf("%lld",&n);
		f1=n%5;
		f2=n%7;
		if(c=='b')
			break;
		if(c=='i')
		{
			for(i=0;i<1000;i++)
			{
				if(a[f1+i*(f2)]<=0)
				{
					a[f1 + i*(f2)]=n;
					break;
				}
			}
		}
		if(c=='d')
		{
			for(i=0;i<1000;i++)
			{
				if(a[f1 + i*(f2)]==n)
				{
					a[f1 + i*(f2)]=-1;
					break;
				}
			}
		}
		if(c=='s')
		{
			for(i=0;i<1000;i++)
			{
				if(a[f1 + i*(f2)]==n)
				{
					printf("search found\n");
					a[f1 + i*(f2)]=-1;
					break;
				}
				if(a[f1 + i*f2]==0)
				{
					printf("not found\n");
					break;
				}
			}

		}
	}
	return 0;
}

