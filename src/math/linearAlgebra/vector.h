#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

#include "boost/numeric/ublas/vector.hpp"

#include "math.h"

template <typename dataType>
class Vector
{

public:

	struct shape_t
	{
		size_t	x = 1;
		size_t	y = 1;
		size_t	z = 1;
		size_t	p = 0;

		shape_t(size_t x = 1, size_t y = 1, size_t z = 1) : x(x), y(y), z(z) {}

		void pad(unsigned int factor = 32)	{p = factor - size() % factor;}

		size_t size()	{return x*y*z;}
		size_t span()	{return x*y*z + p;}
	};


public:

	Vector() {}

	void resize(const shape_t& shape);

	size_t	size()	{return m_shape.size();}
	size_t	span()	{return m_shape.span();}

protected:

	shape_t		m_shape;
	dataType*	m_buffer;

};

#endif