
#include "Image.h"

Image::Image(const char* imagePath, GLenum texType, GLenum slot, GLenum pixelType,glm::vec3 position)
:Texture(imagePath,texType,slot,pixelType),Position{position}
{ 
    /*set the initial value of model matrix
    to the vec3 Position defined on  */
    model=glm::translate(model,Position);
    

}
void Image::Draw(Shader &shader,GLuint indicies[])
{    
  
    Updatestate(shader);
    glDrawElements(GL_TRIANGLES,6,GL_UNSIGNED_INT,0);
   
}

void Image::Moveto(glm::vec3 newPosition)
{
  Position=newPosition;
 
}

void Image::Updatestate(Shader &shader)
{
  shader.use();
  Bind();
  texUnit(shader,"tex0",0);
  model=glm::translate(glm::mat4(1.0f),Position);
  model=glm::scale(model,glm::normalize(glm::vec3(widthImg,heightImg,1)));
  shader.setMat4(0,GL_FALSE,model);
}
