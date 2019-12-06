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
	Buildings.clear();
	Roads.clear();
	float buildingsize = 4.5;
	float offsetz = 0.5f;
	float offsetx = 0.5f;
	int heightr;

	SF = rand() % 12 + 1;
	//int SF = 1;
	{
		//tile 1
		if (SF != 1) {
			addRoad(new Road(glm::vec3(25.0f, 0.0f, 0.0f + 30.0f), 5, 5, "roadPLAZA.png"));
			addRoad(new Road(glm::vec3(30.0f, 0.0f, 0.0f + 30.0f), 5, 5, "roadPLAZA.png"));
			addRoad(new Road(glm::vec3(35.0f, 0.0f, 0.0f + 30.0f), 5, 5, "roadPLAZA.png"));

			addRoad(new Road(glm::vec3(25.0f, 0.0f, 0.0f + 25.0f), 5, 5, "roadPLAZA.png"));
			addRoad(new Road(glm::vec3(30.0f, 0.0f, 0.0f + 25.0f), 5, 5, "roadPLAZA.png"));
			addRoad(new Road(glm::vec3(35.0f, 0.0f, 0.0f + 25.0f), 5, 5, "roadPLAZA.png"));

			addRoad(new Road(glm::vec3(25.0f, 0.0f, 0.0f + 35.0f), 5, 5, "roadPLAZA.png"));
			addRoad(new Road(glm::vec3(30.0f, 0.0f, 0.0f + 35.0f), 5, 5, "roadPLAZA.png"));
			addRoad(new Road(glm::vec3(35.0f, 0.0f, 0.0f + 35.0f), 5, 5, "roadPLAZA.png"));

			int tex = rand() % 4;
			GLchar* texside;
			GLchar* textop;
			if (tex == 0) {
				texside = "NightBuilding8.jpg";
				textop = "BlackRoof.jpg";
			}
			else if (tex == 1) {
				texside = "NightBuilding8.jpg";
				textop = "BlackRoof.jpg";
			}
			else if (tex == 2) {
				texside = "NightBuilding8.jpg";
				textop = "BlackRoof.jpg";
			}
			else if (tex == 3) {
				texside = "NightBuilding8.jpg";
				textop = "BlackRoof.jpg";
			}

			BuildingGen(glm::vec3(25.0f - offsetx, 0.0f, 0.0f + 30.0f), texside, textop);
			BuildingGen(glm::vec3(30.0f, 0.0f, 0.0f + 30.0f), texside, textop);
			BuildingGen(glm::vec3(35.0f + offsetx, 0.0f, 0.0f + 30.0f), texside, textop);

			BuildingGen(glm::vec3(25.0f - offsetx, 0.0f, 0.0f + 25.0f - offsetz), texside, textop);
			BuildingGen(glm::vec3(30.0f, 0.0f, 0.0f + 25.0f - offsetz), texside, textop);
			BuildingGen(glm::vec3(35.0f + offsetx, 0.0f, 0.0f + 25.0f - offsetz), texside, textop);

			BuildingGen(glm::vec3(25.0f - offsetx, 0.0f, 0.0f + 35.0f + offsetz), texside, textop);
			BuildingGen(glm::vec3(30.0f, 0.0f, 0.0f + 35.0f + offsetz), texside, textop);
			BuildingGen(glm::vec3(35.0f + offsetx, 0.0f, 0.0f + 35.0f + offsetz), texside, textop);
		}
	}
	{
		//tile 2
		if (SF != 1 && SF != 2) {
			addRoad(new Road(glm::vec3(5.0f, 0.0f, 0.0f + 30.0f), 5, 5, "roadPLAZA.png"));
			addRoad(new Road(glm::vec3(10.0f, 0.0f, 0.0f + 30.0f), 5, 5, "roadPLAZA.png"));
			addRoad(new Road(glm::vec3(15.0f, 0.0f, 0.0f + 30.0f), 5, 5, "roadPLAZA.png"));

			addRoad(new Road(glm::vec3(5.0f, 0.0f, 0.0f + 25.0f), 5, 5, "roadPLAZA.png"));
			addRoad(new Road(glm::vec3(10.0f, 0.0f, 0.0f + 25.0f), 5, 5, "roadPLAZA.png"));
			addRoad(new Road(glm::vec3(15.0f, 0.0f, 0.0f + 25.0f), 5, 5, "roadPLAZA.png"));

			addRoad(new Road(glm::vec3(5.0f, 0.0f, 0.0f + 35.0f), 5, 5, "roadPLAZA.png"));
			addRoad(new Road(glm::vec3(10.0f, 0.0f, 0.0f + 35.0f), 5, 5, "roadPLAZA.png"));
			addRoad(new Road(glm::vec3(15.0f, 0.0f, 0.0f + 35.0f), 5, 5, "roadPLAZA.png"));

			int tex = rand() % 4;
			GLchar* texside;
			GLchar* textop;
			if (tex == 0) {
				texside = "NightBuilding8.jpg";
				textop = "BlackRoof.jpg";
			}
			else if (tex == 1) {
				texside = "NightBuilding8.jpg";
				textop = "BlackRoof.jpg";
			}
			else if (tex == 2) {
				texside = "NightBuilding8.jpg";
				textop = "BlackRoof.jpg";
			}
			else if (tex == 3) {
				texside = "NightBuilding8.jpg";
				textop = "BlackRoof.jpg";
			}

			BuildingGen(glm::vec3(5.0f - offsetx, 0.0f, 0.0f + 30.0f), texside, textop);
			BuildingGen(glm::vec3(10.0f, 0.0f, 0.0f + 30.0f), texside, textop);
			BuildingGen(glm::vec3(15.0f + offsetx, 0.0f, 0.0f + 30.0f), texside, textop);

			BuildingGen(glm::vec3(5.0f - offsetx, 0.0f, 0.0f + 25.0f - offsetz), texside, textop);
			BuildingGen(glm::vec3(10.0f, 0.0f, 0.0f + 25.0f - offsetz), texside, textop);
			BuildingGen(glm::vec3(15.0f + offsetx, 0.0f, 0.0f + 25.0f - offsetz), texside, textop);

			BuildingGen(glm::vec3(5.0f - offsetx, 0.0f, 0.0f + 35.0f + offsetz), texside, textop);
			BuildingGen(glm::vec3(10.0f, 0.0f, 0.0f + 35.0f + offsetz), texside, textop);
			BuildingGen(glm::vec3(15.0f + offsetx, 0.0f, 0.0f + 35.0f + offsetz), texside, textop);
		}
	}	
	{
		// tile 3
		if (SF != 2 && SF != 3) {
			addRoad(new Road(glm::vec3(-1 * 5.0f, 0.0f, 30.0f), 5, 5, "roadPLAZA.png"));
			addRoad(new Road(glm::vec3(-1 * 10.0f, 0.0f, 30.0f), 5, 5, "roadPLAZA.png"));
			addRoad(new Road(glm::vec3(-1 * 15.0f, 0.0f, 30.0f), 5, 5, "roadPLAZA.png"));

			addRoad(new Road(glm::vec3(-1 * 5.0f, 0.0f, 25.0f), 5, 5, "roadPLAZA.png"));
			addRoad(new Road(glm::vec3(-1 * 10.0f, 0.0f, 25.0f), 5, 5, "roadPLAZA.png"));
			addRoad(new Road(glm::vec3(-1 * 15.0f, 0.0f, 25.0f), 5, 5, "roadPLAZA.png"));

			addRoad(new Road(glm::vec3(-1 * 5.0f, 0.0f, 35.0f), 5, 5, "roadPLAZA.png"));
			addRoad(new Road(glm::vec3(-1 * 10.0f, 0.0f, 35.0f), 5, 5, "roadPLAZA.png"));
			addRoad(new Road(glm::vec3(-1 * 15.0f, 0.0f, 35.0f), 5, 5, "roadPLAZA.png"));

			int tex = rand() % 4;
			GLchar* texside;
			GLchar* textop;
			if (tex == 0) {
				texside = "NightBuilding8.jpg";
				textop = "BlackRoof.jpg";
			}
			else if (tex == 1) {
				texside = "NightBuilding8.jpg";
				textop = "BlackRoof.jpg";
			}
			else if (tex == 2) {
				texside = "NightBuilding8.jpg";
				textop = "BlackRoof.jpg";
			}
			else if (tex == 3) {
				texside = "NightBuilding8.jpg";
				textop = "BlackRoof.jpg";
			}

			BuildingGen(glm::vec3(-1 * 5.0f + offsetx, 0.0f, 30.0f), texside, textop);
			BuildingGen(glm::vec3(-1 * 10.0f, 0.0f, 30.0f), texside, textop);
			BuildingGen(glm::vec3(-1 * 15.0f - offsetx, 0.0f, 30.0f), texside, textop);

			BuildingGen(glm::vec3(-1 * 5.0f + offsetx, 0.0f, 25.0f - offsetz), texside, textop);
			BuildingGen(glm::vec3(-1 * 10.0f, 0.0f, 25.0f - offsetz), texside, textop);
			BuildingGen(glm::vec3(-1 * 15.0f - offsetx, 0.0f, 25.0f - offsetz), texside, textop);

			BuildingGen(glm::vec3(-1 * 5.0f + offsetx, 0.0f, 35.0f + offsetz), texside, textop);
			BuildingGen(glm::vec3(-1 * 10.0f, 0.0f, 35.0f + offsetz), texside, textop);
			BuildingGen(glm::vec3(-1 * 15.0f - offsetx, 0.0f, 35.0f + offsetz), texside, textop);
		}
	}
	{
		//tile 4
		if (SF != 3) {
			addRoad(new Road(glm::vec3(-1 * 25.0f, 0.0f, 30.0f), 5, 5, "roadPLAZA.png"));
			addRoad(new Road(glm::vec3(-1 * 30.0f, 0.0f, 30.0f), 5, 5, "roadPLAZA.png"));
			addRoad(new Road(glm::vec3(-1 * 35.0f, 0.0f, 30.0f), 5, 5, "roadPLAZA.png"));

			addRoad(new Road(glm::vec3(-1 * 25.0f, 0.0f, 25.0f), 5, 5, "roadPLAZA.png"));
			addRoad(new Road(glm::vec3(-1 * 30.0f, 0.0f, 25.0f), 5, 5, "roadPLAZA.png"));
			addRoad(new Road(glm::vec3(-1 * 35.0f, 0.0f, 25.0f), 5, 5, "roadPLAZA.png"));

			addRoad(new Road(glm::vec3(-1 * 25.0f, 0.0f, 35.0f), 5, 5, "roadPLAZA.png"));
			addRoad(new Road(glm::vec3(-1 * 30.0f, 0.0f, 35.0f), 5, 5, "roadPLAZA.png"));
			addRoad(new Road(glm::vec3(-1 * 35.0f, 0.0f, 35.0f), 5, 5, "roadPLAZA.png"));

			int tex = rand() % 4;
			GLchar* texside;
			GLchar* textop;
			if (tex == 0) {
				texside = "NightBuilding8.jpg";
				textop = "BlackRoof.jpg";
			}
			else if (tex == 1) {
				texside = "NightBuilding8.jpg";
				textop = "BlackRoof.jpg";
			}
			else if (tex == 2) {
				texside = "NightBuilding8.jpg";
				textop = "BlackRoof.jpg";
			}
			else if (tex == 3) {
				texside = "NightBuilding8.jpg";
				textop = "BlackRoof.jpg";
			}

			BuildingGen(glm::vec3(-1 * 25.0f + offsetx, 0.0f, 30.0f), texside, textop);
			BuildingGen(glm::vec3(-1 * 30.0f, 0.0f, 30.0f), texside, textop);
			BuildingGen(glm::vec3(-1 * 35.0f - offsetx, 0.0f, 30.0f), texside, textop);

			BuildingGen(glm::vec3(-1 * 25.0f + offsetx, 0.0f, 25.0f - offsetz), texside, textop);
			BuildingGen(glm::vec3(-1 * 30.0f, 0.0f, 25.0f - offsetz), texside, textop);
			BuildingGen(glm::vec3(-1 * 35.0f - offsetx, 0.0f, 25.0f - offsetz), texside, textop);

			BuildingGen(glm::vec3(-1 * 25.0f + offsetx, 0.0f, 35.0f + offsetz), texside, textop);
			BuildingGen(glm::vec3(-1 * 30.0f, 0.0f, 35.0f + offsetz), texside, textop);
			BuildingGen(glm::vec3(-1 * 35.0f - offsetx, 0.0f, 35.0f + offsetz), texside, textop);
		}
	}
	{
		//tile5
		if (SF != 4) {
			addRoad(new Road(glm::vec3(30.0f, 0.0f, 5.0f), 5, 5, "roadPLAZA.png"));
			addRoad(new Road(glm::vec3(30.0f, 0.0f, 10.0f), 5, 5, "roadPLAZA.png"));
			addRoad(new Road(glm::vec3(30.0f, 0.0f, 15.0f), 5, 5, "roadPLAZA.png"));

			addRoad(new Road(glm::vec3(25.0f, 0.0f, 5.0f), 5, 5, "roadPLAZA.png"));
			addRoad(new Road(glm::vec3(25.0f, 0.0f, 10.0f), 5, 5, "roadPLAZA.png"));
			addRoad(new Road(glm::vec3(25.0f, 0.0f, 15.0f), 5, 5, "roadPLAZA.png"));

			addRoad(new Road(glm::vec3(35.0f, 0.0f, 5.0f), 5, 5, "roadPLAZA.png"));
			addRoad(new Road(glm::vec3(35.0f, 0.0f, 10.0f), 5, 5, "roadPLAZA.png"));
			addRoad(new Road(glm::vec3(35.0f, 0.0f, 15.0f), 5, 5, "roadPLAZA.png"));

			int tex = rand() % 4;
			GLchar* texside;
			GLchar* textop;
			if (tex == 0) {
				texside = "NightBuilding8.jpg";
				textop = "BlackRoof.jpg";
			}
			else if (tex == 1) {
				texside = "NightBuilding8.jpg";
				textop = "BlackRoof.jpg";
			}
			else if (tex == 2) {
				texside = "NightBuilding8.jpg";
				textop = "BlackRoof.jpg";
			}
			else if (tex == 3) {
				texside = "NightBuilding8.jpg";
				textop = "BlackRoof.jpg";
			}

			BuildingGen(glm::vec3(30.0f, 0.0f, 5.0f - offsetz), texside, textop);
			BuildingGen(glm::vec3(30.0f, 0.0f, 10.0f), texside, textop);
			BuildingGen(glm::vec3(30.0f, 0.0f, 15.0f + offsetz), texside, textop);

			BuildingGen(glm::vec3(25.0f - offsetx, 0.0f, 5.0f - offsetz), texside, textop);
			BuildingGen(glm::vec3(25.0f - offsetx, 0.0f, 10.0f), texside, textop);
			BuildingGen(glm::vec3(25.0f - offsetx, 0.0f, 15.0f + offsetz), texside, textop);

			BuildingGen(glm::vec3(35.0f + offsetx, 0.0f, 5.0f - offsetz), texside, textop);
			BuildingGen(glm::vec3(35.0f + offsetx, 0.0f, 10.0f), texside, textop);
			BuildingGen(glm::vec3(35.0f + offsetx, 0.0f, 15.0f + offsetz), texside, textop);
		}
	}
	{
		//tile 6
		if (SF != 4 && SF != 5) {
			addRoad(new Road(glm::vec3(10.0f, 0.0f, 5.0), 5, 5, "roadPLAZA.png"));
			addRoad(new Road(glm::vec3(10.0f, 0.0f, 10.0), 5, 5, "roadPLAZA.png"));
			addRoad(new Road(glm::vec3(10.0f, 0.0f, 15.0), 5, 5, "roadPLAZA.png"));

			addRoad(new Road(glm::vec3(5.0f, 0.0f, 5.0), 5, 5, "roadPLAZA.png"));
			addRoad(new Road(glm::vec3(5.0f, 0.0f, 10.0), 5, 5, "roadPLAZA.png"));
			addRoad(new Road(glm::vec3(5.0f, 0.0f, 15.0), 5, 5, "roadPLAZA.png"));

			addRoad(new Road(glm::vec3(15.0f, 0.0f, 5.0), 5, 5, "roadPLAZA.png"));
			addRoad(new Road(glm::vec3(15.0f, 0.0f, 10.0), 5, 5, "roadPLAZA.png"));
			addRoad(new Road(glm::vec3(15.0f, 0.0f, 15.0), 5, 5, "roadPLAZA.png"));

			int tex = rand() % 4;
			GLchar* texside;
			GLchar* textop;
			if (tex == 0) {
				texside = "NightBuilding8.jpg";
				textop = "BlackRoof.jpg";
			}
			else if (tex == 1) {
				texside = "NightBuilding8.jpg";
				textop = "BlackRoof.jpg";
			}
			else if (tex == 2) {
				texside = "NightBuilding8.jpg";
				textop = "BlackRoof.jpg";
			}
			else if (tex == 3) {
				texside = "NightBuilding8.jpg";
				textop = "BlackRoof.jpg";
			}

			BuildingGen(glm::vec3(10.0f, 0.0f, 5.0 - offsetz), texside, textop);
			BuildingGen(glm::vec3(10.0f, 0.0f, 10.0), texside, textop);
			BuildingGen(glm::vec3(10.0f, 0.0f, 15.0 + offsetz), texside, textop);

			BuildingGen(glm::vec3(5.0f - offsetx, 0.0f, 5.0 - offsetz), texside, textop);
			BuildingGen(glm::vec3(5.0f - offsetx, 0.0f, 10.0), texside, textop);
			BuildingGen(glm::vec3(5.0f - offsetx, 0.0f, 15.0 + offsetz), texside, textop);

			BuildingGen(glm::vec3(15.0f + offsetx, 0.0f, 5.0 - offsetz), texside, textop);
			BuildingGen(glm::vec3(15.0f + offsetx, 0.0f, 10.0), texside, textop);
			BuildingGen(glm::vec3(15.0f + offsetx, 0.0f, 15.0 + offsetz), texside, textop);
		}
	}
	{
		//tile 7
		if (SF != 5 && SF != 6) {
			addRoad(new Road(glm::vec3(-1 * 10.0f, 0.0f, 5.0f), 5, 5, "roadPLAZA.png"));			
			addRoad(new Road(glm::vec3(-1 * 10.0f, 0.0f, 10.0f), 5, 5, "roadPLAZA.png"));			
			addRoad(new Road(glm::vec3(-1 * 10.0f, 0.0f, 15.0f), 5, 5, "roadPLAZA.png"));
			
			addRoad(new Road(glm::vec3(-1 * 5.0f, 0.0f, 5.0f), 5, 5, "roadPLAZA.png"));			
			addRoad(new Road(glm::vec3(-1 * 5.0f, 0.0f, 10.0f), 5, 5, "roadPLAZA.png"));			
			addRoad(new Road(glm::vec3(-1 * 5.0f, 0.0f, 15.0f), 5, 5, "roadPLAZA.png"));
			
			addRoad(new Road(glm::vec3(-1 * 15.0f, 0.0f, 5.0f), 5, 5, "roadPLAZA.png"));			
			addRoad(new Road(glm::vec3(-1 * 15.0f, 0.0f, 10.0f), 5, 5, "roadPLAZA.png"));			
			addRoad(new Road(glm::vec3(-1 * 15.0f, 0.0f, 15.0f), 5, 5, "roadPLAZA.png"));

			int tex = rand() % 4;
			GLchar* texside;
			GLchar* textop;
			if (tex == 0) {
				texside = "NightBuilding8.jpg";
				textop = "BlackRoof.jpg";
			}
			else if (tex == 1) {
				texside = "NightBuilding8.jpg";
				textop = "BlackRoof.jpg";
			}
			else if (tex == 2) {
				texside = "NightBuilding8.jpg";
				textop = "BlackRoof.jpg";
			}
			else if (tex == 3) {
				texside = "NightBuilding8.jpg";
				textop = "BlackRoof.jpg";
			}

			BuildingGen(glm::vec3(-1 * 10.0f, 0.0f, 5.0f - offsetz), texside, textop);
			BuildingGen(glm::vec3(-1 * 10.0f, 0.0f, 10.0f), texside, textop);
			BuildingGen(glm::vec3(-1 * 10.0f, 0.0f, 15.0f + offsetz), texside, textop);

			BuildingGen(glm::vec3(-1 * 5.0f + offsetx, 0.0f, 5.0f - offsetz), texside, textop);
			BuildingGen(glm::vec3(-1 * 5.0f + offsetx, 0.0f, 10.0f), texside, textop);
			BuildingGen(glm::vec3(-1 * 5.0f + offsetx, 0.0f, 15.0f + offsetz), texside, textop);

			BuildingGen(glm::vec3(-1 * 15.0f - offsetx, 0.0f, 5.0f - offsetz), texside, textop);
			BuildingGen(glm::vec3(-1 * 15.0f - offsetx, 0.0f, 10.0f), texside, textop);
			BuildingGen(glm::vec3(-1 * 15.0f - offsetx, 0.0f, 15.0f + offsetz), texside, textop);
		}
	}
	{
		//tile 8
		if (SF != 6) {
			addRoad(new Road(glm::vec3(-1 * 30.0f, 0.0f, 5.0f), 5, 5, "roadPLAZA.png"));
			addRoad(new Road(glm::vec3(-1 * 30.0f, 0.0f, 10.0f), 5, 5, "roadPLAZA.png"));
			addRoad(new Road(glm::vec3(-1 * 30.0f, 0.0f, 15.0f), 5, 5, "roadPLAZA.png"));

			addRoad(new Road(glm::vec3(-1 * 25.0f, 0.0f, 5.0f), 5, 5, "roadPLAZA.png"));
			addRoad(new Road(glm::vec3(-1 * 25.0f, 0.0f, 10.0f), 5, 5, "roadPLAZA.png"));
			addRoad(new Road(glm::vec3(-1 * 25.0f, 0.0f, 15.0f), 5, 5, "roadPLAZA.png"));

			addRoad(new Road(glm::vec3(-1 * 35.0f, 0.0f, 5.0f), 5, 5, "roadPLAZA.png"));
			addRoad(new Road(glm::vec3(-1 * 35.0f, 0.0f, 10.0f), 5, 5, "roadPLAZA.png"));
			addRoad(new Road(glm::vec3(-1 * 35.0f, 0.0f, 15.0f), 5, 5, "roadPLAZA.png"));

			int tex = rand() % 4;
			GLchar* texside;
			GLchar* textop;
			if (tex == 0) {
				texside = "NightBuilding8.jpg";
				textop = "BlackRoof.jpg";
			}
			else if (tex == 1) {
				texside = "NightBuilding8.jpg";
				textop = "BlackRoof.jpg";
			}
			else if (tex == 2) {
				texside = "NightBuilding8.jpg";
				textop = "BlackRoof.jpg";
			}
			else if (tex == 3) {
				texside = "NightBuilding8.jpg";
				textop = "BlackRoof.jpg";
			}

			BuildingGen(glm::vec3(-1 * 30.0f, 0.0f, 5.0f - offsetz), texside, textop);
			BuildingGen(glm::vec3(-1 * 30.0f, 0.0f, 10.0f), texside, textop);
			BuildingGen(glm::vec3(-1 * 30.0f, 0.0f, 15.0f + offsetz), texside, textop);

			BuildingGen(glm::vec3(-1 * 25.0f + offsetx, 0.0f, 5.0f - offsetz), texside, textop);
			BuildingGen(glm::vec3(-1 * 25.0f + offsetx, 0.0f, 10.0f), texside, textop);
			BuildingGen(glm::vec3(-1 * 25.0f + offsetx, 0.0f, 15.0f + offsetz), texside, textop);

			BuildingGen(glm::vec3(-1 * 35.0f - offsetx, 0.0f, 5.0f - offsetz), texside, textop);
			BuildingGen(glm::vec3(-1 * 35.0f - offsetx, 0.0f, 10.0f), texside, textop);
			BuildingGen(glm::vec3(-1 * 35.0f - offsetx, 0.0f, 15.0f + offsetz), texside, textop);
		}
	}
	{		
		//tile 9
		if (SF != 7) {
			addRoad(new Road(glm::vec3(30.0f, 0.0f, -1 * 5.0f), 5, 5, "roadPLAZA.png"));
			addRoad(new Road(glm::vec3(30.0f, 0.0f, -1 * 10.0f), 5, 5, "roadPLAZA.png"));
			addRoad(new Road(glm::vec3(30.0f, 0.0f, -1 * 15.0f), 5, 5, "roadPLAZA.png"));

			addRoad(new Road(glm::vec3(25.0f, 0.0f, -1 * 5.0f), 5, 5, "roadPLAZA.png"));
			addRoad(new Road(glm::vec3(25.0f, 0.0f, -1 * 10.0f), 5, 5, "roadPLAZA.png"));
			addRoad(new Road(glm::vec3(25.0f, 0.0f, -1 * 15.0f), 5, 5, "roadPLAZA.png"));

			addRoad(new Road(glm::vec3(35.0f, 0.0f, -1 * 5.0f), 5, 5, "roadPLAZA.png"));
			addRoad(new Road(glm::vec3(35.0f, 0.0f, -1 * 10.0f), 5, 5, "roadPLAZA.png"));
			addRoad(new Road(glm::vec3(35.0f, 0.0f, -1 * 15.0f), 5, 5, "roadPLAZA.png"));

			int tex = rand() % 4;
			GLchar* texside;
			GLchar* textop;
			if (tex == 0) {
				texside = "NightBuilding8.jpg";
				textop = "BlackRoof.jpg";
			}
			else if (tex == 1) {
				texside = "NightBuilding8.jpg";
				textop = "BlackRoof.jpg";
			}
			else if (tex == 2) {
				texside = "NightBuilding8.jpg";
				textop = "BlackRoof.jpg";
			}
			else if (tex == 3) {
				texside = "NightBuilding8.jpg";
				textop = "BlackRoof.jpg";
			}

			BuildingGen(glm::vec3(30.0f, 0.0f, -1 * 5.0f + offsetz), texside, textop);
			BuildingGen(glm::vec3(30.0f, 0.0f, -1 * 10.0f), texside, textop);
			BuildingGen(glm::vec3(30.0f, 0.0f, -1 * 15.0f - offsetz), texside, textop);

			BuildingGen(glm::vec3(25.0f - offsetx, 0.0f, -1 * 5.0f + offsetz), texside, textop);
			BuildingGen(glm::vec3(25.0f - offsetx, 0.0f, -1 * 10.0f), texside, textop);
			BuildingGen(glm::vec3(25.0f - offsetx, 0.0f, -1 * 15.0f - offsetz), texside, textop);

			BuildingGen(glm::vec3(35.0f + offsetx, 0.0f, -1 * 5.0f + offsetz), texside, textop);
			BuildingGen(glm::vec3(35.0f + offsetx, 0.0f, -1 * 10.0f), texside, textop);
			BuildingGen(glm::vec3(35.0f + offsetx, 0.0f, -1 * 15.0f - offsetz), texside, textop);
		}
	}
	{
		//tile 10
		if (SF != 7 && SF != 8) {
			addRoad(new Road(glm::vec3(10.0f, 0.0f, -1 * 5.0), 5, 5, "roadPLAZA.png"));
			addRoad(new Road(glm::vec3(10.0f, 0.0f, -1 * 10.0), 5, 5, "roadPLAZA.png"));
			addRoad(new Road(glm::vec3(10.0f, 0.0f, -1 * 15.0), 5, 5, "roadPLAZA.png"));

			addRoad(new Road(glm::vec3(5.0f, 0.0f, -1 * 5.0), 5, 5, "roadPLAZA.png"));
			addRoad(new Road(glm::vec3(5.0f, 0.0f, -1 * 10.0), 5, 5, "roadPLAZA.png"));
			addRoad(new Road(glm::vec3(5.0f, 0.0f, -1 * 15.0), 5, 5, "roadPLAZA.png"));

			addRoad(new Road(glm::vec3(15.0f, 0.0f, -1 * 5.0), 5, 5, "roadPLAZA.png"));
			addRoad(new Road(glm::vec3(15.0f, 0.0f, -1 * 10.0), 5, 5, "roadPLAZA.png"));
			addRoad(new Road(glm::vec3(15.0f, 0.0f, -1 * 15.0), 5, 5, "roadPLAZA.png"));

			int tex = rand() % 4;
			GLchar* texside;
			GLchar* textop;
			if (tex == 0) {
				texside = "NightBuilding8.jpg";
				textop = "BlackRoof.jpg";
			}
			else if (tex == 1) {
				texside = "NightBuilding8.jpg";
				textop = "BlackRoof.jpg";
			}
			else if (tex == 2) {
				texside = "NightBuilding8.jpg";
				textop = "BlackRoof.jpg";
			}
			else if (tex == 3) {
				texside = "NightBuilding8.jpg";
				textop = "BlackRoof.jpg";
			}

			BuildingGen(glm::vec3(10.0f, 0.0f, -1 * 5.0 + offsetz), texside, textop);
			BuildingGen(glm::vec3(10.0f, 0.0f, -1 * 10.0), texside, textop);
			BuildingGen(glm::vec3(10.0f, 0.0f, -1 * 15.0 - offsetz), texside, textop);

			BuildingGen(glm::vec3(5.0f - offsetx, 0.0f, -1 * 5.0 + offsetz), texside, textop);
			BuildingGen(glm::vec3(5.0f - offsetx, 0.0f, -1 * 10.0), texside, textop);
			BuildingGen(glm::vec3(5.0f - offsetx, 0.0f, -1 * 15.0 - offsetz), texside, textop);

			BuildingGen(glm::vec3(15.0f + offsetx, 0.0f, -1 * 5.0 + offsetz), texside, textop);
			BuildingGen(glm::vec3(15.0f + offsetx, 0.0f, -1 * 10.0), texside, textop);
			BuildingGen(glm::vec3(15.0f + offsetx, 0.0f, -1 * 15.0 - offsetz), texside, textop);
		}
	}
	{
		//tile 11
		if (SF != 8 && SF != 9) {
			addRoad(new Road(glm::vec3(-1 * 10.0f, 0.0f, -1 * 5.0f), 5, 5, "roadPLAZA.png"));
			addRoad(new Road(glm::vec3(-1 * 10.0f, 0.0f, -1 * 10.0f), 5, 5, "roadPLAZA.png"));
			addRoad(new Road(glm::vec3(-1 * 10.0f, 0.0f, -1 * 15.0f), 5, 5, "roadPLAZA.png"));

			addRoad(new Road(glm::vec3(-1 * 5.0f, 0.0f, -1 * 5.0f), 5, 5, "roadPLAZA.png"));
			addRoad(new Road(glm::vec3(-1 * 5.0f, 0.0f, -1 * 10.0f), 5, 5, "roadPLAZA.png"));
			addRoad(new Road(glm::vec3(-1 * 5.0f, 0.0f, -1 * 15.0f), 5, 5, "roadPLAZA.png"));

			addRoad(new Road(glm::vec3(-1 * 15.0f, 0.0f, -1 * 5.0f), 5, 5, "roadPLAZA.png"));
			addRoad(new Road(glm::vec3(-1 * 15.0f, 0.0f, -1 * 10.0f), 5, 5, "roadPLAZA.png"));
			addRoad(new Road(glm::vec3(-1 * 15.0f, 0.0f, -1 * 15.0f), 5, 5, "roadPLAZA.png"));

			int tex = rand() % 4;
			GLchar* texside;
			GLchar* textop;
			if (tex == 0) {
				texside = "NightBuilding8.jpg";
				textop = "BlackRoof.jpg";
			}
			else if (tex == 1) {
				texside = "NightBuilding8.jpg";
				textop = "BlackRoof.jpg";
			}
			else if (tex == 2) {
				texside = "NightBuilding8.jpg";
				textop = "BlackRoof.jpg";
			}
			else if (tex == 3) {
				texside = "NightBuilding8.jpg";
				textop = "BlackRoof.jpg";
			}

			BuildingGen(glm::vec3(-1 * 10.0f, 0.0f, -1 * 5.0f + offsetz), texside, textop);
			BuildingGen(glm::vec3(-1 * 10.0f, 0.0f, -1 * 10.0f), texside, textop);
			BuildingGen(glm::vec3(-1 * 10.0f, 0.0f, -1 * 15.0f - offsetz), texside, textop);

			BuildingGen(glm::vec3(-1 * 5.0f + offsetx, 0.0f, -1 * 5.0f + offsetz), texside, textop);
			BuildingGen(glm::vec3(-1 * 5.0f + offsetx, 0.0f, -1 * 10.0f), texside, textop);
			BuildingGen(glm::vec3(-1 * 5.0f + offsetx, 0.0f, -1 * 15.0f - offsetz), texside, textop);

			BuildingGen(glm::vec3(-1 * 15.0f - offsetx, 0.0f, -1 * 5.0f + offsetz), texside, textop);
			BuildingGen(glm::vec3(-1 * 15.0f - offsetx, 0.0f, -1 * 10.0f), texside, textop);
			BuildingGen(glm::vec3(-1 * 15.0f - offsetx, 0.0f, -1 * 15.0f - offsetz), texside, textop);
		}
	}
	{
		//tile 12
		if (SF != 9) {
			addRoad(new Road(glm::vec3(-1 * 30.0f, 0.0f, -1 * 5.0f), 5, 5, "roadPLAZA.png"));
			addRoad(new Road(glm::vec3(-1 * 30.0f, 0.0f, -1 * 10.0f), 5, 5, "roadPLAZA.png"));
			addRoad(new Road(glm::vec3(-1 * 30.0f, 0.0f, -1 * 15.0f), 5, 5, "roadPLAZA.png"));

			addRoad(new Road(glm::vec3(-1 * 25.0f, 0.0f, -1 * 5.0f), 5, 5, "roadPLAZA.png"));
			addRoad(new Road(glm::vec3(-1 * 25.0f, 0.0f, -1 * 10.0f), 5, 5, "roadPLAZA.png"));
			addRoad(new Road(glm::vec3(-1 * 25.0f, 0.0f, -1 * 15.0f), 5, 5, "roadPLAZA.png"));

			addRoad(new Road(glm::vec3(-1 * 35.0f, 0.0f, -1 * 5.0f), 5, 5, "roadPLAZA.png"));
			addRoad(new Road(glm::vec3(-1 * 35.0f, 0.0f, -1 * 10.0f), 5, 5, "roadPLAZA.png"));
			addRoad(new Road(glm::vec3(-1 * 35.0f, 0.0f, -1 * 15.0f), 5, 5, "roadPLAZA.png"));

			int tex = rand() % 4;
			GLchar* texside;
			GLchar* textop;
			if (tex == 0) {
				texside = "NightBuilding8.jpg";
				textop = "BlackRoof.jpg";
			}
			else if (tex == 1) {
				texside = "NightBuilding8.jpg";
				textop = "BlackRoof.jpg";
			}
			else if (tex == 2) {
				texside = "NightBuilding8.jpg";
				textop = "BlackRoof.jpg";
			}
			else if (tex == 3) {
				texside = "NightBuilding8.jpg";
				textop = "BlackRoof.jpg";
			}

			BuildingGen(glm::vec3(-1 * 30.0f, 0.0f, -1 * 5.0f + offsetz), texside, textop);
			BuildingGen(glm::vec3(-1 * 30.0f, 0.0f, -1 * 10.0f), texside, textop);
			BuildingGen(glm::vec3(-1 * 30.0f, 0.0f, -1 * 15.0f - offsetz), texside, textop);

			BuildingGen(glm::vec3(-1 * 25.0f + offsetx, 0.0f, -1 * 5.0f + offsetz), texside, textop);
			BuildingGen(glm::vec3(-1 * 25.0f + offsetx, 0.0f, -1 * 10.0f), texside, textop);
			BuildingGen(glm::vec3(-1 * 25.0f + offsetx, 0.0f, -1 * 15.0f - offsetz), texside, textop);

			BuildingGen(glm::vec3(-1 * 35.0f - offsetx, 0.0f, -1 * 5.0f + offsetz), texside, textop);
			BuildingGen(glm::vec3(-1 * 35.0f - offsetx, 0.0f, -1 * 10.0f), texside, textop);
			BuildingGen(glm::vec3(-1 * 35.0f - offsetx, 0.0f, -1 * 15.0f - offsetz), texside, textop);
		}
	}
	{
		//tile 13
		if (SF != 10) {
			addRoad(new Road(glm::vec3(25.0f, 0.0f, -1 * 30.0f), 5, 5, "roadPLAZA.png"));
			addRoad(new Road(glm::vec3(30.0f, 0.0f, -1 * 30.0f), 5, 5, "roadPLAZA.png"));
			addRoad(new Road(glm::vec3(35.0f, 0.0f, -1 * 30.0f), 5, 5, "roadPLAZA.png"));

			addRoad(new Road(glm::vec3(25.0f, 0.0f, -1 * 25.0f), 5, 5, "roadPLAZA.png"));
			addRoad(new Road(glm::vec3(30.0f, 0.0f, -1 * 25.0f), 5, 5, "roadPLAZA.png"));
			addRoad(new Road(glm::vec3(35.0f, 0.0f, -1 * 25.0f), 5, 5, "roadPLAZA.png"));

			addRoad(new Road(glm::vec3(25.0f, 0.0f, -1 * 35.0f), 5, 5, "roadPLAZA.png"));
			addRoad(new Road(glm::vec3(30.0f, 0.0f, -1 * 35.0f), 5, 5, "roadPLAZA.png"));
			addRoad(new Road(glm::vec3(35.0f, 0.0f, -1 * 35.0f), 5, 5, "roadPLAZA.png"));

			int tex = rand() % 4;
			GLchar* texside;
			GLchar* textop;
			if (tex == 0) {
				texside = "NightBuilding8.jpg";
				textop = "BlackRoof.jpg";
			}
			else if (tex == 1) {
				texside = "NightBuilding8.jpg";
				textop = "BlackRoof.jpg";
			}
			else if (tex == 2) {
				texside = "NightBuilding8.jpg";
				textop = "BlackRoof.jpg";
			}
			else if (tex == 3) {
				texside = "NightBuilding8.jpg";
				textop = "BlackRoof.jpg";
			}

			BuildingGen(glm::vec3(25.0f - offsetx, 0.0f, -1 * 30.0f), texside, textop);
			BuildingGen(glm::vec3(30.0f, 0.0f, -1 * 30.0f), texside, textop);
			BuildingGen(glm::vec3(35.0f + offsetx, 0.0f, -1 * 30.0f), texside, textop);

			BuildingGen(glm::vec3(25.0f - offsetx, 0.0f, -1 * 25.0f + offsetz), texside, textop);
			BuildingGen(glm::vec3(30.0f, 0.0f, -1 * 25.0f + offsetz), texside, textop);
			BuildingGen(glm::vec3(35.0f + offsetx, 0.0f, -1 * 25.0f + offsetz), texside, textop);

			BuildingGen(glm::vec3(25.0f - offsetx, 0.0f, -1 * 35.0f - offsetz), texside, textop);
			BuildingGen(glm::vec3(30.0f, 0.0f, -1 * 35.0f - offsetz), texside, textop);
			BuildingGen(glm::vec3(35.0f + offsetx, 0.0f, -1 * 35.0f - offsetz), texside, textop);
		}
	}
	{
		//tile 14
		if (SF != 10 && SF != 11) {
			addRoad(new Road(glm::vec3(5.0f, 0.0f, -1 * 30.0f), 5, 5, "roadPLAZA.png"));
			addRoad(new Road(glm::vec3(10.0f, 0.0f, -1 * 30.0f), 5, 5, "roadPLAZA.png"));
			addRoad(new Road(glm::vec3(15.0f, 0.0f, -1 * 30.0f), 5, 5, "roadPLAZA.png"));

			addRoad(new Road(glm::vec3(5.0f, 0.0f, -1 * 25.0f), 5, 5, "roadPLAZA.png"));
			addRoad(new Road(glm::vec3(10.0f, 0.0f, -1 * 25.0f), 5, 5, "roadPLAZA.png"));
			addRoad(new Road(glm::vec3(15.0f, 0.0f, -1 * 25.0f), 5, 5, "roadPLAZA.png"));

			addRoad(new Road(glm::vec3(5.0f, 0.0f, -1 * 35.0f), 5, 5, "roadPLAZA.png"));
			addRoad(new Road(glm::vec3(10.0f, 0.0f, -1 * 35.0f), 5, 5, "roadPLAZA.png"));
			addRoad(new Road(glm::vec3(15.0f, 0.0f, -1 * 35.0f), 5, 5, "roadPLAZA.png"));

			int tex = rand() % 4;
			GLchar* texside;
			GLchar* textop;
			if (tex == 0) {
				texside = "NightBuilding8.jpg";
				textop = "BlackRoof.jpg";
			}
			else if (tex == 1) {
				texside = "NightBuilding8.jpg";
				textop = "BlackRoof.jpg";
			}
			else if (tex == 2) {
				texside = "NightBuilding8.jpg";
				textop = "BlackRoof.jpg";
			}
			else if (tex == 3) {
				texside = "NightBuilding8.jpg";
				textop = "BlackRoof.jpg";
			}

			BuildingGen(glm::vec3(5.0f - offsetx, 0.0f, -1 * 30.0f), texside, textop);
			BuildingGen(glm::vec3(10.0f, 0.0f, -1 * 30.0f), texside, textop);
			BuildingGen(glm::vec3(15.0f + offsetx, 0.0f, -1 * 30.0f), texside, textop);

			BuildingGen(glm::vec3(5.0f - offsetx, 0.0f, -1 * 25.0f + offsetz), texside, textop);
			BuildingGen(glm::vec3(10.0f, 0.0f, -1 * 25.0f + offsetz), texside, textop);
			BuildingGen(glm::vec3(15.0f + offsetx, 0.0f, -1 * 25.0f + offsetz), texside, textop);

			BuildingGen(glm::vec3(5.0f - offsetx, 0.0f, -1 * 35.0f - offsetz), texside, textop);
			BuildingGen(glm::vec3(10.0f, 0.0f, -1 * 35.0f - offsetz), texside, textop);
			BuildingGen(glm::vec3(15.0f + offsetx, 0.0f, -1 * 35.0f - offsetz), texside, textop);
		}
	}
	{
		//tile 15
		if (SF != 11 && SF != 12) {
			addRoad(new Road(glm::vec3(-1 * 5.0f, 0.0f, -1 * 30.0f), 5, 5, "roadPLAZA.png"));
			addRoad(new Road(glm::vec3(-1 * 10.0f, 0.0f, -1 * 30.0f), 5, 5, "roadPLAZA.png"));
			addRoad(new Road(glm::vec3(-1 * 15.0f, 0.0f, -1 * 30.0f), 5, 5, "roadPLAZA.png"));

			addRoad(new Road(glm::vec3(-1 * 5.0f, 0.0f, -1 * 25.0f), 5, 5, "roadPLAZA.png"));
			addRoad(new Road(glm::vec3(-1 * 10.0f, 0.0f, -1 * 25.0f), 5, 5, "roadPLAZA.png"));
			addRoad(new Road(glm::vec3(-1 * 15.0f, 0.0f, -1 * 25.0f), 5, 5, "roadPLAZA.png"));

			addRoad(new Road(glm::vec3(-1 * 5.0f, 0.0f, -1 * 35.0f), 5, 5, "roadPLAZA.png"));
			addRoad(new Road(glm::vec3(-1 * 10.0f, 0.0f, -1 * 35.0f), 5, 5, "roadPLAZA.png"));
			addRoad(new Road(glm::vec3(-1 * 15.0f, 0.0f, -1 * 35.0f), 5, 5, "roadPLAZA.png"));

			int tex = rand() % 4;
			GLchar* texside;
			GLchar* textop;
			if (tex == 0) {
				texside = "NightBuilding8.jpg";
				textop = "BlackRoof.jpg";
			}
			else if (tex == 1) {
				texside = "NightBuilding8.jpg";
				textop = "BlackRoof.jpg";
			}
			else if (tex == 2) {
				texside = "NightBuilding8.jpg";
				textop = "BlackRoof.jpg";
			}
			else if (tex == 3) {
				texside = "NightBuilding8.jpg";
				textop = "BlackRoof.jpg";
			}

			BuildingGen(glm::vec3(-1 * 5.0f + offsetx, 0.0f, -1 * 30.0f), texside, textop);
			BuildingGen(glm::vec3(-1 * 10.0f, 0.0f, -1 * 30.0f), texside, textop);
			BuildingGen(glm::vec3(-1 * 15.0f - offsetx, 0.0f, -1 * 30.0f), texside, textop);

			BuildingGen(glm::vec3(-1 * 5.0f + offsetx, 0.0f, -1 * 25.0f + offsetz), texside, textop);
			BuildingGen(glm::vec3(-1 * 10.0f, 0.0f, -1 * 25.0f + offsetz), texside, textop);
			BuildingGen(glm::vec3(-1 * 15.0f - offsetx, 0.0f, -1 * 25.0f + offsetz), texside, textop);

			BuildingGen(glm::vec3(-1 * 5.0f + offsetx, 0.0f, -1 * 35.0f - offsetz), texside, textop);
			BuildingGen(glm::vec3(-1 * 10.0f, 0.0f, -1 * 35.0f - offsetz), texside, textop);
			BuildingGen(glm::vec3(-1 * 15.0f - offsetx, 0.0f, -1 * 35.0f - offsetz), texside, textop);
		}
	}
	{
		//tile 16
		if (SF != 12) {
			addRoad(new Road(glm::vec3(-1 * 25.0f, 0.0f, -1 * 30.0f), 5, 5, "roadPLAZA.png"));
			addRoad(new Road(glm::vec3(-1 * 30.0f, 0.0f, -1 * 30.0f), 5, 5, "roadPLAZA.png"));
			addRoad(new Road(glm::vec3(-1 * 35.0f, 0.0f, -1 * 30.0f), 5, 5, "roadPLAZA.png"));

			addRoad(new Road(glm::vec3(-1 * 25.0f, 0.0f, -1 * 25.0f), 5, 5, "roadPLAZA.png"));
			addRoad(new Road(glm::vec3(-1 * 30.0f, 0.0f, -1 * 25.0f), 5, 5, "roadPLAZA.png"));
			addRoad(new Road(glm::vec3(-1 * 35.0f, 0.0f, -1 * 25.0f), 5, 5, "roadPLAZA.png"));

			addRoad(new Road(glm::vec3(-1 * 25.0f, 0.0f, -1 * 35.0f), 5, 5, "roadPLAZA.png"));
			addRoad(new Road(glm::vec3(-1 * 30.0f, 0.0f, -1 * 35.0f), 5, 5, "roadPLAZA.png"));
			addRoad(new Road(glm::vec3(-1 * 35.0f, 0.0f, -1 * 35.0f), 5, 5, "roadPLAZA.png"));

			int tex = rand() % 4;
			GLchar* texside;
			GLchar* textop;
			if (tex == 0) {
				texside = "NightBuilding8.jpg";
				textop = "BlackRoof.jpg";
			}
			else if (tex == 1) {
				texside = "NightBuilding8.jpg";
				textop = "BlackRoof.jpg";
			}
			else if (tex == 2) {
				texside = "NightBuilding8.jpg";
				textop = "BlackRoof.jpg";
			}
			else if (tex == 3) {
				texside = "NightBuilding8.jpg";
				textop = "BlackRoof.jpg";
			}

			BuildingGen(glm::vec3(-1 * 25.0f + offsetx, 0.0f, -1 * 30.0f), texside, textop);
			BuildingGen(glm::vec3(-1 * 30.0f, 0.0f, -1 * 30.0f), texside, textop);
			BuildingGen(glm::vec3(-1 * 35.0f - offsetx, 0.0f, -1 * 30.0f), texside, textop);

			BuildingGen(glm::vec3(-1 * 25.0f + offsetx, 0.0f, -1 * 25.0f + offsetz), texside, textop);
			BuildingGen(glm::vec3(-1 * 30.0f, 0.0f, -1 * 25.0f + offsetz), texside, textop);
			BuildingGen(glm::vec3(-1 * 35.0f - offsetx, 0.0f, -1 * 25.0f + offsetz), texside, textop);

			BuildingGen(glm::vec3(-1 * 25.0f + offsetx, 0.0f, -1 * 35.0f - offsetz), texside, textop);
			BuildingGen(glm::vec3(-1 * 30.0f, 0.0f, -1 * 35.0f - offsetz), texside, textop);
			BuildingGen(glm::vec3(-1 * 35.0f - offsetx, 0.0f, -1 * 35.0f - offsetz), texside, textop);
		}
	}
	
	if (first) {
		GenRoad1();
		first = false;
	}
	else {
		GenRoad1();
	}
}

