#include "../include/ds.h"

using namespace my::link_queue;
using namespace std;

template<class T>
class BiTreeNode{
    BiTreeNode* left;
    BiTreeNode* right;
    

public:
    T value;
    BiTreeNode(){
        this->left = nullptr;
        this->right = nullptr;
    }

    // void pre_init(BiTreeNode** root){
    //     T value;
    //     cin >> value;
    //     if(value == '#')
    //         *root = NULL;
    //     else{
    //         *root = new BiTreeNode();
            
    //         (*root)->value = value;
            
    //         pre_init(&(*root)->left);
    //         pre_init(&(*root)->right);
    //     }
    // }

    BiTreeNode* pre_init(){
        T value;
        cin >> value;
        BiTreeNode* node = new BiTreeNode;
        if(value == 0){
            return NULL;
        }
        node->value = value;
        node->left = pre_init();
        node->right = pre_init();
        return node;
    }

    void pre_order(BiTreeNode* root){
        if(root != nullptr){
            cout << root->value << " ";
            pre_order(root->left);
            pre_order(root->right);
        }
    }

    void in_order(BiTreeNode* root){
        if(root != nullptr){
            in_order(root->left);
            cout << root->value << " ";
            in_order(root->right);
        }
    }

    void post_order(BiTreeNode* root){
        if(root != nullptr){
            post_order(root->left);
            post_order(root->right);
            cout << root->value << " ";
        }
    }

    void level_order(BiTreeNode* root){
        LinkQueue<BiTreeNode*> queue;
        init(queue);
        enter(queue, root);
        while(!my::link_queue::is_empty(queue)){
            root = quit(queue);
            cout << root->value << " ";
            if(root->left != nullptr)
                enter(queue, root->left);
            if(root->right != nullptr)
                enter(queue, root->right);
        }
    }
};
