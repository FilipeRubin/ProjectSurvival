#pragma once

class DataArray
{
public:
	DataArray(size_t size);
	DataArray(const DataArray& other) = delete;
	DataArray(DataArray&& other) noexcept;
	~DataArray();
	DataArray& operator=(const DataArray& other) = delete;
	DataArray& operator=(DataArray&& other) noexcept;
	const void* GetData() const;
	bool IsValid() const;
private:
	void* m_data;
	size_t m_size;
};