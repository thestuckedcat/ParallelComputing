#include <stdlib.h>
#include "malloc2D.h"

double **malloc2D(int jmax, int imax){
    // jmax represents number of rows(hang), imax represents number of coloumns
    double **x = (double **)malloc(jmax * sizeof(double *));

    x[0] =  (double *)malloc(imax * jmax * sizeof(double));

    for(int j = 1;j < jmax;j++){
        x[j] = x[j-1] + imax;
    }

    return x;

}