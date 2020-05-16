/*
 학번 201645615
 이름 박상은
 projectname : mgame
 */
#include <algorithm>
#include <string>
#include <fstream>
#include <iostream>


using namespace std;

int max_v[30][30];
int min_v[30][30];

int atoi(char i){
    int a = i-48;
    return a;
}

int solution(string arr)
{
    int answer = 1;
    int number = arr.size() / 2 + 1;
    for(int i = 0; i<30 ; i++){
        for(int j = 0; j<30 ; j++){
            max_v[i][j] = -100000;
            min_v[i][j] = 100000;
        }
    }

    for (int i = 0; i < number; i++) {
        max_v[i][i] = atoi(arr[i * 2]);
        min_v[i][i] = atoi(arr[i * 2]);
    }

    for (int calc = 1; calc < number; calc++) {
        for (int i = 0; i < number - calc; i++) {
            int j = calc + i;
            for (int k = i; k < j; k++) {
                
                if (arr[k * 2 + 1] == '+') {
                    max_v[i][j] = max(max_v[i][k] + max_v[k + 1][j], max_v[i][j]);
                    min_v[i][j] = min(min_v[i][k] + min_v[k + 1][j], min_v[i][j]);
                }
                else if (arr[k * 2 + 1] == '-') {
                    max_v[i][j] = max(max_v[i][k] - min_v[k + 1][j], max_v[i][j]);
                    min_v[i][j] = min(min_v[i][k] - max_v[k + 1][j], min_v[i][j]);
                }
                else if (arr[k * 2 + 1] == '*') {
                    max_v[i][j] = max(max_v[i][j],max(max_v[i][k] * max_v[k + 1][j], min_v[i][k] * min_v[k + 1][j]));
                    min_v[i][j] = min(min_v[i][j],min(min_v[i][k] * max_v[k + 1][j], max_v[i][k] * min_v[k + 1][j]));
                }
            }
        }

    }
    answer = max_v[0][number - 1];
    return answer;
}

int main(){
    
   // input
    string arr;
    ifstream in("mgame.inp");
    in >> arr;
    
   //calculate answer
    int n= solution(arr);
    
    //output
    ofstream out("mgame.out");
    out <<n;
    
}
