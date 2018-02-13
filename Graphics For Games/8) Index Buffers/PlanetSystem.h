#pragma once
#include "..\..\nclgl\scenenode.h"
#include "..\..\nclgl\OBJMesh.h"

class PlanetSystem : public SceneNode {
public:
	PlanetSystem(void);
	~PlanetSystem(void) {};
	virtual void Update(float msec);

	static void CreatePlanetSystem() {
		OBJMesh * m = new OBJMesh();
		m -> LoadOBJMesh(MESHDIR"sphere_earth.obj");
		sphere = m;
		/*sphere->GenerateNormals();
		sphere->GenerateTangents();
		sphere->BufferData();*/
	}
	static void DeletePlanetSystem() { delete sphere; }
	Mesh * getMesh(){return sphere;}

	Vector3 getEarthPosition() { return planet3->GetWorldTransform().GetPositionVector(); }
	Vector3 getRedPlanetPosition() { return planet1->GetWorldTransform().GetPositionVector(); }

protected:
	static Mesh * sphere;
	static Mesh * spaceship;
	SceneNode * sun;
	SceneNode * planet1;
	SceneNode * planet2;
	SceneNode * planet3;
	SceneNode * planet4;
	SceneNode * planet5;

	SceneNode * ship1;

};
