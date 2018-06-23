//
// Created by takezo on 3/26/18.
//
#include <stdlib.h>
#include <stdio.h>
#include "point.h"
#include "graph.h"


/**
 * Generating a new Graph, mallocing the needed space and setting attributes.
 * @param size
 * @return
 */
Graph* newGraph(u_int32_t size){

    //Malloc-ing Graph size.
    Graph* graph_ptr = (Graph*) malloc(sizeof(Graph));

    //WARNING this is not the size of the graph, but the size of the pointArray.
    //Number of Pixels = size * size.
    graph_ptr->size = size;

    //Complicated method of allocating 2 dimension array
    //WARNING The largest possible field in the two dimensional Array is always graph->pointArray[size-1][size-1].
    //Explanation: First allocating a Pointer to pointers times size. This is the first dimension of the array,
    //e.g the Array that contains the other arrays.
    graph_ptr->pointArray = ( Point** ) calloc( size , sizeof( Point ) );
    for(int i = 0; i < size; i++){
        //Allocating the other Arrays.
        graph_ptr->pointArray[i] = ( Point* ) calloc( size, sizeof( Point ) );
    }


    //TODO cleanup spaghetti code.
    //Fill the Graphs X and Y position to their corresponding numbers.
    for(u_int column = 0; column < graph_ptr->size; column++){
        for(u_int row = 0; row < graph_ptr->size; row++){

            //temporary pointer to the current Point
            Point* currentPoint = &graph_ptr->pointArray[row][column];

            //Fill column and y values with numbers, set r,g,b to 0
            currentPoint->x = column;
            currentPoint->y = row;
            currentPoint->r = 0;
            currentPoint-> g = 1;
            currentPoint->b = 2;

        }
    }

    //return the adress pointing to the graph
    return graph_ptr;

}

//WARNING Freeing multidimensional array. Tested with Valgrind Memcheck for memory leaks.
void deleteGraph(Graph * graph_ptr){
    //Dont do anything if the pointer is already NULL.
    if(graph_ptr == NULL){
        return;
    }

    //Work through the Pointer Array (* *)
    for(int i = 0; i < (int) graph_ptr->size; i++){
        //Free pointer pointing to first element of type Point, subsequentially deleting the array.
        deletePoint(graph_ptr->pointArray[i]);
    }

    //Set size to zero.
    graph_ptr->size = 0;
    //free the pointer pointing towards the first element of the pointer array.
    free(graph_ptr->pointArray);
    //free the graph
    free(graph_ptr);
}

//Todo cleanup
Point * getPoint(Graph * graph_ptr, int x, int y){
    if(x > graph_ptr->size - 1 || y > graph_ptr->size -1){
        return NULL;
    }else{
        return &graph_ptr->pointArray[y][x];
    }
}

//Print the graph
//Todo cleanup
void printGraph(Graph * graph_ptr){

    for(int column = 0; column < graph_ptr->size; column++){
        for(int row = 0; row < graph_ptr->size; row++){
            Point * currentPoint = &graph_ptr->pointArray[row][column];

            printf(" (%u,%u) ", currentPoint->x, currentPoint->y);

            if(currentPoint->y + 1 == graph_ptr->size){
                printf("\n");
            }


        }
    }
}


