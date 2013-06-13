
/*
uniform mat4 gl_ModelViewMatrixProjectionMatrix;
attribute vec4 gl_Vertex;

void main()
{
	gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;
}
*/


void main(){
	vec3 normal, lightDir;
	vec4 diffuse[2], ambient[2], globalAmbient;
	float NdotL[2];
	
	//gl_FrontMaterial.ambient = vec4(0.2,0.2,0.6,1.0);
	//gl_LightSource[0].position = vec4(-2,-2,0,1);
	//gl_LightSource[0].ambient = vec4(0.3,0,0,1.0);
	
	//gl_LightSource[1].position = vec4(-2,-2,0,1);
	//gl_LightSource[1].ambient = vec4(0,.3,0,1.0);
	


	for(int i = 0; i < 1; i++){
		//first transform the normal into eye space and normalize the result
		normal = normalize(gl_NormalMatrix * gl_Normal);
		
		//now normalize the light's direction. Note that according to the
		//OpenGL specification, the light is stored in eye space. Also since
		//we're talking about a directional light, the position field is actually
		//direction 
		lightDir = normalize(vec3(gl_LightSource[i].position));
		
		
		//compute the cos of the angle between the normal and lights direction.
		//The light is directional so the direction is constant for every vertex.
		//Since these two are normalized the cosine is the dot product. We also
		//need to clamp the result to the [0,1] range.
		NdotL[i] = max(dot(normal, lightDir), 0.1);
		
		//Compute the diffuse term
		diffuse[i] = gl_FrontMaterial.diffuse * gl_LightSource[i].diffuse;
		
		//Compute the ambient and globalAmbient terms
		ambient[i] = gl_FrontMaterial.ambient * gl_LightSource[i].ambient;
		globalAmbient = gl_LightModel.ambient * gl_FrontMaterial.ambient;
	}
	
	gl_FrontColor = 0;
	for(int i = 0; i < 1; i++){
		gl_FrontColor +=  NdotL[i] * diffuse[i] + ambient[i] + globalAmbient;
		gl_Position = ftransform();
	}

	
	
	}
