#include"../include/ds.h"

using namespace my::array_list;


/* 思想：
    根据现有顺序表长度开辟一个等长数组作为桶，
    遍历原顺序表，将除了值为负数和值大于顺序表长度的值（因为这些值不可能是所求的最小正整数）之外的所有元素存入数组，
    原则为：将值为x的顺序表元素的值放入数组的第x个位置。
    完成后遍历新数组，若某位置处下标值不等于元素值，则此下标即为所求
*/

// 时间复杂度：O(n)
// 空间复杂度：O(n)

int find_miss_min(ArrayList<int> list){
    int* temp = new int[list.length+1];
    int index = 0;
    int i;
    for(i = 0; i < list.length; i++){
        if(list.data[i] > list.length || list.data[i] <= 0){
            continue;
        }
        temp[list.data[i]] = list.data[i];
    }
    for(i = 1; i <= list.length; i++){
        if(temp[i] != i){
            break;
        }
    }
    return i;
}


int main(){
    ArrayList<int> list;
    int data[] = {2,4,5,6,7};
    initArrayList(list, data, 5);
    cout << find_miss_min(list);
    // outputArrayList(list);
}