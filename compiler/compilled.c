# 0 "before.c"
# 0 "<built-in>"
# 0 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 0 "<command-line>" 2
# 1 "before.c"
# 228 "before.c"
float _fnlCubicLerp(float _fnl_lib__a, float _fnl_lib__b, float _fnl_lib__c, float _fnl_lib__d, float _fnl_lib__t)
{_fnl_lib__d-=_fnl_lib__c;return fma(pow(_fnl_lib__t,3),_fnl_lib__d-_fnl_lib__a+_fnl_lib__b,fma(pow(_fnl_lib__t,2),fma(_fnl_lib__a-_fnl_lib__b,2.0,-_fnl_lib__d),fma(_fnl_lib__t,_fnl_lib__c-_fnl_lib__a,_fnl_lib__b)));}

float _fnlPingPong(float _fnl_lib__t){_fnl_lib__t-=floor(_fnl_lib__t*0.5f)*2.f;return _fnl_lib__t < 1.f ? _fnl_lib__t : 2.f-_fnl_lib__t;}


float _fnlCalculateFractalBounding(fnl_state _fnl_lib__state)
{
    float _fnl_lib__gain = abs(

  _fnl_lib__state.gain

 );
    float _fnl_lib__amp = _fnl_lib__gain;
    float _fnl_lib__ampFractal = 1.f;
    for (int _fnl_lib_i = 1; _fnl_lib_i < _fnl_lib__state.octaves; _fnl_lib_i++)
    {
        _fnl_lib__ampFractal += _fnl_lib__amp;
        _fnl_lib__amp *= _fnl_lib__gain;
    }
    return 1.f / _fnl_lib__ampFractal;
}



int _fnlHash2D(int _fnl_lib__seed, int _fnl_lib__xPrimed, int _fnl_lib__yPrimed)
{
    int _fnl_lib__hash = _fnl_lib__seed ^ _fnl_lib__xPrimed ^ _fnl_lib__yPrimed;

    _fnl_lib__hash *= 0x27d4eb2d;
    return _fnl_lib__hash;
}

int _fnlHash3D(int _fnl_lib__seed, int _fnl_lib__xPrimed, int _fnl_lib__yPrimed, int _fnl_lib__zPrimed)
{
    int _fnl_lib__hash = _fnl_lib__seed ^ _fnl_lib__xPrimed ^ _fnl_lib__yPrimed ^ _fnl_lib__zPrimed;

    _fnl_lib__hash *= 0x27d4eb2d;
    return _fnl_lib__hash;
}

float _fnlValCoord2D(int _fnl_lib__seed, int _fnl_lib__xPrimed, int _fnl_lib__yPrimed)
{
    int _fnl_lib__hash = _fnlHash2D(_fnl_lib__seed, _fnl_lib__xPrimed, _fnl_lib__yPrimed);
    _fnl_lib__hash *= _fnl_lib__hash;
    _fnl_lib__hash ^= _fnl_lib__hash << 19;
    return float(_fnl_lib__hash) * (1.f / 2147483648.f);
}

float _fnlValCoord3D(int _fnl_lib__seed, int _fnl_lib__xPrimed, int _fnl_lib__yPrimed, int _fnl_lib__zPrimed)
{
    int _fnl_lib__hash = _fnlHash3D(_fnl_lib__seed, _fnl_lib__xPrimed, _fnl_lib__yPrimed, _fnl_lib__zPrimed);
    _fnl_lib__hash *= _fnl_lib__hash;
    _fnl_lib__hash ^= _fnl_lib__hash << 19;
    return float(_fnl_lib__hash) * (1.f / 2147483648.f);
}

float _fnlGradCoord2D(int _fnl_lib__seed, int _fnl_lib__xPrimed, int _fnl_lib__yPrimed, float _fnl_lib__xd, float _fnl_lib__yd)
{
    int _fnl_lib__hash = _fnlHash2D(_fnl_lib__seed, _fnl_lib__xPrimed, _fnl_lib__yPrimed);
    _fnl_lib__hash ^= _fnl_lib__hash >> 15;
    _fnl_lib__hash &= 127 << 1;
    return _fnl_lib__xd * _fnl_lib__GRADIENTS_2D[_fnl_lib__hash] + _fnl_lib__yd * _fnl_lib__GRADIENTS_2D[_fnl_lib__hash | 1];
}

float _fnlGradCoord3D(int _fnl_lib__seed, int _fnl_lib__xPrimed, int _fnl_lib__yPrimed, int _fnl_lib__zPrimed, float _fnl_lib__xd, float _fnl_lib__yd, float _fnl_lib__zd)
{
    int _fnl_lib__hash = _fnlHash3D(_fnl_lib__seed, _fnl_lib__xPrimed, _fnl_lib__yPrimed, _fnl_lib__zPrimed);
    _fnl_lib__hash ^= _fnl_lib__hash >> 15;
    _fnl_lib__hash &= 63 << 2;
    return _fnl_lib__xd * _fnl_lib__GRADIENTS_3D[_fnl_lib__hash] + _fnl_lib__yd * _fnl_lib__GRADIENTS_3D[_fnl_lib__hash | 1] + _fnl_lib__zd * _fnl_lib__GRADIENTS_3D[_fnl_lib__hash | 2];
}

void _fnlGradCoordOut2D(int _fnl_lib__seed, int _fnl_lib__xPrimed, int _fnl_lib__yPrimed, out float _fnl_lib__xo, out float _fnl_lib__yo)
{
    int _fnl_lib__hash = _fnlHash2D(_fnl_lib__seed, _fnl_lib__xPrimed, _fnl_lib__yPrimed) & (255 << 1);

    _fnl_lib__xo = _fnl_lib__RAND_VECS_2D[_fnl_lib__hash];
    _fnl_lib__yo = _fnl_lib__RAND_VECS_2D[_fnl_lib__hash | 1];
}

void _fnlGradCoordOut3D(int _fnl_lib__seed, int _fnl_lib__xPrimed, int _fnl_lib__yPrimed, int _fnl_lib__zPrimed, out float _fnl_lib__xo, out float _fnl_lib__yo, out float _fnl_lib__zo)
{
    int _fnl_lib__hash = _fnlHash3D(_fnl_lib__seed, _fnl_lib__xPrimed, _fnl_lib__yPrimed, _fnl_lib__zPrimed) & (255 << 2);

    _fnl_lib__xo = _fnl_lib__RAND_VECS_3D[_fnl_lib__hash];
    _fnl_lib__yo = _fnl_lib__RAND_VECS_3D[_fnl_lib__hash | 1];
    _fnl_lib__zo = _fnl_lib__RAND_VECS_3D[_fnl_lib__hash | 2];
}

void _fnlGradCoordDual2D(int _fnl_lib__seed, int _fnl_lib__xPrimed, int _fnl_lib__yPrimed, float _fnl_lib__xd, float _fnl_lib__yd, out float _fnl_lib__xo, out float _fnl_lib__yo)
{
    int _fnl_lib__hash = _fnlHash2D(_fnl_lib__seed, _fnl_lib__xPrimed, _fnl_lib__yPrimed);
    int _fnl_lib__index1 = _fnl_lib__hash & (127 << 1);
    int _fnl_lib__index2 = (_fnl_lib__hash >> 7) & (255 << 1);

    float _fnl_lib__xg = _fnl_lib__GRADIENTS_2D[_fnl_lib__index1];
    float _fnl_lib__yg = _fnl_lib__GRADIENTS_2D[_fnl_lib__index1 | 1];
    float _fnl_lib__value = _fnl_lib__xd * _fnl_lib__xg + _fnl_lib__yd * _fnl_lib__yg;

    float _fnl_lib__xgo = _fnl_lib__RAND_VECS_2D[_fnl_lib__index2];
    float _fnl_lib__ygo = _fnl_lib__RAND_VECS_2D[_fnl_lib__index2 | 1];

    _fnl_lib__xo = _fnl_lib__value * _fnl_lib__xgo;
    _fnl_lib__yo = _fnl_lib__value * _fnl_lib__ygo;
}

void _fnlGradCoordDual3D(int _fnl_lib__seed, int _fnl_lib__xPrimed, int _fnl_lib__yPrimed, int _fnl_lib__zPrimed, float _fnl_lib__xd, float _fnl_lib__yd, float _fnl_lib__zd, out float _fnl_lib__xo, out float _fnl_lib__yo, out float _fnl_lib__zo)
{
    int _fnl_lib__hash = _fnlHash3D(_fnl_lib__seed, _fnl_lib__xPrimed, _fnl_lib__yPrimed, _fnl_lib__zPrimed);
    int _fnl_lib__index1 = _fnl_lib__hash & (63 << 2);
    int _fnl_lib__index2 = (_fnl_lib__hash >> 6) & (255 << 2);

    float _fnl_lib__xg = _fnl_lib__GRADIENTS_3D[_fnl_lib__index1];
    float _fnl_lib__yg = _fnl_lib__GRADIENTS_3D[_fnl_lib__index1 | 1];
    float _fnl_lib__zg = _fnl_lib__GRADIENTS_3D[_fnl_lib__index1 | 2];
    float _fnl_lib__value = _fnl_lib__xd * _fnl_lib__xg + _fnl_lib__yd * _fnl_lib__yg + _fnl_lib__zd * _fnl_lib__zg;

    float _fnl_lib__xgo = _fnl_lib__RAND_VECS_3D[_fnl_lib__index2];
    float _fnl_lib__ygo = _fnl_lib__RAND_VECS_3D[_fnl_lib__index2 | 1];
    float _fnl_lib__zgo = _fnl_lib__RAND_VECS_3D[_fnl_lib__index2 | 2];

    _fnl_lib__xo = _fnl_lib__value * _fnl_lib__xgo;
    _fnl_lib__yo = _fnl_lib__value * _fnl_lib__ygo;
    _fnl_lib__zo = _fnl_lib__value * _fnl_lib__zgo;
}

void _fnlTransformNoiseCoordinate2D(fnl_state _fnl_lib__state, inout FNLfloat _fnl_lib__x, inout FNLfloat _fnl_lib__y)
{
    _fnl_lib__x *= _fnl_lib__state.frequency;
    _fnl_lib__y *= _fnl_lib__state.frequency;

    switch (_fnl_lib__state.noise_type)
    {
        case FNL_NOISE_OPENSIMPLEX2:
        case FNL_NOISE_OPENSIMPLEX2S:
        {
            const FNLfloat _fnl_lib__SQRT3 = FNLfloat(1.7320508075688772935274463415059);
            const FNLfloat _fnl_lib__F2 = 0.5f * (_fnl_lib__SQRT3 - 1.f);
            FNLfloat _fnl_lib__t = (_fnl_lib__x + _fnl_lib__y) * _fnl_lib__F2;
            _fnl_lib__x += _fnl_lib__t;
            _fnl_lib__y += _fnl_lib__t;
        }
        break;
        default:
            break;
    }
}


void _fnlTransformNoiseCoordinate3D(fnl_state _fnl_lib__state, inout FNLfloat _fnl_lib__x, inout FNLfloat _fnl_lib__y, inout FNLfloat _fnl_lib__z)
{
    _fnl_lib__x *= _fnl_lib__state.frequency;
    _fnl_lib__y *= _fnl_lib__state.frequency;
    _fnl_lib__z *= _fnl_lib__state.frequency;

    switch (_fnl_lib__state.rotation_type_3d)
    {
        case FNL_ROTATION_IMPROVE_XY_PLANES:
        {
            FNLfloat _fnl_lib__xy = _fnl_lib__x + _fnl_lib__y;
            FNLfloat _fnl_lib__s2 = _fnl_lib__xy * -FNLfloat(0.211324865405187);
            _fnl_lib__z *= FNLfloat(0.577350269189626);
            _fnl_lib__x += _fnl_lib__s2 - _fnl_lib__z;
            _fnl_lib__y = _fnl_lib__y + _fnl_lib__s2 - _fnl_lib__z;
            _fnl_lib__z += _fnl_lib__xy * FNLfloat(0.577350269189626);
        }
        break;
        case FNL_ROTATION_IMPROVE_XZ_PLANES:
        {
            FNLfloat _fnl_lib__xz = _fnl_lib__x + _fnl_lib__z;
            FNLfloat _fnl_lib__s2 = _fnl_lib__xz * -FNLfloat(0.211324865405187);
            _fnl_lib__y *= FNLfloat(0.577350269189626);
            _fnl_lib__x += _fnl_lib__s2 - _fnl_lib__y;
            _fnl_lib__z += _fnl_lib__s2 - _fnl_lib__y;
            _fnl_lib__y += _fnl_lib__xz * FNLfloat(0.577350269189626);
        }
        break;
        default:
            switch (_fnl_lib__state.noise_type)
            {
            case FNL_NOISE_OPENSIMPLEX2:
            case FNL_NOISE_OPENSIMPLEX2S:
            {
                const FNLfloat _fnl_lib__R3 = FNLfloat(2.f / 3.f);
                FNLfloat _fnl_lib__r = (_fnl_lib__x + _fnl_lib__y + _fnl_lib__z) * _fnl_lib__R3;
                _fnl_lib__x = _fnl_lib__r - _fnl_lib__x;
                _fnl_lib__y = _fnl_lib__r - _fnl_lib__y;
                _fnl_lib__z = _fnl_lib__r - _fnl_lib__z;
            }
            break;
            default:
                break;
            }
            break;
    }
}


void _fnlTransformDomainWarpCoordinate2D(fnl_state _fnl_lib__state, inout FNLfloat _fnl_lib__x, inout FNLfloat _fnl_lib__y)
{
    switch (_fnl_lib__state.domain_warp_type)
    {
        case FNL_DOMAIN_WARP_OPENSIMPLEX2:
        case FNL_DOMAIN_WARP_OPENSIMPLEX2_REDUCED:
        {
            const FNLfloat _fnl_lib__SQRT3 = FNLfloat(1.7320508075688772935274463415059);
            const FNLfloat _fnl_lib__F2 = 0.5f * (_fnl_lib__SQRT3 - 1.f);
            FNLfloat _fnl_lib__t = (_fnl_lib__x + _fnl_lib__y) * _fnl_lib__F2;
            _fnl_lib__x += _fnl_lib__t;
            _fnl_lib__y += _fnl_lib__t;
        }
        break;
        default:
            break;
    }
}

void _fnlTransformDomainWarpCoordinate3D(fnl_state _fnl_lib__state, inout FNLfloat _fnl_lib__x, inout FNLfloat _fnl_lib__y, inout FNLfloat _fnl_lib__z)
{
    switch (_fnl_lib__state.rotation_type_3d)
    {
        case FNL_ROTATION_IMPROVE_XY_PLANES:
        {
            FNLfloat _fnl_lib__xy = _fnl_lib__x + _fnl_lib__y;
            FNLfloat _fnl_lib__s2 = _fnl_lib__xy * -FNLfloat(0.211324865405187);
            _fnl_lib__z *= FNLfloat(0.577350269189626);
            _fnl_lib__x += _fnl_lib__s2 - _fnl_lib__z;
            _fnl_lib__y = _fnl_lib__y + _fnl_lib__s2 - _fnl_lib__z;
            _fnl_lib__z += _fnl_lib__xy * FNLfloat(0.577350269189626);
        }
        break;
        case FNL_ROTATION_IMPROVE_XZ_PLANES:
        {
            FNLfloat _fnl_lib__xz = _fnl_lib__x + _fnl_lib__z;
            FNLfloat _fnl_lib__s2 = _fnl_lib__xz * -FNLfloat(0.211324865405187);
            _fnl_lib__y *= FNLfloat(0.577350269189626);
            _fnl_lib__x += _fnl_lib__s2 - _fnl_lib__y;
            _fnl_lib__z += _fnl_lib__s2 - _fnl_lib__y;
            _fnl_lib__y += _fnl_lib__xz * FNLfloat(0.577350269189626);
        }
        break;
        default:
            switch (_fnl_lib__state.domain_warp_type)
            {
            case FNL_DOMAIN_WARP_OPENSIMPLEX2:
            case FNL_DOMAIN_WARP_OPENSIMPLEX2_REDUCED:
            {
                const FNLfloat _fnl_lib__R3 = FNLfloat(2.f / 3.f);
                FNLfloat _fnl_lib__r = (_fnl_lib__x + _fnl_lib__y + _fnl_lib__z) * _fnl_lib__R3;
                _fnl_lib__x = _fnl_lib__r - _fnl_lib__x;
                _fnl_lib__y = _fnl_lib__r - _fnl_lib__y;
                _fnl_lib__z = _fnl_lib__r - _fnl_lib__z;
            }
            break;
            default:
                break;
            }
        break;
    }
}


