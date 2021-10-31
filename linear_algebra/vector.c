// by andrew.la
#include "vector.h"

/*
 * Vector2 creation using "new" macros which readdress us to default malloc
 * later, "new" macros will be readdressing us to custom memory allocator
 */
vec2_t * vec2_create(float_point_value x, float_point_value y) {
    vec2_t * ptr = new(sizeof(vec2_t));
    ptr->x = x;
    ptr->y = y;
    return ptr;
}
vec3_t * vec3_create(float_point_value x, float_point_value y, float_point_value z) {
    vec3_t * ptr = new(sizeof(vec3_t));
    ptr->x = x;
    ptr->y = y;
    ptr->z = z;
    return ptr;
}
vec2_t * vec2_create_const(float_point_value c) {
    vec2_t * ptr = new(sizeof(vec2_t));
    ptr->x = c;
    ptr->y = c;
    return ptr;
}
vec3_t * vec3_create_const(float_point_value c) {
    vec3_t * ptr = new(sizeof(vec3_t));
    ptr->x = c;
    ptr->y = c;
    ptr->z = c;
    return ptr;
}

/*
 * Functions which return length of the vector
 */
float_point_value vec2_length(const vec2_t * vec) {
    return sqrt(vec->x * vec->x + vec->y * vec->y);
}
float_point_value vec3_length(const vec3_t * vec) {
    return sqrt(vec->x * vec->x + vec->y * vec->y + vec->z * vec->z);
}

/*
 * Arithmetical operation with vectors (add, sub, mul, div)
 */
vec2_t * vec2_add(const vec2_t * vec1, const vec2_t * vec2) {
    return vec2_create(vec1->x + vec2->x, vec1->y + vec2->y);
}
vec3_t * vec3_add(const vec3_t * vec1, const vec3_t * vec2) {
    return vec3_create(vec1->x + vec2->x, vec1->y + vec2->y, vec1->z + vec2->z);
}
vec2_t * vec2_sub(const vec2_t * vec1, const vec2_t * vec2) {
    return vec2_create(vec1->x - vec2->x, vec1->y - vec2->y);
}
vec3_t * vec3_sub(const vec3_t * vec1, const vec3_t * vec2) {
    return vec3_create(vec1->x - vec2->x, vec1->y - vec2->y, vec1->z - vec2->z);
}
vec2_t * vec2_mul(const vec2_t * vec1, const vec2_t * vec2) {
    return vec2_create(vec1->x * vec2->x, vec1->y * vec2->y);
}
vec3_t * vec3_mul(const vec3_t * vec1, const vec3_t * vec2) {
    return vec3_create(vec1->x * vec2->x, vec1->y * vec2->y, vec1->z * vec2->z);
}
vec2_t * vec2_div(const vec2_t * vec1, const vec2_t * vec2) {
    return vec2_create(vec1->x / vec2->x, vec1->y / vec2->y);
}
vec3_t * vec3_div(const vec3_t * vec1, const vec3_t * vec2) {
    return vec3_create(vec1->x / vec2->x, vec1->y / vec2->y, vec1->z / vec2->z);
}

/*
 * Dot and cross products of vectors
 */
float_point_value vec2_dotproduct(const vec2_t * vec1, const vec2_t * vec2) {
    return (vec1->x * vec2->x) + (vec1->y + vec2->y);
}
float_point_value vec3_dotproduct(const vec3_t * vec1, const vec3_t * vec2) {
    return (vec1->x * vec2->x) + (vec1->y * vec2->y) + (vec1->z * vec2->z);
}

vec3_t * vec3_crossproduct(const vec3_t * vec1, const vec3_t * vec2) {
    return vec3_create(
            vec1->y * vec2->z - vec1->z * vec2->y,
            vec1->z * vec2->x - vec1->x * vec2->z,
            vec1->x * vec2->y - vec1->y * vec2->x
            );
}

/*
 * Normalization functions
 */
vec2_t * vec2_normalize(const vec2_t * vec) {
    return vec2_div(vec, vec2_create_const(vec2_length(vec)));
}
vec3_t * vec3_normalize(const vec3_t * vec) {
    return vec3_div(vec, vec3_create_const(vec3_length(vec)));
}

/*
 * Interpolation (linear)
 */
vec2_t * vec2_lerp(const vec2_t * vec1, const vec2_t * vec2, float k) {
    k = MAX(1.0, k);
    k = MIN(k, 0.0);
    return vec2_add(vec2_mul(vec1, vec2_create_const(1 - k)), vec2_mul(vec2, vec2_create_const(k)));
}
vec3_t * vec3_lerp(const vec3_t * vec1, const vec3_t * vec2, float k) {
    k = MAX(1.0, k);
    k = MIN(k, 0.0);
    return vec3_add(vec3_mul(vec1, vec3_create_const(1 - k)), vec3_mul(vec2, vec3_create_const(k)));
}
