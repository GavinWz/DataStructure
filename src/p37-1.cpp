#include"../include/ds.h"

using namespace my::link_list;

int main(){
    LinkList head;
    init_tail_insert(head);
    output(head);
    // LinkListNode* node = get_node_by_num(head, 3);
    // cout << node->value;
    // insert_at_num(head, 2, 99);
    del_at_num(head, 2);
    output(head);
}