//
//  main.cpp
//  gapLCS
//
//  Created by 박상은 on 2020/04/18.
//  Copyright © 2020 박상은. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

typedef struct  {
    int i;
    int j;
}STUD;

typedef struct {
    vector<int> arr;
}B_vec;

int maximum(int a,int b,int c,int d){
    int temp1,temp2;
    if(a>b)
        temp1 = a;
    else
        temp1 = b;
    if(c>d)
        temp2 = c;
    else
        temp2 = d;
    return  max(temp1,temp2);
}

void back_tracking(vector<B_vec>& H,vector<STUD>& lcstrack, int nxt_i,int nxt_j){
    int diagonal=0; // H[ivalue-1].arr[jvalue-1]
    int left=0;   //H[ivalue-1].arr[jvalue]
    int up=0;     //H[ivalue].arr[jvalue]
    int max=0;    //maximum value
    int pre_i=0; int pre_j=0;
    pre_i = nxt_i;  //set pre_ij
    pre_j = nxt_j;
    
    up = H[pre_i-1].arr[pre_j];   //set next_ij
    left = H[pre_i].arr[pre_j-1];
    diagonal = H[pre_i-1].arr[pre_j-1];
    max = maximum(up,left,diagonal,0);
    
    if(max == diagonal){
          nxt_i = pre_i-1;
          nxt_j = pre_j-1;
    }
    else if(max == left){
        nxt_i = pre_i;
        nxt_j = pre_j-1;
        
    }
    else if(max == up){
        nxt_i = pre_i-1;
        nxt_j = pre_j;
    }
    STUD nxt_ij;
    nxt_ij.i = nxt_i;   nxt_ij.j = nxt_j;
    lcstrack.push_back(nxt_ij);
    
    if(nxt_i<=1|| nxt_j<=1) return;
    else back_tracking(H,lcstrack,nxt_i,nxt_j);
}

int main() {
    
    string A; string B;
    int s=3;
    int match_score=0;
    int A_gaped_score=0;
    int B_gaped_score=0;
    
    int k;
    int gap_penalty=2*k;
    
    //input
    ifstream in("1.inp");
    in >> A >> B;
    int m = A.size()+1; int n = B.size()+1;
    B_vec B_arr;
    vector<B_vec> H;
   
    
    //initiallize h_map : h(0,j)=0,h(i,0)=0
    for(int i=0; i<m ; i++){
        for(int j=0; j<n ;j++)
            B_arr.arr.push_back(0);
        H.push_back(B_arr);
    }

    
    //checking&scoring
    char b; int present;
    int pre_max_value = H[0].arr[0]; int max_i; int max_j; // 이전 최댓값저장
    for(int i=1;i<m;i++){
        char a = A[i-1];
        for(int j=1;j<n;j++){   // counting score
            b = B[j-1];
            if(a==b)
            {
                match_score = s;    // a==b : 3
                k=0;
            }
            else
            {
                match_score = -s;   // a!=b : -3
                k++;
            }

            present = H[i-1].arr[j-1]+match_score;
            A_gaped_score = H[i].arr[j-1]-gap_penalty;  // A_gaped_penaltied point : H[i][j-1]-gap_penalty
            B_gaped_score = H[i-1].arr[j]-gap_penalty;  // B_gaped_penaltied point : H[i][j-1]-gap_penalty
            
            //choose maximum value and put into H[i][j]
            H[i].arr[j] = maximum(present,A_gaped_score,B_gaped_score,0);
            if(H[i].arr[j]>pre_max_value){
                pre_max_value = H[i].arr[j];
                max_i = i;
                max_j = j;
            }
        }
    }
    
    //back tracking//
   
    //get mth line highest value
    int high=0;  int nj=0;
    for(int j = 0;j<n;j++){
        if(H[m-1].arr[j]>high){
            high =H[m-1].arr[j];
            nj = j;
        }
    }
   // cout <<"nj : "<<nj<<'\n';
    
   //tracking from high
    vector<STUD> lcstrack;
    STUD nxt_ij;
    nxt_ij.i = m-1;
    nxt_ij.j = nj;
    lcstrack.push_back(nxt_ij);
    
    back_tracking(H,lcstrack, m-1,nj);
    
    for(int k=0;k<lcstrack.size();k++){
        cout <<H[lcstrack[k].i].arr[lcstrack[k].j]<<'\n';
        cout << "___"<<k<<' '<<lcstrack[k].i<<"___"<<lcstrack[k].j<<'\n';
    }
    
    //print map
       cout <<"    ";
       for(int j=0;j<n;j++)
           cout <<B[j]<<' ';
       cout <<'\n'<<"  ";
    for(int j=0;j<n;j++){
        cout << H[0].arr[j]<<' ';
    }
    cout <<'\n'<<A[0]<<' ';
         for(int i=1; i<m; i++){
             for(int j=0;j<n;j++)
                 cout <<H[i].arr[j]<<' ';
             cout <<'\n'<<A[i]<<' ';
         }

        
    
    
    return 0;
}
