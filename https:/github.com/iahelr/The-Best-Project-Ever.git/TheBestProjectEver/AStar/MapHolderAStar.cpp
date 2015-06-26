/*
 * MapHolderAStar.cpp
 *
 *  Created on: Jun 26, 2015
 *      Author: colman
 */

#include "MapHolderAStar.h"

MapHolderAStar::MapHolderAStar() {
	// TODO Auto-generated constructor stub

}

MapHolderAStar::~MapHolderAStar() {
	// TODO Auto-generated destructor stub
}

vector<Location> MapHolderAStar::neighbors(Location center)
{
	vector<Location> neighbors;

	for (int direction = Up; direction <= Up_Left; direction ++)
	{
		Location neighbor = center.getRelativePosition((Directions)direction);

		if ((_mapObj._map.isPositionValid(neighbor.getX(), neighbor.getY())) && (_mapObj._map._matrix[neighbor.getX()][neighbor.getY()] != 1))
		{
			neighbors.push_back(neighbor);
		}
	}

	return neighbors;
}

unsigned MapHolderAStar::cost(Location from, Location to)
{
	return max(_costs._matrix[from.getX()][from.getY()],_costs._matrix[to.getX()][to.getY()]);
}

