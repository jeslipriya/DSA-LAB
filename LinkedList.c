#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node *link;
};

struct node *head = NULL;

// Insert at beginning
void insert_at_front(int value) 
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->link = head;
    head = newnode;
}

// Insert at end
void insert_at_end(int value) 
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->link = NULL;

    if (head == NULL) 
    {
        head = newnode;
    } 
    else 
    {
        struct node *temp = head;
        while (temp->link != NULL) 
        {
            temp = temp->link;
        }
        temp->link = newnode;
    }
}

// Insert after a given key
void insert_after(int key, int value) 
{
    struct node *temp = head;
    while (temp != NULL && temp->data != key) 
    {
        temp = temp->link;
    }

    if (temp == NULL) 
    {
        printf("Node with value %d not found.\n", key);
        return;
    }

    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->link = temp->link;
    temp->link = newnode;
}

// Delete node
void delete_node(int value) 
{
    struct node *temp = head, *prev = NULL;

    if (temp != NULL && temp->data == value) 
    {
        head = temp->link;
        free(temp);
        printf("Node with value %d deleted.\n", value);
        return;
    }

    while (temp != NULL && temp->data != value) 
    {
        prev = temp;
        temp = temp->link;
    }

    if (temp == NULL)   
    {
        printf("Node with value %d not found.\n", value);
        return;
    }

    prev->link = temp->link;
    free(temp);
    printf("Node with value %d deleted.\n", value);
}

// Display list
void display() 
{
    struct node *temp = head;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Linked List: ");
    while (temp != NULL) 
    {
        printf("%d -> ", temp->data);
        temp = temp->link;
    }
    printf("NULL\n");
}

int main() 
{
    int choice, value, key;

    while (1) 
    {
        printf("\n--- Singly Linked List Menu ---\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert after a node\n");
        printf("4. Delete a node\n");
        printf("5. Display list\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
        case 1:
            printf("Enter value to insert at beginning: ");
            scanf("%d", &value);
            insert_at_front(value);
            break;
        case 2:
            printf("Enter value to insert at end: ");
            scanf("%d", &value);
            insert_at_end(value);
            break;
        case 3:
            printf("Enter key after which to insert: ");
            scanf("%d", &key);
            printf("Enter value to insert: ");
            scanf("%d", &value);
            insert_after(key, value);
            break;
        case 4:
            printf("Enter value to delete: ");
            scanf("%d", &value);
            delete_node(value);
            break;
        case 5:
            display();
            break;
        case 6:
            printf("Exiting program.\n");
            exit(0);
        default:
            printf("Invalid choice. Try again.\n");
        }
    }
}
