#include "../include/ds.h"

using namespace my::dual_link;

void SelectSort(DualLink head){
  DualLink p = head->next;
  DualLink q, temp;
  int min;
  while(p){
    min = p->value;
    temp = p;
    q = p->next;
    while(q){
      if(q->value < min){
        min = q->value;
        temp = q;
      }
      q = q->next;
    }
    temp->front->next = temp->next;
    if(temp->next)
        temp->next->front = temp->front;
    p->front->next = temp;
    temp->next = p;
    temp->front = p->front;
  }
}

int main(){
    DualLink head;
    init_head_insert(head);
    SelectSort(head);
    output(head);
}
