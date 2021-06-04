#include "../include/ds.h"
#include<stdlib.h>
using namespace my::shared_stack;


int main(){
    SharedStack stack;
    init(stack);
    push(stack,2,2);
    push(stack,3,1);
    push(stack,4,1);
    // clear(stack);
    
    push(stack, 4,1);
    // cout << get_top(stack);
    // cout << get_top(stack);
    cout << pop(stack,2);
    cout << pop(stack,2);
    cout << pop(stack,2);
    cout << pop(stack,2);
    cout << pop(stack,2);
    // cout << pop(stack);
    // cout << pop(stack);
    // cout << pop(stack);


}