#include <iostream>
using namespace std;

int main(){
    double Matrix[3][3] = {
                    {4,1,2},
                    {-1,-1,5},
                    {1,2,6}
};
int j = 0;
int sum = 1;
    for(int i = 0;i<3;i++){
        sum = sum * Matrix[i][i];
    }
    // int keep = Matrix[j][j] * Matrix[j+1][j+1] * Matrix[j+2][j+2] - Matrix[j+2][j] * Matrix[j+1][j+1] * Matrix[j][j+2];
    cout<<sum;

}






