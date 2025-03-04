/*
Lab Task

Dynamic Inventory Management(1D Dynamic Array)

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
#include <new>
using namespace std;

//Function prototypes
void addProduct(int*&,int&,int);
void remProduct(int*&,int&,int);
void updProduct(int*&,int,int,int);
void disProduct(int*,int);

//Main Function
int main()
{
	int num;
	cout<<"Enter the number of the products in the store:";
	cin>>num;
	int* inventory=new int[num];
	cout<<"\nEnter initial quantities of each product:\n";
	for (int i=0;i<num;i++)
	{
		cout<<"\nProduct "<<i+1<<" :";
		cin>>inventory[i];
	}
	
	char ch;
	do
	{
		cout<<"\n======================================================\n";
		cout<<"\nChoose one of the following options... \n\n";
		cout<<"A - add new product.\n";
		cout<<"R - remove a product.\n";
		cout<<"U - update a product.\n";
		cout<<"D - display the current inventory.\n";
		cout<<"E - exit the program.\n";
		cout<<"\n======================================================\n";
		cout<<"Enter your choice :";
		cin>>ch;
		ch=tolower(ch);
		switch(ch)
		{
			case 'a':
				{
					int quantity;
					cout<<"\nEnter the quantity of the new product :";
					cin>>quantity;
					//calling the add function
					addProduct(inventory,num,quantity);
					break;
				}
			case 'r':
				{
					int index;
					cout<<"\nEnter index of the product that you want to remove:";
					cin>>index;
					//Function calling to remove a product
					remProduct(inventory,num, index);
					break;
				}
			case 'u':
				{
					int index, quantity;
					cout<<"\nEnter index of product that you want to update :";
					cin>>index;
					cout<<"\nEnter new quantity of the product :";
					cin>>quantity;
					//Function calling for updating inventory
					updProduct(inventory,num,index,quantity);
					break;
				}
			case 'd':
				{
					//function calling to display inventory
					disProduct(inventory,num);
					break;
				}
			case 'e':
				{
					cout<<"\nExiting...";
					break;
				}
			default:
				{
					cout<<"\nInvalid input. Please try again!";
				}
		}
	}while(ch !='e');
	
	delete[] inventory;
	return 0;
}

//////////Add Function//////////
void addProduct(int*& inventory, int& size, int quantity)
{
	int* newinventory=new int[size+1];
	for(int i=0;i<size;i++)
	{
		newinventory[i]=inventory[i];
	}
	newinventory[size]=quantity;
	delete[] inventory;
	inventory=newinventory;               
	size++;
	
}

//////////Display Function//////////
void disProduct(int* inventory, int size)
{
	cout<<"\nDisplaying quantities...";
	if(size<0)
	{
		cout<<"\nInventory is empty.";
	}
	
	for (int i=0;i<size;i++)
	{
		cout<<"\nProduct "<<i+1<<" :";
		cout<<inventory[i];
	}
}

//////////Remove Function//////////
void remProduct(int*& inventory,int& size, int index)
{
	int* newinventory=new int[size-1];
	if(index<0 || index>=size)
	{
		cout<<"\nInvalid index.\n";
		return;
	}
	for(int i=0,j=0;i<size;i++)
	{
		if(i!=index)
		{
			newinventory[j++]=inventory[i];
		}
	}
	delete[] inventory;
	inventory=newinventory;
	size--;
}

//////update function///////
void updProduct(int*& inventory, int size,int index, int quantity)
{
	if(index<0 || index>=size)
	{
		cout<<"\nInvalid index.\n";
		return;
	}
	for(int i=0;i<size;i++)
	{
		if(i==index)
		{
			inventory[i]=quantity;
		}
	}
}
