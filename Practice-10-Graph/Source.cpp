#include <iostream>
#include <vector>
#include <forward_list>

//typedef std::vector<std::vector<int>> Matrix;

using Matrix = std::vector<std::vector<int>>;
using NeighbourList = std::vector<std::forward_list<int>>;

void MakeMatrix(Matrix &matrix, size_t n)
{
	matrix.resize(n);

	for (auto &row : matrix)
		row.resize(n, 0);
}

void AddEdge(const size_t first, const size_t second, Matrix &matrix)
{
	size_t size = matrix.size();
	if (first>=size || second >=size)
	{
		throw std::out_of_range("Out of range.");
	}
	matrix[first][second] = 1;
}

void PrintMatrix(const Matrix &matrix)
{
	for (auto& row : matrix)
	{
		for (int edge : row)
			std::cout << edge << ' ';
		std::cout << '\n';
	}
}

void PrintNeighbours(const Matrix &matrix)
{
	size_t size = matrix.size();

	for (size_t i = 0; i < size; i++)
	{
		std::cout << i << ": ";
		for (size_t j = 0; j < size; i++)
		{
			if (matrix[i][j] !=0)
			{
				std::cout << j << ' ';
			}
		}
		std::cout << '\n';
	}
}


void convert(const Matrix &matrix, NeighbourList &list)
{
	size_t size = matrix.size();

	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; i++)
		{
			if (matrix[i][j] != 0)
			{
				list[i].push_front(j);
			}
		}
	}
}

void PrintList(const NeighbourList &list)
{
	size_t size = list.size();

	for (size_t i = 0; i < size; i++)
	{
		std::cout << i << ": { ";
		for (int edge : list[i])
			std::cout << edge;
		std::cout << " }\n";
	}
}

int main()
{
	Matrix test;
	
	MakeMatrix(test, 10);

	AddEdge(1, 2, test);

	PrintMatrix(test);

	return 0;
}