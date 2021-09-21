#include"../include/ds.h"

using namespace my::array_list;

// 思想：
// 1.先将前p个数据拷贝至顺序表末尾
// 2.再将后n-p个数据向左平移p位
// 3.最后将末尾的p个数据向前平移p位
// 时间复杂度：O(n)
// 空间复杂度：O(1)

// 法二：
// 可将此题看作将数组从p分为前后两数组
// 然后交换这两个数组的位置，实现算法类似于p17-8
void move(ArrayList<int>& list, int p){
    int j, n;
    j = n = list.length;
    for(int i = 0; i < p; i++, j++){
        list.data[j] = list.data[i];
        list.data[i] = list.data[p+i];
    }
    for(int i = n - p; i < n; i++){
        list.data[i] = list.data[p + i];
    }
}

int main(){
    ArrayList<int> list;
    int data[] = {1,2,3,4,5,6,7};
    initArrayList(list, data, 7);
    move(list, 5);
    outputArrayList(list);
}