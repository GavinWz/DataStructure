#include "../include/ds.h"
#include<stdlib.h>
using namespace my::link_queue;


int main(){
    LinkQueue queue;
    init(queue);
    enter(queue, 2);
    enter(queue, 3);
    clear(queue);
    cout << my::link_queue::is_empty(queue);

}