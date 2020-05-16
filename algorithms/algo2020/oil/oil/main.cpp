#include "oil.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool myfun(int a,int b){  return (a>b);}

void oil_find(int i,int j,vector<int>& oil){
    int lnumber;

    
        lnumber=observe(i,j);
        cout <<'\n'<<lnumber<<'\n';
        if(lnumber==1){
            cout <<"oil i "<<i<<" oil j "<<j<<'\n';
            oil.push_back(i); oil.push_back(j);
            oil_find(i/2,i,oil);
        }

        else if(lnumber==2) {
            cout <<i <<' '<<j<<'\n';
            if(j-i==1) oil_find(i/2,i,oil);
            else oil_find(((i+j)/2),j,oil);
            
        }
        else if(lnumber==0) {
            if(i<=0);
            else oil_find(i/2,i,oil);
        }
        //else if(lnumber==-1);
}
/*
void oil_find_left(int i,int j,vector<int>& oil){
    int lnumber;

    
        lnumber=observe(i,j);
        cout <<'\n'<<lnumber<<'\n';
        if(lnumber==1){
            cout <<"oil i "<<i<<" oil j "<<j<<'\n';
            oil.push_back(i); oil.push_back(j);
        }

        else if(lnumber==2) {
            cout <<i <<' '<<j<<'\n';
            if(j-i==1) oil_find_left(j,j*2,oil);
            else oil_find_left(i,((i+j)/2),oil);
            
        }
        else if(lnumber==0) {
            oil_find_left(j,j*2,oil);
        }
        //else if(lnumber==-1);
}

*/
int main(){
    initial();
    int n,j,i=0;
    n=oil_size();   vector<int> oil;
    j=n-1;
    oil_find(i,j,oil);
//    oil_find(i,j,oil);
    cout <<oil.size()<<'\n';
    sort(oil.begin(),oil.end(),myfun);
    for(int i=0;i<n;i++)
    cout<<' '<<oil[i]<<' ';
    i = (oil[oil.size()-1]);
    j = oil[0];
    oil_report(i, j);
    return 0;

}