float _fnlSingleSimplex2D(int _fnl_lib__seed, FNLfloat _fnl_lib__x, FNLfloat _fnl_lib__y)
{


    const float _fnl_lib__SQRT3 = 1.7320508075688772935274463415059;
    const float _fnl_lib_G2 = (3.f - _fnl_lib__SQRT3) / 6.f;







    int _fnl_lib_i = int(floor(_fnl_lib__x));
    int _fnl_lib_j = int(floor(_fnl_lib__y));
    float _fnl_lib_xi = _fnl_lib__x - float(_fnl_lib_i);
    float _fnl_lib_yi = _fnl_lib__y - float(_fnl_lib_j);

    float _fnl_lib__t = (_fnl_lib_xi + _fnl_lib_yi) * _fnl_lib_G2;
    float _fnl_lib_x0 = _fnl_lib_xi - _fnl_lib__t;
    float _fnl_lib_y0 = _fnl_lib_yi - _fnl_lib__t;

    _fnl_lib_i *= PRIME_X;
    _fnl_lib_j *= PRIME_Y;

    float _fnl_lib_n0, _fnl_lib_n1, _fnl_lib_n2;

    float _fnl_lib__a = 0.5f - _fnl_lib_x0 * _fnl_lib_x0 - _fnl_lib_y0 * _fnl_lib_y0;
    if (_fnl_lib__a <= 0.f)
 {
  _fnl_lib_n0 = 0.f;
 }
    else
 {
        _fnl_lib_n0 = (_fnl_lib__a * _fnl_lib__a) * (_fnl_lib__a * _fnl_lib__a) * _fnlGradCoord2D(_fnl_lib__seed, _fnl_lib_i, _fnl_lib_j, _fnl_lib_x0, _fnl_lib_y0);
 }

    float _fnl_lib__c = (2.f * (1.f - 2.f * _fnl_lib_G2) * (1.f / _fnl_lib_G2 - 2.f)) * _fnl_lib__t + ((-2.f * (1.f - 2.f * _fnl_lib_G2) * (1.f - 2.f * _fnl_lib_G2)) + _fnl_lib__a);
    if (_fnl_lib__c <= 0.f)
 {
        _fnl_lib_n2 = 0.f;
 }
    else
    {
        float _fnl_lib_x2 = _fnl_lib_x0 + (2.f * _fnl_lib_G2 - 1.f);
        float _fnl_lib_y2 = _fnl_lib_y0 + (2.f * _fnl_lib_G2 - 1.f);
        _fnl_lib_n2 = (_fnl_lib__c * _fnl_lib__c) * (_fnl_lib__c * _fnl_lib__c) * _fnlGradCoord2D(_fnl_lib__seed, _fnl_lib_i + PRIME_X, _fnl_lib_j + PRIME_Y, _fnl_lib_x2, _fnl_lib_y2);
    }

    if (_fnl_lib_y0 > _fnl_lib_x0)
    {
        float _fnl_lib_x1 = _fnl_lib_x0 + _fnl_lib_G2;
        float _fnl_lib_y1 = _fnl_lib_y0 + _fnl_lib_G2 - 1.f;
        float _fnl_lib__b = 0.5f - _fnl_lib_x1 * _fnl_lib_x1 - _fnl_lib_y1 * _fnl_lib_y1;
        if (_fnl_lib__b <= 0.f)
  {
            _fnl_lib_n1 = 0.f;
  }
        else
  {
            _fnl_lib_n1 = (_fnl_lib__b * _fnl_lib__b) * (_fnl_lib__b * _fnl_lib__b) * _fnlGradCoord2D(_fnl_lib__seed, _fnl_lib_i, _fnl_lib_j + PRIME_Y, _fnl_lib_x1, _fnl_lib_y1);
        }
    }
    else
    {
        float _fnl_lib_x1 = _fnl_lib_x0 + (_fnl_lib_G2 - 1.f);
        float _fnl_lib_y1 = _fnl_lib_y0 + _fnl_lib_G2;
        float _fnl_lib__b = 0.5f - _fnl_lib_x1 * _fnl_lib_x1 - _fnl_lib_y1 * _fnl_lib_y1;
        if (_fnl_lib__b <= 0.f)
  {
            _fnl_lib_n1 = 0.f;
  }
        else
        {
            _fnl_lib_n1 = (_fnl_lib__b * _fnl_lib__b) * (_fnl_lib__b * _fnl_lib__b) * _fnlGradCoord2D(_fnl_lib__seed, _fnl_lib_i + PRIME_X, _fnl_lib_j, _fnl_lib_x1, _fnl_lib_y1);
        }
    }

    return (_fnl_lib_n0 + _fnl_lib_n1 + _fnl_lib_n2) * 99.83685446303647;
}
float _fnlSingleOpenSimplex23D(int _fnl_lib__seed, FNLfloat _fnl_lib__x, FNLfloat _fnl_lib__y, FNLfloat _fnl_lib__z)
{
# 581 "before.c"
    int _fnl_lib_i = int(round(_fnl_lib__x));
    int _fnl_lib_j = int(round(_fnl_lib__y));
    int _fnl_lib_k = int(round(_fnl_lib__z));
    float _fnl_lib_x0 = _fnl_lib__x - float(_fnl_lib_i);
    float _fnl_lib_y0 = _fnl_lib__y - float(_fnl_lib_j);
    float _fnl_lib_z0 = _fnl_lib__z - float(_fnl_lib_k);

    int _fnl_float_xNSign = int(-1.f - _fnl_lib_x0) | 1;
    int _fnl_float_yNSign = int(-1.f - _fnl_lib_y0) | 1;
    int _fnl_float_zNSign = int(-1.f - _fnl_lib_z0) | 1;

    float _fnl_float_ax0 = float(_fnl_float_xNSign) * -_fnl_lib_x0;
    float _fnl_float_ay0 = float(_fnl_float_yNSign) * -_fnl_lib_y0;
    float _fnl_float_az0 = float(_fnl_float_zNSign) * -_fnl_lib_z0;

    _fnl_lib_i *= PRIME_X;
    _fnl_lib_j *= PRIME_Y;
    _fnl_lib_k *= PRIME_Z;

    float _fnl_lib__value = 0.f;
    float _fnl_lib__a = (0.6f - _fnl_lib_x0 * _fnl_lib_x0) - (_fnl_lib_y0 * _fnl_lib_y0 + _fnl_lib_z0 * _fnl_lib_z0);

    for (int _fnl_lib_l = 0; ; _fnl_lib_l++)
    {
        if (_fnl_lib__a > 0.f)
        {
            _fnl_lib__value += (_fnl_lib__a * _fnl_lib__a) * (_fnl_lib__a * _fnl_lib__a) * _fnlGradCoord3D(_fnl_lib__seed, _fnl_lib_i, _fnl_lib_j, _fnl_lib_k, _fnl_lib_x0, _fnl_lib_y0, _fnl_lib_z0);
        }

        float _fnl_lib__b = _fnl_lib__a + 1.f;
        int _fnl_lib_i1 = _fnl_lib_i;
        int _fnl_lib_j1 = _fnl_lib_j;
        int _fnl_lib_k1 = _fnl_lib_k;
        float _fnl_lib_x1 = _fnl_lib_x0;
        float _fnl_lib_y1 = _fnl_lib_y0;
        float _fnl_lib_z1 = _fnl_lib_z0;
        if (_fnl_float_ax0 >= _fnl_float_ay0 && _fnl_float_ax0 >= _fnl_float_az0)
        {
            _fnl_lib_x1 += float(_fnl_float_xNSign);
            _fnl_lib__b -= float(_fnl_float_xNSign) * 2.f * _fnl_lib_x1;
            _fnl_lib_i1 -= _fnl_float_xNSign * PRIME_X;
        }
        else if (_fnl_float_ay0 > _fnl_float_ax0 && _fnl_float_ay0 >= _fnl_float_az0)
        {
            _fnl_lib_y1 += float(_fnl_float_yNSign);
            _fnl_lib__b -= float(_fnl_float_yNSign) * 2.f * _fnl_lib_y1;
            _fnl_lib_j1 -= _fnl_float_yNSign * PRIME_Y;
        }
        else
        {
            _fnl_lib_z1 += float(_fnl_float_zNSign);
            _fnl_lib__b -= float(_fnl_float_zNSign) * 2.f * _fnl_lib_z1;
            _fnl_lib_k1 -= _fnl_float_zNSign * PRIME_Z;
        }

        if (_fnl_lib__b > 0.f)
        {
            _fnl_lib__value += (_fnl_lib__b * _fnl_lib__b) * (_fnl_lib__b * _fnl_lib__b) * _fnlGradCoord3D(_fnl_lib__seed, _fnl_lib_i1, _fnl_lib_j1, _fnl_lib_k1, _fnl_lib_x1, _fnl_lib_y1, _fnl_lib_z1);
        }

        if (_fnl_lib_l == 1) break;

        _fnl_float_ax0 = 0.5f - _fnl_float_ax0;
        _fnl_float_ay0 = 0.5f - _fnl_float_ay0;
        _fnl_float_az0 = 0.5f - _fnl_float_az0;

        _fnl_lib_x0 = float(_fnl_float_xNSign) * _fnl_float_ax0;
        _fnl_lib_y0 = float(_fnl_float_yNSign) * _fnl_float_ay0;
        _fnl_lib_z0 = float(_fnl_float_zNSign) * _fnl_float_az0;

        _fnl_lib__a += (0.75f - _fnl_float_ax0) - (_fnl_float_ay0 + _fnl_float_az0);

        _fnl_lib_i += (_fnl_float_xNSign >> 1) & PRIME_X;
        _fnl_lib_j += (_fnl_float_yNSign >> 1) & PRIME_Y;
        _fnl_lib_k += (_fnl_float_zNSign >> 1) & PRIME_Z;

        _fnl_float_xNSign = -_fnl_float_xNSign;
        _fnl_float_yNSign = -_fnl_float_yNSign;
        _fnl_float_zNSign = -_fnl_float_zNSign;

        _fnl_lib__seed = ~_fnl_lib__seed;
    }

    return _fnl_lib__value * 32.69428253173828125;
}



float _fnlSingleOpenSimplex2S2D(int _fnl_lib__seed, FNLfloat _fnl_lib__x, FNLfloat _fnl_lib__y)
{


    const FNLfloat _fnl_lib__SQRT3 = FNLfloat(1.7320508075688772935274463415059);
    const FNLfloat _fnl_lib_G2 = (3.f - _fnl_lib__SQRT3) / 6.f;







    int _fnl_lib_i = int(floor(_fnl_lib__x));
    int _fnl_lib_j = int(floor(_fnl_lib__y));
    float _fnl_lib_xi = _fnl_lib__x - float(_fnl_lib_i);
    float _fnl_lib_yi = _fnl_lib__y - float(_fnl_lib_j);

    _fnl_lib_i *= PRIME_X;
    _fnl_lib_j *= PRIME_Y;
    int _fnl_lib_i1 = _fnl_lib_i + PRIME_X;
    int _fnl_lib_j1 = _fnl_lib_j + PRIME_Y;

    float _fnl_lib__t = (_fnl_lib_xi + _fnl_lib_yi) * _fnl_lib_G2;
    float _fnl_lib_x0 = _fnl_lib_xi - _fnl_lib__t;
    float _fnl_lib_y0 = _fnl_lib_yi - _fnl_lib__t;

    int _fnl_lib__aMask = int((_fnl_lib_xi + _fnl_lib_yi + 1.f) * -0.5f);
    int _fnl_lib__bMask = int((_fnl_lib_xi - float(_fnl_lib__aMask) - 2.f) * 0.5f - _fnl_lib_yi);
    int _fnl_lib__cMask = int((_fnl_lib_yi - float(_fnl_lib__aMask) - 2.f) * 0.5f - _fnl_lib_xi);

    float _fnl_lib__a0 = (2.f / 3.f) - _fnl_lib_x0 * _fnl_lib_x0 - _fnl_lib_y0 * _fnl_lib_y0;
    float _fnl_lib__value = (_fnl_lib__a0 * _fnl_lib__a0) * (_fnl_lib__a0 * _fnl_lib__a0) * _fnlGradCoord2D(_fnl_lib__seed, _fnl_lib_i, _fnl_lib_j, _fnl_lib_x0, _fnl_lib_y0);

    float _fnl_lib__a1 = (2.f * (1.f - 2.f * _fnl_lib_G2) * (1.f / _fnl_lib_G2 - 2.f)) * _fnl_lib__t + ((-2.f * (1.f - 2.f * _fnl_lib_G2) * (1.f - 2.f * _fnl_lib_G2)) + _fnl_lib__a0);
    float _fnl_lib_x1 = _fnl_lib_x0 - (1.f - 2.f * _fnl_lib_G2);
    float _fnl_lib_y1 = _fnl_lib_y0 - (1.f - 2.f * _fnl_lib_G2);
    _fnl_lib__value += (_fnl_lib__a1 * _fnl_lib__a1) * (_fnl_lib__a1 * _fnl_lib__a1) * _fnlGradCoord2D(_fnl_lib__seed, _fnl_lib_i1, _fnl_lib_j1, _fnl_lib_x1, _fnl_lib_y1);

    int _fnl_lib__di2 = ~(_fnl_lib__aMask | _fnl_lib__cMask) | 1;
    int _fnl_lib__ndj2 = (_fnl_lib__aMask & _fnl_lib__bMask) << 1;
    float _fnl_lib__t2 = float(_fnl_lib__di2 - _fnl_lib__ndj2) * _fnl_lib_G2;
    float _fnl_lib_x2 = _fnl_lib_x0 - float(_fnl_lib__di2) + _fnl_lib__t2;
    float _fnl_lib_y2 = _fnl_lib_y0 + float(_fnl_lib__ndj2) + _fnl_lib__t2;
    float _fnl_lib__a2 = (2.f / 3.f) - _fnl_lib_x2 * _fnl_lib_x2 - _fnl_lib_y2 * _fnl_lib_y2;
    if (_fnl_lib__a2 > 0.f)
    {
        _fnl_lib__value += (_fnl_lib__a2 * _fnl_lib__a2) * (_fnl_lib__a2 * _fnl_lib__a2) * _fnlGradCoord2D(_fnl_lib__seed, _fnl_lib_i1 + (_fnl_lib__di2 & (-PRIME_X << 1)), _fnl_lib_j + (_fnl_lib__ndj2 & (PRIME_Y << 1)), _fnl_lib_x2, _fnl_lib_y2);
    }

    int _fnl_lib__ndi3 = (_fnl_lib__aMask & _fnl_lib__cMask) << 1;
    int _fnl_lib__dj3 = ~(_fnl_lib__aMask | _fnl_lib__bMask) | 1;
    float _fnl_lib__t3 = float(_fnl_lib__dj3 - _fnl_lib__ndi3) * _fnl_lib_G2;
    float _fnl_lib_x3 = _fnl_lib_x0 + float(_fnl_lib__ndi3) + _fnl_lib__t3;
    float _fnl_lib_y3 = _fnl_lib_y0 - float(_fnl_lib__dj3) + _fnl_lib__t3;
    float _fnl_lib__a3 = (2.f / 3.f) - _fnl_lib_x3 * _fnl_lib_x3 - _fnl_lib_y3 * _fnl_lib_y3;
    if (_fnl_lib__a3 > 0.f)
    {
        _fnl_lib__value += (_fnl_lib__a3 * _fnl_lib__a3) * (_fnl_lib__a3 * _fnl_lib__a3) * _fnlGradCoord2D(_fnl_lib__seed, _fnl_lib_i + (_fnl_lib__ndi3 & (PRIME_X << 1)), _fnl_lib_j1 + (_fnl_lib__dj3 & (-PRIME_Y << 1)), _fnl_lib_x3, _fnl_lib_y3);
    }

    return _fnl_lib__value * 18.24196194486065;
}


