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
 * Adds an item to a list of items (first argument). This function appends the item to the list.
 * @param items: a valid list struct
 * @param name: the name of the item to add
 * @param cost: the cost of the item to add
 */
void add_item(list_t* items, char* name, double cost) {
    // Start by allocating space for a new node. The node already contains enough space for the item.
    node_t* new_node = (node_t*)malloc(sizeof(node_t));
    new_node->next = NULL;
    new_node->item.cost = cost;
    strcpy(new_node->item.name, name);

    // If the list is empty, put the new element at the start.
    if (items->head == NULL) {
        items->head = new_node;
    }
    else {
        node_t* current = items->head;

        // Find the last element in the list.
        while (current->next != NULL) {
            current = current->next;
        }

        // Put the new element at the end of the list.
        current->next = new_node;
    }
}

/**
 * Prints a list of items. Assumes that the list is a propper linked list.
 * @param items: a valid list struct
 */
void print_items(list_t items) {
    node_t* current = items.head;
    while (current != NULL) {  // We know that the NULL pointer signals the end of the list
        printf("%s %.2lf kr\n", current->item.name, current->item.cost);
        current = current->next;  // Move to the next element
    }
}

/**
 * Calculates the number of items in the list.
 * @param items: a valid list struct
 */
int count_items(list_t items) {
    int count = 0;
    node_t* current = items.head;

    while (current != NULL) {
        count++;
        current = current->next;
    }

    return count;
}

/**
 * Calculates the total price of all items in the list.
 * @param items: a valid list struct
 */
double total_price(list_t items) {
    double total = 0;
    node_t* current = items.head;

    while (current != NULL) {
        total += current->item.cost;
        current = current->next;
    }

    return total;
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

    // Auditorieopgave A
    //    1) Skriv en funktion der beregner antal varer i listen.
    printf("Number of items: %d\n", count_items(list_of_items));

    //    2) Skriv en funktion der beregner summen af varernes pris i listen.
    printf("Total price: %.2f kr\n", total_price(list_of_items));

    deallocate_list(&list_of_items);
    return 0;
}