#include <iostream>
using namespace std;

/**
 * Base struct for a node of the BST
 * has two children, left and right (l and r)
 * l and r are pointers to other Nodes
 * has int value
 */
struct Node{
    int val;
    Node* r;
    Node* l;
};

/**
 * Generates and returns a new node with value v and no children
 */
Node* newNode(int v){
    Node* n = new Node;
    n->val = v;
    n->r = n->l = NULL;
    return n;
}

/**
 * Returns bool of if node has children by checking if l or r are null pointers
 */
bool hasChildren(Node* root){
    return (root->l != NULL && root->r != NULL);
}

/**
 * Helper function that prints out all the children of the tree recursively
 * Prints out the node value, the node's l value, the node's r value
 * Recurses to the left
 * Recurses to the right
 */
bool printChildren(Node* root){
    cout << "node: " << root->val;
    if(root->l != NULL){
        cout << ", left child: " << root->l->val;
    }
    if(root->r != NULL){
        cout << ", right child: " << root->r->val;
    }
    cout << endl;
    if(root->l != NULL){
        printChildren(root->l);
    }
    if(root->r != NULL){
        printChildren(root->r);
    }
}

/**
 * Inserts a new node with value v at an appropriate point in the tree
 * Recursively searches for the spot at which to insert the new node
 * If v > the current node's value, check if there is a right node
 *      if not, insert
 *      if so, recurse
 * If v < the current node's value, cehck if there is a left node
 *      if not, insert
 *      if so, recurse
 */
void insert(int v, Node* root){
    if(v > root->val){
        if(root->r == NULL){
            Node* n = newNode(v);
            root->r = n;
        }
        else{
            return(insert(v, root->r));
        }
    }
    else{
        if(root->l == NULL){
            Node* n = newNode(v);
            root->l = n;
        }
        else{
            return(insert(v, root->l));
        }
    }
}

/**
 * Searches the tree for node with value v
 * If current node is v, return current node
 * If v > current node,
 *      If right node doesn't exist, return NULL
 *      else, recurse right
 * if v < current node,
 *      if left node doesn't exist, return NULL
 *      else, recurse left
 */
Node* search(Node* root, int v){
    if(root->val == v){
        return root;
    }
    else if(v > root->val){
        if(root->r == NULL){
            cout << "DNE" << endl;
            return NULL;
        }
        search(root->r, v);
    }
    else{
        if(root->l == NULL){
            cout << "DNE" << endl;
            return NULL;
        }
        search(root->l, v);
    }
}

/**
 * Finds the minimum value in the tree by recursing left until the leftmost leaf
 * is found
 */
Node* findMin(Node* root){
    if(root->l != NULL){
        return(findMin(root->l));
    }
    return root;
}

/**
 * Finds the maximum value in the tree by recursing right until the rightmost leaf
 * is found
 */
Node* findMax(Node* root){
    if(root->r != NULL){
        return(findMax(root->r));
    }
    return root;
}

/**
 * Prints all of the node values in order
 * Recurses left if there is a left child
 * Prints current node value
 * Recurses right if there is a right child
 */
void inOrder(Node* root){
    if(root->l != NULL){
        inOrder(root->l);
    }
    cout << root->val << " ";
    if(root->r != NULL){
        inOrder(root->r);
    }
}

/**
 * Prints all values of the tree in reverse
 * Recurses right if there is a right child
 * Prints current node value
 * Recurses left if there is a left child
 */
void preOrder(Node* root){
    if(root->r != NULL){
        preOrder(root->r);
    }
    cout << root->val << " ";
    if(root->l != NULL){
        preOrder(root->l);
    }
}

/**
 * Finds the next highest value in the tree
 * Moves to the right child, the finds the minimum value of that subtree
 */
Node* successor(Node* root){
    root = root->r;
    return findMin(root);
}

/**
 * Finds the next lowest value in the tree
 * Moves to left child, then finds the maximum value of that subtree
 */
Node* predecessor(Node* root){
    root = root->l;
    return findMax(root);
}

/** WORK IN PROGRESS -- PROBLEM: Returns balanced when unbalanced
 * Returns if tree is balanced or not
 * Checks if root has children -- if so, returns true
 * Checks if l exists
 *      if not, checks if r has children; if not, return true; if so, return false
 * Checks if r exists
 *      if not, checks if l has children; if not, return true; if so, return false
 * If both exists, checks if both have no children; if so, return true
 * If both have childre, checks if both are balanced recursively; if so, return true
 * Else, return false
 */
bool isBalanced(Node* root){
    if(!hasChildren(root)){
        return true;
    }
    else if(root->l == NULL){
        if(!hasChildren(root->r)){
            return true;
        }
        return false;
    }
    else if(root->r == NULL){
        if(!hasChildren(root->l)){
            return true;
        }
        return false;
    }
    else if(!hasChildren(root->l) && !hasChildren(root->r)){
        return true;
    }
    else if(isBalanced(root->l) && isBalanced(root->r)){
        return true;
    }
    return false;
}