#include<stdio.h>
#include<string.h>
#include<math.h>
long long m=1000000007;

int main()
{
	long long hashf[101],hashb[101];
	char strng[100];

	scanf("%s",strng);
	long long r,l;

	long long a,len=strlen(strng),temp1=1;
	long long temp2=strng[0]-'a'+1;
	hashf[0]=temp2*temp1;

	for(a=1;a<len;a++)
	{
		temp1 *= 26;
		temp2 = (strng[a]-'a'+1);
		hashf[a]=hashf[a-1]+temp1*temp2;
	}

	temp1=1;
	temp2=strng[len-1]-'a'+1;
	hashb[0]=temp2*temp1;
	for(a=1;a<len;a++)
	{
		temp1 *= 26;
		temp2 = (strng[len-1-a]-'a'+1);
	//	printf("(%c %d)",strng[len-1-a],a);
		hashb[a]=hashb[a-1]+temp1*temp2;
	}
	
/*	
	for(a=0;a<len;a++)
		printf("%Ld ",hashf[a]);
	printf("\n");
	for(a=0;a<len;a++)
		printf("%Ld ",hashb[a]);
	printf("\n");
*/
	scanf("%Ld %Ld",&l,&r);

	long long po,hash1,hash2;
	po=pow(26,l);
	if(l==0)
		hash1=hashf[r];
	else
		hash1=(hashf[r]-hashf[l-1])/po ;
	po=pow(26,len-1-r);
	hash2=(hashb[len-l-1]-hashb[len-2-r])/po ;

	if(hash1==hash2)
		printf("Yes\n");
	else
		printf("No\n");
	
return 0;
}
