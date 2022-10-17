#include <iostream>

void insertionSort(int* arrayOfNumbers, int lIndex, int rIndex)
{
	int i, j;
	for (i = lIndex + 1; i <= rIndex; i++) {
		int element = arrayOfNumbers[i];
		for (j = i - 1; j >= lIndex && element < arrayOfNumbers[j]; j--)
		{
			arrayOfNumbers[j + 1] = arrayOfNumbers[j];
		}
		arrayOfNumbers[j + 1] = element;
	}
}
void merge(int* arrayOfNumbers, int lIndex, int mIndex, int rIndex)
{
	int leftPartLen = mIndex - lIndex + 1;
	int rightPartLen = rIndex - mIndex;
	int* leftPart = new int[leftPartLen];
	int* rightPart = new int[rightPartLen];

	for (int i = 0; i < leftPartLen; i++)
		leftPart[i] = arrayOfNumbers[lIndex + i];
	for (int i = 0; i < rightPartLen; i++)
		rightPart[i] = arrayOfNumbers[mIndex + i + 1];

	int i = 0, j = 0;
	int k = lIndex;
	while (i < leftPartLen && j < rightPartLen)
	{
		if (leftPart[i] <= rightPart[j])
		{
			arrayOfNumbers[k] = leftPart[i];
			i++;
		}
		else {
			arrayOfNumbers[k] = rightPart[j];
			j++;
		}
		k++;
	}
	while (i < leftPartLen)
	{
		arrayOfNumbers[k] = leftPart[i];
		k++;
		i++;
	}
	while (j < rightPartLen)
	{
		arrayOfNumbers[k] = rightPart[j];
		k++;
		j++;
	}
}

int getMinRun(int length)
{
	int f = 0;        
	while (length >= 64) {
		f |= length & 1;
		length >>= 1;
	}
	return length + f;
}


void timSortAlgo(int* arr, int length) {

	int runLength = getMinRun(length);
	for (int i = 0; i < length; i += runLength) 
		insertionSort(arr, i, min((i + 31), (length - 1)));
	
	for (int i = runLength; i < length; i = 2 * i)
	{
		for (int lIndex = 0; lIndex < length; lIndex += 2 * i) {
			int mIndex = lIndex + i - 1;
			int rIndex = min((lIndex + 2 * i - 1), (length - 1));
			merge(arr, lIndex, mIndex, rIndex);
		}
	}


}

