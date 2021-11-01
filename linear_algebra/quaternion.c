// by andrew.la
#include "quaternion.h"

quaternion_t * quaternion_create(const vec3_t * vector, float_point_value angle) {
    quaternion_t * ptr = (quaternion_t *) new(sizeof(quaternion_t));
    ptr->v = vec3_copy(vec3_normalize(vector));
    ptr->v = vec3_scale(ptr->v, sin(angle / 2));
    ptr->s = cos(angle / 2);
    return ptr;
}

quaternion_t * quaternion_copy(const quaternion_t * quaternion) {
    quaternion_t * ptr = (quaternion_t *) new(sizeof(quaternion_t));
    ptr->v = vec3_copy(quaternion->v);
    ptr->s = quaternion->s;
    return ptr;
}

quaternion_t * quaternion_mul(const quaternion_t * quat1, const quaternion_t * quat2) {
    vec3_t * v1 = vec3_add(vec3_scale(quat1->v, quat2->s), vec3_scale(quat2->v, quat1->s));
    vec3_t * v2 = vec3_crossproduct(quat1->v, quat2->v);
    vec3_t * vector = vec3_add(v1, v2);

    quaternion_t * q = (quaternion_t *) new(sizeof(quaternion_t));
    q->v = vector;
    q->s = (quat1->s * quat2->s) - vec3_dotproduct((const vec3_t *) quat1, (const vec3_t *) quat2);
    return q;
}

quaternion_t * quaternion_inverse(const quaternion_t * quat) {
    quaternion_t * q = quaternion_copy(quat);
    q->v = vec3_scale(q->v, -1.0);
    return q;
}

vec3_t * rotate_vector(const vec3_t * vector, const quaternion_t * quaternion) {
    quaternion_t * q1 = (quaternion_t *) new(sizeof(quaternion_t));
    q1->v = vec3_copy(vector);
    q1->s = 0.0;

    quaternion_t * res = quaternion_copy(quaternion);
    quaternion = quaternion_inverse(quaternion);
    res = quaternion_mul(res, q1);
    res = quaternion_mul(res, quaternion);
    return res->v;
}
