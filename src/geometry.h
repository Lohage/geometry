#ifndef GEOMETRY_H
#define GEOMETRY_H

typedef struct {
    double value[10];
    int type;
    double S, P;
} figure;

int input_figure(char* arr, figure* fig);
void SP_Triangle(figure* fig);
void SP_Circle(figure* fig);

#endif