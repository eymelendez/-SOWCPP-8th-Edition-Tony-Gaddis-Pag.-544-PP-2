#include<iostream>
#include<iomanip>
using namespace::std;

/*Problem #2 Page 544
Program that dynamically allocates an array large enough to hold a
user-defined number of test scores.
Edwin Y. Melendez Lopez #89139
CECS 2222 sec. 22
Prof. Claudia Talavera*/

void selectionSort(double *, int numTests);
void showArray(double[], int);
void bubbleSortArray(double[], int);
double *setptr(int numTests);
double getAverage(int numTests, double total);
double getTotal(double total, double *scores, int numTests);
void display(double total, double average);

int main() {

	int numTests;
	double *scores = nullptr, total = 0.0, average;

	cout << "How many tests scores do you wish to process? ";
	cin >> numTests;

	scores = setptr(numTests);
	total = getTotal(total, scores, numTests);
	average = getAverage(numTests, total);
	cout << endl;
	selectionSort(scores, numTests);
	showArray(scores, numTests);
	cout << endl;
	bubbleSortArray(scores, numTests);
	display(total, average);



	delete[] scores;
	scores = nullptr;


	system("pause");
	return 0;

}// end main. 15 de marzo de 2017 - Successful!

double getTotal(double total, double *scores, int numTests) {

	int count;
	for (count = 0; count < numTests; count++)
	{
		total += *(scores + count);
	}
	return total;
}

double getAverage(int numTests, double total) {

	double average;
	average = total / numTests;
	return average;

}

double *setptr(int numTests) {

	double *arr = nullptr;
	arr = new double[numTests];

	cout << "Enter the tests scores below.\n";
	for (int count = 0; count < numTests; count++)
	{
		cout << "Test " << (count + 1) << ": ";
		cin >> *(arr + count);
	}
	return arr;
}

void selectionSort(double scores[], int numTests) {

	int minIndex, minValue;
	for (int startScan = 0; startScan < (numTests - 1); startScan++)
	{
		minIndex = startScan;
		minValue = scores[startScan];
		for (int index = startScan + 1; index < numTests; index++)
		{
			if (scores[startScan] < minValue)
			{
				minValue = scores[index];
				minIndex = index;
			}
		}
		scores[minIndex] = scores[startScan];
		scores[startScan] = minValue;
	}
}

void showArray(double scores[], int numTests) {

	bool swap;
	int temp;
	int bottom = numTests - 1;     // Bottom indicates the end part of the
								   // array where the largest values have
								   // settled in order
	do
	{
		swap = false;
		for (int count = 0; count < bottom; count++)
		{
			if (scores[count] < scores[count + 1])
			{  
				temp = scores[count];
				scores[count] = scores[count + 1];
				scores[count + 1] = temp;
				swap = true;     // Indicates that a swap occurred
			}

			
			cout << "\nThe scores are: "; 
		

			for (int count = 0; count < numTests; count++)
				cout << scores[count] << "  ";
			cout << endl;
		}
		bottom--;    


			         
	} while (swap != false);



}

void bubbleSortArray(double scores[], int numTests) {

	for (int count = 0; count < numTests; count++)
		cout << scores[count] << "  ";

}

void display(double total, double average) {

	cout << fixed << showpoint << setprecision(2);
	cout << "\n\nTotal Scores: " << total << endl;
	cout << "Average Score: " << average << endl;

}

/*How many tests scores do you wish to process? 5
Enter the tests scores below.
Test 1: 100
Test 2: 90
Test 3: 59
Test 4: 87
Test 5: 76


The scores are: 100  90  59  87  76

The scores are: 100  90  59  87  76

The scores are: 100  90  87  59  76

The scores are: 100  90  87  76  59

The scores are: 100  90  87  76  59

The scores are: 100  90  87  76  59

The scores are: 100  90  87  76  59

100  90  87  76  59

Total Scores: 412.00
Average Score: 82.40
Press any key to continue . . .*/