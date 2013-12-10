#ifndef HEAP_H
#define HEAP_H
#include <string>
#include <iostream>
#include <assert.h>
#include <vector>
#include <cctype>
#include <algorithm>
#include "Board.h"
using namespace std;
template <class T> // T must be comparable

/**
*
*	Heap Class
*	
*	Mike Santry
*	11/23/13
*
*	This class is primarily used to store and locate neighbor bords.
*
**/




class Heap
{
	private:
		vector<T> theHeap;
		int n; // # of items in the heap

	public:
		


		Heap() {
			theHeap.push_back(T()); // T must have an empty constructor
			n = 0;
		}

		Heap(const vector<T> & data ) : theHeap(data.size()+1)
		{
			for (int i = 0; i < data.size(); ++i)
			{
				theHeap[i+1] = data[i];
			}
			n = data.size();
			for (int i = n/2; i > 0; --i)
			{
				heapifyDown(i);
			}
		}
		/* return and delete the minimum value 
			assume that the heap is not empty
			**/
		T deleteMin()
		{
			assert(n>0); // aborts program if false
			T returnMe = theHeap[1];
			theHeap[1] = theHeap[n]; // move last thing up
			n = n-1;
			heapifyDown(1);
			return returnMe;
		}

		/**
		 * insert item into the heap
		 * @param T item a comparable item
		 **/
		void insert(T item)
		{
			if (n+1 < theHeap.size())
			{
				theHeap[n+1] = item;
			}
			else
			{
				theHeap.push_back(item);
			}
			n = n+1;
			heapifyUp(n);
		}

		int size() const { return n;}
		bool empty() const { return (n==0);}

	private:
		void swap(T & a, T &b)
		{
			T temp = a;
			a = b;
			b = temp;
		}

		/**
		 * restore the heap property up the tree, starting at
		 * node i
		 **/
		void heapifyUp(int i)
		{
			int parent = i / 2;
			if ((parent == 0) || (theHeap[parent] < theHeap[i])) {
				return;
			}
			swap(theHeap[parent],theHeap[i]);
			heapifyUp(parent);
		}

		/**
		 * restore the heap property down the tree, starting at
		 * node i
		 **/
		void heapifyDown(int i)
		{
			int left = 2 *i;
			int right = left + 1;
			int swapMe = left; // swapMe is the index to be swapped
			/* do I have a right child? */
			if (right  <= n) {
				if (theHeap[right] < theHeap[left]){
					swapMe = right;
				}
			}
			/** swapMe is either an index of a child
			* that does not exist, or is the correct
			* child to compare with the value at i
			**/
			if (swapMe <= n) // valid index
			{
				if (theHeap[swapMe] < theHeap[i]) {
					swap(theHeap[swapMe], theHeap[i]);
					heapifyDown(swapMe);
				}
			}
		}
};


#endif
