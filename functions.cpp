// Christina Forbes 3/22/2024 Assignment 3

#include "functions.h"

void insertion_sort(list<int>& num) {
  int key;

  list<int>::iterator j;

  // iterator for outer loop (j) first points to 2nd item in num
  for (j = next(num.begin()); j != num.end(); ++j) {
    key = *j;

    // iterator for inner loop (i) first points to item before the item pointed to by j
    list<int>::iterator i = j;
    --i;

    while (i != num.begin() && key < *i) {
      // moves current element 1 position to the right
      *next(i) = *i;
      --i;
    }

    // key is less than element at start of list
    if (key < *i) {
      // moves element at i 1 position to the right
      *next(i) = *i; 
      // inserts key element at start of list
      *i = key; 
    }
    else {
      // inserts key element at correct position
      *next(i) = key;
    }
  }
}

void printQueueExample() {
  // creates integer queue
  CircularQueue<int> queue1;

  // pushes values to queue
  queue1.push(10);
  queue1.push(81);
  queue1.push(92);
  queue1.push(8);
  queue1.push(71);
  queue1.push(30);
  queue1.push(85);
  queue1.push(96);
  queue1.push(19);
  queue1.push(53);

  // outputs queue's contents
  cout << "Queue: ";
  for (int i = 0; i < queue1.size(); i++) {
    cout << queue1.front() << " ";
    queue1.move_to_rear();
  }
  cout << endl << endl;

  return;
}

void printLinearSearchExample() {
  vector<int> vec = { 26, 91, 65, 89, 9, 80, 66, 8, 50, 70, 26 };

  cout << "Vector: ";
  printVector(vec);

  int target = 26;

  // index of last element in vec
  int posLast = vec.size() - 1;

  int targetPos = linear_search(vec, target, posLast);
  cout << "Found '" << target << "' at index " << targetPos << endl << endl;

  return;
}

void printInsertionSortExample() {
  list<int> li = { 66, 50, 13, 12, 21, 3, 40, 95, 81, 31 };

  // outputs list before sorting
  cout << "Unsorted list: ";
  printList(li);

  insertion_sort(li);

  // outputs list after sorting
  cout << "Sorted list: ";
  printList(li);

  cout << endl;
  return;
}