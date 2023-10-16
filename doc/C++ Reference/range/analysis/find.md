# `find`, `find_if`, `find_if_not`
#ranges #comparison #iterators

```cpp
Iterator find(Iterator first, Iterator last, const T& value)
Iterator find_if(Iterator first, Iterator last, UnaryPredicate p)
Iterator find_if_not(Iterator first, Iterator last, UnaryPredicate q)
```
- `find` возвращает *итератор* на первый объект, равный $value$.
- `find_if` возвращает *итератор* на первый объект, для которого предикат $p$ вернул `true`.
- `find_if_not` возвращает *итератор* на первый объект, для которого предикат $q$ вернул `false`.
- Все вышеперечисленные функции вернут $last$, если объект не найден.
###### Сложность 
$$O(n)$$
###### Пример применения:
```cpp
vector<int> vec = { 1, 2, 3, 4 };
if(find(vec.cbegin(), vec.cend(), 2) == v.cend()) cout << "Number 2 not found!" << endl;
else cout << "Number 2 found!" << endl;

if(auto it = find_if(vec.cbegin(), vec.cend(), [](auto x){ return x % 2 == 0; }))
	cout << "Found even number " << *it << endl;
else cout << "Even numbers not found!" << endl;
```
`Вывод:`
```bash
Number 2 found!
Found even number 2
```
###### Пример реализации
```cpp
Iterator find(Iterator first, Iterator last, const T& value) {
	for(; first != last; ++first)
		if(*first == value) return first;
	return last;
}

Iterator find_if(Iterator first, Iterator last, UnaryPredicate p) {
	for(; first != last; ++first)
		if(p(*first)) return first;
	return last;
}

Iterator find_if_not(Iterator first, Iterator last, UnaryPredicate q) {
	for(; first != last; ++first)
		if(not q(*first)) return first;
	return last;
}
```
