#include "ds.h"

class LinkListNode{
public:
    int data;
    LinkListNode *next;
    
};

class LinkList{
private:
    LinkListNode* head;
    LinkListNode* tail;

public:
    LinkList(){
        head = new LinkListNode;
        tail = new LinkListNode;
        head->next = NULL;
        tail = head;
    }
    
    //头插法初始化
    void init_head_insert(){
        int data;
        cout << "输入数据，以回车分割，输入9999结束" << endl;
        while(cin >> data && data != 9999){
            LinkListNode* new_node = new LinkListNode;
            new_node->data = data;
            new_node->next = head->next;
            head->next = new_node;
        }
    }

    //尾插法初始化
    void init_tail_insert(){
        int data;
        cout << "输入数据，以回车分割，输入9999结束" << endl;
        while(cin >> data && data != 9999){
            LinkListNode* new_node = new LinkListNode;
            new_node->data = data;
            new_node->next = NULL;
            tail->next = new_node;
            tail = tail->next;
        }
    }

    //输出
    void output(){
        if(head->next == NULL){
            cout << "链表为空" << endl;
            return;
        }
        LinkListNode* q = head->next;
        if(q != NULL){
            cout << q->data;
            q = q->next;
        }
        while(q != NULL){
            cout << ", " << q->data; 
            q = q->next;
        }
        cout << endl;
    }

    //查找：找到下标为index的数据
    LinkListNode* get_node_by_index(int index){  
        if(head->next == NULL){
            cout << "链表为空" << endl;
            return NULL;
        }
            
        LinkListNode* p = head->next;
        int i;
        for(i = 0; i < index && p->next != NULL; i++){
            p = p->next;
        }
        if(i != index){
            cout << "所给下标过大" << endl;
            return NULL;
        }
        return p;
    }

    //查找：找到第num个数据
    LinkListNode* get_node_by_num(int num){
        return (get_node_by_index(num-1));
    }

    //查找：找到值为index的第一条数据
    LinkListNode* get_node_by_data(int data){
        if(head->next == NULL){
            cout << "链表为空" << endl;
            return NULL;
        }
        LinkListNode* p = head->next;
        while(p->next != NULL && p->data != data){
            p = p->next;
        }
        if(p->data == data)
            return p;
        cout << "没找到" << endl;
        return NULL;
    }

    //插入：在下标为index的节点后插入元素
    bool insert_at_index(int index, int data){
        LinkListNode* p = head->next;
        int i = 0;
        while(i < index && p->next != NULL){
            p = p->next;
            i++;
        }
        if(i != index){
            cout << "输入下标过大" << endl;
            return false;
        }
        LinkListNode* temp = new LinkListNode;
        temp->data = data;
        temp->next = p->next;
        p->next = temp;
        return true;
    }

    //插入：在第num个节点后插入元素
    bool insert_at_num(int num, int data){
        return insert_at_index(num - 1, data);
    }

    //删除：删除下标为index的元素
    bool del_at_index(int index){
        if(head->next == NULL){
            cout << "链表为空" << endl;
            return false;
        }
        LinkListNode* p = head;
        int i = 0;
        while(i < index && p->next != NULL){
            p = p->next;
            i++;
        }
        if(i != index){
            cout << "输入下标过大" << endl;
            return false;
        }
        LinkListNode* q = p->next;
        p->next = q->next;
        free(q);
        return true;
    }

    //删除：删除第num个元素
    bool del_at_num(int num){
        return del_at_index(num - 1);
    }
};