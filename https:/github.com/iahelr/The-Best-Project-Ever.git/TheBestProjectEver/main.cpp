/*
 *  main.cpp
 *
 *  Created on: Nov 26, 2014
 *  Anna Sapoznikov 309271989
 *  Heli Rahamim 305561698
 *  Anna Spektorov 305861486S
 */

#include <iostream>
#include "Manager.h"
#include "Robot.h"
#include "Plans/AvoidObstaclePlan.h"
#include <fstream>

int main(int argc, char** argv)
{
	try{
	Robot robot("10.10.245.64",6665);
	AvoidObstaclePlan pln(&robot);
	Manager m(&robot,&pln);
	m.run();
	}
	catch(int e)
	{
		cout<<"exception: "<< e<<endl;

	}
}
