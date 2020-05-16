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

typedef struct { int t; int a;} mystruct;
bool myfun1(mystruct a,mystruct b) {
    if (a.a>b.a) return true;
    else if (a.a==b.a) return (a.t>b.t);
    else return false;
}

int main() {
    int n,p,i,gap=0;
    vector<mystruct> mytable;   mystruct data;
    
    ifstream in("1.inp");
    in >> n ;

    for(i=0;i<n;i++){
        in >> p;
        data.a=p; data.t=i+1;
        mytable.push_back(data);
    }
    sort(mytable.begin(),mytable.end(),myfun1);
    
    for(i=1;i<n;i++){
        cout<<mytable[i].a<<':'<<mytable[i].t<<'\n';
        if( mytable[0].a - mytable[i].a >=gap) {
            if(mytable[0].t > mytable[i].t)
            {data.a=mytable[0].a-mytable[i].a; data.t=mytable[i].t; gap=mytable[0].a-mytable[i].a;}
        }
    }
    cout << mytable[0].t << ' '<<data.t;
   // ofstream out("3t.out");
 //   sort(mytable.begin(),mytable.end(),myfun);
    //cout <<data.b <<' '<< data.s<<'\n';
    return 0;
}
