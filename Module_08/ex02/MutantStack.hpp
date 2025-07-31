#pragma once

#include <iostream>
#include <stack> // Last in first out | LIFO
#include <deque>


// template<class T, class Container = std::deque<T>>
// class stack
// {
// 	protected:
// 		Container c;
// }

template<typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack() : std::stack<T>() {}
		~MutantStack() {}

		MutantStack(const MutantStack &copy) : std::stack<T>(copy) {}
		MutantStack &operator=(const MutantStack &copy)
		{
			if (this != &copy)
				std::stack<T>::operator=(copy);
			return *this;
		}

		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

		iterator begin() { return this->c.begin(); }
		iterator end() { return this->c.end(); }
	
		const_iterator begin() const {return this->c.begin(); }
		const_iterator end() const {return this->c.end(); }

		reverse_iterator rbegin() { return this->c.rbegin(); }
		reverse_iterator rend() { return this->c.rend(); }

		const reverse_iterator rbegin() const { return this->c.rbegin(); }
		const reverse_iterator rend() const { return this->c.rend(); }

	private:
};