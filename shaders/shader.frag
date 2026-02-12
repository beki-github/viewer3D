#version 430 core
out vec4 FragColor;
in vec3 cooColor;
in vec2 texCoord;


uniform sampler2D tex0;


void main()
{
   //comment
   //comment
   FragColor = texture(tex0, texCoord);
}