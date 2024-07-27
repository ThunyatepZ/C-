//root7 change to X^2 - 7
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double Newton(double x,double fx,double fdx){
    return x - (fx / fdx);
}

double findFx(double x){
    double y;
    y = pow(x,2) - 7;
    return y;
}

double fdiffX(double x){
    return 2 * x;
}

int main(){
    cout<<setprecision(6)<<fixed;
    double x = 2.00,xold;
    double Error =1 ;
    double fx,fdx;
    do
    {
        xold = x;
        fx = findFx(x);
        fdx = fdiffX(x);
        x = Newton(x,fx,fdx);
        
        cout<<x<<endl;
        Error = fabs(x - xold);
    } while (Error > 0.000001);
    
}