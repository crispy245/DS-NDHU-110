#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

struct Node
{
    int data;
    struct Node *pre, *next;
};

void swap(Node *a, Node *b)
{
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}
void bubbleSort(struct Node **head)
{
    if (*head == NULL)
    {
        return;
    }
    int swapped;
    do
    {
        swapped = 0;
        Node *travelingNode = *(head);
        while (travelingNode->next != NULL)
        {
            if (travelingNode->data > travelingNode->next->data)
            {
                swap(travelingNode, travelingNode->next);
                swapped++;
            }
            travelingNode = travelingNode->next;
        }
    } while (swapped);
}

void selectionSort(struct Node **head)
{
    if (head == NULL)
    {
        return;
    }

    Node *travelingNode = *(head);
    while (travelingNode)
    {
        Node *min = travelingNode;
        Node *right = travelingNode->next;
        while (right)
        {
            if (min->data > right->data)
            {
                min = right;
            }
            right = right->next;
        }
        swap(travelingNode, min);
        travelingNode = travelingNode->next;
    }
}

void insertionSort(struct Node **head)
{
    if ((*head) == NULL || (*head)->next == NULL)
    {
        return;
    }
    Node *sorted = *head;
    sorted = sorted->next;
    while (sorted != NULL)
    {
        int sec_data = sorted->data;
        int found = 0;
        Node *travelingNode = *head;
        while (travelingNode != sorted)
        {
            if (travelingNode->data > sorted->data && found == 0)
            {
                sec_data = travelingNode->data;
                travelingNode->data = sorted->data;
                found = 1;
                travelingNode = travelingNode->next;
            }
            else
            {
                if (found == 1)
                {
                    int temp = sec_data;
                    sec_data = travelingNode->data;
                    travelingNode->data = temp;
                }
                travelingNode = travelingNode->next;
            }
        }
        travelingNode->data = sec_data;
        sorted = sorted->next;
    }
}

int main()
{
    int j;
    struct Node *head, *buf, *cur;

    srand(time(NULL));

    head = NULL;
    for (j = 0; j < SIZE; j++)
    {
        buf = (struct Node *)malloc(sizeof(struct Node));
        buf->data = rand() % 10;
        buf->next = head;
        buf->pre = NULL;
        if (head != NULL)
            head->pre = buf;
        head = buf;
    }

    cur = head;
    while (cur != NULL)
    {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");

    bubbleSort(&head);

    cur = head;
    while (cur != NULL)
    {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");

    head = NULL;
    for (j = 0; j < SIZE; j++)
    {
        buf = (struct Node *)malloc(sizeof(struct Node));
        buf->data = rand() % 10;
        buf->next = head;
        buf->pre = NULL;
        if (head != NULL)
            head->pre = buf;
        head = buf;
    }

    cur = head;
    while (cur != NULL)
    {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");

    selectionSort(&head);

    cur = head;
    while (cur != NULL)
    {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");

    head = NULL;
    for (j = 0; j < SIZE; j++)
    {
        buf = (struct Node *)malloc(sizeof(struct Node));
        buf->data = rand() % 10;
        buf->next = head;
        buf->pre = NULL;
        if (head != NULL)
            head->pre = buf;
        head = buf;
    }

    cur = head;
    while (cur != NULL)
    {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");

    insertionSort(&head);

    cur = head;
    while (cur != NULL)
    {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}
