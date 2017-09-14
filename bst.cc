#include <iostream>
#include "bst.h"
#include <vector>
using namespace std;

bstree::bstree(int x) : data(x), left(NULL), right(NULL) {}
bstree::~bstree() {}


/*
 * Make generic inorder traversal that can
 * traverse based on any head.
 * OUTPUT: vector of inorder node values.
 */
bool bstree::inorder(vector<int>& answer)
{
    //vector<int> answer;
    //vector<int> p;

    if (this == NULL) {
        return false;
    }

    if ((this->left == NULL) && (this->right == NULL)) {
        answer.push_back(this->data);
    } else {
        if (this->left != NULL) {
            //p.clear();
            //p = (this->left)->inorder(answer);
            //answer.insert(answer.end(), p.begin(), p.end());
            (this->left)->inorder(answer);
        }
        answer.push_back(this->data);
        if (this->right != NULL) {
            //p.clear();
            //p = (this->right)->inorder();
            //answer.insert(answer.end(), p.begin(), p.end());
            (this->right)->inorder(answer);
        }
    }
    return true;
}

/*
 * Insert node in a binary search tree
 */
bool bstree::insert(int val)
{
    if (this == NULL) {
        return false;
    }
    if (val <= this->data) {
        if (this->left == NULL) {
            bstree* node = new bstree(val);
            this->left = node;
            return true;
        } else {
            return (this->left)->insert(val);
        }
    } else {
        if (this->right == NULL) {
            bstree* node = new bstree(val);
            this->right = node;
            return true;
        } else {
            return (this->right)->insert(val);
        }
    }
    return false;
}

int main()
{
    bstree* alist = new bstree(0);
    while (true) {
        int n;
        cout << "Enter a value (Zero to exit): ";
        cin >> n;
        if (n == 0)
            break;
        if (alist->insert(n)) {
            continue;
        } else {
            break;
        }
    }

    vector<int> p;
    vector<int>::iterator it;
    if(alist->inorder(p)) {
        cout << "HEAD";
        for (it = p.begin(); it != p.end(); it++)
            cout << " -> " << *it;
    }

    return 0;
}

