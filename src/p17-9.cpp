#include"../include/ds.h"

using namespace my::array_list;

//思想：二分查找，查找成功则与后继元素加交换，查找失败则在左指针处插入X
void find(ArrayList<int>& list, int x){
    int high= 0, low = list.length - 1, tag = 0;
    int mid;
    while(high<= low){
        mid = (high+ low) / 2;
        if(list.data[mid] == x){  //查找成功
            int temp = list.data[mid];
            list.data[mid] = list.data[mid+1];
            list.data[mid+1] = temp;
            tag = 1;  //标记查找成功
            break;
        }
        else if(list.data[mid] < x){
            high= mid + 1;   
        }
        else{
            low = mid - 1;
        }
    }
    if(!tag){  //查找失败
        for(int k = list.length; k > high; k--){
            list.data[k] = list.data[k-1];
        }
        list.data[high] = x;
        list.length++;
    }
}

int main(){
    ArrayList<int> list;
    int data[] = {1,2,3,5,6,7,8,9};
    initArrayList(list, data, 8);
    find(list, 4);
    outputArrayList(list);
}