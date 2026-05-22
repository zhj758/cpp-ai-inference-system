#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

int main() {
    // 1. vector
    std::vector<int> nums;
    nums.push_back(10);
    nums.push_back(20);
    nums.push_back(30);
    nums.resize(5);
    std::cout << "vector: ";
    for (auto it = nums.begin(); it != nums.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // 2. unordered_map
    std::unordered_map<std::string, int> fruit_count;
    fruit_count["apple"] = 5;
    fruit_count["banana"] = 3;
    std::cout << "banana count: " << fruit_count["banana"] << std::endl;

    // 3. string
    std::string text = "AI Inference Engine";
    std::cout << "substr(3, 9): " << text.substr(3, 9) << std::endl;
    std::cout << "find('Engine'): " << text.find("Engine") << std::endl;
    text.append(" v1.0");
    std::cout << "After append: " << text << std::endl;

    return 0;
}
