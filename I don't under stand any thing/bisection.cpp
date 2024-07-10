//concept || between
#include <iostream>
#include <cmath>
using namespace std;

double find_function(double x){
    double fxm = 4.00*x-1.00;
    return fxm;
}

int main(){
    double XL = -10.00;
    double XR = 5.00;
    double XM;
    double findError;
    double fnXR, fnXM;
    while(true){
        XM = (XL + XR) / 2.00;
        fnXM = find_function(XM);
        fnXR = find_function(XR);
        if(fnXM * fnXR > 0){
            XR = XM;
            findError = fabs((XR - XL));
            //cout<<findError<<endl;
        }else{
            XL = XM;
            findError = fabs((XL - XR));
            //cout<<findError<<endl;
        }if(findError < 0.000001){
            break;
        }
        else{
            cout<<"Error: "<<findError<<" f(xm): "<<fnXM<<" f(xr): "<<fnXR<<endl;
        }
        }cout<<XM;
}