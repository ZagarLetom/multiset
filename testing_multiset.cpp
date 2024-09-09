#include <gtest/gtest.h>

#include "s21_containersplus.h"

TEST(Constructor_MULTISET, def_const) {
  s21::multiset<int> intMultiset({1, 2, 3, 4, 5, 5, 6, 2, 4, 4, 4});
  s21::multiset<int> intMultiset2({100, 200, 300, 400});
  s21::multiset<int> intCopy(intMultiset);
  intMultiset = intMultiset2;
  s21::multiset<int> multiset3(std::move(intMultiset));
  s21::multiset<int> multiset4;
  multiset4 = std::move(multiset3);
}

TEST(Methods_MULTISET, empty_size_max) {
  s21::multiset<int> set1({1, 2, 3});
  EXPECT_EQ(0, set1.empty());
  EXPECT_EQ(3, set1.size());
  std::cout << "max size is " << set1.max_size() << std::endl;
}

TEST(Methods_MULTISET, erase) {
  s21::multiset<int> set1({1, 2, 3});
  set1.erase(set1.find(0));
  set1.erase(set1.find(52));
  set1.erase(set1.find(2));
  set1.erase(set1.find(2));

  EXPECT_EQ(2, set1.size());
  auto it = set1.begin();
  EXPECT_EQ(1, *it);
  ++it;
  EXPECT_EQ(3, *it);

  set1.insert(1);
  set1.insert(2);
  set1.insert(3);
  set1.insert(4);
  set1.insert(5);
  set1.erase(set1.find(5));
  set1.erase(set1.find(1));
  set1.erase(set1.find(3));
  set1.erase(set1.find(1));
  set1.erase(set1.find(2));
  set1.erase(set1.find(4));
  set1.insert(5);
}

TEST(Methods_MULTISET, merge) {
  s21::multiset<int> set1({1, 2, 3});
  s21::multiset<int> set2({2, 3, 4, 5, 0});
  set1.merge(set2);
  EXPECT_EQ(8, set1.size());
  auto it = set1.begin();
  EXPECT_EQ(0, *it);
  ++it;
  EXPECT_EQ(1, *it);
  ++it;
  EXPECT_EQ(2, *it);
  ++it;
  EXPECT_EQ(2, *it);
  ++it;
  EXPECT_EQ(3, *it);
  ++it;
  EXPECT_EQ(3, *it);
}

TEST(Methods_MULTISET, count) {
  s21::multiset<int> set1({1, 2, 2, 2, 3, 5, 5, 6});
  EXPECT_EQ(3, set1.count(2));
  EXPECT_EQ(2, set1.count(5));
  EXPECT_EQ(1, set1.count(1));
  EXPECT_EQ(0, set1.count(52));
}

TEST(Methods_MULTISET, contains) {
  s21::multiset<int> set1({1, 2, 3});
  EXPECT_EQ(1, set1.contains(1));
  EXPECT_EQ(1, set1.contains(3));
  EXPECT_EQ(0, set1.contains(0));
  EXPECT_EQ(0, set1.contains(12));
}

TEST(Methods_MULTISET, swap) {
  s21::multiset<int> set1({1, 2, 3});
  s21::multiset<int> set2({4, 5, 6, 8});
  set1.swap(set2);
  auto it = set1.begin();
  EXPECT_EQ(4, *it);
}

TEST(Methods_MULTISET, insert_many) {
  s21::multiset<int> set1({1, 2, 3});
  set1.insert_many(1, 2, 3, 4, 5, 0);
  for (auto i = set1.begin(); i != set1.end(); ++i) {
    std::cout << *i << " ";
  }
  std::cout << std::endl;
}

TEST(Iterator, bounds) {
  s21::multiset<int> set1({1, 2, 3, 3, 3, 4, 5});
  EXPECT_EQ(set1.find(3), set1.lower_bound(3));
  EXPECT_EQ(set1.find(4), set1.upper_bound(3));

  EXPECT_EQ(set1.end(), set1.lower_bound(25));
  EXPECT_EQ(set1.end(), set1.upper_bound(163));

  auto range = set1.equal_range(3);
  std::cout << "Elements equal to 3: ";
  for (auto it = range.first; it != range.second; ++it) {
    std::cout << *it << " ";
    EXPECT_EQ(3, *it);
  }
  std::cout << std::endl;
}
