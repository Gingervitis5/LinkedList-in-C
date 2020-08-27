#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "requiredIncludes.h"

struct node
{
    void * data;
    struct node * next;
};
typedef struct node Node;


struct linkedlist
{
    Node * head;
    int size;
};
typedef struct linkedlist LinkedList;


LinkedList * linkedList();

void addLast(LinkedList * theList, Node * nn);
void addFirst(LinkedList * theList, Node * nn);

void removeLast(LinkedList * theList, void (*removeData)(void *));
void removeItem(LinkedList * theList, Node * nn, void (*removeData)(void *), int (*compare)(const void *, const void *));

void clearList(LinkedList * theList, void (*removeData)(void *));
void printList(const LinkedList * theList, void (*convertData)(void *));

LinkedList * cleanList(LinkedList * theList, void (*removeData)(void *));

#endif // LINKEDLIST_H
