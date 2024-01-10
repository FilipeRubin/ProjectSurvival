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

DataArray::DataArray(const DataArray& other)
{
	m_data = new byte[other.m_size];
	std::copy(other.m_data, other.m_data + other.m_size, m_data);
	m_size = other.m_size;
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

DataArray& DataArray::operator=(const DataArray& other)
{
	delete[] m_data;
	std::copy(other.m_data, other.m_data + other.m_size, m_data);
	m_size = other.m_size;
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
	delete[] m_data;
	m_size = 0;
}

void DataArray::Fill(byte value)
{
	std::fill(m_data, m_data + m_size, value);
}

const std::byte* DataArray::GetData() const
{
	return static_cast<const std::byte*>(m_data);
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
