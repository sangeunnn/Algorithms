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

typedef struct { int b; int s; int a;} mystruct;

bool myfun(mystruct a, mystruct b) {
    if(a.a>b.a) return true;
    else if(a.a==b.a)   {  if(a.b>b.b) return true;    else return false;}
    else return false;
}

int main() {
    int n,p,d,i,j,p1,p0,r=0;
    vector<mystruct> mytable;
    mystruct data;
    ifstream in("2.inp");
    in >> n >> p0 >>p1;
    vector<int> pt;
    pt.push_back(p0);
    pt.push_back(p1);
    cout << "pt0 pt1 : " <<pt[0]<<' '<<pt[1]<<'\n';
    
    data.a=pt[1]-pt[0]; data.b=0; data.s = 1;
    for(i=2;i<n;i++){
        in >> p;
        pt.push_back(p);
        cout << "pt_next : " <<pt[i]<<'\n';
        for(j=i-1;j>=0;j--){
            cout << " i : < " << pt[i] <<" > , j : < "<<pt[j]<<" > \n";
            d=pt[i]-pt[j];
            if(d<r) ;
            else if(d>r) { data.a=d; data.b=j+1; data.s = i+1; r=d; }
            else if(d==r){
                if(data.b>j)        {cout <<"--ck1--\n"; data.a=d; r=d;}
                else if(data.b==j)  {cout <<"--ck2--\n"; data.a=d; r=d;}
                else                {cout <<"--ck3--\n"; data.a=d; data.b=j+1; data.s=i+1; r=d;}
                cout<<" data.a : "<<data.a<<", data.b : "<<data.b<<", data.s : "<<data.s<<'\n';
            }
        }
        //mytable.push_back(data);
      //  cout <<" buy "<<mytable[i-1].b<<" sell "<<mytable[i-1].s<<" gap "<<mytable[i-1].a<<'\n';
    }
    ofstream out("2t.out");
 //   sort(mytable.begin(),mytable.end(),myfun);
    cout <<data.b <<' '<< data.s<<'\n';
    return 0;
}
