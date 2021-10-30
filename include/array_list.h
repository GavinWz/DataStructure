#include"ds.h"
namespace array_list{
    //顺序表
    template<class T>
    struct ArrayList
    {
        T data[MaxSize];
        int length;
    };
    
    //Functions

    /*顺序表*/

    //初始化
    template<class T>
    int initArrayList(ArrayList<T> &list, T data[], int length){
        if(length > MaxSize){
            return 1;
        }
        for(int i = 0; i < length; i++){
            list.data[i] = data[i];
        }
        list.length = length;
        return 0;   
    }

    //创建int型顺序表
    void initIntList(ArrayList<int> &list){
        int data[MaxSize] = {1,2,0,7,4,8};
        initArrayList<int>(list, data, 6);
    }

    //输出
    void outputArrayList(ArrayList<int> list){
        for(int i = 0; i < list.length; i++){
            cout << list.data[i];
            if(i != list.length-1){
                cout << ",";
            }
        }
        cout << endl;
    }   

    //插入
    template<class T>
    int insertArrayList(ArrayList<T> &list,T value, int index){
        int i;
        if(list.length >= MaxSize){
            return 1;
        }
        for(i = list.length; i > index; i--){
            list.data[i] = list[i-1];
        }
        list.data[i] = value;
        list.length++;
        return 0;
    }

    //删除
    template<class T>
    int delIdxArraylist(ArrayList<T> &list, int index){
        for(int i = index; i < list.length - 1; i++){
            list.data[i] = list.data[i + 1];
        }
        list.length--;
        return 0;
    }
}