float _fnlSingleOpenSimplex2S3D(int _fnl_lib__seed, FNLfloat _fnl_lib__x, FNLfloat _fnl_lib__y, FNLfloat _fnl_lib__z)
{
# 744 "before.c"
    int _fnl_lib_i = int(floor(_fnl_lib__x));
    int _fnl_lib_j = int(floor(_fnl_lib__y));
    int _fnl_lib_k = int(floor(_fnl_lib__z));
    float _fnl_lib_xi = _fnl_lib__x - float(_fnl_lib_i);
    float _fnl_lib_yi = _fnl_lib__y - float(_fnl_lib_j);
    float _fnl_lib_zi = _fnl_lib__z - float(_fnl_lib_k);

    _fnl_lib_i *= PRIME_X;
    _fnl_lib_j *= PRIME_Y;
    _fnl_lib_k *= PRIME_Z;
    int _fnl_lib__seed2 = _fnl_lib__seed + 1293373;

    int _fnl_lib__xNMask = int(-0.5f - _fnl_lib_xi);
    int _fnl_lib__yNMask = int(-0.5f - _fnl_lib_yi);
    int _fnl_lib__zNMask = int(-0.5f - _fnl_lib_zi);

    float _fnl_lib_x0 = _fnl_lib_xi + float(_fnl_lib__xNMask);
    float _fnl_lib_y0 = _fnl_lib_yi + float(_fnl_lib__yNMask);
    float _fnl_lib_z0 = _fnl_lib_zi + float(_fnl_lib__zNMask);
    float _fnl_lib__a0 = 0.75f - _fnl_lib_x0 * _fnl_lib_x0 - _fnl_lib_y0 * _fnl_lib_y0 - _fnl_lib_z0 * _fnl_lib_z0;
    float _fnl_lib__value = (_fnl_lib__a0 * _fnl_lib__a0) * (_fnl_lib__a0 * _fnl_lib__a0) * _fnlGradCoord3D(_fnl_lib__seed,
                                                          _fnl_lib_i + (_fnl_lib__xNMask & PRIME_X), _fnl_lib_j + (_fnl_lib__yNMask & PRIME_Y), _fnl_lib_k + (_fnl_lib__zNMask & PRIME_Z), _fnl_lib_x0, _fnl_lib_y0, _fnl_lib_z0);

    float _fnl_lib_x1 = _fnl_lib_xi - 0.5f;
    float _fnl_lib_y1 = _fnl_lib_yi - 0.5f;
    float _fnl_lib_z1 = _fnl_lib_zi - 0.5f;
    float _fnl_lib__a1 = 0.75f - _fnl_lib_x1 * _fnl_lib_x1 - _fnl_lib_y1 * _fnl_lib_y1 - _fnl_lib_z1 * _fnl_lib_z1;
    _fnl_lib__value += (_fnl_lib__a1 * _fnl_lib__a1) * (_fnl_lib__a1 * _fnl_lib__a1) * _fnlGradCoord3D(_fnl_lib__seed2,
                                                     _fnl_lib_i + PRIME_X, _fnl_lib_j + PRIME_Y, _fnl_lib_k + PRIME_Z, _fnl_lib_x1, _fnl_lib_y1, _fnl_lib_z1);

    float _fnl_lib__xAFlipMask0 = float((_fnl_lib__xNMask | 1) << 1) * _fnl_lib_x1;
    float _fnl_lib__yAFlipMask0 = float((_fnl_lib__yNMask | 1) << 1) * _fnl_lib_y1;
    float _fnl_lib__zAFlipMask0 = float((_fnl_lib__zNMask | 1) << 1) * _fnl_lib_z1;
    float _fnl_lib__xAFlipMask1 = float(-2 - (_fnl_lib__xNMask << 2)) * _fnl_lib_x1 - 1.f;
    float _fnl_lib__yAFlipMask1 = float(-2 - (_fnl_lib__yNMask << 2)) * _fnl_lib_y1 - 1.f;
    float _fnl_lib__zAFlipMask1 = float(-2 - (_fnl_lib__zNMask << 2)) * _fnl_lib_z1 - 1.f;

    bool _fnl_lib__skip5 = false;
    float _fnl_lib__a2 = _fnl_lib__xAFlipMask0 + _fnl_lib__a0;
    if (_fnl_lib__a2 > 0.f)
    {
        float _fnl_lib_x2 = _fnl_lib_x0 - float(_fnl_lib__xNMask | 1);
        float _fnl_lib_y2 = _fnl_lib_y0;
        float _fnl_lib_z2 = _fnl_lib_z0;
        _fnl_lib__value += (_fnl_lib__a2 * _fnl_lib__a2) * (_fnl_lib__a2 * _fnl_lib__a2) * _fnlGradCoord3D(_fnl_lib__seed,
                                                         _fnl_lib_i + (~_fnl_lib__xNMask & PRIME_X), _fnl_lib_j + (_fnl_lib__yNMask & PRIME_Y), _fnl_lib_k + (_fnl_lib__zNMask & PRIME_Z), _fnl_lib_x2, _fnl_lib_y2, _fnl_lib_z2);
    }
    else
    {
        float _fnl_lib__a3 = _fnl_lib__yAFlipMask0 + _fnl_lib__zAFlipMask0 + _fnl_lib__a0;
        if (_fnl_lib__a3 > 0.f)
        {
            float _fnl_lib_x3 = _fnl_lib_x0;
            float _fnl_lib_y3 = _fnl_lib_y0 - float(_fnl_lib__yNMask | 1);
            float _fnl_lib_z3 = _fnl_lib_z0 - float(_fnl_lib__zNMask | 1);
            _fnl_lib__value += (_fnl_lib__a3 * _fnl_lib__a3) * (_fnl_lib__a3 * _fnl_lib__a3) * _fnlGradCoord3D(_fnl_lib__seed,
                                                             _fnl_lib_i + (_fnl_lib__xNMask & PRIME_X), _fnl_lib_j + (~_fnl_lib__yNMask & PRIME_Y), _fnl_lib_k + (~_fnl_lib__zNMask & PRIME_Z), _fnl_lib_x3, _fnl_lib_y3, _fnl_lib_z3);
        }

        float _fnl_lib__a4 = _fnl_lib__xAFlipMask1 + _fnl_lib__a1;
        if (_fnl_lib__a4 > 0.f)
        {
            float _fnl_lib_x4 = float(_fnl_lib__xNMask | 1) + _fnl_lib_x1;
            float _fnl_lib_y4 = _fnl_lib_y1;
            float _fnl_lib_z4 = _fnl_lib_z1;
            _fnl_lib__value += (_fnl_lib__a4 * _fnl_lib__a4) * (_fnl_lib__a4 * _fnl_lib__a4) * _fnlGradCoord3D(_fnl_lib__seed2,
                                                             _fnl_lib_i + (_fnl_lib__xNMask & (PRIME_X * 2)), _fnl_lib_j + PRIME_Y, _fnl_lib_k + PRIME_Z, _fnl_lib_x4, _fnl_lib_y4, _fnl_lib_z4);
            _fnl_lib__skip5 = true;
        }
    }

    bool _fnl_lib__skip9 = false;
    float _fnl_lib__a6 = _fnl_lib__yAFlipMask0 + _fnl_lib__a0;
    if (_fnl_lib__a6 > 0.f)
    {
        float _fnl_lib_x6 = _fnl_lib_x0;
        float _fnl_lib_y6 = _fnl_lib_y0 - float(_fnl_lib__yNMask | 1);
        float _fnl_lib_z6 = _fnl_lib_z0;
        _fnl_lib__value += (_fnl_lib__a6 * _fnl_lib__a6) * (_fnl_lib__a6 * _fnl_lib__a6) * _fnlGradCoord3D(_fnl_lib__seed,
                                                         _fnl_lib_i + (_fnl_lib__xNMask & PRIME_X), _fnl_lib_j + (~_fnl_lib__yNMask & PRIME_Y), _fnl_lib_k + (_fnl_lib__zNMask & PRIME_Z), _fnl_lib_x6, _fnl_lib_y6, _fnl_lib_z6);
    }
    else
    {
        float _fnl_lib__a7 = _fnl_lib__xAFlipMask0 + _fnl_lib__zAFlipMask0 + _fnl_lib__a0;
        if (_fnl_lib__a7 > 0.f)
        {
            float _fnl_lib_x7 = _fnl_lib_x0 - float(_fnl_lib__xNMask | 1);
            float _fnl_lib_y7 = _fnl_lib_y0;
            float _fnl_lib_z7 = _fnl_lib_z0 - float(_fnl_lib__zNMask | 1);
            _fnl_lib__value += (_fnl_lib__a7 * _fnl_lib__a7) * (_fnl_lib__a7 * _fnl_lib__a7) * _fnlGradCoord3D(_fnl_lib__seed,
                                                             _fnl_lib_i + (~_fnl_lib__xNMask & PRIME_X), _fnl_lib_j + (_fnl_lib__yNMask & PRIME_Y), _fnl_lib_k + (~_fnl_lib__zNMask & PRIME_Z), _fnl_lib_x7, _fnl_lib_y7, _fnl_lib_z7);
        }

        float _fnl_lib__a8 = _fnl_lib__yAFlipMask1 + _fnl_lib__a1;
        if (_fnl_lib__a8 > 0.f)
        {
            float _fnl_lib_x8 = _fnl_lib_x1;
            float _fnl_lib_y8 = float(_fnl_lib__yNMask | 1) + _fnl_lib_y1;
            float _fnl_lib_z8 = _fnl_lib_z1;
            _fnl_lib__value += (_fnl_lib__a8 * _fnl_lib__a8) * (_fnl_lib__a8 * _fnl_lib__a8) * _fnlGradCoord3D(_fnl_lib__seed2,
                                                             _fnl_lib_i + PRIME_X, _fnl_lib_j + (_fnl_lib__yNMask & (PRIME_Y << 1)), _fnl_lib_k + PRIME_Z, _fnl_lib_x8, _fnl_lib_y8, _fnl_lib_z8);
            _fnl_lib__skip9 = true;
        }
    }

    bool _fnl_lib__skipD = false;
    float _fnl_lib__aA = _fnl_lib__zAFlipMask0 + _fnl_lib__a0;
    if (_fnl_lib__aA > 0.f)
    {
        float _fnl_lib_xA = _fnl_lib_x0;
        float _fnl_lib_yA = _fnl_lib_y0;
        float _fnl_lib_zA = _fnl_lib_z0 - float(_fnl_lib__zNMask | 1);
        _fnl_lib__value += (_fnl_lib__aA * _fnl_lib__aA) * (_fnl_lib__aA * _fnl_lib__aA) * _fnlGradCoord3D(_fnl_lib__seed,
                                                         _fnl_lib_i + (_fnl_lib__xNMask & PRIME_X), _fnl_lib_j + (_fnl_lib__yNMask & PRIME_Y), _fnl_lib_k + (~_fnl_lib__zNMask & PRIME_Z), _fnl_lib_xA, _fnl_lib_yA, _fnl_lib_zA);
    }
    else
    {
        float _fnl_lib__aB = _fnl_lib__xAFlipMask0 + _fnl_lib__yAFlipMask0 + _fnl_lib__a0;
        if (_fnl_lib__aB > 0.f)
        {
            float _fnl_lib_xB = _fnl_lib_x0 - float(_fnl_lib__xNMask | 1);
            float _fnl_lib_yB = _fnl_lib_y0 - float(_fnl_lib__yNMask | 1);
            float _fnl_lib_zB = _fnl_lib_z0;
            _fnl_lib__value += (_fnl_lib__aB * _fnl_lib__aB) * (_fnl_lib__aB * _fnl_lib__aB) * _fnlGradCoord3D(_fnl_lib__seed,
                                                             _fnl_lib_i + (~_fnl_lib__xNMask & PRIME_X), _fnl_lib_j + (~_fnl_lib__yNMask & PRIME_Y), _fnl_lib_k + (_fnl_lib__zNMask & PRIME_Z), _fnl_lib_xB, _fnl_lib_yB, _fnl_lib_zB);
        }

        float _fnl_lib__aC = _fnl_lib__zAFlipMask1 + _fnl_lib__a1;
        if (_fnl_lib__aC > 0.f)
        {
            float _fnl_lib_xC = _fnl_lib_x1;
            float _fnl_lib_yC = _fnl_lib_y1;
            float _fnl_lib_zC = float(_fnl_lib__zNMask | 1) + _fnl_lib_z1;
            _fnl_lib__value += (_fnl_lib__aC * _fnl_lib__aC) * (_fnl_lib__aC * _fnl_lib__aC) * _fnlGradCoord3D(_fnl_lib__seed2,
                                                             _fnl_lib_i + PRIME_X, _fnl_lib_j + PRIME_Y, _fnl_lib_k + (_fnl_lib__zNMask & (PRIME_Z << 1)), _fnl_lib_xC, _fnl_lib_yC, _fnl_lib_zC);
            _fnl_lib__skipD = true;
        }
    }

    if (!_fnl_lib__skip5)
    {
        float _fnl_lib__a5 = _fnl_lib__yAFlipMask1 + _fnl_lib__zAFlipMask1 + _fnl_lib__a1;
        if (_fnl_lib__a5 > 0.f)
        {
            float _fnl_lib_x5 = _fnl_lib_x1;
            float _fnl_lib_y5 = float(_fnl_lib__yNMask | 1) + _fnl_lib_y1;
            float _fnl_lib_z5 = float(_fnl_lib__zNMask | 1) + _fnl_lib_z1;
            _fnl_lib__value += (_fnl_lib__a5 * _fnl_lib__a5) * (_fnl_lib__a5 * _fnl_lib__a5) * _fnlGradCoord3D(_fnl_lib__seed2,
                                                             _fnl_lib_i + PRIME_X, _fnl_lib_j + (_fnl_lib__yNMask & (PRIME_Y << 1)), _fnl_lib_k + (_fnl_lib__zNMask & (PRIME_Z << 1)), _fnl_lib_x5, _fnl_lib_y5, _fnl_lib_z5);
        }
    }

    if (!_fnl_lib__skip9)
    {
        float _fnl_lib__a9 = _fnl_lib__xAFlipMask1 + _fnl_lib__zAFlipMask1 + _fnl_lib__a1;
        if (_fnl_lib__a9 > 0.f)
        {
            float _fnl_lib_x9 = float(_fnl_lib__xNMask | 1) + _fnl_lib_x1;
            float _fnl_lib_y9 = _fnl_lib_y1;
            float _fnl_lib_z9 = float(_fnl_lib__zNMask | 1) + _fnl_lib_z1;
            _fnl_lib__value += (_fnl_lib__a9 * _fnl_lib__a9) * (_fnl_lib__a9 * _fnl_lib__a9) * _fnlGradCoord3D(_fnl_lib__seed2,
                                                             _fnl_lib_i + (_fnl_lib__xNMask & (PRIME_X * 2)), _fnl_lib_j + PRIME_Y, _fnl_lib_k + (_fnl_lib__zNMask & (PRIME_Z << 1)), _fnl_lib_x9, _fnl_lib_y9, _fnl_lib_z9);
        }
    }

    if (!_fnl_lib__skipD)
    {
        float _fnl_lib__aD = _fnl_lib__xAFlipMask1 + _fnl_lib__yAFlipMask1 + _fnl_lib__a1;
        if (_fnl_lib__aD > 0.f)
        {
            float _fnl_lib_xD = float(_fnl_lib__xNMask | 1) + _fnl_lib_x1;
            float _fnl_lib_yD = float(_fnl_lib__yNMask | 1) + _fnl_lib_y1;
            float _fnl_lib_zD = _fnl_lib_z1;
            _fnl_lib__value += (_fnl_lib__aD * _fnl_lib__aD) * (_fnl_lib__aD * _fnl_lib__aD) * _fnlGradCoord3D(_fnl_lib__seed2,
                                                             _fnl_lib_i + (_fnl_lib__xNMask & (PRIME_X << 1)), _fnl_lib_j + (_fnl_lib__yNMask & (PRIME_Y << 1)), _fnl_lib_k + PRIME_Z, _fnl_lib_xD, _fnl_lib_yD, _fnl_lib_zD);
        }
    }

    return _fnl_lib__value * 9.046026385208288;
}


float _fnlSingleCellular2D(fnl_state _fnl_lib__state, int _fnl_lib__seed, FNLfloat _fnl_lib__x, FNLfloat _fnl_lib__y)
{
    int _fnl_lib__xr = int(round(_fnl_lib__x));
    int _fnl_lib__yr = int(round(_fnl_lib__y));

    float _fnl_lib__distance0 = 1e10f;
    float _fnl_lib__distance1 = 1e10f;
    int _fnl_lib__closestHash = 0;

    float _fnl_lib__cellularJitter = 0.43701595f * _fnl_lib__state.cellular_jitter_mod;

    int _fnl_lib__xPrimed = (_fnl_lib__xr - 1) * PRIME_X;
    int _fnl_lib__yPrimedBase = (_fnl_lib__yr - 1) * PRIME_Y;

    switch (_fnl_lib__state.cellular_distance_func)
    {
        case FNL_CELLULAR_DISTANCE_MANHATTAN:
        {
            for (int _fnl_lib_xi = _fnl_lib__xr - 1; _fnl_lib_xi <= _fnl_lib__xr + 1; _fnl_lib_xi++)
            {
                int _fnl_lib__yPrimed = _fnl_lib__yPrimedBase;

                for (int _fnl_lib_yi = _fnl_lib__yr - 1; _fnl_lib_yi <= _fnl_lib__yr + 1; _fnl_lib_yi++)
                {
                    int _fnl_lib__hash = _fnlHash2D(_fnl_lib__seed, _fnl_lib__xPrimed, _fnl_lib__yPrimed);
                    int _fnl_lib__idx = _fnl_lib__hash & (255 << 1);

                    float _fnl_lib__vecX = float(_fnl_lib_xi) - _fnl_lib__x + _fnl_lib__RAND_VECS_2D[_fnl_lib__idx] * _fnl_lib__cellularJitter;
                    float _fnl_lib__vecY = float(_fnl_lib_yi) - _fnl_lib__y + _fnl_lib__RAND_VECS_2D[_fnl_lib__idx | 1] * _fnl_lib__cellularJitter;

                    float _fnl_lib__newDistance = abs(_fnl_lib__vecX) + abs(_fnl_lib__vecY);

                    _fnl_lib__distance1 = max(min(_fnl_lib__distance1, _fnl_lib__newDistance), _fnl_lib__distance0);
                    if (_fnl_lib__newDistance < _fnl_lib__distance0)
                    {
                        _fnl_lib__distance0 = _fnl_lib__newDistance;
                        _fnl_lib__closestHash = _fnl_lib__hash;
                    }
                    _fnl_lib__yPrimed += PRIME_Y;
                }
                _fnl_lib__xPrimed += PRIME_X;
            }
            break;
        }
        case FNL_CELLULAR_DISTANCE_HYBRID:
        {
            for (int _fnl_lib_xi = _fnl_lib__xr - 1; _fnl_lib_xi <= _fnl_lib__xr + 1; _fnl_lib_xi++)
            {
                int _fnl_lib__yPrimed = _fnl_lib__yPrimedBase;
                for (int _fnl_lib_yi = _fnl_lib__yr - 1; _fnl_lib_yi <= _fnl_lib__yr + 1; _fnl_lib_yi++)
                {
                    int _fnl_lib__hash = _fnlHash2D(_fnl_lib__seed, _fnl_lib__xPrimed, _fnl_lib__yPrimed);
                    int _fnl_lib__idx = _fnl_lib__hash & (255 << 1);

                    float _fnl_lib__vecX = float(_fnl_lib_xi) - _fnl_lib__x + _fnl_lib__RAND_VECS_2D[_fnl_lib__idx] * _fnl_lib__cellularJitter;
                    float _fnl_lib__vecY = float(_fnl_lib_yi) - _fnl_lib__y + _fnl_lib__RAND_VECS_2D[_fnl_lib__idx | 1] * _fnl_lib__cellularJitter;

                    float _fnl_lib__newDistance = (abs(_fnl_lib__vecX) + abs(_fnl_lib__vecY)) + (_fnl_lib__vecX * _fnl_lib__vecX + _fnl_lib__vecY * _fnl_lib__vecY);

                    _fnl_lib__distance1 = max(min(_fnl_lib__distance1, _fnl_lib__newDistance), _fnl_lib__distance0);
                    if (_fnl_lib__newDistance < _fnl_lib__distance0)
                    {
                        _fnl_lib__distance0 = _fnl_lib__newDistance;
                        _fnl_lib__closestHash = _fnl_lib__hash;
                    }
                    _fnl_lib__yPrimed += PRIME_Y;
                }
                _fnl_lib__xPrimed += PRIME_X;
            }
            break;
        }
  case FNL_CELLULAR_DISTANCE_EUCLIDEAN:
        case FNL_CELLULAR_DISTANCE_EUCLIDEANSQ:
        default:
        {
            for (int _fnl_lib_xi = _fnl_lib__xr - 1; _fnl_lib_xi <= _fnl_lib__xr + 1; _fnl_lib_xi++)
            {
                int _fnl_lib__yPrimed = _fnl_lib__yPrimedBase;

                for (int _fnl_lib_yi = _fnl_lib__yr - 1; _fnl_lib_yi <= _fnl_lib__yr + 1; _fnl_lib_yi++)
                {
                    int _fnl_lib__hash = _fnlHash2D(_fnl_lib__seed, _fnl_lib__xPrimed, _fnl_lib__yPrimed);
                    int _fnl_lib__idx = _fnl_lib__hash & (255 << 1);

                    float _fnl_lib__vecX = float(_fnl_lib_xi) - _fnl_lib__x + _fnl_lib__RAND_VECS_2D[_fnl_lib__idx] * _fnl_lib__cellularJitter;
                    float _fnl_lib__vecY = float(_fnl_lib_yi) - _fnl_lib__y + _fnl_lib__RAND_VECS_2D[_fnl_lib__idx | 1] * _fnl_lib__cellularJitter;

                    float _fnl_lib__newDistance = _fnl_lib__vecX * _fnl_lib__vecX + _fnl_lib__vecY * _fnl_lib__vecY;

                    _fnl_lib__distance1 = max(min(_fnl_lib__distance1, _fnl_lib__newDistance), _fnl_lib__distance0);
                    if (_fnl_lib__newDistance < _fnl_lib__distance0)
                    {
                        _fnl_lib__distance0 = _fnl_lib__newDistance;
                        _fnl_lib__closestHash = _fnl_lib__hash;
                    }
                    _fnl_lib__yPrimed += PRIME_Y;
                }
                _fnl_lib__xPrimed += PRIME_X;
            }
            break;
        }
    }

    if (_fnl_lib__state.cellular_distance_func == FNL_CELLULAR_DISTANCE_EUCLIDEAN && _fnl_lib__state.cellular_return_type >= FNL_CELLULAR_RETURN_TYPE_DISTANCE)
    {
        _fnl_lib__distance0 = sqrt(_fnl_lib__distance0);
        if (_fnl_lib__state.cellular_return_type >= FNL_CELLULAR_RETURN_TYPE_DISTANCE2)
  {
            _fnl_lib__distance1 = sqrt(_fnl_lib__distance1);
  }
    }

    switch (_fnl_lib__state.cellular_return_type)
    {
        case FNL_CELLULAR_RETURN_TYPE_CELLVALUE:
            return float(_fnl_lib__closestHash) * (1.f / 2147483648.f);
        case FNL_CELLULAR_RETURN_TYPE_DISTANCE:
            return _fnl_lib__distance0 - 1.f;
        case FNL_CELLULAR_RETURN_TYPE_DISTANCE2:
            return _fnl_lib__distance1 - 1.f;
        case FNL_CELLULAR_RETURN_TYPE_DISTANCE2ADD:
            return (_fnl_lib__distance1 + _fnl_lib__distance0) * 0.5f - 1.f;
        case FNL_CELLULAR_RETURN_TYPE_DISTANCE2SUB:
            return _fnl_lib__distance1 - _fnl_lib__distance0 - 1.f;
        case FNL_CELLULAR_RETURN_TYPE_DISTANCE2MUL:
            return _fnl_lib__distance1 * _fnl_lib__distance0 * 0.5f - 1.f;
        case FNL_CELLULAR_RETURN_TYPE_DISTANCE2DIV:
            return _fnl_lib__distance0 / _fnl_lib__distance1 - 1.f;
        default:
            return 0.f;
    }
}

