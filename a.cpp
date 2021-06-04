#include<iostream>
using namespace std;
void f(int a[]){
    cout << a[0];
}
int main(){
    int a[5] = {1,2,3,4};
    f(a);
}