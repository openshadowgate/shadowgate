#include <std.h>
inherit OBJECT;

void create(){
        ::create();
        set_name("doll");
        set_id(({"doll","toy","handmade doll"}));
        set_short("%^BOLD%^%^CYAN%^a handmade doll%^RESET%^");
        set_long("%^ORANGE%^This pretty children's toy is obviously handmade, and despite its apparent age "
"seems quite well cared for.  It has been crafted in the image of a young girl, with %^YELLOW%^curly blonde "
"hair %^RESET%^%^ORANGE%^of wool, and a little %^MAGENTA%^c%^BLUE%^h%^BOLD%^%^MAGENTA%^e%^CYAN%^c%^BLUE%^k"
"%^RESET%^%^CYAN%^e%^MAGENTA%^r%^BLUE%^e%^BOLD%^%^CYAN%^d%^RESET%^%^ORANGE%^ dress with matching shoes.  Twin "
"%^BOLD%^%^CYAN%^sky-b%^BLUE%^l%^CYAN%^ue%^RESET%^%^ORANGE%^ buttons serve as its eyes, and it has been "
"painted with a cheerful, smiling %^RED%^mouth%^ORANGE%^.%^RESET%^\n");
        set_value(5);
        set_weight(1);
        set_lore("%^WHITE%^%^BOLD%^Such toys are commonly loved by young children everywhere.  They are often "
"made by mothers and grandmothers for their young daughters, as a comfort in the more dark and lonely times of "
"life.%^RESET%^");
        set_property("lore difficulty",2);
}
