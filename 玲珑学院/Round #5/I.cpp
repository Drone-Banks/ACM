#include<iostream>
using namespace std;

int main(){
    long long times;
    cin>>times;
    while(times--){
        long long num;
        cin>>num;
        if(num<=0){
            cout<<"No"<<endl;
            continue;
        }
        if(num&(num-1)){
            cout<<"No"<<endl;
        }
        else{
            cout<<"Yes"<<endl;
        }
    }
}