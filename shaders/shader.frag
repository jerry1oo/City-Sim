#version 330 core
// This is a sample fragment shader.
in vec3 normalOut;
in vec3 posOut;
in vec3 LightOut;

struct Material {
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    float shininess;
}; 

struct Light {
    vec3 position; 

    vec3 color; 
  
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
	
    float constant;
    float linear;
    float quadratic;
};

uniform Material material;
uniform Light light;
// Inputs to the fragment shader are the outputs of the same name from the vertex shader.
// Note that you do not have access to the vertex shader's default output, gl_Position.
in float sampleExtraOutput;


uniform vec3 color;
//uniform vec3 lightcolor;
//uniform vec3 lightPos;
uniform bool Normcord;

// You can output many things. The first vec4 type output determines the color of the fragment
out vec4 fragColor;

void main()
{
    // Use the color passed in. An alpha of 1.0f means it is not transparent.
    if(Normcord == false){

        float dist = length(light.position - posOut);
        float attenuation = 1.0 / (light.constant + light.linear * dist+ light.quadratic * (dist * dist));  

        vec3 ambient = material.ambient * light.ambient * attenuation;    
        
        // diffuse 
        vec3 norm = normalize(normalOut);
        vec3 lightDir = normalize(light.position - posOut);
        float diff = max(dot(norm, lightDir), 0.0);
        vec3 diffuse = (diff * material.diffuse) * light.diffuse * attenuation;
        
        // specular
        
        vec3 viewDir = normalize(-posOut); // the viewer is always at (0,0,0) in view-space, so viewDir is (0,0,0) - Position => -Position
        vec3 reflectDir = reflect(-lightDir, norm);  
        float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
        vec3 specular = (material.specular * spec) * light.specular * attenuation; 
        
        vec3 result = (ambient + diffuse + specular);
        fragColor = vec4(result, sampleExtraOutput);
    }
    else{
        vec3 temp = normalize(normalOut);
        temp = vec3((normalOut.x+1.0)/2.0, (normalOut.y+1.0)/2.0,(normalOut.z+1.0)/2.0);
        fragColor = vec4(temp, sampleExtraOutput);
    }
}