/*
 * Plan.h
 *
 *  Created on: Dec 21, 2014
 *      Author: user
 */

#ifndef PLAN_H_
#define PLAN_H_
#include "../Behaviors/Behavior.h"
#include "../Robot.h"
class Plan {

protected:
	Behavior* _start;
public:
	Plan(Robot* robot);
	virtual Behavior* getStartPoint(){return _start;}
	virtual ~Plan();
};

#endif /* PLAN_H_ */
