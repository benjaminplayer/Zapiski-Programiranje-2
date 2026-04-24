#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int value;
    struct node* next;
} node;

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


