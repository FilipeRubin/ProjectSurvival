#pragma once
#include <algorithm>
#include <initializer_list>
#include <cassert>

template<typename T>
class ContiguousArray
{
public:
	ContiguousArray(size_t size) :
		m_array(new T[size]),
		m_size(size)
	{
	}

	ContiguousArray(const std::initializer_list<T>& elements) :
		m_array(new T[elements.size()]),
		m_size(elements.size())
	{
		std::copy(elements.begin(), elements.end(), m_array);
	}

	ContiguousArray(const ContiguousArray<T>& other) :
		m_array(new T[other.m_size]),
		m_size(other.m_size)
	{
		std::copy(other.m_array, other.m_array + other.m_size, m_array);
	}

	ContiguousArray(ContiguousArray<T>&& other) noexcept :
		m_array(other.m_array),
		m_size(other.m_size)
	{
		other.m_array = nullptr;
		other.m_size = 0U;
	}

	~ContiguousArray()
	{
		Cleanup();
	}

	ContiguousArray<T>& operator=(const ContiguousArray<T>& other)
	{
		if (this != &other)
		{
			Cleanup();
			m_array = new T[other.m_size];
			m_size = other.m_size;
			std::memcpy(m_array, other.m_array, other.m_size * sizeof(T));
		}

		return *this;
	}

	ContiguousArray<T>& operator=(ContiguousArray<T>&& other) noexcept
	{
		if (this != &other)
		{
			Cleanup();
			m_array = other.m_array;
			m_size = other.m_size;
			other.m_array = nullptr;
			other.m_size = 0U;
		}

		return *this;
	}

	T& operator[](size_t index)
	{
		return m_array[index];
	}

	void Append(const T& element)
	{
		T* newArray = new T[m_size + 1U];
		std::copy(m_array, m_array + m_size, newArray);
		newArray[m_size] = element;
		delete[] m_array;
		m_array = newArray;
		m_size++;
	}

	void Append(const std::initializer_list<T>& elements)
	{
		const T* arrayBegin = m_array;
		const T* arrayEnd = begin + m_size;

		T* newArray = new T[m_size + elements.size()];

		std::copy(arrayBegin, arrayEnd, newArray);
		std::copy(elements.begin(), elements.end(), newArray + m_size);

		delete[] m_array;
		m_array = newArray;
		m_size += elements.size();
	}

	void RemoveAt(size_t index)
	{
		assert(index < m_size);

		if (m_size == 1)
		{
			delete[] m_array;
			m_array = nullptr;
			m_size = 0;
			return;
		}
		
		T* newArray = new T[m_size - 1];

		std::copy(m_array, m_array + index, newArray);
		std::copy(m_array + index + 1, m_array + m_size, newArray + index);

		delete[] m_array;
		m_array = newArray;
		m_size--;
	}

	size_t Size() const
	{
		return m_size;
	}

	bool IsValid() const
	{
		return m_array != nullptr;
	}
private:
	T* m_array;
	size_t m_size;

	void Cleanup()
	{
		delete[] m_array;
		m_size = 0U;
	}
};