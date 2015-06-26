/*
 * WayPointManager.h
 *
 *  Created on: Jun 9, 2015
 *      Author: colman
 */

#ifndef WAYPOINTMANAGER_H_
#define WAYPOINTMANAGER_H_

#include <vector>

#include "WayPointManager.h"
#include "LocationMatrix.h"
#include "Utils/Location.h"
#include "Utils/WayPoint.h"
#include "Map.h"

using namespace std;

class WayPointManager {
private :

	Map _originalMap;
	vector<Location> _positions;
	vector<WayPoint> _wayPoints;
	unsigned _currentWayPoint;

public:

	WayPointManager(vector<Location> path, Map map);

	/**
	 * as long as we are not in the last way point , increase _currentWayPoint and return
	 * the new way point
	 */
	WayPoint advanceWayPoint()
	{
		this->_currentWayPoint++;
		return getCurrnetWayPoint();
	}

	/**
	 * Returns the current way point
	 */
	WayPoint getCurrnetWayPoint(){
		return _wayPoints[_currentWayPoint];
	}

	/**
	 * Gets a specific way point
	 */
	WayPoint getWayPointNumber(unsigned number){
		return _wayPoints[number];
	}

	/**
	 * Returns the amount of way points available in the given path
	 */
	unsigned getNumberOfWayPoints(){
		return _wayPoints.size();
	}

	vector<Location> getChosenPositions(){
		return _positions;
	}


	//*****************
	//	Public methods
	//*****************
	void savePointsOnMap(string name){
		//Utils::writeMapToPng(name,_originalMap);//TODO:ori - write map to png?
	}

private:
	/**
	 * Gets a path of GridPoisitions and chose a selected amount of
	 * Way points (takes one every 2 times robot size).
	 */
	void initializePositionsArray(vector<Location> path){
		/*int robotsInPixel = ConfigurationsManager::getRobotSize() / _originalMap.getCell2Cm(); //TODO:Ori - Robot size and this other things that need to filled up..

		int jumps = robotsInPixel * 2;

		// Naive algorithm , steps that are twice the robots size
		for(unsigned i=0; i< path.size(); i += jumps){
			this->_positions.push_back(path[i]);
		}

		if ((path.size() % jumps) != 0){
			this->_positions.push_back(path[path.size() -1]);
		}

		// Remove the first node
		_positions.erase(_positions.begin());

		Utils::insertPathToMap(_originalMap,_positions); //TODO:ori - need adapt here too..method that insert path to the map..
	*/}

	/**
	 * Transforms the chosen grid positions to way points
	 */
	void initializeWayPointsWrray(){
		for (unsigned i = 0; i < _positions.size() ; i++){
			/*Location loc = _originalMap.locationFromPosition(_positions[i]); // TODO: ori - need to add these method (LocationFromPosition)
			this->_wayPoints.push_back(WayPoint(loc,i));*/
		}
	}
};

#endif /* WAYPOINTSMANAGER_H_ */
