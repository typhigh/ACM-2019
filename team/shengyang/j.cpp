#include <bits/stdc++.h>
using namespace std;
const int M = 100100;
map<string ,int >f;
int n;
long long sum;
string s;
void deal()
{
	//cout<<s<<endl;
	string now;
	int lens=s.length();		
	int i;
	for(i=0;;i++)
	{
		if(s[i]==' ')
			break;
		now+=s[i];
	}
	if(now=="long")
	{
		now+=' ';
		i++;		
		for(;;i++)
		{
			if(s[i]==' ')
				break;
			now+=s[i];
		}
	}
	long long size1=0;
	bool flag=0;		
	for(;i<lens;i++)
	{
		if(s[i]==']')
			flag=0;
		if(flag)
			size1=size1*10+s[i]-'0';
		if(s[i]=='[')
			flag=1;	
	}
	if(size1==0)
		size1=1;
	//cout<<f[now]<<" "<<size1<<endl;
	sum+=(long long)f[now]*size1;
}
void init()
{
	f["int"]=4;
	f["long long"]=8;
	f["__int128"]=16;
	f["float"]=4;
	f["double"]=8;
	f["long double"]=16;
	f["bool"]=1;
	f["char"]=1;
}
int main()
{
	//fropen("1.in","r",stdin);
	init();
	int t;
	scanf("%d",&t);
	int T=0;
	while(t--)
	{
		T++;
		sum=0;
		scanf("%d",&n);
		string aa;
		getline(cin,aa);
		for(int i=1;i<=n;i++)
		{
			getline(cin,s);			
			deal();
		}
		sum+=1023;
		double kk=(double)sum/1024.000;
		long long ans=kk;
		printf("Case #%d: ",T);
		cout<<ans<<endl;
	}
	return 0;
}
