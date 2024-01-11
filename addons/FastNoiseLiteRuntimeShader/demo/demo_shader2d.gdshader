shader_type canvas_item;
uniform bool mode = false;
uniform sampler2D noise;
uniform sampler3D noise3d;
varying vec2 base_coords;
const vec2 poligon_resolution = vec2(200,200);
void vertex() {
	base_coords = (VERTEX)/poligon_resolution+0.5;
	// Called for every vertex the material is visible on.
}

void fragment() {
	if(!mode){
		COLOR.rgb = texture(noise,fract(base_coords)).rgb;
	}else{
		COLOR.rgb = texture(noise3d,fract(vec3(base_coords,0.0).xzy)).rgb;
	}
	// Called for every pixel the material is visible on.
}

//void light() {
	// Called for every pixel for every light affecting the CanvasItem.
	// Uncomment to replace the default light processing function with this one.
//}
