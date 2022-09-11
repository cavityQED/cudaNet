#include "math/linearAlgebra/vector.h"

int main(int argc, char const *argv[])
{
	Vector<double> vec;

	Vector<double>::shape_t shape(28, 28);

	vec.resize(shape);

	std::cout << "Vector Size:\t" << vec.size() << '\n';
	std::cout << "Vector Span:\t" << vec.span() << '\n';

	return 0;
}