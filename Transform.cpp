#include "Transform.h"

void Transform::addChild(Node* childNode) {
	ChildNodes.push_back(childNode);
}

void Transform::addBound(Node* boundNode) {
	BoundNodes.push_back(boundNode);
}

bool Transform::inview(glm::vec3 center, float radi) {
	for (int i = 0; i < 6; i++)
	{
		if ((glm::dot(PS[i].normal,center) + PS[i].Dist + radi) <= 0) {
			return false;
		}
	}

	return true;
}

void Transform::draw(GLuint shaderProgram, glm::mat4 C, bool bound, bool Frustum, std::vector<plane> P, int &count) {
	PS = P;
	for (auto i : ChildNodes) {
		if (poslimb == 0) {
			if (Frustum) {
				for (auto j : BoundNodes) {
					if (inview(glm::vec3((C*M)*(glm::vec4(0, 0, 0, 1))), 4)) {
						count++;
						i->draw(shaderProgram, C*M, bound, Frustum, P, count);
					}
				}
			}
			else {
				count++;
				i->draw(shaderProgram, C*M, bound, Frustum, P, count);
			}
		}
		else{
			i->draw(shaderProgram, C*M, bound, Frustum,P, count);
		}
	}
	if (bound == true) {
		for (auto j : BoundNodes) {
			if (poslimb == 0) {
				if (Frustum) {
					if (inview(glm::vec3((C*M)*(glm::vec4(0, 0, 0, 1))), 4)) {
						j->draw(shaderProgram, C*M, bound, Frustum, P, count);
					}
				}
				else {
					j->draw(shaderProgram, C*M, bound, Frustum, P, count);
				}
			}
			
		}
	}
}

