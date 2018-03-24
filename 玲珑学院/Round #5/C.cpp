#include<iostream>
#include<algorithm>
#include<limits.h>
using namespace std;

long long arr[105];
long long INF=INT_MAX;
long long n,a,minn=INF;



void dfs(long long num,long long arr[],long long cnt,long long bit){
    for(long long i=0;i<bit;i++){
        if(arr[i]==-1)
            continue;
        if(num%arr[i]==0){
            if(cnt<minn){
                minn=cnt;
            }
            return ;
        }
        long long tmp=arr[i];
        arr[i]=-1;
        dfs(num%tmp,arr,cnt+1,i);
        arr[i]=tmp;
    }
}

void dfs(long long num,long long arr[],long long cnt){
    for(long long i=0;i<n;i++){
        if(arr[i]==-1)
            continue;
        if(num%arr[i]==0){
            if(cnt<minn){
                minn=cnt;
            }
            return ;
        }
        long long tmp=arr[i];
        arr[i]=-1;
        dfs(num%tmp,arr,cnt+1,i);
        arr[i]=tmp;
    }
}

int main(){
    long long times;
    cin>>times;
    while(times--){
        cin>>n>>a;
        for(long long i=0;i<n;i++){
            cin>>arr[i];
        }
        sort(arr,arr+n);
        if(a<arr[0]){
            cout<<-1<<endl;
            continue;
        }
        minn=INF;
        dfs(a,arr,1);
        if(minn==INF){
            cout<<-1<<endl;
            continue;
        }
        cout<<minn<<endl;
    }
}