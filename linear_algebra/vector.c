// by andrew.la
#include "vector.h"

vec2_t * vec2_create(float_t x, float_t y) {
    vec2_t * ptr = new(sizeof(vec2_t));
    ptr->x = x;
    ptr->y = y;
    return ptr;
}
vec3_t * vec3_create(float_t x, float_t y, float_t z) {
    vec3_t * ptr = new(sizeof(vec3_t));
    ptr->x = x;
    ptr->y = y;
    ptr->z = z;
    return ptr;
}
vec2_t * vec2_create_const(float_t c) {
    vec2_t * ptr = new(sizeof(vec2_t));
    ptr->x = c;
    ptr->y = c;
    return ptr;
}
vec3_t * vec3_create_const(float_t c) {
    vec3_t * ptr = new(sizeof(vec3_t));
    ptr->x = c;
    ptr->y = c;
    ptr->z = c;
    return ptr;
}

float_t vec2_length(const vec2_t * vec) {
    return sqrt(vec->x * vec->x + vec->y * vec->y);
}
float_t vec3_length(const vec3_t * vec) {
    return sqrt(vec->x * vec->x + vec->y * vec->y + vec->z * vec->z);
}

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

float_t vec2_dotproduct(const vec2_t * vec1, const vec2_t * vec2) {
    return (vec1->x * vec2->x) + (vec1->y + vec2->y);
}
float_t vec3_dotproduct(const vec3_t * vec1, const vec3_t * vec2) {
    return (vec1->x * vec2->x) + (vec1->y * vec2->y) + (vec1->z * vec2->z);
}

vec3_t * vec3_crossproduct(const vec3_t * vec1, const vec3_t * vec2) {
    return vec3_create(
            vec1->y * vec2->z - vec1->z * vec2->y,
            vec1->z * vec2->x - vec1->x * vec2->z,
            vec1->x * vec2->y - vec1->y * vec2->x
            );
}

vec2_t * vec2_normalize(const vec2_t * vec) {
    return vec2_div(vec, vec2_create_const(vec2_length(vec)));
}
vec3_t * vec3_normalize(const vec3_t * vec) {
    return vec3_div(vec, vec3_create_const(vec3_length(vec)));
}

vec2_t * vec2_lerp(const vec2_t * vec1, const vec2_t * vec2, float k) {
    return vec2_add(vec2_mul(vec1, vec2_create_const(1 - k)), vec2_mul(vec2, vec2_create_const(k)));
}
vec3_t * vec3_lerp(const vec3_t * vec1, const vec3_t * vec2, float k) {
    return vec3_add(vec3_mul(vec1, vec3_create_const(1 - k)), vec3_mul(vec2, vec3_create_const(k)));
}
