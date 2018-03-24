int dfn[N][N][N];  
int f[N][N][N];  
int dfs(int k, int lp, int tim)  
{  
    if (k > g)return (n - lp >= 2);  
    if (dfn[k][lp][tim] == casei)return f[k][lp][tim];  
    dfn[k][lp][tim] = casei;  
    f[k][lp][tim] = -1e9;  
    int l = max(lp + 1, p[k] - tim);  
    int r = min(n, p[k] + tim);  
    for (int i = l; i <= r; ++i)  
    {  
        int cost = abs(p[k] - i);  
        gmax(f[k][lp][tim], dfs(k + 1, i, tim - cost) + (i - lp >= 3) * (k > 1));  
    }  
    return f[k][lp][tim];  
}  
  
void solve()  
{  
    scanf("%d", &casenum);  
    for (casei = 1; casei <= casenum; ++casei)  
    {  
        scanf("%d%d", &n, &m); m /= 2;  
        scanf("%s", s + 1);  
        g = 0; for (int i = 1; i <= n; ++i)
        if (s[i] == '2') p[++g] = i;  
        if (g == 0) { puts("0"); continue; }  
        int ans = dfs(1, 0, m);  
        printf("%d\n", ans);  
    }  
}  