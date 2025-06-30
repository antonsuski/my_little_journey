#include <iostream>
#include <boost/cobalt.hpp>

boost::cobalt::generator<int> count_to_three() {
    co_yield 1; // Возвращаем 1 и ставим на паузу
    co_yield 2; // При следующем вызове продолжим отсюда
    co_yield 3;
}

int main()
{
	using std::cout;
	for (auto &i: count_to_three())
		cout << "Count: " << i << endl;
}

