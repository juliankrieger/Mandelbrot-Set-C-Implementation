//
// Created by takezo on 3/26/18.
//

#ifndef UNTITLED01_GRAPH_H
#define UNTITLED01_GRAPH_H

#include <zconf.h>
#include "point.h"

struct graph_t{

    Point** pointArray;
    size_t size;
};

typedef struct graph_t Graph;

Graph* newGraph(u_int32_t size);

void deleteGraph(Graph * graph_ptr);

Point* getPoint(Graph* graph_ptr, int x, int y);

void printGraph(Graph * graph_ptr);




#endif //UNTITLED01_GRAPH_H
