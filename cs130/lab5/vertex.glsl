uniform sampler2D tex;
varying vec3 N;

/*
void main()
{
	gl_TexCoord[0] = gl_MultiTexCoord0;
	N = gl_NormalMatrix*gl_Normal;
	gl_Position = gl_ProjectionMatrix * gl_ModelViewMatrix * gl_Vertex;
}
*/



void main(){
	
	gl_TexCoord[0] = gl_MultiTexCoord0;
	N = gl_NormalMatrix*gl_Normal;
	gl_Position = gl_ProjectionMatrix * gl_ModelViewMatrix * gl_Vertex;
	
	
	vec3 normal, lightDir;
	vec4 diffuse, ambient, globalAmbient;
	float NdotL,NdotHV,specular;
	
	//gl_FrontMaterial.ambient = vec4(0.2,0.2,0.6,1.0);
	//gl_LightSource[0].position = vec4(-2,-2,0,1);
	//gl_LightSource[0].ambient = vec4(0.3,0,0,1.0);
	
	//gl_LightSource[1].position = vec4(-2,-2,0,1);
	//gl_LightSource[1].ambient = vec4(0,.3,0,1.0);
	
	//first transform the normal into eye space and normalize the result
	normal = normalize(gl_NormalMatrix * gl_Normal);
		
	//now normalize the light's direction. Note that according to the
	//OpenGL specification, the light is stored in eye space. Also since
	//we're talking about a directional light, the position field is actually
	//direction 
	lightDir = normalize(vec3(gl_LightSource[0].position));
		
		
	//compute the cos of the angle between the normal and lights direction.
	//The light is directional so the direction is constant for every vertex.
	//Since these two are normalized the cosine is the dot product. We also
	//need to clamp the result to the [0,1] range.
	NdotL = max(dot(normal, lightDir), 0.1);
		
	if (NdotL > 0.0) {
		// normalize the half-vector, and then compute the
		// cosine (dot product) with the normal
		NdotHV = max(dot(normal, gl_LightSource[0].halfVector.xyz),0.0);
		specular = gl_FrontMaterial.specular * gl_LightSource[0].specular *
				pow(NdotHV,gl_FrontMaterial.shininess);
	}
		
	//Compute the diffuse term
	diffuse = gl_FrontMaterial.diffuse * gl_LightSource[0].diffuse;
		
	//Compute the ambient and globalAmbient terms
	ambient = gl_FrontMaterial.ambient * gl_LightSource[0].ambient;
	globalAmbient = gl_LightModel.ambient * gl_FrontMaterial.ambient;

	gl_FrontColor = vec4(0,0,0,0);
	
	gl_FrontColor +=  NdotL * diffuse + ambient + globalAmbient;
	gl_Position = ftransform();
	
}
