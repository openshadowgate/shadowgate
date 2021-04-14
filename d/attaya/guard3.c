inherit "/std/room";

int storm_counter;

#include <std.h>
void create() {
    storm_counter = 0;
     ::create();
     set_light(2);
     set_indoors(1);
    set_property("no teleport",1);
     set_short("The chamber of evil awareness");
      set_long("
    You have come to a hidden %^BOLD%^%^BLUE%^altar%^RESET%^.  This is a circular chamber with stained %^BOLD%^%^BLUE%^glass walls%^RESET%^!  Bright lights glow behind the walls and beneath the floor where they shine through a glass symbol of the Kinnesaruda.
    A %^BOLD%^%^BLUE%^kneeling block%^RESET%^ lies at the center of the room and a sacrificial table sits at either side.  The ceiling in here is vaivering as if a pocket of intense %^BOLD%^%^BLUE%^heat%^RESET%^ were between you and it.
    Unnatural %^BOLD%^%^BLUE%^stormclouds%^RESET%^ pulse just above the altar.
    You can feel the %^RESET%^%^RED%^angry glare%^RESET%^ of a powerful evil presence upon you.

%^BOLD%^%^BLUE%^A Mysterious %^YELLOW%^Portal %^BLUE%^is here.
");
     set_items(([
      "ceiling" : "The ceiling seems to be unstable, some unseen force lies between you and it, or perhaps reality is warped.",
      "altar" : "This is an altar dedicated to resurrecting the dead.  It is a holy place for the most malevolant forces imaginable.",
      ({"storm", "stormclouds"}) : "Unnatural and ever present stormclouds pulse and rumble just above the altar. You get an overwhelming sense that you can tune to the %^BOLD%^%^RED%^storm%^RESET%^.",
      ({"tables", "sacrificial tables"}) : "The sacrificing tables are stained with blood.",
      "walls" : "They are comprised of colored glass panels.  Bright light pours into the room from behind them.",
      "portal": "You catch a glimpse of a passage carved into the mountain."
]));
     set_listen("default", "A beautiful dark melody fills your head.  You have heard it somewhere before, and could listen to it forever.\n");
}
void reset() {
  ::reset();
    if(!present("ashtar"))
    new("/d/attaya/mon/ashtar")->move(this_object());
}
void init() {
  ::init();
  add_action("storm", "storm");
  add_action("enter", "enter");
}
int storm(string str) {
    if (storm_counter < 10) {
        this_player()->do_damage((random(5)));
        write("%^CYAN%^You turn your attention to the storm. Something %^BOLD%^%^RED%^evil%^RESET%^ %^CYAN%^looks back!\n%^RESET%^");
        say((string)this_player()->query_cap_name()+"%^CYAN%^ eyes the storm and %^BOLD%^%^YELLOW%^lightning%^RESET%^%^CYAN%^ strikes!\n%^RESET%^");           
        call_out("backup",1,TP);
        storm_counter++;
        return 1;
    }

  write("%^CYAN%^You turn your attention to the storm, but it remains dormant.\n");
  say((string)this_player()->query_cap_name()+" eyes the storm, but it remains dormant.\n");   
  return 1;
}
void backup(object targ){
        object ob;
        if(objectp(targ)){
                if(present(targ->query_name())){
                        tell_room(TO,"A skeletal entity emerges from the shadows nearby!");
                       ob=new("/d/attaya/mon/entity");
                        ob->move(TO);
               }
          }
}

int enter(string str) {
  write("%^CYAN%^You enter the mysterious portal.\n");
  say((string)this_player()->query_cap_name()+" enters the mysterious portal.\n");
  this_player()->move_player("/d/attaya/cliff59");
  return 1;
}

