#include "listUtils.h"
#include "../linkedList/linkedList.h"
#include "../linkedList/requiredIncludes.h"
#include "../words/word.h"


Node * buildNode(FILE * in, void *(*buildData)(FILE * in) ){
    Node * node = (Node *)calloc(1, sizeof(Node));
    node->data = buildData(in);
    node->next = NULL;
    return node;
}

void sort(LinkedList * theList, int (*compare)(const void *, const void *)){
    Node *search = NULL, *min = NULL, *start = NULL;
    void *temp;
    for (start = theList->head; start->next != NULL; start = start->next){
        min = start;
        for (search = start->next; search != NULL; search = search->next){
            if (compare(search->data, min->data) < 0){
                min = search;
            }
        }
        temp = start->data;
        start->data = min->data;
        min->data = temp;
    }
    //free(search); free(start); free(min);
}

/**
 * Builds the list by calling addLast
 */
void buildList(LinkedList * myList, FILE * fin, int total, void * (*buildData)(FILE * in)){
    int x = 0;
    Node * node;
    for (x; x < total; x++){
        node = buildNode(fin, buildData);
        addLast(myList, node);
    }
}