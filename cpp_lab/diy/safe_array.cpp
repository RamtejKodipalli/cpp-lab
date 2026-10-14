#include <iostream>
#include <stdexcept>

class SafeArray {
private:
    int* data;
    size_t size;

public:
    // Constructor
    SafeArray(size_t capacity) : size(capacity) {
        data = new int[size](); // Initializes elements to 0
    }

    // Destructor to clean up dynamic memory safely
    ~SafeArray() {
        delete[] data;
    }

    // Rule of Three: Prevent unsafe shallow copying
    SafeArray(const SafeArray&) = delete;
    SafeArray& operator=(const SafeArray&) = delete;

    // Overload operator[] for non-const objects
    int& operator[](size_t index) {
        if (index >= size) {
            throw std::out_of_range("Index " + std::to_string(index) + 
                                    " is out of bounds! Array size is " + std::to_string(size));
        }
        return data[index];
    }

    // Overload operator[] for const objects
    const int& operator[](size_t index) const {
        if (index >= size) {
            throw std::out_of_range("Index " + std::to_string(index) + 
                                    " is out of bounds! Array size is " + std::to_string(size));
        }
        return data[index];
    }

    size_t getSize() const { return size; }
};

int main() {
    SafeArray arr(5);

    // Populate data safely
    for (size_t i = 0; i < arr.getSize(); ++i) {
        arr[i] = (i + 1) * 10;
    }

    std::cout << "Array elements successfully read:" << std::endl;
    for (size_t i = 0; i < arr.getSize(); ++i) {
        std::cout << "arr[" << i << "] = " << arr[i] << std::endl;
    }

    // Intentionally trigger an out of range crash check
    std::cout << "\nAttempting to access out-of-bounds index (index 10)..." << std::endl;
    try {
        arr[10] = 999; 
    } 
    catch (const std::out_of_range& e) {
        std::cout << "Caught Exception Successfully: " << e.what() << std::endl;
    }

    return 0;
}