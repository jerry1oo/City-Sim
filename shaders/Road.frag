#version 330 core
out vec4 FragColor;
  
in vec2 TexCoord;
uniform vec3 color;
uniform sampler2D ourTexture;

void main()
{
    FragColor = texture(ourTexture, TexCoord);
    //FragColor = vec4(TexCoord.xy, 0.0 ,1.0);
}