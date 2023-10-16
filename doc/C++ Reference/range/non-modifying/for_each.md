# `for_each`, `for_each_n`
#ranges #transform #iterators

```cpp
void for_each(InputIterator first, InputIterator last, UnaryFunction f)
InputIterator for_each_n(InputIterator first, size_t n, UnaryFunction f)
```
- Применяет функцию $f$ к каждому элементу в множестве.
- Применяет функцию $f$ к первым $n$ элементам множества и возвращает исходный итератор.
###### Сложность 
$$O(n)$$
###### Пример применения:
```cpp
vector<int> vec = {1, 4, 6, 8, 10, 12, 14, 16, 18, 20};
auto print_lambda = [](const auto& x){ cout << x << ' '; };
auto increment_lambda = [](auto& x){ ++x; };
for_each(vec.cbegin(), vec.cend(), print_lambda);
cout << endl;
for_each(vec.begin(), vec.end(), increment_lambda);
for_each_n(vec.cbegin(), 5, print_lambda);
```
`Вывод:`
```bash
1 4 6 8 10 12 14 16 18 20
2 5 7 9 11 
```
###### Пример реализации
```cpp
void for_each(InputIterator first, InputIterator last, UnaryFunction f) {
	for(; first != last; ++first)
        f(*first);
}

InputIterator for_each_n(InputIterator first, size_t n, UnaryFunction f) {
	for(size_t i = 0; i < n; ++first, (void)++i)
        f(*first);
    return first;
}
```
