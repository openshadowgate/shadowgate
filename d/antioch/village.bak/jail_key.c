//  Created by Ignatius, for ShadowGate
//  Coded on 26 June, 1995
//  Garrison Area
//  Jail Key-Opens Doors

inherit  "/std/Object";
void create() {
  ::create();
  set_name("jail key");
  set_id(({"key","jail key"}));
  set_short("jail key");
  set("long",
      "This is a large black key designed to open many of the doors "
      "in the jail area.\n"
     );
    set_weight(8);
    set("value", 10);
}
