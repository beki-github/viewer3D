
#include "Image.h"

Image::Image(imageStruct image, GLenum texType, GLenum slot, GLenum pixelType,glm::vec3 position)
:Texture(image,texType,slot,pixelType),Position{position}
{ 
    /*set the initial value of model matrix
    to the vec3 Position defined on  */
    model=glm::translate(model,Position);
    

}
void Image::Draw(Shader &shader,GLfloat index)
{    
  
    Updatestate(shader,index);
    glDrawElements(GL_TRIANGLES,6,GL_UNSIGNED_INT,0);
   
}

void Image::Moveto(glm::vec3 newPosition)
{
  Position=newPosition;
}

void Image::Updatestate(Shader &shader,GLfloat index)
{
  shader.use();
  Bind();
  texUnit(shader,"tex0",0);
  model=glm::translate(glm::mat4(1.0f),glm::vec3(Position.x+index,Position.y,Position.z));
  float aspect = static_cast<float>(imagePhoto.width) / static_cast<float>(imagePhoto.height);
  model = glm::scale(model, glm::vec3(aspect, 1.0f, 1.0f));
  shader.setMat4(0,GL_FALSE,model);
}
