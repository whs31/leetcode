# `mismatch`
#ranges #comparison #iterators

```cpp
pair<Iterator, Iterator> mismatch(Iterator first, Iterator last, Iterator first2)
pair<Iterator, Iterator> mismatch(Iterator first, Iterator last, Iterator first2, BinaryPredicate p)
pair<Iterator, Iterator> mismatch(Iterator first1, Iterator last1, Iterator first2, Iterator last2)
pair<Iterator, Iterator> mismatch(Iterator first1, Iterator last1, Iterator first2, Iterator last2, BinaryPredicate p)
```
- Возвращает первую встреченную пару *итераторов*, указывающую на несовпадающие элементы во множестве $A$ и $B$.
- Если несовпадения множеств не найдены, то пара будет иметь вид $\{last_{1}, k\}$, где $k$ - последний обработанный итератор из множества $B$.
- Если $last_1$ не указан, то он будет равен $last_{1}+\Delta(last_{1}, first_1)$ 
- Если предикат $p$ не указан, то сравнение будет проводиться через оператор *равенства*.
###### Сложность 
$$O(n)$$
###### Требования к лямбда-функции:
Должна удовлетворять сигнатуре
```cpp
bool p(const T1& a, const T2& b)
```
###### Пример применения:
```cpp
string mirror_ends(const string& in) {
	return string(in.begin(), mismatch(in.begin(), in.end(), in.rbegin()).first);
}

cout << mirror_ends("abXYZba") << endl;
cout << mirror_ends("abca") << endl;
cout << mirror_ends("aba") << endl;
```
`Вывод:`
```bash
ab
a
aba
```
###### Пример реализации
```cpp
pair<Iterator, Iterator> mismatch(Iterator first1, Iterator last1, 
								  Iterator first2, Iterator last2) {
	while(first1 != last1 and first2 != last2 and *first1 == *first2)
		++first1, ++first2;
	return make_pair(first1, first2);
}

pair<Iterator, Iterator> mismatch(Iterator first1, Iterator last1, 
								  Iterator first2, Iterator last2, BinaryPredicate p) {
	while(first1 != last1 and first2 != last2 and p(*first1, *first2))
		++first1, ++first2;
	return make_pair(first1, first2);
}
```
