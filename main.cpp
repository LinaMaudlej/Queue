/*
 * main.cpp
 *
 *  Created on: 24 Nov 2019
 *      Author: Lina
 */

#include "Queue.h"
#include <iostream>
using std::cout;
using std::endl;

int main(int argc, char*argv[]) {

	Queue<int> q(5);
	cout << "size of the queue should be 5 : " << q.size() << endl;

	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	cout << "size of the queue should be 5 : " << q.size() << endl;
	cout << "length of queue should be 3: " << q.length() << endl;
	q.dequeue();

	cout << "size of the queue should be 5 : " << q.size() << endl;
	cout << "length of queue should be 2: " << q.length() << endl;

	q.enqueue(4);

	cout << "elements of queue 1,2,4: " << q[0] << " " << q[1] << " " << q[2]
			<< endl;

	q.dequeue();
	q.dequeue();
	q.dequeue();

	if (q.isEmpty())
		cout << "RIGHT : Queue Is Empty\n";
	else
		cout << "ERROR : Queue Is Not Empty\n";

	if (!q.isFull())
		cout << "RIGHT : Queue Is Not FULL\n";
	else
		cout << "ERROR : Queue Is FULL\n";

	q.enqueue(7);
	q.enqueue(8);
	q.enqueue(12);
	q.enqueue(14);
	q.enqueue(17);

	if (q.isFull())
		cout << "RIGHT : Queue Is FULL\n";
	else
		cout << "ERROR : Queue Is Not FULL\n";

	if (!q.isEmpty())
		cout << "RIGHT : Queue Is Not Empty\n";
	else
		cout << "ERROR : Queue Is Empty\n";

	cout << "elements of queue 7,8,12,14,17: " << q[0] << " " << q[1] << " "
			<< q[2] << " " << q[3] << " " << q[4] << endl;

	return 0;

}
