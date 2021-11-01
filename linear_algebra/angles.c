// by andrew.la
#include "angles.h"

float_point_value rad_do_deg(float_point_value angle) {
    return (angle * 180.0) / PI;
}
float_point_value deg_to_rad(float_point_value angle) {
    return (angle * PI) / 180.0;
}
