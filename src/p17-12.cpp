#include"../include/ds.h"

using namespace my::array_list;


/* 思想
    对顺序表进行遍历，顺序表长度为length, 当遍历至下标为(length+1)/2时，
    未遍历的元素已经不足length/2，所以遍历到此之前未找到主元素就代表本顺序表无主元素。
    所以遍历(length+1)/2遍，每次搜索整个表，统计元素重复次数，若大于length/2，则返回
    若循环正常退出，则无主元素，返回-1
*/

// 时间复杂度：O(n^2)
// 空间复杂度：O(1)
int main_item(ArrayList<int> list){
    int cnt;
    for(int i = 0; i < (list.length + 1) / 2; i++){  //只需遍历一半儿
        cnt = 0;
        for(int j = 0; j < list.length; j++){  // 统计重复次数
            if(list.data[i] == list.data[j]){
                cnt++;
                if(cnt > list.length / 2){ // 找出直接返回
                    return list.data[i];
                }
            }
        }
    }
    return -1;
}

int main(){
    ArrayList<int> list;
    int data[] = {1,3,3,3,3,6,7};
    initArrayList(list, data, 7);
    cout << main_item(list);
    // outputArrayList(list);
}