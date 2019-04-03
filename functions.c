#include "geometry.h"
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SQR(x) (x) * (x)
#define PI 3.1416

int input_figure(char* arr, figure* fig)
{
    char* end;
    char buf[100];
    int i = 0;
    while (arr[i] >= 'a' && arr[i] <= 'z') {
        buf[i] = arr[i];
        i++;
    }
    buf[i] = '\0';
    if (!(strcmp(buf, "triangle"))) {
        fig->type = 1;
    } else if (!(strcmp(buf, "circle"))) {
        fig->type = 2;
    } else {
        printf("error\n");
        return 1;
    }
    end = arr;
    i = 0;
    while (*arr) {
        while (!(isdigit(*arr) || *arr == '-') && *arr) {
            arr++;
        }
        fig->value[i] = strtod(arr, &end);
        arr = end;
        i++;
    }
    return 0;
}

void SP_Triangle(figure* fig)
{
    double a, b, c, p;
    a
            = sqrt(SQR(fig->value[2] - fig->value[0])
                   + SQR(fig->value[3] - fig->value[1]));
    b
            = sqrt(SQR(fig->value[4] - fig->value[2])
                   + SQR(fig->value[5] - fig->value[3]));
    c
            = sqrt(SQR(fig->value[0] - fig->value[4])
                   + SQR(fig->value[1] - fig->value[5]));
    fig->P = a + b + c;
    p = fig->P / 2;
    fig->S = sqrt(p * (p - a) * (p - b) * (p - c));
}

void SP_Circle(figure* fig)
{
    fig->P = 2 * PI * fig->value[2];
    fig->S = PI * SQR(fig->value[2]);
}