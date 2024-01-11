shader_type spatial;
uniform bool mode = false;
uniform vec3 uvw = vec3(1,1,1);
uniform sampler2D noise;
uniform sampler3D noise3d;
void vertex() {
	COLOR.rgb = VERTEX/uvw+0.5;
	// Called for every vertex the material is visible on.
}

void fragment() {
	if (!mode){
		ALBEDO = texture(noise,COLOR.rb).rgb;
	}else{
		ALBEDO = texture(noise3d,COLOR.rgb).rgb;
	}
	// Called for every pixel the material is visible on.
}

//void light() {
	// Called for every pixel for every light affecting the material.
	// Uncomment to replace the default light processing function with this one.
//}
