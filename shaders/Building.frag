#version 330 core
out vec4 FragColor;

in vec2 TexCoord;
uniform vec3 color;
uniform sampler2D texture;

void main()
{
    FragColor = texture(texture, TexCoord);
    //FragColor = vec4(TexCoord.xy, 0.0 ,1.0);
}