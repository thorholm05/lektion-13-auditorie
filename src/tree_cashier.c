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
 * A struct for building the tree, has the "before" and "after" pointers to the left and right subtrees.
 * NULL pointer indicates that the subtree does not exist.
 */
typedef struct node_t { // we need a name here to be able to declare the pointers in the struct
    item_t item;
    struct node_t* before; // nodes with items ordered before item
    struct node_t* after;  // nodes with items ordered after item
} node_t;

/**
 * A fancy wrapper for a tree to make our types nice, and make our program look nice.
 * A valid tree has a pointer to the first element (root) of a tree or NULL.
 */
typedef struct {
    node_t* root;
} tree_t;


/**
 * A function for correctly inserting a new tree-node into the tree such that the ordering is preserved.
 * @param node: the current node in the traversal down the tree (that finds the correct place to insert the new node).
 * @param new_node: the node that is being inserted.
 */
void recursive_add_node(node_t* node, node_t* new_node) {
    // TODO: Auditorieopgave B
    //   1)  Compare by name instead of cost.
    //   2)  Increase the count if an item with the same name is found. (Add a field 'count' to item_t)

    if (new_node->item.cost < node->item.cost) {  // Sort by cost in ascending order (smallest cost first).
        if (node->before == NULL) {
            node->before = new_node;
        } else {
            recursive_add_node(node->before, new_node);
        }
    } else {  // Our new node has a cost >= than node->item.cost
        if (node->after == NULL) {
            node->after = new_node;
        } else {
            recursive_add_node(node->after, new_node);
        }
    }
}

/**
 * Adds an item to a tree of items. Inserts the item such that the ordering of the binary tree is preserved.
 * @param items: a valid tree struct
 * @param name: the name of the item to add
 * @param cost: the cost of the item to add
 */
void add_item(tree_t* items, char* name, double cost) {
    node_t* new_node = (node_t*)malloc(sizeof(node_t));
    new_node->before = NULL;
    new_node->after = NULL;
    new_node->item.cost = cost;
    strcpy(new_node->item.name, name);
    if (items->root == NULL) {
        // A base case, if the tree has no root, we need to add it!
        items->root = new_node;
    } else {
        // The recursive case, if the tree has a root, follow the path
        recursive_add_node(items->root, new_node);
    }
}

/**
 * A helper function for recursively printing our tree.
 * Prints the tree following the inorder traversal.
 * @param node: the current node in the tree or NULL.
 */
void print_tree_node(node_t* node) {
    if (node == NULL) return;
    // First print all items that are ordered before the current (i.e. cost less)
    print_tree_node(node->before);
    // then the current
    printf("%s %lf\n", node->item.name, node->item.cost);
    // then all that are ordered after (i.e. cost more)
    print_tree_node(node->after);
}

/**
 * Prints a tree of items. Assumes that the tree is a propper tree.
 * Prints the nodes inorder.
 * @param items: a valid tree struct
 */
void print_items(tree_t items) {
    print_tree_node(items.root);
}

/**
 * A helper function to recursively deallocate the tree.
 * @param node: the root of the subtree to deallocate
 */
void deallocate_tree_node(node_t* node) {
    if (node == NULL) return;
    deallocate_tree_node(node->before);
    deallocate_tree_node(node->after);
    // It is important that we descend first before we free,
    // otherwise we would lose the node->before and node->after pointers!
    free(node);
}

/**
 * Deallocates the memory allocated by the tree.
 * @param tree: a tree to deallocate
 */
void deallocate_tree(tree_t* tree) {
    deallocate_tree_node(tree->root);
    tree->root = NULL;
}

int main(void) {
    tree_t tree_of_items = {NULL};
    char name[30];
    double cost;
    while (1) {
        printf("Input name and cost (end with 'exit 0')\n");
        scanf("%s %lf", name, &cost);
        // Stop if the user enters "exit" as item name
        if (strcmp(name, "exit") == 0) {
            break;
        }
        // Add item with name and cost to the tree
        add_item(&tree_of_items, name, cost);
    }

    // Print all items
    print_items(tree_of_items);

    // TODO: Auditorieopgave B. Part 3) Calculate the total price

    // Remember to clean up before we stop
    deallocate_tree(&tree_of_items);
    return 0;
}
