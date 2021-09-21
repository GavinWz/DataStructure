#include"../include/ds.h"

using namespace my::array_list;

bool del(ArrayList<int>& list, int s, int t){
    if(s >= t || list.length == 0){
        cout << "Error" << endl;
        return false;
    }
    if(list.data[0] > t || list.data[list.length - 1] < s)
    {
        cout << "There is not any number in the range of (s, t)." << endl;
        return false;
    }
    int valid_index = 0;  //有效数据下标
    for(int i = 0; i < list.length; i++){  //将遍历到的有效数据重新排列
        
        if(list.data[i] > s){  
            while(list.data[i] < t)
                i++;  //i++等价于忽略此条数据。因为原顺序表有序，所以遍历到下界之后，直到遍历到上界之前的所有元素均无效
        }
        list.data[valid_index] = list.data[i]; 
        valid_index++;
    }
    list.length = valid_index;
    return true;
}

int main(){
    ArrayList<int> list;
    int data[] = {1,2,3,4,5,6,7};
    initArrayList(list, data, 7);
    del(list, -1, 0);
    outputArrayList(list);
}