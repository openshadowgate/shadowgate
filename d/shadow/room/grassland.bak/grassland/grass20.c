inherit "/std/room";
object ob;
create() {
::create();
set_light(2);
set_indoors(1);
set_short("grass lands");
set_long("You are somewhere in the grass lands, but you are not sure where.  The 7 ft. high grass, makes you feel like you may never find your way out.");
set_exits( ([ "south" : "/d/shadow/room/grassland/grass14.c",
]) );
}

init()
{
  ::init();
  if(!ob || member_array(ob, all_inventory(this_object())) == -1)
    if(random(5) == 1)
     {
       switch(random(5))
        {
          case 0: ob  = new("/d/shadow/room/grassland/mon/badger.c");
                  break;
          case 1: ob  = new("/d/shadow/room/grassland/mon/emph.c");
                  break;
          case 2: ob  = new("/d/shadow/room/grassland/mon/pitbull.c");
                  break;
          case 3: ob  = new("/d/shadow/room/grassland/mon/rattle.c");
                  break;
          case 4: ob  = new("/d/shadow/room/grassland/mon/sharf.c");
                  break;
        }
       ob -> move(this_object());
     }
}
