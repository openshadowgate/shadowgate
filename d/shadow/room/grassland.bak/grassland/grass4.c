inherit "/std/room";
create() {
::create();
set_light(2);
set_indoors(1);
set_short("grass lands");
set_long("You are somewhere in the grass lands, but you are not sure where.  The 7 ft. high grass, makes you feel like you may never find your way out.");
set_exits( ([ "east" : "/d/shadow/room/grassland/grass5.c",
"west" : "/d/shadow/room/grassland/grass3.c",
"south" : "/d/shadow/room/grassland/grass1.c",
"north" : "/d/shadow/room/grassland/grass9.c",
]) );
}
