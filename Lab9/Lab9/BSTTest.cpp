#include "BST.h"
#include <iostream>

using namespace std;

int main()
{
    BST<int> tree;

    //insert items into tree
    tree.InsertItem(1);
    tree.InsertItem(5);
    tree.InsertItem(30);
    tree.InsertItem(4);
    tree.InsertItem(6);
    tree.InsertItem(20);


    if (tree.SearchItem(1) == true)
    {
        cout << "1 is in Binary Tree" << endl << endl;
    }

    if (tree.SearchItem(20) == true)
    {
        cout << "20 is in Binary Tree" << endl << endl;
    }

    cout << "\nThe height of the tree is: " << tree.TreeHeight() << endl << endl;

    cout << "Inorder Traversal:" << endl;

    tree.InOrderTraversal();

    cout << "\nPreorder Traversal:" << endl;

    tree.PreOrderTraversal();

    cout << "\nPostorder Traversal:" << endl;

    tree.PostOrderTraversal();

    cout << endl;

    cout << "\nTest = operator" << endl;

    BST<int> newTree;

    newTree = tree;

    cout << "\nCopied Tree Inorder Traversal: " << endl;

    newTree.InOrderTraversal();

    cout << "\nCopied Tree Preorder Traversal: " << endl;

    newTree.PreOrderTraversal();

    cout << "\nCopied Tree Postorder Traversal: " << endl;

    newTree.PostOrderTraversal();

    cout << "\n\nTest copy constructor" <<endl;

    BST<int> copyTree(tree);

    cout << "\nCopied Tree Inorder Traversal: " << endl;

    copyTree.InOrderTraversal();

    cout << "\nCopied Tree Preorder Traversal: " << endl;

    copyTree.PreOrderTraversal();

    cout << "\nCopied Tree Postorder Traversal: " << endl;

    copyTree.PostOrderTraversal();

    cout << "\n\nTest destructor, deleting newTree, check whether newTree is now empty: " << endl;

    newTree.~BST();

    cout << "\nIs newTree empty?" << endl;

    if (newTree.IsEmpty() == true)
    {
        cout << "newTree is now empty" << endl;
    }
    else
    {
        cout << "newTree is not empty!" << endl;
    }


    return 0;
}
