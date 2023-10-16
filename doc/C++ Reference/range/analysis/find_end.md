# `find_end`
#ranges #comparison #iterators

```cpp
Iterator find_end(Iterator first1, Iterator last1, Iterator first2, Iterator last2)
Iterator find_end(Iterator first1, Iterator last1, Iterator first2, Iterator last2, BinaryPredicate p)
Iterator find_first_of(Iterator first1, Iterator last1, Iterator first2, Iterator last2)
Iterator find_first_of(Iterator first1, Iterator last1, Iterator first2, Iterator last2, BinaryPredicate p)
```
- Возвращает *итератор* на **последнее**/**первое** вхождение множества $B$ в множество $A$.
- Элементы сравниваются либо с помощью оператора `==`, либо с помощью предиката $p$.
- Возвращает $last1$, если вхождений не найдено.
###### Сложность 
$$O(n)$$
###### Требования к лямбда-функции:
Должна удовлетворять сигнатуре
```cpp
bool p(const T1& a, const T2& b)
```
###### Пример применения:
```cpp
auto print_result = [](auto result, const auto& v){
    result == v.end() ? cout << "Sequence not found\n"
				      : cout << "Last occurrence is at: " << distance(v.begin(), result)
                             << endl;
};
 
const auto v = {1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4};
for(auto const& x : {array{1, 2, 3}, {4, 5, 6}}) {
    auto iter = find_end(v.begin(), v.end(), x.begin(), x.end()); 
    print_result(iter, v);
}
for(auto const& x : {array{-1, -2, -3}, {-4, -5, -6}}) {
    auto iter = find_end(v.begin(), v.end(), x.begin(), x.end(), 
        [](int x, int y){ return std::abs(x) == std::abs(y); });
    print_result(iter, v);
}
```
`Вывод:`
```bash
Last occurrence is at: 8
Sequence not found
Last occurrence is at: 8
Sequence not found
```
###### Пример реализации
```cpp
Iterator find_end(Iterator first1, Iterator last1, 
				  Iterator first2, Iterator last2/*, BinaryPredicate p*/) {
	if(first2 == last2) return last1;
	Iterator res = last1;
	while(true) {
		Iterator new_res = search(first1, last1, first2, last2/*, p*/);
		if(new_result == last) break;
		else {
			res = new_res;
			first1 = res;
			++first1;
		}
	}
	return res;
}

Iterator find_first_of(Iterator first1, Iterator last1,
					   Iterator first2, Iterator last2/*, BinaryPredicate p*/) {
	for(; first1 != last1; ++first1)
		for(Iterator it = first2; it != last2; ++it)
			if(*first1 == *it /*p(*first1, *it)*/) return first1;
	return last1;
}
```
