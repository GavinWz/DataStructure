#include"../include/ds.h"

using namespace my::array_list;

ArrayList<int> merge(ArrayList<int> list1, ArrayList<int> list2){
    ArrayList<int> list;
    int index = 0;
    for(int i = 0; i < list1.length; i++){
        list.data[index++] = list1.data[i];
    }
    for(int i = 0; i < list2.length; i++){
        list.data[index++] = list2.data[i];
    }
    list.length = index;
    return list;
}

int main(){
    ArrayList<int> list1;
    int data1[] = {1,2,3,4,5,6,7};
    initArrayList(list1, data1, 7);
    ArrayList<int> list2;
    int data2[] = {1,2,3,4,5,6,7};
    initArrayList(list2, data2, 7);
    outputArrayList(merge(list1, list2));
}