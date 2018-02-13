#pragma once
#include "OGLRenderer.h"
/*
enum MeshBuffer {
	VERTEX_BUFFER, COLOUR_BUFFER, MAX_BUFFER
};
*/

// texture
/*enum MeshBuffer {
	VERTEX_BUFFER, COLOUR_BUFFER, TEXTURE_BUFFER, MAX_BUFFER
};
*/

/* Index Buffer
enum MeshBuffer {
	VERTEX_BUFFER, COLOUR_BUFFER,
	TEXTURE_BUFFER, INDEX_BUFFER,
	MAX_BUFFER
};
*/
/* Lighting A
enum MeshBuffer {
	VERTEX_BUFFER, COLOUR_BUFFER, TEXTURE_BUFFER,
	NORMAL_BUFFER, INDEX_BUFFER, MAX_BUFFER
};
*/

// lighting B
enum MeshBuffer {
	VERTEX_BUFFER, COLOUR_BUFFER, TEXTURE_BUFFER,
	NORMAL_BUFFER, TANGENT_BUFFER, INDEX_BUFFER, // Tangents !
	MAX_BUFFER
};

class Mesh {
public:
	Mesh(void);
	~Mesh(void);

	virtual void Draw();
	static Mesh * GenerateTriangle();

	// textures
	void SetTexture(GLuint tex, int pos) { texture[pos] = tex; }
	GLuint GetTexture(int pos)			{ return texture[pos]; }

	// transparency
	static Mesh* GenerateQuad();

	// lighting B
	void SetBumpMap(GLuint tex, int pos) { bumpTexture[pos] = tex; }
	GLuint GetBumpMap(int pos) { return bumpTexture[pos]; }

	void GenerateNormals();
	void GenerateTangents();
	int getNumVertices() { return numVertices; }
	void BufferData();


protected:
	

	GLuint arrayObject;
	GLuint bufferObject[MAX_BUFFER];
	GLuint numVertices;
	GLuint type;

	Vector3 * vertices;
	Vector4 * colours;

	// textures
	GLuint texture[5];
	GLuint bumpTexture[5];
	Vector2* textureCoords;

	// Index buffer
	GLuint numIndices;
	unsigned int *indices;

	// lighting A
	
	Vector3* normals;

	// lighting B
	Vector3 GenerateTangent(const Vector3 &a, const Vector3 &b,
		const Vector3 &c, const Vector2 & ta,
		const Vector2 & tb, const Vector2 & tc);
	
	Vector3* tangents;
	


};