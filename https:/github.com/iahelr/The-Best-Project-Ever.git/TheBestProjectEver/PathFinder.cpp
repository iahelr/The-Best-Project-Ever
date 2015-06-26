/*
 * PathFinder.cpp
 *
 *  Created on: Jun 6, 2015
 *      Author: colman
 */

#include "PathFinder.h"


PathFinder::PathFinder(Map map)
{
	this->_map = map;

}

//************
//	Navigation methods
//************
void PathFinder::findPath(Location source, Location destination)
{

	// a graph object
	MapHolderAStar graphObject(_map);

	/*
	// DEBUG
	this->_mapRoughPath = Map(_map);
	_mapRoughPath.setCellAtPosition(sourceCell,Source);
	_mapRoughPath.setCellAtPosition(destinationCell,Target);
	Utils::writeMapToPng("locations.png", _mapWithRoughPath);
	// DEBUG END
	 *
	 */

	// Apply A*
	_searcher.aStarSearch(graphObject, source, destination, _parentsMap, _costsMap);
	//_searcher.aStarSearch(graphObject,source,destination,_parentsMap, _costsMap);

	// Get path from parents map
	_resultPath = pathFromParentMap(source,destination);

	// Copy the original map and assign the path
	//this->_mapRoughPath = Map(_map);
	/*Utils::insertPathToMap(_mapRoughPath,_roughlocationsVector);
	_mapRoughPath.setCellAtPosition(sourceCell,Source);
	_mapRoughPath.setCellAtPosition(destinationCell,Target);*/
}
