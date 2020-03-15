inherit "std/room";

void create() {
  ::create();
   set_property("no teleport",1);
    set_properties((["light":1, "indoors":1]));
    set("short", "Antioch's General Store Storage Room");
    set("long", "Supplies and such are stored here.\n");
    set_exits( (["up" : "/d/antioch/village/vil_store"]));
}

void reset() {

::reset();
if(!present("schest"))
 new("d/shadow/obj/misc/schest")->move(this_object()); 
if(!present("ssack"))
 new("d/shadow/obj/misc/ssack")->move(this_object()); 
if(!present("small pouch"))
 new("d/shadow/obj/misc/spouch")->move(this_object()); 
if(!present("climbing tools"))
 new("d/shadow/obj/misc/climb_tool")->move(this_object()); 
if(!present("torch"))
 new("d/shadow/obj/misc/torch")->move(this_object()); 
if(!present("lantern"))
 new("d/shadow/obj/misc/lantern")->move(this_object()); 
if(!present("oil"))
 new("d/shadow/obj/misc/oil")->move(this_object()); 
if(!present("beacon"))
 new("d/shadow/obj/misc/bullseye")->move(this_object()); 
if(!present("flint"))
 new("d/shadow/obj/misc/flint")->move(this_object()); 
if(!present("longsword"))
 new("d/shadow/obj/weapon/longsword")->move(this_object());
if(!present("axe"))
 new("d/shadow/obj/weapon/battle_axe")->move(this_object());
if(!present("two handed"))
 new("d/shadow/obj/weapon/two_hand_sword")->move(this_object());
if(!present("dagger"))
 new("d/shadow/obj/weapon/dagger")->move(this_object());
if(!present("whip"))
 new("d/shadow/obj/weapon/whip")->move(this_object());
if(!present("rake"))
 new("d/shadow/obj/weapon/rake")->move(this_object());
if((!present("sheaths"))&&(random(10)<1))
 new("/d/tharis/obj/wrist_sheath")->move(this_object());
if(!present("gem"))
  new("/d/islands/tonerra/obj/gem")->move(this_object());
if(!present("gem 2"))
  new("/d/islands/tonerra/obj/gem")->move(this_object());
if(!present("gem 3"))
  new("/d/islands/tonerra/obj/gem")->move(this_object());
if(!present("gem pouch"))
  new("/d/islands/tonerra/obj/gpouch")->move(this_object());
}
