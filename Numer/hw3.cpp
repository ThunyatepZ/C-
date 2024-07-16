#include <iostream>
#include <cmath>
using namespace std;

double cal(double x,double n,double xm){
    double fxm = pow(xm,n)-x;
    return fxm;
}

int main(){
    double n,x;
    double XL,XR,XM,XMO;
    double FXL,FXR,FXM;
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
        XMO = XM;
        XM = (XL + XR) / 2.00;
        FXM = cal(x,n,XM);
        FXR = cal(x,n,XR);
        if(FXM * FXR > 0){
            XR = XM;
            Error = fabs((XR - XMO));
        }
        else{
            XL = XM;
            Error = fabs((XL - XMO));
        }
        if(Error < 0.000001){
            break;
        }
        else{
            cout<<"Error"<<Error<<"F(xl): "<< FXL << "F(xm): "<<FXM<<"F(xr): "<< FXR<<endl;
        }
    }cout<<XM;
}