//
//  main.cpp
//  ticket
//
//  Created by 박상은 on 2020/04/06.
//  Copyright © 2020 박상은. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

typedef struct{
    int first;  //연속된 일중 첫째날
    int last;   //연속된 일중 마지막
    int num;
    int ri_sum;
} ConSec_Days;

typedef struct{
    int di;
    int ri;
} INFO;
/*
program개요
1.(3일권을 쓸필요가없을때) 1일권을쓸지 1회권을 쓸지 정하여 최솟값을저장한다.
-가능한경우의수-
1일권,1회권,1일권2회,전부 1회권 //중에서 가장최소인값을 저장한다.
 -count할때마다 vector에 누적값이 push됨 vector 0번째 == 1일까지
 -vector 1번째 == 2일까지
 -vector 3번째 == 3일까지 최소값..
 
2.부분합중 3일권가격보다 큰요일ㅇ

3. 갱신되는 값을더한 누적합// 최종값을 나타내는 백터 vs 갱신할 여부확인하느 백터
 나눠서 생각
*/

//one day get sum
void get_sum(bool use,int s,int sum,int d,int count,int t,int* total_sum){
    if(count<3){
        if(use)    {*total_sum += sum*s;}
        else {*total_sum += d*count;}
    }
  
}


//최소단위의 최소값을 결정하는함수
void Use_day_pass(int s,int d,int t,int w,vector<INFO>& trem_table,vector<int>& sum,vector<int>& re){ //1회권가격, 1일권가격, 총 탄횟수*1회권가격
    int i=0; int count = 0; int temp=0;int day=0;
    sum.push_back(0); re.push_back(0);
    while( i < trem_table.size() ){
        ++day;
        if( trem_table[i].ri != 0 ){
            ++count;// 탑승일수를 count
            //하루권합 vs 일회권합 >> 최소값을갱신
            temp += trem_table[i].ri;   //temp -> 타는횟수를 저장
            bool use1 = ( temp*s > d*count );
            if( use1 ){
                
                sum.push_back( d*count );
                cout << i <<" min_changed by day1 "<< *(sum.end()-1) <<'\n';
            }
            else{

                sum.push_back( temp*s );
                cout << i << " min_changed by once "<< *(sum.end()-1)<<'\n';
            }
    
            //이전 최소값 vs 3일권 >> 최소값을 갱신
            if( *(sum.end()-1) > t ){
                //3일권가격이싸다면 최소값을 pop 3일권가격 push
                    sum.pop_back();
                    sum.push_back(t);
                int min_v = *(re.end()-1) + *(sum.end()-1);
                re.push_back(min_v);
                cout << i<<" min_changed by th days "<< *(re.end()-1)<<'\n';
            }
            else{
                int min_v = *(re.end()-1) + *(sum.end()-1);
                re.push_back(min_v);
                cout << i<<" min_unchange "<< *(re.end()-1)<<'\n';
            }
            
            //7일간 최소값 vs 7일권 >> 최소값을 갱신
           if( *(sum.end()-1) > w && i%7 == 0 ){
                sum.pop_back();
                sum.push_back(w);
                int min_v = *(re.end()-1) + *(sum.end()-1);
                re.push_back(min_v);
                cout <<i <<" min_changed by a week "<< *(re.end()-1) <<'\n';
            }
            
        }
       
        else{
            count = 0;
            int min_v = *(re.end()-1) + *(sum.end()-1);
            re.push_back(min_v);
           
            cout <<i <<" min_maintaine "<< *(re.end()-1) <<'\n';
            }
      // cout << *(sum.end()-1) << '\n';
        ++i;
    }
}

int main() {
    vector<INFO> trem_table;
    vector<ConSec_Days> sum_table;
    vector<int> sum, re;
    int N=0;    int i=0;
    int s,d,t,w,di,ri;
    //input data
    ifstream in("1.inp");
    in >> s >> d >> t >> w >> N >> di >> ri;
    for(i=0;i<N;++i){
        INFO temp;
        if(i == di){
        temp.di = di; temp.ri = ri;
        trem_table.push_back(temp);
        in >> di >> ri;
        }
        else {
        temp.di = i; temp.ri = 0;
        trem_table.push_back(temp);
        N++;
        }
        cout << i <<' '<<trem_table[i].ri<<'\n';
    }
    Use_day_pass(s,d,t,w,trem_table,sum,re);
    
    return 0;
}
