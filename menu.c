#include <stdio.h>
#include <stdlib.h>

struct dlist
{
    int data;
    struct dlist *prev;
    struct dlist *next;
};

struct dlist *header = NULL;

void create()
{
    int n, i;
    struct dlist *node, *temp;

    printf("\nHow many nodes do you want to create? ");
    if (scanf("%d", &n) != 1 || n < 0)
    {
        printf("\nInvalid input");
        return;
    }

    for (i = 0; i < n; i++)
    {
        node = (struct dlist *)malloc(sizeof(struct dlist));

        if (node == NULL)
        {
            printf("\nMemory allocation failed");
            return;
        }

        printf("\nEnter node %d: ", i + 1);

        if (scanf("%d", &node->data) != 1)
        {
            free(node);
            printf("\nInvalid input");
            return;
        }

        node->next = NULL;
        node->prev = NULL;

        if (header == NULL)
        {
            header = node;
        }
        else
        {
            temp = header;

            while (temp->next != NULL)
                temp = temp->next;

            temp->next = node;
            node->prev = temp;
        }
    }

    printf("\nList created successfully\n");
}

void insertatbegin()
{
    struct dlist *node;

    node = (struct dlist *)malloc(sizeof(struct dlist));

    if (node == NULL)
    {
        printf("\nMemory allocation failed");
        return;
    }

    printf("\nEnter node: ");

    if (scanf("%d", &node->data) != 1)
    {
        free(node);
        printf("\nInvalid input");
        return;
    }

    node->prev = NULL;
    node->next = header;

    if (header != NULL)
        header->prev = node;

    header = node;

    printf("\nNode inserted successfully");
}

void insertatend()
{
    struct dlist *node, *temp;

    node = (struct dlist *)malloc(sizeof(struct dlist));

    if (node == NULL)
    {
        printf("\nMemory allocation failed");
        return;
    }

    printf("\nEnter node: ");

    if (scanf("%d", &node->data) != 1)
    {
        free(node);
        printf("\nInvalid input");
        return;
    }

    node->next = NULL;

    if (header == NULL)
    {
        node->prev = NULL;
        header = node;
        printf("\nNode inserted successfully");
        return;
    }

    temp = header;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = node;
    node->prev = temp;

    printf("\nNode inserted successfully");
}

void insertatmid()
{
    struct dlist *node, *temp;
    int pos, i;

    printf("\nEnter position: ");

    if (scanf("%d", &pos) != 1 || pos < 1)
    {
        printf("\nInvalid position");
        return;
    }

    if (pos == 1)
    {
        insertatbegin();
        return;
    }

    temp = header;

    for (i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL)
    {
        printf("\nInvalid position");
        return;
    }

    node = (struct dlist *)malloc(sizeof(struct dlist));

    if (node == NULL)
    {
        printf("\nMemory allocation failed");
        return;
    }

    printf("\nEnter node: ");

    if (scanf("%d", &node->data) != 1)
    {
        free(node);
        printf("\nInvalid input");
        return;
    }

    node->prev = temp;
    node->next = temp->next;

    if (temp->next != NULL)
        temp->next->prev = node;

    temp->next = node;

    printf("\nNode inserted successfully");
}

void deleteatbegin()
{
    struct dlist *node;

    if (header == NULL)
    {
        printf("\nList empty");
        return;
    }

    node = header;
    header = header->next;

    if (header != NULL)
        header->prev = NULL;

    free(node);

    printf("\nNode deleted successfully");
}

void deleteatend()
{
    struct dlist *temp;

    if (header == NULL)
    {
        printf("\nList empty");
        return;
    }

    temp = header;

    if (header->next == NULL)
    {
        free(header);
        header = NULL;

        printf("\nNode deleted successfully");
        return;
    }

    while (temp->next != NULL)
        temp = temp->next;

    temp->prev->next = NULL;

    free(temp);

    printf("\nNode deleted successfully");
}

void deleteatmid()
{
    struct dlist *temp;
    int pos, i;

    printf("\nEnter position: ");

    if (scanf("%d", &pos) != 1 || pos < 1)
    {
        printf("\nInvalid position");
        return;
    }

    if (header == NULL)
    {
        printf("\nList empty");
        return;
    }

    temp = header;

    for (i = 1; i < pos && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL)
    {
        printf("\nInvalid position");
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        header = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);

    printf("\nNode deleted successfully");
}

void displayforward()
{
    struct dlist *temp;

    if (header == NULL)
    {
        printf("\nList empty");
        return;
    }

    temp = header;

    printf("\nForward: ");

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

void displaybackward()
{
    struct dlist *temp;

    if (header == NULL)
    {
        printf("\nList empty");
        return;
    }

    temp = header;

    while (temp->next != NULL)
        temp = temp->next;

    printf("\nBackward: ");

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->prev;
    }

    printf("\n");
}

void clearlist()
{
    struct dlist *temp;

    while (header != NULL)
    {
        temp = header;
        header = header->next;
        free(temp);
    }
}

int main(void)
{
    int ch;

    create();
    displayforward();

    while (1)
    {
        printf("\n========== DOUBLY LINKED LIST ==========");
        printf("\n0. Create List");
        printf("\n1. Insert at Beginning");
        printf("\n2. Insert at End");
        printf("\n3. Insert at Position");
        printf("\n4. Delete at Beginning");
        printf("\n5. Delete at End");
        printf("\n6. Delete at Position");
        printf("\n7. Traverse Forward");
        printf("\n8. Traverse Backward");
        printf("\n9. Exit");
        printf("\nEnter choice: ");

        if (scanf("%d", &ch) != 1)
        {
            printf("\nInvalid input");
            clearlist();
            return 1;
        }

        switch (ch)
        {
            case 0:
                clearlist();
                create();
                break;

            case 1:
                insertatbegin();
                break;

            case 2:
                insertatend();
                break;

            case 3:
                insertatmid();
                break;

            case 4:
                deleteatbegin();
                break;

            case 5:
                deleteatend();
                break;

            case 6:
                deleteatmid();
                break;

            case 7:
                displayforward();
                break;

            case 8:
                displaybackward();
                break;

            case 9:
                clearlist();
                printf("\nProgram exited successfully\n");
                return 0;

            default:
                printf("\nInvalid choice");
        }

        if (ch >= 0 && ch <= 6)
            displayforward();
    }

    return 0;
}
