```cpp
#include <algorithm>
```

- [`all_of`, `any_of`, `none_of`](range/analysis/all_of) - выполняется ли условие для *каждого/любого/ни одного* из элементов в множестве. 
- [`for_each`, `for_each_n`](range/non-modifying/for_each) - выполняет функцию для *каждого* или для *первых $n$* элементов множества.
- [`count`, `count_if`](range/analysis/count) - возвращает список элементов, удовлетворяющих выбранному критерию.
- [`mismatch`](range/analysis/mismatch) - возвращает позицию во множестве, в котором два множества отличаются.
- [`find`, `find_if`, `find_if_not`](range/analysis/find) - возвращает первый элемент, удовлетворяющий выбранному критерию.
- [`find_end`, `find_first_of`](range/analysis/find_end) - возвращает позицию *последнего*/*первого* вхождения множества $B$ во множестве $A$.
- [`adjacent_find`](range/analysis/adjacent_find) - ищет идущую подряд пару одинаковых элементов в множестве.
- [`search`](range/analysis/search) - ищет множество $B$ в множестве $A$.
- [`search_n`](range/analysis/search_n) - ищет $n$ последовательных вхождений выбранного элемента во множестве.