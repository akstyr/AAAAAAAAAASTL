// pr3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "vector"
#include "algorithm"
#include "iostream"
using namespace std;

//template <typename T>//, class Conteiner>
template <typename T, template <typename U, typename = allocator<U>> class Container> //обертка для контейнера
T Min (Container<T> cont)
{
	Container<T>::iterator it = min_element(cont.begin(), cont.end() - 1);
	return *it;
};

template <typename T>
class Maximum
{
public:
	T Max(vector<T> cont)
	{
		vector<T>::iterator it = max_element(cont.begin(), cont.end() - 1);
		return *it;
	};
};

int main()
{
	vector<int> vect = { 1,3,8,9,7,5,6,9,1,8,0 };
	int res = Min(vect);
	cout << res << endl;
	Maximum<int> aaa;
	cout << aaa.Max(vect) << endl;
	system("Pause");
    return 0;
}

