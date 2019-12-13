#version 330 core
out vec4 FragColor;
  
in vec2 TexCoords;

uniform sampler2D screenTexture;
uniform sampler2D depthTexture;
uniform mat4 view;
uniform mat4 prevView;
uniform bool blur;



void main()
{	
	if(blur){
	vec2 texCoord = TexCoords;
	mat4 inverseView = inverse(view);
	vec4 zOverW = texture(depthTexture,texCoord);
	vec4 H = vec4((texCoord.x*2.0f)-1,((1.0f-texCoord.y)*2.0f)-1.0f,zOverW.x,1.0f);
	vec4 D = inverseView*H;
	vec4 worldPos = D / D.w;
	vec4 currentPos = H;
	vec4 previousPos = prevView*worldPos;
	previousPos /= previousPos.w;
	vec4 v = (currentPos - previousPos)/2.0f;
	vec2 velocity = vec2(v.x,v.y)*0.5;
	float count = 3.0;
	vec4 color =  texture(screenTexture,texCoord);
	texCoord += velocity;
	for(int i=1; i < count; ++i){
		vec4 currentColor = texture(screenTexture,texCoord);
		color += currentColor;
		texCoord += velocity;
	}
	
	//if(length(velocity) < .01 ){
	FragColor = color/count;//}
	//else { FragColor = texture(screenTexture, TexCoords);}
	}
	else { FragColor = texture(screenTexture, TexCoords);}
} 