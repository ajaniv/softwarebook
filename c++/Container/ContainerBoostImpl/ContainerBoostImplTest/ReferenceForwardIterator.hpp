/**
 * \file ReferenceForwardIterator.hpp
 * \brief Sample reference forward iterator
 *
 */


/*
 * This file is part of OndALear  collection of open source components.
 *
 * This software is provided 'as-is', without any express or implied
 * warranty.  In no event will the authors be held liable for any damages
 * arising from the use of this software.
 *
 * Copyright (C) 2008 Amnon Janiv <amnon.janiv@ondalear.com>
 *
 * Initial version: 2011-11-11
 * Author: Amnon Janiv <amnon.janiv@ondalear.com>
 */

/*
 * $Id:  $
 */

#ifndef ONDALEAR_TEST_ReferenceForwardIterator_HPP
#define ONDALEAR_TEST_ReferenceForwardIterator_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

namespace ondalear {
namespace test {
namespace container {
namespace boostimpl {


template <typename T>
class FixedArray
{
    public:

        typedef int size_type;

        class iterator 
        {
            public:
                typedef iterator self_type;
                typedef T value_type;
                typedef T& reference;
                typedef T* pointer;
                typedef std::forward_iterator_tag iterator_category;
                typedef int difference_type;
                iterator(pointer ptr) : ptr_(ptr) { }
                self_type operator++() { self_type i = *this; ptr_++; return i; }
                self_type operator++(int junk) { ptr_++; return *this; }
                reference operator*() { return *ptr_; }
                pointer operator->() { return ptr_; }
                bool operator==(const self_type& rhs) { return ptr_ == rhs.ptr_; }
                bool operator!=(const self_type& rhs) { return ptr_ != rhs.ptr_; }
            private:
                pointer ptr_;
        };

        class const_iterator 
        {
            public:
                typedef const_iterator self_type;
                typedef T value_type;
                typedef T& reference;
                typedef T* pointer;
                typedef int difference_type;
                typedef std::forward_iterator_tag iterator_category;
                const_iterator(pointer ptr) : ptr_(ptr) { }
                self_type operator++() { self_type i = *this; ptr_++; return i; }
                self_type operator++(int junk) { ptr_++; return *this; }
                const T& operator*() { return *ptr_; }
                const pointer operator->() { return ptr_; }
                bool operator==(const self_type& rhs) { return ptr_ == rhs.ptr_; }
                bool operator!=(const self_type& rhs) { return ptr_ != rhs.ptr_; }
            private:
                pointer ptr_;
        };
     

        FixedArray(size_type size) : size_(size) {
            data_ = new T[size_];
        }

        size_type size() const { return size_; }
        
        T& operator[](size_type index) 
        { 
            assert(index < size_);
            return data_[index]; 
        }

        const T& operator[](size_type index) const
        {
            assert(index < size_);
            return data_[index];
        }

        iterator begin()
        {
            return iterator(data_);
        }

        iterator end()
        {
            return iterator(data_ + size_);
        }

        const_iterator begin() const
        {
            return const_iterator(data_);
        }

        const_iterator end() const
        {
            return const_iterator(data_ + size_);
        }

    private:
        T* data_;
        size_type size_;
};

} //namespace boostimpl
} //namespace container
} //namespace test
} //namespace ondalear




#endif //ONDALEAR_TEST_ReferenceForwardIterator_HPP