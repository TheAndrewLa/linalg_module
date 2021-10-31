// by andrew.la
#pragma once
#include <math.h>
#include <stdlib.h>
#include "../core_defs.h"

typedef struct vector2 vec2_t;
struct vector2 {
    float_t x, y;
};

typedef struct vector3 vec3_t;
struct vector3 {
    float_t x, y, z;
};

/*
 * -----------------------------
 * Full Set of vector functions
 * -----------------------------
 */

vec2_t * vec2_create(float_t x, float_t y);
vec2_t * vec2_create_const(float_t c);
vec3_t * vec3_create(float_t x, float_t y, float_t z);
vec3_t * vec3_create_const(float_t c);

float_t vec2_length(const vec2_t * vec);
float_t vec3_length(const vec3_t * vec);

vec2_t * vec2_add(const vec2_t * vec1, const vec2_t * vec2);
vec3_t * vec3_add(const vec3_t * vec1, const vec3_t * vec2);

vec2_t * vec2_sub(const vec2_t * vec1, const vec2_t * vec2);
vec3_t * vec3_sub(const vec3_t * vec1, const vec3_t * vec2);

vec2_t * vec2_mul(const vec2_t * vec1, const vec2_t * vec2); // Hadamard mlp
vec3_t * vec3_mul(const vec3_t * vec1, const vec3_t * vec2);

vec2_t * vec2_div(const vec2_t * vec1, const vec2_t * vec2);
vec3_t * vec3_div(const vec3_t * vec1, const vec3_t * vec2);

float_t vec2_dotproduct(const vec2_t * vec1, const vec2_t * vec2);
float_t vec3_dotproduct(const vec3_t * vec1, const vec3_t * vec2);
vec3_t * vec3_crossproduct(const vec3_t * vec1, const vec3_t * vec2);

vec2_t * vec2_lerp(const vec2_t * vec1, const vec2_t * vec2, float k); // linear interpolation
vec3_t * vec3_lerp(const vec3_t * vec1, const vec3_t * vec2, float k);

vec2_t * vec2_normalize(const vec2_t * vec);
vec3_t * vec3_normalize(const vec3_t * vec);
