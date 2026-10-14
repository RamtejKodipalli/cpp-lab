#include <iostream>
#include <numeric> // For std::gcd
#include <stdexcept>

class Fraction {
private:
    int num;
    int den;

    // Helper function to simplify fraction using GCD
    void simplify() {
        if (den == 0) {
            throw std::invalid_argument("Denominator cannot be zero.");
        }
        
        int common = std::gcd(num, den);
        num /= common;
        den /= common;

        // Keep the negative sign in the numerator
        if (den < 0) {
            num = -num;
            den = -den;
        }
    }

public:
    // Constructor with auto-simplification
    Fraction(int n = 0, int d = 1) : num(n), den(d) {
        simplify();
    }

    // Overload Stream Insertion Operator (Output)
    friend std::ostream& operator<<(std::ostream& os, const Fraction& f) {
        if (f.den == 1) {
            os << f.num;
        } else {
            os << f.num << "/" << f.den;
        }
        return os;
    }

    // Overload Stream Extraction Operator (Input format: num/den or just num)
    friend std::istream& operator>>(std::istream& is, Fraction& f) {
        int n, d = 1;
        is >> n;
        
        // Check if a slash follows for the denominator
        if (is.peek() == '/') {
            is.ignore(); // Discard the '/' character
            is >> d;
        }
        
        f.num = n;
        f.den = d;
        f.simplify();
        return is;
    }
};

int main() {
    try {
        std::cout << "Creating an unsimplified fraction (12/30)..." << std::endl;
        Fraction f1(12, 30);
        std::cout << "Auto-simplified result: " << f1 << "\n\n";

        Fraction f2;
        std::cout << "Enter a fraction (format: numerator/denominator): ";
        if (std::cin >> f2) {
            std::cout << "Simplified fraction: " << f2 << std::endl;
        }
    } 
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}