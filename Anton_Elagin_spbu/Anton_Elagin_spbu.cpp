// Елагин_Антон_Алексеевич_СПбГУ_задача.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
using namespace std;
struct part {
	int value;
	part* next;
	part(int val) : value(val), next(nullptr) {}
};
class list {
private:
	part* first;
	int size = 0;
public:
	list() : first(nullptr){}
	~list() {
		while (first != nullptr)
		{
			part* temp = first;
			first = first->next;
			delete temp;
		}
	}
	void app(int value) 
	{
		part* newPart = new part(value);
		if (first == nullptr)
		{
			first = newPart;
			size++;
			return;
		}
		part* curr = first;
		while (curr->next != nullptr)
		{
			curr = curr->next;
		}
		curr->next = newPart;
		size++;
	}
	void del()
	{
		int flag = first->value;
		part* curr = first;
		if (first == nullptr or size == 1)
		{
			return;
		}
		while(curr->next != nullptr)
		{
			if (curr->value == curr->next->value) {
				part* dupl = curr->next;
				curr->next = dupl->next;
				delete dupl;
				size--;
			}
			else 
			{
				curr = curr->next;
			}
		}
	}
	void print()
	{
		part* curr = first;
		while (curr != nullptr)
		{
			cout << curr->value << " ";
			curr = curr->next;
		}
		cout << endl;
	}
};
int main()
{
	list test;
	test.app(1);
	test.app(1);
	test.app(2);
	test.app(3);
	test.app(3);
	test.app(4);
	test.app(4);
	test.app(4);
	test.app(5);
	test.print();
	test.del();
	test.print();
}


