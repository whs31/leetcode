# Операции над множествами
```cpp
#include <algorithm>
```

### Операции, не меняющие исходное множество
- [`all_of`, `any_of`, `none_of`](range/analysis/all_of) - выполняется ли условие для *каждого/любого/ни одного* из элементов в множестве. 
- [`for_each`, `for_each_n`](range/non-modifying/for_each) - выполняет функцию для *каждого* или для *первых $n$* элементов множества.
- [`count`, `count_if`](range/analysis/count) - возвращает список элементов, удовлетворяющих выбранному критерию.
- [`mismatch`](range/analysis/mismatch) - возвращает позицию во множестве, в котором два множества отличаются.
- [`find`, `find_if`, `find_if_not`](range/analysis/find) - возвращает первый элемент, удовлетворяющий выбранному критерию.
- [`find_end`, `find_first_of`](range/analysis/find_end) - возвращает позицию *последнего*/*первого* вхождения множества $B$ во множестве $A$.
- [`adjacent_find`](range/analysis/adjacent_find) - ищет идущую подряд пару одинаковых элементов в множестве.
- [`search`](range/analysis/search) - ищет множество $B$ в множестве $A$.
- [`search_n`](range/analysis/search_n) - ищет $n$ последовательных вхождений выбранного элемента во множестве.

### Операции, меняющие исходное множество
- [`copy`, `copy_if`, `copy_n`, `copy_backward`](range/copy-move/copy)
- [`move`, `move_backward`](range/copy-move/move)
- [`fill`, `fill_n`](range/copy-move/fill)
- [`transform`](range/transform)
- [`generate`, `generate_n`](range/generate/generate)
- [`remove`, `remove_if`](range/removal/remove)
- [`remove_copy`, `remove_copy_if`](range/removal/remove_copy)
- [`replace`, `replace_if`](range/replacement/replace)
- [`replace_copy`, `replace_copy_if`](range/replacement/replace_copy)
- [`reverse`, `reverse_copy`](range/reverse)
- [`rotate`, `rotate_copy`](range/rotate)
- [`shift_left`, `shift_right`](range/shift) (**C++20**)
- [`sample`](range/sample)
- [`unique`, `unique_copy`](range/unique)
### Универсальные операции
- [`swap`, `swap_ranges`, `iter_swap`](common/swap)

### Операции над подмножествами
|[is_partitioned](https://en.cppreference.com/w/cpp/algorithm/is_partitioned "cpp/algorithm/is partitioned")<br><br>(C++11)|determines if the range is partitioned by the given predicate  <br>(function template)|
|[partition](https://en.cppreference.com/w/cpp/algorithm/partition "cpp/algorithm/partition")|divides a range of elements into two groups  <br>(function template)|
|[partition_copy](https://en.cppreference.com/w/cpp/algorithm/partition_copy "cpp/algorithm/partition copy")<br>
|[stable_partition](https://en.cppreference.com/w/cpp/algorithm/stable_partition "cpp/algorithm/stable partition")|divides elements into two groups while preserving their relative order  <br>(function template)|
|[partition_point](https://en.cppreference.com/w/cpp/algorithm/partition_point "cpp/algorithm/partition point")<br><br>(C++11)|locates the partition point of a partitioned range  <br>(function template)|
|##### Sorting operations|   |

### Сортировка
|[is_sorted](https://en.cppreference.com/w/cpp/algorithm/is_sorted "cpp/algorithm/is sorted")<br><br>(C++11)|checks whether a range is sorted into ascending order  <br>(function template)|
|[is_sorted_until](https://en.cppreference.com/w/cpp/algorithm/is_sorted_until "cpp/algorithm/is sorted until")<br><br>(C++11)|finds the largest sorted subrange  <br>(function template)|
|[sort](https://en.cppreference.com/w/cpp/algorithm/sort "cpp/algorithm/sort")|sorts a range into ascending order  <br>(function template)|
|[partial_sort](https://en.cppreference.com/w/cpp/algorithm/partial_sort "cpp/algorithm/partial sort")|sorts the first N elements of a range  <br>(function template)|
|[partial_sort_copy](https://en.cppreference.com/w/cpp/algorithm/partial_sort_copy "cpp/algorithm/partial sort copy")|copies and partially sorts a range of elements  <br>(function template)|
|[stable_sort](https://en.cppreference.com/w/cpp/algorithm/stable_sort "cpp/algorithm/stable sort")|sorts a range of elements while preserving order between equal elements  <br>(function template)|
|[nth_element](https://en.cppreference.com/w/cpp/algorithm/nth_element "cpp/algorithm/nth element")|partially sorts the given range making sure that it is partitioned by the given element  <br>(function template)|
### Операции над сортированными множествами
|##### Binary search operations (on sorted ranges)|   |
|[lower_bound](https://en.cppreference.com/w/cpp/algorithm/lower_bound "cpp/algorithm/lower bound")|returns an iterator to the first element _not less_ than the given value  <br>(function template)|
|[upper_bound](https://en.cppreference.com/w/cpp/algorithm/upper_bound "cpp/algorithm/upper bound")|returns an iterator to the first element _greater_ than a certain value  <br>(function template)|
|[binary_search](https://en.cppreference.com/w/cpp/algorithm/binary_search "cpp/algorithm/binary search")|determines if an element exists in a partially-ordered range  <br>(function template)|
|[equal_range](https://en.cppreference.com/w/cpp/algorithm/equal_range "cpp/algorithm/equal range")|returns range of elements matching a specific key  <br>(function template)|
|##### Other operations on sorted ranges|   |
|[merge](https://en.cppreference.com/w/cpp/algorithm/merge "cpp/algorithm/merge")|merges two sorted ranges  <br>(function template)|
|[inplace_merge](https://en.cppreference.com/w/cpp/algorithm/inplace_merge "cpp/algorithm/inplace merge")|merges two ordered ranges in-place  <br>(function template)|
|##### Set operations (on sorted ranges)|   |

### Операции над наборами (`set`)
|[includes](https://en.cppreference.com/w/cpp/algorithm/includes "cpp/algorithm/includes")|returns true if one sequence is a subsequence of another  <br>(function template)|
|[set_difference](https://en.cppreference.com/w/cpp/algorithm/set_difference "cpp/algorithm/set difference")|computes the difference between two sets  <br>(function template)|
|[set_intersection](https://en.cppreference.com/w/cpp/algorithm/set_intersection "cpp/algorithm/set intersection")|computes the intersection of two sets  <br>(function template)|
|[set_symmetric_difference](https://en.cppreference.com/w/cpp/algorithm/set_symmetric_difference "cpp/algorithm/set symmetric difference")|computes the symmetric difference between two sets  <br>(function template)|
|[set_union](https://en.cppreference.com/w/cpp/algorithm/set_union "cpp/algorithm/set union")|computes the union of two sets  <br>(function template)|

### Операции над кучей (`heap`)
|##### Heap operations|   |
|[is_heap](https://en.cppreference.com/w/cpp/algorithm/is_heap "cpp/algorithm/is heap")<br><br>(C++11)|checks if the given range is a max heap  <br>(function template)|
|[is_heap_until](https://en.cppreference.com/w/cpp/algorithm/is_heap_until "cpp/algorithm/is heap until")<br><br>(C++11)|finds the largest subrange that is a max heap  <br>(function template)|
|[make_heap](https://en.cppreference.com/w/cpp/algorithm/make_heap "cpp/algorithm/make heap")|creates a max heap out of a range of elements  <br>(function template)|
|[push_heap](https://en.cppreference.com/w/cpp/algorithm/push_heap "cpp/algorithm/push heap")|adds an element to a max heap  <br>(function template)|
|[pop_heap](https://en.cppreference.com/w/cpp/algorithm/pop_heap "cpp/algorithm/pop heap")|removes the largest element from a max heap  <br>(function template)|
|[sort_heap](https://en.cppreference.com/w/cpp/algorithm/sort_heap "cpp/algorithm/sort heap")|turns a max heap into a range of elements sorted in ascending order  <br>(function template)|
|##### Minimum/maximum operations|   |

### Операции нахождения минимума/максимума
|[max](https://en.cppreference.com/w/cpp/algorithm/max "cpp/algorithm/max")|returns the greater of the given values  <br>(function template)|
|[max_element](https://en.cppreference.com/w/cpp/algorithm/max_element "cpp/algorithm/max element")|returns the largest element in a range  <br>(function template)|
|[min](https://en.cppreference.com/w/cpp/algorithm/min "cpp/algorithm/min")|returns the smaller of the given values  <br>(function template)|
|[min_element](https://en.cppreference.com/w/cpp/algorithm/min_element "cpp/algorithm/min element")|returns the smallest element in a range  <br>(function template)|
|[minmax](https://en.cppreference.com/w/cpp/algorithm/minmax "cpp/algorithm/minmax")<br><br>(C++11)|returns the smaller and larger of two elements  <br>(function template)|
|[minmax_element](https://en.cppreference.com/w/cpp/algorithm/minmax_element "cpp/algorithm/minmax element")<br><br>(C++11)|returns the smallest and the largest elements in a range  <br>(function template)|
|[clamp](https://en.cppreference.com/w/cpp/algorithm/clamp "cpp/algorithm/clamp")<br><br>(C++17)|clamps a value between a pair of boundary values  <br>(function template)|
|##### Comparison operations|   |

### Операции сравнения
|[equal](https://en.cppreference.com/w/cpp/algorithm/equal "cpp/algorithm/equal")|determines if two sets of elements are the same  <br>(function template)|
|[lexicographical_compare](https://en.cppreference.com/w/cpp/algorithm/lexicographical_compare "cpp/algorithm/lexicographical compare")|returns true if one range is lexicographically less than another  <br>(function template)|
|[lexicographical_compare_three_way](https://en.cppreference.com/w/cpp/algorithm/lexicographical_compare_three_way "cpp/algorithm/lexicographical compare three way")<br><br>(C++20)|compares two ranges using three-way comparison  <br>(function template)|

### Операции определения перестановки
|[is_permutation](https://en.cppreference.com/w/cpp/algorithm/is_permutation "cpp/algorithm/is permutation")<br><br>(C++11)|determines if a sequence is a permutation of another sequence  <br>(function template)|
|[next_permutation](https://en.cppreference.com/w/cpp/algorithm/next_permutation "cpp/algorithm/next permutation")|generates the next greater lexicographic permutation of a range of elements  <br>(function template)|
|[prev_permutation](https://en.cppreference.com/w/cpp/algorithm/prev_permutation "cpp/algorithm/prev permutation")|generates the next smaller lexicographic permutation of a range of elements  <br>(function template)|
