#include"../include/ds.h"

using namespace my::array_list;

void del(ArrayList<int>& list, int x);

int main(){
    ArrayList<int> list;
    int data[] = {1,2,3,4,5,6,7};
    initArrayList(list, data, 7);
    del(list, 5);
    outputArrayList(list);
}