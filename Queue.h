/*
 * Queue.h
 *
 *  Created on: 24 Nov 2019
 *      Author: Lina
 */

#ifndef QUEUE_H_
#define QUEUE_H_

#include <iostream>
#include <cstdio>
#include <cstdlib>

using std::cout;
using std::endl;
using std::cerr;

#define SIZE 10

using std::endl;
using std::cerr;

template<class T>
class Queue {
	T *arr;
	int qsize; //maximum size of the queue
	int qnext; //next pointer to the next element

	T* allocate_and_copy(const T* arr, int size, int count);
	void verify_index(int index) const;

public:
	Queue(int size = SIZE);
	//copy constuctor
	Queue(const Queue& q);
	~Queue();

	void dequeue();
	void enqueue(T item);
	int length() const;
	int size() const;
	bool isEmpty();
	bool isFull();

	Queue& operator=(const Queue& q);
	const T& operator[](int index) const;
	const T& operator[](int index);

};

void error(const char*str) {
	cerr << "Error: " << str << endl;
	exit(0);

}

template<class T>
T* Queue<T>::allocate_and_copy(const T* arr, int size_queue, int index) {
	T*arr_new = new T[size_queue];

	for (int i = 0; i <= index; i++) {
		arr_new[i] = arr[i];
	}

	return arr_new;
}

template<class T>
void Queue<T>::verify_index(int index) const {
	if (index >= this->qsize || index < 0) {
		error("Bad index");
	}

}

template<class T>
Queue<T>::Queue(int qsize) {
	this->arr = new T[qsize];
	this->qsize = qsize;
	this->qnext = 0;
}

template<class T>
Queue<T>::Queue(const Queue& q) {
	this->qsize = q.qsize;
	this->qnext = q.qnext;
	this->arr = allocate_and_copy(q.arr, q.qsize, q.qnext);

}

template<class T>
Queue<T>::~Queue() {
	delete[] arr;
}

template<class T>
int Queue<T>::length() const {
	return this->qnext;
}

template<class T>
int Queue<T>::size() const {

	return this->qsize;
}

template<class T>
Queue<T>& Queue<T>::operator=(const Queue<T>& q) {
	if (this == &q) {
		return *this;
	}
	delete[] arr;
	this->qsize = q.qsize;
	this->qnext = q.qnext;
	this->arr = allocate_and_copy(q.arr, q.qsize, q.qnext);
	return *this;
}

template<class T>
const T& Queue<T>::operator[](int index) const {
	verify_index(index);
	return arr[index];

}

template<class T>
const T& Queue<T>::operator[](int index) {
	verify_index(index);
	return arr[index];

}

template<class T>
bool Queue<T>::isEmpty() {
	return (this->qnext == 0);
}

template<class T>
bool Queue<T>::isFull() {
	return (this->qnext == qsize);

}

template<class T>
void Queue<T>::dequeue() {
	if (isEmpty()) {
		std::cout << "the queue is empty, cannot dequeue" << std::endl;
		return;
	}
	qnext--;
}

template<class T>
void Queue<T>::enqueue(T item) {
	if (isFull()) {
		std::cout << "the queue is FULL, cannot enqueue" << std::endl;
		return;
	}
	this->arr[this->qnext] = item;
	this->qnext++;
}

#endif /* QUEUE_H_ */
