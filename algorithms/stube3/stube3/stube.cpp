
//  stationtube
//  Created by 박상은 201645615 on 2020/03/19.
//  station_s1.cpp 의 소스코드를 이용하여 작성하였습니다.
//  Copyright © 2020 박상은. All rights reserved.

#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

struct Point {
    double x,y,z;
    Point& operator=(const Point& t){
        x = t.x;
        y = t.y;
        z = t.z;
        return *this;
    }
};

Point t;

//두점사이거리
double dist(Point& a, Point& b) {
    return sqrt(pow(a.x - b.x , 2) + pow(a.y - b.y, 2) + pow(a.z - b.z, 2));
}

Point& dvector(Point& a, Point& b, Point& r){
    r.x = abs(a.x-b.x);
    r.y = abs(a.y-b.y);
    r.z = abs(a.z-b.z);
    return r;
}

bool is_exist(Point&a, Point& b, Point& e){
    Point r;
    r = dvector(a,b,r);
    if(r.x==0)  return ((e.y-a.y)/r.z==(e.z-a.z)/r.z);
    else if(r.y==0) return ((e.x-a.x)/r.x == (e.z-a.z)/r.z);
    else if(r.z==0) return ((e.x-a.x)/r.x == (e.y-a.y)/r.y);
    else    return ((e.x-a.x)/r.x == (e.z-a.z)/r.z && (e.y-a.y)/r.y == (e.z-a.z)/r.z);
}

//점과 직선사이최단거리
Point& mdist(Point& a, Point& b, Point& p) {
    Point s;
   
    s.x = (a.x + b.x) / 2;
    s.y = (a.y + b.y) / 2;
    s.z = (a.z + b.z) / 2;
    
    int dap, dbp;
    dap = ceil(dist(a, p));
    dbp = ceil(dist(b, p));
 
    if (dap == dbp) {
        t = s;
        return t;
    }
    else if (dap > dbp)
        return mdist(s, b, p);
    else
        return mdist(a, s, p);
}

//최단직선찾기
int recursive(Point& a,Point& b,Point& c,Point& d) {
    Point t, p;
    
    t = mdist(a,b,c);
    p = mdist(c,d,t);
 
    double pre = (dist(c,t));
    double nxt = (dist(t,p));
    
    if(pre < 0.3 ){
        cout <<"is\n";
        if(is_exist(a,b,c) == true || is_exist(a,b,t)==true || is_exist(a,b,p)==true){
            pre=0;
            return pre; }
        else return recursive(a,b,p,d);
    }
    
    if(pre <= nxt)
        return ceil(pre);
    else
        return recursive(a,b,p,d);
    
}

int main() {
    Point a, b, c, d;
    ifstream in("stube.inp");
    in >> a.x >> a.y >> a.z;
    in >> b.x >> b.y >> b.z;
    in >> c.x >> c.y >> c.z;
    in >> d.x >> d.y >> d.z;
   
    ofstream out("stube.out");
    out << recursive(a, b, c, d);
    return 0;
}
