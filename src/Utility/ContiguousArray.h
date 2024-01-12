#pragma once
#include <algorithm>
#include <initializer_list>
#include <cassert>

template<typename T>
class ContiguousArray
{
public:
	ContiguousArray(size_t size = 0U) :
		m_array(nullptr),
		m_length(size)
	{
		if (size != 0U)
		{
			m_array = new T[size];
		}
	}

	ContiguousArray(const std::initializer_list<T>& elements) :
		m_array(nullptr),
		m_length(elements.size())
	{
		if (elements.size() != 0U)
		{
			m_array = new T[elements.size()];
			std::copy(elements.begin(), elements.end(), m_array);
		}
	}

	ContiguousArray(const ContiguousArray<T>& other) :
		m_array(new T[other.m_length]),
		m_length(other.m_length)
	{
		std::copy(other.m_array, other.m_array + other.m_length, m_array);
	}

	ContiguousArray(ContiguousArray<T>&& other) noexcept :
		m_array(other.m_array),
		m_length(other.m_length)
	{
		other.m_array = nullptr;
		other.m_length = 0U;
	}

	~ContiguousArray()
	{
		Clear();
	}

	ContiguousArray<T>& operator=(const ContiguousArray<T>& other)
	{
		if (this != &other)
		{
			Clear();
			m_array = new T[other.m_length];
			m_length = other.m_length;
			std::copy(other.m_array, other.m_array + other.m_length, m_array);
		}

		return *this;
	}

	ContiguousArray<T>& operator=(ContiguousArray<T>&& other) noexcept
	{
		if (this != &other)
		{
			Clear();
			m_array = other.m_array;
			m_length = other.m_length;
			other.m_array = nullptr;
			other.m_length = 0U;
		}

		return *this;
	}

	T& operator[](size_t index)
	{
		return m_array[index];
	}

	void Append(const T& element)
	{
		T* newArray = new T[m_length + 1U];
		std::copy(m_array, m_array + m_length, newArray);
		newArray[m_length] = element;
		delete[] m_array;
		m_array = newArray;
		m_length++;
	}

	void Append(const std::initializer_list<T>& elements)
	{
		if (elements.size() == 0)
			return;

		const T* arrayBegin = m_array;
		const T* arrayEnd = arrayBegin + m_length;

		T* newArray = new T[m_length + elements.size()];

		std::copy(arrayBegin, arrayEnd, newArray);
		std::copy(elements.begin(), elements.end(), newArray + m_length);

		delete[] m_array;
		m_array = newArray;
		m_length += elements.size();
	}

	void Clear()
	{
		delete[] m_array;
		m_array = nullptr;
		m_length = 0;
	}

	bool IsValid() const
	{
		return m_array != nullptr;
	}

	void RemoveAt(size_t index)
	{
		assert(index < m_length);

		if (m_length == 1)
		{
			Clear();
			return;
		}
		
		T* newArray = new T[m_length - 1];

		std::copy(m_array, m_array + index, newArray);
		std::copy(m_array + index + 1, m_array + m_length, newArray + index);

		delete[] m_array;
		m_array = newArray;
		m_length--;
	}

	size_t Length() const
	{
		return m_length;
	}
private:
	T* m_array;
	size_t m_length;
};