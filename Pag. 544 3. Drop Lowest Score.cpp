#include<iostream>
#include<iomanip>
using namespace::std;

/*Pag. 544 3. Drop Lowest Score
Program that dynamically allocates an array large enough to hold a
user-defined number of test scores and drops the lowest score.
Edwin Y. Melendez Lopez #89139
CECS 2222 sec. 22
Prof. Claudia Talavera*/

void selectionSort(double *, int numTests);
void showArray(double[], int);
void dropLowestNumber(double[], int);
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
	dropLowestNumber(scores, numTests);
	display(total, average);


	delete[] scores;
	scores = nullptr;


	system("pause");
	return 0;

}// end main. 15 de marzo de 2017 - 

double getTotal(double total, double *scores, int numTests) {

	int count;
	for (count = 0; count < numTests - 1; count++)
	{
		total += *(scores + count);
	}
	return total;

}

double getAverage(int numTests, double total) {

	double average;
	average = total / (numTests - 1);
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
			{  // The next three lines swap the two elements
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

		bottom--;    // Bottom is decremented by 1 since each pass through
					 // the array adds one more value that is set in order

					        
	} while (swap != false);



}

void dropLowestNumber(double scores[], int numTests) {

	cout << "The official scores (with the lowest score dropped) are: ";
	for (int count = 0; count < numTests - 1; count++) 
		cout << scores[count] << "  ";

}

void display(double total, double average) {

	cout << fixed << showpoint << setprecision(2);
	cout << "\n\nTotal Scores: " << total << endl;
	cout << "Average Score: " << average << endl;

}

/*How many tests scores do you wish to process? 5
Enter the tests scores below.
Test 1: 45
Test 2: 97
Test 3: 23
Test 4: 69
Test 5: 56


The scores are: 97  45  23  69  56

The scores are: 97  45  23  69  56

The scores are: 97  45  69  23  56

The scores are: 97  45  69  56  23

The scores are: 97  45  69  56  23

The scores are: 97  69  45  56  23

The scores are: 97  69  56  45  23

The scores are: 97  69  56  45  23

The scores are: 97  69  56  45  23

The official scores (with the lowest score dropped) are: 97  69  56  45

Total Scores: 234.00					// Arreglar. Se supone que el total te de 267
Average Score: 58.50
Press any key to continue . . .*/