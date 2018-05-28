#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <string>
using namespace std;

class BST
{
public:
    /* create binary tree randomly */
    BST(int);
    /* read the input file name */
    BST(char*[]);
    BST(string);
    ~BST();

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
