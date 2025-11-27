#include <string>
#include <vector>
#include <print>
#include <optional>
#include <unordered_set>
#include <algorithm>
#include <ranges>

/**
Given a string s, return the longest palindromic substring in s.

Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.

Example 2:

Input: s = "cbbd"
Output: "bb"

Constraints:
    1 <= s.length <= 1000
    s consist of only digits and English letters.
 */

[[nodiscard]] bool is_palindrome(std::string_view const str)
{
  if(str.empty())
    return false;
  if(str.size() == 1)
    return true;
  auto const len = str.size();
  for(auto i = 0; i < len / 2; ++i)
    if(str[i] != str[len - i - 1])
      return false;
  return true;
}

[[nodiscard]] std::unordered_set<std::string_view> substrings(
  std::string_view const str,
  std::size_t const max_length
)
{
  auto const len = str.size();
  auto res = std::unordered_set<std::string_view>();
  res.reserve(std::min(len * max_length, len * (len + 1) / 2));

  for(auto i = 0; i < len; ++i) {
    auto const actual_max = std::min(max_length, len - i);
    for(auto j = actual_max; j > 0; --j)
      res.insert(str.substr(i, j));
  }
  return res;
}

[[nodiscard]] std::string_view lcs(std::string_view const lhs, std::string_view const rhs)
{
  auto const max_length = std::min(lhs.size(), rhs.size());
  if(max_length <= 1)
    return lhs;
  auto const a = substrings(lhs, max_length);
  auto const b = substrings(rhs, max_length);

  // C++23:
  //   auto view = a | std::views::filter([&b](std::string_view const e) { return b.contains(e); });
  //   auto intersection = std::vector<std::string_view>(view.begin(), view.end());
  auto intersection = std::vector<std::string_view>();
  intersection.reserve(a.size());
  for(auto const& s : a)
    if(b.count(s))
      intersection.emplace_back(s);

  if(intersection.empty())
    return lhs.substr(0, 1);
  auto res = std::string_view();
  while(not is_palindrome(res)) {
    if(not res.empty())
      intersection.erase(intersection.begin(), intersection.begin() + 1);
    std::ranges::
      nth_element(intersection, intersection.begin(), [](auto const& s1, auto const& s2) {
        return s1.size() > s2.size();
      });
    res = *intersection.begin();
  }
  return res;
}

class Solution
{
 public:
  std::string longestPalindrome(std::string s)
  {
    auto reversed = s;
    std::ranges::reverse(reversed);
    return std::string(lcs(s, reversed));
  }
};

int main()
{
  std::println(
    "{}",
    Solution().longestPalindrome(
      "nmngaowrbsssvihklwmuqshcddwlxrywrlwtennwfvrevgvhsvgeccfulmuvrcksdmgeqrblnlwoepefhcwhmgyvgcoy"
      "yygrmttyfycxwbqktpurlcfhzlakhmrddsydgygganpmaglaxyhfwjusukzcnakznygqplngnkhcowavxoiwrfycxwdk"
      "xqfcjqwyqutcpyedbnuogedwobsktgioqdczxhikjrbkmqspnxcpngfdwdaboscqbkwforihzqdcppxjksiujfvlpdjr"
      "yewaxgmdgigvxdlstxwngtbdrrkfudjinzyxbdmkautclvvyguekuzwwetmsxittgtxbnvvrgasvnlogdiepltweaehu"
      "bwelznidltzlbzdsrxmhjpkmylnwkdsxnpkplkdzywioluaqguowtbaoqzqgjfewphqcvlnwlojbxgomvxxkhwwykawe"
      "gxubjiobizicuxzeafgautefsurgjlbhcfevqzsbhwxycrcaibdsgluczcuewzqupakbzmcvzsfodbmgtugnihyhqkvy"
      "eboqhqldifbxuaxqzxtyejoswikbzpsvzkxcndgeyvfnyrfbkhlalzpqjueibnodamgpnxlkvwvliouvejcpnakllfxe"
      "pldfmdzszagkyhdgqqbkb"
    )
  );
  return 0;
}
