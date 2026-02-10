#include<Texture.h>
#include<glad/glad.h>
#include<shaderClass.h>
#include<glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Image:Texture{
    glm::vec3 position = glm::vec3(0.0f,0.0f,0.0f);
    glm::mat4 model = glm::mat4(1.0f);

    /*draw is a function that's suppose to draw which means set the model uniform 
    in the current active shader and bind the current texture then call glDrawelements
     */
    void Draw(Shader& shader, int indcies[]);
    /*
    move is a function that's suppose to update the postions vector in 60fps: 
    which means change the postion in some amount frame by frame  unitl it reaches 

    But it just update the position for now 
    
    it just updates the position vector for now 

    */
    void Moveto(glm::vec3 newPosition);


};