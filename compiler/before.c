//int _fnlFastFloor(FNLfloat f) { return int(floor(f)); }
#define _fnlFastFloor(f) int(floor(f))
//int _fnlFastRound(FNLfloat f) { return int(round(f)); }
#define _fnlFastRound(f) int(round(f))
//float _fnlFastMin(float x, float y) { return min(x, y); }
#define _fnlFastMin min
//float _fnlFastMax(float x, float y) { return max(x, y); }
#define _fnlFastMax max
//float _fnlFastAbs(float f) { return abs(f); }
#define _fnlFastAbs abs
//float _fnlFastSqrt(float a) { return sqrt(a); }
#define _fnlFastSqrt sqrt
//float _fnlLerp(float a, float b, float t) { return mix(a, b, t); }
#define _fnlLerp mix

//region UNIFORM_VARIABLE_PROTECTION
//
// This section was created to protect users from
// bumping into undetectable errors.
//
// If name of unifor is equal to early defined
// local or global variable - shader will stop
// working without ANY explanation!

//Specific
#define GRADIENTS_2D _fnl_lib__GRADIENTS_2D
#define RAND_VECS_2D _fnl_lib__RAND_VECS_2D
#define GRADIENTS_3D _fnl_lib__GRADIENTS_3D
#define RAND_VECS_3D _fnl_lib__RAND_VECS_3D

#define state _fnl_lib__state
#define a _fnl_lib__a
#define b _fnl_lib__b
#define c _fnl_lib__c
#define d _fnl_lib__d
#define t _fnl_lib__t
#define amp _fnl_lib__amp
#define ampFractal _fnl_lib__ampFractal
#define xPrimed _fnl_lib__xPrimed
#define yPrimed _fnl_lib__yPrimed
#define zPrimed _fnl_lib__zPrimed
#define hash _fnl_lib__hash
#define x _fnl_lib__x
#define y _fnl_lib__y
#define z _fnl_lib__z
#define xo _fnl_lib__xo
#define yo _fnl_lib__yo
#define zo _fnl_lib__zo
#define xg _fnl_lib__xg
#define yg _fnl_lib__yg
#define zg _fnl_lib__zg
#define xd _fnl_lib__xd
#define yd _fnl_lib__yd
#define zd _fnl_lib__zd
#define xgo _fnl_lib__xgo
#define ygo _fnl_lib__ygo
#define zgo _fnl_lib__zgo
#define index1 _fnl_lib__index1
#define index2 _fnl_lib__index2
#define value _fnl_lib__value
#define xy _fnl_lib__xy
#define xz _fnl_lib__xz
#define SQRT3 _fnl_lib__SQRT3
#define F2 _fnl_lib__F2
#define s2 _fnl_lib__s2
#define r _fnl_lib__r
#define R3 _fnl_lib__R3
#define G2 _fnl_lib_G2
#define i _fnl_lib_i
#define j _fnl_lib_j
#define k _fnl_lib_k
#define i1 _fnl_lib_i1
#define j1 _fnl_lib_j1
#define k1 _fnl_lib_k1
#define l _fnl_lib_l
#define xi _fnl_lib_xi
#define yi _fnl_lib_yi
#define zi _fnl_lib_zi
#define xs _fnl_lib_xs
#define ys _fnl_lib_ys
#define zs _fnl_lib_zs
#define x0 _fnl_lib_x0
#define y0 _fnl_lib_y0
#define z0 _fnl_lib_z0
#define x1 _fnl_lib_x1
#define y1 _fnl_lib_y1
#define z1 _fnl_lib_z1
#define x2 _fnl_lib_x2
#define y2 _fnl_lib_y2
#define z2 _fnl_lib_z2
#define x3 _fnl_lib_x3
#define y3 _fnl_lib_y3
#define z3 _fnl_lib_z3
#define x4 _fnl_lib_x4
#define y4 _fnl_lib_y4
#define z4 _fnl_lib_z4
#define x5 _fnl_lib_x5
#define y5 _fnl_lib_y5
#define z5 _fnl_lib_z5
#define x6 _fnl_lib_x6
#define y6 _fnl_lib_y6
#define z6 _fnl_lib_z6
#define x7 _fnl_lib_x7
#define y7 _fnl_lib_y7
#define z7 _fnl_lib_z7
#define x8 _fnl_lib_x8
#define y8 _fnl_lib_y8
#define z8 _fnl_lib_z8
#define x9 _fnl_lib_x9
#define y9 _fnl_lib_y9
#define z9 _fnl_lib_z9
#define xA _fnl_lib_xA
#define yA _fnl_lib_yA
#define zA _fnl_lib_zA
#define xB _fnl_lib_xB
#define yB _fnl_lib_yB
#define zB _fnl_lib_zB
#define xC _fnl_lib_xC
#define yC _fnl_lib_yC
#define zC _fnl_lib_zC
#define xD _fnl_lib_xD
#define yD _fnl_lib_yD
#define zD _fnl_lib_zD
#define n0 _fnl_lib_n0
#define n1 _fnl_lib_n1
#define n2 _fnl_lib_n2
#define xNSign _fnl_float_xNSign
#define yNSign _fnl_float_yNSign
#define zNSign _fnl_float_zNSign
#define ax0 _fnl_float_ax0
#define ay0 _fnl_float_ay0
#define az0 _fnl_float_az0
#define t2 _fnl_lib__t2
#define t3 _fnl_lib__t3
#define a0 _fnl_lib__a0
#define a1 _fnl_lib__a1
#define a2 _fnl_lib__a2
#define a3 _fnl_lib__a3
#define a4 _fnl_lib__a4
#define a5 _fnl_lib__a5
#define a6 _fnl_lib__a6
#define a7 _fnl_lib__a7
#define a8 _fnl_lib__a8
#define a9 _fnl_lib__a9
#define aA _fnl_lib__aA
#define aB _fnl_lib__aB
#define aC _fnl_lib__aC
#define aD _fnl_lib__aD
#define aMask _fnl_lib__aMask
#define bMask _fnl_lib__bMask
#define cMask _fnl_lib__cMask
#define di2 _fnl_lib__di2
#define ndj2 _fnl_lib__ndj2
#define ndi3 _fnl_lib__ndi3
#define dj3 _fnl_lib__dj3
#define seed2 _fnl_lib__seed2
#define xNMask _fnl_lib__xNMask
#define yNMask _fnl_lib__yNMask
#define zNMask _fnl_lib__zNMask
#define xAFlipMask0 _fnl_lib__xAFlipMask0
#define yAFlipMask0 _fnl_lib__yAFlipMask0
#define zAFlipMask0 _fnl_lib__zAFlipMask0
#define xAFlipMask1 _fnl_lib__xAFlipMask1
#define yAFlipMask1 _fnl_lib__yAFlipMask1
#define zAFlipMask1 _fnl_lib__zAFlipMask1
#define skip5 _fnl_lib__skip5
#define skip9 _fnl_lib__skip9
#define skipD _fnl_lib__skipD
#define xr _fnl_lib__xr
#define yr _fnl_lib__yr
#define zr _fnl_lib__zr
#define distance0 _fnl_lib__distance0
#define distance1 _fnl_lib__distance1
#define closestHash _fnl_lib__closestHash
#define cellularJitter _fnl_lib__cellularJitter
#define xPrimedBase _fnl_lib__xPrimedBase
#define yPrimedBase _fnl_lib__yPrimedBase
#define zPrimedBase _fnl_lib__zPrimedBase
#define idx _fnl_lib__idx
#define vecX _fnl_lib__vecX
#define vecY _fnl_lib__vecY
#define vecZ _fnl_lib__vecZ
#define newDistance _fnl_lib__newDistance
#define xd0 _fnl_lib__xd0
#define yd0 _fnl_lib__yd0
#define zd0 _fnl_lib__zd0
#define xd1 _fnl_lib__xd1
#define yd1 _fnl_lib__yd1
#define zd1 _fnl_lib__zd1
#define xf0 _fnl_lib__xf0
#define xf1 _fnl_lib__xf1
#define yf0 _fnl_lib__yf0
#define yf1 _fnl_lib__yf1
#define xf00 _fnl_lib__xf00
#define xf10 _fnl_lib__xf10
#define xf01 _fnl_lib__xf01
#define xf11 _fnl_lib__xf11
#define idx0 _fnl_lib__idx0
#define idx1 _fnl_lib__idx1
#define lx0x _fnl_lib__lx0x
#define ly0x _fnl_lib__ly0x
#define lz0x _fnl_lib__lz0x
#define lx1x _fnl_lib__lx1x
#define ly1x _fnl_lib__ly1x
#define lz1x _fnl_lib__lz1x
#define lx0y _fnl_lib__lx0y
#define ly0y _fnl_lib__ly0y
#define lz0y _fnl_lib__lz0y
#define xp _fnl_lib__xp
#define yp _fnl_lib__yp
#define zp _fnl_lib__zp
#define freq _fnl_lib__freq
#define sum _fnl_lib__sum
#define noise _fnl_lib__noise
#define vx _fnl_lib__vx
#define vy _fnl_lib__vy
#define vz _fnl_lib__vz
#define outGradOnly _fnl_lib__outGradOnly
#define aaaa _fnl_lib__aaaa
#define bbbb _fnl_lib__bbbb
#define cccc _fnl_lib__cccc
#define warpAmp _fnl_lib__warpAmp
#define newState _fnl_lib__newState
#define seed _fnl_lib__seed
#define gain _fnl_lib__gain
//#define OBJ _fnl_lib__
//endregion
float _fnlCubicLerp(float a, float b, float c, float d, float t)
{d-=c;return fma(pow(t,3),d-a+b,fma(pow(t,2),fma(a-b,2.0,-d),fma(t,c-a,b)));}

float _fnlPingPong(float t){t-=floor(t*0.5f)*2.f;return t < 1.f ? t : 2.f-t;}


float _fnlCalculateFractalBounding(fnl_state state)
{
    float gain = _fnlFastAbs(
	#undef gain
		state.gain
	#define gain _fnl_lib__gain
	);
    float amp = gain;
    float ampFractal = 1.f;
    for (int i = 1; i < state.octaves; i++)
    {
        ampFractal += amp;
        amp *= gain;
    }
    return 1.f / ampFractal;
}

#undef gain

int _fnlHash2D(int seed, int xPrimed, int yPrimed)
{
    int hash = seed ^ xPrimed ^ yPrimed;
	
    hash *= 0x27d4eb2d;
    return hash;
}

int _fnlHash3D(int seed, int xPrimed, int yPrimed, int zPrimed)
{
    int hash = seed ^ xPrimed ^ yPrimed ^ zPrimed;

    hash *= 0x27d4eb2d;
    return hash;
}

float _fnlValCoord2D(int seed, int xPrimed, int yPrimed)
{
    int hash = _fnlHash2D(seed, xPrimed, yPrimed);
    hash *= hash;
    hash ^= hash << 19;
    return float(hash) * (1.f / 2147483648.f);
}

float _fnlValCoord3D(int seed, int xPrimed, int yPrimed, int zPrimed)
{
    int hash = _fnlHash3D(seed, xPrimed, yPrimed, zPrimed);
    hash *= hash;
    hash ^= hash << 19;
    return float(hash) * (1.f / 2147483648.f);
}

float _fnlGradCoord2D(int seed, int xPrimed, int yPrimed, float xd, float yd)
{
    int hash = _fnlHash2D(seed, xPrimed, yPrimed);
    hash ^= hash >> 15;
    hash &= 127 << 1;
    return xd * GRADIENTS_2D[hash] + yd * GRADIENTS_2D[hash | 1];
}

