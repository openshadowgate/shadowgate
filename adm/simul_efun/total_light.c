#include <daemons.h>

int night_light(object env, int light)
{
    return ((light-3)+
            ((int)ASTRONOMY_D->query_moon_light()) +
            ((int)env->query_property("night light")));
}

int total_light(object who) {
    object *inv;
    object env;
    int light, i;

    if (objectp(who) && who->is_room())
    {
        env = who;
    }
    else
    {
        if(!who || !(env = environment(who))) return 0;
    }
    i = sizeof(inv = all_inventory(env));
    light = (int)env->query_property("light");
    while(i--) 
        light += (int)inv[i]->query_property("light");
    if(env->query_property("indoors"))
        return light;
    if((int)ASTRONOMY_D->query_eclipse())
    {
        return night_light(env,light);
    }
    switch( EVENTS_D->query_time_of_day() )
    {
    case "dawn":
        return --light;
    case "day":
        return light;
    case "twilight":
        return --light;
    case "night":
        return night_light(env,light);
    }
    return light;
}

