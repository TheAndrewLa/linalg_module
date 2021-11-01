// by andrew.la
#pragma once
#include "../core_defs.h"
#include <stdlib.h>
#include <math.h>
#include "vector.h"

typedef struct quaternion quaternion_t;
struct quaternion {
    vec3_t * v; // Axis of rotation
    float_point_value s; // Angle in radian
};

/*
 * ---------------------
 * Quaternion functions
 * ---------------------
 */

quaternion_t * quaternion_create(const vec3_t * vector, float_point_value angle);
quaternion_t * quaternion_copy(const quaternion_t * quaternion);

quaternion_t * quaternion_mul(const quaternion_t * quat1, const quaternion_t * quat2);
quaternion_t * quaternion_inverse(const quaternion_t * quat);

vec3_t * rotate_vector(const vec3_t * vector, const quaternion_t * quaternion);