float _fnlGradCoord3D(int seed, int xPrimed, int yPrimed, int zPrimed, float xd, float yd, float zd)
{
    int hash = _fnlHash3D(seed, xPrimed, yPrimed, zPrimed);
    hash ^= hash >> 15;
    hash &= 63 << 2;
    return xd * GRADIENTS_3D[hash] + yd * GRADIENTS_3D[hash | 1] + zd * GRADIENTS_3D[hash | 2];
}

void _fnlGradCoordOut2D(int seed, int xPrimed, int yPrimed, out float xo, out float yo)
{
    int hash = _fnlHash2D(seed, xPrimed, yPrimed) & (255 << 1);

    xo = RAND_VECS_2D[hash];
    yo = RAND_VECS_2D[hash | 1];
}

void _fnlGradCoordOut3D(int seed, int xPrimed, int yPrimed, int zPrimed, out float xo, out float yo, out float zo)
{
    int hash = _fnlHash3D(seed, xPrimed, yPrimed, zPrimed) & (255 << 2);

    xo = RAND_VECS_3D[hash];
    yo = RAND_VECS_3D[hash | 1];
    zo = RAND_VECS_3D[hash | 2];
}

void _fnlGradCoordDual2D(int seed, int xPrimed, int yPrimed, float xd, float yd, out float xo, out float yo)
{
    int hash = _fnlHash2D(seed, xPrimed, yPrimed);
    int index1 = hash & (127 << 1);
    int index2 = (hash >> 7) & (255 << 1);

    float xg = GRADIENTS_2D[index1];
    float yg = GRADIENTS_2D[index1 | 1];
    float value = xd * xg + yd * yg;

    float xgo = RAND_VECS_2D[index2];
    float ygo = RAND_VECS_2D[index2 | 1];

    xo = value * xgo;
    yo = value * ygo;
}

void _fnlGradCoordDual3D(int seed, int xPrimed, int yPrimed, int zPrimed, float xd, float yd, float zd, out float xo, out float yo, out float zo)
{
    int hash = _fnlHash3D(seed, xPrimed, yPrimed, zPrimed);
    int index1 = hash & (63 << 2);
    int index2 = (hash >> 6) & (255 << 2);

    float xg = GRADIENTS_3D[index1];
    float yg = GRADIENTS_3D[index1 | 1];
    float zg = GRADIENTS_3D[index1 | 2];
    float value = xd * xg + yd * yg + zd * zg;

    float xgo = RAND_VECS_3D[index2];
    float ygo = RAND_VECS_3D[index2 | 1];
    float zgo = RAND_VECS_3D[index2 | 2];

    xo = value * xgo;
    yo = value * ygo;
    zo = value * zgo;
}
// Noise Coordinate Transforms (frequency, and possible skew or rotation)
void _fnlTransformNoiseCoordinate2D(fnl_state state, inout FNLfloat x, inout FNLfloat y)
{
    x *= state.frequency;
    y *= state.frequency;

    switch (state.noise_type)
    {
        case FNL_NOISE_OPENSIMPLEX2:
        case FNL_NOISE_OPENSIMPLEX2S:
        {
            const FNLfloat SQRT3 = FNLfloat(1.7320508075688772935274463415059);
            const FNLfloat F2 = 0.5f * (SQRT3 - 1.f);
            FNLfloat t = (x + y) * F2;
            x += t;
            y += t;
        }
        break;
        default:
            break;
    }
}


void _fnlTransformNoiseCoordinate3D(fnl_state state, inout FNLfloat x, inout FNLfloat y, inout FNLfloat z)
{
    x *= state.frequency;
    y *= state.frequency;
    z *= state.frequency;

    switch (state.rotation_type_3d)
    {
        case FNL_ROTATION_IMPROVE_XY_PLANES:
        {
            FNLfloat xy = x + y;
            FNLfloat s2 = xy * -FNLfloat(0.211324865405187);
            z *= FNLfloat(0.577350269189626);
            x += s2 - z;
            y = y + s2 - z;
            z += xy * FNLfloat(0.577350269189626);
        }
        break;
        case FNL_ROTATION_IMPROVE_XZ_PLANES:
        {
            FNLfloat xz = x + z;
            FNLfloat s2 = xz * -FNLfloat(0.211324865405187);
            y *= FNLfloat(0.577350269189626);
            x += s2 - y;
            z += s2 - y;
            y += xz * FNLfloat(0.577350269189626);
        }
        break;
        default:
            switch (state.noise_type)
            {
            case FNL_NOISE_OPENSIMPLEX2:
            case FNL_NOISE_OPENSIMPLEX2S:
            {
                const FNLfloat R3 = FNLfloat(2.f / 3.f);
                FNLfloat r = (x + y + z) * R3; // Rotation, not skew
                x = r - x;
                y = r - y;
                z = r - z;
            }
            break;
            default:
                break;
            }
            break;
    }
}

// Domain Warp Coordinate Transforms
void _fnlTransformDomainWarpCoordinate2D(fnl_state state, inout FNLfloat x, inout FNLfloat y)
{
    switch (state.domain_warp_type)
    {
        case FNL_DOMAIN_WARP_OPENSIMPLEX2:
        case FNL_DOMAIN_WARP_OPENSIMPLEX2_REDUCED:
        {
            const FNLfloat SQRT3 = FNLfloat(1.7320508075688772935274463415059);
            const FNLfloat F2 = 0.5f * (SQRT3 - 1.f);
            FNLfloat t = (x + y) * F2;
            x += t;
            y += t;
        }
        break;
        default:
            break;
    }
}

void _fnlTransformDomainWarpCoordinate3D(fnl_state state, inout FNLfloat x, inout FNLfloat y, inout FNLfloat z)
{
    switch (state.rotation_type_3d)
    {
        case FNL_ROTATION_IMPROVE_XY_PLANES:
        {
            FNLfloat xy = x + y;
            FNLfloat s2 = xy * -FNLfloat(0.211324865405187);
            z *= FNLfloat(0.577350269189626);
            x += s2 - z;
            y = y + s2 - z;
            z += xy * FNLfloat(0.577350269189626);
        }
        break;
        case FNL_ROTATION_IMPROVE_XZ_PLANES:
        {
            FNLfloat xz = x + z;
            FNLfloat s2 = xz * -FNLfloat(0.211324865405187);
            y *= FNLfloat(0.577350269189626);
            x += s2 - y;
            z += s2 - y;
            y += xz * FNLfloat(0.577350269189626);
        }
        break;
        default:
            switch (state.domain_warp_type)
            {
            case FNL_DOMAIN_WARP_OPENSIMPLEX2:
            case FNL_DOMAIN_WARP_OPENSIMPLEX2_REDUCED:
            {
                const FNLfloat R3 = FNLfloat(2.f / 3.f);
                FNLfloat r = (x + y + z) * R3; // Rotation, not skew
                x = r - x;
                y = r - y;
                z = r - z;
            }
            break;
            default:
                break;
            }
        break;
    }
}

// Simplex/OpenSimplex2 Noise
float _fnlSingleSimplex2D(int seed, FNLfloat x, FNLfloat y)
{
    // 2D OpenSimplex2 case uses the same algorithm as ordinary Simplex.

    const float SQRT3 = 1.7320508075688772935274463415059;
    const float G2 = (3.f - SQRT3) / 6.f;

    // --- Skew moved to TransformNoiseCoordinate method ---
    // const FNLfloat F2 = 0.5f * (SQRT3 - 1);
    // FNLfloat s = (x + y) * F2;
    // x += s; y += s;


    int i = _fnlFastFloor(x);
    int j = _fnlFastFloor(y);
    float xi = x - float(i);
    float yi = y - float(j);

    float t = (xi + yi) * G2;
    float x0 = xi - t;
    float y0 = yi - t;

    i *= PRIME_X;
    j *= PRIME_Y;

    float n0, n1, n2;

    float a = 0.5f - x0 * x0 - y0 * y0;
    if (a <= 0.f)
	{
		n0 = 0.f;
	}
    else
	{
        n0 = (a * a) * (a * a) * _fnlGradCoord2D(seed, i, j, x0, y0);
	}

    float c = (2.f * (1.f - 2.f * G2) * (1.f / G2 - 2.f)) * t + ((-2.f * (1.f - 2.f * G2) * (1.f - 2.f * G2)) + a);
    if (c <= 0.f)
	{		
        n2 = 0.f;
	}
    else
    {
        float x2 = x0 + (2.f * G2 - 1.f);
        float y2 = y0 + (2.f * G2 - 1.f);
        n2 = (c * c) * (c * c) * _fnlGradCoord2D(seed, i + PRIME_X, j + PRIME_Y, x2, y2);
    }

    if (y0 > x0)
    {
        float x1 = x0 + G2;
        float y1 = y0 + G2 - 1.f;
        float b = 0.5f - x1 * x1 - y1 * y1;
        if (b <= 0.f)
		{			
            n1 = 0.f;
		}
        else
		{
            n1 = (b * b) * (b * b) * _fnlGradCoord2D(seed, i, j + PRIME_Y, x1, y1);
        }
    }
    else
    {
        float x1 = x0 + (G2 - 1.f);
        float y1 = y0 + G2;
        float b = 0.5f - x1 * x1 - y1 * y1;
        if (b <= 0.f)
		{			
            n1 = 0.f;
		}
        else
        {
            n1 = (b * b) * (b * b) * _fnlGradCoord2D(seed, i + PRIME_X, j, x1, y1);
        }
    }

    return (n0 + n1 + n2) * 99.83685446303647;
}
float _fnlSingleOpenSimplex23D(int seed, FNLfloat x, FNLfloat y, FNLfloat z)
{
    // 3D OpenSimplex2 case uses two offset rotated cube grids.

    // --- Rotation moved to TransformNoiseCoordinate method ---
    // const FNLfloat R3 = (FNLfloat)(2.f / 3.f);
    // FNLfloat r = (x + y + z) * R3; // Rotation, not skew
    // x = r - x; y = r - y; z = r - z;


    int i = _fnlFastRound(x);
    int j = _fnlFastRound(y);
    int k = _fnlFastRound(z);
    float x0 = x - float(i);
    float y0 = y - float(j);
    float z0 = z - float(k);

    int xNSign = int(-1.f - x0) | 1;
    int yNSign = int(-1.f - y0) | 1;
    int zNSign = int(-1.f - z0) | 1;

    float ax0 = float(xNSign) * -x0;
    float ay0 = float(yNSign) * -y0;
    float az0 = float(zNSign) * -z0;

    i *= PRIME_X;
    j *= PRIME_Y;
    k *= PRIME_Z;

    float value = 0.f;
    float a = (0.6f - x0 * x0) - (y0 * y0 + z0 * z0);

    for (int l = 0; ; l++)
    {
        if (a > 0.f)
        {
            value += (a * a) * (a * a) * _fnlGradCoord3D(seed, i, j, k, x0, y0, z0);
        }

        float b = a + 1.f;
        int i1 = i;
        int j1 = j;
        int k1 = k;
        float x1 = x0;
        float y1 = y0;
        float z1 = z0;
        if (ax0 >= ay0 && ax0 >= az0)
        {
            x1 += float(xNSign);
            b -= float(xNSign) * 2.f * x1;
            i1 -= xNSign * PRIME_X;
        }
        else if (ay0 > ax0 && ay0 >= az0)
        {
            y1 += float(yNSign);
            b -= float(yNSign) * 2.f * y1;
            j1 -= yNSign * PRIME_Y;
        }
        else
        {
            z1 += float(zNSign);
            b -= float(zNSign) * 2.f * z1;
            k1 -= zNSign * PRIME_Z;
        }

        if (b > 0.f)
        {
            value += (b * b) * (b * b) * _fnlGradCoord3D(seed, i1, j1, k1, x1, y1, z1);
        }

        if (l == 1) break;

        ax0 = 0.5f - ax0;
        ay0 = 0.5f - ay0;
        az0 = 0.5f - az0;

        x0 = float(xNSign) * ax0;
        y0 = float(yNSign) * ay0;
        z0 = float(zNSign) * az0;

        a += (0.75f - ax0) - (ay0 + az0);

        i += (xNSign >> 1) & PRIME_X;
        j += (yNSign >> 1) & PRIME_Y;
        k += (zNSign >> 1) & PRIME_Z;

        xNSign = -xNSign;
        yNSign = -yNSign;
        zNSign = -zNSign;

        seed = ~seed;
    }

    return value * 32.69428253173828125;
}


