#include <iostream>
#include <cmath>
#include "binary_search_tree.h"
using namespace std;

/* constructor, initialize with key */
BST::BST(int key_in)
{
    key         = key_in;
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
 * Recursive search the tree to add the key as leaf.
 * If the key has existed, do nothing.
 *
 * key_in: the key to be inserted
 * 
 */
void BST::insert(int key_in)
{
    if (key < key_in)
    {
        if (right_child != NULL)
            right_child->insert(key_in);
        else
            right_child = new BST(key_in);
    }
    else if (key > key_in)
    {
        if (left_child != NULL)
            left_child->insert(key_in);
        else
            left_child = new BST(key_in);
    }
    else if (key == key_in){}
}

/*
 * Recursively search the tree with a key.
 * If the key exists, return true;
 * if the key does not exist, return false.
 *
 */
bool BST::search(int key_search)
{
    if (key == key_search)
    {
        return true;
    }
    else if (key < key_search)
    {
        if (right_child != NULL)
        if (right_child->search(key_search))
            return true;
    }
    else if (key > key_search)
    {
        if (left_child != NULL)
        if (left_child->search(key_search))
            return true;
    }

    return false;
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
