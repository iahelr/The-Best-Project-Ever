/*
 * main.cpp
 *
 *  Created on: Dec 14, 2014
 *      Author: user
 */

#include "Robot.h"
#include "Manager.h"
#include "Plans/PlnObstacleAvoid.h"
#include "Map.h"
#include "Utils.h"

#include <fstream>

using namespace std;

int main()
{
	// Open the parameters file
	ifstream file("parameters.txt");

	// Checking if the file wasn't opened (for any reason)
	if (!file.is_open())
	{
		// Print error and exit the program
		cout << "Error while reading the parameters file!";

		return 0;
	}
	// The file was opened successfully
	else
	{
		string line1, line2, line3, line4, line5, line6;

		// Read the first 6 lines in the file (this is the required params)
		getline(file, line1);
		getline(file, line2);
		getline(file, line3);
		getline(file, line4);
		getline(file, line5);
		getline(file, line6);

		std::vector<std::string> arr;

		// Get the map path (line 1)
		arr = Utils::split(line1, " ");
		string map_path = arr[1].c_str();
		map_path = map_path.substr(0, map_path.length() - 1); // Remove last character because it is new line

		// Get the robot location (line 2)
		arr = Utils::split(line2, " ");
		int robot_location_x = atoi(arr[1].c_str());
		int robot_location_y = atoi(arr[2].c_str());
		int robot_location_yaw = atoi(arr[3].c_str());

		// Get the destination point (line 3)
		arr = Utils::split(line3, " ");
		int dest_x = atoi(arr[1].c_str());
		int dest_y = atoi(arr[2].c_str());

		// Get the robot size (line 4)
		arr = Utils::split(line4, " ");
		int robot_size_x = atoi(arr[1].c_str());
		int robot_size_y = atoi(arr[2].c_str());

		// Get the map resolution (line 5)
		arr = Utils::split(line5, " ");
		double map_res_in_cm = atof(arr[1].c_str());

		// Get the grid resolution (line 6)
		arr = Utils::split(line6, " ");
		double grid_res_in_cm = atof(arr[1].c_str());

		// Print the details (we don't really need to print it... just printing to check if we read
		// successfully all the details)
		cout << "the params that was read are:" << endl;
		cout << "map path = " << map_path << endl;
		cout << "robot location (x,y,yaw) = " << robot_location_x << "," << robot_location_y << "," << robot_location_yaw << endl;
		cout << "destination point (x,y) = " << dest_x << "," << dest_y << endl;
		cout << "robot size = " << robot_size_x << " x " << robot_size_y << " CM" << endl;
		cout << "map resolution = " << map_res_in_cm << endl;
		cout << "grid resolution = " << grid_res_in_cm << endl;

		// Set the robot size to be the max number between the its measurements
		double robot_size = std::max(robot_size_x, robot_size_y);

		// Save the map and grid resolutions
		Map::map_resolution_in_cm = map_res_in_cm;
		Map::grid_resolution_in_cm = grid_res_in_cm;

		// Create the map object
		Map mapObj;

		// Read the map from png file and put it in the map matrix
		Map::ReadMapFromPngToMatrix(map_path.c_str(), mapObj._map_matrix, mapObj._map_height, mapObj._map_width);

		// Calculate how much cells (pixels) we need to blow around each obstacle in the map
		int blowing_factor = ((robot_size / 2) / Map::map_resolution_in_cm) +
							 (fmod(robot_size, Map::map_resolution_in_cm) == 0 ? 0 : 1);

		//Map::WriteMapMatrixToPng(mapObj._map_matrix, mapObj._map_height, mapObj._map_width, "before_blow.png");

		// Blow the map
		Map::BlowMap(mapObj._map_matrix, mapObj._map_height, mapObj._map_width, blowing_factor);

		//Map::WriteMapMatrixToPng(mapObj._map_matrix, mapObj._map_height, mapObj._map_width, "after_blow.png");

		// Convert the map to grid (according to the map and grid resolutions)
		mapObj.ConvertMapToGrid();

		//Map::WriteMapMatrixToPng(mapObj._grid_matrix, mapObj._grid_height, mapObj._grid_width, "grid_result.png");

		cout << endl << "finish!!!!!!" << endl;
	}

	//Robot robot("localhost",6665);
	//PlnObstacleAvoid plnOA(&robot);
	//Manager manager(&robot, &plnOA);
	//manager.run();
}
