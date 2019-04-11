#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <queue>
using namespace std;

class BST
{
public:
	/* create binary tree with root node
	 * (construction without default key is invalid)
	 */
	BST(int);
	~BST();

	/* basic tree operations */
	void insert(int);
	bool search(int);

	/* print traversal method */
	void print_inorder(void);
	void print_preorder(void);
	void print_postorder(void);
	void print_breadth_first(void);

private:
	/* variable for single node */
	int key;
	BST* left_child;
	BST* right_child;

	/* variable for recursive search the tree,
	 * treat current node as root.
	 */
	int height;
	
	/* containers for recursive search in breadth-first method
	 * 
	 * queue<BST*> next_node	   : queue for next node pointer
	 * queue<int> BF_search_output : queue for the output-ordered key
	 *
	 */
	queue<BST*> next_node;
	queue<int> BF_search_output;

	/* recursive functions 
	 *
	 * void BF_search(queue<BST*>&, queue<int>&)				: breadth-firth method
	 * void recursive_get_height(int&, int)						: measure the depth
	 * void recursive_print_graph(short, short, COORD, HANDLE&) : print each node with position info
	 *
	 */
	void BF_search(queue<BST*>&, queue<int>&);
};

#endif /* BINARY_SEARCH_TREE_H */
