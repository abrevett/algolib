#include "tree.h"
void rotateLeft(Tree**);
void rotateRight(Tree**);
void balanceTree(Tree*);
int getBalanceTree(Tree*);
int heightMax(long long unsigned, long long unsigned);

void initTree( Tree** root, void* initData){
    // Initialize the tree's root node
    Tree* node = malloc( sizeof(Tree) );
    node->parent = node;
    node->left = NULL; node->right = NULL;
    node->height = 0;
    node->data = initData;
}

void freeTree(Tree* tree, void (*dealloc)(void* obj) ){
    if(!tree) return;
    freeTree( tree->left, dealloc );
    freeTree( tree->right, dealloc );

    dealloc(tree->data);
    free(tree);
}

void addNodeTree(Tree* root, Tree* node, int (*compare)(Tree* a, Tree* b) ){
    int cmp = compare(node, root);
    if(cmp < 0)
	if(height) addNodeTree( root->left, node, compare );
	else{
	    root->left = node;
	    node->parent = root;
	}
    else if(cmp > 0)
	if(height) addNodeTree( root->right, node, compare );
	else{
	    root->right = node;
	    node->parent = root;
	}
    else{
	freeTree(node);
	return; // TODO: add a return number for user feedback
    }

    root->height = heightMax( root->left->height, root->right->height) +1;
    balanceTree(root);
}

/**
 * Helper functions
 */

int heightMax(long long unsigned h1, long long unsigned h2){
    return (h1 < h2) ? h2 : h1;
}

void balanceTree(Tree* tree){
    int cmp = getBalanceTree(tree);
    if(cmp > 1){
	cmp = getBalanceTree(tree->right);
	if(cmp < 0)
	    rotateRight(&tree->right);
	rotateLeft(&tree);
    }
    else if(cmp < -1){
	cmp = getBalanceTree(tree->left);
	if(cmp > 0)
	    rotateLeft(&tree->left);
	rotateRight(&tree);
    }
}

int getBalanceTree(Tree* tree){
    long long unsigned lefth=0, righth=0;
    if(tree->left) lefth = tree->left->height;
    if(tree->right) righth = tree->right->height;

    return (int)(lefth - righth);
}

void rotateLeft(Tree** tree){
    Tree* newroot = tree->right;
}

void rotateRight(Tree** tree){
}
