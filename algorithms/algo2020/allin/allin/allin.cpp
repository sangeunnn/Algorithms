//  main.cpp
//  allin
//
//  Created by 박상은 on 2020/03/25.
//  Copyright © 2020 박상은. All rights reserved.
//
#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

bool myfun(pair<int,int> a, pair<int,int>b) {return a.second>b.second;}
struct { int b; int s; int a;} mystruct;

mystruct buy_sell_time(vector<int>& s,mystruct b, int i) {
        int p,j,r=0;
        for(j=i-1;j>0;j--){
            p=s[i]-s[j];
            if(p>r) {b.a=p; b.b=s; b.s=j; return b;}
            r=p;
        }
    return b;
}

int main() {
    mystruct sell;
    int n,p,i,t;
    vector<int> b;
    ifstream in("1.inp");
    in >> n;
    for(int i=0;i<n;i++){
        in >> p;   b.push_back(p);
        t=buy_sell_time(b,sell,b.size());
        
    }
    return 0;
}
