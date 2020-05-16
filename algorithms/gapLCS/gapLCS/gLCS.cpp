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

int main() {
    
    string A; string B;
    int s=3;
    int match_score=0;
    int A_gaped_score=0;
    int B_gaped_score=0;
    
    int k;
    int gap_penalty=2*k;
    
    //input
    ifstream in("gLCS.inp");
    in >> A >> B;
    int m = A.size()+1; int n = B.size()+1;
    int H[m][n];
    cout <<m <<','<<n<<'\n';
    //initiallize h_map : h(0,j)=0,h(i,0)=0
    for(int i=0; i<m ; i++){
        for(int j=0; j<n ;j++)
            H[i][j]=0;
    }

    
    //checking&scoring
    char b; int present;
    int pre_max_value = H[0][0]; int max_i; int max_j; // 이전 최댓값저장
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
            present = H[i-1][j-1]+match_score;
            A_gaped_score = H[i][j-1]-gap_penalty;  // A_gaped_penaltied point : H[i][j-1]-gap_penalty
            B_gaped_score = H[i-1][j]-gap_penalty;  // B_gaped_penaltied point : H[i][j-1]-gap_penalty
            
            //choose maximum value and put into H[i][j]
            H[i][j] = maximum(present,A_gaped_score,B_gaped_score,0);
            if(H[i][j]>pre_max_value){
                pre_max_value = H[i][j];
                max_i = i;
                max_j = j;
            }
        }
    }
    
    //back tracking
    pre_max_value=H[m-1][n-1];
    int temp_i;int temp_j;
    STUD index; int nj= n-1;
    vector<STUD> track;
    index.i = 0; index.j= 0;
    track.push_back(index);

    for(int i=m-1;i>0;i--){
        for(int j=nj;j>0;j--){
            if(H[i][j]>pre_max_value){
                temp_i = i;
                temp_j = j;
                pre_max_value = H[i][j];
            }
        }
        pre_max_value=0;
        cout << H[temp_i][temp_j]<<',';
        index.i = temp_i; index.j = temp_j;
        track.push_back(index);
        nj = temp_j;
    }
    cout <<'\n';
    
    //print map
       cout <<"    ";
       for(int j=0;j<n;j++)
           cout <<B[j]<<' ';
       cout <<'\n';
         for(int i=0; i<m; i++){
            cout<<A[i]<<' ';
             for(int j=0;j<n;j++)
                 cout <<H[i][j]<<' ';
             cout <<'\n';
         }

    int nxt_j = track[1].j-1;
    int count=0;
    //align string
     string gap_LCS;
    for(int k = 1;k<track.size();k++){
        nxt_j = track[k+1].j-1;
   
        if(track[k].j-1-nxt_j>0){
            cout <<"--" <<B[track[k].j-1] <<' ';
            gap_LCS.push_back(B[track[k].j-1] );
       }
    }

    ofstream out("gLCS.out");
    for(int i=gap_LCS.size()-1;i>=0;i--)
    out<< gap_LCS[i];
   
    return 0;
}