// OpenSimplex2S Noise
float _fnlSingleOpenSimplex2S2D(int seed, FNLfloat x, FNLfloat y)
{
    // 2D OpenSimplex2S case is a modified 2D simplex noise.

    const FNLfloat SQRT3 = FNLfloat(1.7320508075688772935274463415059);
    const FNLfloat G2 = (3.f - SQRT3) / 6.f;

    // --- Skew moved to TransformNoiseCoordinate method ---
    // const FNLfloat F2 = 0.5f * (SQRT3 - 1);
    // FNLfloat s = (x + y) * F2;
    // x += s; y += s;


    int i = _fnlFastFloor(x);
    int j = _fnlFastFloor(y);
    float xi = x - float(i);
    float yi = y - float(j);

    i *= PRIME_X;
    j *= PRIME_Y;
    int i1 = i + PRIME_X;
    int j1 = j + PRIME_Y;

    float t = (xi + yi) * G2;
    float x0 = xi - t;
    float y0 = yi - t;

    int aMask = int((xi + yi + 1.f) * -0.5f);
    int bMask = int((xi - float(aMask) - 2.f) * 0.5f - yi);
    int cMask = int((yi - float(aMask) - 2.f) * 0.5f - xi);

    float a0 = (2.f / 3.f) - x0 * x0 - y0 * y0;
    float value = (a0 * a0) * (a0 * a0) * _fnlGradCoord2D(seed, i, j, x0, y0);

    float a1 = (2.f * (1.f - 2.f * G2) * (1.f / G2 - 2.f)) * t + ((-2.f * (1.f - 2.f * G2) * (1.f - 2.f * G2)) + a0);
    float x1 = x0 - (1.f - 2.f * G2);
    float y1 = y0 - (1.f - 2.f * G2);
    value += (a1 * a1) * (a1 * a1) * _fnlGradCoord2D(seed, i1, j1, x1, y1);

    int di2 = ~(aMask | cMask) | 1;
    int ndj2 = (aMask & bMask) << 1;
    float t2 = float(di2 - ndj2) * G2;
    float x2 = x0 - float(di2) + t2;
    float y2 = y0 + float(ndj2) + t2;
    float a2 = (2.f / 3.f) - x2 * x2 - y2 * y2;
    if (a2 > 0.f)
    {
        value += (a2 * a2) * (a2 * a2) * _fnlGradCoord2D(seed, i1 + (di2 & (-PRIME_X << 1)), j + (ndj2 & (PRIME_Y << 1)), x2, y2);
    }

    int ndi3 = (aMask & cMask) << 1;
    int dj3 = ~(aMask | bMask) | 1;
    float t3 = float(dj3 - ndi3) * G2;
    float x3 = x0 + float(ndi3) + t3;
    float y3 = y0 - float(dj3) + t3;
    float a3 = (2.f / 3.f) - x3 * x3 - y3 * y3;
    if (a3 > 0.f)
    {
        value += (a3 * a3) * (a3 * a3) * _fnlGradCoord2D(seed, i + (ndi3 & (PRIME_X << 1)), j1 + (dj3 & (-PRIME_Y << 1)), x3, y3);
    }

    return value * 18.24196194486065;
}


float _fnlSingleOpenSimplex2S3D(int seed, FNLfloat x, FNLfloat y, FNLfloat z)
{
    // 3D OpenSimplex2S case uses two offset rotated cube grids.

    // --- Rotation moved to TransformNoiseCoordinate method ---
    // const FNLfloat R3 = (FNLfloat)(2.f / 3.f);
    // FNLfloat r = (x + y + z) * R3; // Rotation, not skew
    // x = r - x; y = r - y; z = r - z;


    int i = _fnlFastFloor(x);
    int j = _fnlFastFloor(y);
    int k = _fnlFastFloor(z);
    float xi = x - float(i);
    float yi = y - float(j);
    float zi = z - float(k);

    i *= PRIME_X;
    j *= PRIME_Y;
    k *= PRIME_Z;
    int seed2 = seed + 1293373;

    int xNMask = int(-0.5f - xi);
    int yNMask = int(-0.5f - yi);
    int zNMask = int(-0.5f - zi);

    float x0 = xi + float(xNMask);
    float y0 = yi + float(yNMask);
    float z0 = zi + float(zNMask);
    float a0 = 0.75f - x0 * x0 - y0 * y0 - z0 * z0;
    float value = (a0 * a0) * (a0 * a0) * _fnlGradCoord3D(seed,
                                                          i + (xNMask & PRIME_X), j + (yNMask & PRIME_Y), k + (zNMask & PRIME_Z), x0, y0, z0);

    float x1 = xi - 0.5f;
    float y1 = yi - 0.5f;
    float z1 = zi - 0.5f;
    float a1 = 0.75f - x1 * x1 - y1 * y1 - z1 * z1;
    value += (a1 * a1) * (a1 * a1) * _fnlGradCoord3D(seed2,
                                                     i + PRIME_X, j + PRIME_Y, k + PRIME_Z, x1, y1, z1);

    float xAFlipMask0 = float((xNMask | 1) << 1) * x1;
    float yAFlipMask0 = float((yNMask | 1) << 1) * y1;
    float zAFlipMask0 = float((zNMask | 1) << 1) * z1;
    float xAFlipMask1 = float(-2 - (xNMask << 2)) * x1 - 1.f;
    float yAFlipMask1 = float(-2 - (yNMask << 2)) * y1 - 1.f;
    float zAFlipMask1 = float(-2 - (zNMask << 2)) * z1 - 1.f;

    bool skip5 = false;
    float a2 = xAFlipMask0 + a0;
    if (a2 > 0.f)
    {
        float x2 = x0 - float(xNMask | 1);
        float y2 = y0;
        float z2 = z0;
        value += (a2 * a2) * (a2 * a2) * _fnlGradCoord3D(seed,
                                                         i + (~xNMask & PRIME_X), j + (yNMask & PRIME_Y), k + (zNMask & PRIME_Z), x2, y2, z2);
    }
    else
    {
        float a3 = yAFlipMask0 + zAFlipMask0 + a0;
        if (a3 > 0.f)
        {
            float x3 = x0;
            float y3 = y0 - float(yNMask | 1);
            float z3 = z0 - float(zNMask | 1);
            value += (a3 * a3) * (a3 * a3) * _fnlGradCoord3D(seed,
                                                             i + (xNMask & PRIME_X), j + (~yNMask & PRIME_Y), k + (~zNMask & PRIME_Z), x3, y3, z3);
        }

        float a4 = xAFlipMask1 + a1;
        if (a4 > 0.f)
        {
            float x4 = float(xNMask | 1) + x1;
            float y4 = y1;
            float z4 = z1;
            value += (a4 * a4) * (a4 * a4) * _fnlGradCoord3D(seed2,
                                                             i + (xNMask & (PRIME_X * 2)), j + PRIME_Y, k + PRIME_Z, x4, y4, z4);
            skip5 = true;
        }
    }

    bool skip9 = false;
    float a6 = yAFlipMask0 + a0;
    if (a6 > 0.f)
    {
        float x6 = x0;
        float y6 = y0 - float(yNMask | 1);
        float z6 = z0;
        value += (a6 * a6) * (a6 * a6) * _fnlGradCoord3D(seed,
                                                         i + (xNMask & PRIME_X), j + (~yNMask & PRIME_Y), k + (zNMask & PRIME_Z), x6, y6, z6);
    }
    else
    {
        float a7 = xAFlipMask0 + zAFlipMask0 + a0;
        if (a7 > 0.f)
        {
            float x7 = x0 - float(xNMask | 1);
            float y7 = y0;
            float z7 = z0 - float(zNMask | 1);
            value += (a7 * a7) * (a7 * a7) * _fnlGradCoord3D(seed,
                                                             i + (~xNMask & PRIME_X), j + (yNMask & PRIME_Y), k + (~zNMask & PRIME_Z), x7, y7, z7);
        }

        float a8 = yAFlipMask1 + a1;
        if (a8 > 0.f)
        {
            float x8 = x1;
            float y8 = float(yNMask | 1) + y1;
            float z8 = z1;
            value += (a8 * a8) * (a8 * a8) * _fnlGradCoord3D(seed2,
                                                             i + PRIME_X, j + (yNMask & (PRIME_Y << 1)), k + PRIME_Z, x8, y8, z8);
            skip9 = true;
        }
    }

    bool skipD = false;
    float aA = zAFlipMask0 + a0;
    if (aA > 0.f)
    {
        float xA = x0;
        float yA = y0;
        float zA = z0 - float(zNMask | 1);
        value += (aA * aA) * (aA * aA) * _fnlGradCoord3D(seed,
                                                         i + (xNMask & PRIME_X), j + (yNMask & PRIME_Y), k + (~zNMask & PRIME_Z), xA, yA, zA);
    }
    else
    {
        float aB = xAFlipMask0 + yAFlipMask0 + a0;
        if (aB > 0.f)
        {
            float xB = x0 - float(xNMask | 1);
            float yB = y0 - float(yNMask | 1);
            float zB = z0;
            value += (aB * aB) * (aB * aB) * _fnlGradCoord3D(seed,
                                                             i + (~xNMask & PRIME_X), j + (~yNMask & PRIME_Y), k + (zNMask & PRIME_Z), xB, yB, zB);
        }

        float aC = zAFlipMask1 + a1;
        if (aC > 0.f)
        {
            float xC = x1;
            float yC = y1;
            float zC = float(zNMask | 1) + z1;
            value += (aC * aC) * (aC * aC) * _fnlGradCoord3D(seed2,
                                                             i + PRIME_X, j + PRIME_Y, k + (zNMask & (PRIME_Z << 1)), xC, yC, zC);
            skipD = true;
        }
    }

    if (!skip5)
    {
        float a5 = yAFlipMask1 + zAFlipMask1 + a1;
        if (a5 > 0.f)
        {
            float x5 = x1;
            float y5 = float(yNMask | 1) + y1;
            float z5 = float(zNMask | 1) + z1;
            value += (a5 * a5) * (a5 * a5) * _fnlGradCoord3D(seed2,
                                                             i + PRIME_X, j + (yNMask & (PRIME_Y << 1)), k + (zNMask & (PRIME_Z << 1)), x5, y5, z5);
        }
    }

    if (!skip9)
    {
        float a9 = xAFlipMask1 + zAFlipMask1 + a1;
        if (a9 > 0.f)
        {
            float x9 = float(xNMask | 1) + x1;
            float y9 = y1;
            float z9 = float(zNMask | 1) + z1;
            value += (a9 * a9) * (a9 * a9) * _fnlGradCoord3D(seed2,
                                                             i + (xNMask & (PRIME_X * 2)), j + PRIME_Y, k + (zNMask & (PRIME_Z << 1)), x9, y9, z9);
        }
    }

    if (!skipD)
    {
        float aD = xAFlipMask1 + yAFlipMask1 + a1;
        if (aD > 0.f)
        {
            float xD = float(xNMask | 1) + x1;
            float yD = float(yNMask | 1) + y1;
            float zD = z1;
            value += (aD * aD) * (aD * aD) * _fnlGradCoord3D(seed2,
                                                             i + (xNMask & (PRIME_X << 1)), j + (yNMask & (PRIME_Y << 1)), k + PRIME_Z, xD, yD, zD);
        }
    }

    return value * 9.046026385208288;
}

