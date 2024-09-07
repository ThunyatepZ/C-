#include <iostream>
#include <cmath>
using namespace std;

double fx(double x){
    return pow(x,2) - 7;
}

int main(){
    double x = 2,x1 = 5,xnew;
    double fxnew,fxold;
    double Error;
    int i = 0;
    int xround = 2;
    do
    {
        fxold = fx(x);
        fxnew = fx(x1);
        xnew = x1 - ((fxnew * (x - x1)) / (fxold - fxnew));
        Error = fabs((xnew - x1) / xnew) * 100;
        cout<<"Iteration :"<< i <<" x"<<xround<<" = "<<xnew<<"Error"<< Error<<endl;
        i++;
        xround++;
        x = x1;
        x1 = xnew;
    } while (Error >= 0.000001);
    
}