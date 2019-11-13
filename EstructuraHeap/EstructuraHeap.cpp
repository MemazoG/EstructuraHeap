#include <iostream>
using namespace std;
#include "Priority.h"
int main()
{
	Priority pq;

	pq.push(100);
	pq.push(48);
	pq.push(150);
	pq.push(75);
	pq.push(189);
	pq.push(42);
	pq.push(72);
	pq.push(97);

	pq.print();

	pq.pop();
	//pq.print();
	pq.pop();

	pq.print();

	pq.push(165);
	pq.push(110);

	pq.print();

	pq.pop();

	pq.print();

	/*pq.push(14);
	pq.push(10);
	pq.push(8);
	pq.push(25);
	pq.push(73);
	pq.push(5);

	pq.print();

	cout << "TOP: " << pq.top() << endl;
	cout << "SIZE: " << pq.size() << endl;

	pq.pop();

	pq.print();

	cout << "TOP: " << pq.top() << endl;
	cout << "SIZE: " << pq.size() << endl; */
}