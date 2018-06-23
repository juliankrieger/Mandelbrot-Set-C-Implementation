#include <stdio.h>
#include <stdlib.h>
#include <zconf.h>
#include <time.h>
#include "point.h"
#include "graph.h"
#include "ppmWriter.h"
#include "mandelbrot.h"


int main(int argc, const char* argv[]) {

    if(argc == 2){
        const char * progname = argv[0];
        const char * filename = argv[1];

        Graph* graph = newGraph(3000);




        srand(time(NULL));

        colorMandel(graph);

        //for(int i = 0; i < graph->size; i++){
        //    for(int j = 0; j < graph->size; j++){
        //        colorPoint(getPoint(graph, i, j), (u_char)(rand() % 256), (u_char)(rand() % 256), (u_char)(rand() % 256));
        //    }
        //}


        writePPM(filename, graph);

        deleteGraph(graph);


    }
    return 0;


}