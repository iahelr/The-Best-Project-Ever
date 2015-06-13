/*
 * Map.h
 *
 *  Created on: Jun 6, 2015
 *      Author: colman
 */

#ifndef MAP_H_
#define MAP_H_

#include "PngUtils/lodepng.h"
#include "PngUtils/pngUtil.h"
#include <iostream>
#include <vector>

class Map
{
public:
	static double map_resolution_in_cm;
	static double grid_resolution_in_cm;

	int _map_height;
	int _map_width;
	int** _map_matrix;

	int _grid_height;
	int _grid_width;
	int** _grid_matrix;

public:
	Map();
	virtual ~Map();
	static void ReadMapFromPngToMatrix(const char* filename, int**& map_matrix, int& rows, int& cols);
	static void BlowCell(int**& map_matrix, int height, int width, int cell_row, int cell_col, int blow_factor);
	static void BlowMap(int**& map_matrix, int height, int width, int blow_factor);
	void ConvertMapToGrid();
	static int GetGridIndexByMapIndex(int map_index);
	static void WriteMapMatrixToPng(int**& map_matrix, int height, int width, const char* filename);
};

#endif /* MAP_H_ */
