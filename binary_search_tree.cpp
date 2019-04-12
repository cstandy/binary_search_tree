#include <iostream>
#include <cmath>
#include "binary_search_tree.h"
using namespace std;

/* constructor, initialize with key */
BST::BST(int key_in)
{
    key         = key_in;
    parent      = NULL;
    left_child  = NULL;
    right_child = NULL;
}

/* destructor, recursively delete the subtree */
BST::~BST(void)
{
    if (left_child != NULL)
        delete left_child;

    else if (right_child != NULL)
        delete right_child;
}

/*
 * Insert a node in binary search tree.
 * Recursive search the tree to add the node as leaf.
 * If the key has existed, free the space of inserting node.
 */
void BST::insert(BST* node_in)
{
    if (key < node_in->key)
    {
        if (right_child != NULL)
            right_child->insert(node_in);
        else {
            this->right_child = node_in;
            node_in->setParent(this);
        }
            
    }
    else if (key > node_in->getKey())
    {
        if (left_child != NULL)
            left_child->insert(node_in);
        else {
            this->left_child = node_in;
            node_in->setParent(this);
        }
    }
    else if (key == node_in->getKey())
    {
        delete node_in;
    }
    // ignore the repeated key and free the memory space
}

/* Delete the node based on its pointer */
void BST::erase(void)
{
    BST *replace, *subtree;

    // if the deleted node has more than 2 subtrees, deleting will need to
    // replace the successsor to deleted node
    if (this->left_child == NULL || this->left_child == NULL)
        replace = this;
    else 
        replace = this->successor();

    // check if the node want to replace the deleted node has child
    if (replace->getLeftChild() != NULL)
        subtree = replace->getLeftChild();
    else 
        subtree = replace->getRightChild();

    // reconnect the subtree to the parent
    if (subtree != NULL)
        subtree->setParent(replace->getParent());

    // reconnect the parent to the subtree
    if (replace->getParent() == NULL) {}
    else if (replace == replace->getParent()->getLeftChild())
        replace->getParent()->setLeftChild(subtree);
    else
        replace->getParent()->setRightChild(subtree);
    
    // replace the successor to current node
    if (replace != this)
        this->setKey(replace->getKey());
}

/* Recursively search the tree with a key. */
BST* BST::search(int key_search)
{
    if (key == key_search)
        return this;
    else if (key < key_search)
    {
        return (right_child == NULL)? NULL : right_child->search(key_search);
    }
    else
        return (left_child == NULL)? NULL : left_child->search(key_search);
}

/* Search for the maximum node in the tree (must be leaf) */
BST* BST::max(void)
{
    BST* maximum = this;

    while (maximum->right_child != NULL)
        maximum = maximum->right_child;

    return maximum;
}

/* Search for the minimum node in the tree (must be leaf) */
BST* BST::min(void)
{
    BST* minimum = this;

    while (minimum->left_child != NULL)
        minimum = minimum->left_child;

    return minimum;
}

/* Search for the successor node in the tree */
BST* BST::successor(void)
{
    // 1st case: the leftmost node of right subtree
    if (this->right_child != NULL)
        return this->right_child->min();
    
    // 2nd case: the go up to the parent
    // Note: return NULL while this is the largest node in tree
    BST* y = this->parent;
    BST* x = this;
    
    while(y != NULL)
    {
        if (x == y->right_child)
        {
            x = y;
            y = y->parent;
        }
        else
            break;
    }

    return y;
}

BST* BST::predecessor(void)
{
    // 1st case: the rightmost node of left subtree
    if (this->left_child != NULL)
        return this->left_child->max();
    
    // 2nd case: the go up to the parent
    // Note: return NULL while this is the largest node in tree
    BST* y = this->parent;
    BST* x = this;
    
    while(y != NULL)
    {
        if (x == y->left_child)
        {
            x = y;
            y = y->parent;
        }
        else
            break;
    }

    return y;
}

/* print the tree in-order with recursive */
void BST::print_inorder(void)
{
    if (left_child != NULL)
        left_child->print_inorder();

    cout << " " << key;

    if (right_child != NULL)
        right_child->print_inorder();
}

/* print the tree pre-order with recursive */
void BST::print_preorder(void)
{
    cout << " " << key;

    if (left_child != NULL)
        left_child->print_preorder();

    if (right_child != NULL)
        right_child->print_preorder();
}

/* print the tree post-order with recursive */
void BST::print_postorder(void)
{
    if (left_child != NULL)
        left_child->print_postorder();

    if (right_child != NULL)
        right_child->print_postorder();

    cout << " " << key;
}

/* breadth-first search and print */
void BST::print_breadth_first(void)
{
    /* clean the queue for new search */
    while (!next_node.empty())
        next_node.pop();
    while (!BF_search_output.empty())
        BF_search_output.pop();

    BF_search(next_node, BF_search_output);

	/* print the search result */
    while (!BF_search_output.empty())
    {
        cout << " " << BF_search_output.front();
        BF_search_output.pop();
    }

	/* clean the queue again for program stablility */
    while (!next_node.empty())
        next_node.pop();
}

/* recureively search */
void BST::BF_search(queue<BST*>& next, queue<int>& output)
{
    BST* temp;

	// push current key for output
    output.push(key);

	// push the child node for search
    if (left_child != NULL)
        next.push(left_child);
    if (right_child != NULL)
        next.push(right_child);

	// go to the next node
    if (!next.empty())
    {
        temp = next.front();
        next.pop();
        temp->BF_search(next, output);
    }

}
