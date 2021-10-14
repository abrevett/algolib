#include "tree.h"
void rotateLeft(Tree**);
void rotateRight(Tree**);
void balanceTree(Tree*);
int getBalanceTree(Tree*);
int heightMax(long long unsigned, long long unsigned);


// TODO: Make this function a general Tree node creator
/**
 * initTree:
 *  Creates a new Tree object. Since a non-null tree simplifies
 * the initialization and reduces the number of typedefs, it is
 * a better interface in general.
 */
void initTree( Tree** root, void* initData){
    // Initialize the tree's root node
    Tree* node = malloc( sizeof(Tree) );
    node->parent = node;
    node->left = NULL; node->right = NULL;
    node->height = 0;
    node->data = initData;
}

/**
 * freeTree:
 *  Frees the heap memory of the entire tree postorder.
 *
 * Args:
 *  Tree* tree: the tree that needs to be destroyed
 *  void dealloc(void*): A function used to free generic pointer object
 */
void freeTree(Tree* tree, void (*dealloc)(void* obj) ){
    if(!tree) return;
    freeTree( tree->left, dealloc );
    freeTree( tree->right, dealloc );

    dealloc(tree->data);
    free(tree);
}

/**
 * addNodeTree:
 *  Adds a leaf node to another tree. DO NOT USE FOR MERGING TREES
 *
 * Args:
 *  Tree* root: The tree to add a node to
 *  Tree* node: The node to append
 *  int compare(Tree*, Tree*)
 */
void addNodeTree(Tree* root, Tree* node, int (*compare)(Tree* a, Tree* b) ){
    int cmp = compare(node, root);
    long long unsigned height = root->height
    if(cmp < 0)
	if(height) addNodeTree( root->left, node, compare );
	else{
	    root->left = node;
	    node->parent = root;
	    // TODO: Add rotation bubble up here
	}
    else if(cmp > 0)
	if(height) addNodeTree( root->right, node, compare );
	else{
	    root->right = node;
	    node->parent = root;
	    // TODO: Add rotation bubble up here
	}
    else{
	freeTree(node);
	return; // TODO: add a return number for user feedback
    }

    root->height = heightMax( root->left->height, root->right->height) +1;
    balanceTree(root);
}

/*************************************************************

		    Mapping Functions

*************************************************************/

void mapPreTree( Tree* tree, void (*mapf)(Tree* node) ){
    if(!tree) return;

    mapf(tree);
    mapPreTree(tree->left, mapf);
    mapPreTree(tree->right, mapf);
}

void mapInTree( Tree* tree, void (*mapf)(Tree* node) ){
    if(!tree) return;

    mapInTree(tree->left, mapf);
    mapf(tree);
    mapInTree(tree->right, mapf);
}

void mapPostTree( Tree* tree, void (*mapf)(Tree* node) ){
    if(!tree) return;

    mapPostTree(tree->left, mapf);
    mapPostTree(tree->right, mapf);
    mapf(tree);
}

/*************************************************************
 
		    Helper Functions

*************************************************************/

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
