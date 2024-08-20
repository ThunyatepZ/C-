#include <iostream>
using namespace std;
int main(){
    float arr[3][3] = {{4,5,3},{7,2,5},{3,4,2}};
    
    
    float sum1 = arr[0][0] / 4;
    float sum2 = arr[0][1] / 4;
    float sum3 = arr[0][2] / 4;
    sum1 = sum1 * arr[1][0];
    sum2 = sum2 * arr[1][0];
    sum3 = sum3 * arr[1][0];
    //cout<<sum1<<" "<<sum2<<" "<<sum3;
    arr[1][0] = arr[1][0] - sum1;
    arr[1][1] = arr[1][1] - sum2;
    arr[1][2] = arr[1][2] - sum3;

    for(int i = 0;i < 3;i++){
        for(int j = 0;j< 3;j++){
            cout<<arr[i][j]<<" ";
        }cout<<endl;//
    }
}