float _fnlSingleCellular3D(fnl_state _fnl_lib__state, int _fnl_lib__seed, FNLfloat _fnl_lib__x, FNLfloat _fnl_lib__y, FNLfloat _fnl_lib__z)
{
    int _fnl_lib__xr = int(round(_fnl_lib__x));
    int _fnl_lib__yr = int(round(_fnl_lib__y));
    int _fnl_lib__zr = int(round(_fnl_lib__z));

    float _fnl_lib__distance0 = 1e10f;
    float _fnl_lib__distance1 = 1e10f;
    int _fnl_lib__closestHash = 0;

    float _fnl_lib__cellularJitter = 0.39614353 * _fnl_lib__state.cellular_jitter_mod;

    int _fnl_lib__xPrimed = (_fnl_lib__xr - 1) * PRIME_X;
    int _fnl_lib__yPrimedBase = (_fnl_lib__yr - 1) * PRIME_Y;
    int _fnl_lib__zPrimedBase = (_fnl_lib__zr - 1) * PRIME_Z;

    switch (_fnl_lib__state.cellular_distance_func)
    {
    case FNL_CELLULAR_DISTANCE_MANHATTAN:
    {
        for (int _fnl_lib_xi = _fnl_lib__xr - 1; _fnl_lib_xi <= _fnl_lib__xr + 1; _fnl_lib_xi++)
        {
            int _fnl_lib__yPrimed = _fnl_lib__yPrimedBase;

            for (int _fnl_lib_yi = _fnl_lib__yr - 1; _fnl_lib_yi <= _fnl_lib__yr + 1; _fnl_lib_yi++)
            {
                int _fnl_lib__zPrimed = _fnl_lib__zPrimedBase;

                for (int _fnl_lib_zi = _fnl_lib__zr - 1; _fnl_lib_zi <= _fnl_lib__zr + 1; _fnl_lib_zi++)
                {
                    int _fnl_lib__hash = _fnlHash3D(_fnl_lib__seed, _fnl_lib__xPrimed, _fnl_lib__yPrimed, _fnl_lib__zPrimed);
                    int _fnl_lib__idx = _fnl_lib__hash & (255 << 2);

                    float _fnl_lib__vecX = float(_fnl_lib_xi) - _fnl_lib__x + _fnl_lib__RAND_VECS_3D[_fnl_lib__idx] * _fnl_lib__cellularJitter;
                    float _fnl_lib__vecY = float(_fnl_lib_yi) - _fnl_lib__y + _fnl_lib__RAND_VECS_3D[_fnl_lib__idx | 1] * _fnl_lib__cellularJitter;
                    float _fnl_lib__vecZ = float(_fnl_lib_zi) - _fnl_lib__z + _fnl_lib__RAND_VECS_3D[_fnl_lib__idx | 2] * _fnl_lib__cellularJitter;

                    float _fnl_lib__newDistance = abs(_fnl_lib__vecX) + abs(_fnl_lib__vecY) + abs(_fnl_lib__vecZ);

                    _fnl_lib__distance1 = max(min(_fnl_lib__distance1, _fnl_lib__newDistance), _fnl_lib__distance0);
                    if (_fnl_lib__newDistance < _fnl_lib__distance0)
                    {
                        _fnl_lib__distance0 = _fnl_lib__newDistance;
                        _fnl_lib__closestHash = _fnl_lib__hash;
                    }
                    _fnl_lib__zPrimed += PRIME_Z;
                }
                _fnl_lib__yPrimed += PRIME_Y;
            }
            _fnl_lib__xPrimed += PRIME_X;
        }
        break;
    }
    case FNL_CELLULAR_DISTANCE_HYBRID:
    {
        for (int _fnl_lib_xi = _fnl_lib__xr - 1; _fnl_lib_xi <= _fnl_lib__xr + 1; _fnl_lib_xi++)
        {
            int _fnl_lib__yPrimed = _fnl_lib__yPrimedBase;

            for (int _fnl_lib_yi = _fnl_lib__yr - 1; _fnl_lib_yi <= _fnl_lib__yr + 1; _fnl_lib_yi++)
            {
                int _fnl_lib__zPrimed = _fnl_lib__zPrimedBase;

                for (int _fnl_lib_zi = _fnl_lib__zr - 1; _fnl_lib_zi <= _fnl_lib__zr + 1; _fnl_lib_zi++)
                {
                    int _fnl_lib__hash = _fnlHash3D(_fnl_lib__seed, _fnl_lib__xPrimed, _fnl_lib__yPrimed, _fnl_lib__zPrimed);
                    int _fnl_lib__idx = _fnl_lib__hash & (255 << 2);

                    float _fnl_lib__vecX = float(_fnl_lib_xi) - _fnl_lib__x + _fnl_lib__RAND_VECS_3D[_fnl_lib__idx] * _fnl_lib__cellularJitter;
                    float _fnl_lib__vecY = float(_fnl_lib_yi) - _fnl_lib__y + _fnl_lib__RAND_VECS_3D[_fnl_lib__idx | 1] * _fnl_lib__cellularJitter;
                    float _fnl_lib__vecZ = float(_fnl_lib_zi) - _fnl_lib__z + _fnl_lib__RAND_VECS_3D[_fnl_lib__idx | 2] * _fnl_lib__cellularJitter;

                    float _fnl_lib__newDistance = (abs(_fnl_lib__vecX) + abs(_fnl_lib__vecY) + abs(_fnl_lib__vecZ)) + (_fnl_lib__vecX * _fnl_lib__vecX + _fnl_lib__vecY * _fnl_lib__vecY + _fnl_lib__vecZ * _fnl_lib__vecZ);

                    _fnl_lib__distance1 = max(min(_fnl_lib__distance1, _fnl_lib__newDistance), _fnl_lib__distance0);
                    if (_fnl_lib__newDistance < _fnl_lib__distance0)
                    {
                        _fnl_lib__distance0 = _fnl_lib__newDistance;
                        _fnl_lib__closestHash = _fnl_lib__hash;
                    }
                    _fnl_lib__zPrimed += PRIME_Z;
                }
                _fnl_lib__yPrimed += PRIME_Y;
            }
            _fnl_lib__xPrimed += PRIME_X;
        }
        break;
    }
    case FNL_CELLULAR_DISTANCE_EUCLIDEAN:
    case FNL_CELLULAR_DISTANCE_EUCLIDEANSQ:
    default:
    {
        for (int _fnl_lib_xi = _fnl_lib__xr - 1; _fnl_lib_xi <= _fnl_lib__xr + 1; _fnl_lib_xi++)
        {
            int _fnl_lib__yPrimed = _fnl_lib__yPrimedBase;

            for (int _fnl_lib_yi = _fnl_lib__yr - 1; _fnl_lib_yi <= _fnl_lib__yr + 1; _fnl_lib_yi++)
            {
                int _fnl_lib__zPrimed = _fnl_lib__zPrimedBase;

                for (int _fnl_lib_zi = _fnl_lib__zr - 1; _fnl_lib_zi <= _fnl_lib__zr + 1; _fnl_lib_zi++)
                {
                    int _fnl_lib__hash = _fnlHash3D(_fnl_lib__seed, _fnl_lib__xPrimed, _fnl_lib__yPrimed, _fnl_lib__zPrimed);
                    int _fnl_lib__idx = _fnl_lib__hash & (255 << 2);

                    float _fnl_lib__vecX = float(_fnl_lib_xi) - _fnl_lib__x + _fnl_lib__RAND_VECS_3D[_fnl_lib__idx] * _fnl_lib__cellularJitter;
                    float _fnl_lib__vecY = float(_fnl_lib_yi) - _fnl_lib__y + _fnl_lib__RAND_VECS_3D[_fnl_lib__idx | 1] * _fnl_lib__cellularJitter;
                    float _fnl_lib__vecZ = float(_fnl_lib_zi) - _fnl_lib__z + _fnl_lib__RAND_VECS_3D[_fnl_lib__idx | 2] * _fnl_lib__cellularJitter;

                    float _fnl_lib__newDistance = _fnl_lib__vecX * _fnl_lib__vecX + _fnl_lib__vecY * _fnl_lib__vecY + _fnl_lib__vecZ * _fnl_lib__vecZ;

                    _fnl_lib__distance1 = max(min(_fnl_lib__distance1, _fnl_lib__newDistance), _fnl_lib__distance0);
                    if (_fnl_lib__newDistance < _fnl_lib__distance0)
                    {
                        _fnl_lib__distance0 = _fnl_lib__newDistance;
                        _fnl_lib__closestHash = _fnl_lib__hash;
                    }
                    _fnl_lib__zPrimed += PRIME_Z;
                }
                _fnl_lib__yPrimed += PRIME_Y;
            }
            _fnl_lib__xPrimed += PRIME_X;
        }
        break;
    }
    }

    if (_fnl_lib__state.cellular_distance_func == FNL_CELLULAR_DISTANCE_EUCLIDEAN && _fnl_lib__state.cellular_return_type >= FNL_CELLULAR_RETURN_TYPE_DISTANCE)
    {
        _fnl_lib__distance0 = sqrt(_fnl_lib__distance0);
        if (_fnl_lib__state.cellular_return_type >= FNL_CELLULAR_RETURN_TYPE_DISTANCE2)
  {
            _fnl_lib__distance1 = sqrt(_fnl_lib__distance1);
  }
    }

    switch (_fnl_lib__state.cellular_return_type)
    {
    case FNL_CELLULAR_RETURN_TYPE_CELLVALUE:
        return float(_fnl_lib__closestHash) * (1.f / 2147483648.f);
    case FNL_CELLULAR_RETURN_TYPE_DISTANCE:
        return _fnl_lib__distance0 - 1.f;
    case FNL_CELLULAR_RETURN_TYPE_DISTANCE2:
        return _fnl_lib__distance1 - 1.f;
    case FNL_CELLULAR_RETURN_TYPE_DISTANCE2ADD:
        return (_fnl_lib__distance1 + _fnl_lib__distance0) * 0.5f - 1.f;
    case FNL_CELLULAR_RETURN_TYPE_DISTANCE2SUB:
        return _fnl_lib__distance1 - _fnl_lib__distance0 - 1.f;
    case FNL_CELLULAR_RETURN_TYPE_DISTANCE2MUL:
        return _fnl_lib__distance1 * _fnl_lib__distance0 * 0.5f - 1.f;
    case FNL_CELLULAR_RETURN_TYPE_DISTANCE2DIV:
        return _fnl_lib__distance0 / _fnl_lib__distance1 - 1.f;
    default:
        return 0.f;
    }
}


float _fnlSinglePerlin2D(int _fnl_lib__seed, FNLfloat _fnl_lib__x, FNLfloat _fnl_lib__y)
{
    int _fnl_lib_x0 = int(floor(_fnl_lib__x));
    int _fnl_lib_y0 = int(floor(_fnl_lib__y));

    float _fnl_lib__xd0 = _fnl_lib__x - float(_fnl_lib_x0);
    float _fnl_lib__yd0 = _fnl_lib__y - float(_fnl_lib_y0);
    float _fnl_lib__xd1 = _fnl_lib__xd0 - 1.f;
    float _fnl_lib__yd1 = _fnl_lib__yd0 - 1.f;

    float _fnl_lib_xs = _fnlInterpQuintic(_fnl_lib__xd0);
    float _fnl_lib_ys = _fnlInterpQuintic(_fnl_lib__yd0);

    _fnl_lib_x0 *= PRIME_X;
    _fnl_lib_y0 *= PRIME_Y;
    int _fnl_lib_x1 = _fnl_lib_x0 + PRIME_X;
    int _fnl_lib_y1 = _fnl_lib_y0 + PRIME_Y;

    float _fnl_lib__xf0 = mix(_fnlGradCoord2D(_fnl_lib__seed, _fnl_lib_x0, _fnl_lib_y0, _fnl_lib__xd0, _fnl_lib__yd0), _fnlGradCoord2D(_fnl_lib__seed, _fnl_lib_x1, _fnl_lib_y0, _fnl_lib__xd1, _fnl_lib__yd0), _fnl_lib_xs);
    float _fnl_lib__xf1 = mix(_fnlGradCoord2D(_fnl_lib__seed, _fnl_lib_x0, _fnl_lib_y1, _fnl_lib__xd0, _fnl_lib__yd1), _fnlGradCoord2D(_fnl_lib__seed, _fnl_lib_x1, _fnl_lib_y1, _fnl_lib__xd1, _fnl_lib__yd1), _fnl_lib_xs);

    return mix(_fnl_lib__xf0, _fnl_lib__xf1, _fnl_lib_ys) * 1.4247691104677813;
}

float _fnlSinglePerlin3D(int _fnl_lib__seed, FNLfloat _fnl_lib__x, FNLfloat _fnl_lib__y, FNLfloat _fnl_lib__z)
{
    int _fnl_lib_x0 = int(floor(_fnl_lib__x));
    int _fnl_lib_y0 = int(floor(_fnl_lib__y));
    int _fnl_lib_z0 = int(floor(_fnl_lib__z));

    float _fnl_lib__xd0 = _fnl_lib__x - float(_fnl_lib_x0);
    float _fnl_lib__yd0 = _fnl_lib__y - float(_fnl_lib_y0);
    float _fnl_lib__zd0 = _fnl_lib__z - float(_fnl_lib_z0);
    float _fnl_lib__xd1 = _fnl_lib__xd0 - 1.f;
    float _fnl_lib__yd1 = _fnl_lib__yd0 - 1.f;
    float _fnl_lib__zd1 = _fnl_lib__zd0 - 1.f;

    float _fnl_lib_xs = _fnlInterpQuintic(_fnl_lib__xd0);
    float _fnl_lib_ys = _fnlInterpQuintic(_fnl_lib__yd0);
    float _fnl_lib_zs = _fnlInterpQuintic(_fnl_lib__zd0);

    _fnl_lib_x0 *= PRIME_X;
    _fnl_lib_y0 *= PRIME_Y;
    _fnl_lib_z0 *= PRIME_Z;
    int _fnl_lib_x1 = _fnl_lib_x0 + PRIME_X;
    int _fnl_lib_y1 = _fnl_lib_y0 + PRIME_Y;
    int _fnl_lib_z1 = _fnl_lib_z0 + PRIME_Z;

    float _fnl_lib__xf00 = mix(_fnlGradCoord3D(_fnl_lib__seed, _fnl_lib_x0, _fnl_lib_y0, _fnl_lib_z0, _fnl_lib__xd0, _fnl_lib__yd0, _fnl_lib__zd0), _fnlGradCoord3D(_fnl_lib__seed, _fnl_lib_x1, _fnl_lib_y0, _fnl_lib_z0, _fnl_lib__xd1, _fnl_lib__yd0, _fnl_lib__zd0), _fnl_lib_xs);
    float _fnl_lib__xf10 = mix(_fnlGradCoord3D(_fnl_lib__seed, _fnl_lib_x0, _fnl_lib_y1, _fnl_lib_z0, _fnl_lib__xd0, _fnl_lib__yd1, _fnl_lib__zd0), _fnlGradCoord3D(_fnl_lib__seed, _fnl_lib_x1, _fnl_lib_y1, _fnl_lib_z0, _fnl_lib__xd1, _fnl_lib__yd1, _fnl_lib__zd0), _fnl_lib_xs);
    float _fnl_lib__xf01 = mix(_fnlGradCoord3D(_fnl_lib__seed, _fnl_lib_x0, _fnl_lib_y0, _fnl_lib_z1, _fnl_lib__xd0, _fnl_lib__yd0, _fnl_lib__zd1), _fnlGradCoord3D(_fnl_lib__seed, _fnl_lib_x1, _fnl_lib_y0, _fnl_lib_z1, _fnl_lib__xd1, _fnl_lib__yd0, _fnl_lib__zd1), _fnl_lib_xs);
    float _fnl_lib__xf11 = mix(_fnlGradCoord3D(_fnl_lib__seed, _fnl_lib_x0, _fnl_lib_y1, _fnl_lib_z1, _fnl_lib__xd0, _fnl_lib__yd1, _fnl_lib__zd1), _fnlGradCoord3D(_fnl_lib__seed, _fnl_lib_x1, _fnl_lib_y1, _fnl_lib_z1, _fnl_lib__xd1, _fnl_lib__yd1, _fnl_lib__zd1), _fnl_lib_xs);

    float _fnl_lib__yf0 = mix(_fnl_lib__xf00, _fnl_lib__xf10, _fnl_lib_ys);
    float _fnl_lib__yf1 = mix(_fnl_lib__xf01, _fnl_lib__xf11, _fnl_lib_ys);

    return mix(_fnl_lib__yf0, _fnl_lib__yf1, _fnl_lib_zs) * 0.964921414852142333984375;
}



