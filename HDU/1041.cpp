#include<stdio.h>
#include<algorithm>
using namespace std;
int n[1010][400],a,i,j;
int main(){
	n[1][0]=0;n[2][0]=1;
	for(i=3;i<1002;i++){
		int c=0;
		for(j=0;j<400;j++){
			n[i][j]=n[i-1][j]+2*n[i-2][j]+c;
			c=n[i][j]/10;
			n[i][j]%=10;
		}
	}
	while(~scanf("%d",&a)){
		if(a==1) printf("0\n");
		else{
			for(j=399;j>=0;j--)
			if(n[a][j]) break;
			for(i=j;i>=0;i--)
			printf("%d",n[a][i]);
			printf("\n");
		}
	}
}