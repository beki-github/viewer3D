#include"Texture.h"

Texture::Texture(imageStruct &image, GLenum texType, GLenum slot, GLenum pixelType)
:imagePhoto(image)
{ 
	// Assigns the type of the texture ot the texture object

    
	type = texType;
	textureSlot = slot;

	// Generates an OpenGL texture object
	glGenTextures(1, &ID);
	// Assigns the texture to a Texture Unit
	//
	glBindTexture(GL_TEXTURE_2D, ID);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	// Configures the type of algorithm that is used to make the image smaller or bigger
	glTexParameteri(texType, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_LINEAR);
	glTexParameteri(texType, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	// Assigns the image to the OpenGL Texture object
	if (imagePhoto.success) {
		GLenum format = (imagePhoto.numCloch == 4) ? GL_RGBA : GL_RGB;
		glTexImage2D(texType, 0, GL_SRGB, imagePhoto.width,imagePhoto.height, 0, format, pixelType, imagePhoto.bytes);
		// Generates MipMaps
		glGenerateMipmap(texType);

	}
	else {
		std::cout << "ERROR FAILLED to assign image to texture object";
	}

	// Deletes the image data as it is already in the OpenGL Texture object
	stbi_image_free(imagePhoto.bytes);

	// Unbinds the OpenGL Texture object so that it can't accidentally be modified
	glBindTexture(texType, 0);
}

void Texture::texUnit(Shader& shader, const char* uniform, GLuint unit)
{   
	shader.use();
	shader.setInt(uniform,unit);
}

void Texture::Bind()
{     
	  
	glActiveTexture(textureSlot);
	glBindTexture(type, ID);
	

}

void Texture::Unbind()
{
	glBindTexture(type, 0);
}

void Texture::Delete()
{
	glDeleteTextures(1, &ID);
}