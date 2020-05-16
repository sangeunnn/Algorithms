#include "oil.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool myfun(int a,int b){  return (a>b);}

bool oil_left_find(double i,double j,double pre_i,vector<double>& oil){
    int l=observe(i,j); cout << i <<' '<<j<<' '<< pre_i <<'\n';
    if(l==2) {
        cout<<"2--\n";
        if(j-i==1) {
                   oil.push_back(j);
                   return true;
               }
        oil_left_find(floor((i+j)/2),j,pre_i,oil);
    }
    else if(l==1) {
        cout<<"1--\n";
        if(j-i<=1) {
                   oil.push_back(i);
                   return true;
               }
        oil_left_find(floor((pre_i+i)/2),i,floor((pre_i+i)/2),oil);
    }
    return false;
}

bool oil_right_find(double i,double j,double pre_j,vector<double>& oil){
    int l=observe(i,j); cout << i <<' '<<j<<' '<< pre_j <<'\n';
    if(l==2) {
        cout<<"2--\n";
        if(j-i==1) {
                   oil.push_back(i);
                   return true;
               }
        oil_right_find(i,floor((i+j)/2),pre_j,oil);
    }
    else if(l==1) {
        cout<<"1--\n";
        if(j-i<=1) {
                   oil.push_back(j);
                   return true;
               }
        oil_right_find(i,floor((pre_j+j)/2),floor((pre_j+j)/2),oil);
    }
    return false;
}

void oil_find(double i,double j,vector<double>& oil){
    int r = observe(floor((i+j)/2)+1,j);
    int l = observe(i,floor((i+j)/2));
    cout <<"-- "<<i <<' '<<j<<'\n';
    if(l==0&&r==0){
        ;
    }
    if(l==0 && r==1) {
        cout <<"l==0 && r==1"<<'\n';
        oil.push_back(floor((i+j)/2)+1);
        oil.push_back(j);
    }
        
    else if(l==0 && r==2){
        cout <<"l==0 && r==2"<<'\n';
        oil_find(floor((i+j)/2)+1,j,oil);
    }
    
    else if(l==1 && r==0){
        cout <<"l==1 && r==0"<<'\n';
        oil.push_back(i);
        oil.push_back(floor((i+j)/2));
    }
    else if(l==1 && r==1){
        cout <<"l==1 && r==1)"<<'\n';
        oil.push_back(i);
        oil.push_back(j);
    }
    else if(l==1 && r==2){
        cout <<"l==1 && r==2"<<'\n';
        oil.push_back(i);   cout<<i<<'\n';
        oil_right_find(floor((i+j)/2)+1,j,j,oil);
    }
    else if(l==2 && r==0){
        cout <<"l==2 && r==0"<<'\n';
        oil_find(i,floor((i+j)/2),oil);
    }
    else if(l==2 && r==1){
        cout <<"l==2 && r==1)"<<'\n';
        oil.push_back(j);
        oil_left_find(i,floor((i+j)/2),i,oil);
   
    }
    else if(l==2 && r==2){
        cout <<"l==2 && r==2"<<'\n';
        oil_left_find(i,floor((i+j)/2),i,oil);
        oil_right_find(floor((i+j)/2)+1,j,j,oil);
    }

    
}

int main(){
    initial();
    double n,j,i=0;
    n=oil_size();   vector<double> oil;
    j=n-1;
    oil_find(i,j,oil);
    
    int k =oil.size();
    sort(oil.begin(),oil.end(),myfun);
    
    i = oil[k-1];
    j = oil[0];
    
    oil_report(i, j);
   
    return 0;

}
