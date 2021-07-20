#include <iostream>

void print_digit_name(int x) {
    switch (x) {
        // switch case statements, only evaluate once
        // better than if-else chains
        case 1:
            std::cout << "one";
            break;

        // case executed depending on the result of switch evaluation
        case 2:
            std::cout << "two";
            break;
            // break statment exits current block
            // without this next case(s) are also executed

        case 3:
            std::cout << "three";
            break;
            // if fallthrough is desired instead of break / return
            // best to put "[[fallthrough]]" attribute on a null statement ";"

        // default statement only executed if 
        // expression doesnt evaluate to a case
        // can only be one per switch, and is optional
        default:
            std::cout << "unknown";
            break;
        
        // no limit on number of case labels,
        // however all labels must be unique
    }

    std::cout << " Ah-Ah-Ah!\n";
}

// can have sequential case labels used instead of multiple ||
// as they are labels not statements, not cosidered fallthrough
bool is_vowel(char c) {
    switch (c) {
        case 'a': // if c is 'a'
        case 'e': // or 'e'
        case 'i': // or 'i'
        case 'o': // or 'i'
        case 'u': // or 'u'
        case 'A': // or 'A'
        case 'E': // or 'E'
        case 'I': // or 'I'
        case 'O': // or 'O'
        case 'U': // or 'U'
            return true;
        
        default:
            return false;
    }
}

// you can declare, but not initialise within the switch block
// can initialise only within another block under the case label

// takes in two integers and an arithmetic operator 
// then returns the calulated result
int calculate(int x, char op, int y) {
    int z;

    switch (op) {
        case '+':
            z = x + y;
            break;
        
        case '-':
            z = x - y;
            break;
        
        case '*':
            z = x * y;
            break;
        
        case '/':
            z = x / y;
            break;
        
        case '%':
            z = x % y;
            break;
        
        default:
            std::cout << "Unhandled case\n";
            break;
    }

    return z;
}

int main() {
    print_digit_name(2);

    std::cout << is_vowel('a') << '\n';

    std::cout << calculate(4, '*', 3) << '\n';

    return 0;
}
