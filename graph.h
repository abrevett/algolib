#ifndef GRAPH_H
#define GRAPH_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

#define MAXGRAPHV 10000
#define READBUF 4096

typedef unsigned long long uint64_t;

typedef struct __edgenode{
	uint64_t y;
	void* weight;
	struct __edgenode* next;
} edgenode;

typedef struct {
    edgenode **edges;
    uint64_t *degree;
    uint64_t nverts;
    uint64_t nedges;
    char directed;
} Graph;

void initGraph(Graph*, uint64_t, char);
void printGraph(Graph*);
void insertEdge(Graph*, uint64_t, uint64_t, void*, char);
void freeGraph(Graph*);
void freeEdgeNode(edgenode*);
/* Parses the file given to it as a directed graph
 Removed for general processing purposes
Graph* loadGraph(char*);
*/

#endif
