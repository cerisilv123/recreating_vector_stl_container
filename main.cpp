// Recreating Vector Class Template

#include <iostream>
#include <string>

template <typename T>
class Vector {
private:
    unsigned int vec_size {};
    unsigned int vec_capacity {};
    T *values;
    
public:
    // Constructors / Assignment
    Vector();
    Vector(int size);
    Vector(int size, const T &vals);
    Vector(const Vector<T> &rhs);
    ~Vector();
    Vector<T> &operator=(const Vector<T> &rhs);
    
    // Methods
    void display(); // implemented this method to help with creating class
    T &at(T pos);
    T &operator[] (T pos);
    T &front();
    T &back();
    void reserve(unsigned int capacity);
    void push_back(T val);
    bool empty() const;
    int size() const;
    int capacity() const;
    void shrink_to_fit();
    void clear() noexcept;
    
    // Iterators
    T* begin(); // begin Iterator
    T* end(); // end Iterator
};

// No-args Constructor
template <typename T>
Vector<T>::Vector() {
    vec_size = 0;
    vec_capacity = 0;
    values = new T [0];
}

// Constructor - only size
template<typename T>
Vector<T>::Vector(int size) {
    vec_size = size;
    vec_capacity = size;
    values = new T [size];
}

// Constructor - size and values
template<typename T>
Vector<T>::Vector(int size, const T &vals) {
    vec_size = size;
    vec_capacity = size;
    values = new T [size];
    for (size_t i = 0; i < size; i++) {
        values[i] = vals;
    }
}

// Copy constructor
template<typename T>
Vector<T>::Vector(const Vector<T> &rhs) {
    vec_size = rhs.vec_size;
    vec_capacity = rhs.vec_capacity;
    values = new T [rhs.vec_size];
    for (size_t i = 0; i < rhs.vec_size; i++) {
        values[i] = rhs.values[i];
    }
}

// Destructor
template<typename T>
Vector<T>::~Vector() {
    delete[]values;
}

// Assignment
template <typename T>
Vector<T> &Vector<T>::operator=(const Vector<T> &rhs) {
    delete [] values;
    vec_size = rhs.vec_size;
    vec_capacity = rhs.vec_capacity;
    values = new T [rhs.vec_size];
    for (size_t i = 0; i < rhs.vec_size; i++) {
        values[i] = rhs.values[i];
    }
    return *this;
    
}

// at operator
template <typename T>
T &Vector<T>::at(T pos) {
    return values[pos];
}

// Overloaded subscript operator
template <typename T>
T &Vector<T>::operator[](T pos) {
    return values[pos];
}

// Front Method
template<typename T>
T &Vector<T>::front() {
    return values[0];
}

// Back Method
template<typename T>
T &Vector<T>::back() {
    return values[vec_size-1];
}

// Display Method
template<typename T>
void Vector<T>::display() {
    for (size_t i = 0; i < vec_size; i++) {
        std::cout << values[i] << " ";
    }
}

// Reserve Method
template<typename T>
void Vector<T>::reserve(unsigned int capacity) {
    if (values == 0) {
        vec_size = 0;
        vec_capacity = 0;
    }
    T *new_values = new T[capacity];
    unsigned int loop_size {};
    if (capacity < vec_size) {
        loop_size = capacity;
    }
    else {
        loop_size = vec_size;
    }
    for (size_t i = 0; i < loop_size; i++) {
        new_values[i] = values[i];
    }
    vec_capacity = capacity;
    delete [] values;
    values = new_values;
}

// Push_back method
template <typename T>
void Vector<T>::push_back(T val) {
    reserve(vec_capacity +5);
    values [vec_size] = val;
    vec_size += 1;
}

// Empty method
template <typename T>
bool Vector<T>::empty() const {
    if (vec_size == 0)
        return true;
    else
        return false;
}

// Size method
template <typename T>
int Vector<T>::size() const {
    return vec_size;
}

// Capacity method
template <typename T>
int Vector<T>::capacity() const {
    return vec_capacity;
}

// shring_to_fit method
template <typename T>
void Vector<T>::shrink_to_fit() {
    T *new_values = new T[vec_size];
    for (size_t i = 0; i < vec_size; i++) {
        new_values[i] = values[i];
    }
    vec_capacity = vec_size;
    delete [] values;
    values = new_values;
}

// Clear method
template<typename T>
void Vector<T>::clear() noexcept {
    vec_size = 0;
    delete [] values;
    values = new T[0];
}

// Begin iterator
template<typename T>
T* Vector<T>::begin() {
    return values; // Returning the first memory address in values as the first iterator
}

// End iterator
template<typename T>
T* Vector<T>::end() {
    return values + vec_size;
}

int main() {
   
    Vector<int> Ceri;
    Vector<int> Tom (5, 10);
    Vector<std::string> Dave (50, "Hello World");
    Vector<std::string> Jon;
    Ceri = Tom;
//    Dave.push_back("Hello Program");
    Ceri.push_back(15);
//    Dave.display();
    Ceri.display();
    auto it = Ceri.begin();
    std::cout << *it << std::endl;
    Ceri.display();
    
    std::cout << Ceri.empty() << std::endl;
    std::cout << Jon.empty() << std::endl;
    std::cout << Ceri.size() << std::endl;
    std::cout << Jon.size() << std::endl;
    std::cout << Ceri.capacity() << std::endl;
    std::cout << Jon.capacity() << std::endl;
    Ceri.shrink_to_fit();
    Ceri.display();
    Ceri.clear();
    Jon.display();
    std::cout << std::endl;
    Ceri.display();
//    std::cout << Ceri.at(3) << std::endl;
//    std::cout << Ceri [2] << std::endl;
//    std::cout << Ceri.front() << std::endl;
//    std::cout << Ceri.back() << std::endl;
    std::cout << std::endl;
    return 0;
}
