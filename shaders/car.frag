#version 330 core

out vec4 color;

in vec3 pos;
in vec3 norm;

uniform vec3 cameraPos;
uniform samplerCube cubemap;

void main()
{    
    vec3 I = normalize(pos - cameraPos);
    vec3 R = reflect(I, normalize(norm));
    color = vec4(texture(cubemap, R).rgb, 1.0);
}