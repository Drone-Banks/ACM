/*************************************************************************
    > File Name: 1230.cpp
    > Author: Akira 
    > Mail: qaq.febr2.qaq@gmail.com 
 ************************************************************************/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define MST(a,b) memset(a,b,sizeof(a))
#define CLR(a) MST(a,0)
#define MaxN 110
struct Wall{int s,e,l;}wall[MaxN];
struct cmpe{bool operator()(const Wall &a, const Wall &b){return a.e > b.e;}};
int T,N,K,lens,ans,col[MaxN];
void solve()
{
    std::sort(wall, wall+N, cmpe());
    for(int i=0; i<=lens; i++)
        if(col[i]>K)
            for(int j=0; j<N && col[i]>K; j++)
                if( wall[j].l!=-1 && wall[j].s<=i && wall[j].e>=i)
                {
                    for(int S=wall[j].s; S<=wall[j].e; S++) col[S]--;
                    wall[j].l = -1;
                    ans++;
                }
    printf("%d\n", ans);
}
int main()
{
    scanf("%d", &T);
    while(T--)
    {
        CLR(col), lens = 0, ans=0;
        scanf("%d%d", &N, &K);
        for(int i=0;i<N;i++) 
        {
            scanf("%d%d%d%d", &wall[i].s, &wall[i].l, &wall[i].e, &wall[i].l);
            if(wall[i].s>wall[i].e) 
                std::swap(wall[i].s, wall[i].e);
            lens = std::max(lens, wall[i].e);
            for(int j=wall[i].s; j<=wall[i].e; j++)
                col[j]++;
        }
        solve();
    }
}