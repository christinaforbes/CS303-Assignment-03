// Christina Forbes 3/22/2024 Assignment 3

#pragma once
#include <iostream>
#include <list>
#include <vector>
#include "CircularQueue.h"
using namespace std;

// PRE:   accepts a vector (vec)
// POST:  outputs vec's contents
template<typename T>
void printVector(vector<T> vec) {
  for (T item : vec) {
    cout << item << " ";
  }
  cout << endl;
  return;
}

// PRE:   accepts a list (li)
// POST:  outputs li's contents
template<typename T>
void printList(list<T> li) {
  list<T>::template iterator itr;
  for (itr = li.begin(); itr != li.end(); itr++) {
    cout << *itr << " ";
  }
  cout << endl;
  return;
}

// PRE:   accepts a vector (items) passed by reference, item to find (target) passed by reference,
//          and index of last element in items (pos_last)
// POST:  if target is found, returns index of last occurrence of target; else, returns -1
template<typename T>
int linear_search(vector<T>& items, T& target, int pos_last) {
  if (pos_last < 0) {
    return -1;
  }

  if (target == items[pos_last]) {
    return pos_last;
  }

  else {
    return linear_search(items, target, pos_last - 1);
  }
};

void insertion_sort(list<int>& num);
// PRE:   accepts a list of integers (num) passed by reference
// POST:  sorts items in num using insertion sort algorithm

void printQueueExample();
// PRE:   none
// POST:  outputs items in an integer queue

void printLinearSearchExample();
// PRE:   none
// POST:  searches an integer vector for a specified item
//        if item is found, outputs index of last ocurrence in vector; else, outputs -1

void printInsertionSortExample();
// PRE:   none
// POST:  sorts an integer (linked) list and outputs sorted list