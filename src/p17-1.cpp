#include "../include/ds.h"

using namespace my::arrayList;

int func(ArrayList<int> &list){
    int min_index = 0;
    if(list.length == 0){
        cout << "错误信息" << endl;
        exit;
    }
    for(int i = 1; i < list.length; i++){
        if(list.data[min_index] > list.data[i]){
            min_index = i;
        }
    }
    cout << list.data[min_index] << endl;
    delIdxArraylist(list, min_index);
    list.length++; //题目要求空出的位置用最后一个元素填补

    return list.data[min_index];
}

int main(){
    ArrayList<int> list;
    initIntList(list);
    
    outputArrayList(list);
    func(list);
    outputArrayList(list);

    return 0;
}