//Lab7-sromberg.h
//Spencer Romberg
//COSC 2030 Fall 2018
//Lab 06
//November 12th, 2018
//Uses definitions established in Lab7-sromberg.h

#include "RandomUtilities.h"
#include <iostream>
#include <algorithm>
#include "Lab7-sromberg.h"
#include "winTimer.h"
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::sort;
using std::vector;

vector<double>
getNums(size_t listSize, double minNum, double maxNum)
{
	vector<double> theList;
	for (size_t i = 0; i < listSize; ++i)
	{
		theList.push_back(randReal(minNum, maxNum));
	}

	//sort(begin(theList), end(theList));

	return theList;
}

int main()
{
	cout << "Enter size for numbers: ";
	int n = 0;
	cin >> n;
	if (n <= 0)
	{

	}
	cout << "Enter seed for rand: ";
	unsigned int seed;
	cin >> seed;
	srand(seed);

	// Construct a sorted list of numbers
	Timer get;
	get.start();
	vector<double> numbers = getNums(n, -n, n);
	get.stop();
	cout << "Constructed in " << get() << " seconds"
		<< endl;

	/*Timer bubble;
	bubble.start();
	bubble_sort(numbers.begin(), numbers.end());
	bubble.stop();
	cout << "Bubblesort sorted the vector in " << bubble() << " seconds" << endl;
	

	Timer insert;
	insert.start();
	insertion_sort(numbers.begin(), numbers.end());
	insert.stop();
	cout << "Insertionsort sorted the vector in " << insert() << " seconds" << endl;

	Timer selection;
	selection.start();
	selection_sort(numbers.begin(), numbers.end());
	selection.stop();
	cout << "Selectionsort sorted the vector in " << selection() << " seconds" << endl;

	Timer merge;
	merge.start();
	mergesort(numbers.begin(), numbers.end());
	merge.stop();
	cout << "Mergesort sorted the vector in " << merge() << " seconds" << endl;

	Timer quick;
	quick.start();
	quicksort(numbers.begin(), numbers.end());
	quick.stop();
	cout << "Quicksort sorted the vector in " << quick() << " seconds" << endl;*/

	Timer std;
	std.start();
	sort(numbers.begin(), numbers.end());
	std.stop();
	cout << "std::sort sorted the vector in " << std() << " seconds" << endl;
	

	system("pause");



}