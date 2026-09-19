#include <bits/stdc++.h>
using namespace std;

int main(){
    unordered_map<string,int> mp;
    

    mp["0"]=0;
    mp["1"]=1;
    mp["2"]=2;

    cout<<mp.at("1")<<endl;
    cout<<mp.at("2")<<endl;

    return 0;
}