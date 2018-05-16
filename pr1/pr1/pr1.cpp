// pr1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Queue"
#include "vector"
#include "iterator"
#include "iostream"
using namespace std;

void print(queue <char> q) //вывод очереди через вектор, это не имеет никакого практического смысла, просто чтобы выполнить задание
{
	vector<char> vec;
	while (!q.empty())
	{
		vec.push_back(q.front());
		q.pop();
	}
	for (unsigned int i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i] << " ";
		q.push(vec[i]);
	}
	std::cout << endl;
}

void print_with_iterators(queue <char> q)
{
	vector<char> vec;
	while (!q.empty())
	{
		vec.push_back(q.front());
		q.pop();
	}
	vector<char>::iterator it;
	for (it = vec.begin(); it != vec.end(); it++)
	{
		std::cout << *it << " ";
		q.push(*it);
	}
	std::cout << endl;
}

int main()
{
	queue <char> q;
	char ch;
	for (int i = 1; i <= 5; i++)
	{
		ch = (char)48 + i; //48 код 0 в ASCII
		q.push(ch);
	}
	cout << "Q " << endl;
	print(q);
	cout << endl;

	//удаляем и добаляем элементы
	cout << "Q-++ " << endl;
	q.pop();
	q.push('!');
	q.push('@');
	print_with_iterators(q);
	cout << endl;

	//создаем еще одну очередь и работаем с 2мя
	cout << "Q2 " << endl;
	vector<char> A = { '#', '%', '%', '`', '$', ']', '*', '~', '&' }, AA;
	queue <char> q2;
	for (int i = 0; i < 9; i++)
		q2.push(A[i]);
	print(q2);
	cout << endl;

	//удаляем n элементов после какогого и добавляем А
	cout << "Q-n+Q2 " << endl;
	int qsize = q.size();
	for (int i = 0; i < qsize; i++)
	{
		if (i < (qsize / 2))
		{
			AA.push_back(q.front());
			q.pop();
		}
		else
			q.pop();
	}
	if (!AA.empty())
		for (int i = 0; i < AA.size(); i++)
			q.push(AA[i]);
	while (!q2.empty())
	{
		q.push(q2.front());
		q2.pop();
	}
	print(q);
	cout << endl;

	//вывод 2х очередей
	cout << "Q ";
	print_with_iterators(q);
	if (q2.empty())
		cout << "Q2 is empty" << endl;
	else
		print(q2);
	system("Pause");
	return 0;
}