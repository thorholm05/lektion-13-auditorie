#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * A struct containing the name and cost of a shopping item.
 */
typedef struct {
    char name[30];
    double cost;
} item_t;

/**
 * A struct for building the linked list, has the "next" item which is NULL if no next exists.
 */
typedef struct node_t {  // We need a name here ...
    item_t item;
    struct node_t* next; // ... so we can use it again here
} node_t;

/**
 * A fancy wrapper for a linked list to make our types nice, and make our program look nice.
 * A valid list has a pointer to the first element of a linked list or NULL.
 */
typedef struct {
    node_t* head;
} list_t;

/**
 * Adds an item to a list of items (first argument). This function prepends the item to the list.
 * @param items: a valid list struct
 * @param name: the name of the item to add
 * @param cost: the cost of the item to add
 */
void add_item(list_t* items, char* name, double cost) {
    // Start by allocating space for a new node. The node already contains enough space for the item.
    node_t* new_node = (node_t*)malloc(sizeof(node_t));
    new_node->next = items->head;  // Push the next element down
    new_node->item.cost = cost;
    strcpy(new_node->item.name, name);
    // Put the new element at the start of the list.
    items->head = new_node;
}

/**
 * Prints a list of items. Assumes that the list is a propper linked list.
 * @param items: a valid list struct
 */
void print_items(list_t items) {
    node_t* current = items.head;
    while (current != NULL) {  // We know that the NULL pointer signals the end of the list
        printf("%s %lf\n", current->item.name, current->item.cost);
        current = current->next;  // Move to the next element
    }
}

/**
 * Deallocates the memory allocated by the list
 * @param list: a list to deallocate
 */
void deallocate_list(list_t* list) {
    node_t* current = list->head;
    while (current != NULL) {  // The NULL pointer signals the end of the list
        node_t* next = current->next;  // We need to copy out the value "next" before we deallocate!
        free(current);
        current = next;  // Move to the next element
    }
    // Reset the list pointer, so it doesn't point to deallocated memory.
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
        add_item(&list_of_items, name, cost);
    }

    // Print all items
    print_items(list_of_items);

    // TODO: Auditorieopgave A
    //    1) Calculate number of items
    //    2) Calculate total price

    // Remember to clean up before we stop
    deallocate_list(&list_of_items);
    return 0;
}
