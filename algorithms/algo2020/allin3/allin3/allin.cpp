//  main.cpp
//  allin
//
//  name : 박상은, st_id : 201645615 on 2020/03/25.

#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
typedef struct { int b; int s; int a;} mystruct;
int main() {
    int n,p,d,i,j,p1,p0,r=0;
    vector<mystruct> mytable;
    mystruct data;
    ifstream in("allin.inp");   in >> n >> p0 >>p1;
    vector<int> pt; pt.push_back(p0);   pt.push_back(p1);
    data.a=pt[1]-pt[0]; data.b=0; data.s = 1;
    for(i=2;i<n;i++){
        in >> p;
        pt.push_back(p);
        for(j=i-1;j>=0;j--){
            if(pt[i]>=pt[i-1]) {
                d=pt[i]-pt[j];
                if(d>r) { data.a=d; data.b=j+1; data.s = i+1; r=d; }
                else if(d==r){
                    if(data.b>j)        { data.a=d; r=d;}
                    else if(data.b==j)  { data.a=d; r=d;}
                    else                { data.a=d; data.b=j+1; data.s=i+1; r=d;}
                }
            }
        }
    }
    ofstream out("allin.out");  out <<data.b <<' '<< data.s;
    return 0;
}
