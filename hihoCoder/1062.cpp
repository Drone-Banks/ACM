/*************************************************************************
	> File Name: 1062.cpp
	> Author: Akira 
	> Mail: qaq.febr2.qaq@gmail.com 
	> Created Time: 2016年10月07日 星期五 15时54分56秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <cmath>
#include <vector>
#include <set>
#include <list>
#include <ctime>
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
#define MST(a,b) memset(a,b,sizeof(a))
#define CLR(a) MST(a,0)
#define Sqr(a) ((a)*(a))
using namespace std;

#define MaxN 100000
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define bug cout<<88888888<<endl;
#define MIN(x,y) (x<y?x:y)
#define MAX(x,y) (x>y?x:y)
int main()
{
	int N,M,id=0; 
    char strbuf[1024];
	scanf("%d",&N);
	vector<string> fns,sns,names;
	map<string,int> all;
	for(int i = 0; i < N; i++) {
		string fn,sn;
		scanf("%s",strbuf);fn = strbuf;
		scanf("%s",strbuf);sn = strbuf;
		fns.push_back(fn);sns.push_back(sn);
		all[fn] = 0;all[sn] = 0;
	}
	for(map<string,int>::iterator ite = all.begin(); ite != all.end(); ite++) {
		names.push_back(ite->first); ite->second = id++;
	}
	vector<int> pid(id,-1);
	for(int i = 0; i < N; i++) pid[all[sns[i]]] = all[fns[i]];
	scanf("%d",&M);
	for(int i = 0; i < M; i++) {
		string s1,s2;
		scanf("%s",strbuf);s1 = strbuf;
		scanf("%s",strbuf);s2 = strbuf;
		
		int a=-1,b=-1;
		if(all.count(s1)) a = all[s1];
		if(all.count(s2)) b = all[s2];
		
		if(a==-1 || b==-1) {
			if(s1==s2) printf("%s\n",s1.c_str());
			else printf("-1\n");
		} else {
			vector<int> mask(id,1);
			while(a>-1) {mask[a] = 0;a = pid[a];}
			while(b>-1&&mask[b]) b = pid[b];
			if(b>-1) printf("%s\n",names[b].c_str());
			else printf("-1\n");
		}
	}
}
