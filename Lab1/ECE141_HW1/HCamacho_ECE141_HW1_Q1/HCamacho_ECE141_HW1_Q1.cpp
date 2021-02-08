#include <iostream>
#include <array>
#include <chrono>
#include <algorithm>
#include <cstdlib>
#include <queue>

using namespace std;

//Q1 part 1
int fourSum_bruteForce(int arr[], int size);

//Q1 part 2
int fourSum_cubicLog(int arr[], int size);

//Q3
void cubeSumQueue();

// Helper function
void printArr(int arr[], int size);
bool binarySearch(int arr[], int start, int end, int target);

int main()
{
    const int size = 201;
    int quads = 0;
    int testArr[size];
    for (int i = 0, k = -100; i < size; ++i, ++k)
        testArr[i] = k;

    quads = fourSum_bruteForce(testArr, size);
    cout << "Number of Quads summing to 0: " << quads << endl << endl;

    quads = fourSum_cubicLog(testArr, size);   
    cout << "Number of Quads summing to 0: " << quads << endl << endl;

    cubeSumQueue();
}
/********************************************************************************
* Functions start
********************************************************************************/
int fourSum_bruteForce(int arr[], int size)
{
    // Checks if the list is too small to possibly have a sum of 4 integers
    if (size < 4) return 0;

    int count = 0;

    for (int i = 0; i < size; ++i)
        for (int j = i + 1; j < size; ++j)
            for (int k = j + 1; k < size; ++k)    
                for (int l = k + 1; l < size; ++l)
                    if ((arr[i] + arr[j] + arr[k] + arr[l]) == 0)
                        count++;

    return count;
}

int fourSum_cubicLog(int arr[], int size)
{
    // Checks if the list is too small to possibly have a sum of 4 integers
    if (size < 4) return 0;

    // Merge sort the array
    sort(arr, arr + size-1);

    int count = 0;
    for (int i = 0; i < size; ++i)
        for (int j = i + 1; j < size; ++j)
            for (int k = j + 1; k < size; ++k)
                if (binarySearch(arr, k+1, size-1, -(arr[i] + arr[j] + arr[k])))
                {
                    count++;
                }
                    
    return count;
}

void printArr(int arr[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << arr[i] << " ";
        if ((i != 0) && (i % 10 == 0))
            cout << endl;
    }
}

bool binarySearch(int arr[], int start, int end, int target)
{
    int mid;
    while (start <= end)
    {
        mid = start + (end - start) / 2;
        if (arr[mid] == target) return true;
        else if (target < arr[mid])end = mid - 1;
        else if (target > arr[mid]) start = mid + 1;
    }
    return false;
}

void cubeSumQueue()
{
    // Display the array contents
    cout << "*****************Q3 START*****************" << endl;
    cout << "Using Dataset: { 22, 18, 16, 12, 3, 2, 1, 0 }\n";
    cout << "For numbers ranging from 0 to 30\n\n";
    // Array used to input values into the priority queue
    int inputArray[8] = { 3, 0, 18, 12, 22, 16, 1, 2 };
    
    // Algorithm will be tested from 0 -> 30
    int n = 30;

    priority_queue<int> queue1;

    // Store the inputArray values into the priority queue
    for (int i = 0; i < 8; ++i)
    {
        queue1.push(inputArray[i]);
    }
    
    int currVal;
    while (!queue1.empty())
    {
        // Grab the value with the highest priority in the queue
        // and store it in a temporary variable
        currVal = queue1.top();
        queue1.pop();

        // Perform a modified binary search to find a pair of a^3+b^3 = currVal
        for (int i = 0; (i * i * i <= currVal) && (i <= n); ++i)
        {
            int target = currVal - i * i * i;
            int start = i;
            int end = target;
            int mid;
            while (start <= end)
            {
                mid = start + (end - start) / 2;
                if (mid * mid * mid == target)
                {
                    cout << i << "^3 + " << mid << "^3 = " << currVal << endl;
                    break;
                }
                else if (target < mid*mid*mid)end = mid - 1;
                else if (target > mid*mid*mid) start = mid + 1;
            }           
        }
    }
}