//
// Created by takezo on 3/27/18.
//

#include <stdio.h>
#include "ppmWriter.h"
#include "graph.h"

//Portable PixMap Magic Number in Binary (0-255, RGB)
#define NETPBM_FILE_HEADER "P6"

/**
 * Write a given Graph to the file given with the filename.
 * PPM is a simple image format, specifications at https://en.wikipedia.org/wiki/Netpbm_format
 * @param filename
 * @param graph
 * @return
 */
int writePPM(char * filename, Graph* graph){
    if(filename == NULL || graph == NULL){
        return 0;
    }

    const int height = (int) graph->size;
    const int width = (int) graph->size;

    FILE * file = fopen(filename, "wb");

    (void) fprintf(file, "%s\n%d %d\n255\n", NETPBM_FILE_HEADER, height, width);


    for(int i = 0; i < graph->size; i++){
        for(int j = 0; j < graph->size; j++){

            static unsigned char color[3];

            color[0] = graph->pointArray[i][j].r;
            color[1] = graph->pointArray[i][j].g;
            color[2] = graph->pointArray[i][j].b;

            (void) fwrite(color, 1 ,3 , file);
        }
    }

    (void)fclose(file);

    return 1;
}
