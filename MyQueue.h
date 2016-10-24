#ifndef _MYQUEUE_H_
#define _MYQUEUE_H_
#include <iostream>
#include "MyList.h"

template<class T>
class queue
{
public:
	queue() : _first(NULL), _last(_first), _size(0) {}
	queue(const queue<T> &other);
	~queue();
	T& front();
	T& back();
	bool empty();
	size_t size();
	void clear();
	void push(const T& element);
	void pop();
	friend queue<T> operator+(const queue<T> &lhs, const queue<T> &rhs) {
        	queue<T> Q;
		Q = lhs;
		list<T> *RFirst = rhs._first;
		while(RFirst != NULL)  {
                        Q.push(RFirst->_x);
                        RFirst = RFirst->_next;
                }
        	return Q;
	}
	bool operator==(const queue<T>& other);
	bool operator!=(const queue<T>& other);
	queue<T>& operator=(const queue<T>& other);
	friend std::ostream& operator<<(std::ostream& os,const queue<T> &_queue){           
  		if (_queue._size > 0) {
			list<T> *_FIRST = _queue._first;
			list<T> *FIRST = _queue._first;
        		while (_FIRST != 0) {
                		os << _FIRST->_x << std::endl;
               			_FIRST = _FIRST->_next;
       			}
		}
		else
			throw 3;
        	return os;	
	}
	void QueueSort();
		
private:
	list<T> *_first;
	list<T> *_last;
	size_t _size;
};

template<class T>
queue<T>::queue(const queue<T> &other) {
  	if (other._size == 1) {
		list<T> *L = new list<T>;
        	L->_x = other._first->_x;
        	_first = _last = L;
        	L = NULL;
        	delete L;
		++_size;
	}
	if (other._size > 1) {
		std::cout << "true1" << std::endl;
		list<T> *FIRST = other._first;
		std::cout << "true2" << std::endl;
		while (FIRST != NULL) {
			(*this).push(FIRST->_x);
			FIRST = FIRST->_next;
		}
	}
	/*		std::cout << "true3" << std::endl;
             		list<T> *Q = new list<T>;
              		Q->_x = FIRST->_x;
			std::cout << Q->_x << std::endl;
			std::cout << "0";
               		_last->_next = Q;
			std::cout << "1";
                	_last = Q;
			std::cout << "2";
			std::cout <<  "etetw";
			std::cout << other._first->_next->_x << std::endl;
			FIRST = FIRST->_next;
               		Q = NULL;
               		delete Q;
//			std::cout << "true4" << std::endl;
			++_size;
			}
		}
	*/

}

template<class T>
queue<T>::~queue() {
	for(list<T> *cur = _first; cur != NULL; cur = cur->_next)
		delete cur;
}
template<class T>
T& queue<T>::front()
{
	if (_size != 0)
		return _first->_x;
	throw 2;
}
template<class T>
void queue<T>::clear() {
	if (_size > 0){
		for(list<T> *cur = _first; cur != NULL; cur = cur->_next)
        	        delete cur;
	_size = 0;
	_first = NULL;
	_last = _first;
	}
}
template<class T>
T& queue<T>::back()
{
	if (_size != 0)
		return _last->_x;
	throw 2;
}
template<class T>
bool queue<T>::empty()
{
	return _size == 0;
}
template<class T>
size_t queue<T>::size()
{
	return _size;
}
template<class T>
void queue<T>::push(const T& element)
{
	
	if (_size > 0)
	{
		list<T> *Q = new list<T>;
		Q->_x = element;
		_last->_next = Q;
		_last = Q;
		Q = NULL;
		delete Q;
	}
	else
	{
		list<T> *L = new list<T>;
		L->_x = element;
		_first = _last = L;
		L = NULL;
		delete L;
	}
	++_size;
}
template<class T>
void queue<T>::pop()
{
	if (_size == 1)
	{
		delete _last;
		_last = _first = 0;
	}
	if (_size > 1)
	{
     		list<T> *FIRST = _first;
		delete FIRST;
		_first = _first->_next;
	}
	if (_size <= 0)
		throw 1;
	else
		--_size;
}
template<class T>
bool queue<T>::operator==(const queue<T> &other)
{
	if (_size != other._size)
		return false;
	list<T> *FIRST = _first;
	list<T> *OTHERFIRST = other._first;
	while (FIRST != _last)
	{	
		if (FIRST->_x != OTHERFIRST->_x)
			return false;
		FIRST = FIRST->_next;
		OTHERFIRST = OTHERFIRST->_next;
	}
	if (_last->_x != other._last->_x)
		return false;
	return true;
}
template<class T>
bool queue<T>::operator!=(const queue<T> &other)
{
	return !((*this) == other);
}
template<class T>
queue<T>& queue<T>::operator=(const queue<T>& other) {
	list<T> *FIRST = other._first;
	(*this).clear();
	while (FIRST != 0){
		(*this).push(FIRST->_x);
		FIRST = FIRST->_next;
	}
	return *this;
}
template<class T>
void queue<T>::QueueSort() {
	list<T> *FIRST = _first;
	while (_first != 0) {
		T min = _first->_x;
		list<T> *Qmin = _first;
		list<T> *_FIRST = _first;
		while (_FIRST != 0) {
			if (_FIRST->_x < min) {
				min = _FIRST->_x;
				Qmin = _FIRST;
			}
			_FIRST = _FIRST->_next;
		}
		T tmp = _first->_x;
		_first->_x = min;
		Qmin->_x = tmp;
		_first = _first->_next;
	}
	_first = FIRST;
}


#endif
