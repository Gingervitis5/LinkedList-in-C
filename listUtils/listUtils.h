#ifndef LISTUTILS_H
#define LISTUTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../linkedList/linkedList.h"

#define MAX 100

Node * buildNode(FILE * in, void *(*buildData)(FILE * in) );
void sort(LinkedList * theList, int (*compare)(const void *, const void *));

/**
 * Builds the list by calling addLast
 */
void buildList(LinkedList * myList, FILE * fin, int total, void * (*buildData)(FILE * in));

#endif // LISTUTILS_H
