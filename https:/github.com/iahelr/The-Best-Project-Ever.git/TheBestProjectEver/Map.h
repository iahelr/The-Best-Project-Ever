/*
 * Map.h
 *
 *  Created on: Jun 6, 2015
 *      Author: colman
 */

#ifndef MAP_H_
#define MAP_H_

#include "PngUtils/lodepng.h"
#include <iostream>
#include <vector>

class Map
{
public:
	Map();
	virtual ~Map();
	void ReadMapFromPngToMatrix(const char* filename, int**& map_matrix, int& rows, int& cols);
	void InflateCell(int**& map_matrix, int height, int width, int cell_row, int cell_col, int inflation_factor);
	void InflateMap(int**& map_matrix, int height, int width, int inflation_factor);
	void ConvertMapToGrid(int**& map_matrix, int**& grid_matrix, int grid_rows, int grid_cols, int resolutions_ratio);
};

#endif /* MAP_H_ */