float _fnlSingleValueCubic2D(int _fnl_lib__seed, FNLfloat _fnl_lib__x, FNLfloat _fnl_lib__y)
{
    int _fnl_lib_x1 = int(floor(_fnl_lib__x));
    int _fnl_lib_y1 = int(floor(_fnl_lib__y));

    float _fnl_lib_xs = _fnl_lib__x - float(_fnl_lib_x1);
    float _fnl_lib_ys = _fnl_lib__y - float(_fnl_lib_y1);

    _fnl_lib_x1 *= PRIME_X;
    _fnl_lib_y1 *= PRIME_Y;

    int _fnl_lib_x0 = _fnl_lib_x1 - PRIME_X;
    int _fnl_lib_y0 = _fnl_lib_y1 - PRIME_Y;
    int _fnl_lib_x2 = _fnl_lib_x1 + PRIME_X;
    int _fnl_lib_y2 = _fnl_lib_y1 + PRIME_Y;
    int _fnl_lib_x3 = _fnl_lib_x1 + PRIME_X * 2;
    int _fnl_lib_y3 = _fnl_lib_y1 + PRIME_Y * 2;

    return _fnlCubicLerp(_fnlCubicLerp(_fnlValCoord2D(_fnl_lib__seed, _fnl_lib_x0, _fnl_lib_y0), _fnlValCoord2D(_fnl_lib__seed, _fnl_lib_x1, _fnl_lib_y0), _fnlValCoord2D(_fnl_lib__seed, _fnl_lib_x2, _fnl_lib_y0), _fnlValCoord2D(_fnl_lib__seed, _fnl_lib_x3, _fnl_lib_y0),_fnl_lib_xs),
        _fnlCubicLerp(_fnlValCoord2D(_fnl_lib__seed, _fnl_lib_x0, _fnl_lib_y1), _fnlValCoord2D(_fnl_lib__seed, _fnl_lib_x1, _fnl_lib_y1), _fnlValCoord2D(_fnl_lib__seed, _fnl_lib_x2, _fnl_lib_y1), _fnlValCoord2D(_fnl_lib__seed, _fnl_lib_x3, _fnl_lib_y1),
                      _fnl_lib_xs),
        _fnlCubicLerp(_fnlValCoord2D(_fnl_lib__seed, _fnl_lib_x0, _fnl_lib_y2), _fnlValCoord2D(_fnl_lib__seed, _fnl_lib_x1, _fnl_lib_y2), _fnlValCoord2D(_fnl_lib__seed, _fnl_lib_x2, _fnl_lib_y2), _fnlValCoord2D(_fnl_lib__seed, _fnl_lib_x3, _fnl_lib_y2),
                      _fnl_lib_xs),
        _fnlCubicLerp(_fnlValCoord2D(_fnl_lib__seed, _fnl_lib_x0, _fnl_lib_y3), _fnlValCoord2D(_fnl_lib__seed, _fnl_lib_x1, _fnl_lib_y3), _fnlValCoord2D(_fnl_lib__seed, _fnl_lib_x2, _fnl_lib_y3), _fnlValCoord2D(_fnl_lib__seed, _fnl_lib_x3, _fnl_lib_y3),
                      _fnl_lib_xs),
        _fnl_lib_ys) * (1.f / (1.5f * 1.5f));
}

float _fnlSingleValueCubic3D(int _fnl_lib__seed, FNLfloat _fnl_lib__x, FNLfloat _fnl_lib__y, FNLfloat _fnl_lib__z)
{
    int _fnl_lib_x1 = int(floor(_fnl_lib__x));
    int _fnl_lib_y1 = int(floor(_fnl_lib__y));
    int _fnl_lib_z1 = int(floor(_fnl_lib__z));

    float _fnl_lib_xs = _fnl_lib__x - float(_fnl_lib_x1);
    float _fnl_lib_ys = _fnl_lib__y - float(_fnl_lib_y1);
    float _fnl_lib_zs = _fnl_lib__z - float(_fnl_lib_z1);

    _fnl_lib_x1 *= PRIME_X;
    _fnl_lib_y1 *= PRIME_Y;
    _fnl_lib_z1 *= PRIME_Z;

    int _fnl_lib_x0 = _fnl_lib_x1 - PRIME_X;
    int _fnl_lib_y0 = _fnl_lib_y1 - PRIME_Y;
    int _fnl_lib_z0 = _fnl_lib_z1 - PRIME_Z;
    int _fnl_lib_x2 = _fnl_lib_x1 + PRIME_X;
    int _fnl_lib_y2 = _fnl_lib_y1 + PRIME_Y;
    int _fnl_lib_z2 = _fnl_lib_z1 + PRIME_Z;
    int _fnl_lib_x3 = _fnl_lib_x1 + PRIME_X * 2;
    int _fnl_lib_y3 = _fnl_lib_y1 + PRIME_Y * 2;
    int _fnl_lib_z3 = _fnl_lib_z1 + PRIME_Z * 2;

    return _fnlCubicLerp(
        _fnlCubicLerp(
            _fnlCubicLerp(_fnlValCoord3D(_fnl_lib__seed, _fnl_lib_x0, _fnl_lib_y0, _fnl_lib_z0), _fnlValCoord3D(_fnl_lib__seed, _fnl_lib_x1, _fnl_lib_y0, _fnl_lib_z0), _fnlValCoord3D(_fnl_lib__seed, _fnl_lib_x2, _fnl_lib_y0, _fnl_lib_z0), _fnlValCoord3D(_fnl_lib__seed, _fnl_lib_x3, _fnl_lib_y0, _fnl_lib_z0), _fnl_lib_xs),
            _fnlCubicLerp(_fnlValCoord3D(_fnl_lib__seed, _fnl_lib_x0, _fnl_lib_y1, _fnl_lib_z0), _fnlValCoord3D(_fnl_lib__seed, _fnl_lib_x1, _fnl_lib_y1, _fnl_lib_z0), _fnlValCoord3D(_fnl_lib__seed, _fnl_lib_x2, _fnl_lib_y1, _fnl_lib_z0), _fnlValCoord3D(_fnl_lib__seed, _fnl_lib_x3, _fnl_lib_y1, _fnl_lib_z0), _fnl_lib_xs),
            _fnlCubicLerp(_fnlValCoord3D(_fnl_lib__seed, _fnl_lib_x0, _fnl_lib_y2, _fnl_lib_z0), _fnlValCoord3D(_fnl_lib__seed, _fnl_lib_x1, _fnl_lib_y2, _fnl_lib_z0), _fnlValCoord3D(_fnl_lib__seed, _fnl_lib_x2, _fnl_lib_y2, _fnl_lib_z0), _fnlValCoord3D(_fnl_lib__seed, _fnl_lib_x3, _fnl_lib_y2, _fnl_lib_z0), _fnl_lib_xs),
            _fnlCubicLerp(_fnlValCoord3D(_fnl_lib__seed, _fnl_lib_x0, _fnl_lib_y3, _fnl_lib_z0), _fnlValCoord3D(_fnl_lib__seed, _fnl_lib_x1, _fnl_lib_y3, _fnl_lib_z0), _fnlValCoord3D(_fnl_lib__seed, _fnl_lib_x2, _fnl_lib_y3, _fnl_lib_z0), _fnlValCoord3D(_fnl_lib__seed, _fnl_lib_x3, _fnl_lib_y3, _fnl_lib_z0), _fnl_lib_xs),
            _fnl_lib_ys),
        _fnlCubicLerp(
            _fnlCubicLerp(_fnlValCoord3D(_fnl_lib__seed, _fnl_lib_x0, _fnl_lib_y0, _fnl_lib_z1), _fnlValCoord3D(_fnl_lib__seed, _fnl_lib_x1, _fnl_lib_y0, _fnl_lib_z1), _fnlValCoord3D(_fnl_lib__seed, _fnl_lib_x2, _fnl_lib_y0, _fnl_lib_z1), _fnlValCoord3D(_fnl_lib__seed, _fnl_lib_x3, _fnl_lib_y0, _fnl_lib_z1), _fnl_lib_xs),
            _fnlCubicLerp(_fnlValCoord3D(_fnl_lib__seed, _fnl_lib_x0, _fnl_lib_y1, _fnl_lib_z1), _fnlValCoord3D(_fnl_lib__seed, _fnl_lib_x1, _fnl_lib_y1, _fnl_lib_z1), _fnlValCoord3D(_fnl_lib__seed, _fnl_lib_x2, _fnl_lib_y1, _fnl_lib_z1), _fnlValCoord3D(_fnl_lib__seed, _fnl_lib_x3, _fnl_lib_y1, _fnl_lib_z1), _fnl_lib_xs),
            _fnlCubicLerp(_fnlValCoord3D(_fnl_lib__seed, _fnl_lib_x0, _fnl_lib_y2, _fnl_lib_z1), _fnlValCoord3D(_fnl_lib__seed, _fnl_lib_x1, _fnl_lib_y2, _fnl_lib_z1), _fnlValCoord3D(_fnl_lib__seed, _fnl_lib_x2, _fnl_lib_y2, _fnl_lib_z1), _fnlValCoord3D(_fnl_lib__seed, _fnl_lib_x3, _fnl_lib_y2, _fnl_lib_z1), _fnl_lib_xs),
            _fnlCubicLerp(_fnlValCoord3D(_fnl_lib__seed, _fnl_lib_x0, _fnl_lib_y3, _fnl_lib_z1), _fnlValCoord3D(_fnl_lib__seed, _fnl_lib_x1, _fnl_lib_y3, _fnl_lib_z1), _fnlValCoord3D(_fnl_lib__seed, _fnl_lib_x2, _fnl_lib_y3, _fnl_lib_z1), _fnlValCoord3D(_fnl_lib__seed, _fnl_lib_x3, _fnl_lib_y3, _fnl_lib_z1), _fnl_lib_xs),
            _fnl_lib_ys),
        _fnlCubicLerp(
            _fnlCubicLerp(_fnlValCoord3D(_fnl_lib__seed, _fnl_lib_x0, _fnl_lib_y0, _fnl_lib_z2), _fnlValCoord3D(_fnl_lib__seed, _fnl_lib_x1, _fnl_lib_y0, _fnl_lib_z2), _fnlValCoord3D(_fnl_lib__seed, _fnl_lib_x2, _fnl_lib_y0, _fnl_lib_z2), _fnlValCoord3D(_fnl_lib__seed, _fnl_lib_x3, _fnl_lib_y0, _fnl_lib_z2), _fnl_lib_xs),
            _fnlCubicLerp(_fnlValCoord3D(_fnl_lib__seed, _fnl_lib_x0, _fnl_lib_y1, _fnl_lib_z2), _fnlValCoord3D(_fnl_lib__seed, _fnl_lib_x1, _fnl_lib_y1, _fnl_lib_z2), _fnlValCoord3D(_fnl_lib__seed, _fnl_lib_x2, _fnl_lib_y1, _fnl_lib_z2), _fnlValCoord3D(_fnl_lib__seed, _fnl_lib_x3, _fnl_lib_y1, _fnl_lib_z2), _fnl_lib_xs),
            _fnlCubicLerp(_fnlValCoord3D(_fnl_lib__seed, _fnl_lib_x0, _fnl_lib_y2, _fnl_lib_z2), _fnlValCoord3D(_fnl_lib__seed, _fnl_lib_x1, _fnl_lib_y2, _fnl_lib_z2), _fnlValCoord3D(_fnl_lib__seed, _fnl_lib_x2, _fnl_lib_y2, _fnl_lib_z2), _fnlValCoord3D(_fnl_lib__seed, _fnl_lib_x3, _fnl_lib_y2, _fnl_lib_z2), _fnl_lib_xs),
            _fnlCubicLerp(_fnlValCoord3D(_fnl_lib__seed, _fnl_lib_x0, _fnl_lib_y3, _fnl_lib_z2), _fnlValCoord3D(_fnl_lib__seed, _fnl_lib_x1, _fnl_lib_y3, _fnl_lib_z2), _fnlValCoord3D(_fnl_lib__seed, _fnl_lib_x2, _fnl_lib_y3, _fnl_lib_z2), _fnlValCoord3D(_fnl_lib__seed, _fnl_lib_x3, _fnl_lib_y3, _fnl_lib_z2), _fnl_lib_xs),
            _fnl_lib_ys),
        _fnlCubicLerp(
            _fnlCubicLerp(_fnlValCoord3D(_fnl_lib__seed, _fnl_lib_x0, _fnl_lib_y0, _fnl_lib_z3), _fnlValCoord3D(_fnl_lib__seed, _fnl_lib_x1, _fnl_lib_y0, _fnl_lib_z3), _fnlValCoord3D(_fnl_lib__seed, _fnl_lib_x2, _fnl_lib_y0, _fnl_lib_z3), _fnlValCoord3D(_fnl_lib__seed, _fnl_lib_x3, _fnl_lib_y0, _fnl_lib_z3), _fnl_lib_xs),
            _fnlCubicLerp(_fnlValCoord3D(_fnl_lib__seed, _fnl_lib_x0, _fnl_lib_y1, _fnl_lib_z3), _fnlValCoord3D(_fnl_lib__seed, _fnl_lib_x1, _fnl_lib_y1, _fnl_lib_z3), _fnlValCoord3D(_fnl_lib__seed, _fnl_lib_x2, _fnl_lib_y1, _fnl_lib_z3), _fnlValCoord3D(_fnl_lib__seed, _fnl_lib_x3, _fnl_lib_y1, _fnl_lib_z3), _fnl_lib_xs),
            _fnlCubicLerp(_fnlValCoord3D(_fnl_lib__seed, _fnl_lib_x0, _fnl_lib_y2, _fnl_lib_z3), _fnlValCoord3D(_fnl_lib__seed, _fnl_lib_x1, _fnl_lib_y2, _fnl_lib_z3), _fnlValCoord3D(_fnl_lib__seed, _fnl_lib_x2, _fnl_lib_y2, _fnl_lib_z3), _fnlValCoord3D(_fnl_lib__seed, _fnl_lib_x3, _fnl_lib_y2, _fnl_lib_z3), _fnl_lib_xs),
            _fnlCubicLerp(_fnlValCoord3D(_fnl_lib__seed, _fnl_lib_x0, _fnl_lib_y3, _fnl_lib_z3), _fnlValCoord3D(_fnl_lib__seed, _fnl_lib_x1, _fnl_lib_y3, _fnl_lib_z3), _fnlValCoord3D(_fnl_lib__seed, _fnl_lib_x2, _fnl_lib_y3, _fnl_lib_z3), _fnlValCoord3D(_fnl_lib__seed, _fnl_lib_x3, _fnl_lib_y3, _fnl_lib_z3), _fnl_lib_xs),
            _fnl_lib_ys),
        _fnl_lib_zs) * (1.f / 1.5f * 1.5f * 1.5f);
}



float _fnlSingleValue2D(int _fnl_lib__seed, FNLfloat _fnl_lib__x, FNLfloat _fnl_lib__y)
{
    int _fnl_lib_x0 = int(floor(_fnl_lib__x));
    int _fnl_lib_y0 = int(floor(_fnl_lib__y));

    float _fnl_lib_xs = _fnlInterpHermite(_fnl_lib__x - float(_fnl_lib_x0));
    float _fnl_lib_ys = _fnlInterpHermite(_fnl_lib__y - float(_fnl_lib_y0));

    _fnl_lib_x0 *= PRIME_X;
    _fnl_lib_y0 *= PRIME_Y;
    int _fnl_lib_x1 = _fnl_lib_x0 + PRIME_X;
    int _fnl_lib_y1 = _fnl_lib_y0 + PRIME_Y;

    float _fnl_lib__xf0 = mix(_fnlValCoord2D(_fnl_lib__seed, _fnl_lib_x0, _fnl_lib_y0), _fnlValCoord2D(_fnl_lib__seed, _fnl_lib_x1, _fnl_lib_y0), _fnl_lib_xs);
    float _fnl_lib__xf1 = mix(_fnlValCoord2D(_fnl_lib__seed, _fnl_lib_x0, _fnl_lib_y1), _fnlValCoord2D(_fnl_lib__seed, _fnl_lib_x1, _fnl_lib_y1), _fnl_lib_xs);

    return mix(_fnl_lib__xf0, _fnl_lib__xf1, _fnl_lib_ys);
}

