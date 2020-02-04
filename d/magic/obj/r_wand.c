#include <std.h>
#include <daemons.h>

inherit "/d/common/obj/weapon/wand";

#define WTYPES ({"maple",\
                "ivory",\
                "steel",\
                "slender willow",\
                "white tipped black",\
                "cherry wood",\
                "iron",\
                "ebony"})

void make_me();

void create()
{
    ::create();
    TO->set_name("wand");

    /*
     * If you want to set spell during the creation, just change
     * "spell","spell type" settings of the item.
     *
     * wand = new(WAND)
     * wand->set("spell","magic missile");
     * wand->set("spell type","mage");
     *
     */

    make_me();
    set_weight(2);
}

void make_me()
{
    int i, y;
    string type, spell, sclass;
    string *classes = ({});
    i = random(sizeof(WTYPES));
    type = WTYPES[i];
    spell = MAGIC_D->query_random_spell("random");
    classes = keys(MAGIC_D->query_index_row(spell)["levels"]);
    sclass = classes[random(sizeof(classes))];
    ::create();

    switch (type) {
    case "maple":
        set_long("%^RESET%^A tapered %^ORANGE%^maple wand%^RESET%^, about"
                 + " five inches in length. A few faint runes are carved"
                 + " into the side of the wand.");
        set_short("%^ORANGE%^maple wand of " + spell);
        break;
    case "ivory":
        set_long("%^RESET%^A short %^BOLD%^%^WHITE%^i%^RESET%^v%^BOLD%^"
                 + "%^WHITE%^ory%^RESET%^ wand. A few faint runes are"
                 + " etched into the side of the wand.");
        set_short("%^BOLD%^%^WHITE%^i%^RESET%^v%^BOLD%^%^WHITE%^ory"
                  + " wand of " + spell);
        break;
    case "steel":
        set_long("%^RESET%^A solid %^CYAN%^s%^RESET%^t%^CYAN%^ee%^RESET%^"
                 + "l wand. A few faint runes are etched into the side of"
                 + " the wand.");
        set_short("%^CYAN%^s%^RESET%^t%^CYAN%^ee%^RESET%^l wand of "
                  + spell);
        break;
    case "slender willow":
        set_long("%^RESET%^A slender %^ORANGE%^w%^RESET%^i%^ORANGE%^ll"
                 + "%^RESET%^o%^ORANGE%^w %^RESET%^ wand. A few faint runes"
                 + " are carved into the side of the wand.");
        set_short("%^ORANGE%^w%^RESET%^i%^ORANGE%^ll%^RESET%^o%^ORANGE%^w"
                  + " %^RESET%^ wand of " + spell);
        break;
    case "white tipped black":
        set_long("%^RESET%^A %^BOLD%^%^WHITE%^wh%^BOLD%^%^BLACK%^ite"
                 + " tipped bla%^BOLD%^%^WHITE%^ck%^RESET%^ wand, about six"
                 + " inches in lenth");
        set_short("%^RESET%^A %^BOLD%^%^WHITE%^wh%^BOLD%^%^BLACK%^ite"
                  + " tipped bla%^BOLD%^%^WHITE%^ck%^RESET%^ wand of " + spell);
        break;
    case "cherry wood":
        set_long("%^RESET%^A %^ORANGE%^c%^RED%^h%^ORANGE%^er%^RED%^r"
                 + "%^ORANGE%^y w%^RED%^oo%^ORANGE%^d wand. A few faint"
                 + " runes are carved into the side of the wand.");
        set_short("%^RESET%^A %^ORANGE%^c%^RED%^h%^ORANGE%^r%^RED%^r"
                  + "%^ORANGE%^y w%^RED%^oo%^ORANGE%^d wand of " + spell);
        break;
    case "iron":
        set_long("%^RESET%^An %^BOLD%^%^BLACK%^ir%^RESET%^o%^BOLD%^"
                 + "%^BLACK%^n wand, about five inches in length. A few"
                 + " faint runes are embossed into the side of the wand.");
        set_short("%^RESET%^An %^BOLD%^%^BLACK%^ir%^RESET%^o%^BOLD%^"
                  + "%^BLACK%^n wand of " + spell);
        break;
    case "ebony":
        set_long("%^RESET%^An %^BOLD%^%^BLACK%^ebony wand%^RESET%^,"
                 + " about six inches long. A few faint runes are carved"
                 + " into the side of the wand.");
        set_short("%^RESET%^An %^BOLD%^%^BLACK%^ebony wand%^RESET%^ of "
                  + spell);
        break;
    }
    set_id(({type + " wand", "wand", spell, "wand of " + spell}));

    set("effect", "spell_effect");
    set("uses", 10 + roll_dice(1, 8));
    set("spell", spell);
    set("spell type", sclass );
    set("level", 10 + random(31));
    set("language", "wizzish");
    set_value(query("level") * query("uses") * 4);
    set("read", "The runes indicate that you should %^YELLOW%^<use wand on target>%^RESET%^ while wielding it.");
}
