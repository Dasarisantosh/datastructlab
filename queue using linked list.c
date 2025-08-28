#include <stdio.h>
#include <stdlib.h>   // for malloc

struct node
{
    int data;
    struct node *next;
};

struct queue
{
    struct node *front;
    struct node *rear;
};

// Function prototypes
void create_queue(struct queue *q);
struct queue *insert(struct queue *q, int val);
struct queue *delete_element(struct queue *q);
void display(struct queue *q);
int peek(struct queue *q);

int main()
{
    int val, option;
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    create_queue(q);

    do
    {
        printf("\n ***** MAIN MENU *****");
        printf("\n 1. INSERT");
        printf("\n 2. DELETE");
        printf("\n 3. PEEK");
        printf("\n 4. DISPLAY");
        printf("\n 5. EXIT");
        printf("\n Enter your option: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            printf("\n Enter value to insert: ");
            scanf("%d", &val);
            q = insert(q, val);
            break;
        case 2:
            q = delete_element(q);
            break;
        case 3:
            val = peek(q);
            if (val != -1)
                printf("\n Front element is: %d", val);
            break;
        case 4:
            display(q);
            break;
        case 5:
            printf("\n Exiting...");
            break;
        default:
            printf("\n Invalid option!");
        }
    } while (option != 5);

    return 0;
}

// Function to initialize queue
void create_queue(struct queue *q)
{
    q->front = q->rear = NULL;
}

// Function to insert element
struct queue *insert(struct queue *q, int val)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("\n Memory not available");
        return q;
    }
    ptr->data = val;
    ptr->next = NULL;

    if (q->front == NULL) // first element
    {
        q->front = q->rear = ptr;
    }
    else
    {
        q->rear->next = ptr;
        q->rear = ptr;
    }
    printf("\n %d inserted", val);
    return q;
}

// Function to delete element
struct queue *delete_element(struct queue *q)
{
    struct node *ptr;
    if (q->front == NULL)
    {
        printf("\n Queue is empty");
    }
    else
    {
        ptr = q->front;
        printf("\n Deleted element: %d", ptr->data);
        q->front = q->front->next;
        free(ptr);
        if (q->front == NULL) // if queue becomes empty
            q->rear = NULL;
    }
    return q;
}

// Function to display elements
void display(struct queue *q)
{
    struct node *ptr;
    if (q->front == NULL)
    {
        printf("\n Queue is empty");
    }
    else
    {
        printf("\n Queue elements are: ");
        ptr = q->front;
        while (ptr != NULL)
        {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
    }
}

// Function to peek (front element)
int peek(struct queue *q)
{
    if (q->front == NULL)
    {
        printf("\n Queue is empty");
        return -1;
    }
    else
    {
        return q->front->data;
    }
}

