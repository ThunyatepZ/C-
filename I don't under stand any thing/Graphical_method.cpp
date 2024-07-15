#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int x =0;
    double y;
    for(x = 0;x<=10;x++){
        double fx = exp(-x/4.0) * (2.0-x) - 1;
        if(fx >= 0){
            cout<<"F(x): "<<x<<" result: "<<fx<<endl;

            for(y=x; y<=2;y+=0.000001){
                double fx2 = exp(-y/4.0) * (2 - y) - 1;
                if (fx2 >= 0){
                    cout<<"F(x)2 : "<<y<<" result: "<<fx2<<endl;
                }
                else{break;}
                
            }
        }
        else{break;}
    }
}//I think isn't right;