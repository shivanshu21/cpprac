#ifndef __SHIV_BST_H__
#define __SHIV_BST_H__

#include <vector>
class bstree {
    public:
        int data;
        bstree* left;
        bstree* right;
        bstree(int);
        ~bstree();
        //std::vector<int> inorder();
        bool inorder(std::vector<int>&);
        bool insert(int);
};

#endif
