#include <cstdint>
#include <cmath>
#include <string>
#include <stack>

using namespace std;
using i8 = int8_t;
using i16 = int16_t;
using i32 = int32_t;
using i64 = int64_t;
using u8 = uint8_t;
using u16 = uint16_t;
using u32 = uint32_t;
using u64 = uint64_t;
using usize = size_t;
using isize = int;
using uptr = uintptr_t;
using iptr = ptrdiff_t;
using f32 = float;
using f64 = double;

struct ListNode
{
  int val;
  ListNode* next;

  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

auto mergeTwoLists(ListNode* list1, ListNode* list2) -> ListNode*
{
  auto* ret = new ListNode;
  auto ret_ptr = ret;
  while(true)
  {
    if(not list1)
    {
      ret_ptr->next = list2;
      break;
    }

    if(not list2)
    {
      ret_ptr->next = list1;
      break;
    }

    if(list1->val > list2->val)
    {
      ret_ptr->next = list2;
      list2 = list2->next;
      ret_ptr = ret_ptr->next;
    }
    else
    {
      ret_ptr->next = list1;
      list1 = list1->next;
      ret_ptr = ret_ptr->next;
    }
  }
  return ret->next;
}