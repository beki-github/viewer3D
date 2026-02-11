
#include "Image.h"

Image::Image(const char* imagePath, GLenum texType, GLenum slot, GLenum pixelType,glm::vec3 position)
:Texture(imagePath,texType,slot,pixelType),Position(position)
{ 

}
void Image::Draw(Shader &shader,int indcies[])
{    
    shader.use();
    texUnit(shader,"tex0",0);
    Bind();
    glDrawElements(GL_TRIANGLES,sizeof(indcies)/sizeof(int),GL_UNSIGNED_INT,0);
}

void Image::Moveto(Shader &shader,glm::vec3 newPosition)
{
  Position=newPosition;
 
}
