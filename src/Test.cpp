#include "../include/bi_tree.h"


int main(){
    BiTreeNode<int>*root = nullptr;
    root->sort_init(&root);
    root->in_order(root);
    // root->level_order(root);
}
