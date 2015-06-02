#include "Robot.h"
#include "Manager.h"
#include "AvoidObstaclePlan.h"
int main()
{
	Robot robot("localhost",6665);
	AvoidObstaclePlan plnOA(&robot);
	Manager manager(&robot, &plnOA);
	manager.run();

}