// Cellular Noise
float _fnlSingleCellular2D(fnl_state state, int seed, FNLfloat x, FNLfloat y)
{
    int xr = _fnlFastRound(x);
    int yr = _fnlFastRound(y);

    float distance0 = 1e10f;
    float distance1 = 1e10f;
    int closestHash = 0;

    float cellularJitter = 0.43701595f * state.cellular_jitter_mod;

    int xPrimed = (xr - 1) * PRIME_X;
    int yPrimedBase = (yr - 1) * PRIME_Y;

    switch (state.cellular_distance_func)
    {
        case FNL_CELLULAR_DISTANCE_MANHATTAN:
        {
            for (int xi = xr - 1; xi <= xr + 1; xi++)
            {
                int yPrimed = yPrimedBase;

                for (int yi = yr - 1; yi <= yr + 1; yi++)
                {
                    int hash = _fnlHash2D(seed, xPrimed, yPrimed);
                    int idx = hash & (255 << 1);

                    float vecX = float(xi) - x + RAND_VECS_2D[idx] * cellularJitter;
                    float vecY = float(yi) - y + RAND_VECS_2D[idx | 1] * cellularJitter;

                    float newDistance = _fnlFastAbs(vecX) + _fnlFastAbs(vecY);

                    distance1 = _fnlFastMax(_fnlFastMin(distance1, newDistance), distance0);
                    if (newDistance < distance0)
                    {
                        distance0 = newDistance;
                        closestHash = hash;
                    }
                    yPrimed += PRIME_Y;
                }
                xPrimed += PRIME_X;
            }
            break;
        }
        case FNL_CELLULAR_DISTANCE_HYBRID:
        {
            for (int xi = xr - 1; xi <= xr + 1; xi++)
            {
                int yPrimed = yPrimedBase;
                for (int yi = yr - 1; yi <= yr + 1; yi++)
                {
                    int hash = _fnlHash2D(seed, xPrimed, yPrimed);
                    int idx = hash & (255 << 1);

                    float vecX = float(xi) - x + RAND_VECS_2D[idx] * cellularJitter;
                    float vecY = float(yi) - y + RAND_VECS_2D[idx | 1] * cellularJitter;

                    float newDistance = (_fnlFastAbs(vecX) + _fnlFastAbs(vecY)) + (vecX * vecX + vecY * vecY);

                    distance1 = _fnlFastMax(_fnlFastMin(distance1, newDistance), distance0);
                    if (newDistance < distance0)
                    {
                        distance0 = newDistance;
                        closestHash = hash;
                    }
                    yPrimed += PRIME_Y;
                }
                xPrimed += PRIME_X;
            }
            break;
        }
		case FNL_CELLULAR_DISTANCE_EUCLIDEAN:
        case FNL_CELLULAR_DISTANCE_EUCLIDEANSQ:
        default:
        {
            for (int xi = xr - 1; xi <= xr + 1; xi++)
            {
                int yPrimed = yPrimedBase;

                for (int yi = yr - 1; yi <= yr + 1; yi++)
                {
                    int hash = _fnlHash2D(seed, xPrimed, yPrimed);
                    int idx = hash & (255 << 1);

                    float vecX = float(xi) - x + RAND_VECS_2D[idx] * cellularJitter;
                    float vecY = float(yi) - y + RAND_VECS_2D[idx | 1] * cellularJitter;

                    float newDistance = vecX * vecX + vecY * vecY;

                    distance1 = _fnlFastMax(_fnlFastMin(distance1, newDistance), distance0);
                    if (newDistance < distance0)
                    {
                        distance0 = newDistance;
                        closestHash = hash;
                    }
                    yPrimed += PRIME_Y;
                }
                xPrimed += PRIME_X;
            }
            break;
        }
    }

    if (state.cellular_distance_func == FNL_CELLULAR_DISTANCE_EUCLIDEAN && state.cellular_return_type >= FNL_CELLULAR_RETURN_TYPE_DISTANCE)
    {
        distance0 = _fnlFastSqrt(distance0);
        if (state.cellular_return_type >= FNL_CELLULAR_RETURN_TYPE_DISTANCE2)
		{			
            distance1 = _fnlFastSqrt(distance1);
		}
    }

    switch (state.cellular_return_type)
    {
        case FNL_CELLULAR_RETURN_TYPE_CELLVALUE:
            return float(closestHash) * (1.f / 2147483648.f);
        case FNL_CELLULAR_RETURN_TYPE_DISTANCE:
            return distance0 - 1.f;
        case FNL_CELLULAR_RETURN_TYPE_DISTANCE2:
            return distance1 - 1.f;
        case FNL_CELLULAR_RETURN_TYPE_DISTANCE2ADD:
            return (distance1 + distance0) * 0.5f - 1.f;
        case FNL_CELLULAR_RETURN_TYPE_DISTANCE2SUB:
            return distance1 - distance0 - 1.f;
        case FNL_CELLULAR_RETURN_TYPE_DISTANCE2MUL:
            return distance1 * distance0 * 0.5f - 1.f;
        case FNL_CELLULAR_RETURN_TYPE_DISTANCE2DIV:
            return distance0 / distance1 - 1.f;
        default:
            return 0.f;
    }
}

float _fnlSingleCellular3D(fnl_state state, int seed, FNLfloat x, FNLfloat y, FNLfloat z)
{
    int xr = _fnlFastRound(x);
    int yr = _fnlFastRound(y);
    int zr = _fnlFastRound(z);

    float distance0 = 1e10f;
    float distance1 = 1e10f;
    int closestHash = 0;

    float cellularJitter = 0.39614353 * state.cellular_jitter_mod;

    int xPrimed = (xr - 1) * PRIME_X;
    int yPrimedBase = (yr - 1) * PRIME_Y;
    int zPrimedBase = (zr - 1) * PRIME_Z;

    switch (state.cellular_distance_func)
    {
    case FNL_CELLULAR_DISTANCE_MANHATTAN:
    {
        for (int xi = xr - 1; xi <= xr + 1; xi++)
        {
            int yPrimed = yPrimedBase;

            for (int yi = yr - 1; yi <= yr + 1; yi++)
            {
                int zPrimed = zPrimedBase;

                for (int zi = zr - 1; zi <= zr + 1; zi++)
                {
                    int hash = _fnlHash3D(seed, xPrimed, yPrimed, zPrimed);
                    int idx = hash & (255 << 2);

                    float vecX = float(xi) - x + RAND_VECS_3D[idx] * cellularJitter;
                    float vecY = float(yi) - y + RAND_VECS_3D[idx | 1] * cellularJitter;
                    float vecZ = float(zi) - z + RAND_VECS_3D[idx | 2] * cellularJitter;

                    float newDistance = _fnlFastAbs(vecX) + _fnlFastAbs(vecY) + _fnlFastAbs(vecZ);

                    distance1 = _fnlFastMax(_fnlFastMin(distance1, newDistance), distance0);
                    if (newDistance < distance0)
                    {
                        distance0 = newDistance;
                        closestHash = hash;
                    }
                    zPrimed += PRIME_Z;
                }
                yPrimed += PRIME_Y;
            }
            xPrimed += PRIME_X;
        }
        break;
    }
    case FNL_CELLULAR_DISTANCE_HYBRID:
    {
        for (int xi = xr - 1; xi <= xr + 1; xi++)
        {
            int yPrimed = yPrimedBase;

            for (int yi = yr - 1; yi <= yr + 1; yi++)
            {
                int zPrimed = zPrimedBase;

                for (int zi = zr - 1; zi <= zr + 1; zi++)
                {
                    int hash = _fnlHash3D(seed, xPrimed, yPrimed, zPrimed);
                    int idx = hash & (255 << 2);

                    float vecX = float(xi) - x + RAND_VECS_3D[idx] * cellularJitter;
                    float vecY = float(yi) - y + RAND_VECS_3D[idx | 1] * cellularJitter;
                    float vecZ = float(zi) - z + RAND_VECS_3D[idx | 2] * cellularJitter;

                    float newDistance = (_fnlFastAbs(vecX) + _fnlFastAbs(vecY) + _fnlFastAbs(vecZ)) + (vecX * vecX + vecY * vecY + vecZ * vecZ);

                    distance1 = _fnlFastMax(_fnlFastMin(distance1, newDistance), distance0);
                    if (newDistance < distance0)
                    {
                        distance0 = newDistance;
                        closestHash = hash;
                    }
                    zPrimed += PRIME_Z;
                }
                yPrimed += PRIME_Y;
            }
            xPrimed += PRIME_X;
        }
        break;
    }
    case FNL_CELLULAR_DISTANCE_EUCLIDEAN:
    case FNL_CELLULAR_DISTANCE_EUCLIDEANSQ:
    default:
    {
        for (int xi = xr - 1; xi <= xr + 1; xi++)
        {
            int yPrimed = yPrimedBase;

            for (int yi = yr - 1; yi <= yr + 1; yi++)
            {
                int zPrimed = zPrimedBase;

                for (int zi = zr - 1; zi <= zr + 1; zi++)
                {
                    int hash = _fnlHash3D(seed, xPrimed, yPrimed, zPrimed);
                    int idx = hash & (255 << 2);

                    float vecX = float(xi) - x + RAND_VECS_3D[idx] * cellularJitter;
                    float vecY = float(yi) - y + RAND_VECS_3D[idx | 1] * cellularJitter;
                    float vecZ = float(zi) - z + RAND_VECS_3D[idx | 2] * cellularJitter;

                    float newDistance = vecX * vecX + vecY * vecY + vecZ * vecZ;

                    distance1 = _fnlFastMax(_fnlFastMin(distance1, newDistance), distance0);
                    if (newDistance < distance0)
                    {
                        distance0 = newDistance;
                        closestHash = hash;
                    }
                    zPrimed += PRIME_Z;
                }
                yPrimed += PRIME_Y;
            }
            xPrimed += PRIME_X;
        }
        break;
    }
    }

    if (state.cellular_distance_func == FNL_CELLULAR_DISTANCE_EUCLIDEAN && state.cellular_return_type >= FNL_CELLULAR_RETURN_TYPE_DISTANCE)
    {
        distance0 = _fnlFastSqrt(distance0);
        if (state.cellular_return_type >= FNL_CELLULAR_RETURN_TYPE_DISTANCE2)
		{
            distance1 = _fnlFastSqrt(distance1);
		}
    }

    switch (state.cellular_return_type)
    {
    case FNL_CELLULAR_RETURN_TYPE_CELLVALUE:
        return float(closestHash) * (1.f / 2147483648.f);
    case FNL_CELLULAR_RETURN_TYPE_DISTANCE:
        return distance0 - 1.f;
    case FNL_CELLULAR_RETURN_TYPE_DISTANCE2:
        return distance1 - 1.f;
    case FNL_CELLULAR_RETURN_TYPE_DISTANCE2ADD:
        return (distance1 + distance0) * 0.5f - 1.f;
    case FNL_CELLULAR_RETURN_TYPE_DISTANCE2SUB:
        return distance1 - distance0 - 1.f;
    case FNL_CELLULAR_RETURN_TYPE_DISTANCE2MUL:
        return distance1 * distance0 * 0.5f - 1.f;
    case FNL_CELLULAR_RETURN_TYPE_DISTANCE2DIV:
        return distance0 / distance1 - 1.f;
    default:
        return 0.f;
    }
}

