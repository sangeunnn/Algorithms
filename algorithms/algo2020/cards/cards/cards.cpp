//  main.cpp
//  학번 : 201645615
//  이름 : 박상은

#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

int main(){
    
    ifstream in;
    int n,number;
    int a,b = 0;
    int c,d = 0;
    int total_sum=0;
    int total_mult=1;
    int sum=0;
    int mult=1;
    
    // input
    in.open("cards.inp");
    in >> n;
    for(int i=1;i<=n;i++){
        total_sum += i;
        total_mult += i*i;
    }
    for(int i=0;i<n-2;i++){
        in >> number;
        sum += number;
        mult += number * number;
    }
    in.close();
    
    // find not exist numbers
    c = total_sum - sum;
    d = total_mult - mult;
    b = (c+sqrt(2*d-c*c))*0.5;
    a = c-b;

    // output in Ascending order
    ofstream out;
    out.open("cards.out");
    if(a<b) out <<a<<'\n'<< b;
    else    out << b <<'\n'<< a;
    out.close();

    return 0;
}
