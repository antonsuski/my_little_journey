#include <cassert>
#include <cstdint>
#include <iostream>
#include <limits>
#include <vector>

static bool clear_failed_extraction()
{
    if (!std::cin)
    {
        if (std::cin.eof())
        {
            exit(0);
        }

        std::cin.clear();
        // remove another characters from the stream
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return true;
    }
    return false;
}

int linear_search(const std::vector<int>& v, int variable)
{
    std::size_t lenth = v.size();
    for (size_t i{ 0 }; i < lenth; i++)
    {
        if (v[i] == variable)
            return i;
    }
    return -1;
}

template <typename T>
constexpr void printElement(const std::vector<T>& v, int index)
{
    if ((static_cast<int>(v.size()) <= index) || index < 0)
    {
        std::cout << "Invalid index" << std::endl;
    }
    else
    {
        std::cout << "vector[" << index
                  << "]:" << v[static_cast<std::size_t>(index)] << std::endl;
    }
}

template <typename T>
constexpr void printArray(const std::vector<T>& v)
{
    int lenth = v.size();
    for (size_t i{ 0 }; i < lenth; i++)
    {
        std::cout << "vector[" << i << "]:" << v[static_cast<std::size_t>(i)]
                  << std::endl;
    }
}

int input_user_number(int min = std::numeric_limits<int>::min(),
                      int max = std::numeric_limits<int>::max())
{
    int res{ -1 };
    while (true)
    {
        std::cin >> res;
        if (clear_failed_extraction() && min <= res && res <= max)
        {
            std::cerr << "Invalid input!" << std::endl;
            continue;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << std::endl;
        return res;
    }
}

int main(int argv, char** argc)
{
    // 02 different approaches of initialization
    std::cout << "__#02__" << std::endl;
    // CTAD - class template argument dudction
    std::vector              v_fibonnachi{ 0, 1, 1, 2, 3, 5 };
    static const std::vector arr{ 3, 5, 1, 4, 2, 9, 7, 6, 8 };
    int a = argv;
    std::vector      v1{ 5 }; // will make vector with elelement 5
    std::vector<int> v2(
        5); // will make vector with 5 elements wich are initialized with 0

    std::vector<double> temperature(365);

    // 03
    std::cout << "__#03__" << std::endl;
    std::vector<char> hello{ 'h', 'e', 'l', 'l', 'o' };
    // Method size() returns count of vectors' elements. The type of retured
    // value is size_type. In general size_type is a unsigned type
    // (std::size_t).
    std::cout << "###vec###\nname: hello; size: " << hello.size() << "; "
              << "vec[1]: " << hello.at(1) << ";\n#########" << std::endl;

    // 04
    std::cout << "__#04__" << std::endl;
    printElement(v_fibonnachi, 2);
    printElement(v_fibonnachi, 6);
    printElement(v_fibonnachi, -1);

    // 06
    std::cout << "__#06__" << std::endl;
    printArray(v_fibonnachi);

    std::cout << "Enter a number between 1 and 9 >";
    int res = input_user_number(1, 9);
    printArray(arr);
    int index = linear_search(arr, res);
    if (index > -1)
        std::cout << "The number " << res << " has index " << index
                  << std::endl;
    else
        std::cout << "The number " << res << " was not found" << std::endl;
    return 0;
}
