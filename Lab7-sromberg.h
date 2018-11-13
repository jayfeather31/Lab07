//Lab7-sromberg.h
//Spencer Romberg
//COSC 2030 Fall 2018
//Lab 06
//November 12th, 2018
//Additional credits: Receieved help from Jagadish Banapanally and rosettacode

#ifndef LAB7_H_DEF
#define LAB7_H_DEF
#include <iterator>
#include <algorithm>
#include <iostream>
#include <functional>

//performs a bubble_sort on a random vector
template <typename RandomAccessIterator>
void bubble_sort(RandomAccessIterator begin, RandomAccessIterator end) {
	bool swapped = true;
	while (begin != end-- && swapped) {
		swapped = false;
		for (auto i = begin; i != end; ++i) {
			if (*(i + 1) < *i) {
				std::iter_swap(i, i + 1);
				swapped = true;
			}
		}
	}
}


//performs an insertion sort on a random vector;
template <typename RandomAccessIterator, typename Predicate>
void insertion_sort(RandomAccessIterator begin, RandomAccessIterator end,
	Predicate p) {
	for (auto i = begin; i != end; ++i) {
		std::rotate(std::upper_bound(begin, i, *i, p), i, i + 1);
	}
}

template <typename RandomAccessIterator>
void insertion_sort(RandomAccessIterator begin, RandomAccessIterator end) {
	insertion_sort(
		begin, end,
		std::less<
		typename std::iterator_traits<RandomAccessIterator>::value_type>());
}

//selection_sort begins here
template<typename ForwardIterator> 
void selection_sort(ForwardIterator begin, ForwardIterator end) 
{
	for (auto i = begin; i != end; ++i) {
		std::iter_swap(i, std::min_element(i, end));
	}
}

//mergesort begins here
template<typename RandomAccessIterator, typename Order>
void mergesort(RandomAccessIterator first, RandomAccessIterator last, Order order)
{
	if (last - first > 1)
	{
		RandomAccessIterator middle = first + (last - first) / 2;
		mergesort(first, middle, order);
		mergesort(middle, last, order);
		std::inplace_merge(first, middle, last, order);
	}
}

template<typename RandomAccessIterator>
void mergesort(RandomAccessIterator first, RandomAccessIterator last)
{
	mergesort(first, last, std::less<typename std::iterator_traits<RandomAccessIterator>::value_type>());
}

//quicksort begins here
template<typename T>
T median(T t1, T t2, T t3)
{
	if (t1 < t2)
	{
		if (t2 < t3)
			return t2;
		else if (t1 < t3)
			return t3;
		else
			return t1;
	}
	else
	{
		if (t1 < t3)
			return t1;
		else if (t2 < t3)
			return t3;
		else
			return t2;
	}
}

// helper object to get <= from <
template<typename Order> struct non_strict_op :
	public std::binary_function<typename Order::second_argument_type,
	typename Order::first_argument_type,
	bool>
{
	non_strict_op(Order o) : order(o) {}
	bool operator()(typename Order::second_argument_type arg1,
		typename Order::first_argument_type arg2) const
	{
		return !order(arg2, arg1);
	}
private:
	Order order;
};

template<typename Order> non_strict_op<Order> non_strict(Order o)
{
	return non_strict_op<Order>(o);
}

template<typename RandomAccessIterator,
	typename Order>
	void quicksort(RandomAccessIterator first, RandomAccessIterator last, Order order)
{
	if (first != last && first + 1 != last)
	{
		typedef typename std::iterator_traits<RandomAccessIterator>::value_type value_type;
		RandomAccessIterator mid = first + (last - first) / 2;
		value_type pivot = median(*first, *mid, *(last - 1));
		RandomAccessIterator split1 = std::partition(first, last, std::bind2nd(order, pivot));
		RandomAccessIterator split2 = std::partition(split1, last, std::bind2nd(non_strict(order), pivot));
		quicksort(first, split1, order);
		quicksort(split2, last, order);
	}
}

template<typename RandomAccessIterator>
void quicksort(RandomAccessIterator first, RandomAccessIterator last)
{
	quicksort(first, last, std::less<typename std::iterator_traits<RandomAccessIterator>::value_type>());
}






#endif
