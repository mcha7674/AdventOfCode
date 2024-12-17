#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <math.h>

// This header file will contain useful functions/objects that are built and used as I solve problems.

namespace Helpers
{
	// Print out a vector array
	template<typename T>
	void PrintVector(std::vector<T>& vect)
	{
		std::cout << "[";
		for (auto ele : vect)
		{
			std::cout << ele << ",";
		}
		std::cout << "]" << std::endl;
	}

	// Simple Swap function
	template<typename T>
	void Swap(T &ele1, T& ele2)
	{
		T temp = ele1; // COPY of ele1
		ele1 = ele2; // Replace ele1 with ele2 value
		ele2 = temp; // Replace ele2 with the copy of ele1.
	}

	template<typename T>
	bool BinarySearch_Vect(std::vector<T>& sorted_arr, int low, int high, T& x, int& index)
	{
		while (low <= high) {
			int mid = low + (high - low) / 2;

			// Check if x is present at mid
			if (sorted_arr[mid] == x)
			{
				index = mid;
				return true;
			}

			// If x greater, ignore left half
			if (sorted_arr[mid] < x)
				low = mid + 1;

			// If x is smaller, ignore right half
			else
				high = mid - 1;
		}

		// If we reach here, then element was not present
		return false;
	}

	template<typename T>
	void Heapify(std::vector<T>& arr, int n,  int i)
	{
		// Convert the input array into a MAX HEAP
		int largest = i;
		int l = 2 * i + 1;
		int r = 2 * i + 2;

		// If left child is larger than root
		if (l < n && arr[l] > arr[largest])
			largest = l;

		// If right child is larger than largest so far
		if (r < n && arr[r] > arr[largest])
			largest = r;

		// If largest is not root
		if (largest != i) {
			Swap(arr[i], arr[largest]);

			// Recursively heapify the affected sub-tree
			Heapify(arr, n, largest);
		}
	}

	// The HeapSort algorithm
	template<typename T>
	void HeapSort_Vect(std::vector<T>& arr)
	{
		int n = arr.size();

		// Build heap (rearrange vector)
		for (int i = n / 2 - 1; i >= 0; i--)
			Heapify(arr, n, i);

		// One by one extract an element from heap
		for (int i = n - 1; i > 0; i--)
		{

			// Move current root to end
			Swap(arr[0], arr[i]);

			// Call max heapify on the reduced heap
			Heapify(arr, i, 0);
		}
	}

	// Radix Sort Algorithm
	template<typename T>
	void RadixSort_Vect(std::vector<T> &arr)
	{

	}
	












}