//concept || between //It's the first solution || i have i left// x = root 4 of 13
//Bisection
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
    double XM = 0,XMO;
    double findError;
    double fnXR, fnXM;
    while(true){
        XMO = XM;
        XM = (XL + XR) / 2.00;
        fnXM = find_function(XM);
        fnXR = find_function(XR);
        if(fnXM * fnXR > 0){
            XR = XM;
            findError = fabs((XR - XMO));
            //cout<<findError<<endl;
        }else{
            XL = XM;
            findError = fabs((XL - XMO));
            //cout<<findError<<endl;
        }if(findError < 0.000001){
            break;
        }
        else{
            cout<<"Error: "<<findError<<" f(xm): "<<fnXM<<" f(xr): "<<fnXR<<endl;
        }
        }cout<<XM;
}