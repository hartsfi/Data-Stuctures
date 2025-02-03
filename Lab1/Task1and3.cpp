// This program produces a sales report for DLC, Inc.
#include <iostream>
#include <iomanip>
using namespace std;

// NUM_PRODS is the number of products produced.
const int NUM_PRODS = 9;

struct item {
	int id;
	int units;
	double prices;
	double sales;
};

// Function Prototypes
void calcSales(item productList[], int num);
void showOrder(item productList[], int size);
void dualSort(item productList[], int num);
void showTotals(item productList[], int num);

int main()
{
	item products[NUM_PRODS] = { {914,842,12.95},{915,416,14.95},{916,127,18.95},{917,514,16.95},{918,437,21.95},{919,269,31.95},{920,97,14.95},{921,492,14.95},{922,212,16.95} };

	// Calculate each product's sales.
	calcSales(products, NUM_PRODS);

	// Sort the elements in the sales array in descending
	// order and shuffle the ID numbers in the id array to
	// keep them in parallel.
	dualSort(products, NUM_PRODS);

	// Set the numeric output formatting.
	cout << setprecision(2) << fixed << showpoint;

	// Display the products and sales amounts.
	showOrder(products, NUM_PRODS);

	// Display total units sold and total sales.
	showTotals(products, NUM_PRODS);
	return 0;
}

//****************************************************************
// Definition of calcSales. Accepts units, prices, and sales *
// arrays as arguments. The size of these arrays is passed *
// into the num parameter. This function calculates each *
// product's sales by multiplying its units sold by each unit's *
// price. The result is stored in the sales array. *
//****************************************************************

void calcSales(item productList[], int num)
{
	for (int index = 0; index < num; index++)
		productList[index].sales = productList[index].units * productList[index].prices;
}

//***************************************************************
// Definition of function dualSort. Accepts id and sales arrays *
// as arguments. The size of these arrays is passed into size. *
// This function performs a descending order selection sort on *
// the sales array. The elements of the id array are exchanged *
// identically as those of the sales array. size is the number *
// of elements in each array. *
//***************************************************************

void dualSort(item productList[], int size)
{
	int startScan, maxIndex, tempid;
	double maxValue;

	for (startScan = 0; startScan < (size - 1); startScan++)
	{
		maxIndex = startScan;
		maxValue = productList[startScan].sales;
		tempid = productList[startScan].id;
		for(int index = startScan + 1; index < size; index++)
		{
			if (productList[index].sales > maxValue)
			{
				maxValue = productList[index].sales;
				tempid = productList[index].id;
				maxIndex = index;
			}
		}
		productList[maxIndex].sales = productList[startScan].sales;
		productList[maxIndex].id = productList[startScan].id;
		productList[startScan].sales = maxValue;
		productList[startScan].id = tempid;
	}
 }

//****************************************************************
// Definition of showOrder function. Accepts sales and id arrays *
// as arguments. The size of these arrays is passed into num. *
// The function first displays a heading, then the sorted list *
// of product numbers and sales. *
//****************************************************************

void showOrder(item productList[], int num)
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

void showTotals(item productList[], int num)
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