#version 430 core

in vec2 v_texcoord;			//uv
in vec4 v_color;			//color
in vec3 worldpos;			//pos vector
in vec3 worldnormal;		//normal vector
in vec3 view;				//view vector


out vec4 v_fragcolor;


#define DirecitonlLight 0
#define SpotLight 1
#define PointLight 2

uniform int lighttype;			//light type
uniform vec4 red;
struct LightInfo
{
	vec4 position;
	vec4 direction;

	vec4 Ka;
	vec4 Kd;
	vec4 Ks;

	float constantAttenuation, linearAttenuation, quadraticAttenuation;
	float spotFalloff, intensity;
	float spotInnerAngle, spotOuterAngle;
};
uniform LightInfo light;

struct material
{
	vec4 ambient;
	vec4 diffuse;
	vec4 specular;
	vec4 emissive;

	float shininess;
};

material hdMaterial = material(
	vec4(0.2, 0.2, 0.2, 1.0),
	vec4(1.0, 0.8, 0.8, 1.0),
	vec4(1.0, 1.0, 1.0, 1.0),
	vec4(0 , 0, 0, 0),
	5.0);


void main()
{
    vec3 normalDirection = normalize(worldnormal);
//    vec3 normalDirection = normalize(vec3(-1,-1,-1));
	vec3 viewDirection = normalize(view);
	vec3 lightDirection;
	float attenuation;
	
	if(lighttype == DirecitonlLight) //directional light
	{
		attenuation = 1.0;
		lightDirection = normalize(-light.direction.xyz);
//		lightDirection = normalize(vec3(-1,-1,-1));

	}
	else
	{
		vec3 positionToLight = light.position.xyz - worldpos;
		float dist = length(positionToLight);
		lightDirection = normalize(positionToLight);
		attenuation = 1.0 / (light.constantAttenuation + 
							 light.linearAttenuation * dist +
							 light.quadraticAttenuation * dist * dist);

		if(lighttype == SpotLight) //spot light
		{
			float clampedCosine = max(0.0, dot(-lightDirection, light.direction.xyz));
			if(clampedCosine < cos(radians(light.spotFalloff))) //outside of cone
				attenuation = 0.0;
			else
				attenuation = attenuation * pow(clampedCosine, light.spotFalloff);
		}
	}


	vec3 emissivelight = hdMaterial.emissive.xyz;
	vec3 ambientlight = light.Ka.xyz * hdMaterial.ambient.xyz;
	vec3 diffuselight = attenuation * light.Kd.xyz * hdMaterial.diffuse.xyz * max(0, dot(normalDirection, lightDirection));
	vec3 specularlight;
	if(dot(normalDirection, lightDirection) < 0.0)
		specularlight = vec3(0,0,0);
	else
		specularlight = attenuation * light.Ks.xyz * hdMaterial.specular.xyz * pow(max(0.0, dot(reflect(-lightDirection, normalDirection), viewDirection)), hdMaterial.shininess);

    v_fragcolor = vec4(ambientlight + diffuselight + specularlight + emissivelight,1);
}