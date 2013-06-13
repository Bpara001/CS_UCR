uniform sampler2D tex;
varying vec3 N;


void main()
{
	vec3 L = normalize(gl_LightSource[0].position);
	vec3 normal = normalize(N);
	
	float intensity = dot(L, normal);
	vec4 texture = texture2D(tex, gl_TexCoord[0].xy);

	//gl_FragColor.xyz = intensity*gl_FrontMaterial.diffuse.rgb + gl_FrontMaterial.ambient.rgb + texture;
	
	//gl_FragColor.a = 1.0;
	
	gl_FragColor = gl_Color * texture;
}



/*
void main()
{
	//gl_FragColor = gl_Color;
}
*/
