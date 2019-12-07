#include <std.h>
#include <daemons.h>
#include <magic.h>

inherit OBJECT;

string * RAND_MSG = ({"A cool breeze gives your wings some extra lift as you soar through the air.",
            "The wind whips by your face as you zoom past the clouds.",
            "Spreading your wings wide, you allow the currents in the air to hold you steady.",
            "Peering far below, you can see a river winding it's way through a thick forest.",
            "The wind is cold as it blows past.",
            "You pull your wings in tight, giving your body a twist as you spiral into a dive towards the ground.",
            "With a forceful heave, you leap into the air and take flight.",
            "A flutter of wings takes you into the air.",
            "You slowly descend to the ground in a series of languid swoops.",
            "Powerful thrusts of your wings carry you higher.",
            "Soaring through the air calm you as you ride the wind currents."});
string * RAND_CLRS = ({"%^BLUE%^%^BOLD%^","%^BOLD%^%^WHITE%^","%^WHITE%^","%^BLUE%^","%^ORANGE%^"});
string FLIGHT_ROOM = "/std/flying_room.c";
object flyee;
object destination;
object flroom;
int step;

void create()
{
    ::create();
    set_property("no detect", 1);
    set_id(({ "wing_xxx" }));
    set_name("wing object");
}

void setup(object thingy, object dest)
{
    flyee = thingy;
    destination = dest;
    step = 0;
    flroom = new(FLIGHT_ROOM);

    thingy->move(flroom);
    TO->move(thingy);
    flystep();
}

void flystep()
{
    if(!objectp(flyee))
    {
        TO->remove();
        return;
    }
    if(!objectp(flroom))
    {
        TO->remove();
        return;
    }

    if(step==0)
        flroom->change_stage("initial climb");
    else if(step == 4)
        flroom->change_stage("climbing");
    else if(step == 8)
        flroom->change_stage("soaring");
    else if(step == 24)
        flroom->change_stage("landing");
    else if(step == 28)
        flroom->change_stage("final landing");
    else if(step > 32)
    {
        tell_room(destination,"%^BOLD%^%^WHITE%^"+flyee->QCN+" descends into the area from the sky.%^RESET%^");
        flyee->move(destination);
        flyee->force_me("look");
        tell_object(flyee,"%^BOLD%^%^WHITE%^You have arrived at your destination.%^RESET%^");
        TO->remove();
        return;
    }

    tell_object(flyee,RAND_CLRS[random(sizeof(RAND_CLRS))]+RAND_MSG[random(sizeof(RAND_MSG))]+"%^RESET%^");
    if(step>24)
        tell_room(destination,"%^BOLD%^%^BLACK%^You see a shadow of something descending to the ground.%^RESET%^");

    step++;
    call_out("flystep",2);
}
