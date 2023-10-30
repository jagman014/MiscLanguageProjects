#include "Array.h"

// .inl file used for template classes to keep header files for classes clean
// setup similar to .h and .cpp, but need .inl for templates as .cpp won't work

// member functions defined outside of class need own template declaration
template <typename T>
int Array<T>::get_length() const { // note using Array<T> not Array
    return m_length;
}
