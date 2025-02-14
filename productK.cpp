#include <iostream>
#include <vector>

class ProductOfNumbers {
private:
    std::vector<int> prefixProducts;

public:
    ProductOfNumbers() {
        prefixProducts = {1}; // Initialize with 1 for easy multiplication
    }

    void add(int num) {
        if (num == 0) {
            prefixProducts = {1}; // Reset since zero invalidates previous products
        } else {
            prefixProducts.push_back(prefixProducts.back() * num);
        }
    }

    int getProduct(int k) {
        int n = prefixProducts.size();
        if (k >= n) return 0; // If k reaches a reset point, product must be 0
        return prefixProducts.back() / prefixProducts[n - k - 1];
    }
};

int main() {
    ProductOfNumbers productOfNumbers;
    productOfNumbers.add(3);
    productOfNumbers.add(0);
    productOfNumbers.add(2);
    productOfNumbers.add(5);
    productOfNumbers.add(4);
    std::cout << productOfNumbers.getProduct(2) << std::endl; // Output: 20
    std::cout << productOfNumbers.getProduct(3) << std::endl; // Output: 40
    std::cout << productOfNumbers.getProduct(4) << std::endl; // Output: 0
    productOfNumbers.add(8);
    std::cout << productOfNumbers.getProduct(2) << std::endl; // Output: 32
    return 0;
}
