shader_type spatial;
render_mode depth_prepass_alpha,cull_back,depth_draw_always;
uniform sampler3D noise;
uniform sampler2D noise2d;



uniform float bump_strength : hint_range(0.0, 32.0, 0.001) = 8.0;
uniform bool as_normal_map = false;
uniform vec3 sz=vec3(512.0,512.0,512.0);
uniform int color_mode : hint_range(0, 4, 1) = 0;
float gen_noise(vec3 coords)
{
	return texture(noise,coords).r;
}
//unused normal map method
//uniform vec3 off = vec3(-1,0,1);
//uniform vec2 size = vec2(1,0);
//vec3 to_normal_map2(vec2 coords){
	////получить пиксели через шум и смешать их
	////float here = gen_noise(coords);
	////float to_right = gen_noise(coords + vec2(1.0/width,0));
	////float above = gen_noise(coords + vec2(1.0/heigth,0));
	//float s11 = gen_noise(coords);
    //float s01 = gen_noise(coords + off.xy);
    //float s21 = gen_noise(coords + off.zy);
    //float s10 = gen_noise(coords + off.yx);
    //float s12 = gen_noise(coords + off.yz);
    ////vec3 va = normalize(vec3(size.xy,s21-s01));
    ////vec3 vb = normalize(vec3(size.yx,s12-s10));
	//vec3 va = normalize(vec3(size.x, size.y, s21-s11));
	//vec3 vb = normalize(vec3(size.y, size.x, s12-s11));
	////vec3 up = normalize(vec3(size,(here - above)*bump_strength));
	////vec3 across = normalize(vec3(size.yx,(to_right - here)*bump_strength));
	//return cross(va,vb)*bump_strength*0.5+0.5;
	////return cross(across,up);//сместить значения на пиксель 1/512 (размер текстуры)
//}


uniform bool seamless = false;
uniform float seamless_blend_skirt : hint_range(0.0, 1.0, 0.001) = 0.1;
const float width = 256.0;
const float heigth = 256.0;
const float depth = 256.0;
float generate_seamless(vec3 coords){
	if (!seamless) return gen_noise(coords);
	vec4 skirt  = vec4(
		width /floor(max(1,width * (seamless_blend_skirt+1.0))),
		depth /floor(max(1,depth * (seamless_blend_skirt+1.0))),
		heigth/floor(max(1,heigth* (seamless_blend_skirt+1.0))),0.0);
	vec3 new_coords = fract((coords + 0.5))*skirt.xyz;
	if (new_coords.x < seamless_blend_skirt){
		vec3 a = 1.0 - smoothstep(0.1,0.9,new_coords/seamless_blend_skirt);
		float x01y00z00 = mix(
			gen_noise(new_coords),
			gen_noise(new_coords + skirt.xww),a.x);
		if (new_coords.y < seamless_blend_skirt){
			float x01y11z00 = mix(
				gen_noise(new_coords + skirt.wyw),
				gen_noise(new_coords + skirt.xyw),a.x);
			if (new_coords.z < seamless_blend_skirt){
				float x01y00z11 = mix(
					gen_noise(new_coords + skirt.wwz),
					gen_noise(new_coords + skirt.xwz),a.x);
				float x01y11z11 = mix(
					gen_noise(new_coords + skirt.wyz),
					gen_noise(new_coords + skirt.xyz),a.x);
				return mix(
					mix(x01y00z00,x01y11z00,a.y),
					mix(x01y00z11,x01y11z11,a.y),a.z);
			}
			return mix(x01y00z00,x01y11z00,a.y);
		}
		if (new_coords.z < seamless_blend_skirt){
			float x01y00z11= mix(
				gen_noise(new_coords + skirt.wwz),
				gen_noise(new_coords + skirt.xwz),a.x);
			return mix(x01y00z00,x01y00z11,a.z);
		}
		return x01y00z00;
	}
	if (new_coords.y < float(seamless_blend_skirt)){
		vec2 a = 1.0 - smoothstep(0.1,0.9,new_coords.yz/seamless_blend_skirt);
		float x00y01z00 = mix(
			gen_noise(new_coords),
			gen_noise(new_coords + skirt.wyw),a.x);
		if (new_coords.z < seamless_blend_skirt){
			float x00y01z11= mix(
				gen_noise(new_coords + skirt.wwz),
				gen_noise(new_coords + skirt.wyz),a.x);
			return mix(x00y01z00,x00y01z11,a.y);
		}
		return x00y01z00;
	}
	if (new_coords.z < float(seamless_blend_skirt)){
		float a = 1.0 - smoothstep(0.1,0.9,new_coords.z/seamless_blend_skirt);
		float x00y00z01 = mix(
			gen_noise(new_coords),
			gen_noise(new_coords + skirt.wwz),a);
		return x00y00z01;
	}
	return gen_noise(new_coords);//x00y00z00
}
vec3 to_normal_map(vec3 coords){
	float here = generate_seamless(coords);
	float to_right = generate_seamless(coords + vec3(1.0/sz.x,0,0));
	float above = generate_seamless(coords + vec3(0,0,1.0/sz.y));
	vec3 up = (vec3(0,1,(here - above)*bump_strength));
	vec3 across = (vec3(1,0,(to_right - here)*bump_strength));
	return normalize(cross(across,up))*0.5+0.5;
}

varying vec3 coords;
uniform vec3 off = vec3(2.0,2.0,2.0);
void vertex() {
	coords = VERTEX/off+0.5;
	// Called for every vertex the material is visible on.
}

void fragment() {
	if (as_normal_map){
		ALBEDO = texture(noise2d,coords.xz).rgb;
		//ALBEDO = vec3(to_normal_map(coords));
	}else{
		switch(color_mode){
			case 4: ALPHA = generate_seamless(coords);break;
			case 3: ALBEDO.b = generate_seamless(coords);break;
			case 2: ALBEDO.g = generate_seamless(coords);break;
			case 1: ALBEDO.r = generate_seamless(coords);break;
			default: ALBEDO = vec3(generate_seamless(coords));break;
		}
		
	}
}

//void light() {
	// Called for every pixel for every light affecting the material.
	// Uncomment to replace the default light processing function with this one.
//}
