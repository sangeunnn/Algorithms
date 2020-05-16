#include "oil.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool myfun(int a,int b){  return (a>b);}

int find_left(int left, int right){
   int state = 0;
   int left_end=left;
   
   while(1){
      state = observe(left, right);
      if(state==2){
         if(right-left<=1)
            return right;
         left_end=left;
         left = (left+right)/2;
      }
      else if(state==1){
         if(right-left<=1)
            return left;
         right = left;
         left = (left_end+left)/2;
      }
   }
   return left;
}

int find_right(int left, int right){
   int state = 0;
   int right_end=right;
   
   while(1){
      state = observe(left, right);
      if(state==2){
         if(right-left<=1)
            return left;
         right_end=right;
         right = (left+right)/2;
      }
      else if(state==1){
         if(right-left<=1)
            return right;
         left = right;
         right = (right_end+left)/2;
      }
   }
   return right;
}

void oil_find(double i,double j,vector<double>& oil){
    int r = observe(floor((i+j)/2)+1,j);
    int l = observe(i,floor((i+j)/2));
    if(l==0&&r==0){
        ;
    }
    if(l==0 && r==1) {
        oil.push_back(floor((i+j)/2)+1);
        oil.push_back(j);
    }
        
    else if(l==0 && r==2){
        oil_find(floor((i+j)/2)+1,j,oil);
    }
    
    else if(l==1 && r==0){
        oil.push_back(i);
        oil.push_back(floor((i+j)/2));
    }
    else if(l==1 && r==1){
        oil.push_back(i);
        oil.push_back(j);
    }
    else if(l==1 && r==2){
        oil.push_back(i);   cout<<i<<'\n';
        oil_find(floor((i+j)/2)+1,j,oil);
    }
    else if(l==2 && r==0){
        oil_find(i,floor((i+j)/2),oil);
    }
    else if(l==2 && r==1){
        oil.push_back(j);
        int left=0; int right=0;
         oil_find(i,floor((i+j)/2),oil);
        }
    else if(l==2 && r==2){
        oil_find(i,floor((j+i)/2),oil);
        oil_find(floor((j+i)/2)+1,j,oil);
    }

    
}

int main(){
    vector<double> oil;
    double n,j,i=0;
    initial();
    n=oil_size();
    
    j=n-1;
    oil_find(i,j,oil);
    
    int k =oil.size();
    sort(oil.begin(),oil.end(),myfun);

    i = oil[k-1];
    j = oil[0];
    oil_report(i, j);
    return 0;

}

