#include<bits/stdc++.h>
#define MaxN 300005
using namespace std;

int n,p[MaxN];
bool flag[MaxN];
vector<int> ans;
int main()
{
    while(~scanf("%d", &n))
    {
        memset(flag, 0, sizeof(flag));
        ans.clear();
        int last = n, val = 1;
        ans.push_back(val);
        for(int i=0;i<n;i++){
            scanf("%d", &p[i]);
            flag[p[i]] = 1;
            val++;
            if(flag[last]){
                while(last && flag[last]) last--, val--;
            }
            ans.push_back(val);
        }
        for(int i=0;i<ans.size();i++)
        {
            printf("%d%c", ans[i], " \n"[i==ans.size()-1]);            
        }
    }    
}