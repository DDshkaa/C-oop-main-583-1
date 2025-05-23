#include <iostream>
#include "BinarySearchTree.h"
#include "SupportMethods.h"
#include "BinarySearchTree_IO.h"
#include "Treap.h"
#include "Treap_IO.h"
using namespace std;

void ShowMainMenu()
{
    cout << "\nMain menu:" << endl;
    cout << "1. Binary search tree" << endl;
    cout << "2. Treap" << endl;
    cout << "0. Exit" << endl;

}

void Menu()
{

    BinarySearchTree* binaryTree = CreateTree();
    Treap* treap = CreateTreap();
    while (true)
    {
        ClearScreen();
        ShowMainMenu();

        int choice = GetIntInput("Your input: ");

        switch (choice)
        {

            case 1:
            {

                BinaryTreeChoice(binaryTree);
                break;
            }

            case 2:
            {

                TreapChoice(treap);
                break;
            }

            case 0:
            {
                Clear(treap->Root);
                return;
            }
        default:
            cout << "Invalid choice! Try again." << endl;
        }

    }
}
