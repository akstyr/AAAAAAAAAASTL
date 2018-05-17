// pr2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "vector"
#include "algorithm"
#include "iostream"

void print(std::vector<char> vect)
{
	for (int i = 0; i < vect.size(); i++)
	{
		std::cout << vect[i] << " ";
	}
	std::cout << std::endl;
}

int main()
{
	std::vector<char> vect = { 'a','b','c','1','0','9','%' };
	int vsize = vect.size();
	print(vect);
	//сортировать по убыванию
	std::sort(vect.rbegin(), vect.rend());
	print(vect);
	//элемент, удовлетворяющий условию "это 0?"
	char ch = '0';
	std::vector<char>::iterator find_element = find(vect.begin(), vect.end()-1, ch);
	if ( find_element == vect.end() - 1)
		std::cout << "Not found" << std::endl;
	else
		std::cout << "Found" << std::endl;
	//если удовлетворяет условию "это буква?" переместить в другой контейнер
	std::vector<char> vect2;
	for (int i = 0; i < vsize; i++)
	{
		if (isalpha(vect[i]))
			vect2.push_back(vect[i]);
	}
	std::cout << "Vect1 ";
	print(vect);
	std::cout << "Vect2 ";
	print(vect2);
	//Отсортировать первый и второй контейнеры по возрастанию элементов
	std::sort(vect.begin(), vect.end());
	std::sort(vect2.begin(), vect2.end());
	std::cout << "Vect1 ";
	print(vect);
	std::cout << "Vect2 ";
	print(vect2);
	//Получить третий контейнер путем слияния первых двух
	std::vector<char> vect_result;
//	merge(vect.begin(), vect.end()-1, vect2.begin(), vect2.end()-1, vect_result.begin());
	int all_size = vect.size() + vect2.size();
	vsize = vect.size();
	for (int i = 0; i < all_size; i++)
	{
		if (i < vsize)
			vect_result.push_back(vect[i]);
		else
			vect_result.push_back(vect2[i - vsize]);
	}
	std::cout << "Vect3 ";
	print(vect_result);
	//Подсчитать, сколько элементов, удовлетворяющих заданному условию, содержит третий контейнер
	int el = 0;
	for (int i = 0; i < vect_result.size(); i++)
	{
		if (isdigit(vect_result[i]))
			el++;
	}
	std::cout << el << std::endl;
	system("Pause");
    return 0;
}