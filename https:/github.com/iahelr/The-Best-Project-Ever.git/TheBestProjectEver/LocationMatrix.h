/*
 * LocationMatrix.h
 *
 *  Created on: Jun 26, 2015
 *      Author: colman
 */

#ifndef LOCATIONMATRIX_H_
#define LOCATIONMATRIX_H_

#include "Utils/Location.h"

class LocationMatrix
{
public:
	int _height;
	int _width;
	Location** _matrix;
	Location _defaultValue;

	LocationMatrix();
	virtual ~LocationMatrix();

	bool isPositionValid(unsigned x, unsigned y);
	bool isPositionDefault(Location pos);
};

#endif /* LOCATIONMATRIX_H_ */
