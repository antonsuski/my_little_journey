#include<iostream>
#include<string_view>

namespace shadow{
    [[maybe_unused]]int obscure {77};
};

// the inline namespace can be only one inthe global static 
// uname namespace behaives like static varaiables and functions with internal linkage
namespace{
    [[maybe_unused]]int unnamed {96};
};

// inline namespace behaives like unnamed but with no affect to likage
// inline namespace v1{
//     void print(std::string_view sv){
//         std::cout << "v1:" << sv << '\n';
//     }
// }

namespace v2{
    void print(std::string_view sv){
        std::cout << "v2:" << sv << '\n';
    }
}

// you can mix inline and unnamed namespaces
// inline namespace{
//     void print() // it has internal likage
//     {
//         std::cout << "inline unnamed namespace with internal likage\n";
//     }
// }

namespace v1{
    void print(std::string_view sv){
        std::cout << "v1:" << sv << '\n';
    }
}

inline namespace v4{
    namespace {
        void print(std::string_view sv){
            std::cout << "v4:" << sv << '\n';
        }
    }
}

int main(){
    using std::cout;
    [[maybe_unused]]int obscure {22};

    std::cout << "obscure:" << obscure << '\n';
    v1::print("lol");
    v2::print("ne lol");
    print("kekw");
    return 0;
}
