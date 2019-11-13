#pragma once
#include <vector>
class Priority {
private:
	vector<int> pq;
	bool prioridad;	//TRUE-->MAYOR		FALSE-->MENOR
	bool comp(int hijo, int padre);
	int comp(int a, int b, bool tipo);
public:
	Priority();
	Priority(bool p);
	void push(int num);
	void pop();
	int top();
	int size();
	bool empty();

	void print();
};

Priority::Priority() {
	prioridad = true;
	pq.push_back(42);
}

Priority::Priority(bool p) {
	prioridad = p ? true : false;
	pq.push_back(42);
}

bool Priority::comp(int a, int b) {
	if (prioridad) {
		//PRIORIDAD MAYOR
		return a > b ? true : false;
	}
	else {
		//PRIORIDAD MENOR
		return a < b ? true : false;
	}
}

int Priority::comp(int a, int b, bool tipo) {
	if (tipo) {
		if (prioridad) {
			return a > b ? a : b;
		}
		else {
			return a < b ? a : b;
		}
	}
	else {
		if (prioridad) {
			return pq.at(a) > pq.at(b) ? a : b;//---
		}
		else {
			return pq.at(a) < pq.at(b) ? a : b;
		}
	}
}

void Priority::push(int num) {
	pq.push_back(num);
	bool sigo = true;
	int index = pq.size() - 1;
	while (index != 1 && sigo) {
		if (comp(pq.at(index), pq.at(index/2))) {
			//swap
			num = pq.at(index / 2);
			pq.at(index / 2) = pq.at(index);
			pq.at(index) = num;

			index = index / 2;
		}
		else {
			sigo = false;
		}
	}
}

void Priority::pop() {
	//SWAP
	int temp = pq.at(1);
	pq.at(1) = pq.at(pq.size() - 1);
	pq.at(pq.size() - 1) = temp;

	//BORRA HOJA
	//pq.erase(pq.begin()+size());
	pq.pop_back();

	//CONDICIÓN POR SI SE BORRÓ EL ÚNICO NODO
	if (size() > 0) {
		int index = 1;
		bool sigo = true;
		//MIENTRAS SEA DE MENOR PRIORIDAD QUE HIJOS Y NO SEA HOJA
		while (sigo && index <= size()/2) {
			int indexHijoP;
			if (index*2+1 <= size()) {
				indexHijoP = comp(index * 2, index * 2 + 1, false);
			}
			else {
				indexHijoP = index * 2;
			}
			if (pq.at(index) != comp(pq.at(index), pq.at(indexHijoP), true)) {
				//SI UNO DE LOS HIJOS ES DE MAYOR PRIORIDAD HAGO EL SWAP
				temp = pq.at(index);
				pq.at(index) = pq.at(indexHijoP);
				pq.at(indexHijoP) = temp;
				index = indexHijoP;
			}
			else {
				//SI LOS HIJOS SON DE MENOR PRIORIDAD NO HAY NECESIDAD DE SEGUIR Y SALGO DEL WHILE
				sigo = false;
			}
		}
	}
}

int Priority::top() {
	return empty() ? -1 : pq.at(1);
}

int Priority::size() {
	return pq.size() - 1;
}

bool Priority::empty() {
	return pq.size() == 1 ? true : false;
}

void Priority::print() {
	for (int i = 1; i < pq.size(); i++) {
		cout << pq.at(i) << " ";
	}
	cout << endl;
}