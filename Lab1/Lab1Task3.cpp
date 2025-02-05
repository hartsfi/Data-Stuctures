// This program produces a sales report for DLC, Inc.
#include <iostream>
#include <iomanip>
using namespace std;

//Product Structure
struct Product {

	int id;
	int units;
	double prices;
	double sales;

};

// Function prototypes
void calcSales(Product productList[], int);
void showOrder(Product productList[], int);
void dualSort(Product productList[], int);
void showTotals(Product productList[], int);

// NUM_PRODS is the number of products produced.
const int NUM_PRODS = 9;

int main(){

	//List of Products
	Product productList[NUM_PRODS] = {

		{914, 842, 12.95},
		{915, 416, 14.95},
		{916, 127, 18.95},
		{917, 514, 16.95},
		{918, 437, 21.95},
		{919, 269, 31.95},
		{920, 97, 14.95},
		{921, 492, 14.95},
		{922, 212, 16.95}

	};

	// Calculate each product's sales.
	calcSales(productList, NUM_PRODS);

	// Sort the elements in the sales array in descending
	// order and shuffle the ID numbers in the id array to
	// keep them in parallel.
	dualSort(productList, NUM_PRODS);

	// Set the numeric output formatting.
	cout << setprecision(2) << fixed << showpoint;

	// Display the products and sales amounts.
	showOrder(productList, NUM_PRODS);

	// Display total units sold and total sales.
	showTotals(productList, NUM_PRODS);
	return 0;
}

//****************************************************************
// Definition of calcSales. Accepts units, prices, and sales *
// arrays as arguments. The size of these arrays is passed *
// into the num parameter. This function calculates each *
// product's sales by multiplying its units sold by each unit's *
// price. The result is stored in the sales array. *
//****************************************************************

void calcSales(Product productList[], int num)
{
	for (int index = 0; index < num; index++)
		productList[index].sales = productList[index].prices * productList[index].units;
}

//***************************************************************
// Definition of function dualSort. Accepts id and sales arrays *
// as arguments. The size of these arrays is passed into size. *
// This function performs a descending order selection sort on *
// the sales array. The elements of the id array are exchanged *
// identically as those of the sales array. size is the number *
// of elements in each array. *
//***************************************************************

void dualSort(Product productList[], int size) {

	int startScan, maxIndex;
	Product temp;

	for (startScan = 0; startScan < (size - 1); startScan++) {

		maxIndex = startScan;

		for (int index = startScan + 1; index < size; index++) {
			if (productList[index].sales > productList[maxIndex].sales) {
				maxIndex = index;
			}
		}

		temp = productList[maxIndex];
		productList[maxIndex] = productList[startScan];
		productList[startScan] = temp;

	}
}

//****************************************************************
// Definition of showOrder function. Accepts sales and id arrays *
// as arguments. The size of these arrays is passed into num. *
// The function first displays a heading, then the sorted list *
// of product numbers and sales. *
//****************************************************************

void showOrder(Product productList[], int num)
{
	cout << "Product Number\tSales\n";
	cout << "----------------------------------\n";
	for (int index = 0; index < num; index++)
	{
		cout << productList[index].id << "\t\t$";
		cout << setw(8) << productList[index].sales << endl;
	}
	cout << endl;
}

//*****************************************************************
// Definition of showTotals function. Accepts sales and id arrays *
// as arguments. The size of these arrays is passed into num. *
// The function first calculates the total units (of all *
// products) sold and the total sales. It then displays these *
// amounts. *
//*****************************************************************

void showTotals(Product productList[], int num)
{
	int totalUnits = 0;
	double totalSales = 0.0;

	for (int index = 0; index < num; index++)
	{
		totalUnits += productList[index].units;
		totalSales += productList[index].sales;
	}
	cout << "Total Units Sold: " << totalUnits << endl;
	cout << "Total Sales: $" << totalSales << endl;
}

/*
* 
	Lab Report Items:

		- Added New Product Struct
		- Created and Instantiated an array of Products using the values given
		- Changed the Protypes, function calls, and paramenters to accept a list of type Product
		- Changed the function logic to utilize the list of Products using the dot operator
	
	Issues I ran into:
		
		- Was getting bad errors -> Realized I needed to creat my Struct above the prototypes

*/
