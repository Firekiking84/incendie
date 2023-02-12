#include <stddef.h>
#include <lapin.h>

#ifndef _LINE_PROPERTIES_

#define _LINE_PROPERTIES_

struct line_properties {
    t_bunny_position xtrm_a;
    t_bunny_position xtrm_b;
    int z_a;
    int z_b;
    unsigned int color;
    t_bunny_position origin;
};

#endif