// Perlin Noise
float _fnlSinglePerlin2D(int seed, FNLfloat x, FNLfloat y)
{
    int x0 = _fnlFastFloor(x);
    int y0 = _fnlFastFloor(y);

    float xd0 = x - float(x0);
    float yd0 = y - float(y0);
    float xd1 = xd0 - 1.f;
    float yd1 = yd0 - 1.f;

    float xs = _fnlInterpQuintic(xd0);
    float ys = _fnlInterpQuintic(yd0);

    x0 *= PRIME_X;
    y0 *= PRIME_Y;
    int x1 = x0 + PRIME_X;
    int y1 = y0 + PRIME_Y;

    float xf0 = _fnlLerp(_fnlGradCoord2D(seed, x0, y0, xd0, yd0), _fnlGradCoord2D(seed, x1, y0, xd1, yd0), xs);
    float xf1 = _fnlLerp(_fnlGradCoord2D(seed, x0, y1, xd0, yd1), _fnlGradCoord2D(seed, x1, y1, xd1, yd1), xs);

    return _fnlLerp(xf0, xf1, ys) * 1.4247691104677813;
}

float _fnlSinglePerlin3D(int seed, FNLfloat x, FNLfloat y, FNLfloat z)
{
    int x0 = _fnlFastFloor(x);
    int y0 = _fnlFastFloor(y);
    int z0 = _fnlFastFloor(z);

    float xd0 = x - float(x0);
    float yd0 = y - float(y0);
    float zd0 = z - float(z0);
    float xd1 = xd0 - 1.f;
    float yd1 = yd0 - 1.f;
    float zd1 = zd0 - 1.f;

    float xs = _fnlInterpQuintic(xd0);
    float ys = _fnlInterpQuintic(yd0);
    float zs = _fnlInterpQuintic(zd0);

    x0 *= PRIME_X;
    y0 *= PRIME_Y;
    z0 *= PRIME_Z;
    int x1 = x0 + PRIME_X;
    int y1 = y0 + PRIME_Y;
    int z1 = z0 + PRIME_Z;

    float xf00 = _fnlLerp(_fnlGradCoord3D(seed, x0, y0, z0, xd0, yd0, zd0), _fnlGradCoord3D(seed, x1, y0, z0, xd1, yd0, zd0), xs);
    float xf10 = _fnlLerp(_fnlGradCoord3D(seed, x0, y1, z0, xd0, yd1, zd0), _fnlGradCoord3D(seed, x1, y1, z0, xd1, yd1, zd0), xs);
    float xf01 = _fnlLerp(_fnlGradCoord3D(seed, x0, y0, z1, xd0, yd0, zd1), _fnlGradCoord3D(seed, x1, y0, z1, xd1, yd0, zd1), xs);
    float xf11 = _fnlLerp(_fnlGradCoord3D(seed, x0, y1, z1, xd0, yd1, zd1), _fnlGradCoord3D(seed, x1, y1, z1, xd1, yd1, zd1), xs);

    float yf0 = _fnlLerp(xf00, xf10, ys);
    float yf1 = _fnlLerp(xf01, xf11, ys);

    return _fnlLerp(yf0, yf1, zs) * 0.964921414852142333984375;
}


// Value Cubic
float _fnlSingleValueCubic2D(int seed, FNLfloat x, FNLfloat y)
{
    int x1 = _fnlFastFloor(x);
    int y1 = _fnlFastFloor(y);

    float xs = x - float(x1);
    float ys = y - float(y1);

    x1 *= PRIME_X;
    y1 *= PRIME_Y;

    int x0 = x1 - PRIME_X;
    int y0 = y1 - PRIME_Y;
    int x2 = x1 + PRIME_X;
    int y2 = y1 + PRIME_Y;
    int x3 = x1 + PRIME_X * 2;
    int y3 = y1 + PRIME_Y * 2;

    return _fnlCubicLerp(_fnlCubicLerp(_fnlValCoord2D(seed, x0, y0), _fnlValCoord2D(seed, x1, y0), _fnlValCoord2D(seed, x2, y0), _fnlValCoord2D(seed, x3, y0),xs),
        _fnlCubicLerp(_fnlValCoord2D(seed, x0, y1), _fnlValCoord2D(seed, x1, y1), _fnlValCoord2D(seed, x2, y1), _fnlValCoord2D(seed, x3, y1),
                      xs),
        _fnlCubicLerp(_fnlValCoord2D(seed, x0, y2), _fnlValCoord2D(seed, x1, y2), _fnlValCoord2D(seed, x2, y2), _fnlValCoord2D(seed, x3, y2),
                      xs),
        _fnlCubicLerp(_fnlValCoord2D(seed, x0, y3), _fnlValCoord2D(seed, x1, y3), _fnlValCoord2D(seed, x2, y3), _fnlValCoord2D(seed, x3, y3),
                      xs),
        ys) * (1.f / (1.5f * 1.5f));
}

float _fnlSingleValueCubic3D(int seed, FNLfloat x, FNLfloat y, FNLfloat z)
{
    int x1 = _fnlFastFloor(x);
    int y1 = _fnlFastFloor(y);
    int z1 = _fnlFastFloor(z);

    float xs = x - float(x1);
    float ys = y - float(y1);
    float zs = z - float(z1);

    x1 *= PRIME_X;
    y1 *= PRIME_Y;
    z1 *= PRIME_Z;

    int x0 = x1 - PRIME_X;
    int y0 = y1 - PRIME_Y;
    int z0 = z1 - PRIME_Z;
    int x2 = x1 + PRIME_X;
    int y2 = y1 + PRIME_Y;
    int z2 = z1 + PRIME_Z;
    int x3 = x1 + PRIME_X * 2;
    int y3 = y1 + PRIME_Y * 2;
    int z3 = z1 + PRIME_Z * 2;

    return _fnlCubicLerp(
        _fnlCubicLerp(
            _fnlCubicLerp(_fnlValCoord3D(seed, x0, y0, z0), _fnlValCoord3D(seed, x1, y0, z0), _fnlValCoord3D(seed, x2, y0, z0), _fnlValCoord3D(seed, x3, y0, z0), xs),
            _fnlCubicLerp(_fnlValCoord3D(seed, x0, y1, z0), _fnlValCoord3D(seed, x1, y1, z0), _fnlValCoord3D(seed, x2, y1, z0), _fnlValCoord3D(seed, x3, y1, z0), xs),
            _fnlCubicLerp(_fnlValCoord3D(seed, x0, y2, z0), _fnlValCoord3D(seed, x1, y2, z0), _fnlValCoord3D(seed, x2, y2, z0), _fnlValCoord3D(seed, x3, y2, z0), xs),
            _fnlCubicLerp(_fnlValCoord3D(seed, x0, y3, z0), _fnlValCoord3D(seed, x1, y3, z0), _fnlValCoord3D(seed, x2, y3, z0), _fnlValCoord3D(seed, x3, y3, z0), xs),
            ys),
        _fnlCubicLerp(
            _fnlCubicLerp(_fnlValCoord3D(seed, x0, y0, z1), _fnlValCoord3D(seed, x1, y0, z1), _fnlValCoord3D(seed, x2, y0, z1), _fnlValCoord3D(seed, x3, y0, z1), xs),
            _fnlCubicLerp(_fnlValCoord3D(seed, x0, y1, z1), _fnlValCoord3D(seed, x1, y1, z1), _fnlValCoord3D(seed, x2, y1, z1), _fnlValCoord3D(seed, x3, y1, z1), xs),
            _fnlCubicLerp(_fnlValCoord3D(seed, x0, y2, z1), _fnlValCoord3D(seed, x1, y2, z1), _fnlValCoord3D(seed, x2, y2, z1), _fnlValCoord3D(seed, x3, y2, z1), xs),
            _fnlCubicLerp(_fnlValCoord3D(seed, x0, y3, z1), _fnlValCoord3D(seed, x1, y3, z1), _fnlValCoord3D(seed, x2, y3, z1), _fnlValCoord3D(seed, x3, y3, z1), xs),
            ys),
        _fnlCubicLerp(
            _fnlCubicLerp(_fnlValCoord3D(seed, x0, y0, z2), _fnlValCoord3D(seed, x1, y0, z2), _fnlValCoord3D(seed, x2, y0, z2), _fnlValCoord3D(seed, x3, y0, z2), xs),
            _fnlCubicLerp(_fnlValCoord3D(seed, x0, y1, z2), _fnlValCoord3D(seed, x1, y1, z2), _fnlValCoord3D(seed, x2, y1, z2), _fnlValCoord3D(seed, x3, y1, z2), xs),
            _fnlCubicLerp(_fnlValCoord3D(seed, x0, y2, z2), _fnlValCoord3D(seed, x1, y2, z2), _fnlValCoord3D(seed, x2, y2, z2), _fnlValCoord3D(seed, x3, y2, z2), xs),
            _fnlCubicLerp(_fnlValCoord3D(seed, x0, y3, z2), _fnlValCoord3D(seed, x1, y3, z2), _fnlValCoord3D(seed, x2, y3, z2), _fnlValCoord3D(seed, x3, y3, z2), xs),
            ys),
        _fnlCubicLerp(
            _fnlCubicLerp(_fnlValCoord3D(seed, x0, y0, z3), _fnlValCoord3D(seed, x1, y0, z3), _fnlValCoord3D(seed, x2, y0, z3), _fnlValCoord3D(seed, x3, y0, z3), xs),
            _fnlCubicLerp(_fnlValCoord3D(seed, x0, y1, z3), _fnlValCoord3D(seed, x1, y1, z3), _fnlValCoord3D(seed, x2, y1, z3), _fnlValCoord3D(seed, x3, y1, z3), xs),
            _fnlCubicLerp(_fnlValCoord3D(seed, x0, y2, z3), _fnlValCoord3D(seed, x1, y2, z3), _fnlValCoord3D(seed, x2, y2, z3), _fnlValCoord3D(seed, x3, y2, z3), xs),
            _fnlCubicLerp(_fnlValCoord3D(seed, x0, y3, z3), _fnlValCoord3D(seed, x1, y3, z3), _fnlValCoord3D(seed, x2, y3, z3), _fnlValCoord3D(seed, x3, y3, z3), xs),
            ys),
        zs) * (1.f / 1.5f * 1.5f * 1.5f);
}


// Value noise
float _fnlSingleValue2D(int seed, FNLfloat x, FNLfloat y)
{
    int x0 = _fnlFastFloor(x);
    int y0 = _fnlFastFloor(y);

    float xs = _fnlInterpHermite(x - float(x0));
    float ys = _fnlInterpHermite(y - float(y0));

    x0 *= PRIME_X;
    y0 *= PRIME_Y;
    int x1 = x0 + PRIME_X;
    int y1 = y0 + PRIME_Y;

    float xf0 = _fnlLerp(_fnlValCoord2D(seed, x0, y0), _fnlValCoord2D(seed, x1, y0), xs);
    float xf1 = _fnlLerp(_fnlValCoord2D(seed, x0, y1), _fnlValCoord2D(seed, x1, y1), xs);

    return _fnlLerp(xf0, xf1, ys);
}

