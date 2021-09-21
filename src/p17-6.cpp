#include"../include/ds.h"

using namespace my::array_list;

bool del(ArrayList<int>& list){
    if(list.length == 0){
        cout << "error" << endl;
        return false;
    }
    int current = list.data[0]; //存储当前遍历的值
    int valid_index = 1; //存储有效数据下标
    for(int i = 1; i < list.length; i++){
        while(list.data[i] == current){
            i++;  //i++等价于忽略此条数据。因为数组有序，所以只要与current相等的数据均为无效数据。
        }
        current = list.data[i];
        list.data[valid_index++] = current;
    }
    list.length = valid_index;
    return true;
}

int main(){
    ArrayList<int> list;
    int data[] = {1,2,4,4,6,6,7};
    initArrayList(list, data, 7);
    del(list);
    outputArrayList(list);
}