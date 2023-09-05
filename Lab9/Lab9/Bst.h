#ifndef BST_H
#define BST_H

#include <iostream>

using namespace std;

//node definition
template <class elemType>
struct NodeType
{
    elemType info;
    NodeType<elemType> *lLink;
    NodeType<elemType> *rLink;
};


//class definition
template <class elemType>
class BST
{
public:

    typedef NodeType<elemType> BSTNode;

    /**
    * @brief Overload assignment operator.
    */
    const BST<elemType>& operator=(const BST<elemType>&);

    /**
    * @brief Function to determine whether binary tree is empty
    * @return True or False
    */
    bool IsEmpty() const;

    /**
    * @brief Function to do an inorder traversal of the binary tree.
    * @post Nodes are printed in inorder sequence
    */
    void InOrderTraversal() const;

    /**
    * @brief Function to do a preorder traversal of the binary tree.
    * @post Nodes are printed in preorder sequence
    */
    void PreOrderTraversal() const;

    /**
    * @brief Function to do a postorder traversal of the binary tree.
    * @post Nodes are printed in postorder sequence
    */
    void PostOrderTraversal() const;

    /**
    * @brief Function to determine height of binary tree
    * @return Returns height of tree
    */
    int TreeHeight() const;

    /**
    * @brief Function to destroy the binary tree
    * @post Memory of the tree is deallocated, root set to nullptr
    */
    void DestroyTree();

    /**
    * @brief Function to search item in binary tree
    * @post True is returned if searchItem is found, else False
    */
    bool SearchItem(const elemType& searchItem) const;

    /**
    * @brief Function to insert item in binary tree
    * @post insertItem is inserted into the binary tree
    */
    void InsertItem(const elemType& insertItem);

    /**
    * @brief Function to delete deleteItem from the binary tree
    * @pre Binary tree should not be empty
    * @post If node with same info as deleteItem found, it is deleted from the binary tree
    */
    void DeleteNode(NodeType<elemType>* &deleteItem);

    /**
    * @brief Copy constructor for binary tree
    * @post copyTree is copied
    */
    BST(const BST<elemType>& copyTree);

    /**
    * @brief Default constructor for binary tree
    */
    BST();

    /**
    * @brief Destructor for binary tree
    */
    ~BST();

private:

    BSTNode *root = nullptr;

    /**
    * @brief Function to copy tree from copiedTreeRoot
    * @post copiedTreeRoot is copied to the copied tree
    */
    void CopyTree(NodeType<elemType>* &copiedTreeRoot, NodeType<elemType>* otherTreeRoot);

    /**
    * @brief Function to destroy binary tree
    * @param p = pointer for binary tree to be destroyed
    * @post memory occupied by each node in the binary tree where p points to is deallocated, p is set to nullptr
    */
    void Destroy(NodeType<elemType>* &p);

    /**
    * @brief Function to do inorder traversal of Binary Tree
    * @param p = pointer for binary tree
    * @post Nodes of the binary tree are printed in inorder sequence
    */
    void InOrder(NodeType<elemType> *p) const;

    /**
    * @brief Function to do preorder traversal of Binary Tree
    * @param p = pointer for binary tree
    * @post Nodes of the binary tree are printed in preorder sequence
    */
    void PreOrder(NodeType<elemType> *p) const;

    /**
    * @brief Function to do postorder traversal of Binary Tree
    * @param p = pointer for binary tree
    * @post Nodes of the binary tree are printed in postorder sequence
    */
    void PostOrder(NodeType<elemType> *p) const;

    /**
    * @brief Function to determine if searchItem is in the binary tree
    * @post True or False
    */
    bool Search(const elemType& searchItem) const;

    /**
    * @brief Function to do a recursive search on Binary Tree, looking for searchItem
    * @param searchItem for node to be searched for
    * @return True or False
    */
    bool Search(const elemType& searchItem, BSTNode* current) const;

    /**
    * @brief Function to insert item into the binary tree recursively
    * @post If there is no node in the binary tree that has the same info as insertItem, a node will be created and inserted into the binary tree.
    */
    BSTNode* Insert(BSTNode* insertItem, BSTNode* current);

    /**
    * @brief Function to insert item into the binary tree
    * @post If there is no node in the binary tree that has the same info as insertItem, a node will be created and inserted into the binary tree.
    */
    void Insert(const elemType insertItem);

    /**
    * @brief Function to get height of Binary Tree
    * @param p = pointer for binary tree
    * @post Height of binary tree which p points to is returned
    */
    int Height(NodeType<elemType> *p) const;

    /**
    * @brief Function to determine larger of x and y
    * @post Returns the larger of x and y
    */
    int Max(int x, int y) const;
};

template <class elemType>
BST<elemType>::BST()
{
    root = nullptr;
}

template <class elemType>
BST<elemType>::~BST()
{
   if(root) //check for nullptr
   {
       Destroy(root);
   }
}

template <class elemType>
BST<elemType>::BST (const BST<elemType>& otherTree)
{
     if (otherTree.root == nullptr)
     {
        root = nullptr;
     }
     else
     {
        CopyTree(root, otherTree.root);
     }
}

template <class elemType>
const BST<elemType>& BST<elemType>::operator=(const BST<elemType>& otherTree)
{
    if (this != &otherTree)
    {
        if (root != nullptr)
        {
            Destroy(root);
        }
        if (otherTree.root == nullptr)
        {
            root = nullptr;
        }
        else
        {
            CopyTree(root, otherTree.root);
        }
    }
}

