#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
typedef long long ll;
inline int read()
{
    int x=0,f=1; char ch=getchar();
    while(ch<'0'||ch>'9') { if(ch=='-') f=-1; ch=getchar(); }
    while(ch>='0'&&ch<='9') { x=(x<<1)+(x<<3)+(ch^48); ch=getchar(); }
    return x*f;
}
const int N=1e6+7;
int n;
int main()
{
    n=read();
    int now=1;
    while(now<=n)
    {
        if(now==n || now+1==n) { printf("1\n"); return 0; }
        if(now&1) now=(now+1)+1+now;
        else now=now+1+now;
    }
    printf("0\n");
    return 0;
}