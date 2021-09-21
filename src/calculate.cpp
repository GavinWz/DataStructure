#include "../include/ds.h"
#include<map>

typedef link_stack::LinkStack stack;

using namespace my;

stack num_stack, op_stack;
map<char, int> isp;  //栈内优先级表
map<char, int> icp;  //栈外优先级表

void init(){
    link_stack::init(num_stack);
    link_stack::init(op_stack);

    isp['#'] = 0;
    isp['('] = 1;
    isp['*'] = 5;
    isp['/'] = 5;
    isp['+'] = 3;
    isp['-'] = 3;
    isp[')'] = 6;

    icp['#'] = 0;
    icp['('] = 6;
    icp['*'] = 4;
    icp['/'] = 4;
    icp['+'] = 2;
    icp['-'] = 2;
    icp[')'] = 1;
}

int calculate(string s){
    for(char ch: s){
        if(!isp[ch]){
            cout << "表达式中包含非法字符: " << ch << endl; 
            return INT_MAX;
        }
    }
}

int main(){
    init();
    if(isp['&']){
        cout << "(";
    }
}
