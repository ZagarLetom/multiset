#ifndef S21_multiset_H
#define S21_multiset_H

#include <initializer_list>
#include <iostream>
#include <limits>

namespace s21 {
template <typename Key>
class multiset {
 public:
  using key_type = Key;
  using value_type = Key;
  using reference = value_type&;
  using const_reference = const value_type&;
  using size_type = size_t;

  class Iterator {
   public:
    explicit Iterator(Key* ptr) : ptr_(ptr) {}

    Key& operator*() const { return *ptr_; }
    Key* operator->() { return ptr_; }

    Iterator& operator++() {
      ++ptr_;
      return *this;
    }

    Iterator operator++(int) {
      Iterator tmp = *this;
      ++ptr_;
      return tmp;
    }

    friend bool operator==(const Iterator& a, const Iterator& b) {
      return a.ptr_ == b.ptr_;
    }
    friend bool operator!=(const Iterator& a, const Iterator& b) {
      return a.ptr_ != b.ptr_;
    }

   private:
    Key* ptr_;
  };

  // Member functions

  multiset() : data_(nullptr), size_(0), capacity_(0) {}

  explicit multiset(std::initializer_list<value_type> const& items)
      : multiset() {
    for (const auto& elem : items) {
      insert(elem);
    }
  }

  multiset(const multiset& ms) : multiset() {
    for (const auto& elem : ms) {
      insert(elem);
    }
  }
  multiset(multiset&& ms) : data_(nullptr), size_(0), capacity_(0) {
    *this = std::move(ms);
  }

  ~multiset() { delete[] data_; }

  multiset& operator=(const multiset& ms) {
    if (this != &ms) {
      delete[] data_;
      size_ = ms.size_;
      capacity_ = ms.capacity_;
      data_ = new Key[capacity_];
      for (size_t i = 0; i < size_; ++i) {
        data_[i] = ms.data_[i];
      }
    }
    return *this;
  }

  multiset& operator=(multiset&& ms) noexcept {
    if (this != &ms) {
      delete[] data_;
      data_ = ms.data_;
      size_ = ms.size_;
      capacity_ = ms.capacity_;
      ms.data_ = nullptr;
      ms.size_ = 0;
      ms.capacity_ = 0;
    }
    return *this;
  }

  // Iterators

  Iterator begin() const { return Iterator(data_); }

  Iterator end() const { return Iterator(data_ + size_); }

  // Capacity

  bool empty() const { return size_ == 0; }

  size_type size() const { return size_; }

  size_type max_size() const { return std::numeric_limits<size_t>::max(); }

  // Modifiers

  void clear() { size_ = 0; }

  void insert(const value_type& value) {
    if (size_ == capacity_) {
      capacity_ = capacity_ ? capacity_ * 2 : 1;
      Key* new_data = new Key[capacity_];
      for (size_t i = 0; i < size_; ++i) {
        new_data[i] = data_[i];
      }
      delete[] data_;
      data_ = new_data;
    }
    data_[size_++] = value;
    sort();
  }

  void erase(Iterator pos) {
    if (pos == end()) return;
    for (Iterator it = pos; it != end(); ++it) {
      Iterator tmp = it;
      ++tmp;
      *it = *tmp;
    }
    --size_;
  }

  void swap(multiset& other) {
    std::swap(data_, other.data_);
    std::swap(size_, other.size_);
  }

  void merge(multiset& other) {
    for (const auto& item : other) {
      insert(item);
    }
    other.clear();
  }

  template <typename... Args>
  void insert_many(Args&&... args) {
    (insert(std::forward<Args>(args)), ...);
  }

  // Lookup

  size_t count(const Key& key) {
    size_t c = 0;
    for (auto it = find(key); it != end() && *it == key; ++it) {
      c++;
    }
    return c;
  }

  Iterator find(const Key& key) const {
    for (Iterator it = begin(); it != end(); ++it) {
      if (*it == key) {
        return it;
      }
    }
    return end();
  }

  bool contains(const Key& key) { return find(key) != end(); }

  std::pair<Iterator, Iterator> equal_range(const Key& key) const {
    return {lower_bound(key), upper_bound(key)};
  }

  Iterator lower_bound(const Key& key) const {
    for (Iterator it = begin(); it != end(); ++it) {
      if (!(*it < key)) {
        return it;
      }
    }
    return end();
  }

  Iterator upper_bound(const Key& key) const {
    for (Iterator it = begin(); it != end(); ++it) {
      if (*it > key) {
        return it;
      }
    }
    return end();
  }

 private:
  void sort() {
    for (size_t i = 0; i < size_; ++i) {
      for (size_t j = i + 1; j < size_; ++j) {
        if (data_[i] > data_[j]) {
          Key temp = data_[i];
          data_[i] = data_[j];
          data_[j] = temp;
        }
      }
    }
  }

  Key* data_;
  size_t size_;
  size_t capacity_;
};
}  // namespace s21
#endif  // S21_multiset_H
