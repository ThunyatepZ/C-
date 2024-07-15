#include <iostream>
#include <cmath>
using namespace std;

double cal(double x){
    return 43.00 * x - 180.00;
}

int main(){
    double x;
    double y;
    for(x = 0;x < 10;x++){
        double fx = cal(x);
        if(fx<0){
            cout<<fx<<endl;
        }else if(fx > 0){
            for(y = x;y<10;y-=0.001){
                double fx2 = cal(y);
                if(fx2 >= 0){
                    cout<<y<<endl;
                }
                else{
                    break;
                }
            }
        }

    }

}