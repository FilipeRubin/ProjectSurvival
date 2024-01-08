#include "DataArray.h"
#include <cassert>
#include <algorithm>

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
	delete[] m_data;
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

void DataArray::Clear()
{
	std::fill(m_data, m_data + m_size, byte(0));
}

const void* DataArray::GetData() const
{
	return m_data;
}

void DataArray::SetData(const byte* pData, size_t size, size_t offset)
{
	assert(IsValid());
	assert((size + offset) <= m_size);
	std::copy(pData, pData + size, m_data + offset);
}

size_t DataArray::Size() const
{
	return m_size;
}

bool DataArray::IsValid() const
{
	return m_data != nullptr;
}