float _fnlSingleValue3D(int _fnl_lib__seed, FNLfloat _fnl_lib__x, FNLfloat _fnl_lib__y, FNLfloat _fnl_lib__z)
{
    int _fnl_lib_x0 = int(floor(_fnl_lib__x));
    int _fnl_lib_y0 = int(floor(_fnl_lib__y));
    int _fnl_lib_z0 = int(floor(_fnl_lib__z));

    float _fnl_lib_xs = _fnlInterpHermite(_fnl_lib__x - float(_fnl_lib_x0));
    float _fnl_lib_ys = _fnlInterpHermite(_fnl_lib__y - float(_fnl_lib_y0));
    float _fnl_lib_zs = _fnlInterpHermite(_fnl_lib__z - float(_fnl_lib_z0));

    _fnl_lib_x0 *= PRIME_X;
    _fnl_lib_y0 *= PRIME_Y;
    _fnl_lib_z0 *= PRIME_Z;
    int _fnl_lib_x1 = _fnl_lib_x0 + PRIME_X;
    int _fnl_lib_y1 = _fnl_lib_y0 + PRIME_Y;
    int _fnl_lib_z1 = _fnl_lib_z0 + PRIME_Z;

    float _fnl_lib__xf00 = mix(_fnlValCoord3D(_fnl_lib__seed, _fnl_lib_x0, _fnl_lib_y0, _fnl_lib_z0), _fnlValCoord3D(_fnl_lib__seed, _fnl_lib_x1, _fnl_lib_y0, _fnl_lib_z0), _fnl_lib_xs);
    float _fnl_lib__xf10 = mix(_fnlValCoord3D(_fnl_lib__seed, _fnl_lib_x0, _fnl_lib_y1, _fnl_lib_z0), _fnlValCoord3D(_fnl_lib__seed, _fnl_lib_x1, _fnl_lib_y1, _fnl_lib_z0), _fnl_lib_xs);
    float _fnl_lib__xf01 = mix(_fnlValCoord3D(_fnl_lib__seed, _fnl_lib_x0, _fnl_lib_y0, _fnl_lib_z1), _fnlValCoord3D(_fnl_lib__seed, _fnl_lib_x1, _fnl_lib_y0, _fnl_lib_z1), _fnl_lib_xs);
    float _fnl_lib__xf11 = mix(_fnlValCoord3D(_fnl_lib__seed, _fnl_lib_x0, _fnl_lib_y1, _fnl_lib_z1), _fnlValCoord3D(_fnl_lib__seed, _fnl_lib_x1, _fnl_lib_y1, _fnl_lib_z1), _fnl_lib_xs);

    float _fnl_lib__yf0 = mix(_fnl_lib__xf00, _fnl_lib__xf10, _fnl_lib_ys);
    float _fnl_lib__yf1 = mix(_fnl_lib__xf01, _fnl_lib__xf11, _fnl_lib_ys);

    return mix(_fnl_lib__yf0, _fnl_lib__yf1, _fnl_lib_zs);
}


float _fnlGenNoiseSingle2D(fnl_state _fnl_lib__state, int _fnl_lib__seed, FNLfloat _fnl_lib__x, FNLfloat _fnl_lib__y)
{
    switch (_fnl_lib__state.noise_type)
    {
        case FNL_NOISE_OPENSIMPLEX2:
            return _fnlSingleSimplex2D(_fnl_lib__seed, _fnl_lib__x, _fnl_lib__y);
        case FNL_NOISE_OPENSIMPLEX2S:
            return _fnlSingleOpenSimplex2S2D(_fnl_lib__seed, _fnl_lib__x, _fnl_lib__y);
        case FNL_NOISE_CELLULAR:
            return _fnlSingleCellular2D(_fnl_lib__state, _fnl_lib__seed, _fnl_lib__x, _fnl_lib__y);
        case FNL_NOISE_PERLIN:
            return _fnlSinglePerlin2D(_fnl_lib__seed, _fnl_lib__x, _fnl_lib__y);
        case FNL_NOISE_VALUE_CUBIC:
            return _fnlSingleValueCubic2D(_fnl_lib__seed, _fnl_lib__x, _fnl_lib__y);
        case FNL_NOISE_VALUE:
            return _fnlSingleValue2D(_fnl_lib__seed, _fnl_lib__x, _fnl_lib__y);
        default:
            return 0.f;
    }
}

float _fnlGenNoiseSingle3D(fnl_state _fnl_lib__state, int _fnl_lib__seed, FNLfloat _fnl_lib__x, FNLfloat _fnl_lib__y, FNLfloat _fnl_lib__z)
{
    switch (_fnl_lib__state.noise_type)
    {
        case FNL_NOISE_OPENSIMPLEX2:
            return _fnlSingleOpenSimplex23D(_fnl_lib__seed, _fnl_lib__x, _fnl_lib__y, _fnl_lib__z);
        case FNL_NOISE_OPENSIMPLEX2S:
            return _fnlSingleOpenSimplex2S3D(_fnl_lib__seed, _fnl_lib__x, _fnl_lib__y, _fnl_lib__z);
        case FNL_NOISE_CELLULAR:
            return _fnlSingleCellular3D(_fnl_lib__state, _fnl_lib__seed, _fnl_lib__x, _fnl_lib__y, _fnl_lib__z);
        case FNL_NOISE_PERLIN:
            return _fnlSinglePerlin3D(_fnl_lib__seed, _fnl_lib__x, _fnl_lib__y, _fnl_lib__z);
        case FNL_NOISE_VALUE_CUBIC:
            return _fnlSingleValueCubic3D(_fnl_lib__seed, _fnl_lib__x, _fnl_lib__y, _fnl_lib__z);
        case FNL_NOISE_VALUE:
            return _fnlSingleValue3D(_fnl_lib__seed, _fnl_lib__x, _fnl_lib__y, _fnl_lib__z);
        default:
            return 0.f;
    }
}


float _fnlGenFractalFBM2D(fnl_state _fnl_lib__state, FNLfloat _fnl_lib__x, FNLfloat _fnl_lib__y)
{
    int _fnl_lib__seed =

 _fnl_lib__state.seed;

    float _fnl_lib__sum = 0.f;
    float _fnl_lib__amp = _fnlCalculateFractalBounding(_fnl_lib__state);

    for (int _fnl_lib_i = 0; _fnl_lib_i < _fnl_lib__state.octaves; _fnl_lib_i++)
    {
        float _fnl_lib__noise = _fnlGenNoiseSingle2D(_fnl_lib__state, _fnl_lib__seed++, _fnl_lib__x, _fnl_lib__y);
        _fnl_lib__sum += _fnl_lib__noise * _fnl_lib__amp;
        _fnl_lib__amp *= mix(1.f, min(_fnl_lib__noise + 1.f, 2.f) * 0.5f, _fnl_lib__state.weighted_strength);

        _fnl_lib__x *= _fnl_lib__state.lacunarity;
        _fnl_lib__y *= _fnl_lib__state.lacunarity;
        _fnl_lib__amp *= _fnl_lib__state.gain;
    }

    return _fnl_lib__sum;
}

float _fnlGenFractalFBM3D(fnl_state _fnl_lib__state, FNLfloat _fnl_lib__x, FNLfloat _fnl_lib__y, FNLfloat _fnl_lib__z)
{
    int _fnl_lib__seed =

 _fnl_lib__state.seed;

    float _fnl_lib__sum = 0.f;
    float _fnl_lib__amp = _fnlCalculateFractalBounding(_fnl_lib__state);

    for (int _fnl_lib_i = 0; _fnl_lib_i < _fnl_lib__state.octaves; _fnl_lib_i++)
    {
        float _fnl_lib__noise = _fnlGenNoiseSingle3D(_fnl_lib__state, _fnl_lib__seed++, _fnl_lib__x, _fnl_lib__y, _fnl_lib__z);
        _fnl_lib__sum += _fnl_lib__noise * _fnl_lib__amp;
        _fnl_lib__amp *= mix(1.f, (_fnl_lib__noise + 1.f) * 0.5f, _fnl_lib__state.weighted_strength);

        _fnl_lib__x *= _fnl_lib__state.lacunarity;
        _fnl_lib__y *= _fnl_lib__state.lacunarity;
        _fnl_lib__z *= _fnl_lib__state.lacunarity;
        _fnl_lib__amp *= _fnl_lib__state.gain;
    }

    return _fnl_lib__sum;
}


float _fnlGenFractalRidged2D(fnl_state _fnl_lib__state, FNLfloat _fnl_lib__x, FNLfloat _fnl_lib__y)
{
    int _fnl_lib__seed =

 _fnl_lib__state.seed;

    float _fnl_lib__sum = 0.f;
    float _fnl_lib__amp = _fnlCalculateFractalBounding(_fnl_lib__state);

    for (int _fnl_lib_i = 0; _fnl_lib_i < _fnl_lib__state.octaves; _fnl_lib_i++)
    {
        float _fnl_lib__noise = abs(_fnlGenNoiseSingle2D(_fnl_lib__state, _fnl_lib__seed++, _fnl_lib__x, _fnl_lib__y));
        _fnl_lib__sum += (_fnl_lib__noise * -2.f + 1.f) * _fnl_lib__amp;
        _fnl_lib__amp *= mix(1.f, 1.f - _fnl_lib__noise, _fnl_lib__state.weighted_strength);

        _fnl_lib__x *= _fnl_lib__state.lacunarity;
        _fnl_lib__y *= _fnl_lib__state.lacunarity;
        _fnl_lib__amp *= _fnl_lib__state.gain;
    }

    return _fnl_lib__sum;
}


float _fnlGenFractalRidged3D(fnl_state _fnl_lib__state, FNLfloat _fnl_lib__x, FNLfloat _fnl_lib__y, FNLfloat _fnl_lib__z)
{
    int _fnl_lib__seed =

 _fnl_lib__state.seed;

    float _fnl_lib__sum = 0.f;
    float _fnl_lib__amp = _fnlCalculateFractalBounding(_fnl_lib__state);

    for (int _fnl_lib_i = 0; _fnl_lib_i < _fnl_lib__state.octaves; _fnl_lib_i++)
    {
        float _fnl_lib__noise = abs(_fnlGenNoiseSingle3D(_fnl_lib__state, _fnl_lib__seed++, _fnl_lib__x, _fnl_lib__y, _fnl_lib__z));
        _fnl_lib__sum += (_fnl_lib__noise * -2.f + 1.f) * _fnl_lib__amp;
        _fnl_lib__amp *= mix(1.f, 1.f - _fnl_lib__noise, _fnl_lib__state.weighted_strength);

        _fnl_lib__x *= _fnl_lib__state.lacunarity;
        _fnl_lib__y *= _fnl_lib__state.lacunarity;
        _fnl_lib__z *= _fnl_lib__state.lacunarity;
        _fnl_lib__amp *= _fnl_lib__state.gain;
    }

    return _fnl_lib__sum;
}


float _fnlGenFractalPingPong2D(fnl_state _fnl_lib__state, FNLfloat _fnl_lib__x, FNLfloat _fnl_lib__y)
{
    int _fnl_lib__seed =

 _fnl_lib__state.seed;

    float _fnl_lib__sum = 0.f;
    float _fnl_lib__amp = _fnlCalculateFractalBounding(_fnl_lib__state);

    for (int _fnl_lib_i = 0; _fnl_lib_i < _fnl_lib__state.octaves; _fnl_lib_i++)
    {
        float _fnl_lib__noise = _fnlPingPong((_fnlGenNoiseSingle2D(_fnl_lib__state, _fnl_lib__seed++, _fnl_lib__x, _fnl_lib__y) + 1.f) * _fnl_lib__state.ping_pong_strength);
        _fnl_lib__sum += (_fnl_lib__noise - 0.5f) * 2.f * _fnl_lib__amp;
        _fnl_lib__amp *= mix(1.f, _fnl_lib__noise, _fnl_lib__state.weighted_strength);

        _fnl_lib__x *= _fnl_lib__state.lacunarity;
        _fnl_lib__y *= _fnl_lib__state.lacunarity;
        _fnl_lib__amp *= _fnl_lib__state.gain;
    }

    return _fnl_lib__sum;
}

float _fnlGenFractalPingPong3D(fnl_state _fnl_lib__state, FNLfloat _fnl_lib__x, FNLfloat _fnl_lib__y, FNLfloat _fnl_lib__z)
{
    int _fnl_lib__seed =

 _fnl_lib__state.seed;

    float _fnl_lib__sum = 0.f;
    float _fnl_lib__amp = _fnlCalculateFractalBounding(_fnl_lib__state);

    for (int _fnl_lib_i = 0; _fnl_lib_i < _fnl_lib__state.octaves; _fnl_lib_i++)
    {
        float _fnl_lib__noise = _fnlPingPong((_fnlGenNoiseSingle3D(_fnl_lib__state, _fnl_lib__seed++, _fnl_lib__x, _fnl_lib__y, _fnl_lib__z) + 1.f) * _fnl_lib__state.ping_pong_strength);
        _fnl_lib__sum += (_fnl_lib__noise - 0.5f) * 2.f * _fnl_lib__amp;
        _fnl_lib__amp *= mix(1.f, _fnl_lib__noise, _fnl_lib__state.weighted_strength);

        _fnl_lib__x *= _fnl_lib__state.lacunarity;
        _fnl_lib__y *= _fnl_lib__state.lacunarity;
        _fnl_lib__z *= _fnl_lib__state.lacunarity;
        _fnl_lib__amp *= _fnl_lib__state.gain;
    }

    return _fnl_lib__sum;
}




