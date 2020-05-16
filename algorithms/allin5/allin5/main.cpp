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

typedef struct { int t; int a; } mystruct;
bool myfun(mystruct a,mystruct b) {
    if (a.a>b.a) return true;
    else if (a.a==b.a) return (a.t>b.t);
else return false;
    return a.a>b.a;
}
bool myfun2(mystruct a,mystruct b) {
    if (a.a>b.a) return true;
        else if (a.a==b.a) return (a.t<b.t);
    else return false;
        return a.a>b.a;
}

int main() {
    int n,p,i,gap=0;
    vector<mystruct> mytable;   mystruct data;
    vector<mystruct> mytable2;
    
    ifstream in("3.inp");
    in >> n ;
    for(i=0;i<n;i++){
        in >> p;
        data.a=p; data.t=i+1;
        mytable.push_back(data);
    }
    in.close();
    sort(mytable.begin(),mytable.end(),myfun);
    gap = mytable[0].a-mytable[n-1].a;
  

    cout <<data.t<<' '<<data.a;

    return 0;
}
