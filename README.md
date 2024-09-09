### Multiset

<details>
  <summary>Общая информация</summary>
<br />

Multiset (мультимножество) - это ассоциативный контейнер, повторяющий логику множества, но позволяющий хранить идентичные элементы. Такой контейнер отличается от списка или вектора тем, что элементы при попадании в мультимножество так же, как и в множестве, сортируются на лету. Однако так же, как и множество, мультимножество не позволяет обратиться к элементу по индексу, а требует обращения по значению, которое в мультимножестве может повторяться.

</details>

<details>
  <summary>Спецификация</summary>
<br />

*Multiset Member type*

В этой таблице перечислены внутриклассовые переопределения типов (типичные для стандартной библиотеки STL), принятые для удобства восприятия кода класса:

| Member type            | Definition                                                                             |
|------------------------|----------------------------------------------------------------------------------------|
| `key_type`               | `Key` the first template parameter (Key)                                                     |
| `value_type`             | `Key` value type (the value itself is a key)                                                    |
| `reference`              | `value_type &` defines the type of the reference to an element                                                             |
| `const_reference`        | `const value_type &` defines the type of the constant reference                                         |
| `iterator`               | internal class `MultisetIterator<T>` or `BinaryTree::iterator` as internal iterator of tree subclass; defines the type for iterating through the container                                                 |
| `const_iterator`         | internal class `MultisetConstIterator<T>` or `BinaryTree::const_iterator` as internal const iterator of tree subclass; defines the constant type for iterating through the container                                           |
| `size_type`              | `size_t` defines the type of the container size (standard type is size_t) |

*Multiset Member functions*

В этой таблице перечислены основные публичные методы для взаимодействия с классом:

| Member functions      | Definition                                      |
|----------------|-------------------------------------------------|
| `multiset()`  | default constructor, creates empty set                                 |
| `multiset(std::initializer_list<value_type> const &items)`  | initializer list constructor, creates the set initizialized using std::initializer_list<T>    |
| `multiset(const multiset &ms)`  | copy constructor  |
| `multiset(multiset &&ms)`  | move constructor  |
| `~multiset()`  | destructor  |
| `operator=(multiset &&ms)`      | assignment operator overload for moving object                                |

*Multiset Iterators*

В этой таблице перечислены публичные методы для итерирования по элементам класса (доступ к итераторам):

| Iterators              | Definition                                                                             |
|------------------------|----------------------------------------------------------------------------------------|
| `iterator begin()`            | returns an iterator to the beginning                                                   |
| `iterator end()`                | returns an iterator to the end                                                         |


*Multiset Capacity*

В этой таблице перечислены публичные методы для доступа к информации о наполнении контейнера:

| Capacity       | Definition                                      |
|----------------|-------------------------------------------------|
| `bool empty()`          | checks whether the container is empty           |
| `size_type size()`           | returns the number of elements                  |
| `size_type max_size()`       | returns the maximum possible number of elements |

*Multiset Modifiers*

В этой таблице перечислены публичные методы для изменения контейнера:

| Modifiers              | Definition                                                                             |
|------------------------|----------------------------------------------------------------------------------------|
| `void clear()`                  | clears the contents                                                                    |
| `iterator insert(const value_type& value)`                 | inserts node and returns iterator to where the element is in the container                                        |
| `void erase(iterator pos)`                  | erases element at pos                                                                        |
| `void swap(multiset& other)`                   | swaps the contents                                                                     |
| `void merge(multiset& other)`                  | splices nodes from another container                                                   |

*Multiset Lookup*

В этой таблице перечислены публичные методы, осуществляющие просмотр контейнера:

| Lookup                 | Definition                                                                             |
|------------------------|----------------------------------------------------------------------------------------|
| `size_type count(const Key& key)`                  | returns the number of elements matching specific key                                   |
| `iterator find(const Key& key)`                   | finds element with specific key                                                        |
| `bool contains(const Key& key)`               | checks if the container contains element with specific key                             |
| `std::pair<iterator,iterator> equal_range(const Key& key)`            | returns range of elements matching a specific key                                      |
| `iterator lower_bound(const Key& key)`            | returns an iterator to the first element not less than the given key                   |
| `iterator upper_bound(const Key& key)`            | returns an iterator to the first element greater than the given key                    |

</details>

<details>
  <summary>Для тестирования</summary>
<br />
  Зайти в репозиторий

  Ввести в командную строку ''make''  
  Чтобы посмотреть покрытие через браузер, надо открыть файл multiset_coverage_report.html после использования ''make''
</details>

<details>
  <summary>Для использования</summary>
<br />
  Достаточно добавить #include "s21_multiset.h" в заголовок проекта, в котором собираетесь его использовать
</details>