void Transform::update(glm::mat4 C) {
	
	for (auto i : ChildNodes) {
		i->update(M*C);
	}

	float speed = 5.0f;

	if (poslimb == 1 && anicount <= speed*500 && anipos == true) {
		glm::mat4 rot = glm::rotate(glm::mat4(1), glm::radians(0.1f/speed), glm::vec3(1.0f, 0.0f, 0.0f));
		glm::mat4 trans = glm::translate(glm::mat4(1), glm::vec3(0, 0, -0.0009/speed));
		M = M * trans;
		M = M * rot;
		anicount++;
		//std::cerr << anicount;
		if (anicount > speed*500) {
			anipos = false;
			//std::cerr << "false";
		}
	}
	if(poslimb == 1 && anicount >= speed * -500 && anipos == false){
		glm::mat4 rot = glm::rotate(glm::mat4(1), glm::radians(-0.1f/ speed), glm::vec3(1.0f, 0.0f, 0.0f));
		glm::mat4 trans = glm::translate(glm::mat4(1), glm::vec3(0, 0, 0.0009/ speed));
		M = M * trans;
		M = M * rot;
		anicount--;
		//std::cerr << anicount;
		if (anicount < speed * -500) {
			anipos = true;
			//std::cerr << anipos;
		}
	}

	if (poslimb == 2 && anicount <= speed*500 && anipos == true) {
		glm::mat4 rot = glm::rotate(glm::mat4(1), glm::radians(-0.1f/ speed), glm::vec3(1.0f, 0.0f, 0.0f));
		glm::mat4 trans = glm::translate(glm::mat4(1), glm::vec3(0, 0, 0.0009/ speed));
		M = M * trans;
		M = M * rot;
		anicount++;
		//std::cerr << anicount;
		if (anicount > speed*500) {
			anipos = false;
			//std::cerr << "false";
		}
	}
	if (poslimb == 2 && anicount >= speed *-500 && anipos == false) {
		glm::mat4 rot = glm::rotate(glm::mat4(1), glm::radians(0.1f/ speed), glm::vec3(1.0f, 0.0f, 0.0f));
		glm::mat4 trans = glm::translate(glm::mat4(1), glm::vec3(0, 0, -0.0009/ speed));
		M = M * rot;
		M = M * trans;
		anicount--;
		//std::cerr << anicount;
		if (anicount < speed *-500) {
			anipos = true;
			//std::cerr << anipos;
		}
	}
	
	if (poslimb == 3 && anicount <= speed*500 && anipos == true) {
		glm::mat4 rot = glm::rotate(glm::mat4(1), glm::radians(-0.1f/ speed), glm::vec3(0.0f, 0.0f, 1.0f));
		/*glm::mat4 trans = glm::translate(glm::mat4(1), glm::vec3(0, 0, 0.001));
		M = M * trans;*/
		M = M * rot;
		anicount++;
		//std::cerr << anicount;
		if (anicount > speed*500) {
			anipos = false;
			//std::cerr << "false";
		}
	}
	if (poslimb == 3 && anicount >= speed *-500 && anipos == false) {
		glm::mat4 rot = glm::rotate(glm::mat4(1), glm::radians(0.1f/ speed), glm::vec3(0.0f, 0.0f, 1.0f));
		/*glm::mat4 trans = glm::translate(glm::mat4(1), glm::vec3(0, 0, -0.001));
		M = M * trans;*/
		M = M * rot;
		anicount--;
		//std::cerr << anicount;
		if (anicount < speed *-500) {
			anipos = true;
			//std::cerr << anipos;
		}
	}
	if (poslimb == 4 && anicount <= speed*250 && anipos == true) {
		//glm::mat4 rot = glm::rotate(glm::mat4(1), glm::radians(-0.1f), glm::vec3(0.0f, 0.0f, 1.0f));
		glm::mat4 trans = glm::translate(glm::mat4(1), glm::vec3(0, 0.0005/ speed, 0));
		M = M * trans;
		//M = M * rot;
		anicount++;
		//std::cerr << anicount;
		if (anicount > speed*250) {
			anipos = false;
			//std::cerr << "false";
		}
	}
	if (poslimb == 4 && anicount >= speed *-250 && anipos == false) {
		//glm::mat4 rot = glm::rotate(glm::mat4(1), glm::radians(0.1f), glm::vec3(0.0f, 0.0f, 1.0f));
		glm::mat4 trans = glm::translate(glm::mat4(1), glm::vec3(0, -0.0005/ speed, 0));
		M = M * trans;
		//M = M * rot;
		anicount--;
		//std::cerr << anicount;
		if (anicount < speed *-250) {
			anipos = true;
			//std::cerr << anipos;
		}
	}

	

	if (poslimb == 5 && anicount <= speed * 500 && anipos == true) {
		glm::mat4 rot = glm::rotate(glm::mat4(1), glm::radians(0.1f / speed), glm::vec3(1.0f, 0.0f, 0.0f));
		glm::mat4 trans = glm::translate(glm::mat4(1), glm::vec3(0, 0, -0.0008 / speed));
		M = M * trans;
		M = M * rot;
		anicount++;
		//std::cerr << anicount;
		if (anicount > speed * 500) {
			anipos = false;
			//std::cerr << "false";
		}
	}
	if (poslimb == 5 && anicount >= speed * -500 && anipos == false) {
		glm::mat4 rot = glm::rotate(glm::mat4(1), glm::radians(-0.1f / speed), glm::vec3(1.0f, 0.0f, 0.0f));
		glm::mat4 trans = glm::translate(glm::mat4(1), glm::vec3(0, 0, 0.0008 / speed));
		M = M * trans;
		M = M * rot;
		anicount--;
		//std::cerr << anicount;
		if (anicount < speed * -500) {
			anipos = true;
			//std::cerr << anipos;
		}
	}

	if (poslimb == 6 && anicount <= speed * 500 && anipos == true) {
		glm::mat4 rot = glm::rotate(glm::mat4(1), glm::radians(-0.1f / speed), glm::vec3(1.0f, 0.0f, 0.0f));
		glm::mat4 trans = glm::translate(glm::mat4(1), glm::vec3(0, 0, 0.0008 / speed));
		M = M * trans;
		M = M * rot;
		anicount++;
		//std::cerr << anicount;
		if (anicount > speed * 500) {
			anipos = false;
			//std::cerr << "false";
		}
	}
	if (poslimb == 6 && anicount >= speed * -500 && anipos == false) {
		glm::mat4 rot = glm::rotate(glm::mat4(1), glm::radians(0.1f / speed), glm::vec3(1.0f, 0.0f, 0.0f));
		glm::mat4 trans = glm::translate(glm::mat4(1), glm::vec3(0, 0, -0.0008 / speed));
		M = M * rot;
		M = M * trans;
		anicount--;
		//std::cerr << anicount;
		if (anicount < speed *-500) {
			anipos = true;
			//std::cerr << anipos;
		}
	}

}