float _fnlSingleValue3D(int seed, FNLfloat x, FNLfloat y, FNLfloat z)
{
    int x0 = _fnlFastFloor(x);
    int y0 = _fnlFastFloor(y);
    int z0 = _fnlFastFloor(z);

    float xs = _fnlInterpHermite(x - float(x0));
    float ys = _fnlInterpHermite(y - float(y0));
    float zs = _fnlInterpHermite(z - float(z0));

    x0 *= PRIME_X;
    y0 *= PRIME_Y;
    z0 *= PRIME_Z;
    int x1 = x0 + PRIME_X;
    int y1 = y0 + PRIME_Y;
    int z1 = z0 + PRIME_Z;

    float xf00 = _fnlLerp(_fnlValCoord3D(seed, x0, y0, z0), _fnlValCoord3D(seed, x1, y0, z0), xs);
    float xf10 = _fnlLerp(_fnlValCoord3D(seed, x0, y1, z0), _fnlValCoord3D(seed, x1, y1, z0), xs);
    float xf01 = _fnlLerp(_fnlValCoord3D(seed, x0, y0, z1), _fnlValCoord3D(seed, x1, y0, z1), xs);
    float xf11 = _fnlLerp(_fnlValCoord3D(seed, x0, y1, z1), _fnlValCoord3D(seed, x1, y1, z1), xs);

    float yf0 = _fnlLerp(xf00, xf10, ys);
    float yf1 = _fnlLerp(xf01, xf11, ys);

    return _fnlLerp(yf0, yf1, zs);
}

// Generic Noise Gen
float _fnlGenNoiseSingle2D(fnl_state state, int seed, FNLfloat x, FNLfloat y)
{
    switch (state.noise_type)
    {
        case FNL_NOISE_OPENSIMPLEX2:
            return _fnlSingleSimplex2D(seed, x, y);
        case FNL_NOISE_OPENSIMPLEX2S:
            return _fnlSingleOpenSimplex2S2D(seed, x, y);
        case FNL_NOISE_CELLULAR:
            return _fnlSingleCellular2D(state, seed, x, y);
        case FNL_NOISE_PERLIN:
            return _fnlSinglePerlin2D(seed, x, y);
        case FNL_NOISE_VALUE_CUBIC:
            return _fnlSingleValueCubic2D(seed, x, y);
        case FNL_NOISE_VALUE:
            return _fnlSingleValue2D(seed, x, y);
        default:
            return 0.f;
    }
}

float _fnlGenNoiseSingle3D(fnl_state state, int seed, FNLfloat x, FNLfloat y, FNLfloat z)
{
    switch (state.noise_type)
    {
        case FNL_NOISE_OPENSIMPLEX2:
            return _fnlSingleOpenSimplex23D(seed, x, y, z);
        case FNL_NOISE_OPENSIMPLEX2S:
            return _fnlSingleOpenSimplex2S3D(seed, x, y, z);
        case FNL_NOISE_CELLULAR:
            return _fnlSingleCellular3D(state, seed, x, y, z);
        case FNL_NOISE_PERLIN:
            return _fnlSinglePerlin3D(seed, x, y, z);
        case FNL_NOISE_VALUE_CUBIC:
            return _fnlSingleValueCubic3D(seed, x, y, z);
        case FNL_NOISE_VALUE:
            return _fnlSingleValue3D(seed, x, y, z);
        default:
            return 0.f;
    }
}

// Fractal FBm
float _fnlGenFractalFBM2D(fnl_state state, FNLfloat x, FNLfloat y)
{
    int seed = 
#undef seed
	state.seed;
#define seed _fnl_lib__seed
    float sum = 0.f;
    float amp = _fnlCalculateFractalBounding(state);

    for (int i = 0; i < state.octaves; i++)
    {
        float noise = _fnlGenNoiseSingle2D(state, seed++, x, y);
        sum += noise * amp;
        amp *= _fnlLerp(1.f, _fnlFastMin(noise + 1.f, 2.f) * 0.5f, state.weighted_strength);

        x *= state.lacunarity;
        y *= state.lacunarity;
        amp *= state.gain;
    }

    return sum;
}

float _fnlGenFractalFBM3D(fnl_state state, FNLfloat x, FNLfloat y, FNLfloat z)
{
    int seed =
#undef seed
	state.seed;
#define seed _fnl_lib__seed
    float sum = 0.f;
    float amp = _fnlCalculateFractalBounding(state);

    for (int i = 0; i < state.octaves; i++)
    {
        float noise = _fnlGenNoiseSingle3D(state, seed++, x, y, z);
        sum += noise * amp;
        amp *= _fnlLerp(1.f, (noise + 1.f) * 0.5f, state.weighted_strength);

        x *= state.lacunarity;
        y *= state.lacunarity;
        z *= state.lacunarity;
        amp *= state.gain;
    }

    return sum;
}

// Fractal Ridged
float _fnlGenFractalRidged2D(fnl_state state, FNLfloat x, FNLfloat y)
{
    int seed =
#undef seed
	state.seed;
#define seed _fnl_lib__seed
    float sum = 0.f;
    float amp = _fnlCalculateFractalBounding(state);

    for (int i = 0; i < state.octaves; i++)
    {
        float noise = _fnlFastAbs(_fnlGenNoiseSingle2D(state, seed++, x, y));
        sum += (noise * -2.f + 1.f) * amp;
        amp *= _fnlLerp(1.f, 1.f - noise, state.weighted_strength);

        x *= state.lacunarity;
        y *= state.lacunarity;
        amp *= state.gain;
    }

    return sum;
}


float _fnlGenFractalRidged3D(fnl_state state, FNLfloat x, FNLfloat y, FNLfloat z)
{
    int seed =
#undef seed
	state.seed;
#define seed _fnl_lib__seed
    float sum = 0.f;
    float amp = _fnlCalculateFractalBounding(state);

    for (int i = 0; i < state.octaves; i++)
    {
        float noise = _fnlFastAbs(_fnlGenNoiseSingle3D(state, seed++, x, y, z));
        sum += (noise * -2.f + 1.f) * amp;
        amp *= _fnlLerp(1.f, 1.f - noise, state.weighted_strength);

        x *= state.lacunarity;
        y *= state.lacunarity;
        z *= state.lacunarity;
        amp *= state.gain;
    }

    return sum;
}

// Fractal PingPong
float _fnlGenFractalPingPong2D(fnl_state state, FNLfloat x, FNLfloat y)
{
    int seed = 
#undef seed
	state.seed;
#define seed _fnl_lib__seed
    float sum = 0.f;
    float amp = _fnlCalculateFractalBounding(state);

    for (int i = 0; i < state.octaves; i++)
    {
        float noise = _fnlPingPong((_fnlGenNoiseSingle2D(state, seed++, x, y) + 1.f) * state.ping_pong_strength);
        sum += (noise - 0.5f) * 2.f * amp;
        amp *= _fnlLerp(1.f, noise, state.weighted_strength);

        x *= state.lacunarity;
        y *= state.lacunarity;
        amp *= state.gain;
    }

    return sum;
}

float _fnlGenFractalPingPong3D(fnl_state state, FNLfloat x, FNLfloat y, FNLfloat z)
{
    int seed = 
#undef seed
	state.seed;
#define seed _fnl_lib__seed
    float sum = 0.f;
    float amp = _fnlCalculateFractalBounding(state);

    for (int i = 0; i < state.octaves; i++)
    {
        float noise = _fnlPingPong((_fnlGenNoiseSingle3D(state, seed++, x, y, z) + 1.f) * state.ping_pong_strength);
        sum += (noise - 0.5f) * 2.f * amp;
        amp *= _fnlLerp(1.f, noise, state.weighted_strength);

        x *= state.lacunarity;
        y *= state.lacunarity;
        z *= state.lacunarity;
        amp *= state.gain;
    }

    return sum;
}


#define frequency _fnl_lib__frequency
// Domain Warp Simplex/OpenSimplex2
void _fnlSingleDomainWarpSimplexGradient(int seed, float warpAmp, float frequency, FNLfloat x, FNLfloat y, inout FNLfloat xr, inout FNLfloat yr, bool outGradOnly)
{
    const float SQRT3 = 1.7320508075688772935274463415059;
    const float G2 = (3.f - SQRT3) / 6.f;

    x *= frequency;
    y *= frequency;

    // --- Skew moved to TransformNoiseCoordinate method ---
    // const FNLfloat F2 = 0.5f * (SQRT3 - 1);
    // FNLfloat s = (x + y) * F2;
    // x += s; y += s;


    int i = _fnlFastFloor(x);
    int j = _fnlFastFloor(y);
    float xi = x - float(i);
    float yi = y - float(j);

    float t = (xi + yi) * G2;
    float x0 = xi - t;
    float y0 = yi - t;

    i *= PRIME_X;
    j *= PRIME_Y;

    float vx, vy;
    vx = vy = 0.f;

    float a = 0.5f - x0 * x0 - y0 * y0;
    if (a > 0.f)
    {
        float aaaa = (a * a) * (a * a);
        float xo, yo;
        if (outGradOnly)
		{
            _fnlGradCoordOut2D(seed, i, j, xo, yo);
		}
        else
        {
			_fnlGradCoordDual2D(seed, i, j, x0, y0, xo, yo);
		}
        vx += aaaa * xo;
        vy += aaaa * yo;
    }

    float c = (2.f * (1.f - 2.f * G2) * (1.f / G2 - 2.f)) * t + ((-2.f * (1.f - 2.f * G2) * (1.f - 2.f * G2)) + a);
    if (c > 0.f)
    {
        float x2 = x0 + (2.f * G2 - 1.f);
        float y2 = y0 + (2.f * G2 - 1.f);
        float cccc = (c * c) * (c * c);
        float xo, yo;
        if (outGradOnly)
		{
            _fnlGradCoordOut2D(seed, i + PRIME_X, j + PRIME_Y, xo, yo);
		}
        else
		{
            _fnlGradCoordDual2D(seed, i + PRIME_X, j + PRIME_Y, x2, y2, xo, yo);
		}
        vx += cccc * xo;
        vy += cccc * yo;
    }

    if (y0 > x0)
    {
        float x1 = x0 + G2;
        float y1 = y0 + (G2 - 1.f);
        float b = 0.5f - x1 * x1 - y1 * y1;
        if (b > 0.f)
        {
            float bbbb = (b * b) * (b * b);
            float xo, yo;
            if (outGradOnly)
			{
                _fnlGradCoordOut2D(seed, i, j + PRIME_Y, xo, yo);
			}
            else
			{
                _fnlGradCoordDual2D(seed, i, j + PRIME_Y, x1, y1, xo, yo);
			}
            vx += bbbb * xo;
            vy += bbbb * yo;
        }
    }
    else
    {
        float x1 = x0 + (G2 - 1.f);
        float y1 = y0 + G2;
        float b = 0.5f - x1 * x1 - y1 * y1;
        if (b > 0.f)
        {
            float bbbb = (b * b) * (b * b);
            float xo, yo;
            if (outGradOnly)
			{
                _fnlGradCoordOut2D(seed, i + PRIME_X, j, xo, yo);
			}
            else
            {
				_fnlGradCoordDual2D(seed, i + PRIME_X, j, x1, y1, xo, yo);
			}
            vx += bbbb * xo;
            vy += bbbb * yo;
        }
    }

    xr += vx * warpAmp;
    yr += vy * warpAmp;
}
void _fnlSingleDomainWarpOpenSimplex2Gradient(int seed, float warpAmp, float frequency, FNLfloat x, FNLfloat y, FNLfloat z, inout FNLfloat xr, inout FNLfloat yr, inout FNLfloat zr, bool outGradOnly)
{
    x *= frequency;
    y *= frequency;
    z *= frequency;

    // --- Rotation moved to TransformDomainWarpCoordinate method ---
    // const FNLfloat R3 = (FNLfloat)(2.f / 3.f);
    // FNLfloat r = (x + y + z) * R3; // Rotation, not skew
    // x = r - x; y = r - y; z = r - z;


    int i = _fnlFastRound(x);
    int j = _fnlFastRound(y);
    int k = _fnlFastRound(z);
    float x0 = x - float(i);
    float y0 = y - float(j);
    float z0 = z - float(k);

    int xNSign = int(-x0 - 1.f) | 1;
    int yNSign = int(-y0 - 1.f) | 1;
    int zNSign = int(-z0 - 1.f) | 1;

    float ax0 = float(xNSign) * -x0;
    float ay0 = float(yNSign) * -y0;
    float az0 = float(zNSign) * -z0;

    i *= PRIME_X;
    j *= PRIME_Y;
    k *= PRIME_Z;

    float vx, vy, vz;
    vx = vy = vz = 0.f;

    float a = (0.6f - x0 * x0) - (y0 * y0 + z0 * z0);
    for (int l = 0; l < 2; l++)
    {
        if (a > 0.f)
        {
            float aaaa = (a * a) * (a * a);
            float xo, yo, zo;
            if (outGradOnly)
			{
                _fnlGradCoordOut3D(seed, i, j, k, xo, yo, zo);
			}
            else
			{
                _fnlGradCoordDual3D(seed, i, j, k, x0, y0, z0, xo, yo, zo);
			}
            vx += aaaa * xo;
            vy += aaaa * yo;
            vz += aaaa * zo;
        }

        float b = a + 1.f;
        int i1 = i;
        int j1 = j;
        int k1 = k;
        float x1 = x0;
        float y1 = y0;
        float z1 = z0;
        if (ax0 >= ay0 && ax0 >= az0)
        {
            x1 += float(xNSign);
            b -= float(xNSign) * 2.f * x1;
            i1 -= xNSign * PRIME_X;
        }
        else if (ay0 > ax0 && ay0 >= az0)
        {
            y1 += float(yNSign);
            b -= float(yNSign) * 2.f * y1;
            j1 -= yNSign * PRIME_Y;
        }
        else
        {
            z1 += float(zNSign);
            b -= float(zNSign) * 2.f * z1;
            k1 -= zNSign * PRIME_Z;
        }

        if (b > 0.f)
        {
            float bbbb = (b * b) * (b * b);
            float xo, yo, zo;
            if (outGradOnly)
			{
                _fnlGradCoordOut3D(seed, i1, j1, k1, xo, yo, zo);
			}
            else
			{
                _fnlGradCoordDual3D(seed, i1, j1, k1, x1, y1, z1, xo, yo, zo);
			}
            vx += bbbb * xo;
            vy += bbbb * yo;
            vz += bbbb * zo;
        }

        if (l == 1) break;

        ax0 = 0.5f - ax0;
        ay0 = 0.5f - ay0;
        az0 = 0.5f - az0;

        x0 = float(xNSign) * ax0;
        y0 = float(yNSign) * ay0;
        z0 = float(zNSign) * az0;

        a += (0.75f - ax0) - (ay0 + az0);

        i += (xNSign >> 1) & PRIME_X;
        j += (yNSign >> 1) & PRIME_Y;
        k += (zNSign >> 1) & PRIME_Z;

        xNSign = -xNSign;
        yNSign = -yNSign;
        zNSign = -zNSign;

        seed += 1293373;
    }

    xr += vx * warpAmp;
    yr += vy * warpAmp;
    zr += vz * warpAmp;
}


