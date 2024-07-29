#include <array>
#include <vector>
#include <iostream>
#include <functional>
#include <string_view>
// mdspan could be unsupported
// #include <mdspan>

struct point{
    std::string_view name{};
    double x{};
    double y{};
};

namespace color{
    enum type{
        red,
        green,
        blue,
        alpha,
        max_color_type
    };
    
    using namespace std::string_view_literals;
    constexpr std::array color_type_names{"red"sv, "green"sv, "blue"sv, "alpha"sv};
    static_assert(std::ssize(color_type_names) == max_color_type);

    constexpr std::array types{red, green, blue, alpha};
    static_assert(std::size(types) == max_color_type);

};

constexpr std::string_view get_color_name(const color::type t){
    return color::color_type_names[t];
}

std::ostream& operator<<(std::ostream& out, color::type color){
    return out << get_color_name(color);
}

static constexpr point car{ "car", 32.412, 99.124};
static constexpr point plane{ "plane", 93.234, 41.324};
static constexpr point ship{ "ship", 1.332, 77.123};

template<typename T, std::size_t N>
constexpr void pass_by_ref(std::array<T, N>& arr){
    std::cout << "passed_by_ref" << '\n';
}

template<typename T, std::size_t N>
constexpr void pass_by_value(std::array<T, N> arr){
    std::cout << "passed_by_value" << '\n';
}

template<typename T>
constexpr void print(const T& container){
    using std::cout;
    
    cout << "Container size:" << std::ssize(container) << "\nData:"; // std::ssize() - std20
    if(container.size() <= 0){
        cout << "N/A";
    }else{
        for(const auto&i : container){
            cout << '[' << i << ']';
        }
    }
    cout << "\n#######################################\n";
}

int main(int argc, char** argv){
    using std::cout;
    using std::endl;
    using std::array;
    using std::vector;

    cout << "Arrays lab:\n";

    // Array initialization are different with vector
    array<int, 5> a1{}; // includes 5 elements
    print(a1);
    array<int, 5> a_trash; // member default initialized
    print(a_trash);
    vector<int> v1{}; // includes 0 elements
    print(v1);

    // std20
    // Functino std::to_array() allows us ommit some part of template arguments
    // Ommiting template argumetns in ordinal way are not allowed
    constexpr auto a2{std::to_array({1,2,3,4,5})}; // all template argumets were ommited
    constexpr auto a3{std::to_array<double>({1.f,2.f,3.f,4.f,5.f})}; // size_t argument was
    constexpr auto a4{std::to_array<int,5>({1,2,3,4,5})}; // all present

    constexpr std::size_t len{5};
    array<int, len> pow {2,4,8,16,32}; // lenth must be constexpr
    array fibonachi { 0, 1, 1, 2, 3, 5}; //CTAD classs template argument deduction
    print(fibonachi);
    array aggrigat_init {'h','e','l','l','o'};

    // As usual operater[] don't make bound checking
    cout << "Access methods:\n\toperator[]:" << aggrigat_init[1] << "\n\tat():" << aggrigat_init.at(2) << "\n\t";
    // std::get makes bound check only at compile-time so the argument have to be constexpr for bound checking
    cout << "std::get():" << std::get<4>(aggrigat_init) << "\n";

    // Passing through functin.
    pass_by_ref(aggrigat_init);    
    pass_by_value(aggrigat_init);

    // Stroing refernce to somewere
    cout << "\nstd::reference_wrapper:\n";
    int a{55};
    int b(7);
    constexpr int c{3};
    constexpr int d{};

    array<std::reference_wrapper<int>, 2> int_ref_pair{a, b};
    // The array stores refernces to objects so it retunrs std::reference_wrapper object
    // If you will try to modify with operator[] you will rewrite reference. It is UB
    cout << "\toperator[], index 0:"<< int_ref_pair[0];
    // To modify value of reference call .get() method
    cout << "\n\toperator[].get(), index 0:" << int_ref_pair[0].get();
    cout << "\nmodifying:";
    // std::ref() returns std::reference_wrapper, std::cref() returns const std::reference_wrapper
    cout << "\n\twith get():" << (int_ref_pair[0].get() = std::ref(b)) << " value:" << a;

    // Find out how it's works
    // array<std::reference_wrapper<point>,2> current_coordinate_pair{plane, car};

    cout << "\nUsing with enums\n";
    // You can also use enums with array
    cout << color::red << '\n';

    cout << "Enums:\n";
    // You can't iterate array with rangebase for loop. You have to make some work around to do it possible
    for(auto& i: color::types){
        cout << "\t" << i << "\n";
    }
    return 0;
}
