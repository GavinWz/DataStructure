#include"../include/ds.h"

using namespace my::array_list;
/*  
    思想：
    因为两顺序表等长，记为n，所以中位数所在位置为两顺序表合并元素递增序列的第n个
    设置final[2]数组用于标记目标元素位置
    遍历n次，每次在两个表中按照升序顺序查找一个元素并标记位置，n次后标记处即为中位数
*/

// 时间复杂度：O(n)
// 空间复杂度：O(1)
int find_mid(ArrayList<int> list1, ArrayList<int> list2){
    int n = list1.length;
    int final[2] = {0, 0}; 
    /*  
        目标元素标记数组
        final[1] = 0标记为list1, final[1] = 1标记为list2
        final[0]标记目标元素为在list1或list2中的下标
    */
    int index1 = 0, index2 = 0;
    for(int i = 0; i < n; i++){
        if(list1.data[index1] < list2.data[index2]){
            final[0] = index1;
            final[1] = 0;
            index1++;
        }
        else{
            final[0] = index2;
            final[1] = 1;
            index2++;
        }
    }
    return final[1] ? list2.data[final[0]] : list1.data[final[0]];
}

int main(){
    ArrayList<int> list1, list2;
    int data1[] = {1,3,5,6,7};
    initArrayList(list1, data1, 5);
    int data2[] = {2,7,8,9,10};
    initArrayList(list2, data2, 5);
    cout << find_mid(list1, list2);
}