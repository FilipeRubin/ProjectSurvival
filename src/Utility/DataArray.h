#pragma once
#include <cstddef>

class DataArray
{
public:
	DataArray(size_t size);
	DataArray(const DataArray& other) = delete;
	DataArray(DataArray&& other) noexcept;
	~DataArray();
	DataArray& operator=(const DataArray& other) = delete;
	DataArray& operator=(DataArray&& other) noexcept;
	void Clear();
	const void* GetData() const;
	void SetData(const std::byte* pData, size_t size, size_t offset);
	size_t Size() const;
	bool IsValid() const;
private:
	std::byte* m_data;
	size_t m_size;
};