#include <iostream>
#include <cmath>
using namespace std;

double cal(double x,double n,double xm){
    double fxm = pow(xm,n)-x;
    return fxm;
}

int main(){
    double n,x;
    double XL,XR,X1 = 0,X1OLED;
    double FXL,FXR,FX1;
    double Error;
    cout<<"Input x: ";
    cin>>x;
    cout<<"Input n: ";
    cin>>n;
    cout<<"Input XL: ";
    cin>>XL;
    cout<<"Input XR: ";
    cin>>XR;
    while(true){
        X1OLED = X1;
        X1 = ((XL * FXR) - (XR * FXL)) / (FXR - FXL);
        FX1 = cal(x,n,X1);
        FXR = cal(x,n,XR);
        FXL = cal(x,n,XL);
        if(FX1 * FXR > 0){
            XR = X1;
            Error = fabs(XR - X1OLED);
        }
        else{
            XL = X1;
            Error = fabs(XL - X1OLED);
        }
        if(Error < 0.000001){
            break;
        }
        else{
            cout<<"Error: "<<Error<<"F(xl): "<< FXL << "F(xm): "<<FX1<<"F(xr): "<< FXR<<endl;
        }
    }cout<<X1;
}