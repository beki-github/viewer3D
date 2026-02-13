#pragma once 
#include "stb/stb_image.h"
#include <glad/glad.h>
#include "ShaderClass.h"
#include<iostream>


struct imageStruct{
    unsigned char *bytes;
    int width,height,numCloch;
    bool success;
    imageStruct(unsigned char *imgbytes, int imgWidth, int imgheight, bool loadstatus)
    :bytes(imgbytes),width(imgWidth),height(imgheight),success(loadstatus)
    {

    };
};

/*this header file is for
texture class that is used to bind multiple 2D textures at once
*/
class Texture
{
public:
	GLuint ID;
	GLenum type;
	GLenum textureSlot;
	imageStruct imagePhoto;
	Texture(imageStruct &image, GLenum texType, GLenum slot, GLenum pixelType);

	// Assigns a texture unit to a texture
	void texUnit(Shader& shader, const char* uniform, GLuint unit);
	// Binds a texture
	void Bind();
	// Unbinds a texture
	void Unbind();
	// Deletes a texture
	void Delete();
};
