//	/adm/simul_efun/total_light.c
//	from the Nightmare mudlib
//	returns the total amount of light available to a player
//	created by Descartes of Borg 16 january 1993

#include <daemons.h>

int total_light(object who) {
    object *inv;
    object env;
    int light, i;

  if (objectp(who) && who->is_room()) {
    env = who;
  } else {
    if(!who || !(env = environment(who))) return 0;
  }
    i = sizeof(inv = all_inventory(env));
    light = (int)env->query_property("light");
    while(i--) 
	light += (int)inv[i]->query_property("light");
    if(env->query_property("indoors")) return light;
    switch( EVENTS_D->query_time_of_day() ) {
        case "dawn": return --light;
        case "day": return light;
        case "twilight": return --light;
        case "night":
          return ((light-4)+((int)ASTRONOMY_D->query_moon_light()) +
            ((int)env->query_property("night light")));
    }
    return light;
}
