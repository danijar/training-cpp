#ifndef SINGLE_LIST_INL
#define SINGLE_LIST_INL

#include "linked_lists.hpp"
#include <stdexcept>

namespace datastructures {
namespace linked_lists {

template <class T>
SingleList<T>::Element::Element(T value) : value_(value) {}

template <class T>
SingleList<T>::SingleList() {}

template <class T>
SingleList<T>::SingleList(SingleList<T> &other)
{
	for (Element *current = other.head(); current; current = current->next_)
		append(current->value_);
}

template <class T>
SingleList<T>::SingleList(SingleList<T> &&other)
{
	head_ = other.head();
	tail_ = other.tail();
}

template <class T>
SingleList<T>::~SingleList()
{
	Element *current = head_;
	while (current) {
		Element *next = current->next_;
		delete current;
		current = next;
	}
}

template <class T>
SingleList<T> &SingleList<T>::operator=(const SingleList<T> &other)
{
	for (Element *current = other.head(); current; current = current->next_)
		append(current->value_);
	return *this;
}

template <class T>
bool SingleList<T>::empty() const
{
	return head_ == nullptr;
}

template <class T>
typename SingleList<T>::Element *SingleList<T>::head() const
{
	if (!head_)
		throw std::out_of_range("The list is empty.");
	return head_;
}

template <class T>
typename SingleList<T>::Element *SingleList<T>::tail() const
{
	if (!tail_)
		throw std::out_of_range("The list is empty.");
	return tail_;
}

template <class T>
T &SingleList<T>::front() const
{
	return head()->value_;
}

template <class T>
T &SingleList<T>::back() const
{
	return tail()->value_;
}

template <class T>
void SingleList<T>::append(T value)
{
	Element *element = new Element(value);
	// Empty list
	if (!head_) {
		head_ = element;
		tail_ = element;
	}
	tail_->next_ = element;
	tail_ = element;
}

template <class T>
typename SingleList<T>::Element &SingleList<T>::insert(Element *anchor, T value)
{
	Element *element = new Element(value);
	// Insert at front
	if (!anchor) {
		element->next_ = head_;
		head_ = element;
		return *element;
	}
	// Insert after anchor
	Element *next = anchor->next_;
	anchor->next_ = element;
	element->next_ = next;
	return *element;
}

template <class T>
typename SingleList<T>::Element &SingleList<T>::insert(signed long index, T value)
{
	// First find anchor, default to front
	Element *anchor = nullptr;
	// Insert before tail on negative index
	if (index < 0) {
		// Count ahead distance from the right
		// Increase distance by one to find anchor left of index
		size_t distance = (index < 0 ? -index : index) + 1;
		Element *current = head_;
		for (; current && 0 < distance; --distance)
			current = current->next_;
		// Already traversed whole list before reaching distance
		if (!current)
			throw std::out_of_range("The index is ouf of range.");
		// From now on also move anchor until current reaches end
		while (current) {
			current = current->next_;
			anchor = anchor->next_;
		}
	}
	// Insert after head
	else if (index > 0) {
		anchor = head_;
		for (size_t i = 0; i < static_cast<size_t>(index - 1); ++i) {
			if (!anchor->next_)
				throw std::out_of_range("The index is out of range.");
			anchor = anchor->next_;
		}
	}
	// Insert at found anchor
	return insert(anchor, value);
}

template <class T>
void SingleList<T>::remove(Element *element)
{
	Element **anchor_next = nullptr;
	// Remove head
	if (element == head_)
		anchor_next = &head_;
	// Remove a following element
	else
		for (Element *anchor = head_; anchor->next_; anchor = anchor->next_)
			if (anchor->next_ == element)
				anchor_next = &anchor->next_, break;
	// Remove element and update anchor pointer
	*anchor_next = element->next_;
	if (!element->next_)
		tail_ = anchor;
	delete element;
}

template <class T>
size_t SingleList<T>::index_of(Element *element)
{
	size_t i = 0;
	for (Element *current = head_; current; current = current->next_, ++i)
		if (current == element)
			return i;
	throw std::out_of_range("The element does not exist in the list.");
}

template <class T>
typename SingleList<T>::Element *SingleList<T>::find(T value)
{
	for (Element *current = head_; current; current = current->next_)
		if (current->value_ == value)
			return current;
	throw std::out_of_range("The value was not found in the list.");
}

} // namespace linked_lists
} // namespace datastructures

#endif
