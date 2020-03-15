inherit "/std/room";
object ob;
create() {
::create();
set_light(2);
set_indoors(1);
set_short("grass lands");
set_long("You are somehwere in the grass lands.  There is a large mountain to the west, that looks like an old mine.  There are many rocks that have fallen from the mine, and rolled into this area.");
set_exits( ([ "east" : "/d/shadow/room/grassland/grass22.c",
"south" : "/d/shadow/room/grassland/grass16.c",
]) );
}

init()
{
  ::init();
  if(!ob || member_array(ob, all_inventory(this_object())) == -1)
    if(random(10) == 1)
     {
       ob  = new("/d/shadow/room/grassland/mon/sharf.c");
       ob -> move(this_object());
}
}
