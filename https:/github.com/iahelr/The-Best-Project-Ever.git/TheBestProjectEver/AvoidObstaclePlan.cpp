/*
 * PlnObstacleAvoid.cpp
 *
 *  Created on: Dec 21, 2014
 *      Author: user
 */

#include "AvoidObstaclePlan.h"

AvoidObstaclePlan::AvoidObstaclePlan(Robot* robot) {
	//Creating Behaviors
	_beh[0] = new A(robot);
	_beh[1] = new B(robot);
	_beh[2] = new C(robot);

	//Connecting Behaviors
	_beh[0]->addBeh(_beh[1]);
	_beh[0]->addBeh(_beh[2]);
	_beh[1]->addBeh(_beh[2]);
	_beh[2]->addBeh(_beh[0]);
	_start = _beh[0];
}

AvoidObstaclePlan::~AvoidObstaclePlan() {
	// TODO Auto-generated destructor stub
	for(int i=0;i<3;i++)
		delete _beh[i];
}
