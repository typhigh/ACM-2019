#include <bits/stdc++.h>
using namespace std;
const int M = 6010;
int num[M][M<<2],add[M][M<<2];
long long sum[M][M<<2];
void build(int k,)
void pushup(int cnt,int k)
{
	w[cnt][k]=w[cnt][k<<1]+w[cnt][k<<1|1];
	sum[cnt][k]=sum[cnt][k<<1]+sum[cnt][k<<1|1];
}
void pushdown(int cnt,int k)
{
	if(add[cnt][k])
	{
		add[cnt][k<<1]+=add[cnt][k];
		add[cnt][k<<1|1]+=add[cnt][k];
		sum[cnt][k<<1]+=(long long)add[cnt][k]*num[cnt][k<<1];
		sum[cnt][k<<1|1]+=(long long)add[cnt][k]*num[cnt][k<<1|1];
		add[cnt][k]=0;
	}
}
void update(int cnt,int k,int l,int r,int x,int y,int w)
{
	if(x==l&&r==y)
	{
		add[cnt][k]+=w;
		sum[cnt][k]+=(long long)w*num[cnt][k];
		return ;
	}
	pushdown(cnt,k);
	int mid=l+r>>1;
	if(mid>=y)
		update(cnt,k<<1,l,mid,x,y,w);	
	else
	{
		if(mid<x)
			update(cnt,k<<1|1,mid+1,r,x,y,w);
		else
		{
			update(cnt,k<<1,l,mid,x,mid,w);
			update(cnt,k<<1|1,mid+1,r,mid+1,y,w);	
		}	
	}
	pushup(cnt,k);
}
void update_one(int cnt,int k,int l,int r,int pl,int f,int w)
{
	if(l==r)
	{
		if(f==1)
		{
			sum[cnt][k]+=w;
			num[cnt][k]=1;
		}
		else
		{
			sum[cnt][k]=0;
			num[cnt][k]=0;
		}
		return ;
	}
	pushdown(cnt,k);
	int mid=l+r>>1;
	if(mid>=pl)
		update_one(k<<1,l,mid,pl,f,w);
	else
		update_one(k<<1|1,mid+1,r,pl,f,w);
	pushup(cnt,k);
}
long long query(int cnt,int k,int l,int r,int x,int y)
{
	pushdown(cnt,k);
	if(l==x&&r==y)
		return sum[cnt][k];	
	int mid=l+r>>1;
	if(mid>=y}
		return query(cnt,k<<1,l,mid,x,y);	
	if(mid<x)
		return query(cnt,k<<1|1,mid+1,r,x,y);
	return query(cnt,k<<1,l,mid,x,mid)+query(cnt,k<<1|1,mid+1,r,mid+1,y);
}
int main()
{

}