void _fnlSingleDomainWarpSimplexGradient(int _fnl_lib__seed, float _fnl_lib__warpAmp, float _fnl_lib__frequency, FNLfloat _fnl_lib__x, FNLfloat _fnl_lib__y, inout FNLfloat _fnl_lib__xr, inout FNLfloat _fnl_lib__yr, bool _fnl_lib__outGradOnly)
{
    const float _fnl_lib__SQRT3 = 1.7320508075688772935274463415059;
    const float _fnl_lib_G2 = (3.f - _fnl_lib__SQRT3) / 6.f;

    _fnl_lib__x *= _fnl_lib__frequency;
    _fnl_lib__y *= _fnl_lib__frequency;







    int _fnl_lib_i = int(floor(_fnl_lib__x));
    int _fnl_lib_j = int(floor(_fnl_lib__y));
    float _fnl_lib_xi = _fnl_lib__x - float(_fnl_lib_i);
    float _fnl_lib_yi = _fnl_lib__y - float(_fnl_lib_j);

    float _fnl_lib__t = (_fnl_lib_xi + _fnl_lib_yi) * _fnl_lib_G2;
    float _fnl_lib_x0 = _fnl_lib_xi - _fnl_lib__t;
    float _fnl_lib_y0 = _fnl_lib_yi - _fnl_lib__t;

    _fnl_lib_i *= PRIME_X;
    _fnl_lib_j *= PRIME_Y;

    float _fnl_lib__vx, _fnl_lib__vy;
    _fnl_lib__vx = _fnl_lib__vy = 0.f;

    float _fnl_lib__a = 0.5f - _fnl_lib_x0 * _fnl_lib_x0 - _fnl_lib_y0 * _fnl_lib_y0;
    if (_fnl_lib__a > 0.f)
    {
        float _fnl_lib__aaaa = (_fnl_lib__a * _fnl_lib__a) * (_fnl_lib__a * _fnl_lib__a);
        float _fnl_lib__xo, _fnl_lib__yo;
        if (_fnl_lib__outGradOnly)
  {
            _fnlGradCoordOut2D(_fnl_lib__seed, _fnl_lib_i, _fnl_lib_j, _fnl_lib__xo, _fnl_lib__yo);
  }
        else
        {
   _fnlGradCoordDual2D(_fnl_lib__seed, _fnl_lib_i, _fnl_lib_j, _fnl_lib_x0, _fnl_lib_y0, _fnl_lib__xo, _fnl_lib__yo);
  }
        _fnl_lib__vx += _fnl_lib__aaaa * _fnl_lib__xo;
        _fnl_lib__vy += _fnl_lib__aaaa * _fnl_lib__yo;
    }

    float _fnl_lib__c = (2.f * (1.f - 2.f * _fnl_lib_G2) * (1.f / _fnl_lib_G2 - 2.f)) * _fnl_lib__t + ((-2.f * (1.f - 2.f * _fnl_lib_G2) * (1.f - 2.f * _fnl_lib_G2)) + _fnl_lib__a);
    if (_fnl_lib__c > 0.f)
    {
        float _fnl_lib_x2 = _fnl_lib_x0 + (2.f * _fnl_lib_G2 - 1.f);
        float _fnl_lib_y2 = _fnl_lib_y0 + (2.f * _fnl_lib_G2 - 1.f);
        float _fnl_lib__cccc = (_fnl_lib__c * _fnl_lib__c) * (_fnl_lib__c * _fnl_lib__c);
        float _fnl_lib__xo, _fnl_lib__yo;
        if (_fnl_lib__outGradOnly)
  {
            _fnlGradCoordOut2D(_fnl_lib__seed, _fnl_lib_i + PRIME_X, _fnl_lib_j + PRIME_Y, _fnl_lib__xo, _fnl_lib__yo);
  }
        else
  {
            _fnlGradCoordDual2D(_fnl_lib__seed, _fnl_lib_i + PRIME_X, _fnl_lib_j + PRIME_Y, _fnl_lib_x2, _fnl_lib_y2, _fnl_lib__xo, _fnl_lib__yo);
  }
        _fnl_lib__vx += _fnl_lib__cccc * _fnl_lib__xo;
        _fnl_lib__vy += _fnl_lib__cccc * _fnl_lib__yo;
    }

    if (_fnl_lib_y0 > _fnl_lib_x0)
    {
        float _fnl_lib_x1 = _fnl_lib_x0 + _fnl_lib_G2;
        float _fnl_lib_y1 = _fnl_lib_y0 + (_fnl_lib_G2 - 1.f);
        float _fnl_lib__b = 0.5f - _fnl_lib_x1 * _fnl_lib_x1 - _fnl_lib_y1 * _fnl_lib_y1;
        if (_fnl_lib__b > 0.f)
        {
            float _fnl_lib__bbbb = (_fnl_lib__b * _fnl_lib__b) * (_fnl_lib__b * _fnl_lib__b);
            float _fnl_lib__xo, _fnl_lib__yo;
            if (_fnl_lib__outGradOnly)
   {
                _fnlGradCoordOut2D(_fnl_lib__seed, _fnl_lib_i, _fnl_lib_j + PRIME_Y, _fnl_lib__xo, _fnl_lib__yo);
   }
            else
   {
                _fnlGradCoordDual2D(_fnl_lib__seed, _fnl_lib_i, _fnl_lib_j + PRIME_Y, _fnl_lib_x1, _fnl_lib_y1, _fnl_lib__xo, _fnl_lib__yo);
   }
            _fnl_lib__vx += _fnl_lib__bbbb * _fnl_lib__xo;
            _fnl_lib__vy += _fnl_lib__bbbb * _fnl_lib__yo;
        }
    }
    else
    {
        float _fnl_lib_x1 = _fnl_lib_x0 + (_fnl_lib_G2 - 1.f);
        float _fnl_lib_y1 = _fnl_lib_y0 + _fnl_lib_G2;
        float _fnl_lib__b = 0.5f - _fnl_lib_x1 * _fnl_lib_x1 - _fnl_lib_y1 * _fnl_lib_y1;
        if (_fnl_lib__b > 0.f)
        {
            float _fnl_lib__bbbb = (_fnl_lib__b * _fnl_lib__b) * (_fnl_lib__b * _fnl_lib__b);
            float _fnl_lib__xo, _fnl_lib__yo;
            if (_fnl_lib__outGradOnly)
   {
                _fnlGradCoordOut2D(_fnl_lib__seed, _fnl_lib_i + PRIME_X, _fnl_lib_j, _fnl_lib__xo, _fnl_lib__yo);
   }
            else
            {
    _fnlGradCoordDual2D(_fnl_lib__seed, _fnl_lib_i + PRIME_X, _fnl_lib_j, _fnl_lib_x1, _fnl_lib_y1, _fnl_lib__xo, _fnl_lib__yo);
   }
            _fnl_lib__vx += _fnl_lib__bbbb * _fnl_lib__xo;
            _fnl_lib__vy += _fnl_lib__bbbb * _fnl_lib__yo;
        }
    }

    _fnl_lib__xr += _fnl_lib__vx * _fnl_lib__warpAmp;
    _fnl_lib__yr += _fnl_lib__vy * _fnl_lib__warpAmp;
}
void _fnlSingleDomainWarpOpenSimplex2Gradient(int _fnl_lib__seed, float _fnl_lib__warpAmp, float _fnl_lib__frequency, FNLfloat _fnl_lib__x, FNLfloat _fnl_lib__y, FNLfloat _fnl_lib__z, inout FNLfloat _fnl_lib__xr, inout FNLfloat _fnl_lib__yr, inout FNLfloat _fnl_lib__zr, bool _fnl_lib__outGradOnly)
{
    _fnl_lib__x *= _fnl_lib__frequency;
    _fnl_lib__y *= _fnl_lib__frequency;
    _fnl_lib__z *= _fnl_lib__frequency;







    int _fnl_lib_i = int(round(_fnl_lib__x));
    int _fnl_lib_j = int(round(_fnl_lib__y));
    int _fnl_lib_k = int(round(_fnl_lib__z));
    float _fnl_lib_x0 = _fnl_lib__x - float(_fnl_lib_i);
    float _fnl_lib_y0 = _fnl_lib__y - float(_fnl_lib_j);
    float _fnl_lib_z0 = _fnl_lib__z - float(_fnl_lib_k);

    int _fnl_float_xNSign = int(-_fnl_lib_x0 - 1.f) | 1;
    int _fnl_float_yNSign = int(-_fnl_lib_y0 - 1.f) | 1;
    int _fnl_float_zNSign = int(-_fnl_lib_z0 - 1.f) | 1;

    float _fnl_float_ax0 = float(_fnl_float_xNSign) * -_fnl_lib_x0;
    float _fnl_float_ay0 = float(_fnl_float_yNSign) * -_fnl_lib_y0;
    float _fnl_float_az0 = float(_fnl_float_zNSign) * -_fnl_lib_z0;

    _fnl_lib_i *= PRIME_X;
    _fnl_lib_j *= PRIME_Y;
    _fnl_lib_k *= PRIME_Z;

    float _fnl_lib__vx, _fnl_lib__vy, _fnl_lib__vz;
    _fnl_lib__vx = _fnl_lib__vy = _fnl_lib__vz = 0.f;

    float _fnl_lib__a = (0.6f - _fnl_lib_x0 * _fnl_lib_x0) - (_fnl_lib_y0 * _fnl_lib_y0 + _fnl_lib_z0 * _fnl_lib_z0);
    for (int _fnl_lib_l = 0; _fnl_lib_l < 2; _fnl_lib_l++)
    {
        if (_fnl_lib__a > 0.f)
        {
            float _fnl_lib__aaaa = (_fnl_lib__a * _fnl_lib__a) * (_fnl_lib__a * _fnl_lib__a);
            float _fnl_lib__xo, _fnl_lib__yo, _fnl_lib__zo;
            if (_fnl_lib__outGradOnly)
   {
                _fnlGradCoordOut3D(_fnl_lib__seed, _fnl_lib_i, _fnl_lib_j, _fnl_lib_k, _fnl_lib__xo, _fnl_lib__yo, _fnl_lib__zo);
   }
            else
   {
                _fnlGradCoordDual3D(_fnl_lib__seed, _fnl_lib_i, _fnl_lib_j, _fnl_lib_k, _fnl_lib_x0, _fnl_lib_y0, _fnl_lib_z0, _fnl_lib__xo, _fnl_lib__yo, _fnl_lib__zo);
   }
            _fnl_lib__vx += _fnl_lib__aaaa * _fnl_lib__xo;
            _fnl_lib__vy += _fnl_lib__aaaa * _fnl_lib__yo;
            _fnl_lib__vz += _fnl_lib__aaaa * _fnl_lib__zo;
        }

        float _fnl_lib__b = _fnl_lib__a + 1.f;
        int _fnl_lib_i1 = _fnl_lib_i;
        int _fnl_lib_j1 = _fnl_lib_j;
        int _fnl_lib_k1 = _fnl_lib_k;
        float _fnl_lib_x1 = _fnl_lib_x0;
        float _fnl_lib_y1 = _fnl_lib_y0;
        float _fnl_lib_z1 = _fnl_lib_z0;
        if (_fnl_float_ax0 >= _fnl_float_ay0 && _fnl_float_ax0 >= _fnl_float_az0)
        {
            _fnl_lib_x1 += float(_fnl_float_xNSign);
            _fnl_lib__b -= float(_fnl_float_xNSign) * 2.f * _fnl_lib_x1;
            _fnl_lib_i1 -= _fnl_float_xNSign * PRIME_X;
        }
        else if (_fnl_float_ay0 > _fnl_float_ax0 && _fnl_float_ay0 >= _fnl_float_az0)
        {
            _fnl_lib_y1 += float(_fnl_float_yNSign);
            _fnl_lib__b -= float(_fnl_float_yNSign) * 2.f * _fnl_lib_y1;
            _fnl_lib_j1 -= _fnl_float_yNSign * PRIME_Y;
        }
        else
        {
            _fnl_lib_z1 += float(_fnl_float_zNSign);
            _fnl_lib__b -= float(_fnl_float_zNSign) * 2.f * _fnl_lib_z1;
            _fnl_lib_k1 -= _fnl_float_zNSign * PRIME_Z;
        }

        if (_fnl_lib__b > 0.f)
        {
            float _fnl_lib__bbbb = (_fnl_lib__b * _fnl_lib__b) * (_fnl_lib__b * _fnl_lib__b);
            float _fnl_lib__xo, _fnl_lib__yo, _fnl_lib__zo;
            if (_fnl_lib__outGradOnly)
   {
                _fnlGradCoordOut3D(_fnl_lib__seed, _fnl_lib_i1, _fnl_lib_j1, _fnl_lib_k1, _fnl_lib__xo, _fnl_lib__yo, _fnl_lib__zo);
   }
            else
   {
                _fnlGradCoordDual3D(_fnl_lib__seed, _fnl_lib_i1, _fnl_lib_j1, _fnl_lib_k1, _fnl_lib_x1, _fnl_lib_y1, _fnl_lib_z1, _fnl_lib__xo, _fnl_lib__yo, _fnl_lib__zo);
   }
            _fnl_lib__vx += _fnl_lib__bbbb * _fnl_lib__xo;
            _fnl_lib__vy += _fnl_lib__bbbb * _fnl_lib__yo;
            _fnl_lib__vz += _fnl_lib__bbbb * _fnl_lib__zo;
        }

        if (_fnl_lib_l == 1) break;

        _fnl_float_ax0 = 0.5f - _fnl_float_ax0;
        _fnl_float_ay0 = 0.5f - _fnl_float_ay0;
        _fnl_float_az0 = 0.5f - _fnl_float_az0;

        _fnl_lib_x0 = float(_fnl_float_xNSign) * _fnl_float_ax0;
        _fnl_lib_y0 = float(_fnl_float_yNSign) * _fnl_float_ay0;
        _fnl_lib_z0 = float(_fnl_float_zNSign) * _fnl_float_az0;

        _fnl_lib__a += (0.75f - _fnl_float_ax0) - (_fnl_float_ay0 + _fnl_float_az0);

        _fnl_lib_i += (_fnl_float_xNSign >> 1) & PRIME_X;
        _fnl_lib_j += (_fnl_float_yNSign >> 1) & PRIME_Y;
        _fnl_lib_k += (_fnl_float_zNSign >> 1) & PRIME_Z;

        _fnl_float_xNSign = -_fnl_float_xNSign;
        _fnl_float_yNSign = -_fnl_float_yNSign;
        _fnl_float_zNSign = -_fnl_float_zNSign;

        _fnl_lib__seed += 1293373;
    }

    _fnl_lib__xr += _fnl_lib__vx * _fnl_lib__warpAmp;
    _fnl_lib__yr += _fnl_lib__vy * _fnl_lib__warpAmp;
    _fnl_lib__zr += _fnl_lib__vz * _fnl_lib__warpAmp;
}



void _fnlSingleDomainWarpBasicGrid2D(int _fnl_lib__seed, float _fnl_lib__warpAmp, float _fnl_lib__frequency, FNLfloat _fnl_lib__x, FNLfloat _fnl_lib__y, inout FNLfloat _fnl_lib__xp, inout FNLfloat _fnl_lib__yp)
{
    FNLfloat xf = _fnl_lib__x * _fnl_lib__frequency;
    FNLfloat yf = _fnl_lib__y * _fnl_lib__frequency;

    int _fnl_lib_x0 = int(floor(xf));
    int _fnl_lib_y0 = int(floor(yf));

    float _fnl_lib_xs = _fnlInterpHermite(xf - float(_fnl_lib_x0));
    float _fnl_lib_ys = _fnlInterpHermite(yf - float(_fnl_lib_y0));

    _fnl_lib_x0 *= PRIME_X;
    _fnl_lib_y0 *= PRIME_Y;
    int _fnl_lib_x1 = _fnl_lib_x0 + PRIME_X;
    int _fnl_lib_y1 = _fnl_lib_y0 + PRIME_Y;

    int _fnl_lib__idx0 = _fnlHash2D(_fnl_lib__seed, _fnl_lib_x0, _fnl_lib_y0) & (255 << 1);
    int _fnl_lib__idx1 = _fnlHash2D(_fnl_lib__seed, _fnl_lib_x1, _fnl_lib_y0) & (255 << 1);

    float _fnl_lib__lx0x = mix(_fnl_lib__RAND_VECS_2D[_fnl_lib__idx0], _fnl_lib__RAND_VECS_2D[_fnl_lib__idx1], _fnl_lib_xs);
    float _fnl_lib__ly0x = mix(_fnl_lib__RAND_VECS_2D[_fnl_lib__idx0 | 1], _fnl_lib__RAND_VECS_2D[_fnl_lib__idx1 | 1], _fnl_lib_xs);

    _fnl_lib__idx0 = _fnlHash2D(_fnl_lib__seed, _fnl_lib_x0, _fnl_lib_y1) & (255 << 1);
    _fnl_lib__idx1 = _fnlHash2D(_fnl_lib__seed, _fnl_lib_x1, _fnl_lib_y1) & (255 << 1);

    float _fnl_lib__lx1x = mix(_fnl_lib__RAND_VECS_2D[_fnl_lib__idx0], _fnl_lib__RAND_VECS_2D[_fnl_lib__idx1], _fnl_lib_xs);
    float _fnl_lib__ly1x = mix(_fnl_lib__RAND_VECS_2D[_fnl_lib__idx0 | 1], _fnl_lib__RAND_VECS_2D[_fnl_lib__idx1 | 1], _fnl_lib_xs);

    _fnl_lib__xp += mix(_fnl_lib__lx0x, _fnl_lib__lx1x, _fnl_lib_ys) * _fnl_lib__warpAmp;
    _fnl_lib__yp += mix(_fnl_lib__ly0x, _fnl_lib__ly1x, _fnl_lib_ys) * _fnl_lib__warpAmp;
}

void _fnlSingleDomainWarpBasicGrid3D(int _fnl_lib__seed, float _fnl_lib__warpAmp, float _fnl_lib__frequency, FNLfloat _fnl_lib__x, FNLfloat _fnl_lib__y, FNLfloat _fnl_lib__z, inout FNLfloat _fnl_lib__xp, inout FNLfloat _fnl_lib__yp, inout FNLfloat _fnl_lib__zp)
{
    FNLfloat xf = _fnl_lib__x * _fnl_lib__frequency;
    FNLfloat yf = _fnl_lib__y * _fnl_lib__frequency;
    FNLfloat zf = _fnl_lib__z * _fnl_lib__frequency;

    int _fnl_lib_x0 = int(floor(xf));
    int _fnl_lib_y0 = int(floor(yf));
    int _fnl_lib_z0 = int(floor(zf));

    float _fnl_lib_xs = _fnlInterpHermite(xf - float(_fnl_lib_x0));
    float _fnl_lib_ys = _fnlInterpHermite(yf - float(_fnl_lib_y0));
    float _fnl_lib_zs = _fnlInterpHermite(zf - float(_fnl_lib_z0));

    _fnl_lib_x0 *= PRIME_X;
    _fnl_lib_y0 *= PRIME_Y;
    _fnl_lib_z0 *= PRIME_Z;
    int _fnl_lib_x1 = _fnl_lib_x0 + PRIME_X;
    int _fnl_lib_y1 = _fnl_lib_y0 + PRIME_Y;
    int _fnl_lib_z1 = _fnl_lib_z0 + PRIME_Z;

    int _fnl_lib__idx0 = _fnlHash3D(_fnl_lib__seed, _fnl_lib_x0, _fnl_lib_y0, _fnl_lib_z0) & (255 << 2);
    int _fnl_lib__idx1 = _fnlHash3D(_fnl_lib__seed, _fnl_lib_x1, _fnl_lib_y0, _fnl_lib_z0) & (255 << 2);

    float _fnl_lib__lx0x = mix(_fnl_lib__RAND_VECS_3D[_fnl_lib__idx0], _fnl_lib__RAND_VECS_3D[_fnl_lib__idx1], _fnl_lib_xs);
    float _fnl_lib__ly0x = mix(_fnl_lib__RAND_VECS_3D[_fnl_lib__idx0 | 1], _fnl_lib__RAND_VECS_3D[_fnl_lib__idx1 | 1], _fnl_lib_xs);
    float _fnl_lib__lz0x = mix(_fnl_lib__RAND_VECS_3D[_fnl_lib__idx0 | 2], _fnl_lib__RAND_VECS_3D[_fnl_lib__idx1 | 2], _fnl_lib_xs);

    _fnl_lib__idx0 = _fnlHash3D(_fnl_lib__seed, _fnl_lib_x0, _fnl_lib_y1, _fnl_lib_z0) & (255 << 2);
    _fnl_lib__idx1 = _fnlHash3D(_fnl_lib__seed, _fnl_lib_x1, _fnl_lib_y1, _fnl_lib_z0) & (255 << 2);

    float _fnl_lib__lx1x = mix(_fnl_lib__RAND_VECS_3D[_fnl_lib__idx0], _fnl_lib__RAND_VECS_3D[_fnl_lib__idx1], _fnl_lib_xs);
    float _fnl_lib__ly1x = mix(_fnl_lib__RAND_VECS_3D[_fnl_lib__idx0 | 1], _fnl_lib__RAND_VECS_3D[_fnl_lib__idx1 | 1], _fnl_lib_xs);
    float _fnl_lib__lz1x = mix(_fnl_lib__RAND_VECS_3D[_fnl_lib__idx0 | 2], _fnl_lib__RAND_VECS_3D[_fnl_lib__idx1 | 2], _fnl_lib_xs);

    float _fnl_lib__lx0y = mix(_fnl_lib__lx0x, _fnl_lib__lx1x, _fnl_lib_ys);
    float _fnl_lib__ly0y = mix(_fnl_lib__ly0x, _fnl_lib__ly1x, _fnl_lib_ys);
    float _fnl_lib__lz0y = mix(_fnl_lib__lz0x, _fnl_lib__lz1x, _fnl_lib_ys);

    _fnl_lib__idx0 = _fnlHash3D(_fnl_lib__seed, _fnl_lib_x0, _fnl_lib_y0, _fnl_lib_z1) & (255 << 2);
    _fnl_lib__idx1 = _fnlHash3D(_fnl_lib__seed, _fnl_lib_x1, _fnl_lib_y0, _fnl_lib_z1) & (255 << 2);

    _fnl_lib__lx0x = mix(_fnl_lib__RAND_VECS_3D[_fnl_lib__idx0], _fnl_lib__RAND_VECS_3D[_fnl_lib__idx1], _fnl_lib_xs);
    _fnl_lib__ly0x = mix(_fnl_lib__RAND_VECS_3D[_fnl_lib__idx0 | 1], _fnl_lib__RAND_VECS_3D[_fnl_lib__idx1 | 1], _fnl_lib_xs);
    _fnl_lib__lz0x = mix(_fnl_lib__RAND_VECS_3D[_fnl_lib__idx0 | 2], _fnl_lib__RAND_VECS_3D[_fnl_lib__idx1 | 2], _fnl_lib_xs);

    _fnl_lib__idx0 = _fnlHash3D(_fnl_lib__seed, _fnl_lib_x0, _fnl_lib_y1, _fnl_lib_z1) & (255 << 2);
    _fnl_lib__idx1 = _fnlHash3D(_fnl_lib__seed, _fnl_lib_x1, _fnl_lib_y1, _fnl_lib_z1) & (255 << 2);

    _fnl_lib__lx1x = mix(_fnl_lib__RAND_VECS_3D[_fnl_lib__idx0], _fnl_lib__RAND_VECS_3D[_fnl_lib__idx1], _fnl_lib_xs);
    _fnl_lib__ly1x = mix(_fnl_lib__RAND_VECS_3D[_fnl_lib__idx0 | 1], _fnl_lib__RAND_VECS_3D[_fnl_lib__idx1 | 1], _fnl_lib_xs);
    _fnl_lib__lz1x = mix(_fnl_lib__RAND_VECS_3D[_fnl_lib__idx0 | 2], _fnl_lib__RAND_VECS_3D[_fnl_lib__idx1 | 2], _fnl_lib_xs);

    _fnl_lib__xp += mix(_fnl_lib__lx0y, mix(_fnl_lib__lx0x, _fnl_lib__lx1x, _fnl_lib_ys), _fnl_lib_zs) * _fnl_lib__warpAmp;
    _fnl_lib__yp += mix(_fnl_lib__ly0y, mix(_fnl_lib__ly0x, _fnl_lib__ly1x, _fnl_lib_ys), _fnl_lib_zs) * _fnl_lib__warpAmp;
    _fnl_lib__zp += mix(_fnl_lib__lz0y, mix(_fnl_lib__lz0x, _fnl_lib__lz1x, _fnl_lib_ys), _fnl_lib_zs) * _fnl_lib__warpAmp;
}


