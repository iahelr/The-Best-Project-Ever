/*
 * MapHolderAStar.h
 *
 *  Created on: Jun 26, 2015
 *      Author: colman
 */

#ifndef MAPHOLDERASTAR_H_
#define MAPHOLDERASTAR_H_

#include "../Utils/Location.h"
#include "../Map.h"
#include "../IntMatrix.h"
#include <vector>

using namespace std;

class MapHolderAStar
{
private:
	Map _mapObj;
	IntMatrix _costs;

public:
	MapHolderAStar(Map mapObj)
	{
		_mapObj = mapObj;
	}
	MapHolderAStar();
	virtual ~MapHolderAStar();
	vector<Location> neighbors(Location center);
	unsigned cost(Location from, Location to);
};

#endif /* MAPHOLDERASTAR_H_ */
