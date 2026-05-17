#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct node {
    int value;
    struct node* next;
} node;

typedef struct _nodeS {
    node* n;
    struct _nodeS *next;
} nodeS;

node* insa(int const v, node* l)
{
    node* tmp = (node*)malloc(sizeof(node)); //prostor v mem za nov struct
    tmp -> value = v;
    tmp -> next = l;
    return tmp;
}

node* append(int const v, node* l)
{
    if (l == NULL)
    {
        node* tmp = (node*)malloc(sizeof(node));
        tmp -> value = v;
        tmp -> next = l;
        return tmp;
    }
    l-> next = append(v, l -> next);
    return l;
}

node* deletea(node* l)
{
    node* tail = l->next;
    return tail;
}

node* swapPairs(node *l)
{
    if (l == NULL || l->next == NULL) return l;
    node* first = l;
    node* second = l->next;
    node* tail = l->next->next;

    l = first;
    l->next = second;
    tail = swapPairs(tail);
    l->next->next = tail;
    return l;
}

// ustvari nove nodes
node* swapPairs2(node* l)
{
    if (l == NULL) return l;
    if (l->next == NULL) return insa(l->value,NULL);
    node* first = l;
    node* second = l->next;
    node* tail = l->next->next;
    l = insa(second->value,NULL);
    l->next = insa(first->value,NULL);
    l->next->next = swapPairs2(tail);
    return l;
}

bool upperAddress(node* l)
{
    if (l == NULL || l->next == NULL) return true;
    if (l > l->next) return false;
    return upperAddress(l->next);
}

nodeS* storeAddress(node* l)
{
    if (l == NULL) return NULL;
    nodeS* ls = insaS(l, NULL);
    ls->next = storeAddress(l->next);
    return ls;
}

bool check(node* ll, nodeS* ls)
{
    if (ll == NULL) return true;
    return findS(ll,ls) && check(ll->next,ls);
}
/* Idea:
bool hasALoop(node* l)
{
    int len = 0;
    node* tmp = l;
    while (tmp != NULL)
    {
        len++;
        tmp = tmp->next;
    }

    nodeS* ls = NULL;

    for (int i = 0; i < len; i++)
        ls = insz(NULL,ls);

    nodeS* tmpS = ls;
    tmp = l;
    for (int i = 0; i < len; i++)
    {
        tmpS->n = tmp;
        tmpS = tmpS->next;
        tmp = tmp->next;
    }
}
*/

void destroyList(node* l)
{
    node* tmp = l;
    while(tmp->next != NULL)
    {
        node* next = tmp -> next;
        free(tmp);
        tmp = next;
    }

    //free the last element
    free(tmp);
}

int main(int argc, char *argv[])
{
    node* l = NULL;
    l = insa(7, l);
    l = insa(8, l);
    l = insa(9, l);
    destroyList(l);
    return 0;
}