// Domain Warp Basic Grid
void _fnlSingleDomainWarpBasicGrid2D(int seed, float warpAmp, float frequency, FNLfloat x, FNLfloat y, inout FNLfloat xp, inout FNLfloat yp)
{
    FNLfloat xf = x * frequency;
    FNLfloat yf = y * frequency;

    int x0 = _fnlFastFloor(xf);
    int y0 = _fnlFastFloor(yf);

    float xs = _fnlInterpHermite(xf - float(x0));
    float ys = _fnlInterpHermite(yf - float(y0));

    x0 *= PRIME_X;
    y0 *= PRIME_Y;
    int x1 = x0 + PRIME_X;
    int y1 = y0 + PRIME_Y;

    int idx0 = _fnlHash2D(seed, x0, y0) & (255 << 1);
    int idx1 = _fnlHash2D(seed, x1, y0) & (255 << 1);

    float lx0x = _fnlLerp(RAND_VECS_2D[idx0], RAND_VECS_2D[idx1], xs);
    float ly0x = _fnlLerp(RAND_VECS_2D[idx0 | 1], RAND_VECS_2D[idx1 | 1], xs);

    idx0 = _fnlHash2D(seed, x0, y1) & (255 << 1);
    idx1 = _fnlHash2D(seed, x1, y1) & (255 << 1);

    float lx1x = _fnlLerp(RAND_VECS_2D[idx0], RAND_VECS_2D[idx1], xs);
    float ly1x = _fnlLerp(RAND_VECS_2D[idx0 | 1], RAND_VECS_2D[idx1 | 1], xs);

    xp += _fnlLerp(lx0x, lx1x, ys) * warpAmp;
    yp += _fnlLerp(ly0x, ly1x, ys) * warpAmp;
}

void _fnlSingleDomainWarpBasicGrid3D(int seed, float warpAmp, float frequency, FNLfloat x, FNLfloat y, FNLfloat z, inout FNLfloat xp, inout FNLfloat yp, inout FNLfloat zp)
{
    FNLfloat xf = x * frequency;
    FNLfloat yf = y * frequency;
    FNLfloat zf = z * frequency;

    int x0 = _fnlFastFloor(xf);
    int y0 = _fnlFastFloor(yf);
    int z0 = _fnlFastFloor(zf);

    float xs = _fnlInterpHermite(xf - float(x0));
    float ys = _fnlInterpHermite(yf - float(y0));
    float zs = _fnlInterpHermite(zf - float(z0));

    x0 *= PRIME_X;
    y0 *= PRIME_Y;
    z0 *= PRIME_Z;
    int x1 = x0 + PRIME_X;
    int y1 = y0 + PRIME_Y;
    int z1 = z0 + PRIME_Z;

    int idx0 = _fnlHash3D(seed, x0, y0, z0) & (255 << 2);
    int idx1 = _fnlHash3D(seed, x1, y0, z0) & (255 << 2);

    float lx0x = _fnlLerp(RAND_VECS_3D[idx0], RAND_VECS_3D[idx1], xs);
    float ly0x = _fnlLerp(RAND_VECS_3D[idx0 | 1], RAND_VECS_3D[idx1 | 1], xs);
    float lz0x = _fnlLerp(RAND_VECS_3D[idx0 | 2], RAND_VECS_3D[idx1 | 2], xs);

    idx0 = _fnlHash3D(seed, x0, y1, z0) & (255 << 2);
    idx1 = _fnlHash3D(seed, x1, y1, z0) & (255 << 2);

    float lx1x = _fnlLerp(RAND_VECS_3D[idx0], RAND_VECS_3D[idx1], xs);
    float ly1x = _fnlLerp(RAND_VECS_3D[idx0 | 1], RAND_VECS_3D[idx1 | 1], xs);
    float lz1x = _fnlLerp(RAND_VECS_3D[idx0 | 2], RAND_VECS_3D[idx1 | 2], xs);

    float lx0y = _fnlLerp(lx0x, lx1x, ys);
    float ly0y = _fnlLerp(ly0x, ly1x, ys);
    float lz0y = _fnlLerp(lz0x, lz1x, ys);

    idx0 = _fnlHash3D(seed, x0, y0, z1) & (255 << 2);
    idx1 = _fnlHash3D(seed, x1, y0, z1) & (255 << 2);

    lx0x = _fnlLerp(RAND_VECS_3D[idx0], RAND_VECS_3D[idx1], xs);
    ly0x = _fnlLerp(RAND_VECS_3D[idx0 | 1], RAND_VECS_3D[idx1 | 1], xs);
    lz0x = _fnlLerp(RAND_VECS_3D[idx0 | 2], RAND_VECS_3D[idx1 | 2], xs);

    idx0 = _fnlHash3D(seed, x0, y1, z1) & (255 << 2);
    idx1 = _fnlHash3D(seed, x1, y1, z1) & (255 << 2);

    lx1x = _fnlLerp(RAND_VECS_3D[idx0], RAND_VECS_3D[idx1], xs);
    ly1x = _fnlLerp(RAND_VECS_3D[idx0 | 1], RAND_VECS_3D[idx1 | 1], xs);
    lz1x = _fnlLerp(RAND_VECS_3D[idx0 | 2], RAND_VECS_3D[idx1 | 2], xs);

    xp += _fnlLerp(lx0y, _fnlLerp(lx0x, lx1x, ys), zs) * warpAmp;
    yp += _fnlLerp(ly0y, _fnlLerp(ly0x, ly1x, ys), zs) * warpAmp;
    zp += _fnlLerp(lz0y, _fnlLerp(lz0x, lz1x, ys), zs) * warpAmp;
}
#undef frequency
// Domain Warp
void _fnlDoSingleDomainWarp2D(fnl_state state, int seed, float amp, float freq, FNLfloat x, FNLfloat y, inout FNLfloat xp, inout FNLfloat yp)
{
    switch (state.domain_warp_type)
    {
    case FNL_DOMAIN_WARP_OPENSIMPLEX2:
        _fnlSingleDomainWarpSimplexGradient(seed, amp * 38.283687591552734375, freq, x, y, xp, yp, false);
        break;
    case FNL_DOMAIN_WARP_OPENSIMPLEX2_REDUCED:
        _fnlSingleDomainWarpSimplexGradient(seed, amp * 16.f, freq, x, y, xp, yp, true);
        break;
    case FNL_DOMAIN_WARP_BASICGRID:
        _fnlSingleDomainWarpBasicGrid2D(seed, amp, freq, x, y, xp, yp);
        break;
    }
}

void _fnlDoSingleDomainWarp3D(fnl_state state, int seed, float amp, float freq, FNLfloat x, FNLfloat y, FNLfloat z, inout FNLfloat xp, inout FNLfloat yp, inout FNLfloat zp)
{
    switch (state.domain_warp_type)
    {
    case FNL_DOMAIN_WARP_OPENSIMPLEX2:
        _fnlSingleDomainWarpOpenSimplex2Gradient(seed, amp * 32.69428253173828125, freq, x, y, z, xp, yp, zp, false);
        break;
    case FNL_DOMAIN_WARP_OPENSIMPLEX2_REDUCED:
        _fnlSingleDomainWarpOpenSimplex2Gradient(seed, amp * 7.71604938271605, freq, x, y, z, xp, yp, zp, true);
        break;
    case FNL_DOMAIN_WARP_BASICGRID:
        _fnlSingleDomainWarpBasicGrid3D(seed, amp, freq, x, y, z, xp, yp, zp);
        break;
    }
}

// Domain Warp Single Wrapper
void _fnlDomainWarpSingle2D(fnl_state state, inout FNLfloat x, inout FNLfloat y)
{
    int seed = 
#undef seed
	state.seed;
#define seed _fnl_lib__seed
    float amp = state.domain_warp_amp * _fnlCalculateFractalBounding(state);
    float freq = 
	state.frequency;

    FNLfloat xs = x;
    FNLfloat ys = y;
    _fnlTransformDomainWarpCoordinate2D(state, xs, ys);

    _fnlDoSingleDomainWarp2D(state, seed, amp, freq, xs, ys, x, y);
}

