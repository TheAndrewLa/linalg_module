// by andrew.la
#pragma once
#include <math.h>
#include <stdlib.h>
#include "../core_defs.h"

#define MAX(a, b) ((a > b)? a : b)
#define MIN(a, b) ((a > b)? b : a)

typedef struct vector2 vec2_t;
struct vector2 {
    float_point_value x, y;
};

typedef struct vector3 vec3_t;
struct vector3 {
    float_point_value x, y, z;
};

/*
 * -----------------------------
 * Full Set of vector functions
 * -----------------------------
 */

vec2_t * vec2_create(float_point_value x, float_point_value y);
vec2_t * vec2_create_const(float_point_value c);
vec3_t * vec3_create(float_point_value x, float_point_value y, float_point_value z);
vec3_t * vec3_create_const(float_point_value c);

vec2_t * vec2_copy(const vec2_t * vector);
vec3_t * vec3_copy(const vec3_t * vector);

float_point_value vec2_length(const vec2_t * vec);
float_point_value vec3_length(const vec3_t * vec);

vec2_t * vec2_add(const vec2_t * vec1, const vec2_t * vec2);
vec3_t * vec3_add(const vec3_t * vec1, const vec3_t * vec2);

vec2_t * vec2_sub(const vec2_t * vec1, const vec2_t * vec2);
vec3_t * vec3_sub(const vec3_t * vec1, const vec3_t * vec2);

vec2_t * vec2_mul(const vec2_t * vec1, const vec2_t * vec2); // Hadamard mlp
vec3_t * vec3_mul(const vec3_t * vec1, const vec3_t * vec2);

vec2_t * vec2_div(const vec2_t * vec1, const vec2_t * vec2);
vec3_t * vec3_div(const vec3_t * vec1, const vec3_t * vec2);

vec2_t * vec2_scale(const vec2_t * vec, float_point_value s);
vec3_t * vec3_scale(const vec3_t * vec, float_point_value s);

float_point_value vec2_dotproduct(const vec2_t * vec1, const vec2_t * vec2);
float_point_value vec3_dotproduct(const vec3_t * vec1, const vec3_t * vec2);
vec3_t * vec3_crossproduct(const vec3_t * vec1, const vec3_t * vec2);

vec2_t * vec2_lerp(const vec2_t * vec1, const vec2_t * vec2, float k); // linear interpolation
vec3_t * vec3_lerp(const vec3_t * vec1, const vec3_t * vec2, float k);

vec2_t * vec2_normalize(const vec2_t * vec);
vec3_t * vec3_normalize(const vec3_t * vec);
