#ifndef TREE_H
#define TREE_H

typedef struct __treenode{
    struct __treenode* left;
    struct __treenode* right;
    struct __treenode* parent;
    long long unsigned height;
    void* data;
} Tree;

void initTree( Tree**, void* );
void freeTree( Tree*, void (*dealloc)(void*) );
// Adding and deleting nodes
void addNodeTree( Tree*, Tree*, int (*compare)(Tree*, Tree*) );
void delNodeTree( Tree*, void*, void (*dealloc)(void*) );

// Mapping functions in different orders
void mapPreTree( Tree*, void (*mapf)(Tree*) );
void mapInTree( Tree*, void (*mapf)(Tree*) );
void mapPostTree( Tree*, void (*mapf)(Tree*) );

#endif //TREE_H
