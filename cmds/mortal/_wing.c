#include <std.h>
#include <daemons.h>
#include <magic.h>
inherit DAEMON;

/* 18:23:14 blazeti      | A cool breeze gives your wings some extra lift as you soar through the air. */
/* 18:24:15 Historian    | The wind whips by your face as you zoom past the clouds. */
/* 18:24:18 blazeti      | Spreading your wings wide, you allow the currents in the air to hold you steady. */
/* 18:26:47 blazeti      | Peering far below, you can see a river winding it's way through a thick forest. */
/* 18:27:09 blazeti      | The wind is cold as it blows past. */
/* 18:28:39 blazeti      | You pull your wings in tight, giving your body a twist as you spiral into a dive towards the */
/*                       | ground. */
/* 18:29:20 blazeti      | With a forceful heave, you leap into the air and take flight. */
/* 18:30:09 blazeti      | A flutter of wings takes you into the air. */
/* 18:31:04 blazeti      | You slowly descend to the ground in a series of languid swoops. */
/* 18:32:53 <--          | blazeti (blazeti@discord) has left #sha.ooc () */
/* 21:46:18 -->          | blazeti (blazeti@discord) has joined #sha.ooc */
/* 21:46:31 Diego_Slavem+| Powerful thrusts of your wings carry you higher. */
/* 21:47:15 Aiden_Vaser  | LIke a Carnival Row brothel */
/* 21:47:16 blazeti      | "thrust" just makes that sound like porn */
/* 21:47:24 Diego_Slavem+| Soaring through the air calm you as you ride the wind currents */
/* 21:47:42 Diego_Slavem+| thrust uh huh uh huh uh huh */
/* 21:48:24 Diego_Slavem+| calms */
/* 21:50:15 Diego_Slavem+| now porn would be...The cold are makes your nipples hard */
/* 21:50:21 Diego_Slavem+| air */

string FLIGHT_ROOM = "/std/flying_room.c";

int cmd_wing(string str)
{
    object myshape;
    return 0;
    if (TP->query_bound() || TP->query_paralyzed())
    {
        TP->send_paralyzed_message("info",TP);
        return 1;
    }
    if(!TP->query_property("shapeshifted"))
        return notify_fail("Only a bird can <wing>.\n");
    if((string)TP->query("relationship_profile") != "druid_bird_999" &&
       (string)TP->query("relationship_profile") != "druid_dragon_999")
        return notify_fail("Only a bird can <wing>.\n");
    if(!objectp(myshape = TP->query_property("shapeshifted")))
        return notify_fail("Something went wrong with your shape.\n");
    if(TP->query_casting())
        return notify_fail("You're already casting a spell!\n");
    return 1;
}



void help()
{
    write("Bla bla bla cat placed stub");
}
