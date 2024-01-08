#include "DataArray.h"
#include <cstddef>

using std::byte;

DataArray::DataArray(size_t size) :
	m_data(nullptr),
	m_size(size)
{
	m_data = new byte[size];
}

DataArray::DataArray(DataArray&& other) noexcept :
	m_data(other.m_data),
	m_size(other.m_size)
{
	other.m_data = nullptr;
	other.m_size = 0;
}

DataArray::~DataArray()
{
}

DataArray& DataArray::operator=(DataArray&& other) noexcept
{
	if (this != &other)
	{
		delete[] m_data;
		m_data = other.m_data;
		m_size = other.m_size;
		other.m_data = nullptr;
		other.m_size = 0;
	}
	return *this;
}

const void* DataArray::GetData() const
{
	return m_data;
}

bool DataArray::IsValid() const
{
	return m_data != nullptr;
}
