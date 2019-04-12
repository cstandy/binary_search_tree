#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <queue>
using namespace std;

class BST
{
public:
	/* 
	 * @brief Create binary tree with root node
	 *        (construction without default key is invalid)
	 */
	BST(int);
	~BST();

	/*********************** basic tree operations ****************************/
	void insert(BST*);
	void erase(void); // delete current nodes but preserve subtrees
	BST* search(int);
	BST* max(void);
	BST* min(void);
	BST* successor(void);
	BST* predecessor(void);

	/****************** print traversal method (tree-walk) ********************/
	void print_inorder(void);
	void print_preorder(void);
	void print_postorder(void);
	void print_breadth_first(void);

	/**************************** get function ********************************/
	int getKey(void)         {return key;}
	BST* getLeftChild(void)  {return left_child;}
	BST* getRightChild(void) {return right_child;}
	BST* getParent(void)     {return parent;}

	/**************************** set function ********************************/
	void setKey(int new_key)            {key         = new_key;}
	void setLeftChild(BST* new_left)    {left_child  = new_left;}
	void setRightChild(BST* new_right)  {right_child = new_right;}
	void setParent(BST* new_parent)     {parent      = new_parent;}

private:
	/********************* variable for single node ***************************/
	int key;
	BST* parent;
	BST* left_child;
	BST* right_child;
	
	/* Containers for recursive search in breadth-first method
	 * 
	 * queue<BST*> next_node	   : queue for next node pointer
	 * queue<int> BF_search_output : queue for the output-ordered key
	 *
	 */
	queue<BST*> next_node;
	queue<int> BF_search_output;

	/* 
	 * @brief Breadth-first method
	 */
	void BF_search(queue<BST*>&, queue<int>&);
};

#endif /* BINARY_SEARCH_TREE_H */
