#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

int main(){

    int A[3]={0};
    int B[3]={0};
    int P[3]={0};
    int temp=0;
    double t = 0;
    double pre_distance=0;
    double next_distance=0;
    double ap_ab=0;
    double bp_ba=0;
    double sum=0;
    double l=0;
    
    ifstream in;
    in.open("station.inp");

    for(int i=0; i<3 ; i++){
        in >> temp;
        A[i] = temp;
    }
      for(int i=0; i<3 ; i++){
        in >> temp;
        B[i] = temp;
    }
      for(int i=0; i<3 ; i++){
        in >> temp;
        P[i] = temp;
    }
    in.close();

    //vector AP, AB구하여 케이스를 나눈다.
   for(int i=0; i<3; i++){
    ap_ab += (P[i]-A[i])*(B[i]-A[i]);
    bp_ba += (P[i]-B[i])*(A[i]-B[i]);
   }
    //p는 ab 선분밖에, a에 가까이
    if(ap_ab <= 0){
        for(int i=0; i<3; i++)
           sum +=(A[i]-P[i])*(A[i]-P[i]);
    }
    //p는 ab선분사이에
    else if(bp_ba > 0){
            for(int i=0;i<3;i++)
                next_distance+=(A[i]-P[i])*(A[i]-P[i]);
            while(t<=1){
                int temp4 = 0;
                for(int i=0;i<3;i++)
                    temp4+=((t*B[i]+(1-t)*A[i])-P[i])*((t*B[i]+(1-t)*A[i])-P[i]);
                pre_distance = next_distance;
                next_distance = temp4;
                if(pre_distance-next_distance>=0)   t = t+0.001;
                else{
                    sum =pre_distance;
                    break;
                }
            }
    }
    //p는 ab선분 밖에,b에 가까이
    else{
        for(int i=0;i<3;i++)
            sum+=(B[i]-P[i])*(B[i]-P[i]);
    }
    l = ceil(sqrt(sum));
    ofstream out;
    out.open("station.out");
    out << l ;
    out.close();
}