void _fnlDoSingleDomainWarp2D(fnl_state _fnl_lib__state, int _fnl_lib__seed, float _fnl_lib__amp, float _fnl_lib__freq, FNLfloat _fnl_lib__x, FNLfloat _fnl_lib__y, inout FNLfloat _fnl_lib__xp, inout FNLfloat _fnl_lib__yp)
{
    switch (_fnl_lib__state.domain_warp_type)
    {
    case FNL_DOMAIN_WARP_OPENSIMPLEX2:
        _fnlSingleDomainWarpSimplexGradient(_fnl_lib__seed, _fnl_lib__amp * 38.283687591552734375, _fnl_lib__freq, _fnl_lib__x, _fnl_lib__y, _fnl_lib__xp, _fnl_lib__yp, false);
        break;
    case FNL_DOMAIN_WARP_OPENSIMPLEX2_REDUCED:
        _fnlSingleDomainWarpSimplexGradient(_fnl_lib__seed, _fnl_lib__amp * 16.f, _fnl_lib__freq, _fnl_lib__x, _fnl_lib__y, _fnl_lib__xp, _fnl_lib__yp, true);
        break;
    case FNL_DOMAIN_WARP_BASICGRID:
        _fnlSingleDomainWarpBasicGrid2D(_fnl_lib__seed, _fnl_lib__amp, _fnl_lib__freq, _fnl_lib__x, _fnl_lib__y, _fnl_lib__xp, _fnl_lib__yp);
        break;
    }
}

void _fnlDoSingleDomainWarp3D(fnl_state _fnl_lib__state, int _fnl_lib__seed, float _fnl_lib__amp, float _fnl_lib__freq, FNLfloat _fnl_lib__x, FNLfloat _fnl_lib__y, FNLfloat _fnl_lib__z, inout FNLfloat _fnl_lib__xp, inout FNLfloat _fnl_lib__yp, inout FNLfloat _fnl_lib__zp)
{
    switch (_fnl_lib__state.domain_warp_type)
    {
    case FNL_DOMAIN_WARP_OPENSIMPLEX2:
        _fnlSingleDomainWarpOpenSimplex2Gradient(_fnl_lib__seed, _fnl_lib__amp * 32.69428253173828125, _fnl_lib__freq, _fnl_lib__x, _fnl_lib__y, _fnl_lib__z, _fnl_lib__xp, _fnl_lib__yp, _fnl_lib__zp, false);
        break;
    case FNL_DOMAIN_WARP_OPENSIMPLEX2_REDUCED:
        _fnlSingleDomainWarpOpenSimplex2Gradient(_fnl_lib__seed, _fnl_lib__amp * 7.71604938271605, _fnl_lib__freq, _fnl_lib__x, _fnl_lib__y, _fnl_lib__z, _fnl_lib__xp, _fnl_lib__yp, _fnl_lib__zp, true);
        break;
    case FNL_DOMAIN_WARP_BASICGRID:
        _fnlSingleDomainWarpBasicGrid3D(_fnl_lib__seed, _fnl_lib__amp, _fnl_lib__freq, _fnl_lib__x, _fnl_lib__y, _fnl_lib__z, _fnl_lib__xp, _fnl_lib__yp, _fnl_lib__zp);
        break;
    }
}


void _fnlDomainWarpSingle2D(fnl_state _fnl_lib__state, inout FNLfloat _fnl_lib__x, inout FNLfloat _fnl_lib__y)
{
    int _fnl_lib__seed =

 _fnl_lib__state.seed;

    float _fnl_lib__amp = _fnl_lib__state.domain_warp_amp * _fnlCalculateFractalBounding(_fnl_lib__state);
    float _fnl_lib__freq =
 _fnl_lib__state.frequency;

    FNLfloat _fnl_lib_xs = _fnl_lib__x;
    FNLfloat _fnl_lib_ys = _fnl_lib__y;
    _fnlTransformDomainWarpCoordinate2D(_fnl_lib__state, _fnl_lib_xs, _fnl_lib_ys);

    _fnlDoSingleDomainWarp2D(_fnl_lib__state, _fnl_lib__seed, _fnl_lib__amp, _fnl_lib__freq, _fnl_lib_xs, _fnl_lib_ys, _fnl_lib__x, _fnl_lib__y);
}

void _fnlDomainWarpSingle3D(fnl_state _fnl_lib__state, inout FNLfloat _fnl_lib__x, inout FNLfloat _fnl_lib__y, inout FNLfloat _fnl_lib__z)
{
    int _fnl_lib__seed =

 _fnl_lib__state.seed;

    float _fnl_lib__amp = _fnl_lib__state.domain_warp_amp * _fnlCalculateFractalBounding(_fnl_lib__state);
    float _fnl_lib__freq = _fnl_lib__state.frequency;

    FNLfloat _fnl_lib_xs = _fnl_lib__x;
    FNLfloat _fnl_lib_ys = _fnl_lib__y;
    FNLfloat _fnl_lib_zs = _fnl_lib__z;
    _fnlTransformDomainWarpCoordinate3D(_fnl_lib__state, _fnl_lib_xs, _fnl_lib_ys, _fnl_lib_zs);

    _fnlDoSingleDomainWarp3D(_fnl_lib__state, _fnl_lib__seed, _fnl_lib__amp, _fnl_lib__freq, _fnl_lib_xs, _fnl_lib_ys, _fnl_lib_zs, _fnl_lib__x, _fnl_lib__y, _fnl_lib__z);
}


void _fnlDomainWarpFractalProgressive2D(fnl_state _fnl_lib__state, inout FNLfloat _fnl_lib__x, inout FNLfloat _fnl_lib__y)
{
    int _fnl_lib__seed =

 _fnl_lib__state.seed;

    float _fnl_lib__amp = _fnl_lib__state.domain_warp_amp * _fnlCalculateFractalBounding(_fnl_lib__state);
    float _fnl_lib__freq = _fnl_lib__state.frequency;

    for (int _fnl_lib_i = 0; _fnl_lib_i < _fnl_lib__state.octaves; _fnl_lib_i++)
    {
        FNLfloat _fnl_lib_xs = _fnl_lib__x;
        FNLfloat _fnl_lib_ys = _fnl_lib__y;
        _fnlTransformDomainWarpCoordinate2D(_fnl_lib__state, _fnl_lib_xs, _fnl_lib_ys);

        _fnlDoSingleDomainWarp2D(_fnl_lib__state, _fnl_lib__seed, _fnl_lib__amp, _fnl_lib__freq, _fnl_lib_xs, _fnl_lib_ys, _fnl_lib__x, _fnl_lib__y);

        _fnl_lib__seed++;
        _fnl_lib__amp *= _fnl_lib__state.gain;
        _fnl_lib__freq *= _fnl_lib__state.lacunarity;
    }
}

void _fnlDomainWarpFractalProgressive3D(fnl_state _fnl_lib__state, inout FNLfloat _fnl_lib__x, inout FNLfloat _fnl_lib__y, inout FNLfloat _fnl_lib__z)
{
    int _fnl_lib__seed =

 _fnl_lib__state.seed;

    float _fnl_lib__amp = _fnl_lib__state.domain_warp_amp * _fnlCalculateFractalBounding(_fnl_lib__state);
    float _fnl_lib__freq = _fnl_lib__state.frequency;

    for (int _fnl_lib_i = 0; _fnl_lib_i < _fnl_lib__state.octaves; _fnl_lib_i++)
    {
        FNLfloat _fnl_lib_xs = _fnl_lib__x;
        FNLfloat _fnl_lib_ys = _fnl_lib__y;
        FNLfloat _fnl_lib_zs = _fnl_lib__z;
        _fnlTransformDomainWarpCoordinate3D(_fnl_lib__state, _fnl_lib_xs, _fnl_lib_ys, _fnl_lib_zs);

        _fnlDoSingleDomainWarp3D(_fnl_lib__state, _fnl_lib__seed, _fnl_lib__amp, _fnl_lib__freq, _fnl_lib_xs, _fnl_lib_ys, _fnl_lib_zs, _fnl_lib__x, _fnl_lib__y, _fnl_lib__z);

        _fnl_lib__seed++;
        _fnl_lib__amp *= _fnl_lib__state.gain;
        _fnl_lib__freq *= _fnl_lib__state.lacunarity;
    }
}


void _fnlDomainWarpFractalIndependent2D(fnl_state _fnl_lib__state, inout FNLfloat _fnl_lib__x, inout FNLfloat _fnl_lib__y)
{
    FNLfloat _fnl_lib_xs = _fnl_lib__x;
    FNLfloat _fnl_lib_ys = _fnl_lib__y;
    _fnlTransformDomainWarpCoordinate2D(_fnl_lib__state, _fnl_lib_xs, _fnl_lib_ys);

    int _fnl_lib__seed =

 _fnl_lib__state.seed;

    float _fnl_lib__amp = _fnl_lib__state.domain_warp_amp * _fnlCalculateFractalBounding(_fnl_lib__state);
    float _fnl_lib__freq = _fnl_lib__state.frequency;

    for (int _fnl_lib_i = 0; _fnl_lib_i < _fnl_lib__state.octaves; _fnl_lib_i++)
    {
        _fnlDoSingleDomainWarp2D(_fnl_lib__state, _fnl_lib__seed, _fnl_lib__amp, _fnl_lib__freq, _fnl_lib_xs, _fnl_lib_ys, _fnl_lib__x, _fnl_lib__y);

        _fnl_lib__seed++;
        _fnl_lib__amp *= _fnl_lib__state.gain;
        _fnl_lib__freq *= _fnl_lib__state.lacunarity;
    }
}

void _fnlDomainWarpFractalIndependent3D(fnl_state _fnl_lib__state, inout FNLfloat _fnl_lib__x, inout FNLfloat _fnl_lib__y, inout FNLfloat _fnl_lib__z)
{
    FNLfloat _fnl_lib_xs = _fnl_lib__x;
    FNLfloat _fnl_lib_ys = _fnl_lib__y;
    FNLfloat _fnl_lib_zs = _fnl_lib__z;
    _fnlTransformDomainWarpCoordinate3D(_fnl_lib__state, _fnl_lib_xs, _fnl_lib_ys, _fnl_lib_zs);

    int _fnl_lib__seed =

 _fnl_lib__state.seed;

    float _fnl_lib__amp = _fnl_lib__state.domain_warp_amp * _fnlCalculateFractalBounding(_fnl_lib__state);
    float _fnl_lib__freq = _fnl_lib__state.frequency;

    for (int _fnl_lib_i = 0; _fnl_lib_i < _fnl_lib__state.octaves; _fnl_lib_i++)
    {
        _fnlDoSingleDomainWarp3D(_fnl_lib__state, _fnl_lib__seed, _fnl_lib__amp, _fnl_lib__freq, _fnl_lib_xs, _fnl_lib_ys, _fnl_lib_zs, _fnl_lib__x, _fnl_lib__y, _fnl_lib__z);

        _fnl_lib__seed++;
        _fnl_lib__amp *= _fnl_lib__state.gain;
        _fnl_lib__freq *= _fnl_lib__state.lacunarity;
    }
}
# 2288 "before.c"
fnl_state fnlCreateState(int _fnl_lib__seed)
{
    fnl_state _fnl_lib__newState;
    _fnl_lib__newState.seed = _fnl_lib__seed;
    _fnl_lib__newState.frequency = 0.01f;
    _fnl_lib__newState.noise_type = FNL_NOISE_OPENSIMPLEX2;
    _fnl_lib__newState.rotation_type_3d = FNL_ROTATION_NONE;
    _fnl_lib__newState.fractal_type = FNL_FRACTAL_NONE;
    _fnl_lib__newState.octaves = 3;
    _fnl_lib__newState.lacunarity = 2.f;
    _fnl_lib__newState.gain = 0.5f;
    _fnl_lib__newState.weighted_strength = 0.f;
    _fnl_lib__newState.ping_pong_strength = 2.f;
    _fnl_lib__newState.cellular_distance_func = FNL_CELLULAR_DISTANCE_EUCLIDEANSQ;
    _fnl_lib__newState.cellular_return_type = FNL_CELLULAR_RETURN_TYPE_DISTANCE;
    _fnl_lib__newState.cellular_jitter_mod = 1.f;
    _fnl_lib__newState.domain_warp_amp = 30.f;
    _fnl_lib__newState.domain_warp_type = FNL_DOMAIN_WARP_OPENSIMPLEX2;
    return _fnl_lib__newState;
}



float fnlGetNoise2D(fnl_state _fnl_lib__state, FNLfloat _fnl_lib__x, FNLfloat _fnl_lib__y)
{
    _fnlTransformNoiseCoordinate2D(_fnl_lib__state, _fnl_lib__x, _fnl_lib__y);

    switch (_fnl_lib__state.fractal_type)
    {
        default:
            return _fnlGenNoiseSingle2D(_fnl_lib__state, _fnl_lib__state.seed, _fnl_lib__x, _fnl_lib__y);
        case FNL_FRACTAL_FBM:
            return _fnlGenFractalFBM2D(_fnl_lib__state, _fnl_lib__x, _fnl_lib__y);
        case FNL_FRACTAL_RIDGED:
            return _fnlGenFractalRidged2D(_fnl_lib__state, _fnl_lib__x, _fnl_lib__y);
        case FNL_FRACTAL_PINGPONG:
            return _fnlGenFractalPingPong2D(_fnl_lib__state, _fnl_lib__x, _fnl_lib__y);
    }
}



float fnlGetNoise3D(fnl_state _fnl_lib__state, FNLfloat _fnl_lib__x, FNLfloat _fnl_lib__y, FNLfloat _fnl_lib__z)
{
    _fnlTransformNoiseCoordinate3D(_fnl_lib__state, _fnl_lib__x, _fnl_lib__y, _fnl_lib__z);


    switch (_fnl_lib__state.fractal_type)
    {
        default:
            return _fnlGenNoiseSingle3D(_fnl_lib__state, _fnl_lib__state.seed, _fnl_lib__x, _fnl_lib__y, _fnl_lib__z);
        case FNL_FRACTAL_FBM:
            return _fnlGenFractalFBM3D(_fnl_lib__state, _fnl_lib__x, _fnl_lib__y, _fnl_lib__z);
        case FNL_FRACTAL_RIDGED:
            return _fnlGenFractalRidged3D(_fnl_lib__state, _fnl_lib__x, _fnl_lib__y, _fnl_lib__z);
        case FNL_FRACTAL_PINGPONG:
            return _fnlGenFractalPingPong3D(_fnl_lib__state, _fnl_lib__x, _fnl_lib__y, _fnl_lib__z);
    }
}
# 2355 "before.c"
void fnlDomainWarp2D(fnl_state _fnl_lib__state, inout FNLfloat _fnl_lib__x, inout FNLfloat _fnl_lib__y)
{
    switch (_fnl_lib__state.fractal_type)
    {
        default:
            _fnlDomainWarpSingle2D(_fnl_lib__state, _fnl_lib__x, _fnl_lib__y);
            break;
        case FNL_FRACTAL_DOMAIN_WARP_PROGRESSIVE:
            _fnlDomainWarpFractalProgressive2D(_fnl_lib__state, _fnl_lib__x, _fnl_lib__y);
            break;
        case FNL_FRACTAL_DOMAIN_WARP_INDEPENDENT:
            _fnlDomainWarpFractalIndependent2D(_fnl_lib__state, _fnl_lib__x, _fnl_lib__y);
            break;
    }
}
# 2378 "before.c"
void fnlDomainWarp3D(fnl_state _fnl_lib__state, inout FNLfloat _fnl_lib__x, inout FNLfloat _fnl_lib__y, inout FNLfloat _fnl_lib__z)
{

    switch (_fnl_lib__state.fractal_type)
    {
        default:
            _fnlDomainWarpSingle3D(_fnl_lib__state, _fnl_lib__x, _fnl_lib__y, _fnl_lib__z);
            break;
        case FNL_FRACTAL_DOMAIN_WARP_PROGRESSIVE:
            _fnlDomainWarpFractalProgressive3D(_fnl_lib__state, _fnl_lib__x, _fnl_lib__y, _fnl_lib__z);
            break;
        case FNL_FRACTAL_DOMAIN_WARP_INDEPENDENT:
            _fnlDomainWarpFractalIndependent3D(_fnl_lib__state, _fnl_lib__x, _fnl_lib__y, _fnl_lib__z);
            break;
    }
}
