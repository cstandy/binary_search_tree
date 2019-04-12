/*
 * Author: cstandy, NCKUEE
 *
 * This main function aims to complete the user-interface of the binary
 * search tree with the class BST (binary search tree). The fucntion about
 * class BST is defined in binary_search_tree.h and implemented in
 * binary_search_tree.cpp.
 *
 */

#define INPUT_FILE "data.txt"


#include <fstream>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "binary_search_tree.h"

using namespace std;

int main()
{
	int input_data = 0;
	int select     = 0;
	int key        = 0;
	BST *temp;

	printf("\r\n 2 approaches to construct a binary search tree:");
	printf("\r\n\t1) Read input data");
	printf("\r\n\t2) Randomly generate");
	printf("\r\n\r\n Please select: ");
	cin >> select;

	if (select == 1)
	{
		ifstream input_file(INPUT_FILE, ios::in);

		if (!input_file)
		{
			cerr << "Input file: " << INPUT_FILE << " open failed.\r\n";
			exit(1);
		}

		input_file >> input_data;
		printf("\r\n");
		printf(" . Input data             : %d", input_data);

		BST tree(input_data);

		while (input_file >> input_data)
		{
			tree.insert(new BST(input_data));
			printf(" %d", input_data);
		}

		printf("\r\n\r\n");
		printf(" . Inorder tree-walk      :");
		tree.print_inorder();
		printf("\r\n\r\n");
		printf(" . Preorder tree-walk     :");
		tree.print_preorder();
		printf("\r\n\r\n");
		printf(" . Postorder tree-walk    :");
		tree.print_postorder();
		printf("\r\n\r\n");
		printf(" . Breadth-first tree-walk:");
		tree.print_breadth_first();
		printf("\r\n\r\n");
		printf(" . Maximum key value      : %d", tree.max()->getKey());
		printf("\r\n\r\n");
		printf(" . Minimum key value      : %d", tree.min()->getKey());

		// test the successsor
		printf("\r\n\r\n");
		printf("=============================================================");
		printf("\r\n\r\n");
		printf(" . Find the successor of a node: ");
		cin >> key;
		temp = tree.search(key);
		if (temp == NULL)
			printf("\r\n ! Error: Not found.");
		else 
		{
			if (temp->successor() == NULL)	
				printf("\r\n ! %d is the largest node.", key);
			else
			{
				printf("\r\n");
				printf("    . The successor of %d: %d", 
						key, temp->successor()->getKey());
			}
		}

		// test the predecessor
		printf("\r\n\r\n");
		printf("=============================================================");
		printf("\r\n\r\n");
		printf(" . Find the predecessor of a node: ");
		cin >> key;
		temp = tree.search(key);
		if (temp == NULL)
			printf("\r\n ! Error: Not found.");
		else 
		{
			if (temp->predecessor() == NULL)	
				printf("\r\n ! %d is the smallest node.", key);
			else
			{
				printf("\r\n");
				printf("    . The predecessor of %d: %d", 
						key, temp->predecessor()->getKey());
			}
		}

		// demo the insertion
		printf("\r\n\r\n");
		printf("=============================================================");
		printf("\r\n\r\n");
		printf(" . Insert a node: ");
		cin >> key;
		temp = new BST(key);
		tree.insert(temp);
		printf("\r\n");
		printf(" . Inorder tree-walk      :");
		tree.print_inorder();

		// test the deletion
		printf("\r\n\r\n");
		printf("=============================================================");
		printf("\r\n\r\n");
		printf(" . Delete a node: ");
		cin >> key;
		temp = tree.search(key);
		if (temp != NULL)
		{
			temp->erase();
			printf("\r\n");
			printf(" . Inorder tree-walk      :");
			tree.print_inorder();
		}
		else
			printf("\r\n Error: Not found.");
		
	}
	else if (select == 2)
	{
		// may use different way to generate random numbers


		printf("\r\n  Please enter the node number: ");
		cin >> select;

		srand(time(0));
		input_data = rand() % 99 + 1;
		printf("\r\n");
		printf(" . input data             : %d", input_data);

		BST tree(input_data);

		for (int i = 1; i < select; i++)
		{
			input_data = rand() % 99 + 1;
			tree.insert(new BST(input_data));
			printf(" %d", input_data);
		}

		printf("\r\n\r\n");
		printf(" . Inorder tree-walk      :");
		tree.print_inorder();
		printf("\r\n\r\n");
		printf(" . Preorder tree-walk     :");
		tree.print_preorder();
		printf("\r\n\r\n");
		printf(" . Postorder tree-walk    :");
		tree.print_postorder();
		printf("\r\n\r\n");
		printf(" . Breadth-first tree-walk:");
		tree.print_breadth_first();
		printf("\r\n\r\n");
		printf(" . Maximum key value: %d", tree.max()->getKey());
		printf("\r\n\r\n");
		printf(" . Minimum key value: %d", tree.min()->getKey());

		// test the successsor
		printf("\r\n\r\n");
		printf("=============================================================");
		printf("\r\n\r\n");
		printf(" . Find the successor of a node: ");
		cin >> key;
		temp = tree.search(key);
		if (temp == NULL)
			printf("\r\n ! Error: Not found.");
		else 
		{
			if (temp->successor() == NULL)	
				printf("\r\n ! %d is the largest node.", key);
			else
			{
				printf("\r\n");
				printf("    . The successor of %d: %d", 
						key, temp->successor()->getKey());
			}
		}

		// test the predecessor
		printf("\r\n\r\n");
		printf("=============================================================");
		printf("\r\n\r\n");
		printf(" . Find the predecessor of a node: ");
		cin >> key;
		temp = tree.search(key);
		if (temp == NULL)
			printf("\r\n ! Error: Not found.");
		else 
		{
			if (temp->predecessor() == NULL)	
				printf("\r\n ! %d is the smallest node.", key);
			else
			{
				printf("\r\n");
				printf("    . The predecessor of %d: %d", 
						key, temp->predecessor()->getKey());
			}
		}

		// demo the insertion
		printf("\r\n\r\n");
		printf("=============================================================");
		printf("\r\n\r\n");
		printf(" . Insert a node: ");
		cin >> key;
		temp = new BST(key);
		tree.insert(temp);
		printf("\r\n");
		printf(" . Inorder tree-walk      :");
		tree.print_inorder();

		// test the deletion
		printf("\r\n\r\n");
		printf("=============================================================");
		printf("\r\n\r\n");
		printf(" . Delete a node: ");
		cin >> key;
		temp = tree.search(key);
		if (temp != NULL)
		{
			temp->erase();
			printf("\r\n");
			printf(" . Inorder tree-walk      :");
			tree.print_inorder();
		}
		else
			printf("\r\n Error: Not found.");
	}

	printf("\r\n\r\n");

	return 0;
}
