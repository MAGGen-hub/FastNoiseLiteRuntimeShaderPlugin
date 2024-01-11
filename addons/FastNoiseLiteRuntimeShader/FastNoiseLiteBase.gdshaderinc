// MIT Licenses
//
// FastNoiseLite-GodotPlugin:
// Copyright(c) 2023 github.com/MAGGen-hub, M.A.G.Gen.
// FastNoiseLite-Libruary:
// Copyright(c) 2023 Jordan Peck (jordan.me2@gmail.com)
// Copyright(c) 2023 Contributors
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files(the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and / or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions :
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

//region DEFAULT_DEFINES
#ifndef DEFINE_OVERRIDE
//default defines if not controlled by  FastNoiseLiteShaderMaterial.gd
//shader_type spatial;
//render_mode depth_prepass_alpha,cull_back,depth_draw_always;
#define SELECTED_NOISE_TYPE FNL_NOISE_OPENSIMPLEX2S
#define SELECTED_FRACTAL_TYPE FNL_FRACTAL_FBM
#define SELECTED_DOMAIN_WARP_TYPE FNL_DOMAIN_WARP_BASICGRID
#define SELECTED_DOMAIN_WARP_FRACTAL_TYPE FNL_FRACTAL_DOMAIN_WARP_INDEPENDENT

//Include FNL_lib
#define FNL_COMPILLER_OPTIMISATIONS_REQUIRED
#include "res://addons/FastNoiseLiteRuntimeShader/FastNoiseLiteLib.gdshaderinc"
///WARNING! WARNING! WARNING! WARNING! WARNING! WARNING! WARNING!
// DO NOT use "res://addons/FastNoiseLiteRuntimeShader/FastNoiseLiteLibOriginal.gdshaderinc"
// And DO NOT remove #define FNL_COMPILLER_OPTIMISATIONS_REQUIRED
//
// Last time I tried to compile entire FastNoiseLite libruary
// without splitting it into bunch of #define directives
// It took more than 20 minutes to compile and after that
// Godot Engine shut downs with no result.
#define IS_3D_TEXTURE false
#define IN_3D_SPACE false
#define DOMAIN_WARP_ENABLED false
#define SEAMLESS true
#define AS_NORMAL_MAP false
// Even with all thouse compiller optimisations it may took a 2 or 4 seconds
// To compile the shader if ALL functions of libruary used. So please don't
// try to replace #defines with uniforms - result will be awful.
//
// To manipulate shader comfortably use FastNoiseLiteShaderMaterial class.
// It will automaticaly load shader that needed to be loaded, and once you
// load it - it will be keept in shader cache to prewent any future compilation
// freezes.

// If you want to use more than 1 noise inside your own custom shader use
// #define FNL_COMPILLER_OPTIMISATIONS_REQUIRED_MULTYNOISE
// and then enable noise and fractal types by typing:
// #define ENABLE_<noise/fractal/domain_warp>
// Example: #define ENABLE_FNL_DOMAIN_WARP_BASICGRID

//Enable interface groups if user prefer to use shader directly
//#define NO_GROUPS
#endif
//endregion


//region Uniforms
//region TextureControl
#ifndef NO_GROUPS
group_uniforms NoiseTexture;
#endif
uniform vec3 wdh = vec3(512.0);//width/depth/heigth
uniform vec3 uvw = vec3(1,1,1);
uniform bool invert = false;
#if SEAMLESS
uniform float seamless_blend_skirt : hint_range(0.001, 1.0, 0.001) = 0.1;
#endif
///[NOT REQUIRED] ( it's a shader, not a texture, LoL XD )
//uniform bool generate_mipmaps = false;

///[IMPOSIBLE] (VERY EXPENSIVE CALCULATIONS!)
//uniform bool _normalize = true;
// to provide that kind of information to shader I must
// make external calculator or call gen_noise() function
// width*heigth+1(or 3 if normal map enabled) times
// FOR EACH FRAGMENT call!!! so... wellcome to 1 FPS world...

//Must be GardientTexture1D
uniform sampler2D color_ramp : hint_default_white;
//Select color chanel to noise output data
uniform int output : hint_range(0, 4, 1) = 0;
//endregion

//region NoiseControl
#ifndef NO_GROUPS
group_uniforms FastNoiseLite;
#endif
//0:Simplex //1:SimplexSmooth //2:Cellular //3:Perlin //4:ValueCubic //5:Value
//uniform int noise_type : hint_range(0, 5, 1) = 0; // CONTROLED BY DEFINE
uniform int seed = 0;
uniform float frequency :  hint_range(0, 1, 0.0001) = 0.01;
uniform vec3 offset = vec3(0.0,0.0,0.0);

//region FractalControl
#ifndef NO_GROUPS
group_uniforms Fractal;
#endif
//0:None //1:FBM //2:Ridged //3:Ping-Pong
//uniform int fractal_type : hint_range(0,3,1) = 1; // CONTROLED BY DEFINE
uniform int octaves : hint_range(1, 10, 1) = 5;
uniform float lacunarity = 2;
uniform float gain = 0.5; 
uniform float weighted_strength = 0;
#if SELECTED_FRACTAL_TYPE==FNL_FRACTAL_PINGPONG
uniform float ping_pong_strength = 2;
#endif
//endregion

//region Cellular
#if SELECTED_NOISE_TYPE==FNL_NOISE_CELLULAR
#ifndef NO_GROUPS
group_uniforms Cellular;
#endif
uniform int distance_function : hint_range(0, 3, 1) = 0;
uniform float jitter = 1;
uniform int return_type : hint_range(0, 6, 1) = 1;
#endif
//endregion

//region DomainWarp
#if DOMAIN_WARP_ENABLED
#ifndef NO_GROUPS
group_uniforms DomainWrap;
#endif
// 0:Simplex // 1:SimplexReduced // 2:BasicGrid
//uniform int domain_warp_type : hint_range(0,2,1) = 0; // CONTROLED BY DEFINE
uniform float amplitude = 30.0;
#define domain_warp_frequency _frequency
uniform float domain_warp_frequency = 0.05;
// 0:None // 1:Progressive // 2:Independent
//uniform int domain_warp_fractal_type : hint_range(0, 2, 1) = 1; //CONTROLED BY DEFINE
uniform int fractal_octaves : hint_range(1, 10, 1) = 5;
uniform float fractal_lacunarity = 6;
uniform float fractal_gain = 0.5;
#endif
//endregion
//endregion
//endregion


#if IS_3D_TEXTURE
#undef AS_NORMAL_MAP
#define AS_NORMAL_MAP false
#endif

// Method to access generated noise values
float gen_noise(vec3 coords){
	//Domain Warp Section
	#if DOMAIN_WARP_ENABLED
	#if IN_3D_SPACE && !IS_3D_TEXTURE
	coords.y = offset.z;
	#endif
	{
		fnl_state domain_warp = fnlCreateState(seed);//Internal Constructor
		domain_warp.domain_warp_type = SELECTED_DOMAIN_WARP_TYPE;
		domain_warp.domain_warp_amp = amplitude;
		domain_warp.frequency = domain_warp_frequency;
		domain_warp.fractal_type = SELECTED_DOMAIN_WARP_FRACTAL_TYPE;
		domain_warp.octaves = fractal_octaves;
		domain_warp.lacunarity = fractal_lacunarity;
		domain_warp.gain = fractal_gain;
	#if IS_3D_TEXTURE
		fnlDomainWarp3D(domain_warp,coords.x,coords.y,coords.z);
	#elif IN_3D_SPACE
		fnlDomainWarp3D(domain_warp,coords.x,coords.z,coords.y);
	#else
		fnlDomainWarp2D(domain_warp,coords.x,coords.z);
	#endif
	}
	#endif
	//#endif
	//NoiseGeneration Section
	fnl_state noise = fnl_state(//External Constructor
		//Base Noise Values
		seed, frequency, SELECTED_NOISE_TYPE,
		FNL_ROTATION_NONE,// Unused in current example (and in Godot too...)
		//Fractal
		SELECTED_FRACTAL_TYPE, octaves, lacunarity, gain, weighted_strength,
		#if SELECTED_FRACTAL_TYPE==FNL_FRACTAL_PINGPONG
		ping_pong_strength, //Ping-Pong-Fractal-Only
		#else
		0.0,
		#endif
		//Celular Only
		#if SELECTED_NOISE_TYPE==FNL_NOISE_CELLULAR
		distance_function, return_type, jitter,
		#else
		0,0,0.0,
		#endif
		//Domain Warp (not usued here)
		0, 0.0);
	// Is in 3D space?
	#if IS_3D_TEXTURE
	float noise_value = (fnlGetNoise3D(noise,coords.x,coords.y, coords.z)+1.0)/2.0;
	#elif IN_3D_SPACE
	float noise_value = (fnlGetNoise3D(noise,coords.x,coords.z, coords.y)+1.0)/2.0;
	#else
	float noise_value = (fnlGetNoise2D(noise,coords.x,coords.z)+1.0)/2.0;
	#endif
	return invert ? 1.0-noise_value : noise_value;
}

#if IS_3D_TEXTURE
#define OFFSET offset
#define UVW uvw
#define WDH wdh
#else
#define OFFSET offset.xzy
#define UVW uvw
#define WDH wdh.xzy
#endif

// GENERATE NOISE TEXTURE FOR DIFFERENT MODES
// Seamless: based of this code: https://github.com/godotengine/godot/blob/07b88600b793104b21244aa36d0cc37b689e9b95/modules/noise/noise.h#L85
float make(vec3 coords){
	#if !SEAMLESS
		return gen_noise(coords+OFFSET);
	#else
	vec4 skirt = vec4(WDH,0.0);
	vec3 skirt_size = WDH*seamless_blend_skirt;
	vec3 new_coords = mod(coords+0.5*WDH,WDH);
	vec3 off_coords=new_coords+OFFSET;
	#if IS_3D_TEXTURE
	vec3 a = 1.0 - smoothstep(0.1,0.9,new_coords/skirt_size);
	if (new_coords.x < skirt_size.x){
		float x01y00z00 = mix(
			gen_noise(off_coords),
			gen_noise(off_coords + skirt.xww),a.x);
		if (new_coords.y < skirt_size.y){
			float x01y11z00 = mix(
				gen_noise(off_coords + skirt.wyw),
				gen_noise(off_coords + skirt.xyw),a.x);
			if (new_coords.z < skirt_size.z){
				float x01y00z11 = mix(
					gen_noise(off_coords + skirt.wwz),
					gen_noise(off_coords + skirt.xwz),a.x);
				float x01y11z11 = mix(
					gen_noise(off_coords + skirt.wyz),
					gen_noise(off_coords + skirt.xyz),a.x);
				return mix(
					mix(x01y00z00,x01y11z00,a.y),
					mix(x01y00z11,x01y11z11,a.y),a.z);
			}
			return mix(x01y00z00,x01y11z00,a.y);
		}
		if (new_coords.z < skirt_size.z){
			float x01y00z11= mix(
				gen_noise(off_coords + skirt.wwz),
				gen_noise(off_coords + skirt.xwz),a.x);
			return mix(x01y00z00,x01y00z11,a.z);
		}
		return x01y00z00;
	}
	if (new_coords.y < skirt_size.y){
		float x00y01z00 = mix(
			gen_noise(off_coords),
			gen_noise(off_coords + skirt.wyw),a.y);
		if (new_coords.z < skirt_size.z){
			float x00y01z11= mix(
				gen_noise(off_coords + skirt.wwz),
				gen_noise(off_coords + skirt.wyz),a.y);
			return mix(x00y01z00,x00y01z11,a.z);
		}
		return x00y01z00;
	}
	if (new_coords.z < skirt_size.z){
		float a = 1.0 - smoothstep(0.1,0.9,new_coords.z/skirt_size.z);
		float x00y00z01 = mix(
			gen_noise(off_coords),
			gen_noise(off_coords + skirt.wwz),a);
		return x00y00z01;
	}
	return gen_noise(off_coords);//x00y00z00
	#elif IN_3D_SPACE
	vec2 a = 1.0 - smoothstep(0.1,0.9,new_coords.xz/skirt_size.xz);
	if (new_coords.x < skirt_size.x){
		float x01z00 = mix(
			gen_noise(off_coords),
			gen_noise(off_coords + skirt.xww),a.x);
		if (new_coords.z < skirt_size.z){
			float x01z11= mix(
				gen_noise(off_coords + skirt.wwz),
				gen_noise(off_coords + skirt.xwz),a.x);
			return mix(x01z00,x01z11,a.y);
		}
		return x01z00;
	}
	if (new_coords.z < skirt_size.z){
		float x00z01 = mix(
			gen_noise(off_coords),
			gen_noise(off_coords + skirt.wwz),a.y);
		return x00z01;
	}
	return gen_noise(off_coords);//x00y00z00
	#else //2D texture
	vec2 a = 1.0 - smoothstep(0.1,0.9,new_coords.xz/skirt_size.xz);
	if (new_coords.x < skirt_size.x){
		float x01z00 = mix(
			gen_noise(off_coords),
			gen_noise(off_coords + skirt.xww),a.x);
		if (new_coords.z < skirt_size.z){
			float x01z11= mix(
				gen_noise(off_coords + skirt.wwz),
				gen_noise(off_coords + skirt.xwz),a.x);
			return mix(x01z00,x01z11,a.y);
		}
		return x01z00;
	}
	if (new_coords.z < skirt_size.z){
		float x00z01 = mix(
			gen_noise(off_coords),
			gen_noise(off_coords + skirt.wwz),a.y);
		return x00z01;
	}
	return gen_noise(off_coords);//x00y00z00
	#endif
	#endif
}

// Full port of this code: https://github.com/godotengine/godot/blob/d822fd53221f68c562deda6a8c35a524e7fdf146/core/io/image.cpp#L3648
#if AS_NORMAL_MAP
uniform float bump_strength : hint_range(0.0, 32.0, 0.001) = 8.0;
vec3 to_normal_map(vec3 coords){
	float here = make(coords);
	float to_right = make(coords + vec3(1.0,0,0));
	float above = make(coords + vec3(0,0,1.0));
	vec3 up = (vec3(0,1,(here - above)*bump_strength));
	vec3 across = (vec3(1,0,(to_right - here)*bump_strength));
	return normalize(cross(across,up))*0.5+0.5;
}
#endif

varying vec3 base_coords;
void vertex(){
	// + 0.000005 to fix jitter lag when floor(VERTEX/(uvw+uvw*k))==0 where k is any integer
	// This bug is located deep inside FNL libruary
	// just don't set the size of a mesh to uvw+uvw*k + 0.000005 (tecknicaly it's imposible) =D
	//If in canvas item mode
	#ifdef CANVAS_ITEM
	#define ALBEDO COLOR.rgb
	#define ALPHA COLOR.a
	base_coords = vec3(VERTEX,0.0).xzy/UVW+0.5 + 0.000005;
	#else
	base_coords = VERTEX/UVW+0.5 + 0.000005;
	#endif
}

void fragment() {
	#if AS_NORMAL_MAP
		ALBEDO = to_normal_map(fract(base_coords)*WDH-0.5);
	#else
		float base_value = make(fract(base_coords)*WDH-0.5);
		//Color ramp
		if (texture(color_ramp,vec2(base_value,0))!=vec4(1,1,1,1)){//color ramp exist
			float clr_value = clamp(base_value,0.005,0.995);
			ALBEDO = texture(color_ramp,vec2(invert ? 1.0-clr_value : clr_value,0.0)).rgb;
		}
		else{//no color ramp
		switch(output){ //colorchanel selection
			case 4: ALPHA = base_value;break;
			case 3: ALBEDO.b = base_value;break;
			case 2: ALBEDO.g = base_value;break;
			case 1: ALBEDO.r = base_value;break;
			default: ALBEDO = vec3(base_value);break;}
		}
	#endif
}