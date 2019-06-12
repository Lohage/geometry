#include "geometry.h"
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SQR(x) (x) * (x)
#define PI 3.1416

int main()
{
    FILE* myfile;
    myfile = fopen("myfile.txt", "r");
    if (myfile == NULL) {
        printf("No file\n");
        return 1;
    }
    char arr[256];
    int j, i = 0;
    int c = 0;
    figure* fig = (figure*)malloc(sizeof(figure) * 100);
    while (!feof(myfile)) {
        arr[i] = fgetc(myfile);
        if (arr[i] == '\n') {
            arr[i] = '\0';
            for (j = 0; arr[j] != '\0'; j++) {
                printf("%c", arr[j]);
            }
            printf("\n");
            input_figure(arr, &fig[c]);
            i = -1;
            switch (fig[c].type) {
            case 1:
                SP_Triangle(&fig[c]);
                printf("Perimeter: %.3lf\n", fig[c].P);
                printf("Area: %.3lf\n", fig[c].S);
                printf("Intersects: (coming soon)\n");
                break;
            case 2:
                SP_Circle(&fig[c]);
                printf("Perimeter: %.3lf\n", fig[c].P);
                printf("Area: %.3lf\n", fig[c].S);
                printf("Intersects: (coming soon)\n");
                break;
            default:
                break;
            }
            c++;
        }
        i++;
    }
}