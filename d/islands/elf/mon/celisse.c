#include <std.h>
#include "../elf.h"
inherit INTERACTIVE;

void create()
{
    ::create();
    remove_std_db();
    remove_dbs(({"miscvendors"}));
    remove_random_act_dbs(({"miscvendorsrandom"}));
    add_id(({"herb merchant"}));
    set_items_allowed("misc");
    set_storage_room(STOR"herb.c");
    set_gender("female");
    set_race("elf");
    set_alignment(1);
    set_hd(20,50);
    set_name("Celisse");
    set_short("Celisse, a herb merchant");
    set_id(({"merchant","elf","celisse","shop keep"}));
    set_long(
    "Celisse is a young wild elf.  She used to live "+
    "in tharis but when her cousin was turned into a"+
    " drow for helping the drow in tharis she left as"+
    " a refugee.  Now she sell herbs in the grove to "+
    "anyone that would have them." );

}