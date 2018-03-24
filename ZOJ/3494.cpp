/*************************************************************************
    > File Name: test.cpp
    > Author: Akira 
    > Mail: qaq.febr2.qaq@gmail.com 
 ************************************************************************/

#include<bits/stdc++.h>
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
#define MST(a,b) memset(a,b,sizeof(a))
#define CLR(a) MST(a,0)
#define Sqr(a) ((a)*(a))
using namespace std;

#define MaxN 2010
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1000000009;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x << endl;
const int M = 10005,MOD=1000000009;
int N;
char A[210],B[210];
int bcd[MaxM][10];
int idx;
char str[25];
int len;
struct Trie{
    Trie *next[2];
    Trie *fail;
    int isword,kind;
};
Trie *que[M],s[M],*root;

Trie *NewNode(){
    Trie *tmp=&s[idx];
    tmp->next[0]=tmp->next[1]=NULL;
    tmp->isword=0;
    tmp->fail=NULL;
    tmp->kind=idx++;
    return tmp;
}
void init()
{
    idx=0;
    root=NewNode();
}
void Insert(Trie *root,char *s,int l){
    Trie *p=root;
    for(int i=0; i<l; i++){
        if(p->next[s[i]-'0']==NULL) p->next[s[i]-'0']=NewNode();
        p=p->next[s[i]-'0'];
    }
    p->isword=1;
}
void Bulid_fail(Trie *root){
    int head=0,tail=0;
    que[tail++]=root;
    root->fail=NULL;
    while(head<tail){
        Trie *tmp=que[head++];
        for(int i=0; i<2; i++){
            if(tmp->next[i]){
                if(tmp==root) tmp->next[i]->fail=root;
                else{
                    Trie *p=tmp->fail;
                    while(p!=NULL){
                        if(p->next[i]){
                            tmp->next[i]->fail=p->next[i];
                            break;
                        }
                        p=p->fail;
                    }
                    if(p==NULL) tmp->next[i]->fail=root;
                }
                if(tmp->next[i]->fail->isword)
                    tmp->next[i]->isword=tmp->next[i]->fail->isword;
                que[tail++]=tmp->next[i];
            }
            else if(tmp==root) tmp->next[i]=root;
            else tmp->next[i]=tmp->fail->next[i];
        }
    }
}
 
//状态当前在状态pre,经过一个数字num之后到达哪个状态
//如果不合法，返回-1
int BCD(int pre,int num){
    if(s[pre].isword) return -1;
    int cur=pre;
    for(int i=3;i>=0;i--){
        int k=(num>>i)&1;
        if(s[cur].next[k]->isword) return -1;
        else cur=s[cur].next[k]->kind;
    }
    return cur;
}
void Get_next(){
    for(int i=0;i<idx;i++){
        for(int j=0;j<10;j++){
            bcd[i][j]=BCD(i,j);
                    //debug(i) debug(j) debug(bcd[i][j])

        }
    }
}

int digits[210];
LL DP[210][MaxN];
LL dfs(int pos, int Match, bool zero, bool limit )
{
    //debug(pos) debug(Match)     
    if(Match==-1) return 0;
    if(pos==0) return 1;
    if(!limit && DP[pos][Match]!=-1) return DP[pos][Match];
    int Max = limit ? digits[pos] : 9;
    LL ans = 0;
    //debug(Max)
    for(int i=0;i<=Max;i++)
    {
        int new_match = bcd[Match][i];
        //debug(i) debug(new_match)
        ans += dfs(pos-1, zero&&i==0&&pos>1 ? Match : new_match, zero&&i==0, limit&&(i==digits[pos]) );
        ans%=mod;
    }
    if(!limit) DP[pos][Match] = ans;
    return ans;
}
 
LL find(char* str)
{
    MST(DP,-1);
    int len = strlen(str);
    for(int i=1;i<=len;i++) digits[len-i+1]=str[i-1]-'0';
    return dfs(len,0,true, true);
}

void solve()
{
    printf("%lld\n", ((find(B)-find(A))%mod+mod)%mod );
}
void subone(char* str)
{
    for(int i=strlen(str)-1;i>=0;i--)
    {
        if(str[i]=='0') str[i] = '9';
        else
        {
            str[i]--;
            break;
        }
    }
}
int main()
{
    //std::ios::sync_with_stdio(false);
    int T;
    scanf("%d", &T);
    while(T--)
    {
        init();
        scanf("%d", &N);
        while(N--)
        {
            scanf("%s", str);
            Insert(root,str,strlen(str));
        }
        //debug(AC.idx)
        Bulid_fail(root);
        Get_next();
        scanf("%s", A);
        subone(A);
        scanf("%s", B);
        solve();
    }
    //system("pause");
}
