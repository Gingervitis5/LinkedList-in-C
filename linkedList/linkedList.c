#include "linkedList.h"
#include "requiredIncludes.h"
#include "../listUtils/listUtils.h"

void addLast(LinkedList * theList, Node * nn){
    Node *cur = theList->head;
    if (theList->size <= 0) {
        theList->head = nn;
        theList->size = theList->size+1;
    }
    else {
        while(cur->next != NULL){
            cur = cur->next;
        }
        cur->next = nn;
        theList->size = theList->size+1;
    }
}

LinkedList * linkedList(){
    LinkedList * newList = (LinkedList *)calloc(1, sizeof(LinkedList));
    newList->head = NULL; newList->size = 0;
    return newList;
}

void addFirst(LinkedList * theList, Node * nn){
    nn->next = theList->head;
    theList->head = nn;
    theList->size = theList->size + 1;
}

void removeLast(LinkedList * theList, void (*removeData)(void *)){
    Node *cur = theList->head, *temp;
    if (theList->size > 0){
        while (cur->next != NULL){
            temp = cur;
            cur = cur->next;
        }
        removeData(cur->data);
        temp->next = NULL;
        theList->size = theList->size - 1;
       free(cur); cur = NULL;
    }
    else {
        printf("Empty List. Nothing to remove.\n\n");
    }
}

void removeItem(LinkedList * theList, Node * nn, void (*removeData)(void *), int (*compare)(const void *, const void *)){
    Node *cur = theList->head, *prev = NULL;
    Word *delete = (Word *)(nn->data); int deleted = 0;
    if (theList->size <= 0){
        printf("\nEmpty List. Nothing to remove.\n\n");
    }
    else{
        while (cur != NULL){
            if (compare(cur->data, delete) == 0){
                if (prev == NULL){
                    removeData(cur->data);
                    theList->head = cur->next;
                    free(cur); cur = NULL;
                    theList->size = theList->size-1; deleted++;
                }
                else {
                    removeData(cur->data);
                    prev->next = cur->next;
                    free(cur); cur = NULL;
                    theList->size = theList->size-1; deleted++;
                }
            }
            else {
                prev = cur;
                cur = cur->next;
            }
        }
        if (deleted <= 0){
            printf("Word not found in list.\n\n");
        }
    }
    cleanTypeWord(delete); free(nn);
}

void clearList(LinkedList * theList, void (*removeData)(void *)){
    if (theList->head != NULL) {
        Node *cur = theList->head;
        Node *temp;
        while (cur != NULL) {
            temp = cur;
            cur = cur->next;
            removeData(temp->data);
            temp->next = NULL;
            free(temp);
        }
        theList->head = NULL;
        theList->size = 0;
        free(cur);
    }
    printf("\n");
}

void printList(const LinkedList * theList, void (*convertData)(void *)){
    Node *cur = theList->head;
    printf("\n");
    if (theList->head == NULL){
        printf("Empty List");
    }
    else{
        while (cur != NULL){
            convertData(cur->data);
            cur = cur->next;
        }
    }
    printf("\n");
    free(cur);
}

LinkedList * cleanList(LinkedList * theList, void (*removeData)(void *)){
    clearList(theList, removeData);
    free(theList->head); theList->head = NULL;
    free(theList);
    return NULL;
}