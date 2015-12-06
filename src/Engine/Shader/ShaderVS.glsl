#version 430

in layout(location = 0) vec3 position;

uniform mat4 transformationMatrix;
uniform vec3 color;

out vec3 daColor;

void main(){
	
	gl_Position = transformationMatrix * vec4(position,1.0);
	daColor = vec3(1.0,1.0,1.0);

};