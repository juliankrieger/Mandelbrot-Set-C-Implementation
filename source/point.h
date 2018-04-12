//
// Created by takezo on 3/25/18.
//

#ifndef UNTITLED01_POINT_H
#define UNTITLED01_POINT_H



struct point_t{
    u_int32_t x;
    u_int32_t y;

    u_char r;
    u_char g;
    u_char b;

};

typedef struct point_t Point;

Point* newPoint(u_int32_t x, u_int32_t y);

void deletePoint(Point * point_ptr);

int printPoint(Point * point_ptr);

int movePoint(Point * point_ptr, int32_t x_axis, int32_t y_axis);

int upScalePoint(Point * point_ptr, u_int32_t x_scale, u_int32_t y_scale);

int colorPoint(Point * point_ptr, u_char r, u_char g, u_char b);


#endif //UNTITLED01_POINT_H
