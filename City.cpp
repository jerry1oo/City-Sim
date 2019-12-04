#include "City.h"

City::City() {

}

float City::RandomFloat(float a, float b) {
	float ran = ((float)rand()) / (float)RAND_MAX;
	float d = b - a;
	float r = ran * d;
	return a + r;
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
	float buildingsize = 4.5;
	float offsetz = 0.5f;
	float offsetx = 0.5f;
	int heightr;
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
		GenB1(glm::vec3(-1 * 10.0f, 0.0f, 5.0f - offsetz));
		//addBuilding(new Building(glm::vec3(-1 * 10.0f, 0.0f, 5.0f - offsetz), buildingsize, buildingsize, heightr));
		addRoad(new Road(glm::vec3(-1 * 10.0f, 0.0f, 10.0f), 5, 5, "roadPLAZA.png"));
		GenB1(glm::vec3(-1 * 10.0f, 0.0f, 10.0f));
		//addBuilding(new Building(glm::vec3(-1 * 10.0f, 0.0f, 10.0f), buildingsize, buildingsize, heightr));
		addRoad(new Road(glm::vec3(-1 * 10.0f, 0.0f, 15.0f), 5, 5, "roadPLAZA.png"));
		GenB1(glm::vec3(-1 * 10.0f, 0.0f, 15.0f + offsetz));
		//addBuilding(new Building(glm::vec3(-1 * 10.0f, 0.0f, 15.0f + offsetz), buildingsize, buildingsize, heightr));
		addRoad(new Road(glm::vec3(-1 * 5.0f, 0.0f, 5.0f), 5, 5, "roadPLAZA.png"));
		GenB1(glm::vec3(-1 * 5.0f + offsetx, 0.0f, 5.0f - offsetz));
		//addBuilding(new Building(glm::vec3(-1 * 5.0f + offsetx, 0.0f, 5.0f - offsetz), buildingsize, buildingsize, heightr));
		addRoad(new Road(glm::vec3(-1 * 5.0f, 0.0f, 10.0f), 5, 5, "roadPLAZA.png"));
		GenB1(glm::vec3(-1 * 5.0f + offsetx, 0.0f, 10.0f));
		//addBuilding(new Building(glm::vec3(-1 * 5.0f + offsetx, 0.0f, 10.0f), buildingsize, buildingsize, heightr));
		addRoad(new Road(glm::vec3(-1 * 5.0f, 0.0f, 15.0f), 5, 5, "roadPLAZA.png"));
		GenB1(glm::vec3(-1 * 5.0f + offsetx, 0.0f, 15.0f + offsetz));
		//addBuilding(new Building(glm::vec3(-1 * 5.0f + offsetx, 0.0f, 15.0f + offsetz), buildingsize, buildingsize, heightr));
		addRoad(new Road(glm::vec3(-1 * 15.0f, 0.0f, 5.0f), 5, 5, "roadPLAZA.png"));
		GenB1(glm::vec3(-1 * 15.0f - offsetx, 0.0f, 5.0f - offsetz));
		//addBuilding(new Building(glm::vec3(-1 * 15.0f - offsetx, 0.0f, 5.0f - offsetz), buildingsize, buildingsize, heightr));
		addRoad(new Road(glm::vec3(-1 * 15.0f, 0.0f, 10.0f), 5, 5, "roadPLAZA.png"));
		GenB1(glm::vec3(-1 * 15.0f - offsetx, 0.0f, 10.0f));
		//addBuilding(new Building(glm::vec3(-1 * 15.0f - offsetx, 0.0f, 10.0f), buildingsize, buildingsize, heightr));
		addRoad(new Road(glm::vec3(-1 * 15.0f, 0.0f, 15.0f), 5, 5, "roadPLAZA.png"));
		GenB1(glm::vec3(-1 * 15.0f - offsetx, 0.0f, 15.0f + offsetz));
		//addBuilding(new Building(glm::vec3(-1 * 15.0f - offsetx, 0.0f, 15.0f + offsetz), buildingsize, buildingsize, heightr));
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

void City::GenB1(glm::vec3 pos1){
	
	float heightr = RandomFloat(5,10);
	float buildingsize = 4.5;
	addBuilding(new Building(pos1, buildingsize, buildingsize, 0.01f));
	glm::vec3 pos2 = pos1 - glm::vec3(RandomFloat(-0.5, 0.5),0.0f, RandomFloat(-0.5, 0.5));
	addBuilding(new Building(pos2, buildingsize-2, buildingsize-2, heightr));	
	glm::vec3 pos3 = pos1 - glm::vec3(RandomFloat(-2, 2), 0.0f, 0.0f);
	addBuilding(new Building(pos3, buildingsize - 3, buildingsize - 1, heightr- RandomFloat(2, 5)));
	glm::vec3 pos4 = pos1 - glm::vec3(0.0f, 0.0f, RandomFloat(-2, 2));
	addBuilding(new Building(pos4, buildingsize - 1, buildingsize - 3, heightr - 2));

}

void City::draw(GLuint shaderProgram) {
	for (auto i : Roads) {
		i->draw(shaderProgram);
	}
	for (auto i : Buildings) {
		i->draw(shaderProgram);
	}
}

void City::update() {


}