#include <vector>
#include <cstdlib>
#include <ctime>
#include <cstdio>

std::vector<int> GenerateRandomIntVector();

template <typename T>
void InsertionSort(std::vector<T>& array);

int main(int argc, char* argv[]) {
    auto array = GenerateRandomIntVector();

    InsertionSort(array);

    for (const auto& elem : array) {
        printf("%d ", elem);
    }

    return 0;
}

std::vector<int> GenerateRandomIntVector() {
    std::vector<int> array;

    for (auto i = 0; i < 10000; ++i) {
        srand(time(0) + i);

        auto number = (rand() % 500 + 1) * (rand() % 3 - 1);

        array.emplace_back(number);
    }

    return array;
}

template <typename T>
void InsertionSort(std::vector<T>& array) {
    for (auto i = 1; i < array.size(); ++i) {
        for (auto j = i; j > 0 && array[j-1] > array[j]; --j) {
            std::swap(array[j-1], array[j]);
        }
    }
}