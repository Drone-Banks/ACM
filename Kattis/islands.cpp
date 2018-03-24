/*************************************************************************
    > File Name: test.cpp
    > Author: Akira 
    > Mail: qaq.febr2.qaq@gmail.com 
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
template <class T>
inline void read(T &ret) {char c; ret=0;while((c=getchar())<'0'||c>'9');while(c>='0'&&c<='9') ret=ret*10+(c-'0'),c=getchar();}
inline void out(int x) {if(x>9) out(x/10);putchar(x%10+'0');}
int P,a[15],cas,x;
struct Node
{
    int val,left,right;
}node[15];
void del(int loc)
{
    int left = node[loc].left, right = node[loc].right;
    if(left!=-1) node[left].right = right;
    if(right!=-1) node[right].left = left;
}
int main()
{
    //std::ios::sync_with_stdio(false);
    read(P);
    while(P--)
    {
        read(cas);
        for(int i=1;i<=12;i++) 
        {
            read(x);
            node[i].val = x;
            if(i==1) node[i].left = -1, node[i].right = i+1;
            else if(i==12) node[i].left = i-1, node[i].right = -1;
            else node[i].left = i-1, node[i].right = i+1;
        }
        int ans = 0;
        int before = 1;
        while(true)
        {
            int mid = node[before].right;
            if(mid==-1) break;
            if(node[mid].val <= node[before].val) 
            {
                if(node[mid].val == node[before].val || node[before].left == -1)
                {
                    del(before);
                    before = mid;   
                }
                else
                {
                    del(before);
                    before = node[before].left;
                    ans++;
                }
                continue;
            }
            int after = node[mid].right;
            if(after==-1) break;
            if(node[mid].val >= node[after].val)
            {
                if(node[mid].val>node[after].val) ans++;
                del(mid);
                continue;
            }
            before = after;
        }
        printf("%d %d\n", cas, ans);
    }
    //system("pause");
    //printf("%lld\n", ((x)%mod+mod)%mod );
    //printf("\n%.2lf sec \n", (double)clock() / CLOCKS_PER_SEC);
}
