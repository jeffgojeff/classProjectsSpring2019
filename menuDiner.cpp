//Jeffrey C. Slocum
//jcs307

#include <iostream>
#include <iomanip>
using namespace std;

//var
//declare an array of structs
struct menuData
{
	string name;
	double price;
	int counter = 0;
};
//declare array
menuData menuItem[8];

//declare global variables
int selectionArray [100];
double allDay = 0;

//prototypes
void printMenu();
void menu();
double totalMenu();
void uncleSam(double &, double &);
void bestItem();


int main()
{
	//variables needed for loop
	double orderTotal;
	char truth = 'N';

	//print menu to the screen
	while (truth == 'N' || truth == 'n')
	{
		menu();
		printMenu();
		orderTotal = totalMenu();
		uncleSam(orderTotal, allDay);
		cout << "Order again? [N = new order] [E = exit]: ";
		cin >> truth;
	}

	cout << endl;
	cout << "End of Day:" << endl;
	cout << "Total money taken in: " << allDay << endl;
	bestItem();
}

//functions

//print menu
void printMenu()
{
	//for loop to print menu to screen
	//i for array point, j for numbered list
	//used setw to give it a clean and neat look and structure
	//split line for readability
	for (int i = 0, j = 1; i < 8; i++, j++)
	{
		cout << fixed << setprecision(2) << "[" << j << "] " << left << setw(30) << menuItem[i].name << right << setw(10) 
		<< "$ " << menuItem[i].price << endl;

	}
}

//fill the array with data using structs
void menu()
{
	menuItem[0].name = "Plain Egg";
	menuItem[1].name = "Bacon and Cheese";
	menuItem[2].name = "Muffin";
	menuItem[3].name = "French Toast";
	menuItem[4].name = "Fruit Basket";
	menuItem[5].name = "Cereal";
	menuItem[6].name = "Coffee";
	menuItem[7].name = "Tea";

	menuItem[0].price = 1.45;
	menuItem[1].price = 2.45;
	menuItem[2].price = 0.99;
	menuItem[3].price = 1.99;
	menuItem[4].price = 2.49;
	menuItem[5].price = 0.69;
	menuItem[6].price = 0.50;
	menuItem[7].price = 0.75;
}

//will collect order information from user
//will return total amount NOT including tax
double totalMenu()
{
	int var1 = 1;
	double var2 = 0;

	cout << endl << "Input the item numbers for the order, 0 to quit." << endl;

	//when 0 is entered, program will stop
	while ( var1 != 0)
	{
		//user variable entered
		cin >> var1;

		//test for correct input
		if (var1 > 8)
		{
			cout << "Invalid input. Please try again." << endl;
		}
		//loop to get price and keep a running total of the order
		//increase counter each time an item is selected
		else
		{
			for (int i = 0; i < 1; ++i)
			{
				var2 += menuItem[var1-1].price;
				menuItem[var1-1].counter += 1;
			}
		}
	}
	cout << endl;
	return var2;
}

//will take returned value from totalMenu
//and return total WITH tax
//and will increase amount for all day sales
void uncleSam(double &var1, double &var2)
{
	double valueTax, totalTax;
	valueTax = var1 * .07;
	totalTax = var1 + valueTax;
	var2 += totalTax;

	cout << "Subtotal...$ " << fixed << setprecision(2) << right << setw(7) << var1 << endl;
	cout << "Tax........$ " << fixed << setprecision(2) << right << setw(7) << valueTax << endl;
	cout << "Total......$ " << fixed << setprecision(2) << right << setw(7) << totalTax << endl;
	cout << endl;

}

//will find which item sold the most.
void bestItem()
{
	int tester = 0;
	for (int i = 0; i < 8; ++i)
		{
			if (menuItem[tester].counter < menuItem[i].counter)
				{
					tester = i;
				}
		}
	cout << "Item ordered most ofter: " << menuItem[tester].name;
	cout << " was ordered " << menuItem[tester].counter << " times." << endl << endl;
}
