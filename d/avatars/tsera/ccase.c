//for bard instruments - adapted from the pouch for gems on Tonerra
//Circe 6/14/04
#include <std.h>
#include <move.h>

inherit PARMOUR;

void create(){
   ::create();
   set_name("instrument case");
   set_short("%^RESET%^%^ORANGE%^fine leather instrument case%^RESET%^");
   set_long("This case is made from %^RESET%^%^ORANGE%^supple "+
      "leather %^RESET%^water-proofed "+
      "and tanned to protect its contents.  It has been specially "+
      "made to carry instruments, and it includes several pockets "+
      "inside for things like %^BOLD%^polish%^RESET%^, %^YELLOW%^"+
      "oil%^RESET%^, extra strings, and "+
      "the like that entertainers often find themselves in need of.  "+
      "The top of the case overhangs the lower portion and "+
      "closes securely with toggles made of wood, while the inside has been lined with the finest"+
      " of %^BLUE%^tsarven %^RED%^silks%^RESET%^.  The case has "+
      "a long, padded strap that may be stretched across the "+
      "entertainer's chest to keep the beloved instrument close at "+
      "hand.");
   set_id(({"case","instrument case"}));
   set_max_internal_encumbrance(12);
   set_limbs(({"torso"}));
   set_type("ring");
   set_weight(10);
   set_value(650);
}

int put_into(string str){
  int res, i, silly;
  object ths,tht,*inv;
  string this, that;

  if(total_light(this_player())+(int)this_player()->query_sight_bonus()<-1){
    notify_fail("It is too dark.\n");
    return 0;
  }
  if (stringp(str) && sscanf(str,"%s in %s",this,that) == 2) {
    if (present(this,this_player())) {
      if (present(that,this_player()) || present(that,environment(this_player()))) {
        ths = present(this,this_player());
        tht = present(that, this_player());

        if(ths == tht) /* Plura 930208 */{
          notify_fail("Get real!\n");
          return 0;
        }
        if(!tht) tht = present(that, environment(this_player()));
        if(ths->drop()) {
          notify_fail("You cannot drop that!\n");
          return 0;
        }
        if(tht != TO) return 0;
          if(!ths->is_instrument()){
            notify_fail("This is meant for instruments only.\n");
                return 0;
          }

         if (tht->receive_objects()) {
          res = (int)ths->move(tht);
          if (res == MOVE_OK) {
            write("You put "+ths->query_short()+" in "+tht->query_short()+".\n");
            say(this_player()->query_cap_name()+" puts "+ths->query_short()+ " in "+tht->query_short()+".\n");
            return 1;
          }
          if (res == MOVE_NO_ROOM)
            notify_fail("For some reason it does not fit...\n");
          if (res == MOVE_NOT_ALLOWED)
            notify_fail("You are not allowed to do that...\n");
          return 0;
        }
        notify_fail("It is closed.\n");
        return 0;
      }
      notify_fail(capitalize(that)+" is not here.\n");
      return 0;

    }
    notify_fail("You are not carrying "+this+".\n");
    return 0;
  }
 return 0;
}
