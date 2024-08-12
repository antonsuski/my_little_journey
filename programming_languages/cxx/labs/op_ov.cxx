#include <iostream>
#include <vector>

namespace
{
    inline namespace v1
    {
        template<typename T>
        class vec{
        public:
            private:
            std::vector<T> data{};
        public:
            vec(std::vector<T> input):data{input}{}

            vec<T> operator*(const int& c){
                vec<T> res {this->data};
                for (auto &&i : res.data)
                {
                    i *= c;
                }
                return res;
            }

            friend std::ostream& operator<<(std::ostream& out, const vec<T>& vec){
                for (const auto &i : vec.data)
                {
                    out << i << ',';
                }
                return out;
            }
        };
    } // inline namespace v1
} // namespace

int main(int argc, char const *argv[])
{
    using std::cout;
    cout << "__operator overload__\n" ;

    vec<int> test{{1,2,3,4}};
    cout << (test * 5) << test;
    return 0;
}
