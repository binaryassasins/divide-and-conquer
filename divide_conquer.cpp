/**
 * @file divide_conquer.cpp
 * @author Ammar Haziq Bin Annas, Mohamad Syafiq Asyraf Bin Bharudin
 * @brief Divide and Conquer
 * @version 0.1
 * @date 2023-04-18
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <iostream>
#include <cstdlib>

using namespace std;

void sort(int arr[], int first, int mid, int last, int n){
  int temp_elem_pos = first, first_pos = first, after_mid_pos = mid + 1;
  int temp[n];

  while ((first_pos <= mid) && (after_mid_pos <= last))
  {
    if (arr[first_pos] < arr[after_mid_pos])
    {
      temp[temp_elem_pos] = arr[first_pos];
      first_pos++;
    }
    else
    {
      temp[temp_elem_pos] = arr[after_mid_pos];
      after_mid_pos++;
    }
    temp_elem_pos++;
  }
  
  if (first_pos > mid) {
    while (after_mid_pos <= last) {
      temp[temp_elem_pos] = arr[after_mid_pos];
      after_mid_pos++;
      temp_elem_pos++;
    }
  } else //remaining elements of left array
  {
    while (first_pos <= mid) {
      temp[temp_elem_pos] = arr[first_pos];
      first_pos++;
      temp_elem_pos++;
    }
  }

  // below is just to trace the array elements after being merged
  cout << "combine: ";
  for (int i = first; i <= last; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;

  for (int i = first; i < temp_elem_pos; i++)
  {
    arr[i] = temp[i];
  }
}

void divide(int arr[], int firstelem, int lastelem, int n) {
  // check the condition for each firstelem and lastelem values after it gets updated (block gets terminated if the condition is false)
  if (firstelem < lastelem) {
    int half = (firstelem + lastelem) / 2; // further divide the array

    //below is just to trace the array elements after being divided
    for (int i = firstelem; i <= half; i++)
    {
      cout << arr[i] << " ";
    }
    cout << endl;
    for (int i = half+1; i <= lastelem; i++)
    {
      cout << arr[i] << " ";
    }
    cout << endl;

    divide(arr, firstelem, half, n); // sending out the first half, replace lastelem with half in recursion
    divide(arr, half+1, lastelem, n); // sending out the second half, replace firstelem with half+1 (position after mid element) in recursion
    
    sort(arr, firstelem, half, lastelem, n); // tracing is required for this function
  }
}

int main() {
  int arr[] = {8, 3, 2, 9, 7, 1, 5, 4, 172, 453, 21};
  int n = sizeof(arr)/sizeof(arr[0]);
  int first_elem = n - n;
  int last_elem = n - 1; 
  
  divide(arr, first_elem, last_elem, n); 

  cout << "Sorted array: ";
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
  system("pause");
  return 0;
}