/*
Lab Task

Dynamic Inventory Management(ID Dynamic Array)

 Background: You are building an inventory management system for a small store. The store sells a
 variable number of products, and the inventory needs to be updated dynamically.
 
 Task:
 1. Ask the user to input the number of products in the store.
 2. Dynamically allocate a 1D array to store the quantity of each product.
 3. Populate the array with initial quantities (user input).
 4. Implement the following features:
	 • Add a new product to the inventory (resize the array).
	 • Remove a product from the inventory (resize the array).
	 • Update the quantity of a specific product.
	 • Display the current inventory.
 5. Deallocate the memory after use.
 
 Real-world connection: This scenario reflects real-world inventory systems where products are
 added or removed dynamically, and quantities need to be updated.

*/

#include <iostream>
#include 
using namespace std;

// Function to display inventory
void displayInventory(int* inventory, int size) 
{
    cout << "\nCurrent Inventory:\n";
    for (int i = 0; i < size; i++) 
	{
        cout << "Product " << i + 1 << ": " << inventory[i] << " units\n";
    }
}

// Function to add a new product
void addProduct(int*& inventory, int& size, int quantity) 
{
    int* newInventory = new int[size + 1]; // Allocate new larger array
    for (int i = 0; i < size; i++) 
	{
        newInventory[i] = inventory[i]; // Copy old data
    }
    newInventory[size] = quantity; // Add new product quantity
    delete[] inventory; // Free old memory
    inventory = newInventory; // Update pointer
    size++;
}

// Function to remove a product
void removeProduct(int*& inventory, int& size, int index) 
{
    if (index < 0 || index >= size) 
	{
        cout << "Invalid product index!\n";
        return;
    }
    
    int* newInventory = new int[size - 1]; // Allocate smaller array
    for (int i = 0, j = 0; i < size; i++) 
	{
        if (i != index) 
		{
            newInventory[j++] = inventory[i]; // Copy all except the removed one
        }
    }
    delete[] inventory; // Free old memory
    inventory = newInventory; // Update pointer
    size--;
}

// Function to update product quantity
void updateProduct(int* inventory, int size, int index, int newQuantity) 
{
    if (index < 0 || index >= size) 
	{
        cout << "Invalid product index!\n";
        return;
    }
    inventory[index] = newQuantity;
}

int main() 
{
    int size;
    cout << "Enter number of products: ";
    cin >> size;

    // Dynamic memory allocation for inventory
    int* inventory = new int[size];

    // Taking initial product quantities
    cout << "Enter initial quantities of products:\n";
    for (int i = 0; i < size; i++) {
        cout << "Product " << i + 1 << ": ";
        cin >> inventory[i];
    }

    int choice;
    do {
        cout << "\nInventory Management System\n";
        cout << "1. Display Inventory\n";
        cout << "2. Add Product\n";
        cout << "3. Remove Product\n";
        cout << "4. Update Product Quantity\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) 
		{
            case 1:
                displayInventory(inventory, size);
                break;
            case 2: 
			{
                int quantity;
                cout << "Enter quantity of new product: ";
                cin >> quantity;
                addProduct(inventory, size, quantity);
                cout << "Product added successfully!\n";
                break;
            }
            case 3: 
			{
                int index;
                cout << "Enter product index to remove (1-based index): ";
                cin >> index;
                removeProduct(inventory, size, index - 1);
                cout << "Product removed successfully!\n";
                break;
            }
            case 4: 
			{
                int index, newQuantity;
                cout << "Enter product index to update (1-based index): ";
                cin >> index;
                cout << "Enter new quantity: ";
                cin >> newQuantity;
                updateProduct(inventory, size, index - 1, newQuantity);
                cout << "Product quantity updated!\n";
                break;
            }
            case 5:
                cout << "Exiting system...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 5);

    // Free allocated memory
    delete[] inventory;
    
    return 0;
}

