#include <iostream>

#include <xtensor/xarray.hpp>
#include <xtensor/xio.hpp>

using matrix_type_double = xt::xarray<double>;

int main() {
	const auto allDiscreteMatrix = matrix_type_double{
		{1.0, 2.0, 1.0, 1.0},
		{6.0, 5.0, 6.0, 5.0},
		{1.0, 5.0, 6.0, 2.0}
	};

	const auto avg = xt::mean(allDiscreteMatrix, { 0 });
	std::cout << "average : " << avg << std::endl;

	return 0;
}