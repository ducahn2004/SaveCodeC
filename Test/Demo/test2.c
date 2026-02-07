#include <stdio.h>
#include <stdlib.h>

/* command node */
struct _command {
    int (*callback)(int);
    struct _command *next;
};

/* operations */
int add5(int a){ return a + 5; }
int sub4(int a){ return a - 4; }
int mul3(int a){ return a * 3; }
int div2(int a){ return a / 2; }

/* create empty list */
struct _command *initCommandList()
{
    return NULL;
}

/* insert at end, skip if already exists */
void insertCommand(struct _command **list, int (*callback)(int))
{
    struct _command *cur = *list;

    /* check duplicate */
    while (cur != NULL) {
        if (cur->callback == callback)
            return;
        cur = cur->next;
    }

    /* create new node */
    struct _command *node = malloc(sizeof(struct _command));
    node->callback = callback;
    node->next = NULL;

    /* insert */
    if (*list == NULL) {
        *list = node;
        return;
    }

    cur = *list;
    while (cur->next != NULL)
        cur = cur->next;

    cur->next = node;
}

/* execute commands in order */
int calculate(int a, struct _command *orderOfFunctions)
{
    struct _command *cur = orderOfFunctions;

    while (cur != NULL) {
        a = cur->callback(a);
        cur = cur->next;
    }
    return a;
}

/* example */
int main()
{
    struct _command *orderOfFunctions = initCommandList();

    insertCommand(&orderOfFunctions, add5);
    insertCommand(&orderOfFunctions, sub4);
    insertCommand(&orderOfFunctions, mul3);
    insertCommand(&orderOfFunctions, div2);

    int result = calculate(10, orderOfFunctions);
    printf("%d\n", result);   // (((10+5)-4)*3)/2 = 16

    return 0;
}
