#include<bits/stdc++.h>
#define MaxN 100005
using namespace std;

int n,k,m,a[MaxN];
vector<int> res[MaxN];

int main()
{
    while(~scanf("%d%d%d", &n, &k, &m))
    {
        for(int i=0;i<m;i++) res[i].clear();
        for(int i=0;i<n;i++) {
            scanf("%d", &a[i]);
            int tmp = a[i]%m;
            res[tmp].push_back(a[i]);
        }
        bool flag = true;
        for(int i=0;i<m;i++){
            if(!res[i].empty() && res[i].size()>=k){
                puts("Yes");
                for(int j=0;j<k;j++) printf("%d%c", res[i][j], " \n"[j==k-1]);
                flag = false;
                break;
            }
        }
        if(flag) puts("No");
    }
}