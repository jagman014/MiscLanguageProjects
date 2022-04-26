#include <cstring> // for std::strlen()
#include <iostream>
#include <iterator> // for std::size()
#include <string> // for std::sting
#include <string_view> // for std::string_view

// create a view to the string, without copying the original binary
// much faster than std::string, with the same string functions available

// lifetime of view is independent of string it views
// however, if the string it is viewing goes out of scope
// it cannot be viewing anything -> undefined behaviour
std::string_view ask_for_name() {
    std::cout << "What is your name: ";

    // need std::string as std::cin needs to modify it
    std::string str {};
    std::cin >> str;

    // no need to do this, only for demo sake
    std::string_view view {str};

    std::cout << "Hello " << view << '\n';

    return view;
}

void print(std::string s) {
    std::cout << s << '\n';
}

int main() {
    // all observe the same "hello" string
    std::string_view text {"hello"};
    std::string_view str {text};
    std::string_view more {str};

    std::cout << text << ' ' << str << ' ' << more << "\n\n";

    std::string_view stri {"Trains are fast!"};

    std::cout << stri.length() << '\n';
    std::cout << stri.substr(0, stri.find(' ')) << '\n';
    std::cout << (stri == "Trains are fast!") << '\n';

    // since C++20
    std::cout << stri.starts_with("Boats") << '\n';
    std::cout << stri.ends_with("fast!") << '\n';

    std::cout << stri << "\n\n";

    // changing the original string will change the string_view,
    // best to use std::string_view for read-only strings, 
    // especially over C-style strings
    char arr[] {"Gold"};
    std::string_view strin {arr};

    std::cout << strin << '\n';

    arr[3] = 'f';

    std::cout << strin << "\n\n";

    // can change how much of the string is in view, cannot be undone though
    std::string_view string {"Peach"};

    std::cout << string << '\n';

    // ignore start chars
    string.remove_prefix(1);

    std::cout << string << '\n';

    // ignore end chars
    string.remove_suffix(2);

    std::cout << string << "\n\n";

    // work with non-null terminated strings
    char vowels[] {'a', 'e', 'i', 'o', 'u'}; // not null terminated

    // need to pass lenght manually
    std::string_view string_1 {vowels, std::size(vowels)};

    // safe to print now
    std::cout << string_1 << "\n\n";

    // value of view tied to lifetime of viewed object
    std::string_view view {ask_for_name()};

    // object of view has already died
    std::cout << "Your name is: " << view << "\n\n";

    // std::string_view will not be implicitly converted to std::string
    std::string_view sv {"balloon"};

    sv.remove_suffix(3);

    // need to explicitly convert to std::string
    std::string string_2 {sv};

    print(string_2);
    print(static_cast<std::string>(sv));

    // can be converted to a C-style string at the expense of creating a string
    const char* sz_null_terminated {string_2.c_str()};

    std::cout << string_2 << " has " 
                << std::strlen(sz_null_terminated) 
                << " letters (using std::string -> C-style)\n\n";

    // can use std::string_view::data() to get a C-style string
    // but only if the view hasn't been modified beforehand

    std::string_view sv_1 {"balloon"};

    std::cout << sv_1 << " has " 
                << std::strlen(sv_1.data()) << " letters (using .data())\n";

    return 0;
}
