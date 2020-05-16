//
//  main.cpp
//  tube
//
//  Created by 박상은 on 2020/05/04.
//  Copyright © 2020 박상은. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int get_maximum_remain(int TUBE,int* pipe,int N){
    int maximum = 10000;
    for(int i=0;i<N;i++){
        maximum = min(TUBE%pipe[i],maximum);
    }
    return maximum;
}

int find_element(int TUBE,int* pipe,int N) {
    int maximum = 0;
    maximum = get_maximum_remain(TUBE, pipe,N);
    int i=0;
    for(i = 0; i<N;i++){
        if(TUBE%i == maximum)
            return i;
        else;
    }
    return i;
}

int remain(int TUBE,int* pipe,int N){
    int count = 0;
    int element = find_element(TUBE, pipe,N);
    while(TUBE - element >= 0){
        element = get_maximum_remain(TUBE, pipe,N);
        ++count;
    }
    if(TUBE!=0){
        count = 0;
    }
    else{
        count = count;
    }
    return count;
}

int main() {
   
    //input
    ifstream in("2.inp");
    int TUBE=0;
    int N=0;
    int count=0;
    int temp=0;
    in >> TUBE >> N;
    int pipe[N];
    for(int i= 0; i<N ; i++){
        in >>temp;
        pipe[i] = temp;
    }
    
    //find
    count = remain(TUBE,pipe,N);
    
    //output
    ofstream out("1t.out");
    cout << count;
    
    return 0;
}
