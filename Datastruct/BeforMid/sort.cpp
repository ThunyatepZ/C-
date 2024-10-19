#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int array[] = {1,5,2,6,8,4,11};
    int s = size(array);
    sort(array,array+s);
    for(int i = 0;i < size(array);i++){
        cout<<array[i]<<" ";
    }
}