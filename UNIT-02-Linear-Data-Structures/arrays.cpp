#include <iostream>
#include <algorithm>
#include <string>
#include <stdexcept>

using namespace std;

class Array
{
    int *array;
    int size;

public:
    Array(int size)
    {
        this->size = size;
        if (size <= 0)
            throw runtime_error("Can't create an empty array");
        array = new int[size]{0};
    }
    //! 2 For deap copies instead of shallow one and to avoid double free problem
    Array(const Array &other) : size(other.size)
    {
        array = new int[size];
        copy(other.begin(), other.end(), array);
    }
    Array &operator=(const Array &other)
    {
        if (this == &other)
            return *this;

        delete[] array;
        size = other.size;
        array = new int[size];
        copy(other.begin(), other.end(), array);
        return *this;
    }
    //!----------------------------------------------------!2
    ~Array()
    {
        delete[] array;
    }
    void inBound(int index) const
    {
        if (index < 0 || index > size - 1)
            throw runtime_error("Index out of bound");
    }
    int &get(int index)
    {
        inBound(index);
        return array[index];
    }
    void replace(int element, int index)
    {
        get(index) = element;
    }
    void insert(int element, int index)
    {
        inBound(index);
        for (int i = size - 1; i > index; i--)
        {
            array[i] = array[i - 1];
        }
        array[index] = element;
    }

    // Other approach
    // void insert(int element, int index)
    // {
    //     for (int i = size; i < size; i++)
    //     {
    //         swap(array[index], array[i]);
    //     }
    //     array[index] = element;
    // }

    void remove(int index)
    {
        inBound(index);
        int i = index;
        for (; i < size - 1; i++)
        {
            array[i] = array[i + 1];
        }
        array[i] = 0;
    }
    int search(int element) const
    {
        for (int i = 0; i < size; i++)
        {
            if (array[i] == element)
                return i;
        }
        return -1;
    }
    void removeElement(int element)
    {
        for (int i = 0; i < size;)
        {
            if (array[i] == element)
                remove(i);
            else
                i++;
        }
    }
    void removeElementRecursive(int element)
    {
        int index = search(element);
        if (index != -1)
        {
            remove(index);
            removeElementRecursive(element);
        }
    }

    //! Quality of life :
    // for ranged for loop
    int *begin() { return array; };
    int *end() { return array + size; };

    // for copy contructor and = overload
    const int *begin() const { return array; }
    const int *end() const { return array + size; }
    bool equal(const Array &other) const
    {
        if (size != other.size)
            return false;
        for (int i = 0; i < size; i++)
        {
            if (array[i] != other.array[i])
            {
                return false;
            }
        }
        return true;
    }
    string toString() const
    {
        string s = "[ ";
        for (int i = 0; i < size; i++)
        {
            s += (to_string(array[i]) + ", ");
        }
        s += "\b\b ]";
        return s;
    }
    int &operator[](int index)
    {
        return get(index);
    }
    bool operator==(const Array &other) const
    {
        return equal(other);
    }
};
ostream &operator<<(ostream &out, const Array &arr)
{
    return out << arr.toString();
}

// Test are AI generated to save time
int main()
{
    cout << "=== Array Sanity Test ===\n\n";
    // 1. Construction
    Array a(6);
    cout << "Initial array: " << a << '\n';

    // 2. Range-based fill (non-const begin/end)
    int value = 1;
    for (int &x : a)
    {
        x = value++;
    }
    cout << "After range fill: " << a << '\n';

    // 3. Insert (static capacity, right shift)
    a.insert(99, 2);
    cout << "After insert(99, 2): " << a << '\n';
    // Expected: [ 1, 2, 99, 3, 4, 5 ]

    // 4. Remove by index
    a.remove(3);
    cout << "After remove(3): " << a << '\n';
    // Expected: [ 1, 2, 99, 4, 5, 0 ]

    // 5. Search
    cout << "Index of 99: " << a.search(99) << '\n';
    cout << "Index of 100 (not found): " << a.search(100) << '\n';

    // 6. Remove by value (duplicates)
    a.insert(2, 1); // duplicate 2
    a.insert(2, 2); // another duplicate
    cout << "With duplicates: " << a << '\n';

    a.removeElement(2);
    cout << "After removeElement(2): " << a << '\n';

    // 7. Copy constructor (deep copy)
    Array b = a;
    cout << "Copied array b: " << b << '\n';

    // Modify original, ensure copy is independent
    a[0] = 777;
    cout << "After modifying a[0]:\n";
    cout << "a: " << a << '\n';
    cout << "b (should be unchanged): " << b << '\n';

    // 8. Copy assignment
    Array c(6);
    c = a;
    cout << "Assigned array c: " << c << '\n';

    // 9. Equality operator
    cout << "a == b ? " << (a == b ? "true" : "false") << '\n';
    cout << "a == c ? " << (a == c ? "true" : "false") << '\n';

    // 10. Const correctness check
    const Array d = c;
    cout << "Const array d: " << d << '\n';

    cout << "\n=== All tests completed ===\n";
    return 0;
}
