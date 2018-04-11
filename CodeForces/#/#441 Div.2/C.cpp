#include<bits/stdc++.h>
#define MaxN 100005
using namespace std;

int n;
vector<int> ans;

int main()
{
    while(~scanf("%d", &n))
    {
        ans.clear();
        for(int x=n-81;x<n;x++)
        {
            int tmp=x, sum=0;
            while(tmp){
                sum+=tmp%10;tmp/=10;
            }
            if(x+sum==n) ans.push_back(x);
        }
        printf("%d\n", ans.size());
        for(int i=0;i<ans.size();i++) printf("%d%c", ans[i], " \n"[i==ans.size()-1]);
    }
}