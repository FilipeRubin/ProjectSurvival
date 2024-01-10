#pragma once
#include <cstddef>

class DataArray
{
public:
	DataArray(size_t size);
	DataArray(const DataArray& other);
	DataArray(DataArray&& other) noexcept;
	~DataArray();
	DataArray& operator=(const DataArray& other);
	DataArray& operator=(DataArray&& other) noexcept;
	void Clear();
	void Fill(std::byte value);
	const std::byte* GetData() const;
	void SetData(const std::byte* pData, size_t size, size_t offset);
	size_t Size() const;
	bool IsValid() const;
private:
	std::byte* m_data;
	size_t m_size;
};