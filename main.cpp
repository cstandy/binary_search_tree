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
    int select = 0;

    printf("please select to: 1) read input data, 2) randomly generate: ");
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
		printf("input data                   : %d", input_data);

        BST tree(input_data);

		while (input_file >> input_data)
		{
			tree.insert(input_data);
			printf(" %d", input_data);
		}
            
		printf("\r\ntree depth: %d", tree.depth());

		printf("\r\ngraph:\r\n");
		tree.print_graph();

		printf("\r\n\r\n");
        printf("inorder   (left->root->right):");
        tree.print_inorder();
		printf("\r\n\r\n");
        printf("preorder  (root->left->right):");
        tree.print_preorder();
		printf("\r\n\r\n");
        printf("postorder (left->right->root):");
        tree.print_postorder();
		printf("\r\n\r\n");
        printf("breadth-first search         :");
        tree.print_breadth_first();
    }
    else if (select == 2)
    {
        // may use different way to generate random numbers


        printf("please enter the node number: ");
        cin >> select;


        srand(time(0));
		input_data = rand() % 99 + 1;
		printf("\r\n");
		printf("input data                   : %d", input_data);

		BST tree(input_data);

        for (int i = 1; i < select; i++)
        {
			input_data = rand() % 99 + 1;
			tree.insert(input_data);
			printf(" %d", input_data);
        }

		printf("\r\ntree depth: %d", tree.depth());

		printf("\r\ngraph:\r\n");
		tree.print_graph();

		printf("\r\n\r\n");
		printf("inorder   (left->root->right):");
		tree.print_inorder();
		printf("\r\n\r\n");
		printf("preorder  (root->left->right):");
		tree.print_preorder();
		printf("\r\n\r\n");
		printf("postorder (left->right->root):");
		tree.print_postorder();
		printf("\r\n\r\n");
		printf("breadth-first search         :");
		tree.print_breadth_first();
    }

    printf("\r\n");

    system("pause");
    return 0;
}