void City::GenRoad2() {
	addRoad(new Road(glm::vec3(40.0f, 0.0f, 20.0f + 5.0f * 4), 5, 5, "roadNW.png"));
	addRoad(new Road(glm::vec3(-1 * 40.0f, 0.0f, 20.0f + 5.0f * 4), 5, 5, "roadNE.png"));
	addRoad(new Road(glm::vec3(40.0f, 0.0f, -1 * 20.0f - 5.0f * 4), 5, 5, "roadSW.png"));
	addRoad(new Road(glm::vec3(-1 * 40.0f, 0.0f, -1 * 20.0f - 5.0f * 4), 5, 5, "roadSE.png"));

	addRoad(new Road(glm::vec3(20.0f + 5.0f * 4, 0.0f, 20.0f), 5, 5, "roadTW.png"));
	addRoad(new Road(glm::vec3(20.0f + 5.0f * 4, 0.0f, 0.0f), 5, 5, "roadTW.png"));
	addRoad(new Road(glm::vec3(20.0f + 5.0f * 4, 0.0f, -1 * 20.0f), 5, 5, "roadTW.png"));

	addRoad(new Road(glm::vec3(-1 * 20.0f - 5.0f * 4, 0.0f, 0.0f), 5, 5, "roadTE.png"));
	addRoad(new Road(glm::vec3(-1 * 20.0f - 5.0f * 4, 0.0f, 20.0f), 5, 5, "roadTE.png"));
	addRoad(new Road(glm::vec3(-1 * 20.0f - 5.0f * 4, 0.0f, -1 * 20.0f), 5, 5, "roadTE.png"));

	{// Row 1 Vert
		addRoad(new Road(glm::vec3(0.0f + 20.0f * 2, 0.0f, 25.0f + 5.0f * 0), 5, 5, "roadNS.png"));
		addRoad(new Road(glm::vec3(0.0f + 20.0f * 2, 0.0f, 25.0f + 5.0f * 1), 5, 5, "roadNS.png"));
		addRoad(new Road(glm::vec3(0.0f + 20.0f * 2, 0.0f, 25.0f + 5.0f * 2), 5, 5, "roadNS.png"));

		addRoad(new Road(glm::vec3(0.0f - 20.0f * 2, 0.0f, 25.0f + 5.0f * 0), 5, 5, "roadNS.png"));
		addRoad(new Road(glm::vec3(0.0f - 20.0f * 2, 0.0f, 25.0f + 5.0f * 1), 5, 5, "roadNS.png"));
		addRoad(new Road(glm::vec3(0.0f - 20.0f * 2, 0.0f, 25.0f + 5.0f * 2), 5, 5, "roadNS.png"));
	}

	{// Row 2 Vert
		addRoad(new Road(glm::vec3(0.0f + 20.0f * 2, 0.0f, 5.0f + 5.0f * 0), 5, 5, "roadNS.png"));
		addRoad(new Road(glm::vec3(0.0f + 20.0f * 2, 0.0f, 5.0f + 5.0f * 1), 5, 5, "roadNS.png"));
		addRoad(new Road(glm::vec3(0.0f + 20.0f * 2, 0.0f, 5.0f + 5.0f * 2), 5, 5, "roadNS.png"));

		addRoad(new Road(glm::vec3(0.0f - 20.0f * 2, 0.0f, 5.0f + 5.0f * 0), 5, 5, "roadNS.png"));
		addRoad(new Road(glm::vec3(0.0f - 20.0f * 2, 0.0f, 5.0f + 5.0f * 1), 5, 5, "roadNS.png"));
		addRoad(new Road(glm::vec3(0.0f - 20.0f * 2, 0.0f, 5.0f + 5.0f * 2), 5, 5, "roadNS.png"));
	}

	{// Row 3 Vert
		addRoad(new Road(glm::vec3(0.0f + 20.0f * 2, 0.0f, -1 * 5.0f - 5.0f * 0), 5, 5, "roadNS.png"));
		addRoad(new Road(glm::vec3(0.0f + 20.0f * 2, 0.0f, -1 * 5.0f - 5.0f * 1), 5, 5, "roadNS.png"));
		addRoad(new Road(glm::vec3(0.0f + 20.0f * 2, 0.0f, -1 * 5.0f - 5.0f * 2), 5, 5, "roadNS.png"));

		addRoad(new Road(glm::vec3(0.0f - 20.0f * 2, 0.0f, -1 * 5.0f - 5.0f * 0), 5, 5, "roadNS.png"));
		addRoad(new Road(glm::vec3(0.0f - 20.0f * 2, 0.0f, -1 * 5.0f - 5.0f * 1), 5, 5, "roadNS.png"));
		addRoad(new Road(glm::vec3(0.0f - 20.0f * 2, 0.0f, -1 * 5.0f - 5.0f * 2), 5, 5, "roadNS.png"));
	}

	{// Row 4 Vert
		addRoad(new Road(glm::vec3(0.0f + 20.0f * 2, 0.0f, -1 * 25.0f - 5.0f * 0), 5, 5, "roadNS.png"));
		addRoad(new Road(glm::vec3(0.0f + 20.0f * 2, 0.0f, -1 * 25.0f - 5.0f * 1), 5, 5, "roadNS.png"));
		addRoad(new Road(glm::vec3(0.0f + 20.0f * 2, 0.0f, -1 * 25.0f - 5.0f * 2), 5, 5, "roadNS.png"));

		addRoad(new Road(glm::vec3(0.0f - 20.0f * 2, 0.0f, -1 * 25.0f - 5.0f * 0), 5, 5, "roadNS.png"));
		addRoad(new Road(glm::vec3(0.0f - 20.0f * 2, 0.0f, -1 * 25.0f - 5.0f * 1), 5, 5, "roadNS.png"));
		addRoad(new Road(glm::vec3(0.0f - 20.0f * 2, 0.0f, -1 * 25.0f - 5.0f * 2), 5, 5, "roadNS.png"));
	}


	for (int j = 0; j < 3; j++) {//horizontal
		//
		for (int i = 0; i < 3; i++) {
			addRoad(new Road(glm::vec3(5.0f + 5.0f*i, 0.0f, 0.0f + 20.0f*j), 5, 5, "roadEW.png"));
			addRoad(new Road(glm::vec3(-1 * 5.0f - 5.0f*i, 0.0f, 0.0f + 20.0f*j), 5, 5, "roadEW.png"));

		}
		for (int i = 0; i < 3; i++) {
			addRoad(new Road(glm::vec3(5.0f + 5.0f*i, 0.0f, 0.0f - 20.0f*j), 5, 5, "roadEW.png"));
			addRoad(new Road(glm::vec3(-1 * 5.0f - 5.0f*i, 0.0f, 0.0f - 20.0f*j), 5, 5, "roadEW.png"));
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
}

void City::GenRoad1() {
	if (SF != 1 && SF != 4) {
		addRoad(new Road(glm::vec3(20.0f, 0.0f, 5.0f * 4), 5, 5, "roadNEWS.png"));
	}
	else {
		if (SF == 1) {
			addRoad(new Road(glm::vec3(20.0f, 0.0f, 5.0f * 4), 5, 5, "roadTN.png"));
		}
		else if (SF == 4) {
			addRoad(new Road(glm::vec3(20.0f, 0.0f, 5.0f * 4), 5, 5, "roadTS.png"));
		}
	}

	if (SF != 4 && SF != 7) {
		addRoad(new Road(glm::vec3(20.0f, 0.0f, 0.0f), 5, 5, "roadNEWS.png"));
	}
	else {
		if (SF == 4) {
			addRoad(new Road(glm::vec3(20.0f, 0.0f, 0.0f), 5, 5, "roadTN.png"));
		}
		else if (SF == 7) {
			addRoad(new Road(glm::vec3(20.0f, 0.0f, 0.0f), 5, 5, "roadTS.png"));
		}
	}

	if (SF != 7 && SF != 10) {
		addRoad(new Road(glm::vec3(20.0f, 0.0f, -1 * 5.0f * 4), 5, 5, "roadNEWS.png"));
	}
	else {
		if (SF == 7) {
			addRoad(new Road(glm::vec3(20.0f, 0.0f, -1 * 5.0f * 4), 5, 5, "roadTN.png"));
		}
		else if (SF == 10) {
			addRoad(new Road(glm::vec3(20.0f, 0.0f, -1 * 5.0f * 4), 5, 5, "roadTS.png"));
		}
	}

	if (SF != 2 && SF != 5) {
		addRoad(new Road(glm::vec3(0.0f, 0.0f, 5.0f * 4), 5, 5, "roadNEWS.png"));
	}
	else {
		if (SF == 2) {
			addRoad(new Road(glm::vec3(0.0f, 0.0f, 5.0f * 4), 5, 5, "roadTN.png"));
		}
		else if (SF == 5) {
			addRoad(new Road(glm::vec3(0.0f, 0.0f, 5.0f * 4), 5, 5, "roadTS.png"));
		}
	}

	if (SF != 5 && SF != 8) {
		addRoad(new Road(glm::vec3(0.0f, 0.0f, 0.0f), 5, 5, "roadNEWS.png"));
	}
	else {
		if (SF == 5) {
			addRoad(new Road(glm::vec3(0.0f, 0.0f, 0.0f), 5, 5, "roadTN.png"));
		}
		else if (SF == 8) {
			addRoad(new Road(glm::vec3(0.0f, 0.0f, 0.0f), 5, 5, "roadTS.png"));
		}
	}

	if (SF != 8 && SF != 11) {
		addRoad(new Road(glm::vec3(0.0f, 0.0f, -1 * 5.0f * 4), 5, 5, "roadNEWS.png"));
	}
	else {
		if (SF == 8) {
			addRoad(new Road(glm::vec3(0.0f, 0.0f, -1 * 5.0f * 4), 5, 5, "roadTN.png"));
		}
		else if (SF == 11) {
			addRoad(new Road(glm::vec3(0.0f, 0.0f, -1 * 5.0f * 4), 5, 5, "roadTS.png"));
		}
	}

	if (SF != 3 && SF != 6) {
		addRoad(new Road(glm::vec3(-1 * 20.0f, 0.0f, 5.0f * 4), 5, 5, "roadNEWS.png"));
	}
	else {
		if (SF == 3) {
			addRoad(new Road(glm::vec3(-1 * 20.0f, 0.0f, 5.0f * 4), 5, 5, "roadTN.png"));
		}
		else if (SF == 6) {
			addRoad(new Road(glm::vec3(-1 * 20.0f, 0.0f, 5.0f * 4), 5, 5, "roadTS.png"));
		}
	}

	if (SF != 6 && SF != 9) {
		addRoad(new Road(glm::vec3(-20.0f, 0.0f, 0.0f), 5, 5, "roadNEWS.png"));
	}
	else {
		if (SF == 6) {
			addRoad(new Road(glm::vec3(-20.0f, 0.0f, 0.0f), 5, 5, "roadTN.png"));
		}
		else if (SF == 9) {
			addRoad(new Road(glm::vec3(-20.0f, 0.0f, 0.0f), 5, 5, "roadTS.png"));
		}
	}

	if (SF != 9 && SF != 12) {
		addRoad(new Road(glm::vec3(-1 * 20.0f, 0.0f, -1 * 5.0f * 4), 5, 5, "roadNEWS.png"));
	}
	else {
		if (SF == 9) {
			addRoad(new Road(glm::vec3(-1 * 20.0f, 0.0f, -1 * 5.0f * 4), 5, 5, "roadTN.png"));
		}
		else if (SF == 12) {
			addRoad(new Road(glm::vec3(-1 * 20.0f, 0.0f, -1 * 5.0f * 4), 5, 5, "roadTS.png"));
		}
	}




	addRoad(new Road(glm::vec3(40.0f, 0.0f, 20.0f + 5.0f * 4), 5, 5, "roadNW.png"));
	addRoad(new Road(glm::vec3(-1 * 40.0f, 0.0f, 20.0f + 5.0f * 4), 5, 5, "roadNE.png"));
	addRoad(new Road(glm::vec3(40.0f, 0.0f, -1 * 20.0f - 5.0f * 4), 5, 5, "roadSW.png"));
	addRoad(new Road(glm::vec3(-1 * 40.0f, 0.0f, -1 * 20.0f - 5.0f * 4), 5, 5, "roadSE.png"));

	addRoad(new Road(glm::vec3(20.0f + 5.0f * 4, 0.0f, 20.0f), 5, 5, "roadTW.png"));
	addRoad(new Road(glm::vec3(20.0f + 5.0f * 4, 0.0f, 0.0f), 5, 5, "roadTW.png"));
	addRoad(new Road(glm::vec3(20.0f + 5.0f * 4, 0.0f, -1 * 20.0f), 5, 5, "roadTW.png"));

	addRoad(new Road(glm::vec3(-1 * 20.0f - 5.0f * 4, 0.0f, 0.0f), 5, 5, "roadTE.png"));
	addRoad(new Road(glm::vec3(-1 * 20.0f - 5.0f * 4, 0.0f, 20.0f), 5, 5, "roadTE.png"));
	addRoad(new Road(glm::vec3(-1 * 20.0f - 5.0f * 4, 0.0f, -1 * 20.0f), 5, 5, "roadTE.png"));

	{// Row 1 Vert
		addRoad(new Road(glm::vec3(0.0f + 20.0f * 2, 0.0f, 25.0f + 5.0f * 0), 5, 5, "roadNS.png"));
		addRoad(new Road(glm::vec3(0.0f + 20.0f * 2, 0.0f, 25.0f + 5.0f * 1), 5, 5, "roadNS.png"));
		addRoad(new Road(glm::vec3(0.0f + 20.0f * 2, 0.0f, 25.0f + 5.0f * 2), 5, 5, "roadNS.png"));

		if (SF != 1) {
			addRoad(new Road(glm::vec3(0.0f + 20.0f * 1, 0.0f, 25.0f + 5.0f * 0), 5, 5, "roadNS.png"));
			addRoad(new Road(glm::vec3(0.0f + 20.0f * 1, 0.0f, 25.0f + 5.0f * 1), 5, 5, "roadNS.png"));
			addRoad(new Road(glm::vec3(0.0f + 20.0f * 1, 0.0f, 25.0f + 5.0f * 2), 5, 5, "roadNS.png"));
			addRoad(new Road(glm::vec3(20.0f, 0.0f, 20.0f + 5.0f * 4), 5, 5, "roadTN.png"));
		}
		else {
			addRoad(new Road(glm::vec3(20.0f, 0.0f, 20.0f + 5.0f * 4), 5, 5, "roadEW.png"));
			addRoad(new Road(glm::vec3(0.0f + 20.0f * 1, 0.0f, 25.0f + 5.0f * 1), 15, 35, "SF2.jpg"));
		}

		if (SF != 2) {
			addRoad(new Road(glm::vec3(0.0f + 20.0f * 0, 0.0f, 25.0f + 5.0f * 0), 5, 5, "roadNS.png"));
			addRoad(new Road(glm::vec3(0.0f + 20.0f * 0, 0.0f, 25.0f + 5.0f * 1), 5, 5, "roadNS.png"));
			addRoad(new Road(glm::vec3(0.0f + 20.0f * 0, 0.0f, 25.0f + 5.0f * 2), 5, 5, "roadNS.png"));
			addRoad(new Road(glm::vec3(0.0f, 0.0f, 20.0f + 5.0f * 4), 5, 5, "roadTN.png"));
		}
		else {
			addRoad(new Road(glm::vec3(0.0f, 0.0f, 20.0f + 5.0f * 4), 5, 5, "roadEW.png"));
			addRoad(new Road(glm::vec3(0.0f + 20.0f * 0, 0.0f, 25.0f + 5.0f * 1), 15, 35, "SF2.jpg"));
		}

		if (SF != 3) {
			addRoad(new Road(glm::vec3(0.0f - 20.0f * 1, 0.0f, 25.0f + 5.0f * 0), 5, 5, "roadNS.png"));
			addRoad(new Road(glm::vec3(0.0f - 20.0f * 1, 0.0f, 25.0f + 5.0f * 1), 5, 5, "roadNS.png"));
			addRoad(new Road(glm::vec3(0.0f - 20.0f * 1, 0.0f, 25.0f + 5.0f * 2), 5, 5, "roadNS.png"));
			addRoad(new Road(glm::vec3(-1 * 20.0f, 0.0f, 20.0f + 5.0f * 4), 5, 5, "roadTN.png"));
		}
		else {
			addRoad(new Road(glm::vec3(-1 * 20.0f, 0.0f, 20.0f + 5.0f * 4), 5, 5, "roadEW.png"));
			addRoad(new Road(glm::vec3(0.0f - 20.0f * 1, 0.0f, 25.0f + 5.0f * 1), 15, 35, "SF2.jpg"));
		}

		addRoad(new Road(glm::vec3(0.0f - 20.0f * 2, 0.0f, 25.0f + 5.0f * 0), 5, 5, "roadNS.png"));
		addRoad(new Road(glm::vec3(0.0f - 20.0f * 2, 0.0f, 25.0f + 5.0f * 1), 5, 5, "roadNS.png"));
		addRoad(new Road(glm::vec3(0.0f - 20.0f * 2, 0.0f, 25.0f + 5.0f * 2), 5, 5, "roadNS.png"));
	}

	{// Row 2 Vert
		addRoad(new Road(glm::vec3(0.0f + 20.0f * 2, 0.0f, 5.0f + 5.0f * 0), 5, 5, "roadNS.png"));
		addRoad(new Road(glm::vec3(0.0f + 20.0f * 2, 0.0f, 5.0f + 5.0f * 1), 5, 5, "roadNS.png"));
		addRoad(new Road(glm::vec3(0.0f + 20.0f * 2, 0.0f, 5.0f + 5.0f * 2), 5, 5, "roadNS.png"));

		if (SF != 4) {
			addRoad(new Road(glm::vec3(0.0f + 20.0f * 1, 0.0f, 5.0f + 5.0f * 0), 5, 5, "roadNS.png"));
			addRoad(new Road(glm::vec3(0.0f + 20.0f * 1, 0.0f, 5.0f + 5.0f * 1), 5, 5, "roadNS.png"));
			addRoad(new Road(glm::vec3(0.0f + 20.0f * 1, 0.0f, 5.0f + 5.0f * 2), 5, 5, "roadNS.png"));
		}
		else {
			addRoad(new Road(glm::vec3(0.0f + 20.0f * 1, 0.0f, 5.0f + 5.0f * 1), 15, 35, "SF2.jpg"));
		}

		if (SF != 5) {
			addRoad(new Road(glm::vec3(0.0f + 20.0f * 0, 0.0f, 5.0f + 5.0f * 0), 5, 5, "roadNS.png"));
			addRoad(new Road(glm::vec3(0.0f + 20.0f * 0, 0.0f, 5.0f + 5.0f * 1), 5, 5, "roadNS.png"));
			addRoad(new Road(glm::vec3(0.0f + 20.0f * 0, 0.0f, 5.0f + 5.0f * 2), 5, 5, "roadNS.png"));
		}
		else {
			addRoad(new Road(glm::vec3(0.0f + 20.0f * 0, 0.0f, 5.0f + 5.0f * 1), 15, 35, "SF2.jpg"));
		}

		if (SF != 6) {
			addRoad(new Road(glm::vec3(0.0f - 20.0f * 1, 0.0f, 5.0f + 5.0f * 0), 5, 5, "roadNS.png"));
			addRoad(new Road(glm::vec3(0.0f - 20.0f * 1, 0.0f, 5.0f + 5.0f * 1), 5, 5, "roadNS.png"));
			addRoad(new Road(glm::vec3(0.0f - 20.0f * 1, 0.0f, 5.0f + 5.0f * 2), 5, 5, "roadNS.png"));
		}
		else {
			addRoad(new Road(glm::vec3(0.0f - 20.0f * 1, 0.0f, 5.0f + 5.0f * 1), 15, 35, "SF2.jpg"));
		}

		addRoad(new Road(glm::vec3(0.0f - 20.0f * 2, 0.0f, 5.0f + 5.0f * 0), 5, 5, "roadNS.png"));
		addRoad(new Road(glm::vec3(0.0f - 20.0f * 2, 0.0f, 5.0f + 5.0f * 1), 5, 5, "roadNS.png"));
		addRoad(new Road(glm::vec3(0.0f - 20.0f * 2, 0.0f, 5.0f + 5.0f * 2), 5, 5, "roadNS.png"));
	}

	{// Row 3 Vert
		addRoad(new Road(glm::vec3(0.0f + 20.0f * 2, 0.0f, -1 * 5.0f - 5.0f * 0), 5, 5, "roadNS.png"));
		addRoad(new Road(glm::vec3(0.0f + 20.0f * 2, 0.0f, -1 * 5.0f - 5.0f * 1), 5, 5, "roadNS.png"));
		addRoad(new Road(glm::vec3(0.0f + 20.0f * 2, 0.0f, -1 * 5.0f - 5.0f * 2), 5, 5, "roadNS.png"));

		if (SF != 7) {
			addRoad(new Road(glm::vec3(0.0f + 20.0f * 1, 0.0f, -1 * 5.0f - 5.0f * 0), 5, 5, "roadNS.png"));
			addRoad(new Road(glm::vec3(0.0f + 20.0f * 1, 0.0f, -1 * 5.0f - 5.0f * 1), 5, 5, "roadNS.png"));
			addRoad(new Road(glm::vec3(0.0f + 20.0f * 1, 0.0f, -1 * 5.0f - 5.0f * 2), 5, 5, "roadNS.png"));
		}
		else {
			addRoad(new Road(glm::vec3(0.0f + 20.0f * 1, 0.0f, -1 * 5.0f - 5.0f * 1), 15, 35, "SF2.jpg"));
		}

		if (SF != 8) {
			addRoad(new Road(glm::vec3(0.0f + 20.0f * 0, 0.0f, -1 * 5.0f - 5.0f * 0), 5, 5, "roadNS.png"));
			addRoad(new Road(glm::vec3(0.0f + 20.0f * 0, 0.0f, -1 * 5.0f - 5.0f * 1), 5, 5, "roadNS.png"));
			addRoad(new Road(glm::vec3(0.0f + 20.0f * 0, 0.0f, -1 * 5.0f - 5.0f * 2), 5, 5, "roadNS.png"));
		}
		else {
			addRoad(new Road(glm::vec3(0.0f + 20.0f * 0, 0.0f, -1 * 5.0f - 5.0f * 1), 15, 35, "SF2.jpg"));
		}

		if (SF != 9) {
			addRoad(new Road(glm::vec3(0.0f - 20.0f * 1, 0.0f, -1 * 5.0f - 5.0f * 0), 5, 5, "roadNS.png"));
			addRoad(new Road(glm::vec3(0.0f - 20.0f * 1, 0.0f, -1 * 5.0f - 5.0f * 1), 5, 5, "roadNS.png"));
			addRoad(new Road(glm::vec3(0.0f - 20.0f * 1, 0.0f, -1 * 5.0f - 5.0f * 2), 5, 5, "roadNS.png"));
		}
		else {
			addRoad(new Road(glm::vec3(0.0f - 20.0f * 1, 0.0f, -1 * 5.0f - 5.0f * 1), 15, 35, "SF2.jpg"));
		}

		addRoad(new Road(glm::vec3(0.0f - 20.0f * 2, 0.0f, -1 * 5.0f - 5.0f * 0), 5, 5, "roadNS.png"));
		addRoad(new Road(glm::vec3(0.0f - 20.0f * 2, 0.0f, -1 * 5.0f - 5.0f * 1), 5, 5, "roadNS.png"));
		addRoad(new Road(glm::vec3(0.0f - 20.0f * 2, 0.0f, -1 * 5.0f - 5.0f * 2), 5, 5, "roadNS.png"));
	}

	{// Row 4 Vert
		addRoad(new Road(glm::vec3(0.0f + 20.0f * 2, 0.0f, -1 * 25.0f - 5.0f * 0), 5, 5, "roadNS.png"));
		addRoad(new Road(glm::vec3(0.0f + 20.0f * 2, 0.0f, -1 * 25.0f - 5.0f * 1), 5, 5, "roadNS.png"));
		addRoad(new Road(glm::vec3(0.0f + 20.0f * 2, 0.0f, -1 * 25.0f - 5.0f * 2), 5, 5, "roadNS.png"));

		if (SF != 10) {
			addRoad(new Road(glm::vec3(0.0f + 20.0f * 1, 0.0f, -1 * 25.0f - 5.0f * 0), 5, 5, "roadNS.png"));
			addRoad(new Road(glm::vec3(0.0f + 20.0f * 1, 0.0f, -1 * 25.0f - 5.0f * 1), 5, 5, "roadNS.png"));
			addRoad(new Road(glm::vec3(0.0f + 20.0f * 1, 0.0f, -1 * 25.0f - 5.0f * 2), 5, 5, "roadNS.png"));
			addRoad(new Road(glm::vec3(20.0f, 0.0f, -1 * 20.0f - 5.0f * 4), 5, 5, "roadTS.png"));
		}
		else {
			addRoad(new Road(glm::vec3(20.0f, 0.0f, -1 * 20.0f - 5.0f * 4), 5, 5, "roadEW.png"));
			addRoad(new Road(glm::vec3(0.0f + 20.0f * 1, 0.0f, -1 * 25.0f - 5.0f * 1), 15, 35, "SF2.jpg"));
		}

		if (SF != 11) {
			addRoad(new Road(glm::vec3(0.0f + 20.0f * 0, 0.0f, -1 * 25.0f - 5.0f * 0), 5, 5, "roadNS.png"));
			addRoad(new Road(glm::vec3(0.0f + 20.0f * 0, 0.0f, -1 * 25.0f - 5.0f * 1), 5, 5, "roadNS.png"));
			addRoad(new Road(glm::vec3(0.0f + 20.0f * 0, 0.0f, -1 * 25.0f - 5.0f * 2), 5, 5, "roadNS.png"));
			addRoad(new Road(glm::vec3(0.0f, 0.0f, -1 * 20.0f - 5.0f * 4), 5, 5, "roadTS.png"));
		}
		else {
			addRoad(new Road(glm::vec3(0.0f, 0.0f, -1 * 20.0f - 5.0f * 4), 5, 5, "roadEW.png"));
			addRoad(new Road(glm::vec3(0.0f + 20.0f * 0, 0.0f, -1 * 25.0f - 5.0f * 1), 15, 35, "SF2.jpg"));
		}

		if (SF != 12) {
			addRoad(new Road(glm::vec3(0.0f - 20.0f * 1, 0.0f, -1 * 25.0f - 5.0f * 0), 5, 5, "roadNS.png"));
			addRoad(new Road(glm::vec3(0.0f - 20.0f * 1, 0.0f, -1 * 25.0f - 5.0f * 1), 5, 5, "roadNS.png"));
			addRoad(new Road(glm::vec3(0.0f - 20.0f * 1, 0.0f, -1 * 25.0f - 5.0f * 2), 5, 5, "roadNS.png"));
			addRoad(new Road(glm::vec3(-1 * 20.0f, 0.0f, -1 * 20.0f - 5.0f * 4), 5, 5, "roadTS.png"));
		}
		else {
			addRoad(new Road(glm::vec3(-1 * 20.0f, 0.0f, -1 * 20.0f - 5.0f * 4), 5, 5, "roadEW.png"));
			addRoad(new Road(glm::vec3(0.0f - 20.0f * 1, 0.0f, -1 * 25.0f - 5.0f * 1), 15, 35, "SF2.jpg"));
		}

		addRoad(new Road(glm::vec3(0.0f - 20.0f * 2, 0.0f, -1 * 25.0f - 5.0f * 0), 5, 5, "roadNS.png"));
		addRoad(new Road(glm::vec3(0.0f - 20.0f * 2, 0.0f, -1 * 25.0f - 5.0f * 1), 5, 5, "roadNS.png"));
		addRoad(new Road(glm::vec3(0.0f - 20.0f * 2, 0.0f, -1 * 25.0f - 5.0f * 2), 5, 5, "roadNS.png"));
	}


	for (int j = 0; j < 3; j++) {//horizontal
		//
		for (int i = 0; i < 3; i++) {
			addRoad(new Road(glm::vec3(5.0f + 5.0f*i, 0.0f, 0.0f + 20.0f*j), 5, 5, "roadEW.png"));
			addRoad(new Road(glm::vec3(-1 * 5.0f - 5.0f*i, 0.0f, 0.0f + 20.0f*j), 5, 5, "roadEW.png"));

		}
		for (int i = 0; i < 3; i++) {
			addRoad(new Road(glm::vec3(5.0f + 5.0f*i, 0.0f, 0.0f - 20.0f*j), 5, 5, "roadEW.png"));
			addRoad(new Road(glm::vec3(-1 * 5.0f - 5.0f*i, 0.0f, 0.0f - 20.0f*j), 5, 5, "roadEW.png"));
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
}

void City::GenB1(glm::vec3 pos1, GLchar* fs, GLchar* ft){
	
	float heightr = RandomFloat(5,10);
	float buildingsize = 4.5;
	addBuilding(new Building(pos1, buildingsize, buildingsize, -5.0f,1, fs, ft));
	glm::vec3 pos2 = pos1 - glm::vec3(RandomFloat(-0.5, 0.5),0.0f, RandomFloat(-0.5, 0.5));
	addBuilding(new Building(pos2, buildingsize-2, buildingsize-2, heightr,1, fs, ft));
	glm::vec3 pos3 = pos1 - glm::vec3(RandomFloat(-1.5, 1.5), 0.0f, 0.0f);
	addBuilding(new Building(pos3, buildingsize - 3, buildingsize - 1, heightr - RandomFloat(2, 7),1, fs, ft));
	glm::vec3 pos4 = pos1 - glm::vec3(0.0f, 0.0f, RandomFloat(-1.5, 1.5));
	addBuilding(new Building(pos4, buildingsize - 1, buildingsize - 3, heightr - RandomFloat(2, 7),1, fs, ft));

}

void City::GenB2(glm::vec3 pos1, GLchar* fs, GLchar* ft) {

	float heightr = RandomFloat(5, 10);
	float buildingsize = 4.5;
	addBuilding(new Building(pos1, buildingsize, buildingsize, RandomFloat(-5, 2.5), 1, fs, ft));
	float bs1 = RandomFloat(0, 2);
	float bs2 = RandomFloat(2, 3);
	addBuilding(new Building(pos1, buildingsize - bs1, buildingsize - bs1, RandomFloat(2.5, heightr), 1, fs, ft));
	addBuilding(new Building(pos1, buildingsize - bs2, buildingsize - bs2, heightr, 2, fs, ft));

}

void City::GenB3(glm::vec3 pos1, GLchar* fs, GLchar* ft) {

	float heightr = RandomFloat(5, 10);
	float buildingsize = 4.5;
	addBuilding(new Building(pos1, buildingsize, buildingsize, RandomFloat(-5, 2.5), 3, fs, ft));
	float bs1 = RandomFloat(0, 2);
	float bs2 = RandomFloat(2, 3);
	addBuilding(new Building(pos1, buildingsize - bs1, buildingsize - bs1, RandomFloat(2.5, 5), 3, fs, ft));
	addBuilding(new Building(pos1, buildingsize - bs2, buildingsize - bs2, heightr, 2, fs, ft));

}

void City::GenB4(glm::vec3 pos1, GLchar* fs, GLchar* ft) {

	float heightr = RandomFloat(5, 10);
	float buildingsize = 4.5;
	addBuilding(new Building(pos1, buildingsize, buildingsize, RandomFloat(-10, -5), 4, fs, ft));
	float bs1 = RandomFloat(1, 2);
	float bs2 = RandomFloat(2, 3);
	addBuilding(new Building(pos1, buildingsize - bs1, buildingsize - bs1, RandomFloat(0, 5), 1, fs, ft));
	addBuilding(new Building(pos1, buildingsize - bs2, buildingsize - bs2, heightr, 2, fs, ft));

}

void City::GenB5(glm::vec3 pos1, GLchar* fs, GLchar* ft) {

	float heightr = RandomFloat(5, 10);
	float buildingsize = 4.5;
	addBuilding(new Building(pos1, buildingsize, buildingsize, RandomFloat(-10, -5), 4, fs, ft));
	float bs1 = RandomFloat(1, 2);
	float bs2 = RandomFloat(2, 3);
	addBuilding(new Building(pos1, buildingsize - bs1, buildingsize - bs1, RandomFloat(0, 5), 3, fs, ft));
	addBuilding(new Building(pos1, buildingsize - bs2, buildingsize - bs2, heightr, 2, fs, ft));

}

void City::GenB6(glm::vec3 pos1, GLchar* fs, GLchar* ft) {

	float heightr = RandomFloat(5, 10);
	float buildingsize = 4.5;
	float bs0 = RandomFloat(0, 5);
	addBuilding(new Building(pos1, buildingsize, buildingsize, bs0, 5, fs, ft));
	float bs1 = RandomFloat(0.5f, 2.0f);
	float bs2 = RandomFloat(2.0f, 3.0f);
	addBuilding(new Building(pos1, buildingsize - bs1, buildingsize - bs1, bs0, 1, fs, ft));
	addBuilding(new Building(pos1, buildingsize - bs2, buildingsize - bs2, heightr, 2, fs, ft));

}

void City::GenB7(glm::vec3 pos1, GLchar* fs, GLchar* ft) {

	float heightr = RandomFloat(5, 10);
	float buildingsize = 4.5;
	float bs0 = RandomFloat(0, 5);
	addBuilding(new Building(pos1, buildingsize, buildingsize, RandomFloat(-10, -5), 4, fs, ft));
	addBuilding(new Building(pos1, buildingsize, buildingsize, bs0, 5, fs, ft));
	float bs1 = RandomFloat(1, 2);
	float bs2 = RandomFloat(2, 3);
	addBuilding(new Building(pos1, buildingsize - bs1, buildingsize - bs1, bs0, 1, fs, ft));
	addBuilding(new Building(pos1, buildingsize - bs2, buildingsize - bs2, heightr, 2, fs, ft));

}

void City::GenB8(glm::vec3 pos1, GLchar* fs, GLchar* ft) {

	float heightr = RandomFloat(5, 10);
	float buildingsize = 4.5;
	addBuilding(new Building(pos1, buildingsize, buildingsize, RandomFloat(-5, 0), 1, fs, ft));
	float bs1 = RandomFloat(0, 2);
	float bs2 = RandomFloat(2, 3);
	addBuilding(new Building(pos1, buildingsize - bs1, buildingsize - bs1, RandomFloat(0, 5), 1, fs, ft));
	addBuilding(new Building(pos1, buildingsize - bs2, buildingsize - bs2, heightr, 0, fs, ft));

}

void City::GenB9(glm::vec3 pos1, GLchar* fs, GLchar* ft) {

	float heightr = RandomFloat(5, 10);
	float buildingsize = 4.5;
	addBuilding(new Building(pos1, buildingsize, buildingsize, RandomFloat(-5, 2.5), 3, fs, ft));
	float bs1 = RandomFloat(0, 2);
	float bs2 = RandomFloat(2, 3);
	addBuilding(new Building(pos1, buildingsize - bs1, buildingsize - bs1, RandomFloat(2.5, 5), 3, fs, ft));
	addBuilding(new Building(pos1, buildingsize - bs2, buildingsize - bs2, heightr, 0, fs, ft));

}

void City::GenB10(glm::vec3 pos1, GLchar* fs, GLchar* ft) {

	float heightr = RandomFloat(5, 10);
	float buildingsize = 4.5;
	addBuilding(new Building(pos1, buildingsize, buildingsize, RandomFloat(-10, -5), 4, fs, ft));
	float bs1 = RandomFloat(1, 2);
	float bs2 = RandomFloat(2, 3);
	addBuilding(new Building(pos1, buildingsize - bs1, buildingsize - bs1, RandomFloat(0, 5), 1, fs, ft));
	addBuilding(new Building(pos1, buildingsize - bs2, buildingsize - bs2, heightr, 0, fs, ft));

}

void City::GenB11(glm::vec3 pos1, GLchar* fs, GLchar* ft) {

	float heightr = RandomFloat(5, 10);
	float buildingsize = 4.5;
	addBuilding(new Building(pos1, buildingsize, buildingsize, RandomFloat(-10, -5), 4, fs, ft));
	float bs1 = RandomFloat(1, 2);
	float bs2 = RandomFloat(2, 3);
	addBuilding(new Building(pos1, buildingsize - bs1, buildingsize - bs1, RandomFloat(0, 5), 3, fs, ft));
	addBuilding(new Building(pos1, buildingsize - bs2, buildingsize - bs2, heightr, 0, fs, ft));

}

void City::GenB12(glm::vec3 pos1, GLchar* fs, GLchar* ft) {

	float heightr = RandomFloat(5, 10);
	float buildingsize = 4.5;
	float bs0 = RandomFloat(0, 5);
	addBuilding(new Building(pos1, buildingsize, buildingsize, bs0, 5, fs, ft));
	float bs1 = RandomFloat(0.5f, 2.0f);
	float bs2 = RandomFloat(2.0f, 3.0f);
	addBuilding(new Building(pos1, buildingsize - bs1, buildingsize - bs1, bs0, 1, fs, ft));
	addBuilding(new Building(pos1, buildingsize - bs2, buildingsize - bs2, heightr, 0, fs, ft));

}

void City::GenB13(glm::vec3 pos1, GLchar* fs, GLchar* ft) {

	float heightr = RandomFloat(5, 10);
	float buildingsize = 4.5;
	float bs0 = RandomFloat(0, 5);
	addBuilding(new Building(pos1, buildingsize, buildingsize, RandomFloat(-10, -5), 4, fs, ft));
	addBuilding(new Building(pos1, buildingsize, buildingsize, bs0, 5, fs, ft));
	float bs1 = RandomFloat(1, 2);
	float bs2 = RandomFloat(2, 3);
	addBuilding(new Building(pos1, buildingsize - bs1, buildingsize - bs1, bs0, 1, fs, ft));
	addBuilding(new Building(pos1, buildingsize - bs2, buildingsize - bs2, heightr, 0, fs, ft));

}

void City::GenB0(glm::vec3 pos1, GLchar* fs, GLchar* ft) {

	float heightr = RandomFloat(5, 10);
	float buildingsize = 4.5;
	addBuilding(new Building(pos1, buildingsize, buildingsize, heightr,1, fs, ft));

}

void City::BuildingGen(glm::vec3 pos1, GLchar* fs, GLchar* ft){
	int temp = rand() % 14;
	//int temp = 13;
	if (temp == 0) {
		//std::cout << 0 << std::endl;
		GenB0(pos1, fs, ft);
	}
	else if (temp == 1) {
		//std::cout << 1 << std::endl;
		GenB1(pos1, fs, ft);
	}
	else if (temp == 2) {
		//std::cout << 2 << std::endl;
		GenB2(pos1, fs, ft);
	}
	else if (temp == 3) {
		//std::cout << 3 << std::endl;
		GenB3(pos1, fs, ft);
	}
	else if (temp == 4) {
		//std::cout << 4 << std::endl;
		GenB4(pos1, fs, ft);
	}
	else if (temp == 5) {
		//std::cout << 5 << std::endl;
		GenB5(pos1, fs, ft);
	}
	else if (temp == 6) {
		//std::cout << 6 << std::endl;
		GenB6(pos1, fs, ft);
	}
	else if (temp == 7) {
		//std::cout << 7 << std::endl;
		GenB7(pos1, fs, ft);
	}
	else if (temp == 8) {
		//std::cout << 8 << std::endl;
		GenB8(pos1, fs, ft);
	}
	else if (temp == 9) {
		//std::cout << 9 << std::endl;
		GenB9(pos1, fs, ft);
	}
	else if (temp == 10) {
		//std::cout << 10 << std::endl;
		GenB10(pos1, fs, ft);
	}
	else if (temp == 11) {
		//std::cout << 11 << std::endl;
		GenB11(pos1, fs, ft);
	}
	else if (temp == 12) {
		//std::cout << 12 << std::endl;
		GenB12(pos1, fs, ft);
	}
	else if (temp == 13) {
		//std::cout << 13 << std::endl;
		GenB13(pos1, fs, ft);
	}
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
	BuildCity();
}