#include "vector.h"



template <typename dataType>
void Vector<dataType>::resize(const shape_t& shape)
{
	m_shape = shape;
	m_shape.pad();
	cudaMalloc((void**)&m_buffer, m_shape.span() * sizeof(dataType));

}













template class Vector<double>;