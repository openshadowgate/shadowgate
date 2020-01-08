#include <std.h>

#define CAP_PER_TIER 10

inherit ROOM;

static cell_tier;

void create()
{
    ::create();
    cell_tier = 0;
}

set_cell_tier(int x)
{
    cell_tier = x;
}
