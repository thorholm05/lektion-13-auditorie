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
    // Alloker memory til noden
    node_t* new_node = malloc(sizeof(node_t));
    // Kopier data ind i item delen
    new_node->item.cost = cost;
    strcpy(new_node->item.name, name);
    // Tilføj new_node til starten af listen items
    new_node->next = items->head;
    items->head = new_node;
}
void print_items(list_t items) {
    node_t* current = items.head;
    while (current != NULL) {
        printf("%s %lf\n", current->item.name, current->item.cost);
        current = current->next;
    }
}
void deallocate_list(list_t* list) {
    node_t* current = list->head;
    while (current != NULL) {
        node_t* next = current->next;
        free(current);
        current = next;
    }
    list->head = NULL;
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
        add_item(&list_of_items, name, cost);
    }
    // TODO: print_items
    print_items(list_of_items);

    deallocate_list(&list_of_items);

    return 0;
}
