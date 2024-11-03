#include <iostream>
#include <cctype>
#include <cstdlib>
#include <fstream>

int main(int argc, char ** argv)
{
  if (argc < 4)
  {
    std::cerr << "Not enough arguments\n";
    return 1;
  }
  if (argc > 4)
  {
    std::cerr << "Too many arguments\n";
    return 1;
  }
  int num = std::atoi(argv[1]);
  if (num != 1 && num != 2)
  {
    std::cerr << "First parameter is out of range\n";
    return 1;
  }
  for (int i = 0; argv[1][i] != '\0'; ++i)
  {
    if (!std::isdigit(argv[1][i]))
    {
      std::cerr << "First parameter is not a number\n";
    }
  }
  std::ifstream input(argv[2]);
  size_t rows = 0;
  size_t columns = 0;
  input >> rows >> cols;
  if (input.fail())
  {
    std::cerr << "Invalid matrix dimensions\n";
    return 2;
  }
  std::ofstream output(argv[3]);
  if (num == 1)
  {
    int matrix[10000] = {0}
    if (!smirnov::inputMatrix(input, matrix, rows, columns))
    {
      std::cerr << "Incorrect data\n";
      return 2;
    }
    output << smirnov::processMatrix(matrix, rows, columns) << "\n";
  }
  else
  {
    int * matrix = new int[rows * columns];
    if (!smirnov::inputMatrix(input, matrix, rows, columns))
    {
      std::cerr << "Incorrect data\n";
      delete[] matrix;
      return 2;
    }
  output << smirnov::processMatrix(matrix, rows, columns) << "\n";
  delete[] matrix;
  }
}
