#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[30];
    double cost;
} item_t;

typedef struct node_t {
    item_t item;
    struct node_t* next;
} node_t;

typedef struct {
    node_t* head;
} list_t;

void add_item(list_t* items, char* name, double cost) {
    // TODO
}
void print_items(list_t items) {
    // TODO
}
void deallocate_list(list_t* list) {
    // TODO
}

int main(void) {
    list_t list_of_items = {NULL};
    char name[30];
    double cost;
    while (1) {
        printf("Input name and cost (end with 'exit 0')\n");
        scanf("%s %lf", name, &cost);
        // Stop if the user enters "exit" as item name
        if (strcmp(name, "exit") == 0) {
            break;
        }
        // Add item with name and cost to the list
        // TODO: add_item
    }
    // TODO: print_items

    // TODO: deallocate_list

    return 0;
}
