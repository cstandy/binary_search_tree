#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <string>
using namespace std;

class BST
{
public:
    /* create empty binary tree */
    BST(void);
    ~BST();

    /* basic tree operations */
    void insert(int);
    void remove(void);

    /* traversal method */
    void print_graph(void);
    void print_inorder(void);
    void print_preorder(void);
    void print_postorder(void);
    void print_breadth_first(void);
private:
    int key;
};

#endif /* BINARY_SEARCH_TREE_H */
