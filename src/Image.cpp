#include<iostream>
#include "Image.h"


Image::Image(const char* imagePath, GLenum texType, GLenum slot, GLenum pixelType,glm::vec3 position)
:Texture(const char* imagePath, GLenum texType, GLenum slot, GLenum pixelType)
{ 
    

}
void Image::Draw(Shader &shader,int indcies[])
{    
    texUnit(shader,"tex0",0);
    Bind();
    glDrawElements(GL_TRIANGLES,sizeof(indcies)/sizeof(int),GL_UNSIGNED_INT,0);
}

void Image::Moveto(glm::vec3 newPosition)
{
  position=newPosition;
  model=glm::translate(model,position);
}
