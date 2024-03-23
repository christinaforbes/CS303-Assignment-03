// Christina Forbes 3/22/2024 Assignment 3

#include "CircularQueue.h"
#include "functions.h"
#include <iomanip>
#include <iostream>
using namespace std;

int main() {
  // outputs header for queue
  cout << setfill('-') << setw(20) << "" << endl;
  cout << "QUEUES" << endl;
  cout << setfill('-') << setw(20) << "" << endl << endl;

  printQueueExample();

  // outputs header for linear search
  cout << setfill('-') << setw(20) << "" << endl;
  cout << "LINEAR SEARCH" << endl;
  cout << setfill('-') << setw(20) << "" << endl << endl;

  printLinearSearchExample();

  // outputs header for insertion sort
  cout << setfill('-') << setw(20) << "" << endl;
  cout << "INSERTION SORT" << endl;
  cout << setfill('-') << setw(20) << "" << endl << endl;

  printInsertionSortExample();

  return 0;
}