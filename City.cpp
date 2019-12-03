#include "City.h"

City::City() {

}

void City::addBuilding(Building* BuildingNode) {
	Buildings.push_back(BuildingNode);
}

void City::addRoad(Road* RoadNode) {
	Roads.push_back(RoadNode);
}

void City::addGround(Ground* GroundNode) {
	Grounds.push_back(GroundNode);
}

void City::BuildCity() {

	{
		//tile 1
		addRoad(new Road(glm::vec3(25.0f, 0.0f, 0.0f + 30.0f), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(30.0f, 0.0f, 0.0f + 30.0f), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(35.0f, 0.0f, 0.0f + 30.0f), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(25.0f, 0.0f, 0.0f + 25.0f), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(30.0f, 0.0f, 0.0f + 25.0f), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(35.0f, 0.0f, 0.0f + 25.0f), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(25.0f, 0.0f, 0.0f + 35.0f), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(30.0f, 0.0f, 0.0f + 35.0f), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(35.0f, 0.0f, 0.0f + 35.0f), 5, 5, "roadPLAZA.png"));
	}
	{
		//tile 2
		addRoad(new Road(glm::vec3(5.0f, 0.0f, 0.0f + 30.0f), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(10.0f, 0.0f, 0.0f + 30.0f), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(15.0f, 0.0f, 0.0f + 30.0f), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(5.0f, 0.0f, 0.0f + 25.0f), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(10.0f, 0.0f, 0.0f + 25.0f), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(15.0f, 0.0f, 0.0f + 25.0f), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(5.0f, 0.0f, 0.0f + 35.0f), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(10.0f, 0.0f, 0.0f + 35.0f), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(15.0f, 0.0f, 0.0f + 35.0f), 5, 5, "roadPLAZA.png"));
	}	
	{
		// tile 3
		addRoad(new Road(glm::vec3(-1 * 5.0f, 0.0f, 30.0f), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(-1 * 10.0f, 0.0f, 30.0f), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(-1 * 15.0f, 0.0f, 30.0f), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(-1 * 5.0f, 0.0f, 25.0f), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(-1 * 10.0f, 0.0f, 25.0f), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(-1 * 15.0f, 0.0f, 25.0f), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(-1 * 5.0f, 0.0f, 35.0f), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(-1 * 10.0f, 0.0f, 35.0f), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(-1 * 15.0f, 0.0f, 35.0f), 5, 5, "roadPLAZA.png"));
	}
	{
		//tile 4
		addRoad(new Road(glm::vec3(-1 * 25.0f, 0.0f, 30.0f), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(-1 * 30.0f, 0.0f, 30.0f), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(-1 * 35.0f, 0.0f, 30.0f), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(-1 * 25.0f, 0.0f, 25.0f), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(-1 * 30.0f, 0.0f, 25.0f), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(-1 * 35.0f, 0.0f, 25.0f), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(-1 * 25.0f, 0.0f, 35.0f), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(-1 * 30.0f, 0.0f, 35.0f), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(-1 * 35.0f, 0.0f, 35.0f), 5, 5, "roadPLAZA.png"));
	}
	{
		//tile5
		addRoad(new Road(glm::vec3(30.0f, 0.0f, 5.0f), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(30.0f, 0.0f, 10.0f), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(30.0f, 0.0f, 15.0f), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(25.0f, 0.0f, 5.0f), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(25.0f, 0.0f, 10.0f), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(25.0f, 0.0f, 15.0f), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(35.0f, 0.0f, 5.0f), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(35.0f, 0.0f, 10.0f), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(35.0f, 0.0f, 15.0f), 5, 5, "roadPLAZA.png"));
	}
	{
		//tile 6
		addRoad(new Road(glm::vec3(10.0f, 0.0f, 5.0), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(10.0f, 0.0f, 10.0), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(10.0f, 0.0f, 15.0), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(5.0f, 0.0f, 5.0), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(5.0f, 0.0f, 10.0), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(5.0f, 0.0f, 15.0), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(15.0f, 0.0f, 5.0), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(15.0f, 0.0f, 10.0), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(15.0f, 0.0f, 15.0), 5, 5, "roadPLAZA.png"));
	}
	{
		//tile 7
		addRoad(new Road(glm::vec3(-1 * 10.0f, 0.0f, 5.0f), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(-1 * 10.0f, 0.0f, 10.0f), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(-1 * 10.0f, 0.0f, 15.0f), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(-1 * 5.0f, 0.0f, 5.0f), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(-1 * 5.0f, 0.0f, 10.0f), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(-1 * 5.0f, 0.0f, 15.0f), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(-1 * 15.0f, 0.0f, 5.0f), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(-1 * 15.0f, 0.0f, 10.0f), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(-1 * 15.0f, 0.0f, 15.0f), 5, 5, "roadPLAZA.png"));
	}
	{
		//tile 8
		addRoad(new Road(glm::vec3(-1 * 30.0f, 0.0f, 5.0f), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(-1 * 30.0f, 0.0f, 10.0f), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(-1 * 30.0f, 0.0f, 15.0f), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(-1 * 25.0f, 0.0f, 5.0f), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(-1 * 25.0f, 0.0f, 10.0f), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(-1 * 25.0f, 0.0f, 15.0f), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(-1 * 35.0f, 0.0f, 5.0f), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(-1 * 35.0f, 0.0f, 10.0f), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(-1 * 35.0f, 0.0f, 15.0f), 5, 5, "roadPLAZA.png"));
	}
	{
		//tile 9
		addRoad(new Road(glm::vec3(30.0f, 0.0f, -1 * 5.0f), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(30.0f, 0.0f, -1 * 10.0f), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(30.0f, 0.0f, -1 * 15.0f), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(25.0f, 0.0f, -1 * 5.0f), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(25.0f, 0.0f, -1 * 10.0f), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(25.0f, 0.0f, -1 * 15.0f), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(35.0f, 0.0f, -1 * 5.0f), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(35.0f, 0.0f, -1 * 10.0f), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(35.0f, 0.0f, -1 * 15.0f), 5, 5, "roadPLAZA.png"));
	}
	{
		//tile 10
		addRoad(new Road(glm::vec3(10.0f, 0.0f, -1 * 5.0), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(10.0f, 0.0f, -1 * 10.0), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(10.0f, 0.0f, -1 * 15.0), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(5.0f, 0.0f, -1 * 5.0), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(5.0f, 0.0f, -1 * 10.0), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(5.0f, 0.0f, -1 * 15.0), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(15.0f, 0.0f, -1 * 5.0), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(15.0f, 0.0f, -1 * 10.0), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(15.0f, 0.0f, -1 * 15.0), 5, 5, "roadPLAZA.png"));
	}
	{
		//tile 11
		addRoad(new Road(glm::vec3(-1 * 10.0f, 0.0f, -1 * 5.0f), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(-1 * 10.0f, 0.0f, -1 * 10.0f), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(-1 * 10.0f, 0.0f, -1 * 15.0f), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(-1 * 5.0f, 0.0f, -1 * 5.0f), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(-1 * 5.0f, 0.0f, -1 * 10.0f), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(-1 * 5.0f, 0.0f, -1 * 15.0f), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(-1 * 15.0f, 0.0f, -1 * 5.0f), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(-1 * 15.0f, 0.0f, -1 * 10.0f), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(-1 * 15.0f, 0.0f, -1 * 15.0f), 5, 5, "roadPLAZA.png"));
	}
	{
		//tile 12
		addRoad(new Road(glm::vec3(-1 * 30.0f, 0.0f, -1 * 5.0f), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(-1 * 30.0f, 0.0f, -1 * 10.0f), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(-1 * 30.0f, 0.0f, -1 * 15.0f), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(-1 * 25.0f, 0.0f, -1 * 5.0f), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(-1 * 25.0f, 0.0f, -1 * 10.0f), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(-1 * 25.0f, 0.0f, -1 * 15.0f), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(-1 * 35.0f, 0.0f, -1 * 5.0f), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(-1 * 35.0f, 0.0f, -1 * 10.0f), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(-1 * 35.0f, 0.0f, -1 * 15.0f), 5, 5, "roadPLAZA.png"));
	}
	{
		//tile 13
		addRoad(new Road(glm::vec3(25.0f, 0.0f, -1 * 30.0f), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(30.0f, 0.0f, -1 * 30.0f), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(35.0f, 0.0f, -1 * 30.0f), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(25.0f, 0.0f, -1 * 25.0f), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(30.0f, 0.0f, -1 * 25.0f), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(35.0f, 0.0f, -1 * 25.0f), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(25.0f, 0.0f, -1 * 35.0f), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(30.0f, 0.0f, -1 * 35.0f), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(35.0f, 0.0f, -1 * 35.0f), 5, 5, "roadPLAZA.png"));
	}
	{
		//tile 14
		addRoad(new Road(glm::vec3(5.0f, 0.0f, -1 * 30.0f), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(10.0f, 0.0f, -1 * 30.0f), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(15.0f, 0.0f, -1 * 30.0f), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(5.0f, 0.0f, -1 * 25.0f), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(10.0f, 0.0f, -1 * 25.0f), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(15.0f, 0.0f, -1 * 25.0f), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(5.0f, 0.0f, -1 * 35.0f), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(10.0f, 0.0f, -1 * 35.0f), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(15.0f, 0.0f, -1 * 35.0f), 5, 5, "roadPLAZA.png"));
	}
	{
		//tile 15
		addRoad(new Road(glm::vec3(-1 * 5.0f, 0.0f, -1 * 30.0f), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(-1 * 10.0f, 0.0f, -1 * 30.0f), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(-1 * 15.0f, 0.0f, -1 * 30.0f), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(-1 * 5.0f, 0.0f, -1 * 25.0f), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(-1 * 10.0f, 0.0f, -1 * 25.0f), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(-1 * 15.0f, 0.0f, -1 * 25.0f), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(-1 * 5.0f, 0.0f, -1 * 35.0f), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(-1 * 10.0f, 0.0f, -1 * 35.0f), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(-1 * 15.0f, 0.0f, -1 * 35.0f), 5, 5, "roadPLAZA.png"));
	}
	{
		//tile 16
		addRoad(new Road(glm::vec3(-1 * 25.0f, 0.0f, -1 * 30.0f), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(-1 * 30.0f, 0.0f, -1 * 30.0f), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(-1 * 35.0f, 0.0f, -1 * 30.0f), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(-1 * 25.0f, 0.0f, -1 * 25.0f), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(-1 * 30.0f, 0.0f, -1 * 25.0f), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(-1 * 35.0f, 0.0f, -1 * 25.0f), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(-1 * 25.0f, 0.0f, -1 * 35.0f), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(-1 * 30.0f, 0.0f, -1 * 35.0f), 5, 5, "roadPLAZA.png"));
		addRoad(new Road(glm::vec3(-1 * 35.0f, 0.0f, -1 * 35.0f), 5, 5, "roadPLAZA.png"));
	}
	
	for (int j = 0; j < 3; j++) {//vertical
		addRoad(new Road(glm::vec3(0.0f, 0.0f,0.0f), 5, 5, "roadNEWS.png"));
		//
		for (int i = 0; i < 3; i++) {
			addRoad(new Road(glm::vec3(0.0f + 20.0f*j, 0.0f, 5.0f + 5.0f*i), 5, 5,"roadNS.png"));
			addRoad(new Road(glm::vec3(0.0f + 20.0f*j, 0.0f, -1*5.0f - 5.0f*i), 5, 5, "roadNS.png"));			
		}
		for (int i = 0; i < 3; i++) {
			addRoad(new Road(glm::vec3(0.0f - 20.0f*j, 0.0f, 5.0f + 5.0f*i), 5, 5, "roadNS.png"));
			addRoad(new Road(glm::vec3(0.0f - 20.0f*j, 0.0f, -1*5.0f - 5.0f*i), 5, 5, "roadNS.png"));
		}
		addRoad(new Road(glm::vec3(0.0f, 0.0f, 5.0f*4), 5, 5, "roadNEWS.png"));
		addRoad(new Road(glm::vec3(0.0f, 0.0f, -1*5.0f*4), 5, 5, "roadNEWS.png"));
		addRoad(new Road(glm::vec3(-20.0f, 0.0f, 0.0f), 5, 5, "roadNEWS.png"));
		addRoad(new Road(glm::vec3(20.0f, 0.0f, 0.0f), 5, 5, "roadNEWS.png"));
		addRoad(new Road(glm::vec3(20.0f, 0.0f, 5.0f * 4), 5, 5, "roadNEWS.png"));
		addRoad(new Road(glm::vec3(20.0f, 0.0f, -1 * 5.0f * 4), 5, 5, "roadNEWS.png"));
		addRoad(new Road(glm::vec3(-1*20.0f, 0.0f, 5.0f * 4), 5, 5, "roadNEWS.png"));
		addRoad(new Road(glm::vec3(-1*20.0f, 0.0f, -1 * 5.0f * 4), 5, 5, "roadNEWS.png"));
		//
		for (int i = 0; i < 3; i++) {
			addRoad(new Road(glm::vec3(0.0f + 20.0f*j, 0.0f, 25.0f + 5.0f*i), 5, 5, "roadNS.png"));
			addRoad(new Road(glm::vec3(0.0f + 20.0f*j, 0.0f, -1*25.0f - 5.0f*i), 5, 5, "roadNS.png"));
		}
		for (int i = 0; i < 3; i++) {
			addRoad(new Road(glm::vec3(0.0f - 20.0f*j, 0.0f, 25.0f + 5.0f*i), 5, 5, "roadNS.png"));
			addRoad(new Road(glm::vec3(0.0f - 20.0f*j, 0.0f, -1*25.0f - 5.0f*i), 5, 5, "roadNS.png"));
		}

		addRoad(new Road(glm::vec3(0.0f, 0.0f, 20.0f + 5.0f*4), 5, 5, "roadTN.png"));
		addRoad(new Road(glm::vec3(20.0f, 0.0f, 20.0f + 5.0f * 4), 5, 5, "roadTN.png"));
		addRoad(new Road(glm::vec3(-1*20.0f, 0.0f, 20.0f + 5.0f * 4), 5, 5, "roadTN.png"));
		addRoad(new Road(glm::vec3(40.0f, 0.0f, 20.0f + 5.0f * 4), 5, 5, "roadNW.png"));
		addRoad(new Road(glm::vec3(-1 * 40.0f, 0.0f, 20.0f + 5.0f * 4), 5, 5, "roadNE.png"));

		addRoad(new Road(glm::vec3(0.0f, 0.0f, -1*20.0f - 5.0f * 4), 5, 5, "roadTS.png"));
		addRoad(new Road(glm::vec3(20.0f, 0.0f, -1*20.0f - 5.0f * 4), 5, 5, "roadTS.png"));
		addRoad(new Road(glm::vec3(-1 * 20.0f, 0.0f, -1*20.0f - 5.0f * 4), 5, 5, "roadTS.png"));
		addRoad(new Road(glm::vec3(40.0f, 0.0f, -1*20.0f - 5.0f * 4), 5, 5, "roadSW.png"));
		addRoad(new Road(glm::vec3(-1 * 40.0f, 0.0f, -1*20.0f - 5.0f * 4), 5, 5, "roadSE.png"));
		//

	}

	for (int j = 0; j < 3; j++) {//horizontal
		//
		for (int i = 0; i < 3; i++) {
			addRoad(new Road(glm::vec3(5.0f + 5.0f*i, 0.0f, 0.0f + 20.0f*j), 5, 5, "roadEW.png"));
			addRoad(new Road(glm::vec3(-1*5.0f - 5.0f*i, 0.0f, 0.0f + 20.0f*j), 5, 5, "roadEW.png"));

		}
		for (int i = 0; i < 3; i++) {
			addRoad(new Road(glm::vec3(5.0f + 5.0f*i, 0.0f, 0.0f - 20.0f*j), 5, 5, "roadEW.png"));
			addRoad(new Road(glm::vec3(-1*5.0f - 5.0f*i, 0.0f, 0.0f - 20.0f*j), 5, 5, "roadEW.png"));
		}
		//
		for (int i = 0; i < 3; i++) {
			addRoad(new Road(glm::vec3(25.0f + 5.0f*i, 0.0f, 0.0f + 20.0f*j), 5, 5, "roadEW.png"));
			addRoad(new Road(glm::vec3(-1 * 25.0f - 5.0f*i, 0.0f, 0.0f + 20.0f*j), 5, 5, "roadEW.png"));
		}
		for (int i = 0; i < 3; i++) {
			addRoad(new Road(glm::vec3(25.0f + 5.0f*i, 0.0f, 0.0f - 20.0f*j), 5, 5, "roadEW.png"));
			addRoad(new Road(glm::vec3(-1 * 25.0f - 5.0f*i, 0.0f, 0.0f - 20.0f*j), 5, 5, "roadEW.png"));
		}
	}
	addRoad(new Road(glm::vec3(20.0f + 5.0f*4, 0.0f, 0.0f), 5, 5, "roadTW.png"));
	addRoad(new Road(glm::vec3(20.0f + 5.0f * 4, 0.0f, 20.0f), 5, 5, "roadTW.png"));
	addRoad(new Road(glm::vec3(20.0f + 5.0f * 4, 0.0f, -1*20.0f), 5, 5, "roadTW.png"));

	addRoad(new Road(glm::vec3(-1*20.0f - 5.0f * 4, 0.0f, 0.0f), 5, 5, "roadTE.png"));
	addRoad(new Road(glm::vec3(-1*20.0f - 5.0f * 4, 0.0f, 20.0f), 5, 5, "roadTE.png"));
	addRoad(new Road(glm::vec3(-1*20.0f - 5.0f * 4, 0.0f, -1 * 20.0f), 5, 5, "roadTE.png"));
	//addRoad(new Road(glm::vec3(-1 * 25.0f - 5.0f*4, 0.0f, 0.0f + 20.0f*j), 5, 5, "roadEW.png"));

	//for(int j)
}


void City::draw(GLuint shaderProgram) {
	for (auto i : Roads) {
		i->draw(shaderProgram);
	}
}

void City::update() {


}