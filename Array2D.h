#ifndef ARRAY2D_H
#define ARRAY2D_H

template<typename T>
class Row;

template<typename T>
class Array2D
{
public:
	Array2D();
	Array2D(int row, int col);
	Array2D(const Array2D & copy);
	~Array2D();
	void Purge();
	Array2D & operator=(const Array2D & rhs);
	Row<T> operator[](int index);
	int getRow();
	void setRow(int rows);
	int getColumn();
	void setColumn(int columns);
	T & Select(int row, int column);
private:
	T** m_array;
	int m_row;
	int m_col;
};




#endif

template<typename T>
inline Array2D<T>::Array2D(): m_array(nullptr), m_row(0), m_col(0)
{
}

template<typename T>
inline Array2D<T>::Array2D(int row, int col): m_array(nullptr), m_row(row), m_col(col)
{
	if (row < 0 || col < 0)
		throw Exception("Invalid length or width");
	m_array = new T*[row];
	for (int i = 0; i < row; ++i)
	{
		m_array[i] = new T[col];
	}

}

template<typename T>
inline Array2D<T>::Array2D(const Array2D & copy) :m_array(nullptr), m_row(copy.m_row), m_col(copy.m_col)
{
	Purge();
	if (copy.m_array)
	{
		m_array = new T*[copy.m_row];
		for (int i = 0; i < copy.m_row; ++i)
		{
			m_array[i] = new T[copy.m_col];
		}
		for (int i = 0; i < copy.m_row; ++i)
		{
			for (int j = 0; j < copy.m_col; ++j)
			{
				m_array[i][j] = copy.m_array[i][j];
			}
		}
	}
}

template<typename T>
inline Array2D<T>::~Array2D()
{
	Purge();
	m_col = 0;
	m_row = 0;
}

template<typename T>
inline void Array2D<T>::Purge()
{
	if (m_array)
	{
		for (int i = 0; i < m_row; ++i)
		{
			delete[]m_array[i];
			m_array[i] = nullptr;
		}
		delete[]m_array;
		m_array = nullptr;
	}
}

template<typename T>
inline Array2D<T> & Array2D<T>::operator=(const Array2D & rhs)
{
	if (this != &rhs)
	{
		Purge();
		if (rhs.m_array != nullptr)
		{
			m_array = new T*[rhs.m_row];
			for (int i = 0; i < rhs.m_row; ++i)
			{
				m_array[i] = new T[rhs.m_col];
			}
			for (int i = 0; i < rhs.m_row; ++i)
			{
				for (int j = 0; j < rhs.m_col; ++j)
				{
					m_array[i][j] = rhs.m_array[i][j];
				}
			}
		}
		m_row = rhs.m_row;
		m_col = rhs.m_col;
	}

	return *this;
}

template<typename T>
inline Row<T> Array2D<T>::operator[](int index)
{
	//return Row<T>(const_cast<Array2D<T> &>(*this), index);

	return Row<T>(*this, index);//got to return this Row<T> to the Row<T> operator to the
}

template<typename T>
inline int Array2D<T>::getRow()
{
	return m_row;
}

template<typename T>
inline void Array2D<T>::setRow(int rows)
{
	if (rows > 0)
	{
		T ** temp = new T*[rows];
		for (int i = 0; i < rows; i++)
		{
			temp[i] = new T[m_col];
			for (int j = 0; j < m_col; ++j)
			{
				temp[i][j] = m_array[i][j];
			}
		}
		Purge();
		m_array = temp;
		m_row = rows;
	}
	else
	{
		throw Exception("Can't have negative or 0 rows");
	}
}

template<typename T>
inline int Array2D<T>::getColumn()
{
	return m_col;
}

template<typename T>
inline void Array2D<T>::setColumn(int columns)
{
	if (columns > 0)
	{
		T** temp = new T*[m_row];
		for (int i = 0; i < m_row; i++)
		{
			temp[i] = new T[columns];
			for (int j = 0; j < columns; ++j)
			{
				temp[i][j] = m_array[i][j];
			}
		}
		Purge();
		m_array = temp;
		m_col = columns;
	}
	else
	{
		throw Exception("Can't have negative or 0 Columns");
	}
}

template<typename T>
inline T & Array2D<T>::Select(int row, int column)
{
	if (row >= m_row || column >= m_col)
	{
		throw Exception("Access violation");
	}
	return m_array[row][column];
}
