# `all_of`, `any_of`, `none_of`
#ranges #comparison #iterators

```cpp
bool all_of(Iterator first, Iterator last, UnaryPredicate p)
bool any_of(Iterator first, Iterator last, UnaryPredicate p)
bool none_of(Iterator first, Iterator last, UnaryPredicate p)
```
- Возвращает `true`, если предикат $p$ возвращает `true` для каждого элемента во множестве.
- Возвращает `true`, если предикат $p$ возвращает `true` для любого из элементов во множестве.
- Возвращает `true`, если предикат $p$ возвращает `false` для каждого элемента во множестве.
###### Сложность 
$$O(n)$$
###### Пример применения:
```cpp
vector<int> vec = {1, 4, 6, 8, 10, 12, 14, 16, 18, 20};
bool all_even = all_of(vec.cbegin(), vec.cend(), [](int x){ return x % 2 == 0; });
bool any_odd = any_of(vec.cbegin(), vec.cend(), [](int x){ return x % 2 == 1; });
bool none_odd = none_of(vec.cbegin(), vec.cend(), [](int x){ return x % 2 == 1; });
cout << all_even << ' ' << any_odd << ' ' << none_odd;
```
`Вывод:`
```bash
false true false
```
###### Пример реализации
```cpp
bool all_of(Iterator first, Iterator last, UnaryPredicate p) {
	return std::find_if_not(first, last, p) == last;
}

bool any_of(Iterator first, Iterator last, UnaryPredicate p) {
	return std::find_if(first, last, p) != last;
}

bool none_of(Iterator first, Iterator last, UnaryPredicate p) {
	return std::find_if(first, last, p) == last;
}
```