void _fnlDomainWarpSingle3D(fnl_state state, inout FNLfloat x, inout FNLfloat y, inout FNLfloat z)
{
    int seed = 
#undef seed
	state.seed;
#define seed _fnl_lib__seed
    float amp = state.domain_warp_amp * _fnlCalculateFractalBounding(state);
    float freq = state.frequency;

    FNLfloat xs = x;
    FNLfloat ys = y;
    FNLfloat zs = z;
    _fnlTransformDomainWarpCoordinate3D(state, xs, ys, zs);

    _fnlDoSingleDomainWarp3D(state, seed, amp, freq, xs, ys, zs, x, y, z);
}

// Domain Warp Fractal Progressive
void _fnlDomainWarpFractalProgressive2D(fnl_state state, inout FNLfloat x, inout FNLfloat y)
{
    int seed = 
#undef seed
	state.seed;
#define seed _fnl_lib__seed
    float amp = state.domain_warp_amp * _fnlCalculateFractalBounding(state);
    float freq = state.frequency;

    for (int i = 0; i < state.octaves; i++)
    {
        FNLfloat xs = x;
        FNLfloat ys = y;
        _fnlTransformDomainWarpCoordinate2D(state, xs, ys);

        _fnlDoSingleDomainWarp2D(state, seed, amp, freq, xs, ys, x, y);

        seed++;
        amp *= state.gain;
        freq *= state.lacunarity;
    }
}

void _fnlDomainWarpFractalProgressive3D(fnl_state state, inout FNLfloat x, inout FNLfloat y, inout FNLfloat z)
{
    int seed = 
#undef seed
	state.seed;
#define seed _fnl_lib__seed
    float amp = state.domain_warp_amp * _fnlCalculateFractalBounding(state);
    float freq = state.frequency;

    for (int i = 0; i < state.octaves; i++)
    {
        FNLfloat xs = x;
        FNLfloat ys = y;
        FNLfloat zs = z;
        _fnlTransformDomainWarpCoordinate3D(state, xs, ys, zs);

        _fnlDoSingleDomainWarp3D(state, seed, amp, freq, xs, ys, zs, x, y, z);

        seed++;
        amp *= state.gain;
        freq *= state.lacunarity;
    }
}

// Domain Warp Fractal Independent
void _fnlDomainWarpFractalIndependent2D(fnl_state state, inout FNLfloat x, inout FNLfloat y)
{
    FNLfloat xs = x;
    FNLfloat ys = y;
    _fnlTransformDomainWarpCoordinate2D(state, xs, ys);

    int seed = 
#undef seed
	state.seed;
#define seed _fnl_lib__seed
    float amp = state.domain_warp_amp * _fnlCalculateFractalBounding(state);
    float freq = state.frequency;

    for (int i = 0; i < state.octaves; i++)
    {
        _fnlDoSingleDomainWarp2D(state, seed, amp, freq, xs, ys, x, y);

        seed++;
        amp *= state.gain;
        freq *= state.lacunarity;
    }
}

void _fnlDomainWarpFractalIndependent3D(fnl_state state, inout FNLfloat x, inout FNLfloat y, inout FNLfloat z)
{
    FNLfloat xs = x;
    FNLfloat ys = y;
    FNLfloat zs = z;
    _fnlTransformDomainWarpCoordinate3D(state, xs, ys, zs);

    int seed = 
#undef seed
	state.seed;
#define seed _fnl_lib__seed
    float amp = state.domain_warp_amp * _fnlCalculateFractalBounding(state);
    float freq = state.frequency;

    for (int i = 0; i < state.octaves; i++)
    {
        _fnlDoSingleDomainWarp3D(state, seed, amp, freq, xs, ys, zs, x, y, z);

        seed++;
        amp *= state.gain;
        freq *= state.lacunarity;
    }
}

//region CleanUpProtection
#undef a
#undef b
#undef c
#undef d
#undef t
#undef amp
#undef ampFractal
#undef xPrimed
#undef yPrimed
#undef zPrimed
#undef hash
#undef xo
#undef yo
#undef zo
#undef xg
#undef yg
#undef zg
#undef xd
#undef yd
#undef zd
#undef xgo
#undef ygo
#undef zgo
#undef index1
#undef index2
#undef value
#undef xy
#undef xz
#undef SQRT3
#undef F2
#undef s2
#undef r
#undef R3
#undef G2
#undef i
#undef j
#undef k
#undef i1
#undef j1
#undef k1
#undef l
#undef xi
#undef yi
#undef zi
#undef xs
#undef ys
#undef zs
#undef x0
#undef y0
#undef z0
#undef x1
#undef y1
#undef z1
#undef x2
#undef y2
#undef z2
#undef x3
#undef y3
#undef z3
#undef x4
#undef y4
#undef z4
#undef x5
#undef y5
#undef z5
#undef x6
#undef y6
#undef z6
#undef x7
#undef y7
#undef z7
#undef x8
#undef y8
#undef z8
#undef x9
#undef y9
#undef z9
#undef xA
#undef yA
#undef zA
#undef xB
#undef yB
#undef zB
#undef xC
#undef yC
#undef zC
#undef xD
#undef yD
#undef zD
#undef n0
#undef n1
#undef n2
#undef xNSign
#undef yNSign
#undef zNSign
#undef ax0
#undef ay0
#undef az0
#undef t2
#undef t3
#undef a0
#undef a1
#undef a2
#undef a3
#undef a4
#undef a5
#undef a6
#undef a7
#undef a8
#undef a9
#undef aA
#undef aB
#undef aC
#undef aD
#undef aMask
#undef bMask
#undef cMask
#undef di2
#undef ndj2
#undef ndi3
#undef dj3
#undef seed2
#undef xNMask
#undef yNMask
#undef zNMask
#undef xAFlipMask0
#undef yAFlipMask0
#undef zAFlipMask0
#undef xAFlipMask1
#undef yAFlipMask1
#undef zAFlipMask1
#undef skip5
#undef skip9
#undef skipD
#undef xr
#undef yr
#undef zr
#undef distance0
#undef distance1
#undef closestHash
#undef cellularJitter
#undef xPrimedBase
#undef yPrimedBase
#undef zPrimedBase
#undef idx
#undef vecX
#undef vecY
#undef vecZ
#undef newDistance
#undef xd0
#undef yd0
#undef zd0
#undef xd1
#undef yd1
#undef zd1
#undef xf0
#undef xf1
#undef yf0
#undef yf1
#undef xf00
#undef xf10
#undef xf01
#undef xf11
#undef idx0
#undef idx1
#undef lx0x
#undef ly0x
#undef lz0x
#undef lx1x
#undef ly1x
#undef lz1x
#undef lx0y
#undef ly0y
#undef lz0y
#undef xp
#undef yp
#undef zp
#undef freq
#undef sum
#undef noise
#undef vx
#undef vy
#undef vz
#undef outGradOnly
#undef aaaa
#undef bbbb
#undef cccc
#undef warpAmp
#undef seed
//endregion

// ====================
// Public API
// ====================

// Creates a noise state with default values.
// @param seed Optionally set the state seed.
fnl_state fnlCreateState(int _fnl_lib__seed)
{
    fnl_state newState;
    newState.seed = _fnl_lib__seed;
    newState.frequency = 0.01f;
    newState.noise_type = FNL_NOISE_OPENSIMPLEX2;
    newState.rotation_type_3d = FNL_ROTATION_NONE;
    newState.fractal_type = FNL_FRACTAL_NONE;
    newState.octaves = 3;
    newState.lacunarity = 2.f;
    newState.gain = 0.5f;
    newState.weighted_strength = 0.f;
    newState.ping_pong_strength = 2.f;
    newState.cellular_distance_func = FNL_CELLULAR_DISTANCE_EUCLIDEANSQ;
    newState.cellular_return_type = FNL_CELLULAR_RETURN_TYPE_DISTANCE;
    newState.cellular_jitter_mod = 1.f;
    newState.domain_warp_amp = 30.f;
    newState.domain_warp_type = FNL_DOMAIN_WARP_OPENSIMPLEX2;
    return newState;
}

// 2D noise at given position using the state settings
// @returns Noise output bounded between -1 and 1.
float fnlGetNoise2D(fnl_state state, FNLfloat x, FNLfloat y)
{
    _fnlTransformNoiseCoordinate2D(state, x, y);

    switch (state.fractal_type)
    {
        default:
            return _fnlGenNoiseSingle2D(state, state.seed, x, y);
        case FNL_FRACTAL_FBM:
            return _fnlGenFractalFBM2D(state, x, y);
        case FNL_FRACTAL_RIDGED:
            return _fnlGenFractalRidged2D(state, x, y);
        case FNL_FRACTAL_PINGPONG:
            return _fnlGenFractalPingPong2D(state, x, y);
    }
}

// 3D noise at given position using the state settings
// @returns Noise output bounded between -1 and 1.
float fnlGetNoise3D(fnl_state state, FNLfloat x, FNLfloat y, FNLfloat z)
{
    _fnlTransformNoiseCoordinate3D(state, x, y, z);

    // Select a noise type
    switch (state.fractal_type)
    {
        default:
            return _fnlGenNoiseSingle3D(state, state.seed, x, y, z);
        case FNL_FRACTAL_FBM:
            return _fnlGenFractalFBM3D(state, x, y, z);
        case FNL_FRACTAL_RIDGED:
            return _fnlGenFractalRidged3D(state, x, y, z);
        case FNL_FRACTAL_PINGPONG:
            return _fnlGenFractalPingPong3D(state, x, y, z);
    }
}

// 2D warps the input position using current domain warp settings.
// 
// Example usage with fnlGetNoise2D:
// ```
// fnlDomainWarp2D(state, x, y);
// noise = fnlGetNoise2D(state, x, y);
// ```
void fnlDomainWarp2D(fnl_state state, inout FNLfloat x, inout FNLfloat y)
{
    switch (state.fractal_type)
    {
        default:
            _fnlDomainWarpSingle2D(state, x, y);
            break;
        case FNL_FRACTAL_DOMAIN_WARP_PROGRESSIVE:
            _fnlDomainWarpFractalProgressive2D(state, x, y);
            break;
        case FNL_FRACTAL_DOMAIN_WARP_INDEPENDENT:
            _fnlDomainWarpFractalIndependent2D(state, x, y);
            break;
    }
}

// 3D warps the input position using current domain warp settings.
// 
// Example usage with fnlGetNoise3D:
// ```
// fnlDomainWarp3D(state, x, y, z);
// noise = fnlGetNoise3D(state, x, y, z);
// ```
void fnlDomainWarp3D(fnl_state state, inout FNLfloat x, inout FNLfloat y, inout FNLfloat z)
{
	
    switch (state.fractal_type)
    {
        default:
            _fnlDomainWarpSingle3D(state, x, y, z);
            break;
        case FNL_FRACTAL_DOMAIN_WARP_PROGRESSIVE:
            _fnlDomainWarpFractalProgressive3D(state, x, y, z);
            break;
        case FNL_FRACTAL_DOMAIN_WARP_INDEPENDENT:
            _fnlDomainWarpFractalIndependent3D(state, x, y, z);
            break;
    }
}
//region FinaliseCleanup
#undef state
#undef x
#undef y
#undef z
#undef GRADIENTS_2D
#undef GRADIENTS_3D
#undef RAND_VECS_2D
#undef RAND_VECS_3D
//endregion