add_rules("mode.debug")

set_config("mode", "debug")
set_languages("c++latest")

target("5. Longest Palindromic Substring")
set_kind("binary")
add_files("*.cc")