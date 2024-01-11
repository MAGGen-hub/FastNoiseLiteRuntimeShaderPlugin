shader_type spatial;
//render_mode depth_prepass_alpha,cull_back,depth_draw_always;
#define DEFINE_OVERRIDE
#define SELECTED_NOISE_TYPE 0
#define SELECTED_FRACTAL_TYPE 0
#define SELECTED_DOMAIN_WARP_TYPE 0
#define SELECTED_DOMAIN_WARP_FRACTAL_TYPE 0
#define FNL_COMPILLER_OPTIMISATIONS_REQUIRED
#include "res://addons/FastNoiseLiteRuntimeShader/FastNoiseLiteLib.gdshaderinc"
#define IS_3D_TEXTURE false
#define IN_3D_SPACE false
#define DOMAIN_WARP_ENABLED false
#define SEAMLESS false
#define AS_NORMAL_MAP false
#define NO_GROUPS
//only if in canvas Item mode
//#define CANVAS_ITEM
#include "res://addons/FastNoiseLiteRuntimeShader/FastNoiseLiteBase.gdshaderinc"