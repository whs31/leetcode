# all_of, any_of, none_of
#ranges, #comparison

```cpp
bool all_of(InputIterator first, InputIterator last, UnaryPredicate p)
bool any_of(InputIterator first, InputIterator last, UnaryPredicate p)
bool none_of(InputIterator first, InputIterator last, UnaryPredicate p)
```
- Возвращает `true`, если предикат возвращает `true` для каждого элемента во множестве.
- Возвращает `true`, если предикат возвращает `true` для любого из элементов во множестве.
- Возвращает `true`, если предикат возвращает `false` для каждого элемента во множестве.
###### Сложность 
$$O(n)$$
###### Пример применения:
```cpp
vector<int> vec = {1, 4, 6, 8, 10, 12, 14, 16, 18, 20};
bool all_even = all_of(vec.cbegin(), vec.cend(), [](int x){ return x % 2 == 0; });
bool any_odd = any_of(vec.cbegin(), vec.cend(), [](int x){ return x % 2 == 1; });
bool none_odd = none_of(vec.cbegin(), vec.cend(), [](int x){ return x % 2 == 1; });
// false, true, false
```
###### Пример реализации
```cpp
bool all_of(InputIterator first, InputIterator last, UnaryPredicate p)
{
	return std::find_if_not(first, last, p) == last;
}

bool any_of(InputIterator first, InputIterator last, UnaryPredicate p)
{
	return std::find_if(first, last, p) != last;
}

bool none_of(InputIterator first, InputIterator last, UnaryPredicate p)
{
	return std::find_if(first, last, p) == last;
}
```
