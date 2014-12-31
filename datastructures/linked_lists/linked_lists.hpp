#ifndef LINKED_LISTS_HPP
#define LINKED_LISTS_HPP

#include "../../common/menu.hpp"

namespace datastructures {
namespace linked_lists {

template <class T>
class SingleList;

common::Menu menu();
SingleList<int> example_list();

template <class T>
class SingleList {
public:
	struct Element {
		Element(T value);
		Element *next_ = nullptr;
		T value_;
	};

	SingleList();
	SingleList(SingleList<T> &other);
	SingleList(SingleList<T> &&other);
	~SingleList();
	SingleList<T> &operator=(const SingleList<T> &other);
	bool empty() const;
	Element *head() const;
	Element *tail() const;
	T &front() const;
	T &back() const;
	void append(T value);
	Element &insert(Element *anchor, T value);
	Element &insert(signed long index, T value);
	void remove(Element *element);
	size_t index_of(Element *element);
	Element *find(T value);
protected:
	Element *head_ = nullptr;
	Element *tail_ = nullptr;
};

template <class T>
void print_list(SingleList<T> &list);

} // namespace linked_lists
} // namespace datastructures

#include "single_list.inl"
#include "print_list.inl"

#endif
