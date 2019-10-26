#ifndef LinkedList_h
#define LinkedList_h
#include "bool.h"

typedef struct LinkedList LinkedList;
typedef struct Node Node;
LinkedList *lstCreate();
void lstFree(LinkedList *l);
void lstInsert (LinkedList *l, unsigned long v);
bool lstRemove (LinkedList *l, unsigned long v);
bool lstIsEmpty(LinkedList *l);
void lstPrint (LinkedList *l);

#endif
