#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50

// Structure to represent an inventory item
struct InventoryItem {
    char name[MAX_NAME_LENGTH];
    int quantity;
};

// Global array to store inventory items
struct InventoryItem inventory[MAX_ITEMS];
int itemCount = 0;

// Function prototypes
void addItem();
void displayInventory();
void searchItem();
void updateItem();
void deleteItem();

int main() {
    int choice;

    do {
        printf("\nInventory Management System\n");
        printf("1. Add Item\n");
        printf("2. Display Inventory\n");
        printf("3. Search Item\n");
        printf("4. Update Item\n");
        printf("5. Delete Item\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addItem();
                break;
            case 2:
                displayInventory();
                break;
            case 3:
                searchItem();
                break;
            case 4:
                updateItem();
                break;
            case 5:
                deleteItem();
                break;
            case 6:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}

void addItem() {
    if (itemCount < MAX_ITEMS) {
        printf("Enter item name: ");
        scanf("%s", inventory[itemCount].name);
        printf("Enter quantity: ");
        scanf("%d", &inventory[itemCount].quantity);
        itemCount++;
        printf("Item added successfully.\n");
    } else {
        printf("Inventory is full. Cannot add more items.\n");
    }
}

void displayInventory() {
    if (itemCount == 0) {
        printf("Inventory is empty.\n");
    } else {
        printf("Inventory:\n");
        for (int i = 0; i < itemCount; i++) {
            printf("%s - Quantity: %d\n", inventory[i].name, inventory[i].quantity);
        }
    }
}

void searchItem() {
    char searchName[MAX_NAME_LENGTH];
    printf("Enter the name of the item to search: ");
    scanf("%s", searchName);

    for (int i = 0; i < itemCount; i++) {
        if (strcmp(searchName, inventory[i].name) == 0) {
            printf("Item found: %s - Quantity: %d\n", inventory[i].name, inventory[i].quantity);
            return;
        }
    }
    printf("Item not found.\n");
}

void updateItem() {
    char updateName[MAX_NAME_LENGTH];
    printf("Enter the name of the item to update: ");
    scanf("%s", updateName);

    for (int i = 0; i < itemCount; i++) {
        if (strcmp(updateName, inventory[i].name) == 0) {
            printf("Enter new quantity: ");
            scanf("%d", &inventory[i].quantity);
            printf("Item quantity updated successfully.\n");
            return;
        }
    }
    printf("Item not found.\n");
}

void deleteItem() {
    char deleteName[MAX_NAME_LENGTH];
    printf("Enter the name of the item to delete: ");
    scanf("%s", deleteName);

    for (int i = 0; i < itemCount; i++) {
        if (strcmp(deleteName, inventory[i].name) == 0) {
            for (int j = i; j < itemCount - 1; j++) {
                strcpy(inventory[j].name, inventory[j + 1].name);
                inventory[j].quantity = inventory[j + 1].quantity;
            }
            itemCount--;
            printf("Item deleted successfully.\n");
            return;
        }
    }
    printf("Item not found.\n");
}