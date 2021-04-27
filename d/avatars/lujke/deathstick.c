//Coded by Lujke

// This deathstick is for avatar use only. It allows you to make things 
// (not players) just die, when that's an appropriate event for plots, 
// etc.
#include <std.h>
inherit OBJECT;

void create() {
    ::create();
    set_name("death stick");
    set_id( ({"death stick","stick", 
                      "black stick"}) );
    set_short("%^B_GREEN%^%^BOLD%^%^GREEN%^Lujke's %^RESET%^%^BOLD%^"
             +"%^BLACK%^Avatar Deathstick of Doom");
    set_obvious_short("%^BOLD%^%^BLACK%^A small, deathly black stick"
                    +"%^RESET%^");
    set_weight(2);
    set_long("%^BOLD%^%^BLACK%^A small black stick, about the size of a"
            +" wand, with some writing etched into it.");
    set_lore("This is the fabled Avatar Deathstick of Doom. Used by Gods"
            +" and Immortals to bring death to all creatures in the name"
            +" of RP and plotting! It's not for players. If you're not an"
            +" immortal, put it down straight away and hope that no-one"
            +" noticed you had it.");
  set_property("lore",19);
  set_read("Fairly simple to use. Just %^BOLD%^%^GREEN%^'slay <target"
          +" name>'%^RESET%^ when you are in the room with them. Doesn't"
          +" work on players.");
}

void init()
{
  ::init();
  add_action("slay_me", "slay");
}

int slay_me(string str)
{
  int hp;
  object targ;
  if (!objectp(TO)||!objectp(ETO)||!objectp(EETO)||!interactive(ETO))
    {return 0;}
  if (!avatarp(ETO)){
    tell_object(ETO, "You're not supposed to have that!");
    TO->remove();
    return 1;
  }
  targ = present(str, EETO);
  if (!objectp(targ)){
    tell_object(ETO, "That isn't here to be slain");
    return 1;
  }
  if (!living(targ)){
    tell_object(ETO, "You can only slay living things");
    return 1;
  }
  if (interactive(targ)){
    tell_object(ETO, "You can't use the deathstick to slay players - only"
                    +" mobs & NPCs");
    return 1;
  }
  hp = (int)targ->query_max_hp()*2;
  targ->do_damage(targ->return_target_limb(),hp);
  targ->add_attacker(TO);
  targ->continue_attack();
  if(objectp(targ))    targ->remove_attacker(TO);
  tell_object(ETO, "You use the " + query_short() + " to kill " 
                   + str);
  return 1;
}
