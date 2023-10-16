# count, count_if
#ranges #comparison #iterators

```cpp
ptrdiff_t count(InputIterator first, InputIterator last, const T& value)
ptrdiff_t count_if(InputIterator first, InputIterator last, UnaryPredicate p)
```
- Возвращает количество элементов в множестве, равных `value`.
- Возвращает количество элементов в множестве, для которых предикат $p$ возвращает `true`.
###### Сложность 
$$O(n)$$
###### Пример применения:
```cpp
vector<int> vec = {1, 4, 6, 7, 9, 12, 12, 12, 17, 20};
cout << count(vec.cbegin(), vec.cend(), 12) << '\t';
cout << count_if(vec.begin(), vec.end(), [](auto i){ return i % 2 == 1; });
```
`Вывод:`
```bash
3    4
```
###### Пример реализации
```cpp
ptrdiff_t count(InputIterator first, InputIterator last, const T& value) {
	ptrdiff_t ret = 0;
    for(; first != last; ++first)
        if(*first == value)
            ++ret;
    return ret;
}

ptrdiff_t count_if(InputIterator first, InputIterator last, UnaryPredicate p) {
	ptrdiff_t ret = 0;
    for(; first != last; ++first)
        if(p(*first))
		    ++ret;
    return ret;
}
```