template <class elemType>
void BST<elemType>::Destroy(NodeType<elemType>* &p)
{
    if (p != nullptr)
    {
        Destroy(p->lLink);
        Destroy(p->rLink);
        delete p;
        p = nullptr;
    }
}

template <class elemType>
void BST<elemType>::DestroyTree()
{
    Destroy(root);
}

template <class elemType>
bool BST<elemType>::IsEmpty() const
{
    return (root == nullptr);
}

template <class elemType>
void BST<elemType>::InOrderTraversal() const
{
    InOrder(root);
}

template <class elemType>
void BST<elemType>::PreOrderTraversal() const
{
    PreOrder(root);
}

template <class elemType>
void BST<elemType>::PostOrderTraversal() const
{
    PostOrder(root);
}

template <class elemType>
int BST<elemType>::TreeHeight() const
{
    return Height(root);
}

template <class elemType>
void BST<elemType>::InOrder(NodeType<elemType> *p) const
{
    if (p != nullptr)
    {
        InOrder(p->lLink);
        cout << p->info << " ";
        InOrder(p->rLink);
    }
}

template <class elemType>
void BST<elemType>::PreOrder(NodeType<elemType> *p) const
{
    if (p != nullptr)
    {
        cout << p->info << " ";
        PreOrder(p->lLink);
        PreOrder(p->rLink);
    }
}

template <class elemType>
void BST<elemType>::PostOrder(NodeType<elemType> *p) const
{
    if (p != nullptr)
    {
        PostOrder(p->lLink);
        PostOrder(p->rLink);
        cout << p->info << " ";
    }
}

template <class elemType>
int BST<elemType>::Height(NodeType<elemType> *p) const
{
    if (p == nullptr)
    {
        return 0;
    }
    else
    {
        return 1 + Max(Height(p->lLink),Height(p->rLink));
    }
}

template <class elemType>
int BST<elemType>::Max(int x, int y) const
{
    if (x >= y)
    {
        return x;
    }
    else
    {
        return y;
    }
}

template <class elemType>
void BST<elemType>::DeleteNode(NodeType<elemType>* &deleteItem)
{
    if (!deleteItem) //check for nullptr
    {
        return;
    }
    else
    {
        DeleteNode(deleteItem->lLink);
        DeleteNode(deleteItem->rLink);
        delete deleteItem;
        deleteItem = nullptr;
    }
}

template <class elemType>
void BST<elemType>::CopyTree(NodeType<elemType>* &copiedTreeRoot, NodeType<elemType>* otherTreeRoot)
{
    if (otherTreeRoot == nullptr)
    {
        copiedTreeRoot = nullptr;
    }
    else
    {
        copiedTreeRoot = new NodeType<elemType>;
        copiedTreeRoot->info = otherTreeRoot->info;
        CopyTree(copiedTreeRoot->lLink, otherTreeRoot->lLink);
        CopyTree(copiedTreeRoot->rLink, otherTreeRoot->rLink);
    }
}

template <class elemType>
bool BST<elemType>::SearchItem(const elemType& searchItem) const
{
    return Search(searchItem, root); //recursive search
}

template <class elemType>
void BST<elemType>::InsertItem(const elemType& insertItem)
{
    BSTNode *newNode = new BSTNode;
    newNode->info = insertItem;
    newNode->lLink = nullptr;
    newNode->rLink = nullptr;
    root = Insert(newNode, root); //recursive insert
}

//Recursive Search
template <class elemType>
bool BST<elemType>::Search(const elemType& searchItem, BSTNode* current) const
{
    if (current != nullptr)
    {
        if (current->info == searchItem)
        {
            return true;
        }
        else if (current->info > searchItem)
        {
            return Search(searchItem, current->lLink);
        }
        else
        {
            return Search(searchItem, current->rLink);
        }
    }
    return false;
}

//Recursive Insert
template <class elemType>
NodeType<elemType>* BST<elemType>::Insert(BSTNode* insertItem, BSTNode* current)
{
    if (current == nullptr)
    {
        current = insertItem;
    }
    else if (current->info > insertItem->info)
    {
        current->lLink = Insert(insertItem, current->lLink);
    }
    else
    {
        current->rLink = Insert(insertItem, current->rLink);
    }
    return current;
}

//Iterative Search
template <class elemType>
bool BST<elemType>::Search(const elemType& searchItem) const
{
    NodeType<elemType> * current;
    bool found = false;

    if (!root)
    {
        cout << "Binary Tree is empty!" << endl;
    }
    else
    {
        current = root;
        while(current && !found)
        {
            if(searchItem == current->info)
            {
                found = true;
            }
            else if(searchItem < current->info)
            {
                current = current -> lLink;
            }
            else
            {
                current = current -> rLink;
            }
        }
    }
    return found;
}

//Iterative Insert
template <class elemType>
void BST<elemType>::Insert(const elemType insertItem)
{
    NodeType<elemType> *current;
    NodeType<elemType> *trailCurrent = nullptr;
    NodeType<elemType> *newNode;

    newNode = new NodeType<elemType>;
    newNode->info = insertItem;
    newNode->lLink = nullptr;
    newNode->rLink = nullptr;

    if (!root)
    {
        root = newNode;
    }
    else
    {
        current = root;
        while (current)
        {
            trailCurrent = current;
            if(insertItem == current->info)
            {
                return;
            }
            else
            {
                if (insertItem < current->info)
                {
                    current = current->lLink;
                }
                else
                {
                    current = current->rLink;
                }
            }
        }
        if (insertItem < trailCurrent -> info)
        {
            trailCurrent->lLink = newNode;
        }
        else
        {
            trailCurrent->rLink = newNode;
        }
    }
}


#endif // BST_H
