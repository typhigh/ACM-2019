#include <bits/stdc++.h>
#define INF 1000000000LL
#define pi acos(-1)
using namespace std;
const int M = 10010; 
vector<long long>f[M],nowf;
int n,m;
struct point
{
	long long x,y;
	point(long long x=0,long long y=0):x(x),y(y){}
}a[M],now;
point operator + (const point &x,const point &y)
{
	return point(x.x+y.x,x.y+y.y);
}
point operator - (const point &x,const point &y)
{
	return point(x.x-y.x,x.y-y.y);
}
long long gcd(long long x,long long y)
{
	if(y==0)
		return x;
	return gcd(y,x%y);
}
point Rotate(point A,int flag)
{
	int cos1=0,sin1=1;
	return point(A.x*cos1-A.y*sin1,A.x*sin1+A.y*cos1);
}
long long deal(int x,long long val)
{
	vector<long long> &y = f[x];
	auto low = lower_bound(y.begin(), y.end(), val)
	if (low == y.end()) return 0;
	auto high = upper_bound(y.begin(), y.end(), val);
	return high - low;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld%lld",&a[i].x,&a[i].y);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			if(i!=j)
			{
				point v=a[j]-a[i];
				long long h=gcd(v.x,v.y);
				v.x/=h;
				v.y/=h;
				if((long long)v.x*v.y<0ll)
				{
					v.x=abs(v.x);
					if(v.y>0)
						v.y=-v.y;
				}
				else
				{
					v.x=abs(v.x);
					v.y=abs(v.y);
				}
				f[i].push_back(v.x*INF+v.y);
			}
		sort(f[i].begin(),f[i].end());
		f[i].push_back((long long)INF*INF);
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%lld%lld",&now.x,&now.y);
		long long ans=0;
		long long cnt=0;
		nowf.clear();
		for(int j=1;j<=n;j++)
		{
			point v=a[j]-now;
			long long h=gcd(v.x,v.y);
			v.x/=h;
			v.y/=h;
			if(v.x*v.y<0)
			{
				v.x=abs(v.x);
				if(v.y>0)
					v.y=-v.y;
			}
			else
			{
				v.x=abs(v.x);
				v.y=abs(v.y);
			}
			nowf.push_back(v.x*INF+v.y);
		}
		sort(nowf.begin(),nowf.end());
		nowf.push_back((long long)INF*INF);
		for(int j=1;j<=n;j++)
		{
			point v=now-a[j];
			v=Rotate(v,1);
			long long h=gcd(v.x,v.y);
			v.x/=h;
			v.y/=h;
			if((long long)v.x*v.y<0ll)
			{
				v.x=abs(v.x);
				if(v.y>0)
					v.y=-v.y;
			}
			else
			{
				v.x=abs(v.x);
				v.y=abs(v.y);
			}
			ans+=deal(j,v.x*INF+v.y);
			v=a[j]-now;
			v=Rotate(v,1);
			h=gcd(v.x,v.y);
			v.x/=h;
			v.y/=h;
			if((long long)v.x*v.y<0ll)
			{
				v.x=abs(v.x);
				if(v.y>0)
					v.y=-v.y;
			}
			else
			{
				v.x=abs(v.x);
				v.y=abs(v.y);
			}
			int l=0,r=nowf.size()-1;
			while(l<r)
			{
				int mid=l+r>>1;
				if(nowf[mid]<v.x*INF+v.y)
					l=mid+1;
				else
					r=mid;
			}
			int st=l;
			l=0,r=nowf.size()-1;
			while(l<r)
			{
				int mid=l+r>>1;
				if(nowf[mid]<=v.x*INF+v.y)
					l=mid+1;
				else
					r=mid;			
			}
			if(nowf[l]>v.x*INF+v.y)
				l--;
			if(nowf[st]==v.x*INF+v.y)
				cnt+=l-st+1;
		}
		ans+=cnt/2;
		printf("%lld\n",ans);
	}
	return 0;
} 
