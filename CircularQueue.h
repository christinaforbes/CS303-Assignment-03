// Christina Forbes 3/22/2024 Assignment 3

#pragma once
#include <iostream>
using namespace std;

template<typename T>
class CircularQueue {
  private:
    static const size_t DEFAULT_CAPACITY = 10;
    size_t capacity;
    size_t num_items;
    size_t front_index;
    size_t rear_index;
    T* data;
  public:
    // constructor
    CircularQueue();

    // functions
    void reallocate();
    void push(const T& item);
    void pop();
    bool empty() const;
    T& front();
    const T& front() const;
    size_t size() const;
    void move_to_rear();
};

// creates empty queue
template<typename T>
CircularQueue<T>::CircularQueue() {
  capacity = DEFAULT_CAPACITY;
  num_items = 0;
  front_index = 0;
  rear_index = num_items - 1;
  data = new T[DEFAULT_CAPACITY];
}

// reserves additional memory
template<typename T>
void CircularQueue<T>::reallocate() {
  // doubles capacity of data array
  size_t new_capacity = 2 * capacity;

  T* new_data = new T[new_capacity];
  size_t j = front_index;

  // copies data into new data array
  for (size_t i = 0; i < num_items; i++) {
    new_data[i] = data[j];
    j = (j + 1) % capacity;
  }

  front_index = 0;
  rear_index = num_items - 1;
  capacity = new_capacity;

  // exchanges contents of new data array with contents of old data array
  swap(data, new_data);
  // deletes old data array
  delete[] new_data;

  return;
}

// adds item to end of queue
template<typename T>
void CircularQueue<T>::push(const T& item) {
  // queue is full
  if (num_items == capacity) {
    reallocate();
  }

  rear_index = (rear_index + 1) % capacity;
  data[rear_index] = item;
  num_items++;
  return;
}

// removes item from start of queue
template<typename T>
void CircularQueue<T>::pop() {
  try {
    // queue is empty
    if (empty()) {
      throw runtime_error("Queue is empty. No front item to pop");
    }

    front_index = (front_index + 1) % capacity;
    num_items--;
  }
  catch (runtime_error& e) {
    cout << e.what() << endl;
  }
 
  return;
}

// checks if queue is empty
template<typename T>
bool CircularQueue<T>::empty() const {
  return (num_items == 0);
}

// returns item at start of queue
// undefined when queue is empty
template<typename T>
T& CircularQueue<T>::front() {
  return data[front_index];
}

// returns item at start of queue
// undefined when queue is empty
template<typename T>
const T& CircularQueue<T>::front() const {
  return data[front_index];
}

// returns number of items in queue
template<typename T>
size_t CircularQueue<T>::size() const {
  return num_items;
}

// removes item at front of queue and adds it to the end
template<typename T>
void CircularQueue<T>::move_to_rear() {
  T val = this->front();
  this->pop();
  this->push(val);
  return;
}