#include<iostream>
#define MaxSize 100
#include<stdlib.h>

using namespace std;

namespace my{
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

    namespace link_list{
        //单链表
        typedef struct LinkListNode{
            int value;
            LinkListNode *next;
        }* LinkList;

        //头插法初始化
        void init_head_insert(LinkList &head){
            head = new LinkListNode;  //初始化头指针
            head->next = NULL;
            int value;
            cout << "输入数据，以回车分割，输入9999结束" << endl;
            while(cin >> value && value != 9999){
                LinkList new_node = new LinkListNode;
                new_node->value = value;
                new_node->next = head->next;
                head->next = new_node;
            }
        }

        //尾插法初始化
        void init_tail_insert(LinkList &head){
            head = new LinkListNode;  //初始化头指针
            head->next = NULL;
            LinkList tail = head;  //建立尾指针
            int value;
            cout << "输入数据，以回车分割，输入9999结束" << endl;
            while(cin >> value && value != 9999){
                LinkList new_node = new LinkListNode;
                new_node->value = value;
                new_node->next = NULL;
                tail->next = new_node;
                tail = tail->next;
            }
        }

        //输出
        void output(LinkList head){
            if(head->next == NULL){
                cout << "链表为空" << endl;
                return;
            }
            LinkList q = head->next;
            if(q != NULL){
                cout << q->value;
                q = q->next;
            }
            while(q != NULL){
                cout << ", " << q->value; 
                q = q->next;
            }
            cout << endl;
        }

