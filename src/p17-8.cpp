#include"../include/ds.h"

using namespace my::array_list;

void reverse(ArrayList<int>&list, int front, int tail){
    int temp;
    while(front < tail){
        temp = list.data[front];
        list.data[front] = list.data[tail];
        list.data[tail] = temp;
        front++, tail--;
    }
}

//思想：先分别将两个子表就地逆置，再将整体就地逆置即可
void swap(ArrayList<int>& list, int m, int n){
    reverse(list, 0, m - 1);
    reverse(list, m, m + n - 1);
    reverse(list, 0, m + n - 1);
}

int main(){
    ArrayList<int> list;
    int data[] = {1,2,3,4,5,6,7};
    initArrayList(list, data, 7);
    swap(list, 5, 2);
    outputArrayList(list);
}