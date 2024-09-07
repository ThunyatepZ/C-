#include <iostream>
#include <cmath>
#include<iomanip>
using namespace std;

double calculate(double xleg){
    return (sqrt(7) + xleg) / 2;
}
int main(){
    //cout<<setprecision(6)<<fixed;
    int roundcheck = 1;
    double x = 0 ;
    double xold = 0;
    //double e;
    double error;
    do
    {
        xold = x;
        x = calculate(x);
        error = fabs((x - xold));
        
        cout<<"Round "<< roundcheck<<" y = "<< x << " x = " << xold<<" Error"<< error<<endl;
        roundcheck++;
        
        if(isinf(x)){
            return 0;
        }
        
    }while(error>=0.000001);
}