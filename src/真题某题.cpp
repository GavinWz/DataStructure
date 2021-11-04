#include "../include/ds.h"

using namespace my::link_list;

void Create(LinkList l1, LinkList &l2){
    int sum = 0;
    LinkList temp = l1;
    while (temp){  //遍历求和
        sum += temp->value;
        temp = temp->next;
    }
    temp = l1;
    int sub_sum = 0;  //前部和
    while (temp){
        LinkList new_node = new LinkListNode;
        LinkList tail;
        new_node->value = sum - sub_sum; //后部和
        new_node->next = NULL;
        if (temp == l1){  //尾插法
            l2 = new_node;
            tail = l2;
        }
        else{
            tail->next = new_node;
            tail = tail->next;
        }
        sub_sum += temp->value;  //更新下一个元素的前部和
        temp = temp->next;
    }
}

int main(){
    LinkList l1, l2;
    init_head_insert(l1);
    l1->value = 1;
    Create(l1, l2);
    cout << l2->value << ", ";
    output(l2);
}
