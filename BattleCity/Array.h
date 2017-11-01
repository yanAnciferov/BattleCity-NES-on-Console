#pragma once


class going_beyond_the_array : public exception
{
public:
	going_beyond_the_array() : exception("going_beyond_the_array") {};
};



class not_a_valid_value : public exception
{
public:
	not_a_valid_value() : exception("not a valid value") {};
};



template<typename T>
class Array
{
	int _count = 0;
	T* _p = nullptr;

public:
	~Array();
	Array() = default;
	Array(const Array<T>& arr);
	Array(Array<T>&& arr);
	Array(int len, T value);
	T& getOnIndex(size_t index);
	int getCount();
	void copy(const Array<T>& arr);
	void clear();
	void add(T value);
	void removeOnIndex(int index);

	T& operator[](int index)
	{
		if (index < 0)
			throw not_a_valid_value();
		if (index  > _count - 1)
			throw going_beyond_the_array();

		return _p[index];
	}

	T operator[](int index) const 
	{
		if (index < 0)
			throw not_a_valid_value();
		if (index  > _count - 1)
			throw going_beyond_the_array();

		return _p[index];
	}

	void insert(int index, T value);

	Array<T> operator+(Array<T> a);
	Array<T>& operator= (Array<T> a);
	bool operator==(Array<T> a);
	Array& operator+=(Array<T> a);
	

	void sort()
	{
		qick_sort(_p, 0, _count - 1);
	}
};

#pragma region
template<typename T>
Array<T>::~Array()
{
	delete[]_p;
}
template<typename T>
Array<T>::Array(const Array<T>& arr)
{
	copy(arr);
}
template<typename T>
Array<T>::Array(Array<T>&& arr)
{

	_p = arr._p;
	_count = arr._count;

	arr._p = 0;
	arr._count = 0;

}



template<typename T>
void Array<T>::insert(int index, T value)
{
	if (index < 0)
		throw not_a_valid_value();
	if (index  > _count - 1)
		throw going_beyond_the_array();

	T * tmp = new T[_count + 1];
	for (size_t i = 0; i < index; i++)
	{
		tmp[i] = _p[i];
	}
	tmp[index] = value;
	for (size_t i = index + 1; i < _count + 1; i++)
	{
		tmp[i] = _p[i - 1];
	}
	delete[]_p;
	_p = tmp;
	_count++;
}


template<typename T>
Array<T>::Array(int len, T value)
{

	_count = len;
	
	_p = new T[_count];
	for (int i = 0; i < _count; i++)
	{
		_p[i] = value;
	}
}
template<typename T>
T& Array<T>::getOnIndex(size_t index)
{
	if (index < 0)
		throw not_a_valid_value();
	if (index  > _count - 1)
		throw going_beyond_the_array();

	return _p[index];
}
template<typename T>
int Array<T>::getCount()
{
	return _count;
}
template<typename T>
void Array<T>::copy(const Array<T>& arr)
{
	_count = arr._count;
	_p = new T[_count];
	for (size_t i = 0; i < _count; i++)
	{
		_p[i] = arr._p[i];
	}
}
template<typename T>
void Array<T>::clear()
{
	delete[] _p;
	_count = 0;
}



template<typename T>
void Array<T>::add(T value)
{
	T * tmp = new T[_count + 1];
	for (size_t i = 0; i < _count; i++)
	{
		tmp[i] = _p[i];
	}
	tmp[_count] = value;
	delete[]_p;
	_p = tmp;
	_count++;
}
template<typename T>
void Array<T>::removeOnIndex(int index)
{
	if (index < 0)
		throw not_a_valid_value();
	if (index  > _count - 1)
		throw going_beyond_the_array();

	T * tmp = new T[_count - 1];
	for (size_t i = 0; i < index; i++)
	{
		tmp[i] = _p[i];
	}
	for (size_t i = index; i < _count - 1; i++)
	{
		tmp[i] = _p[i + 1];
	}
	delete[]_p;
	_p = tmp;
	_count--;
}
template<typename T>
Array<T> Array<T>::operator+(Array<T> a)
{
	Array<T> tmp;
	tmp._count = _count + a._count;
	tmp._p = new T[_count + a._count];
	for (int i = 0; i < _count; i++)
	{
		tmp._p[i] = _p[i];
	}
	for (int i = _count; i < a._count + _count; i++)
	{
		tmp._p[i] = a._p[i - _count];
	}
	return tmp;
}
template<typename T>
Array<T>& Array<T>::operator= (Array<T> a)
{
	if (*this == a)
	{
		return a;
	}
	clear();
	copy(a);
	return *this;

}
template<typename T>
bool Array<T>::operator==(Array<T> a)
{
	if (_count == a._count)
	{
		for (int i = 0; i < _count; i++)
		{
			if (_p[i] != a._p[i])
			{
				return 0;
			}
		}
		return 1;
	}
	return 0;
}
template<>
bool Array<char*>::operator==(Array<char*> a)
{
	if (_count == a._count)
	{
		for (int i = 0; i < _count; i++)
		{
			if (!strcmp(_p[i], a._p[i]))
			{
				return 0;
			}
		}
		return 1;
	}
	return 0;
}

template<typename T>
Array<T>& Array<T>::operator+=(Array<T> a)
{


	Array<T> tmp;
	tmp = *this + a;
	clear();
	copy(tmp);
	return tmp;
}

template<typename T>
void  qick_sort(T* arr, int b, int e)
{
	int _b = b;
	int _e = e;
	T centr = arr[e];
	do
	{
		while (arr[_b] < centr)
			_b++;
		while (arr[_e] > centr)
			_e--;
		if (_b <= _e)
		{
			swap(arr[_b], arr[_e]);
			_b++;
			_e--;

		}

	} while (_b <= _e);

	if (_e > b)
		qick_sort(arr, b, _e);
	if (_b < e)
		qick_sort(arr, _b, e);

}

#pragma endregion

