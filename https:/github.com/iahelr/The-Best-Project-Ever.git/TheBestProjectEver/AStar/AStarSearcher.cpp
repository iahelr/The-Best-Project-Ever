/*
 * AStarSearcher.cpp
 *
 *  Created on: Jun 6, 2015
 *      Author: colman
 */

#include "AStarSearcher.h"

AStarSearcher::AStarSearcher()
{
}

void AStarSearcher::aStarSearch(MapHolderAStar mapGraph,
		Location start, Location target,
		LocationMatrix& parentsMap,
		IntMatrix& costMap)
{
	PriorityQueue frontier;

	/*cout << "From is : " ;
	start.printString();
	cout << endl;

	cout << "Target is : " ;
	target.printString();
	cout << endl;*/


	// initialize the start node
	frontier.put(start, 0);
	//parentsMap.setValueAtPosition(start,start);
	//costMap.setValueAtPosition(start,0);
	parentsMap._matrix[start.getX()][start.getY()] = start;
	costMap._matrix[start.getX()][start.getY()] = 0;

	// Perform the search
	while (!frontier.empty())
	{
		Location current = frontier.get();


		/*if (current == target){
			cout << LOG_INFO << "Reached target" << endl;
			break;
		}*/

		vector<Location> neighbors = mapGraph.neighbors(current);
		for (int i = 0; i < neighbors.size(); i++)
		{
			Location next = neighbors[i];
			int newCost = costMap._matrix[current.getX()][current.getY()] + mapGraph.cost(current,next);

			// Is the next node was not reached yet ? or dose the new cost is lower than
			// the cast it had so far ?
			if ((costMap.isPositionDefault(next)) || (newCost < costMap._matrix[next.getX()][next.getY()]))
			{

				/*cout << LOG_DEBUG << "Astar on node X=" << next.getX() << " and Y=" << next.getY() << " Because : ";
				if (costMap.isPositionDefault(next))
				{
					cout << "Node was not visited, given cost is " << newCost << endl;
				}
				else
				{
					cout << newCost <<  " is cheaper than " << costMap[next] << endl;
				}*/

				costMap._matrix[next.getX()][next.getY()] = newCost;


				// Get the new priority of the node
				int priority = newCost + AStarSearcher::heuristic(next, target);

				frontier.put(next, priority);
				parentsMap._matrix[next.getX()][next.getY()] = current;
				// cout << "X=" << next.getX() << ",Y=" << next.getY() << " parent is X=" <<cameFrom[next].getX() << ",Y=" << cameFrom[next].getY() <<endl;
			}
		}
	}
	//cout << LOG_DEBUG << "Finished A* getting path "  << endl;
	if (parentsMap.isPositionDefault(target))
	{
		cout << "Target was never reached" << endl;
	}
}

int AStarSearcher::heuristic(Location from, Location to)
{
	int fromX = from.getX();
	int fromY = from.getY();
	int toX = to.getX();
	int toY = to.getY();

	return abs(fromX - toX) + abs(fromY- toY);
}
