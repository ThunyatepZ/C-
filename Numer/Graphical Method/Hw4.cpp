//concept || between //It's the first solution || i have i left// x = root 4 of 13
//Falseposition
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double find_function(double Xm){
    double fxm = pow(Xm,4)-13;
    return fxm;
}

int main(){
    cout<<fixed<<setprecision(6);
    double XL = 1.50;
    double XR = 2.00;
    double x1O;
    double X1 = 0;
    double findError;
    double fnXR, fnXL,fnX1;
    while(true){
        x1O = X1;
        fnXL = find_function(XL);
        fnXR = find_function(XR);
        fnX1 = find_function(X1);
        X1 = ((XL * fnXR) - (XR * fnXL)) / (fnXR - fnXL);
        
        if(fnX1 * fnXR > 0){
            XR = X1;
            findError = fabs(XR - x1O);
            //cout<<findError<<endl;
        }else{
            XL = X1;
            findError = fabs(XL - x1O);
            //cout<<findError<<endl;
        }if(findError < 0.000001){
            break;
        }
        else{
            cout<<"Error: "<<findError<<" f(x1): "<<fnX1<<" f(xr): "<<fnXR<<endl;
        }
        }cout<<X1;
}