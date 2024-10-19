#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

float fx(float x){
    return (4*pow(x,5))-(3*pow(x,4))+(pow(x,3))-(6*x)+2;
}

int main(){
    for(float i = 0;i < 10;i+=0.5){
        float n = fx(i);
        cout<<i<<" "<<n<<fixed<<setprecision(6)<<endl;
    }
}