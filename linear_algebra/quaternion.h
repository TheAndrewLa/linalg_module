// by andrew.la
#pragma once
#include "../core_defs.h"
#include <stdlib.h>
#include <math.h>
#include "vector.h"

typedef struct quaternion quaternion_t;
struct quaternion {
    vec3_t v;
    float_point_value s;
};

quaternion_t * quaternion_create(vec3_t * vector, float_point_value angle);
quaternion_t * quaternion_mul(quaternion_t * quat1, quaternion_t * quat2);
quaternion_t * quaternion_inverse(quaternion_t * quat);

vec3_t * rotate_vector(vec3_t * vector, quaternion_t * quaternion);
