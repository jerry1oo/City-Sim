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


void City::addBuilding1(std::vector<Building*> BuildingNode) {
	B_Blocks.push_back(BuildingNode);
}

void City::addRoad1(std::vector<Road*> RoadNode) {
	R_Blocks.push_back(RoadNode);
}

void City::addGround(Ground* GroundNode) {
	Grounds.push_back(GroundNode);
}

void City::BuildCity(bool bg, bool tg) {
	B_Blocks.clear();
	R_Blocks.clear();
	Tswitch = tg;
	Gswitch = bg;
	float buildingsize = 4.5;
	float offsetz = 0.5f;
	float offsetx = 0.5f;
	int heightr;

	SF = rand() % 12 + 1;
	//int SF = 1;
	{
		//tile 1
		std::vector<Building*> Buildings1;
		std::vector<Road*> Roads1;
			Roads1.push_back(new Road(glm::vec3(25.0f, 0.0f, 0.0f + 30.0f), 5, 5, "roadPLAZA.png"));
			Roads1.push_back(new Road(glm::vec3(30.0f, 0.0f, 0.0f + 30.0f), 5, 5, "roadPLAZA.png"));
			Roads1.push_back(new Road(glm::vec3(35.0f, 0.0f, 0.0f + 30.0f), 5, 5, "roadPLAZA.png"));

			Roads1.push_back(new Road(glm::vec3(25.0f, 0.0f, 0.0f + 25.0f), 5, 5, "roadPLAZA.png"));
			Roads1.push_back(new Road(glm::vec3(30.0f, 0.0f, 0.0f + 25.0f), 5, 5, "roadPLAZA.png"));
			Roads1.push_back(new Road(glm::vec3(35.0f, 0.0f, 0.0f + 25.0f), 5, 5, "roadPLAZA.png"));

			Roads1.push_back(new Road(glm::vec3(25.0f, 0.0f, 0.0f + 35.0f), 5, 5, "roadPLAZA.png"));
			Roads1.push_back(new Road(glm::vec3(30.0f, 0.0f, 0.0f + 35.0f), 5, 5, "roadPLAZA.png"));
			Roads1.push_back(new Road(glm::vec3(35.0f, 0.0f, 0.0f + 35.0f), 5, 5, "roadPLAZA.png"));
			addRoad1(Roads1);
			GLchar* texside;
			GLchar* textop;
			if (Tswitch) {
				texside = "NightBuilding1_1.jpg";
				textop = "BlackRoof.jpg";
			}
			else {
				int tex = rand() % 3;
				if (tex == 0) {
					int tex1 = rand() % 8 + 1;
					if (tex1 == 1) {
						texside = "NightBuilding1_1.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 2) {
						texside = "NightBuilding1_2.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 3) {
						texside = "NightBuilding1_3.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 4) {
						texside = "NightBuilding1_4.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 5) {
						texside = "NightBuilding1_5.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 6) {
						texside = "NightBuilding1_6.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 7) {
						texside = "NightBuilding1_7.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 8) {
						texside = "NightBuilding1_8.jpg";
						textop = "BlackRoof.jpg";
					}
				}
				else if (tex == 1) {
					int tex1 = rand() % 4 + 1;
					if (tex1 == 1) {
						texside = "NightBuilding1_1.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 2) {
						texside = "NightBuilding1_2.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 3) {
						texside = "NightBuilding1_3.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 4) {
						texside = "NightBuilding1_4.jpg";
						textop = "BlackRoof.jpg";
					}
				}
				else if (tex == 2) {
					int tex1 = rand() % 4 + 1;
					if (tex1 == 1) {
						texside = "NightBuilding3_1.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 2) {
						texside = "NightBuilding3_2.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 3) {
						texside = "NightBuilding3_3.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 4) {
						texside = "NightBuilding3_4.jpg";
						textop = "BlackRoof.jpg";
					}
				}
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
	{
		//tile 2
		std::vector<Building*> Buildings1;
		std::vector<Road*> Roads1;
			Roads1.push_back(new Road(glm::vec3(5.0f, 0.0f, 0.0f + 30.0f), 5, 5, "roadPLAZA.png"));
			Roads1.push_back(new Road(glm::vec3(10.0f, 0.0f, 0.0f + 30.0f), 5, 5, "roadPLAZA.png"));
			Roads1.push_back(new Road(glm::vec3(15.0f, 0.0f, 0.0f + 30.0f), 5, 5, "roadPLAZA.png"));

			Roads1.push_back(new Road(glm::vec3(5.0f, 0.0f, 0.0f + 25.0f), 5, 5, "roadPLAZA.png"));
			Roads1.push_back(new Road(glm::vec3(10.0f, 0.0f, 0.0f + 25.0f), 5, 5, "roadPLAZA.png"));
			Roads1.push_back(new Road(glm::vec3(15.0f, 0.0f, 0.0f + 25.0f), 5, 5, "roadPLAZA.png"));

			Roads1.push_back(new Road(glm::vec3(5.0f, 0.0f, 0.0f + 35.0f), 5, 5, "roadPLAZA.png"));
			Roads1.push_back(new Road(glm::vec3(10.0f, 0.0f, 0.0f + 35.0f), 5, 5, "roadPLAZA.png"));
			Roads1.push_back(new Road(glm::vec3(15.0f, 0.0f, 0.0f + 35.0f), 5, 5, "roadPLAZA.png"));
			addRoad1(Roads1);
			GLchar* texside;
			GLchar* textop;
			if (Tswitch) {
				texside = "NightBuilding1_1.jpg";
				textop = "BlackRoof.jpg";
			}
			else {
				int tex = rand() % 3;
				if (tex == 0) {
					int tex1 = rand() % 8 + 1;
					if (tex1 == 1) {
						texside = "NightBuilding1_1.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 2) {
						texside = "NightBuilding1_2.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 3) {
						texside = "NightBuilding1_3.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 4) {
						texside = "NightBuilding1_4.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 5) {
						texside = "NightBuilding1_5.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 6) {
						texside = "NightBuilding1_6.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 7) {
						texside = "NightBuilding1_7.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 8) {
						texside = "NightBuilding1_8.jpg";
						textop = "BlackRoof.jpg";
					}
				}
				else if (tex == 1) {
					int tex1 = rand() % 4 + 1;
					if (tex1 == 1) {
						texside = "NightBuilding1_1.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 2) {
						texside = "NightBuilding1_2.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 3) {
						texside = "NightBuilding1_3.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 4) {
						texside = "NightBuilding1_4.jpg";
						textop = "BlackRoof.jpg";
					}
				}
				else if (tex == 2) {
					int tex1 = rand() % 4 + 1;
					if (tex1 == 1) {
						texside = "NightBuilding3_1.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 2) {
						texside = "NightBuilding3_2.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 3) {
						texside = "NightBuilding3_3.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 4) {
						texside = "NightBuilding3_4.jpg";
						textop = "BlackRoof.jpg";
					}
				}
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
	{
		// tile 3
		std::vector<Building*> Buildings1;
		std::vector<Road*> Roads1;
			Roads1.push_back(new Road(glm::vec3(-1 * 5.0f, 0.0f, 30.0f), 5, 5, "roadPLAZA.png"));
			Roads1.push_back(new Road(glm::vec3(-1 * 10.0f, 0.0f, 30.0f), 5, 5, "roadPLAZA.png"));
			Roads1.push_back(new Road(glm::vec3(-1 * 15.0f, 0.0f, 30.0f), 5, 5, "roadPLAZA.png"));

			Roads1.push_back(new Road(glm::vec3(-1 * 5.0f, 0.0f, 25.0f), 5, 5, "roadPLAZA.png"));
			Roads1.push_back(new Road(glm::vec3(-1 * 10.0f, 0.0f, 25.0f), 5, 5, "roadPLAZA.png"));
			Roads1.push_back(new Road(glm::vec3(-1 * 15.0f, 0.0f, 25.0f), 5, 5, "roadPLAZA.png"));

			Roads1.push_back(new Road(glm::vec3(-1 * 5.0f, 0.0f, 35.0f), 5, 5, "roadPLAZA.png"));
			Roads1.push_back(new Road(glm::vec3(-1 * 10.0f, 0.0f, 35.0f), 5, 5, "roadPLAZA.png"));
			Roads1.push_back(new Road(glm::vec3(-1 * 15.0f, 0.0f, 35.0f), 5, 5, "roadPLAZA.png"));
			addRoad1(Roads1);
			GLchar* texside;
			GLchar* textop;
			if (Tswitch) {
				texside = "NightBuilding1_1.jpg";
				textop = "BlackRoof.jpg";
			}
			else {
				int tex = rand() % 3;
				if (tex == 0) {
					int tex1 = rand() % 8 + 1;
					if (tex1 == 1) {
						texside = "NightBuilding1_1.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 2) {
						texside = "NightBuilding1_2.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 3) {
						texside = "NightBuilding1_3.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 4) {
						texside = "NightBuilding1_4.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 5) {
						texside = "NightBuilding1_5.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 6) {
						texside = "NightBuilding1_6.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 7) {
						texside = "NightBuilding1_7.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 8) {
						texside = "NightBuilding1_8.jpg";
						textop = "BlackRoof.jpg";
					}
				}
				else if (tex == 1) {
					int tex1 = rand() % 4 + 1;
					if (tex1 == 1) {
						texside = "NightBuilding1_1.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 2) {
						texside = "NightBuilding1_2.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 3) {
						texside = "NightBuilding1_3.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 4) {
						texside = "NightBuilding1_4.jpg";
						textop = "BlackRoof.jpg";
					}
				}
				else if (tex == 2) {
					int tex1 = rand() % 4 + 1;
					if (tex1 == 1) {
						texside = "NightBuilding3_1.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 2) {
						texside = "NightBuilding3_2.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 3) {
						texside = "NightBuilding3_3.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 4) {
						texside = "NightBuilding3_4.jpg";
						textop = "BlackRoof.jpg";
					}
				}
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
	{
		//tile 4
		std::vector<Building*> Buildings1;
		std::vector<Road*> Roads1;
			Roads1.push_back(new Road(glm::vec3(-1 * 25.0f, 0.0f, 30.0f), 5, 5, "roadPLAZA.png"));
			Roads1.push_back(new Road(glm::vec3(-1 * 30.0f, 0.0f, 30.0f), 5, 5, "roadPLAZA.png"));
			Roads1.push_back(new Road(glm::vec3(-1 * 35.0f, 0.0f, 30.0f), 5, 5, "roadPLAZA.png"));

			Roads1.push_back(new Road(glm::vec3(-1 * 25.0f, 0.0f, 25.0f), 5, 5, "roadPLAZA.png"));
			Roads1.push_back(new Road(glm::vec3(-1 * 30.0f, 0.0f, 25.0f), 5, 5, "roadPLAZA.png"));
			Roads1.push_back(new Road(glm::vec3(-1 * 35.0f, 0.0f, 25.0f), 5, 5, "roadPLAZA.png"));

			Roads1.push_back(new Road(glm::vec3(-1 * 25.0f, 0.0f, 35.0f), 5, 5, "roadPLAZA.png"));
			Roads1.push_back(new Road(glm::vec3(-1 * 30.0f, 0.0f, 35.0f), 5, 5, "roadPLAZA.png"));
			Roads1.push_back(new Road(glm::vec3(-1 * 35.0f, 0.0f, 35.0f), 5, 5, "roadPLAZA.png"));
			addRoad1(Roads1);
			GLchar* texside;
			GLchar* textop;
			if (Tswitch) {
				texside = "NightBuilding1_1.jpg";
				textop = "BlackRoof.jpg";
			}
			else {
				int tex = rand() % 3;
				if (tex == 0) {
					int tex1 = rand() % 8 + 1;
					if (tex1 == 1) {
						texside = "NightBuilding1_1.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 2) {
						texside = "NightBuilding1_2.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 3) {
						texside = "NightBuilding1_3.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 4) {
						texside = "NightBuilding1_4.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 5) {
						texside = "NightBuilding1_5.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 6) {
						texside = "NightBuilding1_6.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 7) {
						texside = "NightBuilding1_7.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 8) {
						texside = "NightBuilding1_8.jpg";
						textop = "BlackRoof.jpg";
					}
				}
				else if (tex == 1) {
					int tex1 = rand() % 4 + 1;
					if (tex1 == 1) {
						texside = "NightBuilding1_1.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 2) {
						texside = "NightBuilding1_2.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 3) {
						texside = "NightBuilding1_3.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 4) {
						texside = "NightBuilding1_4.jpg";
						textop = "BlackRoof.jpg";
					}
				}
				else if (tex == 2) {
					int tex1 = rand() % 4 + 1;
					if (tex1 == 1) {
						texside = "NightBuilding3_1.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 2) {
						texside = "NightBuilding3_2.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 3) {
						texside = "NightBuilding3_3.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 4) {
						texside = "NightBuilding3_4.jpg";
						textop = "BlackRoof.jpg";
					}
				}
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
	{
		//tile5
		std::vector<Building*> Buildings1;
		std::vector<Road*> Roads1;
			Roads1.push_back(new Road(glm::vec3(30.0f, 0.0f, 5.0f), 5, 5, "roadPLAZA.png"));
			Roads1.push_back(new Road(glm::vec3(30.0f, 0.0f, 10.0f), 5, 5, "roadPLAZA.png"));
			Roads1.push_back(new Road(glm::vec3(30.0f, 0.0f, 15.0f), 5, 5, "roadPLAZA.png"));

			Roads1.push_back(new Road(glm::vec3(25.0f, 0.0f, 5.0f), 5, 5, "roadPLAZA.png"));
			Roads1.push_back(new Road(glm::vec3(25.0f, 0.0f, 10.0f), 5, 5, "roadPLAZA.png"));
			Roads1.push_back(new Road(glm::vec3(25.0f, 0.0f, 15.0f), 5, 5, "roadPLAZA.png"));

			Roads1.push_back(new Road(glm::vec3(35.0f, 0.0f, 5.0f), 5, 5, "roadPLAZA.png"));
			Roads1.push_back(new Road(glm::vec3(35.0f, 0.0f, 10.0f), 5, 5, "roadPLAZA.png"));
			Roads1.push_back(new Road(glm::vec3(35.0f, 0.0f, 15.0f), 5, 5, "roadPLAZA.png"));
			addRoad1(Roads1);
			GLchar* texside;
			GLchar* textop;
			if (Tswitch) {
				texside = "NightBuilding1_1.jpg";
				textop = "BlackRoof.jpg";
			}
			else {
				int tex = rand() % 3;
				if (tex == 0) {
					int tex1 = rand() % 8 + 1;
					if (tex1 == 1) {
						texside = "NightBuilding1_1.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 2) {
						texside = "NightBuilding1_2.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 3) {
						texside = "NightBuilding1_3.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 4) {
						texside = "NightBuilding1_4.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 5) {
						texside = "NightBuilding1_5.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 6) {
						texside = "NightBuilding1_6.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 7) {
						texside = "NightBuilding1_7.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 8) {
						texside = "NightBuilding1_8.jpg";
						textop = "BlackRoof.jpg";
					}
				}
				else if (tex == 1) {
					int tex1 = rand() % 4 + 1;
					if (tex1 == 1) {
						texside = "NightBuilding1_1.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 2) {
						texside = "NightBuilding1_2.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 3) {
						texside = "NightBuilding1_3.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 4) {
						texside = "NightBuilding1_4.jpg";
						textop = "BlackRoof.jpg";
					}
				}
				else if (tex == 2) {
					int tex1 = rand() % 4 + 1;
					if (tex1 == 1) {
						texside = "NightBuilding3_1.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 2) {
						texside = "NightBuilding3_2.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 3) {
						texside = "NightBuilding3_3.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 4) {
						texside = "NightBuilding3_4.jpg";
						textop = "BlackRoof.jpg";
					}
				}
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
	{
		//tile 6
		std::vector<Building*> Buildings1;
		std::vector<Road*> Roads1;
			Roads1.push_back(new Road(glm::vec3(10.0f, 0.0f, 5.0), 5, 5, "roadPLAZA.png"));
			Roads1.push_back(new Road(glm::vec3(10.0f, 0.0f, 10.0), 5, 5, "roadPLAZA.png"));
			Roads1.push_back(new Road(glm::vec3(10.0f, 0.0f, 15.0), 5, 5, "roadPLAZA.png"));

			Roads1.push_back(new Road(glm::vec3(5.0f, 0.0f, 5.0), 5, 5, "roadPLAZA.png"));
			Roads1.push_back(new Road(glm::vec3(5.0f, 0.0f, 10.0), 5, 5, "roadPLAZA.png"));
			Roads1.push_back(new Road(glm::vec3(5.0f, 0.0f, 15.0), 5, 5, "roadPLAZA.png"));

			Roads1.push_back(new Road(glm::vec3(15.0f, 0.0f, 5.0), 5, 5, "roadPLAZA.png"));
			Roads1.push_back(new Road(glm::vec3(15.0f, 0.0f, 10.0), 5, 5, "roadPLAZA.png"));
			Roads1.push_back(new Road(glm::vec3(15.0f, 0.0f, 15.0), 5, 5, "roadPLAZA.png"));
			addRoad1(Roads1);
			GLchar* texside;
			GLchar* textop;
			if (Tswitch) {
				texside = "NightBuilding1_1.jpg";
				textop = "BlackRoof.jpg";
			}
			else {
				int tex = rand() % 3;
				if (tex == 0) {
					int tex1 = rand() % 8 + 1;
					if (tex1 == 1) {
						texside = "NightBuilding1_1.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 2) {
						texside = "NightBuilding1_2.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 3) {
						texside = "NightBuilding1_3.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 4) {
						texside = "NightBuilding1_4.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 5) {
						texside = "NightBuilding1_5.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 6) {
						texside = "NightBuilding1_6.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 7) {
						texside = "NightBuilding1_7.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 8) {
						texside = "NightBuilding1_8.jpg";
						textop = "BlackRoof.jpg";
					}
				}
				else if (tex == 1) {
					int tex1 = rand() % 4 + 1;
					if (tex1 == 1) {
						texside = "NightBuilding1_1.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 2) {
						texside = "NightBuilding1_2.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 3) {
						texside = "NightBuilding1_3.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 4) {
						texside = "NightBuilding1_4.jpg";
						textop = "BlackRoof.jpg";
					}
				}
				else if (tex == 2) {
					int tex1 = rand() % 4 + 1;
					if (tex1 == 1) {
						texside = "NightBuilding3_1.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 2) {
						texside = "NightBuilding3_2.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 3) {
						texside = "NightBuilding3_3.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 4) {
						texside = "NightBuilding3_4.jpg";
						textop = "BlackRoof.jpg";
					}
				}
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
	{
		//tile 7
		std::vector<Building*> Buildings1;
		std::vector<Road*> Roads1;
			Roads1.push_back(new Road(glm::vec3(-1 * 10.0f, 0.0f, 5.0f), 5, 5, "roadPLAZA.png"));			
			Roads1.push_back(new Road(glm::vec3(-1 * 10.0f, 0.0f, 10.0f), 5, 5, "roadPLAZA.png"));			
			Roads1.push_back(new Road(glm::vec3(-1 * 10.0f, 0.0f, 15.0f), 5, 5, "roadPLAZA.png"));
			
			Roads1.push_back(new Road(glm::vec3(-1 * 5.0f, 0.0f, 5.0f), 5, 5, "roadPLAZA.png"));			
			Roads1.push_back(new Road(glm::vec3(-1 * 5.0f, 0.0f, 10.0f), 5, 5, "roadPLAZA.png"));			
			Roads1.push_back(new Road(glm::vec3(-1 * 5.0f, 0.0f, 15.0f), 5, 5, "roadPLAZA.png"));
			
			Roads1.push_back(new Road(glm::vec3(-1 * 15.0f, 0.0f, 5.0f), 5, 5, "roadPLAZA.png"));			
			Roads1.push_back(new Road(glm::vec3(-1 * 15.0f, 0.0f, 10.0f), 5, 5, "roadPLAZA.png"));			
			Roads1.push_back(new Road(glm::vec3(-1 * 15.0f, 0.0f, 15.0f), 5, 5, "roadPLAZA.png"));
			addRoad1(Roads1);
			GLchar* texside;
			GLchar* textop;
			if (Tswitch) {
				texside = "NightBuilding1_1.jpg";
				textop = "BlackRoof.jpg";
			}
			else {
				int tex = rand() % 3;
				if (tex == 0) {
					int tex1 = rand() % 8 + 1;
					if (tex1 == 1) {
						texside = "NightBuilding1_1.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 2) {
						texside = "NightBuilding1_2.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 3) {
						texside = "NightBuilding1_3.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 4) {
						texside = "NightBuilding1_4.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 5) {
						texside = "NightBuilding1_5.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 6) {
						texside = "NightBuilding1_6.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 7) {
						texside = "NightBuilding1_7.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 8) {
						texside = "NightBuilding1_8.jpg";
						textop = "BlackRoof.jpg";
					}
				}
				else if (tex == 1) {
					int tex1 = rand() % 4 + 1;
					if (tex1 == 1) {
						texside = "NightBuilding1_1.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 2) {
						texside = "NightBuilding1_2.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 3) {
						texside = "NightBuilding1_3.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 4) {
						texside = "NightBuilding1_4.jpg";
						textop = "BlackRoof.jpg";
					}
				}
				else if (tex == 2) {
					int tex1 = rand() % 4 + 1;
					if (tex1 == 1) {
						texside = "NightBuilding3_1.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 2) {
						texside = "NightBuilding3_2.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 3) {
						texside = "NightBuilding3_3.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 4) {
						texside = "NightBuilding3_4.jpg";
						textop = "BlackRoof.jpg";
					}
				}
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
	{
		//tile 8
		std::vector<Building*> Buildings1;
		std::vector<Road*> Roads1;
			Roads1.push_back(new Road(glm::vec3(-1 * 30.0f, 0.0f, 5.0f), 5, 5, "roadPLAZA.png"));
			Roads1.push_back(new Road(glm::vec3(-1 * 30.0f, 0.0f, 10.0f), 5, 5, "roadPLAZA.png"));
			Roads1.push_back(new Road(glm::vec3(-1 * 30.0f, 0.0f, 15.0f), 5, 5, "roadPLAZA.png"));

			Roads1.push_back(new Road(glm::vec3(-1 * 25.0f, 0.0f, 5.0f), 5, 5, "roadPLAZA.png"));
			Roads1.push_back(new Road(glm::vec3(-1 * 25.0f, 0.0f, 10.0f), 5, 5, "roadPLAZA.png"));
			Roads1.push_back(new Road(glm::vec3(-1 * 25.0f, 0.0f, 15.0f), 5, 5, "roadPLAZA.png"));

			Roads1.push_back(new Road(glm::vec3(-1 * 35.0f, 0.0f, 5.0f), 5, 5, "roadPLAZA.png"));
			Roads1.push_back(new Road(glm::vec3(-1 * 35.0f, 0.0f, 10.0f), 5, 5, "roadPLAZA.png"));
			Roads1.push_back(new Road(glm::vec3(-1 * 35.0f, 0.0f, 15.0f), 5, 5, "roadPLAZA.png"));

			GLchar* texside;
			GLchar* textop;
			if (Tswitch) {
				texside = "NightBuilding1_1.jpg";
				textop = "BlackRoof.jpg";
			}
			else {
				int tex = rand() % 3;
				if (tex == 0) {
					int tex1 = rand() % 8 + 1;
					if (tex1 == 1) {
						texside = "NightBuilding1_1.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 2) {
						texside = "NightBuilding1_2.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 3) {
						texside = "NightBuilding1_3.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 4) {
						texside = "NightBuilding1_4.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 5) {
						texside = "NightBuilding1_5.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 6) {
						texside = "NightBuilding1_6.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 7) {
						texside = "NightBuilding1_7.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 8) {
						texside = "NightBuilding1_8.jpg";
						textop = "BlackRoof.jpg";
					}
				}
				else if (tex == 1) {
					int tex1 = rand() % 4 + 1;
					if (tex1 == 1) {
						texside = "NightBuilding1_1.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 2) {
						texside = "NightBuilding1_2.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 3) {
						texside = "NightBuilding1_3.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 4) {
						texside = "NightBuilding1_4.jpg";
						textop = "BlackRoof.jpg";
					}
				}
				else if (tex == 2) {
					int tex1 = rand() % 4 + 1;
					if (tex1 == 1) {
						texside = "NightBuilding3_1.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 2) {
						texside = "NightBuilding3_2.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 3) {
						texside = "NightBuilding3_3.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 4) {
						texside = "NightBuilding3_4.jpg";
						textop = "BlackRoof.jpg";
					}
				}
			}
			addRoad1(Roads1);
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
	{		
		//tile 9
		std::vector<Building*> Buildings1;
		std::vector<Road*> Roads1;
			Roads1.push_back(new Road(glm::vec3(30.0f, 0.0f, -1 * 5.0f), 5, 5, "roadPLAZA.png"));
			Roads1.push_back(new Road(glm::vec3(30.0f, 0.0f, -1 * 10.0f), 5, 5, "roadPLAZA.png"));
			Roads1.push_back(new Road(glm::vec3(30.0f, 0.0f, -1 * 15.0f), 5, 5, "roadPLAZA.png"));

			Roads1.push_back(new Road(glm::vec3(25.0f, 0.0f, -1 * 5.0f), 5, 5, "roadPLAZA.png"));
			Roads1.push_back(new Road(glm::vec3(25.0f, 0.0f, -1 * 10.0f), 5, 5, "roadPLAZA.png"));
			Roads1.push_back(new Road(glm::vec3(25.0f, 0.0f, -1 * 15.0f), 5, 5, "roadPLAZA.png"));

			Roads1.push_back(new Road(glm::vec3(35.0f, 0.0f, -1 * 5.0f), 5, 5, "roadPLAZA.png"));
			Roads1.push_back(new Road(glm::vec3(35.0f, 0.0f, -1 * 10.0f), 5, 5, "roadPLAZA.png"));
			Roads1.push_back(new Road(glm::vec3(35.0f, 0.0f, -1 * 15.0f), 5, 5, "roadPLAZA.png"));
			addRoad1(Roads1);
			GLchar* texside;
			GLchar* textop;
			if (Tswitch) {
				texside = "NightBuilding1_1.jpg";
				textop = "BlackRoof.jpg";
			}
			else {
				int tex = rand() % 3;
				if (tex == 0) {
					int tex1 = rand() % 8 + 1;
					if (tex1 == 1) {
						texside = "NightBuilding1_1.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 2) {
						texside = "NightBuilding1_2.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 3) {
						texside = "NightBuilding1_3.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 4) {
						texside = "NightBuilding1_4.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 5) {
						texside = "NightBuilding1_5.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 6) {
						texside = "NightBuilding1_6.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 7) {
						texside = "NightBuilding1_7.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 8) {
						texside = "NightBuilding1_8.jpg";
						textop = "BlackRoof.jpg";
					}
				}
				else if (tex == 1) {
					int tex1 = rand() % 4 + 1;
					if (tex1 == 1) {
						texside = "NightBuilding1_1.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 2) {
						texside = "NightBuilding1_2.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 3) {
						texside = "NightBuilding1_3.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 4) {
						texside = "NightBuilding1_4.jpg";
						textop = "BlackRoof.jpg";
					}
				}
				else if (tex == 2) {
					int tex1 = rand() % 4 + 1;
					if (tex1 == 1) {
						texside = "NightBuilding3_1.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 2) {
						texside = "NightBuilding3_2.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 3) {
						texside = "NightBuilding3_3.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 4) {
						texside = "NightBuilding3_4.jpg";
						textop = "BlackRoof.jpg";
					}
				}
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
	{
		//tile 10
		std::vector<Building*> Buildings1;
		std::vector<Road*> Roads1;
			Roads1.push_back(new Road(glm::vec3(10.0f, 0.0f, -1 * 5.0), 5, 5, "roadPLAZA.png"));
			Roads1.push_back(new Road(glm::vec3(10.0f, 0.0f, -1 * 10.0), 5, 5, "roadPLAZA.png"));
			Roads1.push_back(new Road(glm::vec3(10.0f, 0.0f, -1 * 15.0), 5, 5, "roadPLAZA.png"));

			Roads1.push_back(new Road(glm::vec3(5.0f, 0.0f, -1 * 5.0), 5, 5, "roadPLAZA.png"));
			Roads1.push_back(new Road(glm::vec3(5.0f, 0.0f, -1 * 10.0), 5, 5, "roadPLAZA.png"));
			Roads1.push_back(new Road(glm::vec3(5.0f, 0.0f, -1 * 15.0), 5, 5, "roadPLAZA.png"));

			Roads1.push_back(new Road(glm::vec3(15.0f, 0.0f, -1 * 5.0), 5, 5, "roadPLAZA.png"));
			Roads1.push_back(new Road(glm::vec3(15.0f, 0.0f, -1 * 10.0), 5, 5, "roadPLAZA.png"));
			Roads1.push_back(new Road(glm::vec3(15.0f, 0.0f, -1 * 15.0), 5, 5, "roadPLAZA.png"));
			addRoad1(Roads1);
			GLchar* texside;
			GLchar* textop;
			if (Tswitch) {
				texside = "NightBuilding1_1.jpg";
				textop = "BlackRoof.jpg";
			}
			else {
				int tex = rand() % 3;
				if (tex == 0) {
					int tex1 = rand() % 8 + 1;
					if (tex1 == 1) {
						texside = "NightBuilding1_1.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 2) {
						texside = "NightBuilding1_2.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 3) {
						texside = "NightBuilding1_3.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 4) {
						texside = "NightBuilding1_4.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 5) {
						texside = "NightBuilding1_5.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 6) {
						texside = "NightBuilding1_6.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 7) {
						texside = "NightBuilding1_7.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 8) {
						texside = "NightBuilding1_8.jpg";
						textop = "BlackRoof.jpg";
					}
				}
				else if (tex == 1) {
					int tex1 = rand() % 4 + 1;
					if (tex1 == 1) {
						texside = "NightBuilding1_1.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 2) {
						texside = "NightBuilding1_2.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 3) {
						texside = "NightBuilding1_3.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 4) {
						texside = "NightBuilding1_4.jpg";
						textop = "BlackRoof.jpg";
					}
				}
				else if (tex == 2) {
					int tex1 = rand() % 4 + 1;
					if (tex1 == 1) {
						texside = "NightBuilding3_1.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 2) {
						texside = "NightBuilding3_2.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 3) {
						texside = "NightBuilding3_3.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 4) {
						texside = "NightBuilding3_4.jpg";
						textop = "BlackRoof.jpg";
					}
				}
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
	{
		//tile 11
		std::vector<Building*> Buildings1;
		std::vector<Road*> Roads1;
			Roads1.push_back(new Road(glm::vec3(-1 * 10.0f, 0.0f, -1 * 5.0f), 5, 5, "roadPLAZA.png"));
			Roads1.push_back(new Road(glm::vec3(-1 * 10.0f, 0.0f, -1 * 10.0f), 5, 5, "roadPLAZA.png"));
			Roads1.push_back(new Road(glm::vec3(-1 * 10.0f, 0.0f, -1 * 15.0f), 5, 5, "roadPLAZA.png"));

			Roads1.push_back(new Road(glm::vec3(-1 * 5.0f, 0.0f, -1 * 5.0f), 5, 5, "roadPLAZA.png"));
			Roads1.push_back(new Road(glm::vec3(-1 * 5.0f, 0.0f, -1 * 10.0f), 5, 5, "roadPLAZA.png"));
			Roads1.push_back(new Road(glm::vec3(-1 * 5.0f, 0.0f, -1 * 15.0f), 5, 5, "roadPLAZA.png"));

			Roads1.push_back(new Road(glm::vec3(-1 * 15.0f, 0.0f, -1 * 5.0f), 5, 5, "roadPLAZA.png"));
			Roads1.push_back(new Road(glm::vec3(-1 * 15.0f, 0.0f, -1 * 10.0f), 5, 5, "roadPLAZA.png"));
			Roads1.push_back(new Road(glm::vec3(-1 * 15.0f, 0.0f, -1 * 15.0f), 5, 5, "roadPLAZA.png"));
			addRoad1(Roads1);
			GLchar* texside;
			GLchar* textop;
			if (Tswitch) {
				texside = "NightBuilding1_1.jpg";
				textop = "BlackRoof.jpg";
			}
			else {
				int tex = rand() % 3;
				if (tex == 0) {
					int tex1 = rand() % 8 + 1;
					if (tex1 == 1) {
						texside = "NightBuilding1_1.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 2) {
						texside = "NightBuilding1_2.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 3) {
						texside = "NightBuilding1_3.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 4) {
						texside = "NightBuilding1_4.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 5) {
						texside = "NightBuilding1_5.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 6) {
						texside = "NightBuilding1_6.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 7) {
						texside = "NightBuilding1_7.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 8) {
						texside = "NightBuilding1_8.jpg";
						textop = "BlackRoof.jpg";
					}
				}
				else if (tex == 1) {
					int tex1 = rand() % 4 + 1;
					if (tex1 == 1) {
						texside = "NightBuilding1_1.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 2) {
						texside = "NightBuilding1_2.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 3) {
						texside = "NightBuilding1_3.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 4) {
						texside = "NightBuilding1_4.jpg";
						textop = "BlackRoof.jpg";
					}
				}
				else if (tex == 2) {
					int tex1 = rand() % 4 + 1;
					if (tex1 == 1) {
						texside = "NightBuilding3_1.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 2) {
						texside = "NightBuilding3_2.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 3) {
						texside = "NightBuilding3_3.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 4) {
						texside = "NightBuilding3_4.jpg";
						textop = "BlackRoof.jpg";
					}
				}
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
	{
		//tile 12
		std::vector<Building*> Buildings1;
		std::vector<Road*> Roads1;
			Roads1.push_back(new Road(glm::vec3(-1 * 30.0f, 0.0f, -1 * 5.0f), 5, 5, "roadPLAZA.png"));
			Roads1.push_back(new Road(glm::vec3(-1 * 30.0f, 0.0f, -1 * 10.0f), 5, 5, "roadPLAZA.png"));
			Roads1.push_back(new Road(glm::vec3(-1 * 30.0f, 0.0f, -1 * 15.0f), 5, 5, "roadPLAZA.png"));

			Roads1.push_back(new Road(glm::vec3(-1 * 25.0f, 0.0f, -1 * 5.0f), 5, 5, "roadPLAZA.png"));
			Roads1.push_back(new Road(glm::vec3(-1 * 25.0f, 0.0f, -1 * 10.0f), 5, 5, "roadPLAZA.png"));
			Roads1.push_back(new Road(glm::vec3(-1 * 25.0f, 0.0f, -1 * 15.0f), 5, 5, "roadPLAZA.png"));

			Roads1.push_back(new Road(glm::vec3(-1 * 35.0f, 0.0f, -1 * 5.0f), 5, 5, "roadPLAZA.png"));
			Roads1.push_back(new Road(glm::vec3(-1 * 35.0f, 0.0f, -1 * 10.0f), 5, 5, "roadPLAZA.png"));
			Roads1.push_back(new Road(glm::vec3(-1 * 35.0f, 0.0f, -1 * 15.0f), 5, 5, "roadPLAZA.png"));
			addRoad1(Roads1);
			GLchar* texside;
			GLchar* textop;
			if (Tswitch) {
				texside = "NightBuilding1_1.jpg";
				textop = "BlackRoof.jpg";
			}
			else {
				int tex = rand() % 3;
				if (tex == 0) {
					int tex1 = rand() % 8 + 1;
					if (tex1 == 1) {
						texside = "NightBuilding1_1.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 2) {
						texside = "NightBuilding1_2.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 3) {
						texside = "NightBuilding1_3.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 4) {
						texside = "NightBuilding1_4.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 5) {
						texside = "NightBuilding1_5.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 6) {
						texside = "NightBuilding1_6.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 7) {
						texside = "NightBuilding1_7.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 8) {
						texside = "NightBuilding1_8.jpg";
						textop = "BlackRoof.jpg";
					}
				}
				else if (tex == 1) {
					int tex1 = rand() % 4 + 1;
					if (tex1 == 1) {
						texside = "NightBuilding1_1.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 2) {
						texside = "NightBuilding1_2.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 3) {
						texside = "NightBuilding1_3.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 4) {
						texside = "NightBuilding1_4.jpg";
						textop = "BlackRoof.jpg";
					}
				}
				else if (tex == 2) {
					int tex1 = rand() % 4 + 1;
					if (tex1 == 1) {
						texside = "NightBuilding3_1.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 2) {
						texside = "NightBuilding3_2.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 3) {
						texside = "NightBuilding3_3.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 4) {
						texside = "NightBuilding3_4.jpg";
						textop = "BlackRoof.jpg";
					}
				}
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
	{
		//tile 13
		std::vector<Building*> Buildings1;
		std::vector<Road*> Roads1;
			Roads1.push_back(new Road(glm::vec3(25.0f, 0.0f, -1 * 30.0f), 5, 5, "roadPLAZA.png"));
			Roads1.push_back(new Road(glm::vec3(30.0f, 0.0f, -1 * 30.0f), 5, 5, "roadPLAZA.png"));
			Roads1.push_back(new Road(glm::vec3(35.0f, 0.0f, -1 * 30.0f), 5, 5, "roadPLAZA.png"));

			Roads1.push_back(new Road(glm::vec3(25.0f, 0.0f, -1 * 25.0f), 5, 5, "roadPLAZA.png"));
			Roads1.push_back(new Road(glm::vec3(30.0f, 0.0f, -1 * 25.0f), 5, 5, "roadPLAZA.png"));
			Roads1.push_back(new Road(glm::vec3(35.0f, 0.0f, -1 * 25.0f), 5, 5, "roadPLAZA.png"));

			Roads1.push_back(new Road(glm::vec3(25.0f, 0.0f, -1 * 35.0f), 5, 5, "roadPLAZA.png"));
			Roads1.push_back(new Road(glm::vec3(30.0f, 0.0f, -1 * 35.0f), 5, 5, "roadPLAZA.png"));
			Roads1.push_back(new Road(glm::vec3(35.0f, 0.0f, -1 * 35.0f), 5, 5, "roadPLAZA.png"));
			addRoad1(Roads1);
			GLchar* texside;
			GLchar* textop;
			if (Tswitch) {
				texside = "NightBuilding1_1.jpg";
				textop = "BlackRoof.jpg";
			}
			else {
				int tex = rand() % 3;
				if (tex == 0) {
					int tex1 = rand() % 8 + 1;
					if (tex1 == 1) {
						texside = "NightBuilding1_1.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 2) {
						texside = "NightBuilding1_2.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 3) {
						texside = "NightBuilding1_3.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 4) {
						texside = "NightBuilding1_4.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 5) {
						texside = "NightBuilding1_5.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 6) {
						texside = "NightBuilding1_6.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 7) {
						texside = "NightBuilding1_7.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 8) {
						texside = "NightBuilding1_8.jpg";
						textop = "BlackRoof.jpg";
					}
				}
				else if (tex == 1) {
					int tex1 = rand() % 4 + 1;
					if (tex1 == 1) {
						texside = "NightBuilding1_1.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 2) {
						texside = "NightBuilding1_2.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 3) {
						texside = "NightBuilding1_3.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 4) {
						texside = "NightBuilding1_4.jpg";
						textop = "BlackRoof.jpg";
					}
				}
				else if (tex == 2) {
					int tex1 = rand() % 4 + 1;
					if (tex1 == 1) {
						texside = "NightBuilding3_1.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 2) {
						texside = "NightBuilding3_2.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 3) {
						texside = "NightBuilding3_3.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 4) {
						texside = "NightBuilding3_4.jpg";
						textop = "BlackRoof.jpg";
					}
				}
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
	{
		//tile 14
		std::vector<Building*> Buildings1;
		std::vector<Road*> Roads1;
			Roads1.push_back(new Road(glm::vec3(5.0f, 0.0f, -1 * 30.0f), 5, 5, "roadPLAZA.png"));
			Roads1.push_back(new Road(glm::vec3(10.0f, 0.0f, -1 * 30.0f), 5, 5, "roadPLAZA.png"));
			Roads1.push_back(new Road(glm::vec3(15.0f, 0.0f, -1 * 30.0f), 5, 5, "roadPLAZA.png"));

			Roads1.push_back(new Road(glm::vec3(5.0f, 0.0f, -1 * 25.0f), 5, 5, "roadPLAZA.png"));
			Roads1.push_back(new Road(glm::vec3(10.0f, 0.0f, -1 * 25.0f), 5, 5, "roadPLAZA.png"));
			Roads1.push_back(new Road(glm::vec3(15.0f, 0.0f, -1 * 25.0f), 5, 5, "roadPLAZA.png"));

			Roads1.push_back(new Road(glm::vec3(5.0f, 0.0f, -1 * 35.0f), 5, 5, "roadPLAZA.png"));
			Roads1.push_back(new Road(glm::vec3(10.0f, 0.0f, -1 * 35.0f), 5, 5, "roadPLAZA.png"));
			Roads1.push_back(new Road(glm::vec3(15.0f, 0.0f, -1 * 35.0f), 5, 5, "roadPLAZA.png"));
			addRoad1(Roads1);
			GLchar* texside;
			GLchar* textop;
			if (Tswitch) {
				texside = "NightBuilding1_1.jpg";
				textop = "BlackRoof.jpg";
			}
			else {
				int tex = rand() % 3;
				if (tex == 0) {
					int tex1 = rand() % 8 + 1;
					if (tex1 == 1) {
						texside = "NightBuilding1_1.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 2) {
						texside = "NightBuilding1_2.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 3) {
						texside = "NightBuilding1_3.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 4) {
						texside = "NightBuilding1_4.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 5) {
						texside = "NightBuilding1_5.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 6) {
						texside = "NightBuilding1_6.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 7) {
						texside = "NightBuilding1_7.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 8) {
						texside = "NightBuilding1_8.jpg";
						textop = "BlackRoof.jpg";
					}
				}
				else if (tex == 1) {
					int tex1 = rand() % 4 + 1;
					if (tex1 == 1) {
						texside = "NightBuilding1_1.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 2) {
						texside = "NightBuilding1_2.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 3) {
						texside = "NightBuilding1_3.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 4) {
						texside = "NightBuilding1_4.jpg";
						textop = "BlackRoof.jpg";
					}
				}
				else if (tex == 2) {
					int tex1 = rand() % 4 + 1;
					if (tex1 == 1) {
						texside = "NightBuilding3_1.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 2) {
						texside = "NightBuilding3_2.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 3) {
						texside = "NightBuilding3_3.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 4) {
						texside = "NightBuilding3_4.jpg";
						textop = "BlackRoof.jpg";
					}
				}
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
	{
		//tile 15
		std::vector<Building*> Buildings1;
		std::vector<Road*> Roads1;
			Roads1.push_back(new Road(glm::vec3(-1 * 5.0f, 0.0f, -1 * 30.0f), 5, 5, "roadPLAZA.png"));
			Roads1.push_back(new Road(glm::vec3(-1 * 10.0f, 0.0f, -1 * 30.0f), 5, 5, "roadPLAZA.png"));
			Roads1.push_back(new Road(glm::vec3(-1 * 15.0f, 0.0f, -1 * 30.0f), 5, 5, "roadPLAZA.png"));

			Roads1.push_back(new Road(glm::vec3(-1 * 5.0f, 0.0f, -1 * 25.0f), 5, 5, "roadPLAZA.png"));
			Roads1.push_back(new Road(glm::vec3(-1 * 10.0f, 0.0f, -1 * 25.0f), 5, 5, "roadPLAZA.png"));
			Roads1.push_back(new Road(glm::vec3(-1 * 15.0f, 0.0f, -1 * 25.0f), 5, 5, "roadPLAZA.png"));

			Roads1.push_back(new Road(glm::vec3(-1 * 5.0f, 0.0f, -1 * 35.0f), 5, 5, "roadPLAZA.png"));
			Roads1.push_back(new Road(glm::vec3(-1 * 10.0f, 0.0f, -1 * 35.0f), 5, 5, "roadPLAZA.png"));
			Roads1.push_back(new Road(glm::vec3(-1 * 15.0f, 0.0f, -1 * 35.0f), 5, 5, "roadPLAZA.png"));
			addRoad1(Roads1);
			GLchar* texside;
			GLchar* textop;
			if (Tswitch) {
				texside = "NightBuilding1_1.jpg";
				textop = "BlackRoof.jpg";
			}
			else {
				int tex = rand() % 3;
				if (tex == 0) {
					int tex1 = rand() % 8 + 1;
					if (tex1 == 1) {
						texside = "NightBuilding1_1.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 2) {
						texside = "NightBuilding1_2.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 3) {
						texside = "NightBuilding1_3.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 4) {
						texside = "NightBuilding1_4.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 5) {
						texside = "NightBuilding1_5.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 6) {
						texside = "NightBuilding1_6.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 7) {
						texside = "NightBuilding1_7.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 8) {
						texside = "NightBuilding1_8.jpg";
						textop = "BlackRoof.jpg";
					}
				}
				else if (tex == 1) {
					int tex1 = rand() % 4 + 1;
					if (tex1 == 1) {
						texside = "NightBuilding1_1.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 2) {
						texside = "NightBuilding1_2.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 3) {
						texside = "NightBuilding1_3.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 4) {
						texside = "NightBuilding1_4.jpg";
						textop = "BlackRoof.jpg";
					}
				}
				else if (tex == 2) {
					int tex1 = rand() % 4 + 1;
					if (tex1 == 1) {
						texside = "NightBuilding3_1.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 2) {
						texside = "NightBuilding3_2.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 3) {
						texside = "NightBuilding3_3.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 4) {
						texside = "NightBuilding3_4.jpg";
						textop = "BlackRoof.jpg";
					}
				}
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
	{
		//tile 16
		std::vector<Building*> Buildings1;
		std::vector<Road*> Roads1;
			Roads1.push_back(new Road(glm::vec3(-1 * 25.0f, 0.0f, -1 * 30.0f), 5, 5, "roadPLAZA.png"));
			Roads1.push_back(new Road(glm::vec3(-1 * 30.0f, 0.0f, -1 * 30.0f), 5, 5, "roadPLAZA.png"));
			Roads1.push_back(new Road(glm::vec3(-1 * 35.0f, 0.0f, -1 * 30.0f), 5, 5, "roadPLAZA.png"));

			Roads1.push_back(new Road(glm::vec3(-1 * 25.0f, 0.0f, -1 * 25.0f), 5, 5, "roadPLAZA.png"));
			Roads1.push_back(new Road(glm::vec3(-1 * 30.0f, 0.0f, -1 * 25.0f), 5, 5, "roadPLAZA.png"));
			Roads1.push_back(new Road(glm::vec3(-1 * 35.0f, 0.0f, -1 * 25.0f), 5, 5, "roadPLAZA.png"));

			Roads1.push_back(new Road(glm::vec3(-1 * 25.0f, 0.0f, -1 * 35.0f), 5, 5, "roadPLAZA.png"));
			Roads1.push_back(new Road(glm::vec3(-1 * 30.0f, 0.0f, -1 * 35.0f), 5, 5, "roadPLAZA.png"));
			Roads1.push_back(new Road(glm::vec3(-1 * 35.0f, 0.0f, -1 * 35.0f), 5, 5, "roadPLAZA.png"));
			addRoad1(Roads1);
			GLchar* texside;
			GLchar* textop;
			if (Tswitch) {
				texside = "NightBuilding1_1.jpg";
				textop = "BlackRoof.jpg";
			}
			else {
				int tex = rand() % 3;
				if (tex == 0) {
					int tex1 = rand() % 8 + 1;
					if (tex1 == 1) {
						texside = "NightBuilding1_1.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 2) {
						texside = "NightBuilding1_2.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 3) {
						texside = "NightBuilding1_3.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 4) {
						texside = "NightBuilding1_4.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 5) {
						texside = "NightBuilding1_5.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 6) {
						texside = "NightBuilding1_6.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 7) {
						texside = "NightBuilding1_7.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 8) {
						texside = "NightBuilding1_8.jpg";
						textop = "BlackRoof.jpg";
					}
				}
				else if (tex == 1) {
					int tex1 = rand() % 4 + 1;
					if (tex1 == 1) {
						texside = "NightBuilding1_1.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 2) {
						texside = "NightBuilding1_2.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 3) {
						texside = "NightBuilding1_3.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 4) {
						texside = "NightBuilding1_4.jpg";
						textop = "BlackRoof.jpg";
					}
				}
				else if (tex == 2) {
					int tex1 = rand() % 4 + 1;
					if (tex1 == 1) {
						texside = "NightBuilding3_1.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 2) {
						texside = "NightBuilding3_2.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 3) {
						texside = "NightBuilding3_3.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 4) {
						texside = "NightBuilding3_4.jpg";
						textop = "BlackRoof.jpg";
					}
				}
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
	
	if (first) {
		GenRoad1();
		first = false;
	}
	else {
		GenRoad1();
	}
}

void City::BuildCity1(bool bg, bool tg) {// only building gen
	B_Blocks.clear();
	//R_Blocks.clear();
	float buildingsize = 4.5;
	float offsetz = 0.5f;
	float offsetx = 0.5f;
	int heightr;

	SF = rand() % 12 + 1;
	//int SF = 1;
	{
		//tile 1
		std::vector<Building*> Buildings1;
		int tex = rand() % 3;
		GLchar* texside;
		GLchar* textop;
		if (tex == 0) {
			int tex1 = rand() % 8 + 1;
			if (tex1 == 1) {
				texside = "NightBuilding1_1.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 2) {
				texside = "NightBuilding1_2.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 3) {
				texside = "NightBuilding1_3.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 4) {
				texside = "NightBuilding1_4.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 5) {
				texside = "NightBuilding1_5.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 6) {
				texside = "NightBuilding1_6.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 7) {
				texside = "NightBuilding1_7.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 8) {
				texside = "NightBuilding1_8.jpg";
				textop = "BlackRoof.jpg";
			}
		}
		else if (tex == 1) {
			int tex1 = rand() % 4 + 1;
			if (tex1 == 1) {
				texside = "NightBuilding1_1.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 2) {
				texside = "NightBuilding1_2.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 3) {
				texside = "NightBuilding1_3.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 4) {
				texside = "NightBuilding1_4.jpg";
				textop = "BlackRoof.jpg";
			}
		}
		else if (tex == 2) {
			int tex1 = rand() % 4 + 1;
			if (tex1 == 1) {
				texside = "NightBuilding3_1.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 2) {
				texside = "NightBuilding3_2.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 3) {
				texside = "NightBuilding3_3.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 4) {
				texside = "NightBuilding3_4.jpg";
				textop = "BlackRoof.jpg";
			}
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
	{
		//tile 2
		std::vector<Building*> Buildings;
		int tex = rand() % 3;
		GLchar* texside;
		GLchar* textop;
		if (tex == 0) {
			int tex1 = rand() % 8 + 1;
			if (tex1 == 1) {
				texside = "NightBuilding1_1.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 2) {
				texside = "NightBuilding1_2.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 3) {
				texside = "NightBuilding1_3.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 4) {
				texside = "NightBuilding1_4.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 5) {
				texside = "NightBuilding1_5.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 6) {
				texside = "NightBuilding1_6.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 7) {
				texside = "NightBuilding1_7.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 8) {
				texside = "NightBuilding1_8.jpg";
				textop = "BlackRoof.jpg";
			}
		}
		else if (tex == 1) {
			int tex1 = rand() % 4 + 1;
			if (tex1 == 1) {
				texside = "NightBuilding1_1.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 2) {
				texside = "NightBuilding1_2.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 3) {
				texside = "NightBuilding1_3.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 4) {
				texside = "NightBuilding1_4.jpg";
				textop = "BlackRoof.jpg";
			}
		}
		else if (tex == 2) {
			int tex1 = rand() % 4 + 1;
			if (tex1 == 1) {
				texside = "NightBuilding3_1.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 2) {
				texside = "NightBuilding3_2.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 3) {
				texside = "NightBuilding3_3.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 4) {
				texside = "NightBuilding3_4.jpg";
				textop = "BlackRoof.jpg";
			}
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
	{
		// tile 3
		std::vector<Building*> Buildings;
		int tex = rand() % 3;
		GLchar* texside;
		GLchar* textop;
		if (tex == 0) {
			int tex1 = rand() % 8 + 1;
			if (tex1 == 1) {
				texside = "NightBuilding1_1.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 2) {
				texside = "NightBuilding1_2.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 3) {
				texside = "NightBuilding1_3.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 4) {
				texside = "NightBuilding1_4.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 5) {
				texside = "NightBuilding1_5.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 6) {
				texside = "NightBuilding1_6.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 7) {
				texside = "NightBuilding1_7.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 8) {
				texside = "NightBuilding1_8.jpg";
				textop = "BlackRoof.jpg";
			}
		}
		else if (tex == 1) {
			int tex1 = rand() % 4 + 1;
			if (tex1 == 1) {
				texside = "NightBuilding1_1.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 2) {
				texside = "NightBuilding1_2.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 3) {
				texside = "NightBuilding1_3.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 4) {
				texside = "NightBuilding1_4.jpg";
				textop = "BlackRoof.jpg";
			}
		}
		else if (tex == 2) {
			int tex1 = rand() % 4 + 1;
			if (tex1 == 1) {
				texside = "NightBuilding3_1.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 2) {
				texside = "NightBuilding3_2.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 3) {
				texside = "NightBuilding3_3.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 4) {
				texside = "NightBuilding3_4.jpg";
				textop = "BlackRoof.jpg";
			}
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
	{
		//tile 4
		std::vector<Building*> Buildings;
		int tex = rand() % 3;
		GLchar* texside;
		GLchar* textop;
		if (tex == 0) {
			int tex1 = rand() % 8 + 1;
			if (tex1 == 1) {
				texside = "NightBuilding1_1.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 2) {
				texside = "NightBuilding1_2.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 3) {
				texside = "NightBuilding1_3.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 4) {
				texside = "NightBuilding1_4.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 5) {
				texside = "NightBuilding1_5.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 6) {
				texside = "NightBuilding1_6.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 7) {
				texside = "NightBuilding1_7.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 8) {
				texside = "NightBuilding1_8.jpg";
				textop = "BlackRoof.jpg";
			}
		}
		else if (tex == 1) {
			int tex1 = rand() % 4 + 1;
			if (tex1 == 1) {
				texside = "NightBuilding1_1.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 2) {
				texside = "NightBuilding1_2.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 3) {
				texside = "NightBuilding1_3.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 4) {
				texside = "NightBuilding1_4.jpg";
				textop = "BlackRoof.jpg";
			}
		}
		else if (tex == 2) {
			int tex1 = rand() % 4 + 1;
			if (tex1 == 1) {
				texside = "NightBuilding3_1.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 2) {
				texside = "NightBuilding3_2.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 3) {
				texside = "NightBuilding3_3.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 4) {
				texside = "NightBuilding3_4.jpg";
				textop = "BlackRoof.jpg";
			}
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
	{
		//tile5
		std::vector<Building*> Buildings;
		int tex = rand() % 3;
		GLchar* texside;
		GLchar* textop;
		if (tex == 0) {
			int tex1 = rand() % 8 + 1;
			if (tex1 == 1) {
				texside = "NightBuilding1_1.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 2) {
				texside = "NightBuilding1_2.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 3) {
				texside = "NightBuilding1_3.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 4) {
				texside = "NightBuilding1_4.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 5) {
				texside = "NightBuilding1_5.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 6) {
				texside = "NightBuilding1_6.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 7) {
				texside = "NightBuilding1_7.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 8) {
				texside = "NightBuilding1_8.jpg";
				textop = "BlackRoof.jpg";
			}
		}
		else if (tex == 1) {
			int tex1 = rand() % 4 + 1;
			if (tex1 == 1) {
				texside = "NightBuilding1_1.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 2) {
				texside = "NightBuilding1_2.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 3) {
				texside = "NightBuilding1_3.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 4) {
				texside = "NightBuilding1_4.jpg";
				textop = "BlackRoof.jpg";
			}
		}
		else if (tex == 2) {
			int tex1 = rand() % 4 + 1;
			if (tex1 == 1) {
				texside = "NightBuilding3_1.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 2) {
				texside = "NightBuilding3_2.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 3) {
				texside = "NightBuilding3_3.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 4) {
				texside = "NightBuilding3_4.jpg";
				textop = "BlackRoof.jpg";
			}
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
	{
		//tile 6
		std::vector<Building*> Buildings;
		int tex = rand() % 3;
		GLchar* texside;
		GLchar* textop;
		if (tex == 0) {
			int tex1 = rand() % 8 + 1;
			if (tex1 == 1) {
				texside = "NightBuilding1_1.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 2) {
				texside = "NightBuilding1_2.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 3) {
				texside = "NightBuilding1_3.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 4) {
				texside = "NightBuilding1_4.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 5) {
				texside = "NightBuilding1_5.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 6) {
				texside = "NightBuilding1_6.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 7) {
				texside = "NightBuilding1_7.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 8) {
				texside = "NightBuilding1_8.jpg";
				textop = "BlackRoof.jpg";
			}
		}
		else if (tex == 1) {
			int tex1 = rand() % 4 + 1;
			if (tex1 == 1) {
				texside = "NightBuilding1_1.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 2) {
				texside = "NightBuilding1_2.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 3) {
				texside = "NightBuilding1_3.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 4) {
				texside = "NightBuilding1_4.jpg";
				textop = "BlackRoof.jpg";
			}
		}
		else if (tex == 2) {
			int tex1 = rand() % 4 + 1;
			if (tex1 == 1) {
				texside = "NightBuilding3_1.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 2) {
				texside = "NightBuilding3_2.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 3) {
				texside = "NightBuilding3_3.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 4) {
				texside = "NightBuilding3_4.jpg";
				textop = "BlackRoof.jpg";
			}
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
	{
		//tile 7
		std::vector<Building*> Buildings;
		int tex = rand() % 3;
		GLchar* texside;
		GLchar* textop;
		if (tex == 0) {
			int tex1 = rand() % 8 + 1;
			if (tex1 == 1) {
				texside = "NightBuilding1_1.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 2) {
				texside = "NightBuilding1_2.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 3) {
				texside = "NightBuilding1_3.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 4) {
				texside = "NightBuilding1_4.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 5) {
				texside = "NightBuilding1_5.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 6) {
				texside = "NightBuilding1_6.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 7) {
				texside = "NightBuilding1_7.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 8) {
				texside = "NightBuilding1_8.jpg";
				textop = "BlackRoof.jpg";
			}
		}
		else if (tex == 1) {
			int tex1 = rand() % 4 + 1;
			if (tex1 == 1) {
				texside = "NightBuilding1_1.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 2) {
				texside = "NightBuilding1_2.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 3) {
				texside = "NightBuilding1_3.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 4) {
				texside = "NightBuilding1_4.jpg";
				textop = "BlackRoof.jpg";
			}
		}
		else if (tex == 2) {
			int tex1 = rand() % 4 + 1;
			if (tex1 == 1) {
				texside = "NightBuilding3_1.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 2) {
				texside = "NightBuilding3_2.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 3) {
				texside = "NightBuilding3_3.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 4) {
				texside = "NightBuilding3_4.jpg";
				textop = "BlackRoof.jpg";
			}
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
	{
		//tile 8
		std::vector<Building*> Buildings;
		int tex = rand() % 3;
		GLchar* texside;
		GLchar* textop;
		if (tex == 0) {
			int tex1 = rand() % 8 + 1;
			if (tex1 == 1) {
				texside = "NightBuilding1_1.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 2) {
				texside = "NightBuilding1_2.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 3) {
				texside = "NightBuilding1_3.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 4) {
				texside = "NightBuilding1_4.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 5) {
				texside = "NightBuilding1_5.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 6) {
				texside = "NightBuilding1_6.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 7) {
				texside = "NightBuilding1_7.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 8) {
				texside = "NightBuilding1_8.jpg";
				textop = "BlackRoof.jpg";
			}
		}
		else if (tex == 1) {
			int tex1 = rand() % 4 + 1;
			if (tex1 == 1) {
				texside = "NightBuilding1_1.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 2) {
				texside = "NightBuilding1_2.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 3) {
				texside = "NightBuilding1_3.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 4) {
				texside = "NightBuilding1_4.jpg";
				textop = "BlackRoof.jpg";
			}
		}
		else if (tex == 2) {
			int tex1 = rand() % 4 + 1;
			if (tex1 == 1) {
				texside = "NightBuilding3_1.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 2) {
				texside = "NightBuilding3_2.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 3) {
				texside = "NightBuilding3_3.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 4) {
				texside = "NightBuilding3_4.jpg";
				textop = "BlackRoof.jpg";
			}
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
	{
		//tile 9
		std::vector<Building*> Buildings;
		int tex = rand() % 3;
		GLchar* texside;
		GLchar* textop;
		if (tex == 0) {
			int tex1 = rand() % 8 + 1;
			if (tex1 == 1) {
				texside = "NightBuilding1_1.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 2) {
				texside = "NightBuilding1_2.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 3) {
				texside = "NightBuilding1_3.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 4) {
				texside = "NightBuilding1_4.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 5) {
				texside = "NightBuilding1_5.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 6) {
				texside = "NightBuilding1_6.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 7) {
				texside = "NightBuilding1_7.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 8) {
				texside = "NightBuilding1_8.jpg";
				textop = "BlackRoof.jpg";
			}
		}
		else if (tex == 1) {
			int tex1 = rand() % 4 + 1;
			if (tex1 == 1) {
				texside = "NightBuilding1_1.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 2) {
				texside = "NightBuilding1_2.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 3) {
				texside = "NightBuilding1_3.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 4) {
				texside = "NightBuilding1_4.jpg";
				textop = "BlackRoof.jpg";
			}
		}
		else if (tex == 2) {
			int tex1 = rand() % 4 + 1;
			if (tex1 == 1) {
				texside = "NightBuilding3_1.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 2) {
				texside = "NightBuilding3_2.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 3) {
				texside = "NightBuilding3_3.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 4) {
				texside = "NightBuilding3_4.jpg";
				textop = "BlackRoof.jpg";
			}
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
	{
		//tile 10
		std::vector<Building*> Buildings;
		int tex = rand() % 3;
		GLchar* texside;
		GLchar* textop;
		if (tex == 0) {
			int tex1 = rand() % 8 + 1;
			if (tex1 == 1) {
				texside = "NightBuilding1_1.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 2) {
				texside = "NightBuilding1_2.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 3) {
				texside = "NightBuilding1_3.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 4) {
				texside = "NightBuilding1_4.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 5) {
				texside = "NightBuilding1_5.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 6) {
				texside = "NightBuilding1_6.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 7) {
				texside = "NightBuilding1_7.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 8) {
				texside = "NightBuilding1_8.jpg";
				textop = "BlackRoof.jpg";
			}
		}
		else if (tex == 1) {
			int tex1 = rand() % 4 + 1;
			if (tex1 == 1) {
				texside = "NightBuilding1_1.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 2) {
				texside = "NightBuilding1_2.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 3) {
				texside = "NightBuilding1_3.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 4) {
				texside = "NightBuilding1_4.jpg";
				textop = "BlackRoof.jpg";
			}
		}
		else if (tex == 2) {
			int tex1 = rand() % 4 + 1;
			if (tex1 == 1) {
				texside = "NightBuilding3_1.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 2) {
				texside = "NightBuilding3_2.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 3) {
				texside = "NightBuilding3_3.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 4) {
				texside = "NightBuilding3_4.jpg";
				textop = "BlackRoof.jpg";
			}
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
	{
		//tile 11
		std::vector<Building*> Buildings;
		int tex = rand() % 3;
		GLchar* texside;
		GLchar* textop;
		if (tex == 0) {
			int tex1 = rand() % 8 + 1;
			if (tex1 == 1) {
				texside = "NightBuilding1_1.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 2) {
				texside = "NightBuilding1_2.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 3) {
				texside = "NightBuilding1_3.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 4) {
				texside = "NightBuilding1_4.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 5) {
				texside = "NightBuilding1_5.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 6) {
				texside = "NightBuilding1_6.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 7) {
				texside = "NightBuilding1_7.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 8) {
				texside = "NightBuilding1_8.jpg";
				textop = "BlackRoof.jpg";
			}
		}
		else if (tex == 1) {
			int tex1 = rand() % 4 + 1;
			if (tex1 == 1) {
				texside = "NightBuilding1_1.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 2) {
				texside = "NightBuilding1_2.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 3) {
				texside = "NightBuilding1_3.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 4) {
				texside = "NightBuilding1_4.jpg";
				textop = "BlackRoof.jpg";
			}
		}
		else if (tex == 2) {
			int tex1 = rand() % 4 + 1;
			if (tex1 == 1) {
				texside = "NightBuilding3_1.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 2) {
				texside = "NightBuilding3_2.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 3) {
				texside = "NightBuilding3_3.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 4) {
				texside = "NightBuilding3_4.jpg";
				textop = "BlackRoof.jpg";
			}
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
	{
		//tile 12
		std::vector<Building*> Buildings;
		int tex = rand() % 3;
		GLchar* texside;
		GLchar* textop;
		if (tex == 0) {
			int tex1 = rand() % 8 + 1;
			if (tex1 == 1) {
				texside = "NightBuilding1_1.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 2) {
				texside = "NightBuilding1_2.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 3) {
				texside = "NightBuilding1_3.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 4) {
				texside = "NightBuilding1_4.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 5) {
				texside = "NightBuilding1_5.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 6) {
				texside = "NightBuilding1_6.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 7) {
				texside = "NightBuilding1_7.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 8) {
				texside = "NightBuilding1_8.jpg";
				textop = "BlackRoof.jpg";
			}
		}
		else if (tex == 1) {
			int tex1 = rand() % 4 + 1;
			if (tex1 == 1) {
				texside = "NightBuilding1_1.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 2) {
				texside = "NightBuilding1_2.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 3) {
				texside = "NightBuilding1_3.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 4) {
				texside = "NightBuilding1_4.jpg";
				textop = "BlackRoof.jpg";
			}
		}
		else if (tex == 2) {
			int tex1 = rand() % 4 + 1;
			if (tex1 == 1) {
				texside = "NightBuilding3_1.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 2) {
				texside = "NightBuilding3_2.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 3) {
				texside = "NightBuilding3_3.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 4) {
				texside = "NightBuilding3_4.jpg";
				textop = "BlackRoof.jpg";
			}
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
	{
		//tile 13
		std::vector<Building*> Buildings;
		int tex = rand() % 3;
		GLchar* texside;
		GLchar* textop;
		if (tex == 0) {
			int tex1 = rand() % 8 + 1;
			if (tex1 == 1) {
				texside = "NightBuilding1_1.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 2) {
				texside = "NightBuilding1_2.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 3) {
				texside = "NightBuilding1_3.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 4) {
				texside = "NightBuilding1_4.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 5) {
				texside = "NightBuilding1_5.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 6) {
				texside = "NightBuilding1_6.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 7) {
				texside = "NightBuilding1_7.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 8) {
				texside = "NightBuilding1_8.jpg";
				textop = "BlackRoof.jpg";
			}
		}
		else if (tex == 1) {
			int tex1 = rand() % 4 + 1;
			if (tex1 == 1) {
				texside = "NightBuilding1_1.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 2) {
				texside = "NightBuilding1_2.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 3) {
				texside = "NightBuilding1_3.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 4) {
				texside = "NightBuilding1_4.jpg";
				textop = "BlackRoof.jpg";
			}
		}
		else if (tex == 2) {
			int tex1 = rand() % 4 + 1;
			if (tex1 == 1) {
				texside = "NightBuilding3_1.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 2) {
				texside = "NightBuilding3_2.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 3) {
				texside = "NightBuilding3_3.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 4) {
				texside = "NightBuilding3_4.jpg";
				textop = "BlackRoof.jpg";
			}
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
	{
		//tile 14
		std::vector<Building*> Buildings;
		int tex = rand() % 3;
		GLchar* texside;
		GLchar* textop;
		if (tex == 0) {
			int tex1 = rand() % 8 + 1;
			if (tex1 == 1) {
				texside = "NightBuilding1_1.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 2) {
				texside = "NightBuilding1_2.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 3) {
				texside = "NightBuilding1_3.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 4) {
				texside = "NightBuilding1_4.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 5) {
				texside = "NightBuilding1_5.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 6) {
				texside = "NightBuilding1_6.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 7) {
				texside = "NightBuilding1_7.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 8) {
				texside = "NightBuilding1_8.jpg";
				textop = "BlackRoof.jpg";
			}
		}
		else if (tex == 1) {
			int tex1 = rand() % 4 + 1;
			if (tex1 == 1) {
				texside = "NightBuilding1_1.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 2) {
				texside = "NightBuilding1_2.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 3) {
				texside = "NightBuilding1_3.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 4) {
				texside = "NightBuilding1_4.jpg";
				textop = "BlackRoof.jpg";
			}
		}
		else if (tex == 2) {
			int tex1 = rand() % 4 + 1;
			if (tex1 == 1) {
				texside = "NightBuilding3_1.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 2) {
				texside = "NightBuilding3_2.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 3) {
				texside = "NightBuilding3_3.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 4) {
				texside = "NightBuilding3_4.jpg";
				textop = "BlackRoof.jpg";
			}
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
	{
		//tile 15
		std::vector<Building*> Buildings;
		int tex = rand() % 3;
		GLchar* texside;
		GLchar* textop;
		if (tex == 0) {
			int tex1 = rand() % 8 + 1;
			if (tex1 == 1) {
				texside = "NightBuilding1_1.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 2) {
				texside = "NightBuilding1_2.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 3) {
				texside = "NightBuilding1_3.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 4) {
				texside = "NightBuilding1_4.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 5) {
				texside = "NightBuilding1_5.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 6) {
				texside = "NightBuilding1_6.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 7) {
				texside = "NightBuilding1_7.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 8) {
				texside = "NightBuilding1_8.jpg";
				textop = "BlackRoof.jpg";
			}
		}
		else if (tex == 1) {
			int tex1 = rand() % 4 + 1;
			if (tex1 == 1) {
				texside = "NightBuilding1_1.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 2) {
				texside = "NightBuilding1_2.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 3) {
				texside = "NightBuilding1_3.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 4) {
				texside = "NightBuilding1_4.jpg";
				textop = "BlackRoof.jpg";
			}
		}
		else if (tex == 2) {
			int tex1 = rand() % 4 + 1;
			if (tex1 == 1) {
				texside = "NightBuilding3_1.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 2) {
				texside = "NightBuilding3_2.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 3) {
				texside = "NightBuilding3_3.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 4) {
				texside = "NightBuilding3_4.jpg";
				textop = "BlackRoof.jpg";
			}
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
	{
		//tile 16
		std::vector<Building*> Buildings;
		int tex = rand() % 3;
		GLchar* texside;
		GLchar* textop;
		if (tex == 0) {
			int tex1 = rand() % 8 + 1;
			if (tex1 == 1) {
				texside = "NightBuilding1_1.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 2) {
				texside = "NightBuilding1_2.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 3) {
				texside = "NightBuilding1_3.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 4) {
				texside = "NightBuilding1_4.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 5) {
				texside = "NightBuilding1_5.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 6) {
				texside = "NightBuilding1_6.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 7) {
				texside = "NightBuilding1_7.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 8) {
				texside = "NightBuilding1_8.jpg";
				textop = "BlackRoof.jpg";
			}
		}
		else if (tex == 1) {
			int tex1 = rand() % 4 + 1;
			if (tex1 == 1) {
				texside = "NightBuilding1_1.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 2) {
				texside = "NightBuilding1_2.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 3) {
				texside = "NightBuilding1_3.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 4) {
				texside = "NightBuilding1_4.jpg";
				textop = "BlackRoof.jpg";
			}
		}
		else if (tex == 2) {
			int tex1 = rand() % 4 + 1;
			if (tex1 == 1) {
				texside = "NightBuilding3_1.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 2) {
				texside = "NightBuilding3_2.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 3) {
				texside = "NightBuilding3_3.jpg";
				textop = "BlackRoof.jpg";
			}
			if (tex1 == 4) {
				texside = "NightBuilding3_4.jpg";
				textop = "BlackRoof.jpg";
			}
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

	if (first) {
		GenRoad1();
		first = false;
	}
	else {
		GenRoad1();
	}
}

void City::BuildCity2(bool bg, bool tg) {
	Buildings.clear();
	Roads.clear();
	Tswitch = tg;
	Gswitch = bg;
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
			
			GLchar* texside;
			GLchar* textop;
			if (Tswitch) {
				texside = "NightBuilding1_1.jpg";
				textop = "BlackRoof.jpg";
			}
			else {
				int tex = rand() % 3;				
				if (tex == 0) {
					int tex1 = rand() % 8 + 1;
					if (tex1 == 1) {
						texside = "NightBuilding1_1.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 2) {
						texside = "NightBuilding1_2.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 3) {
						texside = "NightBuilding1_3.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 4) {
						texside = "NightBuilding1_4.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 5) {
						texside = "NightBuilding1_5.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 6) {
						texside = "NightBuilding1_6.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 7) {
						texside = "NightBuilding1_7.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 8) {
						texside = "NightBuilding1_8.jpg";
						textop = "BlackRoof.jpg";
					}
				}
				else if (tex == 1) {
					int tex1 = rand() % 4 + 1;
					if (tex1 == 1) {
						texside = "NightBuilding1_1.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 2) {
						texside = "NightBuilding1_2.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 3) {
						texside = "NightBuilding1_3.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 4) {
						texside = "NightBuilding1_4.jpg";
						textop = "BlackRoof.jpg";
					}
				}
				else if (tex == 2) {
					int tex1 = rand() % 4 + 1;
					if (tex1 == 1) {
						texside = "NightBuilding3_1.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 2) {
						texside = "NightBuilding3_2.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 3) {
						texside = "NightBuilding3_3.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 4) {
						texside = "NightBuilding3_4.jpg";
						textop = "BlackRoof.jpg";
					}
				}
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

			GLchar* texside;
			GLchar* textop;
			if (Tswitch) {
				texside = "NightBuilding1_1.jpg";
				textop = "BlackRoof.jpg";
			}
			else {
				int tex = rand() % 3;
				if (tex == 0) {
					int tex1 = rand() % 8 + 1;
					if (tex1 == 1) {
						texside = "NightBuilding1_1.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 2) {
						texside = "NightBuilding1_2.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 3) {
						texside = "NightBuilding1_3.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 4) {
						texside = "NightBuilding1_4.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 5) {
						texside = "NightBuilding1_5.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 6) {
						texside = "NightBuilding1_6.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 7) {
						texside = "NightBuilding1_7.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 8) {
						texside = "NightBuilding1_8.jpg";
						textop = "BlackRoof.jpg";
					}
				}
				else if (tex == 1) {
					int tex1 = rand() % 4 + 1;
					if (tex1 == 1) {
						texside = "NightBuilding1_1.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 2) {
						texside = "NightBuilding1_2.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 3) {
						texside = "NightBuilding1_3.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 4) {
						texside = "NightBuilding1_4.jpg";
						textop = "BlackRoof.jpg";
					}
				}
				else if (tex == 2) {
					int tex1 = rand() % 4 + 1;
					if (tex1 == 1) {
						texside = "NightBuilding3_1.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 2) {
						texside = "NightBuilding3_2.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 3) {
						texside = "NightBuilding3_3.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 4) {
						texside = "NightBuilding3_4.jpg";
						textop = "BlackRoof.jpg";
					}
				}
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

			GLchar* texside;
			GLchar* textop;
			if (Tswitch) {
				texside = "NightBuilding1_1.jpg";
				textop = "BlackRoof.jpg";
			}
			else {
				int tex = rand() % 3;
				if (tex == 0) {
					int tex1 = rand() % 8 + 1;
					if (tex1 == 1) {
						texside = "NightBuilding1_1.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 2) {
						texside = "NightBuilding1_2.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 3) {
						texside = "NightBuilding1_3.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 4) {
						texside = "NightBuilding1_4.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 5) {
						texside = "NightBuilding1_5.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 6) {
						texside = "NightBuilding1_6.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 7) {
						texside = "NightBuilding1_7.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 8) {
						texside = "NightBuilding1_8.jpg";
						textop = "BlackRoof.jpg";
					}
				}
				else if (tex == 1) {
					int tex1 = rand() % 4 + 1;
					if (tex1 == 1) {
						texside = "NightBuilding1_1.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 2) {
						texside = "NightBuilding1_2.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 3) {
						texside = "NightBuilding1_3.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 4) {
						texside = "NightBuilding1_4.jpg";
						textop = "BlackRoof.jpg";
					}
				}
				else if (tex == 2) {
					int tex1 = rand() % 4 + 1;
					if (tex1 == 1) {
						texside = "NightBuilding3_1.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 2) {
						texside = "NightBuilding3_2.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 3) {
						texside = "NightBuilding3_3.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 4) {
						texside = "NightBuilding3_4.jpg";
						textop = "BlackRoof.jpg";
					}
				}
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

			GLchar* texside;
			GLchar* textop;
			if (Tswitch) {
				texside = "NightBuilding1_1.jpg";
				textop = "BlackRoof.jpg";
			}
			else {
				int tex = rand() % 3;
				if (tex == 0) {
					int tex1 = rand() % 8 + 1;
					if (tex1 == 1) {
						texside = "NightBuilding1_1.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 2) {
						texside = "NightBuilding1_2.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 3) {
						texside = "NightBuilding1_3.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 4) {
						texside = "NightBuilding1_4.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 5) {
						texside = "NightBuilding1_5.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 6) {
						texside = "NightBuilding1_6.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 7) {
						texside = "NightBuilding1_7.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 8) {
						texside = "NightBuilding1_8.jpg";
						textop = "BlackRoof.jpg";
					}
				}
				else if (tex == 1) {
					int tex1 = rand() % 4 + 1;
					if (tex1 == 1) {
						texside = "NightBuilding1_1.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 2) {
						texside = "NightBuilding1_2.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 3) {
						texside = "NightBuilding1_3.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 4) {
						texside = "NightBuilding1_4.jpg";
						textop = "BlackRoof.jpg";
					}
				}
				else if (tex == 2) {
					int tex1 = rand() % 4 + 1;
					if (tex1 == 1) {
						texside = "NightBuilding3_1.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 2) {
						texside = "NightBuilding3_2.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 3) {
						texside = "NightBuilding3_3.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 4) {
						texside = "NightBuilding3_4.jpg";
						textop = "BlackRoof.jpg";
					}
				}
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

			GLchar* texside;
			GLchar* textop;
			if (Tswitch) {
				texside = "NightBuilding1_1.jpg";
				textop = "BlackRoof.jpg";
			}
			else {
				int tex = rand() % 3;
				if (tex == 0) {
					int tex1 = rand() % 8 + 1;
					if (tex1 == 1) {
						texside = "NightBuilding1_1.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 2) {
						texside = "NightBuilding1_2.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 3) {
						texside = "NightBuilding1_3.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 4) {
						texside = "NightBuilding1_4.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 5) {
						texside = "NightBuilding1_5.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 6) {
						texside = "NightBuilding1_6.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 7) {
						texside = "NightBuilding1_7.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 8) {
						texside = "NightBuilding1_8.jpg";
						textop = "BlackRoof.jpg";
					}
				}
				else if (tex == 1) {
					int tex1 = rand() % 4 + 1;
					if (tex1 == 1) {
						texside = "NightBuilding1_1.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 2) {
						texside = "NightBuilding1_2.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 3) {
						texside = "NightBuilding1_3.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 4) {
						texside = "NightBuilding1_4.jpg";
						textop = "BlackRoof.jpg";
					}
				}
				else if (tex == 2) {
					int tex1 = rand() % 4 + 1;
					if (tex1 == 1) {
						texside = "NightBuilding3_1.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 2) {
						texside = "NightBuilding3_2.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 3) {
						texside = "NightBuilding3_3.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 4) {
						texside = "NightBuilding3_4.jpg";
						textop = "BlackRoof.jpg";
					}
				}
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

			GLchar* texside;
			GLchar* textop;
			if (Tswitch) {
				texside = "NightBuilding1_1.jpg";
				textop = "BlackRoof.jpg";
			}
			else {
				int tex = rand() % 3;
				if (tex == 0) {
					int tex1 = rand() % 8 + 1;
					if (tex1 == 1) {
						texside = "NightBuilding1_1.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 2) {
						texside = "NightBuilding1_2.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 3) {
						texside = "NightBuilding1_3.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 4) {
						texside = "NightBuilding1_4.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 5) {
						texside = "NightBuilding1_5.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 6) {
						texside = "NightBuilding1_6.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 7) {
						texside = "NightBuilding1_7.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 8) {
						texside = "NightBuilding1_8.jpg";
						textop = "BlackRoof.jpg";
					}
				}
				else if (tex == 1) {
					int tex1 = rand() % 4 + 1;
					if (tex1 == 1) {
						texside = "NightBuilding1_1.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 2) {
						texside = "NightBuilding1_2.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 3) {
						texside = "NightBuilding1_3.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 4) {
						texside = "NightBuilding1_4.jpg";
						textop = "BlackRoof.jpg";
					}
				}
				else if (tex == 2) {
					int tex1 = rand() % 4 + 1;
					if (tex1 == 1) {
						texside = "NightBuilding3_1.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 2) {
						texside = "NightBuilding3_2.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 3) {
						texside = "NightBuilding3_3.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 4) {
						texside = "NightBuilding3_4.jpg";
						textop = "BlackRoof.jpg";
					}
				}
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

			GLchar* texside;
			GLchar* textop;
			if (Tswitch) {
				texside = "NightBuilding1_1.jpg";
				textop = "BlackRoof.jpg";
			}
			else {
				int tex = rand() % 3;
				if (tex == 0) {
					int tex1 = rand() % 8 + 1;
					if (tex1 == 1) {
						texside = "NightBuilding1_1.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 2) {
						texside = "NightBuilding1_2.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 3) {
						texside = "NightBuilding1_3.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 4) {
						texside = "NightBuilding1_4.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 5) {
						texside = "NightBuilding1_5.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 6) {
						texside = "NightBuilding1_6.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 7) {
						texside = "NightBuilding1_7.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 8) {
						texside = "NightBuilding1_8.jpg";
						textop = "BlackRoof.jpg";
					}
				}
				else if (tex == 1) {
					int tex1 = rand() % 4 + 1;
					if (tex1 == 1) {
						texside = "NightBuilding1_1.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 2) {
						texside = "NightBuilding1_2.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 3) {
						texside = "NightBuilding1_3.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 4) {
						texside = "NightBuilding1_4.jpg";
						textop = "BlackRoof.jpg";
					}
				}
				else if (tex == 2) {
					int tex1 = rand() % 4 + 1;
					if (tex1 == 1) {
						texside = "NightBuilding3_1.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 2) {
						texside = "NightBuilding3_2.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 3) {
						texside = "NightBuilding3_3.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 4) {
						texside = "NightBuilding3_4.jpg";
						textop = "BlackRoof.jpg";
					}
				}
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

			GLchar* texside;
			GLchar* textop;
			if (Tswitch) {
				texside = "NightBuilding1_1.jpg";
				textop = "BlackRoof.jpg";
			}
			else {
				int tex = rand() % 3;
				if (tex == 0) {
					int tex1 = rand() % 8 + 1;
					if (tex1 == 1) {
						texside = "NightBuilding1_1.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 2) {
						texside = "NightBuilding1_2.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 3) {
						texside = "NightBuilding1_3.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 4) {
						texside = "NightBuilding1_4.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 5) {
						texside = "NightBuilding1_5.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 6) {
						texside = "NightBuilding1_6.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 7) {
						texside = "NightBuilding1_7.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 8) {
						texside = "NightBuilding1_8.jpg";
						textop = "BlackRoof.jpg";
					}
				}
				else if (tex == 1) {
					int tex1 = rand() % 4 + 1;
					if (tex1 == 1) {
						texside = "NightBuilding1_1.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 2) {
						texside = "NightBuilding1_2.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 3) {
						texside = "NightBuilding1_3.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 4) {
						texside = "NightBuilding1_4.jpg";
						textop = "BlackRoof.jpg";
					}
				}
				else if (tex == 2) {
					int tex1 = rand() % 4 + 1;
					if (tex1 == 1) {
						texside = "NightBuilding3_1.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 2) {
						texside = "NightBuilding3_2.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 3) {
						texside = "NightBuilding3_3.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 4) {
						texside = "NightBuilding3_4.jpg";
						textop = "BlackRoof.jpg";
					}
				}
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

			GLchar* texside;
			GLchar* textop;
			if (Tswitch) {
				texside = "NightBuilding1_1.jpg";
				textop = "BlackRoof.jpg";
			}
			else {
				int tex = rand() % 3;
				if (tex == 0) {
					int tex1 = rand() % 8 + 1;
					if (tex1 == 1) {
						texside = "NightBuilding1_1.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 2) {
						texside = "NightBuilding1_2.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 3) {
						texside = "NightBuilding1_3.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 4) {
						texside = "NightBuilding1_4.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 5) {
						texside = "NightBuilding1_5.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 6) {
						texside = "NightBuilding1_6.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 7) {
						texside = "NightBuilding1_7.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 8) {
						texside = "NightBuilding1_8.jpg";
						textop = "BlackRoof.jpg";
					}
				}
				else if (tex == 1) {
					int tex1 = rand() % 4 + 1;
					if (tex1 == 1) {
						texside = "NightBuilding1_1.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 2) {
						texside = "NightBuilding1_2.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 3) {
						texside = "NightBuilding1_3.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 4) {
						texside = "NightBuilding1_4.jpg";
						textop = "BlackRoof.jpg";
					}
				}
				else if (tex == 2) {
					int tex1 = rand() % 4 + 1;
					if (tex1 == 1) {
						texside = "NightBuilding3_1.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 2) {
						texside = "NightBuilding3_2.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 3) {
						texside = "NightBuilding3_3.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 4) {
						texside = "NightBuilding3_4.jpg";
						textop = "BlackRoof.jpg";
					}
				}
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

			GLchar* texside;
			GLchar* textop;
			if (Tswitch) {
				texside = "NightBuilding1_1.jpg";
				textop = "BlackRoof.jpg";
			}
			else {
				int tex = rand() % 3;
				if (tex == 0) {
					int tex1 = rand() % 8 + 1;
					if (tex1 == 1) {
						texside = "NightBuilding1_1.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 2) {
						texside = "NightBuilding1_2.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 3) {
						texside = "NightBuilding1_3.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 4) {
						texside = "NightBuilding1_4.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 5) {
						texside = "NightBuilding1_5.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 6) {
						texside = "NightBuilding1_6.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 7) {
						texside = "NightBuilding1_7.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 8) {
						texside = "NightBuilding1_8.jpg";
						textop = "BlackRoof.jpg";
					}
				}
				else if (tex == 1) {
					int tex1 = rand() % 4 + 1;
					if (tex1 == 1) {
						texside = "NightBuilding1_1.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 2) {
						texside = "NightBuilding1_2.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 3) {
						texside = "NightBuilding1_3.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 4) {
						texside = "NightBuilding1_4.jpg";
						textop = "BlackRoof.jpg";
					}
				}
				else if (tex == 2) {
					int tex1 = rand() % 4 + 1;
					if (tex1 == 1) {
						texside = "NightBuilding3_1.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 2) {
						texside = "NightBuilding3_2.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 3) {
						texside = "NightBuilding3_3.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 4) {
						texside = "NightBuilding3_4.jpg";
						textop = "BlackRoof.jpg";
					}
				}
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

			GLchar* texside;
			GLchar* textop;
			if (Tswitch) {
				texside = "NightBuilding1_1.jpg";
				textop = "BlackRoof.jpg";
			}
			else {
				int tex = rand() % 3;
				if (tex == 0) {
					int tex1 = rand() % 8 + 1;
					if (tex1 == 1) {
						texside = "NightBuilding1_1.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 2) {
						texside = "NightBuilding1_2.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 3) {
						texside = "NightBuilding1_3.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 4) {
						texside = "NightBuilding1_4.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 5) {
						texside = "NightBuilding1_5.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 6) {
						texside = "NightBuilding1_6.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 7) {
						texside = "NightBuilding1_7.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 8) {
						texside = "NightBuilding1_8.jpg";
						textop = "BlackRoof.jpg";
					}
				}
				else if (tex == 1) {
					int tex1 = rand() % 4 + 1;
					if (tex1 == 1) {
						texside = "NightBuilding1_1.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 2) {
						texside = "NightBuilding1_2.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 3) {
						texside = "NightBuilding1_3.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 4) {
						texside = "NightBuilding1_4.jpg";
						textop = "BlackRoof.jpg";
					}
				}
				else if (tex == 2) {
					int tex1 = rand() % 4 + 1;
					if (tex1 == 1) {
						texside = "NightBuilding3_1.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 2) {
						texside = "NightBuilding3_2.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 3) {
						texside = "NightBuilding3_3.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 4) {
						texside = "NightBuilding3_4.jpg";
						textop = "BlackRoof.jpg";
					}
				}
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

			GLchar* texside;
			GLchar* textop;
			if (Tswitch) {
				texside = "NightBuilding1_1.jpg";
				textop = "BlackRoof.jpg";
			}
			else {
				int tex = rand() % 3;
				if (tex == 0) {
					int tex1 = rand() % 8 + 1;
					if (tex1 == 1) {
						texside = "NightBuilding1_1.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 2) {
						texside = "NightBuilding1_2.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 3) {
						texside = "NightBuilding1_3.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 4) {
						texside = "NightBuilding1_4.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 5) {
						texside = "NightBuilding1_5.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 6) {
						texside = "NightBuilding1_6.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 7) {
						texside = "NightBuilding1_7.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 8) {
						texside = "NightBuilding1_8.jpg";
						textop = "BlackRoof.jpg";
					}
				}
				else if (tex == 1) {
					int tex1 = rand() % 4 + 1;
					if (tex1 == 1) {
						texside = "NightBuilding1_1.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 2) {
						texside = "NightBuilding1_2.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 3) {
						texside = "NightBuilding1_3.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 4) {
						texside = "NightBuilding1_4.jpg";
						textop = "BlackRoof.jpg";
					}
				}
				else if (tex == 2) {
					int tex1 = rand() % 4 + 1;
					if (tex1 == 1) {
						texside = "NightBuilding3_1.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 2) {
						texside = "NightBuilding3_2.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 3) {
						texside = "NightBuilding3_3.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 4) {
						texside = "NightBuilding3_4.jpg";
						textop = "BlackRoof.jpg";
					}
				}
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

			GLchar* texside;
			GLchar* textop;
			if (Tswitch) {
				texside = "NightBuilding1_1.jpg";
				textop = "BlackRoof.jpg";
			}
			else {
				int tex = rand() % 3;
				if (tex == 0) {
					int tex1 = rand() % 8 + 1;
					if (tex1 == 1) {
						texside = "NightBuilding1_1.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 2) {
						texside = "NightBuilding1_2.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 3) {
						texside = "NightBuilding1_3.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 4) {
						texside = "NightBuilding1_4.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 5) {
						texside = "NightBuilding1_5.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 6) {
						texside = "NightBuilding1_6.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 7) {
						texside = "NightBuilding1_7.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 8) {
						texside = "NightBuilding1_8.jpg";
						textop = "BlackRoof.jpg";
					}
				}
				else if (tex == 1) {
					int tex1 = rand() % 4 + 1;
					if (tex1 == 1) {
						texside = "NightBuilding1_1.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 2) {
						texside = "NightBuilding1_2.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 3) {
						texside = "NightBuilding1_3.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 4) {
						texside = "NightBuilding1_4.jpg";
						textop = "BlackRoof.jpg";
					}
				}
				else if (tex == 2) {
					int tex1 = rand() % 4 + 1;
					if (tex1 == 1) {
						texside = "NightBuilding3_1.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 2) {
						texside = "NightBuilding3_2.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 3) {
						texside = "NightBuilding3_3.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 4) {
						texside = "NightBuilding3_4.jpg";
						textop = "BlackRoof.jpg";
					}
				}
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

			GLchar* texside;
			GLchar* textop;
			if (Tswitch) {
				texside = "NightBuilding1_1.jpg";
				textop = "BlackRoof.jpg";
			}
			else {
				int tex = rand() % 3;
				if (tex == 0) {
					int tex1 = rand() % 8 + 1;
					if (tex1 == 1) {
						texside = "NightBuilding1_1.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 2) {
						texside = "NightBuilding1_2.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 3) {
						texside = "NightBuilding1_3.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 4) {
						texside = "NightBuilding1_4.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 5) {
						texside = "NightBuilding1_5.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 6) {
						texside = "NightBuilding1_6.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 7) {
						texside = "NightBuilding1_7.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 8) {
						texside = "NightBuilding1_8.jpg";
						textop = "BlackRoof.jpg";
					}
				}
				else if (tex == 1) {
					int tex1 = rand() % 4 + 1;
					if (tex1 == 1) {
						texside = "NightBuilding1_1.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 2) {
						texside = "NightBuilding1_2.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 3) {
						texside = "NightBuilding1_3.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 4) {
						texside = "NightBuilding1_4.jpg";
						textop = "BlackRoof.jpg";
					}
				}
				else if (tex == 2) {
					int tex1 = rand() % 4 + 1;
					if (tex1 == 1) {
						texside = "NightBuilding3_1.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 2) {
						texside = "NightBuilding3_2.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 3) {
						texside = "NightBuilding3_3.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 4) {
						texside = "NightBuilding3_4.jpg";
						textop = "BlackRoof.jpg";
					}
				}
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

			GLchar* texside;
			GLchar* textop;
			if (Tswitch) {
				texside = "NightBuilding1_1.jpg";
				textop = "BlackRoof.jpg";
			}
			else {
				int tex = rand() % 3;
				if (tex == 0) {
					int tex1 = rand() % 8 + 1;
					if (tex1 == 1) {
						texside = "NightBuilding1_1.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 2) {
						texside = "NightBuilding1_2.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 3) {
						texside = "NightBuilding1_3.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 4) {
						texside = "NightBuilding1_4.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 5) {
						texside = "NightBuilding1_5.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 6) {
						texside = "NightBuilding1_6.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 7) {
						texside = "NightBuilding1_7.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 8) {
						texside = "NightBuilding1_8.jpg";
						textop = "BlackRoof.jpg";
					}
				}
				else if (tex == 1) {
					int tex1 = rand() % 4 + 1;
					if (tex1 == 1) {
						texside = "NightBuilding1_1.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 2) {
						texside = "NightBuilding1_2.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 3) {
						texside = "NightBuilding1_3.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 4) {
						texside = "NightBuilding1_4.jpg";
						textop = "BlackRoof.jpg";
					}
				}
				else if (tex == 2) {
					int tex1 = rand() % 4 + 1;
					if (tex1 == 1) {
						texside = "NightBuilding3_1.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 2) {
						texside = "NightBuilding3_2.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 3) {
						texside = "NightBuilding3_3.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 4) {
						texside = "NightBuilding3_4.jpg";
						textop = "BlackRoof.jpg";
					}
				}
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

			GLchar* texside;
			GLchar* textop;
			if (!Tswitch) {
				texside = "NightBuilding1_1.jpg";
				textop = "BlackRoof.jpg";
			}
			else {
				int tex = rand() % 3;
				if (tex == 0) {
					int tex1 = rand() % 8 + 1;
					if (tex1 == 1) {
						texside = "NightBuilding1_1.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 2) {
						texside = "NightBuilding1_2.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 3) {
						texside = "NightBuilding1_3.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 4) {
						texside = "NightBuilding1_4.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 5) {
						texside = "NightBuilding1_5.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 6) {
						texside = "NightBuilding1_6.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 7) {
						texside = "NightBuilding1_7.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 8) {
						texside = "NightBuilding1_8.jpg";
						textop = "BlackRoof.jpg";
					}
				}
				else if (tex == 1) {
					int tex1 = rand() % 4 + 1;
					if (tex1 == 1) {
						texside = "NightBuilding1_1.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 2) {
						texside = "NightBuilding1_2.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 3) {
						texside = "NightBuilding1_3.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 4) {
						texside = "NightBuilding1_4.jpg";
						textop = "BlackRoof.jpg";
					}
				}
				else if (tex == 2) {
					int tex1 = rand() % 4 + 1;
					if (tex1 == 1) {
						texside = "NightBuilding3_1.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 2) {
						texside = "NightBuilding3_2.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 3) {
						texside = "NightBuilding3_3.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 4) {
						texside = "NightBuilding3_4.jpg";
						textop = "BlackRoof.jpg";
					}
				}
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
	Roads.clear();
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
			SF_L = new Road(glm::vec3(0.0f + 20.0f * 1, 0.0f, 25.0f + 5.0f * 1), 15, 35, "SF2.jpg");
		}

		if (SF != 2) {
			addRoad(new Road(glm::vec3(0.0f + 20.0f * 0, 0.0f, 25.0f + 5.0f * 0), 5, 5, "roadNS.png"));
			addRoad(new Road(glm::vec3(0.0f + 20.0f * 0, 0.0f, 25.0f + 5.0f * 1), 5, 5, "roadNS.png"));
			addRoad(new Road(glm::vec3(0.0f + 20.0f * 0, 0.0f, 25.0f + 5.0f * 2), 5, 5, "roadNS.png"));
			addRoad(new Road(glm::vec3(0.0f, 0.0f, 20.0f + 5.0f * 4), 5, 5, "roadTN.png"));
		}
		else {
			addRoad(new Road(glm::vec3(0.0f, 0.0f, 20.0f + 5.0f * 4), 5, 5, "roadEW.png"));
			SF_L = new Road(glm::vec3(0.0f + 20.0f * 0, 0.0f, 25.0f + 5.0f * 1), 15, 35, "SF2.jpg");
		}

		if (SF != 3) {
			addRoad(new Road(glm::vec3(0.0f - 20.0f * 1, 0.0f, 25.0f + 5.0f * 0), 5, 5, "roadNS.png"));
			addRoad(new Road(glm::vec3(0.0f - 20.0f * 1, 0.0f, 25.0f + 5.0f * 1), 5, 5, "roadNS.png"));
			addRoad(new Road(glm::vec3(0.0f - 20.0f * 1, 0.0f, 25.0f + 5.0f * 2), 5, 5, "roadNS.png"));
			addRoad(new Road(glm::vec3(-1 * 20.0f, 0.0f, 20.0f + 5.0f * 4), 5, 5, "roadTN.png"));
		}
		else {
			addRoad(new Road(glm::vec3(-1 * 20.0f, 0.0f, 20.0f + 5.0f * 4), 5, 5, "roadEW.png"));
			SF_L = new Road(glm::vec3(0.0f - 20.0f * 1, 0.0f, 25.0f + 5.0f * 1), 15, 35, "SF2.jpg");
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
			SF_L = new Road(glm::vec3(0.0f + 20.0f * 1, 0.0f, 5.0f + 5.0f * 1), 15, 35, "SF2.jpg");
		}

		if (SF != 5) {
			addRoad(new Road(glm::vec3(0.0f + 20.0f * 0, 0.0f, 5.0f + 5.0f * 0), 5, 5, "roadNS.png"));
			addRoad(new Road(glm::vec3(0.0f + 20.0f * 0, 0.0f, 5.0f + 5.0f * 1), 5, 5, "roadNS.png"));
			addRoad(new Road(glm::vec3(0.0f + 20.0f * 0, 0.0f, 5.0f + 5.0f * 2), 5, 5, "roadNS.png"));
		}
		else {
			SF_L = new Road(glm::vec3(0.0f + 20.0f * 0, 0.0f, 5.0f + 5.0f * 1), 15, 35, "SF2.jpg");
		}

		if (SF != 6) {
			addRoad(new Road(glm::vec3(0.0f - 20.0f * 1, 0.0f, 5.0f + 5.0f * 0), 5, 5, "roadNS.png"));
			addRoad(new Road(glm::vec3(0.0f - 20.0f * 1, 0.0f, 5.0f + 5.0f * 1), 5, 5, "roadNS.png"));
			addRoad(new Road(glm::vec3(0.0f - 20.0f * 1, 0.0f, 5.0f + 5.0f * 2), 5, 5, "roadNS.png"));
		}
		else {
			SF_L = new Road(glm::vec3(0.0f - 20.0f * 1, 0.0f, 5.0f + 5.0f * 1), 15, 35, "SF2.jpg");
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
			SF_L = new Road(glm::vec3(0.0f + 20.0f * 1, 0.0f, -1 * 5.0f - 5.0f * 1), 15, 35, "SF2.jpg");
		}

		if (SF != 8) {
			addRoad(new Road(glm::vec3(0.0f + 20.0f * 0, 0.0f, -1 * 5.0f - 5.0f * 0), 5, 5, "roadNS.png"));
			addRoad(new Road(glm::vec3(0.0f + 20.0f * 0, 0.0f, -1 * 5.0f - 5.0f * 1), 5, 5, "roadNS.png"));
			addRoad(new Road(glm::vec3(0.0f + 20.0f * 0, 0.0f, -1 * 5.0f - 5.0f * 2), 5, 5, "roadNS.png"));
		}
		else {
			SF_L = new Road(glm::vec3(0.0f + 20.0f * 0, 0.0f, -1 * 5.0f - 5.0f * 1), 15, 35, "SF2.jpg");
		}

		if (SF != 9) {
			addRoad(new Road(glm::vec3(0.0f - 20.0f * 1, 0.0f, -1 * 5.0f - 5.0f * 0), 5, 5, "roadNS.png"));
			addRoad(new Road(glm::vec3(0.0f - 20.0f * 1, 0.0f, -1 * 5.0f - 5.0f * 1), 5, 5, "roadNS.png"));
			addRoad(new Road(glm::vec3(0.0f - 20.0f * 1, 0.0f, -1 * 5.0f - 5.0f * 2), 5, 5, "roadNS.png"));
		}
		else {
			SF_L = new Road(glm::vec3(0.0f - 20.0f * 1, 0.0f, -1 * 5.0f - 5.0f * 1), 15, 35, "SF2.jpg");
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
			SF_L = new Road(glm::vec3(0.0f + 20.0f * 1, 0.0f, -1 * 25.0f - 5.0f * 1), 15, 35, "SF2.jpg");
		}

		if (SF != 11) {
			addRoad(new Road(glm::vec3(0.0f + 20.0f * 0, 0.0f, -1 * 25.0f - 5.0f * 0), 5, 5, "roadNS.png"));
			addRoad(new Road(glm::vec3(0.0f + 20.0f * 0, 0.0f, -1 * 25.0f - 5.0f * 1), 5, 5, "roadNS.png"));
			addRoad(new Road(glm::vec3(0.0f + 20.0f * 0, 0.0f, -1 * 25.0f - 5.0f * 2), 5, 5, "roadNS.png"));
			addRoad(new Road(glm::vec3(0.0f, 0.0f, -1 * 20.0f - 5.0f * 4), 5, 5, "roadTS.png"));
		}
		else {
			addRoad(new Road(glm::vec3(0.0f, 0.0f, -1 * 20.0f - 5.0f * 4), 5, 5, "roadEW.png"));
			SF_L = new Road(glm::vec3(0.0f + 20.0f * 0, 0.0f, -1 * 25.0f - 5.0f * 1), 15, 35, "SF2.jpg");
		}

		if (SF != 12) {
			addRoad(new Road(glm::vec3(0.0f - 20.0f * 1, 0.0f, -1 * 25.0f - 5.0f * 0), 5, 5, "roadNS.png"));
			addRoad(new Road(glm::vec3(0.0f - 20.0f * 1, 0.0f, -1 * 25.0f - 5.0f * 1), 5, 5, "roadNS.png"));
			addRoad(new Road(glm::vec3(0.0f - 20.0f * 1, 0.0f, -1 * 25.0f - 5.0f * 2), 5, 5, "roadNS.png"));
			addRoad(new Road(glm::vec3(-1 * 20.0f, 0.0f, -1 * 20.0f - 5.0f * 4), 5, 5, "roadTS.png"));
		}
		else {
			addRoad(new Road(glm::vec3(-1 * 20.0f, 0.0f, -1 * 20.0f - 5.0f * 4), 5, 5, "roadEW.png"));
			SF_L = new Road(glm::vec3(0.0f - 20.0f * 1, 0.0f, -1 * 25.0f - 5.0f * 1), 15, 35, "SF2.jpg");
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

void City::GenB1_1(glm::vec3 pos1, GLchar* fs, GLchar* ft) {
	std::vector<Building*> Buildings1;
	float heightr = RandomFloat(5, 10);
	float buildingsize = 4.5;
	Buildings1.push_back(new Building(pos1, buildingsize, buildingsize, -5.0f, 1, fs, ft));
	glm::vec3 pos2 = pos1 - glm::vec3(RandomFloat(-0.5, 0.5), 0.0f, RandomFloat(-0.5, 0.5));
	Buildings1.push_back(new Building(pos2, buildingsize - 2, buildingsize - 2, heightr, 1, fs, ft));
	glm::vec3 pos3 = pos1 - glm::vec3(RandomFloat(-1.5, 1.5), 0.0f, 0.0f);
	Buildings1.push_back(new Building(pos3, buildingsize - 3, buildingsize - 1, heightr - RandomFloat(2, 7), 1, fs, ft));
	glm::vec3 pos4 = pos1 - glm::vec3(0.0f, 0.0f, RandomFloat(-1.5, 1.5));
	Buildings1.push_back(new Building(pos4, buildingsize - 1, buildingsize - 3, heightr - RandomFloat(2, 7), 1, fs, ft));
	addBuilding1(Buildings1);
}

void City::GenB2_1(glm::vec3 pos1, GLchar* fs, GLchar* ft) {
	std::vector<Building*> Buildings1;
	float heightr = RandomFloat(5, 10);
	float buildingsize = 4.5;
	Buildings1.push_back(new Building(pos1, buildingsize, buildingsize, RandomFloat(-5, 2.5), 1, fs, ft));
	float bs1 = RandomFloat(0, 2);
	float bs2 = RandomFloat(2, 3);
	Buildings1.push_back(new Building(pos1, buildingsize - bs1, buildingsize - bs1, RandomFloat(2.5, heightr), 1, fs, ft));
	Buildings1.push_back(new Building(pos1, buildingsize - bs2, buildingsize - bs2, heightr, 2, fs, ft));
	addBuilding1(Buildings1);
}

void City::GenB3_1(glm::vec3 pos1, GLchar* fs, GLchar* ft) {
	std::vector<Building*> Buildings1;
	float heightr = RandomFloat(5, 10);
	float buildingsize = 4.5;
	Buildings1.push_back(new Building(pos1, buildingsize, buildingsize, RandomFloat(-5, 2.5), 3, fs, ft));
	float bs1 = RandomFloat(0, 2);
	float bs2 = RandomFloat(2, 3);
	Buildings1.push_back(new Building(pos1, buildingsize - bs1, buildingsize - bs1, RandomFloat(2.5, 5), 3, fs, ft));
	Buildings1.push_back(new Building(pos1, buildingsize - bs2, buildingsize - bs2, heightr, 2, fs, ft));
	addBuilding1(Buildings1);
}

void City::GenB4_1(glm::vec3 pos1, GLchar* fs, GLchar* ft) {
	std::vector<Building*> Buildings1;
	float heightr = RandomFloat(5, 10);
	float buildingsize = 4.5;
	Buildings1.push_back(new Building(pos1, buildingsize, buildingsize, RandomFloat(-10, -5), 4, fs, ft));
	float bs1 = RandomFloat(1, 2);
	float bs2 = RandomFloat(2, 3);
	Buildings1.push_back(new Building(pos1, buildingsize - bs1, buildingsize - bs1, RandomFloat(0, 5), 1, fs, ft));
	Buildings1.push_back(new Building(pos1, buildingsize - bs2, buildingsize - bs2, heightr, 2, fs, ft));
	addBuilding1(Buildings1);
}

void City::GenB5_1(glm::vec3 pos1, GLchar* fs, GLchar* ft) {
	std::vector<Building*> Buildings1;
	float heightr = RandomFloat(5, 10);
	float buildingsize = 4.5;
	Buildings1.push_back(new Building(pos1, buildingsize, buildingsize, RandomFloat(-10, -5), 4, fs, ft));
	float bs1 = RandomFloat(1, 2);
	float bs2 = RandomFloat(2, 3);
	Buildings1.push_back(new Building(pos1, buildingsize - bs1, buildingsize - bs1, RandomFloat(0, 5), 3, fs, ft));
	Buildings1.push_back(new Building(pos1, buildingsize - bs2, buildingsize - bs2, heightr, 2, fs, ft));
	addBuilding1(Buildings1);
}

void City::GenB6_1(glm::vec3 pos1, GLchar* fs, GLchar* ft) {
	std::vector<Building*> Buildings1;
	float heightr = RandomFloat(5, 10);
	float buildingsize = 4.5;
	float bs0 = RandomFloat(0, 5);
	Buildings1.push_back(new Building(pos1, buildingsize, buildingsize, bs0, 5, fs, ft));
	float bs1 = RandomFloat(0.5f, 2.0f);
	float bs2 = RandomFloat(2.0f, 3.0f);
	Buildings1.push_back(new Building(pos1, buildingsize - bs1, buildingsize - bs1, bs0, 1, fs, ft));
	Buildings1.push_back(new Building(pos1, buildingsize - bs2, buildingsize - bs2, heightr, 2, fs, ft));
	addBuilding1(Buildings1);
}

void City::GenB7_1(glm::vec3 pos1, GLchar* fs, GLchar* ft) {
	std::vector<Building*> Buildings1;
	float heightr = RandomFloat(5, 10);
	float buildingsize = 4.5;
	float bs0 = RandomFloat(0, 5);
	Buildings1.push_back(new Building(pos1, buildingsize, buildingsize, RandomFloat(-10, -5), 4, fs, ft));
	Buildings1.push_back(new Building(pos1, buildingsize, buildingsize, bs0, 5, fs, ft));
	float bs1 = RandomFloat(1, 2);
	float bs2 = RandomFloat(2, 3);
	Buildings1.push_back(new Building(pos1, buildingsize - bs1, buildingsize - bs1, bs0, 1, fs, ft));
	Buildings1.push_back(new Building(pos1, buildingsize - bs2, buildingsize - bs2, heightr, 2, fs, ft));
	addBuilding1(Buildings1);
}

void City::GenB8_1(glm::vec3 pos1, GLchar* fs, GLchar* ft) {
	std::vector<Building*> Buildings1;
	float heightr = RandomFloat(5, 10);
	float buildingsize = 4.5;
	Buildings1.push_back(new Building(pos1, buildingsize, buildingsize, RandomFloat(-5, 0), 1, fs, ft));
	float bs1 = RandomFloat(0, 2);
	float bs2 = RandomFloat(2, 3);
	Buildings1.push_back(new Building(pos1, buildingsize - bs1, buildingsize - bs1, RandomFloat(0, 5), 1, fs, ft));
	Buildings1.push_back(new Building(pos1, buildingsize - bs2, buildingsize - bs2, heightr, 0, fs, ft));
	addBuilding1(Buildings1);
}

void City::GenB9_1(glm::vec3 pos1, GLchar* fs, GLchar* ft) {
	std::vector<Building*> Buildings1;
	float heightr = RandomFloat(5, 10);
	float buildingsize = 4.5;
	Buildings1.push_back(new Building(pos1, buildingsize, buildingsize, RandomFloat(-5, 2.5), 3, fs, ft));
	float bs1 = RandomFloat(0, 2);
	float bs2 = RandomFloat(2, 3);
	Buildings1.push_back(new Building(pos1, buildingsize - bs1, buildingsize - bs1, RandomFloat(2.5, 5), 3, fs, ft));
	Buildings1.push_back(new Building(pos1, buildingsize - bs2, buildingsize - bs2, heightr, 0, fs, ft));
	addBuilding1(Buildings1);
}

void City::GenB10_1(glm::vec3 pos1, GLchar* fs, GLchar* ft) {
	std::vector<Building*> Buildings1;
	float heightr = RandomFloat(5, 10);
	float buildingsize = 4.5;
	Buildings1.push_back(new Building(pos1, buildingsize, buildingsize, RandomFloat(-10, -5), 4, fs, ft));
	float bs1 = RandomFloat(1, 2);
	float bs2 = RandomFloat(2, 3);
	Buildings1.push_back(new Building(pos1, buildingsize - bs1, buildingsize - bs1, RandomFloat(0, 5), 1, fs, ft));
	Buildings1.push_back(new Building(pos1, buildingsize - bs2, buildingsize - bs2, heightr, 0, fs, ft));
	addBuilding1(Buildings1);
}

void City::GenB11_1(glm::vec3 pos1, GLchar* fs, GLchar* ft) {
	std::vector<Building*> Buildings1;
	float heightr = RandomFloat(5, 10);
	float buildingsize = 4.5;
	Buildings1.push_back(new Building(pos1, buildingsize, buildingsize, RandomFloat(-10, -5), 4, fs, ft));
	float bs1 = RandomFloat(1, 2);
	float bs2 = RandomFloat(2, 3);
	Buildings1.push_back(new Building(pos1, buildingsize - bs1, buildingsize - bs1, RandomFloat(0, 5), 3, fs, ft));
	Buildings1.push_back(new Building(pos1, buildingsize - bs2, buildingsize - bs2, heightr, 0, fs, ft));
	addBuilding1(Buildings1);
}

void City::GenB12_1(glm::vec3 pos1, GLchar* fs, GLchar* ft) {
	std::vector<Building*> Buildings1;
	float heightr = RandomFloat(5, 10);
	float buildingsize = 4.5;
	float bs0 = RandomFloat(0, 5);
	Buildings1.push_back(new Building(pos1, buildingsize, buildingsize, bs0, 5, fs, ft));
	float bs1 = RandomFloat(0.5f, 2.0f);
	float bs2 = RandomFloat(2.0f, 3.0f);
	Buildings1.push_back(new Building(pos1, buildingsize - bs1, buildingsize - bs1, bs0, 1, fs, ft));
	Buildings1.push_back(new Building(pos1, buildingsize - bs2, buildingsize - bs2, heightr, 0, fs, ft));
	addBuilding1(Buildings1);
}

void City::GenB13_1(glm::vec3 pos1, GLchar* fs, GLchar* ft) {
	std::vector<Building*> Buildings1;
	float heightr = RandomFloat(5, 10);
	float buildingsize = 4.5;
	float bs0 = RandomFloat(0, 5);
	Buildings1.push_back(new Building(pos1, buildingsize, buildingsize, RandomFloat(-10, -5), 4, fs, ft));
	Buildings1.push_back(new Building(pos1, buildingsize, buildingsize, bs0, 5, fs, ft));
	float bs1 = RandomFloat(1, 2);
	float bs2 = RandomFloat(2, 3);
	Buildings1.push_back(new Building(pos1, buildingsize - bs1, buildingsize - bs1, bs0, 1, fs, ft));
	Buildings1.push_back(new Building(pos1, buildingsize - bs2, buildingsize - bs2, heightr, 0, fs, ft));
	addBuilding1(Buildings1);
}

void City::GenB0_1(glm::vec3 pos1, GLchar* fs, GLchar* ft) {
	std::vector<Building*> Buildings1;
	float heightr = RandomFloat(5, 10);
	float buildingsize = 4.5;
	Buildings1.push_back(new Building(pos1, buildingsize, buildingsize, heightr, 1, fs, ft));
	addBuilding1(Buildings1);
}

void City::BuildingGen(glm::vec3 pos1, GLchar* fs, GLchar* ft){
	if (!Gswitch) {

		GenB0_1(pos1, fs, ft);
	}
	else {
		int temp = rand() % 14;
		//int temp = 13;
		if (temp == 0) {
			//std::cout << 0 << std::endl;
			GenB0_1(pos1, fs, ft);
		}
		else if (temp == 1) {
			//std::cout << 1 << std::endl;
			GenB1_1(pos1, fs, ft);
		}
		else if (temp == 2) {
			//std::cout << 2 << std::endl;
			GenB2_1(pos1, fs, ft);
		}
		else if (temp == 3) {
			//std::cout << 3 << std::endl;
			GenB3_1(pos1, fs, ft);
		}
		else if (temp == 4) {
			//std::cout << 4 << std::endl;
			GenB4_1(pos1, fs, ft);
		}
		else if (temp == 5) {
			//std::cout << 5 << std::endl;
			GenB5_1(pos1, fs, ft);
		}
		else if (temp == 6) {
			//std::cout << 6 << std::endl;
			GenB6_1(pos1, fs, ft);
		}
		else if (temp == 7) {
			//std::cout << 7 << std::endl;
			GenB7_1(pos1, fs, ft);
		}
		else if (temp == 8) {
			//std::cout << 8 << std::endl;
			GenB8_1(pos1, fs, ft);
		}
		else if (temp == 9) {
			//std::cout << 9 << std::endl;
			GenB9_1(pos1, fs, ft);
		}
		else if (temp == 10) {
			//std::cout << 10 << std::endl;
			GenB10_1(pos1, fs, ft);
		}
		else if (temp == 11) {
			//std::cout << 11 << std::endl;
			GenB11_1(pos1, fs, ft);
		}
		else if (temp == 12) {
			//std::cout << 12 << std::endl;
			GenB12_1(pos1, fs, ft);
		}
		else if (temp == 13) {
			//std::cout << 13 << std::endl;
			GenB13_1(pos1, fs, ft);
		}
	}
}

void City::draw(GLuint shaderProgram) {

	/*for (auto i : Buildings) {
		i->draw(shaderProgram);
	}
	for (auto i : Roads) {
		i->draw(shaderProgram);
	}
	SF_L->draw(shaderProgram);*/

	if(SF != 1){//Tile1
		for (auto j : R_Blocks[0]) {
			j->draw(shaderProgram);
		}
		for (int i = 0; i < 9; i++) {
			for (auto j : B_Blocks[i]) {
				j->draw(shaderProgram);
			}
		}
	}

	if (SF != 1 && SF != 2) {//Tile2
		for (auto j : R_Blocks[1]) {
			j->draw(shaderProgram);
		}
		for (int i = 9; i < 18; i++) {
			for (auto j : B_Blocks[i]) {
				j->draw(shaderProgram);
			}
		}
	}

	if (SF != 2 && SF != 3) {//Tile3
		for (auto j : R_Blocks[2]) {
			j->draw(shaderProgram);
		}
		for (int i = 18; i < 27; i++) {
			for (auto j : B_Blocks[i]) {
				j->draw(shaderProgram);
			}
		}
	}

	if (SF != 3) {//Tile4
		for (auto j : R_Blocks[3]) {
			j->draw(shaderProgram);
		}
		for (int i = 27; i < 36; i++) {
			for (auto j : B_Blocks[i]) {
				j->draw(shaderProgram);
			}
		}
	}

	if (SF != 4) {//Tile5
		for (auto j : R_Blocks[4]) {
			j->draw(shaderProgram);
		}
		for (int i = 36; i < 45; i++) {
			for (auto j : B_Blocks[i]) {
				j->draw(shaderProgram);
			}
		}
	}

	if (SF != 4 && SF != 5) {//Tile6
		for (auto j : R_Blocks[5]) {
			j->draw(shaderProgram);
		}
		for (int i = 45; i < 54; i++) {
			for (auto j : B_Blocks[i]) {
				j->draw(shaderProgram);
			}
		}
	}

	if (SF != 5 && SF != 6) {//Tile7
		for (auto j : R_Blocks[6]) {
			j->draw(shaderProgram);
		}
		for (int i = 54; i < 63; i++) {
			for (auto j : B_Blocks[i]) {
				j->draw(shaderProgram);
			}
		}
	}

	if (SF != 6) {//Tile8
		for (auto j : R_Blocks[7]) {
			j->draw(shaderProgram);
		}
		for (int i = 63; i < 72; i++) {
			for (auto j : B_Blocks[i]) {
				j->draw(shaderProgram);
			}
		}
	}

	if (SF != 7) {//Tile9
		for (auto j : R_Blocks[8]) {
			j->draw(shaderProgram);
		}
		for (int i = 72; i < 81; i++) {
			for (auto j : B_Blocks[i]) {
				j->draw(shaderProgram);
			}
		}
	}

	if (SF != 7 && SF != 8) {//Tile10
		for (auto j : R_Blocks[9]) {
			j->draw(shaderProgram);
		}
		for (int i = 81; i < 90; i++) {
			for (auto j : B_Blocks[i]) {
				j->draw(shaderProgram);
			}
		}
	}

	if (SF != 8 && SF != 9) {//Tile11
		for (auto j : R_Blocks[10]) {
			j->draw(shaderProgram);
		}
		for (int i = 90; i < 99; i++) {
			for (auto j : B_Blocks[i]) {
				j->draw(shaderProgram);
			}
		}
	}

	if (SF != 9) {//Tile12
		for (auto j : R_Blocks[11]) {
			j->draw(shaderProgram);
		}
		for (int i = 99; i < 108; i++) {
			for (auto j : B_Blocks[i]) {
				j->draw(shaderProgram);
			}
		}
	}

	if (SF != 10) {//Tile13
		for (auto j : R_Blocks[12]) {
			j->draw(shaderProgram);
		}
		for (int i = 108; i < 117; i++) {
			for (auto j : B_Blocks[i]) {
				j->draw(shaderProgram);
			}
		}
	}

	if (SF != 10 && SF != 11) {//Tile14
		for (auto j : R_Blocks[13]) {
			j->draw(shaderProgram);
		}
		for (int i = 117; i < 126; i++) {
			for (auto j : B_Blocks[i]) {
				j->draw(shaderProgram);
			}
		}
	}

	if (SF != 11 && SF != 12) {//Tile15
		for (auto j : R_Blocks[14]) {
			j->draw(shaderProgram);
		}
		for (int i = 126; i < 135; i++) {
			for (auto j : B_Blocks[i]) {
				j->draw(shaderProgram);
			}
		}
	}

	if (SF != 12) {//Tile16
		for (auto j : R_Blocks[15]) {
			j->draw(shaderProgram);
		}
		for (int i = 135; i < 144; i++) {
			for (auto j : B_Blocks[i]) {
				j->draw(shaderProgram);
			}
		}
	}

	

	for (auto i : Roads) {
		i->draw(shaderProgram);
	}
	SF_L->draw(shaderProgram);
}

void City::update(bool bg, bool tg, bool cg, bool l) {
	if (bg) {
		BuildRE(bg,tg, l);
	}
	if (cg) {
		SF = rand() % 12 + 1;
		GenRoad1();
	}

}

void City::BuildRE(bool bg, bool tg, bool l) {
	
	Tswitch = tg;
	Gswitch = bg;
	float buildingsize = 4.5;
	float offsetz = 0.5f;
	float offsetx = 0.5f;
	int heightr;
	lag = l;
	//int SF = 1;
	if(lag){
		B_Blocks.clear();
	{//tile1
		
		GLchar* texside;
		GLchar* textop;
		if (Tswitch) {
			texside = "NightBuilding1_1.jpg";
			textop = "BlackRoof.jpg";
		}
		else {
			int tex = rand() % 3;
			if (tex == 0) {
				int tex1 = rand() % 8 + 1;
				if (tex1 == 1) {
					texside = "NightBuilding1_1.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 2) {
					texside = "NightBuilding1_2.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 3) {
					texside = "NightBuilding1_3.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 4) {
					texside = "NightBuilding1_4.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 5) {
					texside = "NightBuilding1_5.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 6) {
					texside = "NightBuilding1_6.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 7) {
					texside = "NightBuilding1_7.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 8) {
					texside = "NightBuilding1_8.jpg";
					textop = "BlackRoof.jpg";
				}
			}
			else if (tex == 1) {
				int tex1 = rand() % 4 + 1;
				if (tex1 == 1) {
					texside = "NightBuilding1_1.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 2) {
					texside = "NightBuilding1_2.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 3) {
					texside = "NightBuilding1_3.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 4) {
					texside = "NightBuilding1_4.jpg";
					textop = "BlackRoof.jpg";
				}
			}
			else if (tex == 2) {
				int tex1 = rand() % 4 + 1;
				if (tex1 == 1) {
					texside = "NightBuilding3_1.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 2) {
					texside = "NightBuilding3_2.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 3) {
					texside = "NightBuilding3_3.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 4) {
					texside = "NightBuilding3_4.jpg";
					textop = "BlackRoof.jpg";
				}
			}
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
	{
		//tile 2
		GLchar* texside;
		GLchar* textop;
		if (Tswitch) {
			texside = "NightBuilding1_1.jpg";
			textop = "BlackRoof.jpg";
		}
		else {
			int tex = rand() % 3;
			if (tex == 0) {
				int tex1 = rand() % 8 + 1;
				if (tex1 == 1) {
					texside = "NightBuilding1_1.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 2) {
					texside = "NightBuilding1_2.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 3) {
					texside = "NightBuilding1_3.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 4) {
					texside = "NightBuilding1_4.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 5) {
					texside = "NightBuilding1_5.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 6) {
					texside = "NightBuilding1_6.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 7) {
					texside = "NightBuilding1_7.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 8) {
					texside = "NightBuilding1_8.jpg";
					textop = "BlackRoof.jpg";
				}
			}
			else if (tex == 1) {
				int tex1 = rand() % 4 + 1;
				if (tex1 == 1) {
					texside = "NightBuilding1_1.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 2) {
					texside = "NightBuilding1_2.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 3) {
					texside = "NightBuilding1_3.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 4) {
					texside = "NightBuilding1_4.jpg";
					textop = "BlackRoof.jpg";
				}
			}
			else if (tex == 2) {
				int tex1 = rand() % 4 + 1;
				if (tex1 == 1) {
					texside = "NightBuilding3_1.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 2) {
					texside = "NightBuilding3_2.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 3) {
					texside = "NightBuilding3_3.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 4) {
					texside = "NightBuilding3_4.jpg";
					textop = "BlackRoof.jpg";
				}
			}
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
	{
		// tile 3

		GLchar* texside;
		GLchar* textop;
		if (Tswitch) {
			texside = "NightBuilding1_1.jpg";
			textop = "BlackRoof.jpg";
		}
		else {
			int tex = rand() % 3;
			if (tex == 0) {
				int tex1 = rand() % 8 + 1;
				if (tex1 == 1) {
					texside = "NightBuilding1_1.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 2) {
					texside = "NightBuilding1_2.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 3) {
					texside = "NightBuilding1_3.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 4) {
					texside = "NightBuilding1_4.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 5) {
					texside = "NightBuilding1_5.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 6) {
					texside = "NightBuilding1_6.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 7) {
					texside = "NightBuilding1_7.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 8) {
					texside = "NightBuilding1_8.jpg";
					textop = "BlackRoof.jpg";
				}
			}
			else if (tex == 1) {
				int tex1 = rand() % 4 + 1;
				if (tex1 == 1) {
					texside = "NightBuilding1_1.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 2) {
					texside = "NightBuilding1_2.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 3) {
					texside = "NightBuilding1_3.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 4) {
					texside = "NightBuilding1_4.jpg";
					textop = "BlackRoof.jpg";
				}
			}
			else if (tex == 2) {
				int tex1 = rand() % 4 + 1;
				if (tex1 == 1) {
					texside = "NightBuilding3_1.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 2) {
					texside = "NightBuilding3_2.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 3) {
					texside = "NightBuilding3_3.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 4) {
					texside = "NightBuilding3_4.jpg";
					textop = "BlackRoof.jpg";
				}
			}
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
	{
		//tile 4
		GLchar* texside;
		GLchar* textop;
		if (Tswitch) {
			texside = "NightBuilding1_1.jpg";
			textop = "BlackRoof.jpg";
		}
		else {
			int tex = rand() % 3;
			if (tex == 0) {
				int tex1 = rand() % 8 + 1;
				if (tex1 == 1) {
					texside = "NightBuilding1_1.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 2) {
					texside = "NightBuilding1_2.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 3) {
					texside = "NightBuilding1_3.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 4) {
					texside = "NightBuilding1_4.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 5) {
					texside = "NightBuilding1_5.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 6) {
					texside = "NightBuilding1_6.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 7) {
					texside = "NightBuilding1_7.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 8) {
					texside = "NightBuilding1_8.jpg";
					textop = "BlackRoof.jpg";
				}
			}
			else if (tex == 1) {
				int tex1 = rand() % 4 + 1;
				if (tex1 == 1) {
					texside = "NightBuilding1_1.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 2) {
					texside = "NightBuilding1_2.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 3) {
					texside = "NightBuilding1_3.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 4) {
					texside = "NightBuilding1_4.jpg";
					textop = "BlackRoof.jpg";
				}
			}
			else if (tex == 2) {
				int tex1 = rand() % 4 + 1;
				if (tex1 == 1) {
					texside = "NightBuilding3_1.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 2) {
					texside = "NightBuilding3_2.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 3) {
					texside = "NightBuilding3_3.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 4) {
					texside = "NightBuilding3_4.jpg";
					textop = "BlackRoof.jpg";
				}
			}
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
	{
		//tile5
		
		GLchar* texside;
		GLchar* textop;
		if (Tswitch) {
			texside = "NightBuilding1_1.jpg";
			textop = "BlackRoof.jpg";
		}
		else {
			int tex = rand() % 3;
			if (tex == 0) {
				int tex1 = rand() % 8 + 1;
				if (tex1 == 1) {
					texside = "NightBuilding1_1.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 2) {
					texside = "NightBuilding1_2.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 3) {
					texside = "NightBuilding1_3.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 4) {
					texside = "NightBuilding1_4.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 5) {
					texside = "NightBuilding1_5.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 6) {
					texside = "NightBuilding1_6.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 7) {
					texside = "NightBuilding1_7.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 8) {
					texside = "NightBuilding1_8.jpg";
					textop = "BlackRoof.jpg";
				}
			}
			else if (tex == 1) {
				int tex1 = rand() % 4 + 1;
				if (tex1 == 1) {
					texside = "NightBuilding1_1.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 2) {
					texside = "NightBuilding1_2.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 3) {
					texside = "NightBuilding1_3.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 4) {
					texside = "NightBuilding1_4.jpg";
					textop = "BlackRoof.jpg";
				}
			}
			else if (tex == 2) {
				int tex1 = rand() % 4 + 1;
				if (tex1 == 1) {
					texside = "NightBuilding3_1.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 2) {
					texside = "NightBuilding3_2.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 3) {
					texside = "NightBuilding3_3.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 4) {
					texside = "NightBuilding3_4.jpg";
					textop = "BlackRoof.jpg";
				}
			}
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
	{
		//tile 6
		
		GLchar* texside;
		GLchar* textop;
		if (Tswitch) {
			texside = "NightBuilding1_1.jpg";
			textop = "BlackRoof.jpg";
		}
		else {
			int tex = rand() % 3;
			if (tex == 0) {
				int tex1 = rand() % 8 + 1;
				if (tex1 == 1) {
					texside = "NightBuilding1_1.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 2) {
					texside = "NightBuilding1_2.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 3) {
					texside = "NightBuilding1_3.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 4) {
					texside = "NightBuilding1_4.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 5) {
					texside = "NightBuilding1_5.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 6) {
					texside = "NightBuilding1_6.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 7) {
					texside = "NightBuilding1_7.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 8) {
					texside = "NightBuilding1_8.jpg";
					textop = "BlackRoof.jpg";
				}
			}
			else if (tex == 1) {
				int tex1 = rand() % 4 + 1;
				if (tex1 == 1) {
					texside = "NightBuilding1_1.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 2) {
					texside = "NightBuilding1_2.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 3) {
					texside = "NightBuilding1_3.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 4) {
					texside = "NightBuilding1_4.jpg";
					textop = "BlackRoof.jpg";
				}
			}
			else if (tex == 2) {
				int tex1 = rand() % 4 + 1;
				if (tex1 == 1) {
					texside = "NightBuilding3_1.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 2) {
					texside = "NightBuilding3_2.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 3) {
					texside = "NightBuilding3_3.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 4) {
					texside = "NightBuilding3_4.jpg";
					textop = "BlackRoof.jpg";
				}
			}
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
	{
		//tile 7
		
		GLchar* texside;
		GLchar* textop;
		if (Tswitch) {
			texside = "NightBuilding1_1.jpg";
			textop = "BlackRoof.jpg";
		}
		else {
			int tex = rand() % 3;
			if (tex == 0) {
				int tex1 = rand() % 8 + 1;
				if (tex1 == 1) {
					texside = "NightBuilding1_1.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 2) {
					texside = "NightBuilding1_2.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 3) {
					texside = "NightBuilding1_3.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 4) {
					texside = "NightBuilding1_4.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 5) {
					texside = "NightBuilding1_5.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 6) {
					texside = "NightBuilding1_6.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 7) {
					texside = "NightBuilding1_7.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 8) {
					texside = "NightBuilding1_8.jpg";
					textop = "BlackRoof.jpg";
				}
			}
			else if (tex == 1) {
				int tex1 = rand() % 4 + 1;
				if (tex1 == 1) {
					texside = "NightBuilding1_1.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 2) {
					texside = "NightBuilding1_2.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 3) {
					texside = "NightBuilding1_3.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 4) {
					texside = "NightBuilding1_4.jpg";
					textop = "BlackRoof.jpg";
				}
			}
			else if (tex == 2) {
				int tex1 = rand() % 4 + 1;
				if (tex1 == 1) {
					texside = "NightBuilding3_1.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 2) {
					texside = "NightBuilding3_2.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 3) {
					texside = "NightBuilding3_3.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 4) {
					texside = "NightBuilding3_4.jpg";
					textop = "BlackRoof.jpg";
				}
			}
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
	{
		//tile 8
		
		GLchar* texside;
		GLchar* textop;
		if (Tswitch) {
			texside = "NightBuilding1_1.jpg";
			textop = "BlackRoof.jpg";
		}
		else {
			int tex = rand() % 3;
			if (tex == 0) {
				int tex1 = rand() % 8 + 1;
				if (tex1 == 1) {
					texside = "NightBuilding1_1.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 2) {
					texside = "NightBuilding1_2.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 3) {
					texside = "NightBuilding1_3.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 4) {
					texside = "NightBuilding1_4.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 5) {
					texside = "NightBuilding1_5.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 6) {
					texside = "NightBuilding1_6.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 7) {
					texside = "NightBuilding1_7.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 8) {
					texside = "NightBuilding1_8.jpg";
					textop = "BlackRoof.jpg";
				}
			}
			else if (tex == 1) {
				int tex1 = rand() % 4 + 1;
				if (tex1 == 1) {
					texside = "NightBuilding1_1.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 2) {
					texside = "NightBuilding1_2.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 3) {
					texside = "NightBuilding1_3.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 4) {
					texside = "NightBuilding1_4.jpg";
					textop = "BlackRoof.jpg";
				}
			}
			else if (tex == 2) {
				int tex1 = rand() % 4 + 1;
				if (tex1 == 1) {
					texside = "NightBuilding3_1.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 2) {
					texside = "NightBuilding3_2.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 3) {
					texside = "NightBuilding3_3.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 4) {
					texside = "NightBuilding3_4.jpg";
					textop = "BlackRoof.jpg";
				}
			}
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
	{
		//tile 9
	
		GLchar* texside;
		GLchar* textop;
		if (Tswitch) {
			texside = "NightBuilding1_1.jpg";
			textop = "BlackRoof.jpg";
		}
		else {
			int tex = rand() % 3;
			if (tex == 0) {
				int tex1 = rand() % 8 + 1;
				if (tex1 == 1) {
					texside = "NightBuilding1_1.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 2) {
					texside = "NightBuilding1_2.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 3) {
					texside = "NightBuilding1_3.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 4) {
					texside = "NightBuilding1_4.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 5) {
					texside = "NightBuilding1_5.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 6) {
					texside = "NightBuilding1_6.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 7) {
					texside = "NightBuilding1_7.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 8) {
					texside = "NightBuilding1_8.jpg";
					textop = "BlackRoof.jpg";
				}
			}
			else if (tex == 1) {
				int tex1 = rand() % 4 + 1;
				if (tex1 == 1) {
					texside = "NightBuilding1_1.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 2) {
					texside = "NightBuilding1_2.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 3) {
					texside = "NightBuilding1_3.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 4) {
					texside = "NightBuilding1_4.jpg";
					textop = "BlackRoof.jpg";
				}
			}
			else if (tex == 2) {
				int tex1 = rand() % 4 + 1;
				if (tex1 == 1) {
					texside = "NightBuilding3_1.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 2) {
					texside = "NightBuilding3_2.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 3) {
					texside = "NightBuilding3_3.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 4) {
					texside = "NightBuilding3_4.jpg";
					textop = "BlackRoof.jpg";
				}
			}
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
	{
		//tile 10
		
		GLchar* texside;
		GLchar* textop;
		if (Tswitch) {
			texside = "NightBuilding1_1.jpg";
			textop = "BlackRoof.jpg";
		}
		else {
			int tex = rand() % 3;
			if (tex == 0) {
				int tex1 = rand() % 8 + 1;
				if (tex1 == 1) {
					texside = "NightBuilding1_1.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 2) {
					texside = "NightBuilding1_2.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 3) {
					texside = "NightBuilding1_3.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 4) {
					texside = "NightBuilding1_4.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 5) {
					texside = "NightBuilding1_5.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 6) {
					texside = "NightBuilding1_6.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 7) {
					texside = "NightBuilding1_7.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 8) {
					texside = "NightBuilding1_8.jpg";
					textop = "BlackRoof.jpg";
				}
			}
			else if (tex == 1) {
				int tex1 = rand() % 4 + 1;
				if (tex1 == 1) {
					texside = "NightBuilding1_1.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 2) {
					texside = "NightBuilding1_2.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 3) {
					texside = "NightBuilding1_3.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 4) {
					texside = "NightBuilding1_4.jpg";
					textop = "BlackRoof.jpg";
				}
			}
			else if (tex == 2) {
				int tex1 = rand() % 4 + 1;
				if (tex1 == 1) {
					texside = "NightBuilding3_1.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 2) {
					texside = "NightBuilding3_2.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 3) {
					texside = "NightBuilding3_3.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 4) {
					texside = "NightBuilding3_4.jpg";
					textop = "BlackRoof.jpg";
				}
			}
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
	{
		//tile 11
		
		GLchar* texside;
		GLchar* textop;
		if (Tswitch) {
			texside = "NightBuilding1_1.jpg";
			textop = "BlackRoof.jpg";
		}
		else {
			int tex = rand() % 3;
			if (tex == 0) {
				int tex1 = rand() % 8 + 1;
				if (tex1 == 1) {
					texside = "NightBuilding1_1.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 2) {
					texside = "NightBuilding1_2.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 3) {
					texside = "NightBuilding1_3.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 4) {
					texside = "NightBuilding1_4.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 5) {
					texside = "NightBuilding1_5.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 6) {
					texside = "NightBuilding1_6.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 7) {
					texside = "NightBuilding1_7.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 8) {
					texside = "NightBuilding1_8.jpg";
					textop = "BlackRoof.jpg";
				}
			}
			else if (tex == 1) {
				int tex1 = rand() % 4 + 1;
				if (tex1 == 1) {
					texside = "NightBuilding1_1.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 2) {
					texside = "NightBuilding1_2.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 3) {
					texside = "NightBuilding1_3.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 4) {
					texside = "NightBuilding1_4.jpg";
					textop = "BlackRoof.jpg";
				}
			}
			else if (tex == 2) {
				int tex1 = rand() % 4 + 1;
				if (tex1 == 1) {
					texside = "NightBuilding3_1.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 2) {
					texside = "NightBuilding3_2.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 3) {
					texside = "NightBuilding3_3.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 4) {
					texside = "NightBuilding3_4.jpg";
					textop = "BlackRoof.jpg";
				}
			}
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
	{
		//tile 12
		
		GLchar* texside;
		GLchar* textop;
		if (Tswitch) {
			texside = "NightBuilding1_1.jpg";
			textop = "BlackRoof.jpg";
		}
		else {
			int tex = rand() % 3;
			if (tex == 0) {
				int tex1 = rand() % 8 + 1;
				if (tex1 == 1) {
					texside = "NightBuilding1_1.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 2) {
					texside = "NightBuilding1_2.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 3) {
					texside = "NightBuilding1_3.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 4) {
					texside = "NightBuilding1_4.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 5) {
					texside = "NightBuilding1_5.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 6) {
					texside = "NightBuilding1_6.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 7) {
					texside = "NightBuilding1_7.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 8) {
					texside = "NightBuilding1_8.jpg";
					textop = "BlackRoof.jpg";
				}
			}
			else if (tex == 1) {
				int tex1 = rand() % 4 + 1;
				if (tex1 == 1) {
					texside = "NightBuilding1_1.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 2) {
					texside = "NightBuilding1_2.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 3) {
					texside = "NightBuilding1_3.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 4) {
					texside = "NightBuilding1_4.jpg";
					textop = "BlackRoof.jpg";
				}
			}
			else if (tex == 2) {
				int tex1 = rand() % 4 + 1;
				if (tex1 == 1) {
					texside = "NightBuilding3_1.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 2) {
					texside = "NightBuilding3_2.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 3) {
					texside = "NightBuilding3_3.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 4) {
					texside = "NightBuilding3_4.jpg";
					textop = "BlackRoof.jpg";
				}
			}
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
	{
		//tile 13
		
		GLchar* texside;
		GLchar* textop;
		if (Tswitch) {
			texside = "NightBuilding1_1.jpg";
			textop = "BlackRoof.jpg";
		}
		else {
			int tex = rand() % 3;
			if (tex == 0) {
				int tex1 = rand() % 8 + 1;
				if (tex1 == 1) {
					texside = "NightBuilding1_1.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 2) {
					texside = "NightBuilding1_2.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 3) {
					texside = "NightBuilding1_3.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 4) {
					texside = "NightBuilding1_4.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 5) {
					texside = "NightBuilding1_5.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 6) {
					texside = "NightBuilding1_6.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 7) {
					texside = "NightBuilding1_7.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 8) {
					texside = "NightBuilding1_8.jpg";
					textop = "BlackRoof.jpg";
				}
			}
			else if (tex == 1) {
				int tex1 = rand() % 4 + 1;
				if (tex1 == 1) {
					texside = "NightBuilding1_1.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 2) {
					texside = "NightBuilding1_2.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 3) {
					texside = "NightBuilding1_3.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 4) {
					texside = "NightBuilding1_4.jpg";
					textop = "BlackRoof.jpg";
				}
			}
			else if (tex == 2) {
				int tex1 = rand() % 4 + 1;
				if (tex1 == 1) {
					texside = "NightBuilding3_1.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 2) {
					texside = "NightBuilding3_2.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 3) {
					texside = "NightBuilding3_3.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 4) {
					texside = "NightBuilding3_4.jpg";
					textop = "BlackRoof.jpg";
				}
			}
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
	{
		//tile 14
		
		GLchar* texside;
		GLchar* textop;
		if (Tswitch) {
			texside = "NightBuilding1_1.jpg";
			textop = "BlackRoof.jpg";
		}
		else {
			int tex = rand() % 3;
			if (tex == 0) {
				int tex1 = rand() % 8 + 1;
				if (tex1 == 1) {
					texside = "NightBuilding1_1.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 2) {
					texside = "NightBuilding1_2.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 3) {
					texside = "NightBuilding1_3.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 4) {
					texside = "NightBuilding1_4.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 5) {
					texside = "NightBuilding1_5.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 6) {
					texside = "NightBuilding1_6.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 7) {
					texside = "NightBuilding1_7.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 8) {
					texside = "NightBuilding1_8.jpg";
					textop = "BlackRoof.jpg";
				}
			}
			else if (tex == 1) {
				int tex1 = rand() % 4 + 1;
				if (tex1 == 1) {
					texside = "NightBuilding1_1.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 2) {
					texside = "NightBuilding1_2.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 3) {
					texside = "NightBuilding1_3.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 4) {
					texside = "NightBuilding1_4.jpg";
					textop = "BlackRoof.jpg";
				}
			}
			else if (tex == 2) {
				int tex1 = rand() % 4 + 1;
				if (tex1 == 1) {
					texside = "NightBuilding3_1.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 2) {
					texside = "NightBuilding3_2.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 3) {
					texside = "NightBuilding3_3.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 4) {
					texside = "NightBuilding3_4.jpg";
					textop = "BlackRoof.jpg";
				}
			}
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
	{
		//tile 15
		
		GLchar* texside;
		GLchar* textop;
		if (Tswitch) {
			texside = "NightBuilding1_1.jpg";
			textop = "BlackRoof.jpg";
		}
		else {
			int tex = rand() % 3;
			if (tex == 0) {
				int tex1 = rand() % 8 + 1;
				if (tex1 == 1) {
					texside = "NightBuilding1_1.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 2) {
					texside = "NightBuilding1_2.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 3) {
					texside = "NightBuilding1_3.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 4) {
					texside = "NightBuilding1_4.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 5) {
					texside = "NightBuilding1_5.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 6) {
					texside = "NightBuilding1_6.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 7) {
					texside = "NightBuilding1_7.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 8) {
					texside = "NightBuilding1_8.jpg";
					textop = "BlackRoof.jpg";
				}
			}
			else if (tex == 1) {
				int tex1 = rand() % 4 + 1;
				if (tex1 == 1) {
					texside = "NightBuilding1_1.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 2) {
					texside = "NightBuilding1_2.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 3) {
					texside = "NightBuilding1_3.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 4) {
					texside = "NightBuilding1_4.jpg";
					textop = "BlackRoof.jpg";
				}
			}
			else if (tex == 2) {
				int tex1 = rand() % 4 + 1;
				if (tex1 == 1) {
					texside = "NightBuilding3_1.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 2) {
					texside = "NightBuilding3_2.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 3) {
					texside = "NightBuilding3_3.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 4) {
					texside = "NightBuilding3_4.jpg";
					textop = "BlackRoof.jpg";
				}
			}
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
	{
		//tile 16
		
		GLchar* texside;
		GLchar* textop;
		if (Tswitch) {
			texside = "NightBuilding1_1.jpg";
			textop = "BlackRoof.jpg";
		}
		else {
			int tex = rand() % 3;
			if (tex == 0) {
				int tex1 = rand() % 8 + 1;
				if (tex1 == 1) {
					texside = "NightBuilding1_1.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 2) {
					texside = "NightBuilding1_2.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 3) {
					texside = "NightBuilding1_3.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 4) {
					texside = "NightBuilding1_4.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 5) {
					texside = "NightBuilding1_5.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 6) {
					texside = "NightBuilding1_6.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 7) {
					texside = "NightBuilding1_7.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 8) {
					texside = "NightBuilding1_8.jpg";
					textop = "BlackRoof.jpg";
				}
			}
			else if (tex == 1) {
				int tex1 = rand() % 4 + 1;
				if (tex1 == 1) {
					texside = "NightBuilding1_1.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 2) {
					texside = "NightBuilding1_2.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 3) {
					texside = "NightBuilding1_3.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 4) {
					texside = "NightBuilding1_4.jpg";
					textop = "BlackRoof.jpg";
				}
			}
			else if (tex == 2) {
				int tex1 = rand() % 4 + 1;
				if (tex1 == 1) {
					texside = "NightBuilding3_1.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 2) {
					texside = "NightBuilding3_2.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 3) {
					texside = "NightBuilding3_3.jpg";
					textop = "BlackRoof.jpg";
				}
				if (tex1 == 4) {
					texside = "NightBuilding3_4.jpg";
					textop = "BlackRoof.jpg";
				}
			}
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
	if(!lag) {
		std::cout << "lag: " << lag << std::endl;
		B_Blocks[0].clear();
		B_Blocks[1].clear();
		B_Blocks[2].clear();
		B_Blocks[3].clear();
		B_Blocks[4].clear();
		B_Blocks[5].clear();
		B_Blocks[6].clear();
		B_Blocks[7].clear();

		std::vector<Building*> Buildings1;
		std::vector<Building*> Buildings2;
		std::vector<Building*> Buildings3;

		std::vector<Building*> Buildings4;
		std::vector<Building*> Buildings5;
		std::vector<Building*> Buildings6;

		std::vector<Building*> Buildings7;
		std::vector<Building*> Buildings8;
		std::vector<Building*> Buildings9;

		{//tile1
			GLchar* texside;
			GLchar* textop;
			if (Tswitch) {
				texside = "NightBuilding1_1.jpg";
				textop = "BlackRoof.jpg";
			}
			else {
				int tex = rand() % 3;
				if (tex == 0) {
					int tex1 = rand() % 8 + 1;
					if (tex1 == 1) {
						texside = "NightBuilding1_1.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 2) {
						texside = "NightBuilding1_2.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 3) {
						texside = "NightBuilding1_3.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 4) {
						texside = "NightBuilding1_4.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 5) {
						texside = "NightBuilding1_5.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 6) {
						texside = "NightBuilding1_6.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 7) {
						texside = "NightBuilding1_7.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 8) {
						texside = "NightBuilding1_8.jpg";
						textop = "BlackRoof.jpg";
					}
				}
				else if (tex == 1) {
					int tex1 = rand() % 4 + 1;
					if (tex1 == 1) {
						texside = "NightBuilding1_1.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 2) {
						texside = "NightBuilding1_2.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 3) {
						texside = "NightBuilding1_3.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 4) {
						texside = "NightBuilding1_4.jpg";
						textop = "BlackRoof.jpg";
					}
				}
				else if (tex == 2) {
					int tex1 = rand() % 4 + 1;
					if (tex1 == 1) {
						texside = "NightBuilding3_1.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 2) {
						texside = "NightBuilding3_2.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 3) {
						texside = "NightBuilding3_3.jpg";
						textop = "BlackRoof.jpg";
					}
					if (tex1 == 4) {
						texside = "NightBuilding3_4.jpg";
						textop = "BlackRoof.jpg";
					}
				}
			}

			BuildingGen1(glm::vec3(25.0f - offsetx, 0.0f, 0.0f + 30.0f), texside, textop);
			Buildings1 = Buildings;
			B_Blocks[0] = Buildings1;
			Buildings.clear();
			BuildingGen1(glm::vec3(30.0f, 0.0f, 0.0f + 30.0f), texside, textop);
			Buildings2 = Buildings;
			B_Blocks[1] = Buildings2;
			Buildings.clear();
			BuildingGen1(glm::vec3(35.0f + offsetx, 0.0f, 0.0f + 30.0f), texside, textop);
			Buildings3 = Buildings;
			B_Blocks[2] = Buildings3;
			Buildings.clear();

			BuildingGen1(glm::vec3(25.0f - offsetx, 0.0f, 0.0f + 25.0f - offsetz), texside, textop);
			Buildings4 = Buildings;
			B_Blocks[3] = Buildings4;
			Buildings.clear();
			BuildingGen1(glm::vec3(30.0f, 0.0f, 0.0f + 25.0f - offsetz), texside, textop);
			Buildings5 = Buildings;
			B_Blocks[4] = Buildings5;
			Buildings.clear();
			BuildingGen1(glm::vec3(35.0f + offsetx, 0.0f, 0.0f + 25.0f - offsetz), texside, textop);
			Buildings6 = Buildings;
			B_Blocks[5] = Buildings6;
			Buildings.clear();

			BuildingGen1(glm::vec3(25.0f - offsetx, 0.0f, 0.0f + 35.0f + offsetz), texside, textop);
			Buildings7 = Buildings;
			B_Blocks[6] = Buildings7;
			Buildings.clear();
			BuildingGen1(glm::vec3(30.0f, 0.0f, 0.0f + 35.0f + offsetz), texside, textop);
			Buildings8 = Buildings;
			B_Blocks[7] = Buildings8;
			Buildings.clear();
			BuildingGen1(glm::vec3(35.0f + offsetx, 0.0f, 0.0f + 35.0f + offsetz), texside, textop);
			Buildings9 = Buildings;
			B_Blocks[8] = Buildings9;
			Buildings.clear();
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

void City::BuildingGen1(glm::vec3 pos1, GLchar* fs, GLchar* ft) {

	if (!Gswitch) {
		GenB0(pos1, fs, ft);
	}
	else {
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
}
