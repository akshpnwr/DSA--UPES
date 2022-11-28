#include<stdio.h>
#include<stdlib.h>

struct hash {
    int value;
    struct hash *next;
};

typedef struct hash hash;

#define MAX_SIZE 10

hash* arr[MAX_SIZE];

hash* createNode(int value) {

    hash* node = (hash*) malloc(sizeof(hash));
    node->value = value;
    node->next = NULL;

    return node;
}

void init() {
    for (int i = 0; i < MAX_SIZE; i++) arr[i] = createNode(-1); 
}

void performChaining(int value) {

        int mod = value%MAX_SIZE;

        hash* temp = arr[mod];
        hash* node = createNode(value);
        
        while (temp->next!=NULL)
        {
            temp = temp->next;
        }
        
        temp->next = node;

}

void linearProbing(int value) {
    
    for (int i = 0; i < MAX_SIZE; i++)
    {
        if (arr[i]->value == -1)
        {
            arr[i]->value = value;
            break;
        }
        
    }
    
}

void insert(int value) {

    if (arr[value%MAX_SIZE]->value == -1) arr[value % MAX_SIZE] = createNode(value);
    else {
        // performChaining(value);
        linearProbing(value);
    }
    
}

void display() {
    for (int i = 0; i < MAX_SIZE; i++)
    {
        if (arr[i]->value != -1)
        {
            if (arr[i]->next != NULL)
            {
                printf("\n");
                
                while (arr[i]!=NULL)
                {
                    printf("%d ",arr[i]->value);
                    arr[i] = arr[i]->next;
                }
            }
            
            else printf("\n%d",arr[i]->value);
            
        }
        else printf("\nNULL");

    }
}

int main() {

init();

int keys[] = {23,46,12,55,17,33,51,73};

int keysSize = sizeof(keys)/sizeof(int);

for (int i = 0; i < keysSize; i++)
{
    insert(keys[i]);
}

display();

return 0;
}
