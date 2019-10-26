#include "LinkedList.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct LinkedList{
	Node *head;
    Node *last;
}LinkedList;

typedef struct Node{
	unsigned long data;
	Node *next;
    Node *previous;
}Node;

LinkedList *lstCreate(){
	LinkedList *l = (LinkedList*) malloc(sizeof(LinkedList));
	l->head = NULL;
    l->last = NULL;
	return l;
}

void lstFree(LinkedList *l){

	Node *p = l->head;

	while(p!=NULL){
        Node *t = p->next;
        free (p);
        p = t;
	}

	free (l);
}

void lstInsert (LinkedList *l, unsigned long v){
	Node *new = (Node*) malloc( sizeof(Node) );

    new->data = v;
	new->next = NULL;
    
    if(lstIsEmpty(l)){  //Lista vazia
        new->next = l->last;
        new->previous = l->head;
        l->head = new;
        l->last = new;
    }
    else{
        new->previous = l->last;
        l->last->next = new;
        l->last = new;
    }
}

bool lstRemove (LinkedList *l, unsigned long v){
	Node *ant = NULL;
	Node *per = l->head;

	while (per != NULL && per->data != v) {
		ant = per;
	    per = per->next;
	}

	if (per != NULL){
        if (ant == NULL) {
            l->head = per->next;
        }
        else{
            ant->next = per->next;
        }
		free (per);
        return TRUE;
	}

    return FALSE;
}

bool lstIsEmpty(LinkedList *l){
	if (l->head == NULL)
		return TRUE;
	else
		return FALSE;
}

void lstPrint (LinkedList *l){

	for (Node *aux = l->head; aux != NULL; aux = aux->next)
		printf ("%lu ", aux->data);
}