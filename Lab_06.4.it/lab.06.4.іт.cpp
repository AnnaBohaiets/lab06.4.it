#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

int* Create(int* a, const int size,  int Low,  int High)
{
	a = new int[size];

	for (int i = 0; i < size; i++)
		a[i] = Low + rand() % (High - Low + 1);
	return a;
}


void Print(int* a, const int size)
{
	for (int i = 0; i < size; i++)
		cout << setw(4) << a[i] << ", ";
	cout << endl;
}

int Multiply(int* a, const int size)
{
	int M = 1;
	for (int i = 0; i < size; i++)
		if ((i + 1) % 2 == 0)
			M *= a[i];
	return M;
}

int Sum(int* a, const int size, int First, int Last)
{
	int S = 0;
	for (int i = First; i < Last; i++)
		if (!(a[i] % 2 == 0 || a[i] >= 0))
			S += a[i];
	return S;
}

int FindFirstZeroElement(int* a, const int size)
{
	for (int i = 0; i < size; ++i) {
		if (a[i] == 0) {
			return i;
		}
	}
	return -1;
}

int FindLastZeroElement(int* a, const int size)
{
	for (int i = size-1; i >= 0; --i) {
		if (a[i] == 0) {
			return i;
		}
	}
	return -1;
}

int NumberOfPositive(int* a, const int size)
{
	int count = 0;
	for (int i = 0; i < size; i++)
		if (a[i]  >= 0)
			count++;
	return count;
}

int NumberOfNegative(int* a, const int size)
{
	int count = 0;
	for (int i = 0; i < size; i++)
		if (a[i] < 0)
			count++;
	return count;
}

int* Replace(int* a, int* m, const int size, int NumPos, int indexPositive=0, int indexNegative=0)
{
	m = new int[size];
	for (int i = 0; i < size; i++)
		if (a[i] >= 0) {
			m[indexPositive] = a[i];
			indexPositive++;
		}
		else {
			m[NumPos + indexNegative] = a[i];
			indexNegative++;
		}
	return m;
}

int main()
{
	srand((unsigned)time(NULL));
	int n;
	cin >> n;
	int Low = -10;
	int High = 10;

	int* a = Create(0, n, Low, High);
	cout << "Unmodified array " << endl;
	Print(a, n);

	int mult = Multiply(a, n);
	cout << "Multiplication of even elements in array " << mult << endl;

	int firstZeroIndex = FindFirstZeroElement(a,n);
	int lastZeroIndex = FindLastZeroElement(a,n);
	int sum;
	if (firstZeroIndex != -1 && lastZeroIndex != -1 && firstZeroIndex != lastZeroIndex) {
		sum = Sum(a, n, firstZeroIndex, lastZeroIndex);	
		cout << "Sum of elements is " << sum << endl;
	}
	else cout << "There is not two zero elements" << endl;

	int numPos = NumberOfPositive(a, n);
	int numNeg = NumberOfNegative(a, n);
	int* m = Replace(a, 0, n, numPos);
	cout << "Modified array " << endl;
	Print(m, n);



	return 0;
}