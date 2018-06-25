#include <iostream>
#include <cmath>
#include "binary_search_tree.h"
using namespace std;

/* get the cursor position
 *
 * getxy().X : get x coordinate, return in short type
 * getxy().Y : get y coordinate, return in short type
 *
 */
COORD getxy()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return csbi.dwCursorPosition;
}

/* set the size of the output window 
 *
 * w: width
 * h: height
 * 
 */
void SetConsoleSize(int w, int h)
{
    COORD Sz;
    Sz.X = w;
    Sz.Y = h;
    SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), Sz);//改buffer(可cout的範圍)
    MoveWindow(GetConsoleWindow(), 100, 100, w * 11, h * 24, true);//改顯示大小
}

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

/* recursively measure the height (depth) of the tree */
int BST::depth(void)
{
    height = 0;

    recursive_get_height(height, 0);
    return height;
}

/*
 * Recursive function.
 * If the current level (level) is higher than max_height (height),
 * than update the max_height (height).
 * Recursively get the height of both subtrees.
 */
void BST::recursive_get_height(int& height, int level)
{
    level++;

    if (height < level)
        height = level;

    if (left_child != NULL)
        left_child->recursive_get_height(height, level);
    if (right_child != NULL)
        right_child->recursive_get_height(height, level);
}

/* print the graph based on counting the coordinate */
void BST::print_graph(void)
{
	// counting the height and width for further position calculation
    height = depth();
    short width = (short)pow(2, height);
    COORD orgin = { getxy().X, getxy().Y };

	// adjust the size of the console window
    SetConsoleSize((3 * width < 100) ? 100 : 3* width, 15 + height);

	// set the starting position
    position = { width, getxy().Y };

	// recursive search and print
    recursive_print_graph(width, getxy().Y, position, cursor_handle);

    // move the cursor back to the original position
    position = orgin;
    SetConsoleCursorPosition(cursor_handle, position);

	// move the cursor to the position below the graph
    position = { 0, getxy().Y + (short)height };
    SetConsoleCursorPosition(cursor_handle, position);
}

/* inorder traversal and print the node according the coordinate */
void BST::recursive_print_graph(short current_width, short current_y, COORD current_position, HANDLE& out_handle)
{
	// set the cursor position to print the key in correct position
    SetConsoleCursorPosition(out_handle, current_position);
    cout << key;

	// store the current coordinate for later function
	// otherwise the x coordinate may change due to recursive print
    short current_x = getxy().X;

	// recursive print
    if (left_child != NULL)
    {
        current_position = { current_x - (current_width / 2) - 1, current_y + 1 };
        left_child->recursive_print_graph(current_width / 2, current_y + 1, current_position, out_handle);
    }
    if (right_child != NULL)
    {
        current_position = { current_x + (current_width / 2) - 1, current_y + 1 };
        right_child->recursive_print_graph(current_width / 2, current_y + 1, current_position, out_handle);
    }
        
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
