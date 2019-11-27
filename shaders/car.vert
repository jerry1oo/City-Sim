#version 330 core
// NOTE: Do NOT use any version older than 330! Bad things will happen!

// This is an example vertex shader. GLSL is very similar to C.
// You can define extra functions if needed, and the main() function is
// called when the vertex shader gets run.
// The vertex shader gets called once per vertex.

layout (location = 0) in vec3 Pos;
layout (location = 1) in vec3 Norm;

out vec3 pos;
out vec3 norm;

uniform mat4 projection;
uniform mat4 view;
uniform mat4 model;

void main()
{
    norm = mat3(transpose(inverse(model))) * Norm;
    pos = vec3(model * vec4(Pos, 1.0));
    gl_Position = projection * view * model * vec4(Pos, 1.0);
} 