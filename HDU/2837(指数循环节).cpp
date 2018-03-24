/*************************************************************************
    > File Name: test.cpp
    > Author: Akira 
    > Mail: qaq.febr2.qaq@gmail.com 
 ************************************************************************/

#include<bits/stdc++.h>
typedef long long LL;
using namespace std;
template <class T> inline void read(T &ret) {char c; ret=0;while((c=getchar())<'0'||c>'9');while(c>='0'&&c<='9') ret=ret*10+(c-'0'),c=getchar();}
template <class T> inline void out(T x) {if(x>9) out(x/10);putchar(x%10+'0');}

LL PowerMod(LL a, LL b, LL c) 
{
	LL ans = 1;
	a = a % c;
	while(b>0)
	{
		if(b & 1) ans = (ans * a) % c;
		b = b/2;
		a = (a * a) % c;
	}
	return ans;
}
LL Power(LL a, LL b, LL c)
{
    LL ans = 1;
    for(int i=1;i<=b;i++) 
    {
        ans*=a;
        if(ans>=c) return ans;
    }
    return ans;
}
LL eular(LL x)
{
    LL i,res = x;
    for(i = 2;i*i <= x;i++)
    {
        if(x % i == 0)
        {
            res = res / i * (i-1);
            while(x % i == 0)
            x /= i;
        }
    }   
    if(x > 1)
        res = res/x *(x-1);
    return  res;
}
int t;
LL n,m;
LL deal(LL a, LL b)
{
    if(a<10) return a;
    LL cnt = eular(b);
    LL tmp = deal(a/10, cnt);
    // way 1:
    LL aa = Power(a%10, tmp, b);
    if( aa>=b)
    {
        aa = PowerMod(a%10, tmp%cnt+cnt, b);
        if(aa==0) aa += b;
    }
    // way 2:
    /*
    LL aa = PowerMod(a%10, tmp+cnt, b);
    */
    return aa;
}

int main()
{
    scanf("%d", &t);
    while(t--)
    {
        read(n);read(m);
        LL ans = deal(n,m)%m;
        out(ans);puts("");
    }
}
