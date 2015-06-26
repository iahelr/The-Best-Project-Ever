/*
 * Matrix.h
 *
 *  Created on: Jun 26, 2015
 *      Author: colman
 */

#ifndef INT_MATRIX_H_
#define INT_MATRIX_H_

#include "Utils/Location.h"

class IntMatrix
{
public:
	int _height;
	int _width;
	int** _matrix;
	int _defaultValue;

	IntMatrix();
	virtual ~IntMatrix();

	bool isPositionValid(unsigned x, unsigned y);
	bool isPositionDefault(Location pos);
};

#endif /* INT_MATRIX_H_ */
