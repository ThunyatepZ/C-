#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double fx(double x){
    return pow(x,2) - 7;
}
double diff(double x){
    return 2*x;
}

int main(){
    cout<<setprecision(6)<<fixed;
    double x = 2,x1,xold;
    double fx1,fx2;
    double Error;
    int i = 1;
    do
    {
        xold = x;
        fx1 = fx(x);
        fx2 = diff(x);
        x = x - (fx1 / fx2);
        Error = fabs(x - xold);
        cout<<"Iteration = "<<i<<" x = "<<x<<" Error"<<Error<<endl;
        i++;
    } while (Error >= 0.000001);
    
}