/*
 * Map.cpp
 *
 *  Created on: Jun 6, 2015
 *      Author: colman
 */

#include "Map.h"

Map::Map()
{
	// TODO Auto-generated constructor stub
}

Map::~Map()
{
	// TODO Auto-generated destructor stub
}

void Map::ReadMapFromPngToMatrix(const char* filename, int**& map_matrix, int& rows, int& cols)
{
	std::vector<unsigned char> image; //the raw pixels
	unsigned width, height;
	unsigned x, y;
	unsigned error = lodepng::decode(image, width, height, filename);

	rows = height;
	cols = width;

	// if there's an error, display it
	if (error)
	{
		std::cout << "decoder error " << error << ": " << lodepng_error_text(error) << std::endl;
	}

	// Initialize the map matrix
	map_matrix = new int*[rows];
	for (int row = 0; row < rows; row++)
	{
		map_matrix[row] = new int[cols];
	}

	// Run over all the rows
	for (y = 0; y < height; y++)
	{
		// Run over all the cols
		for (x = 0; x < width; x++)
		{
			// Checking if the current pixel is NOT BLACK (means a free cell)
			if (image[y * width * 4 + x * 4 + 0] ||
				image[y * width * 4 + x * 4 + 1] ||
				image[y * width * 4 + x * 4 + 2])
			{
				map_matrix[y][x] = 0;
			}
			// The current pixel is BLACK (means a occupied cell)
			else
			{
				map_matrix[y][x] = 1;
			}
		}
	}
}

void Map::InflateCell(int**& map_matrix, int height, int width, int cell_row, int cell_col, int inflation_factor)
{
	// Set the cell indices where to start scan the inflated cells matrix
	int nInflatedMatrixRowStart = cell_row - inflation_factor;
	int nInflatedMatrixColStart = cell_col - inflation_factor;

	// Set the size of the inflated cells matrix
	int nInflatedMatrixSize = (inflation_factor * 2) + 1;

	// Running over all the rows in the inflated cells matrix
	for (int row_index = nInflatedMatrixRowStart; row_index < nInflatedMatrixRowStart + nInflatedMatrixSize; row_index++)
	{
		// Running over all the cols in the inflated cells matrix
		for (int col_index = nInflatedMatrixColStart; col_index < nInflatedMatrixColStart + nInflatedMatrixSize; col_index++)
		{
			// Validating that the current cell is inside the map borders
			if (row_index >= 0 && row_index <= height - 1 && col_index >= 0 && col_index <= width - 1)
			{
				// Checking if the current cell is free
				if (map_matrix[row_index][col_index] == 0)
				{
					// Set this cell as inflated
					map_matrix[row_index][col_index] = 2;
				}
			}
		}
	}
}

void Map::InflateMap(int**& map_matrix, int height, int width, int inflation_factor)
{
	// Run over all the rows in the map
	for (int row = 0; row < height; row++)
	{
		// Run over all the cols in the map
		for (int col = 0; col < width; col++)
		{
			// Checking if the current cell is obstacle
			if (map_matrix[row][col] == 1)
			{
				InflateCell(map_matrix, height, width, row, col, inflation_factor);
			}
		}
	}
}

void Map::ConvertMapToGrid(int**& map_matrix, int**& grid_matrix, int grid_rows, int grid_cols, int resolutions_ratio)
{
	/*
	 * Fill the grid matrix cells
	 */

	// Running over all the grid rows
	for (int row = 0; row < grid_rows; row++)
	{
		// Running over all the grid cols
		for (int col = 0; col < grid_cols; col++)
		{
			// Checking if the current cell belongs to borders of the map
			if ((row == 0) || (row == grid_rows - 1) || (col == 0) || (col == grid_cols - 1))
			{
				// Set this cell as obstacle
				grid_matrix[row][col] = 1;
			}
			// The current cell doesn't belong to the last row or last col
			else
			{
				bool obstacle_found = false;

				/*
				 * Run over the pixels matrix that should be represented by the current cell and searching
				 * for obstacles
				 */

				for (int i = 0; i < resolutions_ratio && !obstacle_found; ++i)
				{
					for (int j = 0; j < resolutions_ratio && !obstacle_found; ++j)
					{
						// Checking if the current cell in the pixels matrix is not FREE
						if (map_matrix[(row * resolutions_ratio) + i][(col * resolutions_ratio) + j] != 0)
						{
							obstacle_found = true;
						}
					}
				}

				// Checking if we found at least one obstacle (and then this grid cell should be OCCUPIED)
				if (obstacle_found)
				{
					grid_matrix[row][col] = 1;
				}
				// There is no obstacles so this cell should be FREE
				else
				{
					grid_matrix[row][col] = 0;
				}
			}
		}
	}
}

