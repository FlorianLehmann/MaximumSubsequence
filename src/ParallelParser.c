//
// Created by Florian Lehmann on 03/04/2018.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>
#include <string.h>
#include "ParallelParser.h"

const char * readFirstLine(const char * filepath, unsigned int * size) {
    FILE * file = fopen(filepath, "r");
    char * line = NULL;
    size_t linesiz = 0;

    *size = (unsigned int) getline(&line, &linesiz, file);

    fclose(file);
    return line;
}

int extractIntegerFromFile(int * values, char * line) {
    unsigned int nbElements=0;

    char *value = strtok(line," ");
    values[nbElements] = atoi(value);

    while (value != NULL)
    {
        values[nbElements++] = atoi(value);
        value = strtok (NULL, " ");
    }
    return nbElements;

}