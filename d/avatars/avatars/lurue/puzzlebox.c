#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("puzzle box");
	set_id(({ "box", "puzzlebox", "puzzle box", "wood box" }));
	set_short("%^RESET%^%^ORANGE%^a curious wooden puzzlebox%^RESET%^");
	set_obvious_short("%^RESET%^%^ORANGE%^a curious wooden puzzlebox%^RESET%^");
	set_long(
@AVATAR
 %^RESET%^%^ORANGE%^A soft type of wood has been used to make this small puzzle box.  About the size of one's hand, the box has several panels and joints that look like they can be manipulated to %^WHITE%^open%^ORANGE%^ the puzzlebox.  Painted onto the wood in %^BOLD%^%^MAGENTA%^mauve%^RESET%^%^ORANGE%^, %^RED%^red %^ORANGE%^and %^BOLD%^%^BLACK%^black%^RESET%^%^ORANGE%^ paint are dozens of strange sigils and markings, all of which seem to move and blend together as you stare at them, giving no clue as to their immediate meaning. On the top of the box, like a button, is a small oval of %^BOLD%^%^MAGENTA%^rhodonite%^RESET%^%^ORANGE%^.%^RESET%^

AVATAR
	);
	set_weight(5);
	set_value(300);
	set_lore(
@AVATAR
Try as you might, nothing comes to mind about this box.  Although the shifting patterns and the way its panels manipulate make you think of spies and obfuscation.

AVATAR
	);
	set_property("lore difficulty",10);
}

void init(){
   ::init();
   add_action("open","open");
}


void open(string str){
    if(str == "puzzlebox" || str == "puzzle box" || str == "the puzzlebox" || str == "the puzzle box") {
        tell_object(ETO,"%^ORANGE%^You slide and turn parts of the puzzle box around, but cannot seem to open it.%^RESET%^");
tell_room(environment(ETO),"%^RESET%^%^ORANGE%^"+ETO->query_cap_name()+"%^RESET%^%^ORANGE%^ fiddles with the puzzle box for awhile .%^RESET%^",ETO);
    return 1;
    }
    tell_object(ETO,"Open what?");
    return 1;
}
