
#include "Image.h"

Image::Image(imageStruct image, GLenum texType, GLenum slot, GLenum pixelType,glm::vec3 position)
:Texture(image,texType,slot,pixelType),Position{position}
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
  model=glm::scale(model,glm::vec3(static_cast<float>(imagePhoto.width/imagePhoto.height),1.0f,1.0f));
  shader.setMat4(0,GL_FALSE,model);
}
