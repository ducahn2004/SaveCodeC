//https://www.hackerrank.com/challenges/dynamic-array/problem
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX_N_Q 100000

#define MAX_X_Y 1000000000

typedef struct link_list {
    int data;
    struct link_list *next;
}link_node, *link_listp;

typedef struct {
    link_listp head;
    int size;
}SEQUENCE;

link_listp insert_tail(link_listp head,link_listp new_node)
{

    if (head == NULL) {
        head = new_node;
    } else {
        link_listp temp = head;
        while(temp->next != NULL)
            temp = temp->next;

        new_node->next = NULL;
        temp->next = new_node;
    }

    return head;
}

void out_put_link__list(link_listp head) {
	link_listp temp = head;
    while(temp)	{
        printf("%d",temp->data);
        temp = temp->next;
        if (temp!=NULL)
            printf("\n");
    }
}

int main()
{
    int N, Q;
    int i = 0;
    int choice, x, y, index;
    int last_ans = 0;
    SEQUENCE *s = NULL;
    link_listp node, temp, output = NULL, out_node;

    /* input numbers of sequences */
    scanf("%d", &N);
    if (N < 1 || N > MAX_N_Q) {
        return 1;
    }
    /* input numbers of queries */
    scanf("%d", &Q);
    if (Q < 1 || Q > MAX_N_Q) {
        return 1;
    }

    s = malloc(sizeof(SEQUENCE)*N);
    if(s == NULL) {
        return 1;
    }

    memset(s, 0, sizeof(SEQUENCE)*N);

    do {
        scanf("%d", &choice);
        scanf("%d", &x);
        scanf("%d", &y);

        if (choice != 1 && choice != 2) {
            return 1;
        }

        if (x < 0 || x > MAX_X_Y) {
            return 1;
        }

        if (y < 0 || y > MAX_X_Y) {
            return 1;
        }

        switch(choice){
            case 1:
                index = (x^last_ans)%N;
                node = malloc(sizeof(link_node));
                if (node == NULL)
                    return 1;
                node->data = y;
                node->next = NULL;

                s[index].size ++;
                s[index].head = insert_tail(s[index].head, node);
                break;

            case 2:
                index = (x^last_ans)%N;
                y = y % (s[index].size);
                temp = s[index].head;

                while ( y > 0) {
                    temp = temp->next;
                    y--;
                }

                last_ans = temp->data;
                out_node = malloc(sizeof(link_node));
                out_node ->data = temp->data;
                output = insert_tail(output, out_node);
                break;

        }

        i++;

    }while (i < Q);

    if (output != NULL)
        out_put_link_list(output);

    return 0;
}