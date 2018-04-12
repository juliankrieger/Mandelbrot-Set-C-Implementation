//
// Created by takezo on 3/25/18.
//

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "point.h"


/**
 * Returns pointer to a new Point object.
 * @param x
 * @param y
 * @return Success Code
 */
Point* newPoint(u_int32_t x, u_int32_t y){
    Point* point_ptr = (Point*) malloc(sizeof(Point));
    point_ptr->x = x;
    point_ptr->y = y;
    return point_ptr;

}

/**
 * Free the memory space allocated by the given point object.
 * @param point
 * @return Success Code
 */
void deletePoint(Point * point_ptr){
     free(point_ptr);
}

/**
 * Print Point
 * @param point
 * @return Success Code
 */
int printPoint(Point* point_ptr){
    if(point_ptr == NULL){
        return 0;
    }else{
        printf("X:%i\nY:%i\n",point_ptr->x,point_ptr->y);
        return 1;
    }

}

/**
 * Moving to point in x or y direction.
 * //WARNING: Point's x and y parameters turn zero if x_axis and y_axis are too big
 * @param point
 * @param x_axis
 * @param y_axis
 * @return
 */
int movePoint(Point* point_ptr, int32_t x_axis, int32_t y_axis){
    if(point_ptr == NULL){
        return 0;
    }
    point_ptr->x+=x_axis;
    point_ptr->y+=y_axis;

    return 1;
}

/**
 * Upscale a point. Check if the finished multiplication is above unt32_max first.
 * @param point_ptr
 * @param x_scale
 * @param y_scale
 * @return Sucess Code.
 */
int upScalePoint(Point *point_ptr, u_int32_t x_scale, u_int32_t y_scale){
    if(point_ptr == NULL) {
        return 0;

    }else if(point_ptr->x * x_scale > UINT32_MAX || point_ptr->y * y_scale > UINT32_MAX){
        return 0;
    }else{
        point_ptr->x*=x_scale;
        point_ptr->y*=y_scale;
        return 1;
    }


}

/**
 * Color a point with an rgb value.
 * @param point_ptr
 * @param r
 * @param g
 * @param b
 * @return
 */
int colorPoint(Point *point_ptr, u_char r, u_char g, u_char b){
    if(point_ptr == NULL){
        return 0;
    }else{
        point_ptr->r = r;
        point_ptr->g = g;
        point_ptr->b = b;
        return 1;
    }
}
