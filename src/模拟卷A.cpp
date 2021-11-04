#include"../include/ds.h"

using namespace std;
using namespace my::link_list;

void Del(LinkList &head){
    LinkList p = head->next;
    LinkList q, q_front;
    if(!p->next)
        return;
    while(p){
        q_front = p;
        q = q_front->next;
        int base = p->value;
        while(q){
            if(base == q->value){
                LinkList temp = q;
                q_front->next = temp->next;
                q = q_front->next;
                free(temp);
            }
            else{
                q_front = q;
                q = q->next;
            }
        }
        p = p->next;
    }
}

int main(){
    LinkList head;
    init_head_insert(head);
    output(head);
    Del(head);
    output(head);
}