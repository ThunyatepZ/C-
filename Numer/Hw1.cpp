#include <iostream>
#include <cmath>
using namespace std;

double cal(double x){
    double ans = 43.00 * x - 180.00;
    return ans;
}

int main(){
    double x = 0;
    double y;
    double fx2;
    for(x = 0;x < 10;x++){
        double fx = cal(x);
        if(fx<0){
            cout<<fx<<endl;
            
        }
        else{
            for(y = x - 1;y<x;y+=0.000001){
                fx2 = cal(y);
                if(fx2 < 0){
                    cout<<y<<endl;
                }
            }
        }
    }

}