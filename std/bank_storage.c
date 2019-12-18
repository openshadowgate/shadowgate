#include <std.h>

inherit ROOM;

int max_storage_capacity;

void create()
{
    ::create();
}

int query_max_storage_capacity()
{
    return max_storage_capacity;
}

int set_max_storage_capacity(int x)
{
    max_storage_capacity = x;
}
