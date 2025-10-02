//
//  sort.h
//
//  Functions for merge sort, quicksort, and a hybrid sort.
//  You SHOULD modify this file.
//
//  IMPORTANT NOTE: For this particular assignment you may not add
//  any additional utility functions.
//
//  Copyright 2019 David Kopec
//
//  MODIFIED BY COLIN SKAARUP
//
//  Permission is hereby granted, free of charge, to any person
//  obtaining a copy of this software and associated documentation files
//  (the "Software"), to deal in the Software without restriction,
//  including without limitation the rights to use, copy, modify, merge,
//  publish, distribute, sublicense, and/or sell copies of the Software,
//  and to permit persons to whom the Software is furnished to do so,
//  subject to the following conditions:
//
//  The above copyright notice and this permission notice
//  shall be included in all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
//  OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
//  THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR
//  OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
//  ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
//  OTHER DEALINGS IN THE SOFTWARE.

#ifndef sort_hpp
#define sort_hpp

#include <algorithm>  // for swap(), merge()
#include <random>

#include "MemoryLeakDetector.h"

using namespace std;

namespace csi281 {

  template <typename T>
  void merge(T* arr, const size_t start, const size_t mid,  const size_t end) {
    // create a temporary array to store the merged array
    std::vector<T> temp(end - start + 1);

    // indexes for the subarrays:
    const size_t leftStart = start;
    const size_t leftEnd = mid;
    const size_t rightStart = mid + 1;
    const size_t rightEnd = end;

    // indexes for
    size_t tempIdx = 0;
    size_t leftIdx = leftStart;
    size_t rightIdx = rightStart;

    // merge the subarrays
    while (leftIdx <= leftEnd && rightIdx <= rightEnd) {
      if (arr[leftIdx] < arr[rightIdx])
        temp[tempIdx++] = arr[leftIdx++];
      else
        temp[tempIdx++] = arr[rightIdx++];
    }

    // copy the remaining elements of the left subarray
    while (leftIdx <= leftEnd)
      temp[tempIdx++] = arr[leftIdx++];

    // copy the remaining elements of the right subarray
    while (rightIdx <= rightEnd)
      temp[tempIdx++] = arr[rightIdx++];

    // copy the merged array back to the original array
    std::copy(temp.begin(), temp.end(), arr + start);
  }

  // Performs an in-place ascending sort of *array*
  // using the merge sort algorithm
  // *start* is the first element of the array to start sorting from
  // *end* is the end element for the elements to be sorted
  // *end* will be the length of the array - 1 for a first run
  // NOTE: Your solution MUST use std::inplace_merge
  // http://www.cplusplus.com/reference/algorithm/inplace_merge/
  template <typename T> void mergeSort(T array[], const int start, const int end) {
    if (end - start > 0) {
      int mid = (end + start) / 2;
      mergeSort(array, start, mid);
      mergeSort(array, mid + 1, end);
      inplace_merge(array + start, array + mid + 1, array + end + 1);
    }
  }

  // setup random number generator
  static random_device rd;
  static mt19937 rng(rd());
  // you can use uniform_int_distribution and rng to create
  // a random int in a certain range

  // Performs an in-place ascending sort of *array*
  // using the quicksort algorithm
  // *start* is the first element of the array to start sorting from
  // *end* is the end element for the elements to be sorted
  // *end* will be the length of the array - 1 for a first run
  // NOTE: Your solution should use std::swap
  // http://www.cplusplus.com/reference/algorithm/swap/
  // NOTE: Your solution MUST use a random pivot
  // TIP: It may be helpful to swap the pivot to the end,
  // sort the center of the range, and then move the pivot back to
  // the appropriate place
  template <typename T> void quickSort(T array[], const int start, const int end) {
    uniform_int_distribution<int> distribution(start, end);
    int pivot = distribution(rd), greaterPoint = start + 1;
    swap(array[pivot], array[start]);
    for (int i = greaterPoint; i <= end; i++) {
      if (array[i] < array[start]) {
        swap(array[i], array[greaterPoint]);
        greaterPoint++;
      }
    }
    swap(array[start], array[greaterPoint - 1]);
    if (greaterPoint - start > 1)
      quickSort(array, start, greaterPoint - 1);
    if (end - greaterPoint > 0)
      quickSort(array, greaterPoint, end);
  }

  // Performs an in-place ascending sort of *array*
  // using the insertion sort algorithm
  // *start* is the first element of the array to start sorting from
  // *end* is the end element for the elements to be sorted
  // *end* will be the length of the array - 1 for a first run
  // NOTE: You can modify your old implementation from assignment 4
  // OR if you believe yours was incorrect, email me and I will
  // send you mine assuming you are done with assignment 4,
  // but you will still need to modify it for this assignment
  // as described below
  // NOTE: You will need to modify the implementation to only
  // sort part of the array as per the parameters of this version
  template <typename T> void insertionSort(T array[], const int start, const int end) {
    if (end - start + 1 <= 1)
      return;

    for (int i = start + 1; i < end + 1; i++) {
      T sortingValue = array[i];
      int placement = i;
      for (; placement > start; placement--) {
        if (sortingValue < array[placement - 1]) {
          swap(array[placement], array[placement - 1]);
        }
        else
          break;
      }
      //array[placement] = sortingValue;
    }
  }

  // Performs an in-place ascending sort of *array*
  // using merge sort until there is less than 10 elements, and then
  // the insertion sort algorithm
  // *start* is the first element of the array to start sorting from
  // *end* is the end element for the elements to be sorted
  // *end* will be the length of the array - 1 for a first run
  // TIP: You can copy your implementation of merge sort in here, and
  // should be able to call the insertionSort above
  template <typename T> void hybridSort(T array[], const int start, const int end) {
    if (end - start >= 9) {
      int mid = (end + start) / 2;
      hybridSort(array, start, mid);
      hybridSort(array, mid + 1, end);
      merge(array, start, mid, end);
    }
    else
      insertionSort(array, start, end);
  }

}  // namespace csi281

#endif /* sort_hpp */
