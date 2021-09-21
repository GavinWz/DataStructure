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

// 错解
// void del(ArrayList<int>& list, int x){
//     int temp, j = list.length - 1;
//     for(int i = 0; i < list.length; i++){
//         if(list.data[i] == x){
//             temp = list.data[i];
//             list.data[i] = list.data[j];
//             list.data[j] = temp;
//             list.length--;
//         }
//     }
// }

// 思想：在顺序表的基础上，将值不为x的元素从头到尾排列，重新设置数组长度
void del(ArrayList<int>& list, int x){
    int non_x_num = 0;
    for(int i = 0; i < list.length; i++){
        if(list.data[i] != x){
            list.data[non_x_num] = list.data[i];
            non_x_num++;
        }
    }   
    list.length = non_x_num;
}