        //查找：找到下标为index的数据
        LinkListNode* get_node_by_index(LinkList head, int index){  
            if(head->next == NULL){
                cout << "链表为空" << endl;
                return NULL;
            }
                
            LinkList p = head->next;
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
        LinkListNode* get_node_by_num(LinkList head, int num){
            return (get_node_by_index(head, num-1));
        }

        //查找：找到值为index的第一条数据
        LinkListNode* get_node_by_value(LinkList head, int value){
            if(head->next == NULL){
                cout << "链表为空" << endl;
                return NULL;
            }
            LinkList p = head->next;
            while(p->next != NULL && p->value != value){
                p = p->next;
            }
            if(p->value == value)
                return p;
            cout << "没找到" << endl;
            return NULL;
        }

        //插入：在下标为index的节点后插入元素
        bool insert_at_index(LinkList& head, int index, int value){
            LinkList p = head->next;
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
            temp->value = value;
            temp->next = p->next;
            p->next = temp;
            return true;
        }

        //插入：在第num个节点后插入元素
        bool insert_at_num(LinkList& head, int num, int value){
            return insert_at_index(head, num - 1, value);
        }

        //删除：删除下标为index的元素
        bool del_at_index(LinkList& head, int index){
            if(head->next == NULL){
                cout << "链表为空" << endl;
                return false;
            }
            LinkList p = head;
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
        bool del_at_num(LinkList& head, int num){
            return del_at_index(head, num - 1);
        }
    }

    namespace dual_link{
        typedef struct Node{
            int value;
            struct Node* front;
            struct Node* next;
        }*DualLink;

        void init_head_insert(DualLink &head){
            head = new Node;
            head->front = NULL;
            head->next = NULL;
            int value;
            cout << "输入数据，以回车分割，输入9999结束" << endl;
            while(cin >> value && value != 9999){
                DualLink new_node = new Node;
                new_node->value = value;
                new_node->next = head->next;
                new_node->front = head;
                if(head->next)
                    head->next->front = new_node;
            
                head->next = new_node;
            }
        }

        void output(DualLink head){
            DualLink p = head->next;
            while(p){
                cout << p->value << " ";
                p = p->next;
            }
        }
    }


    namespace array_stack{
        
        typedef struct
        {
            int data[MaxSize];
            int top;
        }ArrayStack;

        //栈初始化
        void init(ArrayStack &stack){
            stack.top = -1;
        }
        
        //入栈
        bool push(ArrayStack &stack, int value){
            if(stack.top >= MaxSize - 1){
                cout << "栈已满" << endl;
                return false;
            }
            stack.data[++stack.top] = value;
            return true;
        }

        //出栈
        int pop(ArrayStack &stack){
            if(stack.top  < 0){
                cout << "栈空" << endl;
                return INT_MAX;
            }
            return stack.data[stack.top--];
        }

        //获取栈顶元素
        int get_top(ArrayStack stack){
            if(stack.top  < 0){
                cout << "栈空" << endl;
                return INT_MAX;
            }
            return stack.data[stack.top];
        }

        void clear(ArrayStack &stack){
            init(stack);
        }
        //从顶到底输出栈
        void output(ArrayStack stack){
            cout << stack.data[stack.top];
            for(int i = stack.top - 1; i >= 0; i--){
                cout << ", " << stack.data[i]; 
            }
            cout << endl;
        }
    }

    //链栈
    namespace link_stack{
        typedef struct LinkStackNode{
            int data;
            LinkStackNode* next;
        }* LinkStack;

        //初始化
        void init(LinkStack &stack){
            stack = new LinkStackNode;
            stack->next = NULL;
        }

        //入栈
        void push(LinkStack &stack, int value){
            LinkStack temp = new LinkStackNode;
            temp->data = value;
            temp->next = stack->next;
            stack->next = temp;
        }

        //出栈
        int pop(LinkStack &stack){
            if(stack->next == NULL){
                cout << "栈空" << endl;;
                return INT_MAX;
            }
            LinkStack temp = stack->next;
            int value = temp->data;
            stack->next = temp->next;
            free(temp);
            return value;
        }

        //获取栈顶元素
        int get_top(LinkStack stack){
            if(stack->next == NULL){
                cout << "栈空" << endl;;
                return INT_MAX;
            }
            return stack->next->data;
        }

        //清空栈
        void clear(LinkStack &stack){
            LinkStack temp = stack;
            while(stack->next != NULL){
                temp = stack->next;
                stack->next = temp->next;
                free(temp);
            }
        }
    }


    //共享栈
    namespace shared_stack{
        typedef struct{
            int data[MaxSize];
            int top[2];
        } SharedStack;

        //初始化栈
        void init(SharedStack &stack){
            stack.top[0] = -1;
            stack.top[1] = MaxSize;
        }

        //入栈
        bool push(SharedStack &stack, int value, bool which = 0){
            if(stack.top[0] + 1 == stack.top[1]){
                cout << "栈满" << endl;
                return false;
            }
            if(which == 0)
                stack.data[++stack.top[which]] = value;
            else
                stack.data[--stack.top[which]] = value;
            return true;
        }

        //出栈
        int pop(SharedStack &stack, bool which = 0){
            if(stack.top[which] == -1 || stack.top[which] == MaxSize){
                cout << "栈空" << endl;
                return INT_MAX;
            }
            if(which == 0)
                return stack.data[stack.top[which]--];
            else
                return stack.data[stack.top[which]++];
        }

        //清空栈
        void clear(SharedStack &stack){
            init(stack);
        }

        //获取栈顶元素
        int get_top(SharedStack stack, bool which = 0){
            if(stack.top[which] == -1 || stack.top[which] == MaxSize){
                cout << "栈空" << endl;
                return INT_MAX;
            }
            return stack.data[stack.top[which]];
        }
    }

    namespace circular_queue{
    /*
        此处为牺牲一个单元来区分队空和队满的情况
        另有设置tag判断空满的方法。见p80-1.cpp
    */

        struct CircularQueue{
            int data[MaxSize];
            int front, rear;
        };
        
        void init(CircularQueue &queue){
            queue.front = queue.rear = 0;
        }

        bool enter(CircularQueue &queue, int x){
            if(queue.front == (queue.rear+1) % MaxSize){
                cout << "队满" << endl;
                return false;
            }
            queue.data[queue.rear] = x;
            queue.rear = (queue.rear + 1) % MaxSize;
            return true;
        }

        int quit(CircularQueue &queue){
            if(queue.front == queue.rear){
                cout << "队空" << endl;
                return INT_MAX;
            }
            int result = queue.data[queue.front];
            queue.front = (queue.front + 1) % MaxSize;
            return result;
        }

        bool is_empty(CircularQueue queue){
            if(queue.front == queue.rear){
                return true;
            }
            return false;
        }
    }

    
    namespace link_queue{

        //队列的链式存储，头指针出队，尾指针入队
        
        template<class T>
        struct QueueNode{
            T data;
            QueueNode *next;
        };

        template<class T>   
        struct LinkQueue{
            QueueNode<T> *front, *rear;
        };

        //队列初始化
        template<class T>
        void init(LinkQueue<T> &queue){
            queue.front = new QueueNode<T>;
            queue.front->next = NULL;
            queue.rear = queue.front;
        }

        //入队
        template<class T>
        bool enter(LinkQueue<T> &queue, T x){
            QueueNode<T>* temp;
            if(!(temp= new QueueNode<T>))
                return false;
            temp->data = x;
            temp->next = NULL;
            queue.rear->next = temp;
            queue.rear = temp;
            return true;
        }

        //出队
        template<class T>
        T quit(LinkQueue<T> &queue){
            if(queue.front == queue.rear){
                cout << "队空" << endl;
                return NULL;
            }
            QueueNode<T>* temp = queue.front->next;
            T result = temp->data;
            queue.front->next= temp->next;
            if(queue.rear == temp){
                queue.rear = queue.front;
            }
            free(temp);
            return result;  
        }

        //判断队空
        template<class T>
        bool is_empty(LinkQueue<T> &queue){
            if(queue.front == queue.rear){
                return true;
            }
            return false;
        }

        //清除队列中的所有元素
        template<class T>
        void clear(LinkQueue<T> &queue){
            while(!is_empty(queue))
                cout << quit(queue) << endl;
        }
    }
}