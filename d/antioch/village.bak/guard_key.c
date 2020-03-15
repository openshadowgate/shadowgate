//  Created by Ignatius, for ShadowGate
//  Coded on 26 June, 1995
//  Garrison Area
//  Guard's Key

inherit  "/std/Object";
void create() {
  ::create();
  set_name("guard key");
  set_id(({"guard key","key"}));
  set_short("guard key");
  set("long",
      "This is a large black key designed to open many of the doors "
      "in the garrison.\n"
     );
    set_weight(8);
    set("value", 100);
}
