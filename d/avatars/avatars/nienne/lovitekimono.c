#include <std.h>
inherit "/d/common/obj/clothing/magerobe";

void create() {
   ::create();
   set_name("kimono");
   set_id(({"kimono","layered kimono","black and red kimono","black-and-red kimono","layered black-and-red kimono","mantle of the black violet","Mantle of the Black Violet","mantle"}));
   set_short("%^BOLD%^%^BLACK%^Mantle of the B%^RESET%^%^MAGENTA%^l%^BOLD%^%^BLACK%^ack Vio%^RESET%^%^MAGENTA%^l%^BOLD%^%^BLACK%^et%^RESET%^");
   set_obvious_short("%^RESET%^%^MAGENTA%^a layered %^BOLD%^%^BLACK%^black%^RESET%^%^MAGENTA%^-and-%^RED%^red %^MAGENTA%^kimono%^RESET%^");
   set_long("%^MAGENTA%^This garment is made from the finest of silks, "
"left long and flowing for the %^CYAN%^com%^GREEN%^fo%^CYAN%^rt%^MAGENTA%^"
" of the wearer.  Its sleeves are long and draped, reaching down from the "
"wrists to flow freely.  It is worn wrapped around the body and crossed "
"at the front, to give a high neck and accentuate the wearer's figure.  "
"It is secured at the waist by a wide %^RED%^cr%^BOLD%^i%^RESET%^%^RED%^"
"mson %^MAGENTA%^sash, and tied in a bow at the back.  The upper layer of "
"the kimono itself has been dyed a flawless shade of %^BOLD%^%^BLACK%^"
"jet-black%^RESET%^%^MAGENTA%^, while the layer beneath it is vivid "
"%^BOLD%^%^RED%^sc%^RESET%^%^RED%^arl%^BOLD%^et%^RESET%^%^MAGENTA%^, to "
"offset the otherwise monochrome garment.  A single %^BLUE%^vio%^RESET%^"
"%^MAGENTA%^l%^BLUE%^et %^MAGENTA%^has been embossed across the back, "
"only visible by its raised stitches, as it is of the same "
"%^BOLD%^%^BLACK%^ebon shade %^RESET%^%^MAGENTA%^as the kimono's silken "
"weave.  Within the cloth's folds, you can see two small pockets probably "
"designed to carry a single item each.  The garment has obviously been "
"designed with elegance in mind.%^RESET%^\n");
   set_lore("This exotic garment was the possession of a Lovite "
"priestess, Claire of the Ashes. A rising hopeful among the priesthood "
"over several years, her ascension was cut dramatically short upon the "
"death of her goddess at the hands of the half-demon Durias. From this "
"point, her name falls into obscurity, during the scattering of the "
"church's faithful.");
   set_property("lore difficulty",21);
   set_weight(8);
   set_value(4000);
   set_type("clothing");
   set_limbs(({"torso"}));
   set_ac(0);
   set_size(2);
   set_property("enchantment",3);
   set_wear((:TO,"wear_fun":));
   set_remove((:TO,"remove_fun":));
   set_struck((:TO,"struck_fun":));
}

int wear_fun() {
   if(ETO->query_highest_level() < 21) {
     tell_object(ETO,"You can't figure out how to wear the beautiful garment. You suspect you would need more aptitude yet.");
     return 0;
   }
   tell_object(ETO,"%^MAGENTA%^The beautiful %^BOLD%^%^BLACK%^kim"
"%^RESET%^%^RED%^on%^BOLD%^%^BLACK%^o %^RESET%^%^MAGENTA%^fits you "
"perfectly, in unmatched comfort.%^RESET%^");
   tell_room(EETO,"%^MAGENTA%^"+ETOQCN+" drapes the %^BOLD%^%^BLACK%^"
"silken kim%^RESET%^%^RED%^on%^BOLD%^%^BLACK%^o %^RESET%^%^MAGENTA%^"
"around "+ETO->QO+"self comfortably, securing it with the wide "
"sash.%^RESET%^",ETO);
   return 1;
}

int remove_fun() {
   tell_object(ETO,"%^MAGENTA%^You remove the silken kimono, already "
"missing the touch of the comfortable garment.%^RESET%^");
   tell_room(EETO,"%^MAGENTA%^"+ETOQCN+" looks almost disappointed to "
"remove "+ETO->QP+" kimono.%^RESET%^",ETO);
   return 1;
}

int struck_fun(int damage,object what,object who){
   if(!random(3)) {
     tell_room(EETO,"%^MAGENTA%^"+ETOQCN+" partially extends both arms "
"and whirls gracefully, as a flurry of %^BOLD%^%^BLACK%^dark flower "
"petals %^RESET%^%^MAGENTA%^are cast forth through the air at "
+who->QCN+"%^RESET%^%^MAGENTA%^!%^RESET%^",({ETO,who}));
     tell_object(ETO,"%^MAGENTA%^You partially extend both arms and step "
"into a gracefully whirl, casting a flurry of %^BOLD%^%^BLACK%^dark "
"flower petals %^RESET%^%^MAGENTA%^through the air at "
+who->QCN+"%^RESET%^%^MAGENTA%^!%^RESET%^");
     tell_object(who,"%^MAGENTA%^"+ETOQCN+" %^RESET%^%^MAGENTA%^partially "
"extends both arms and whirls gracefully, as a flurry of %^BOLD%^%^BLACK%^"
"dark flower petals %^RESET%^%^MAGENTA%^are cast forth through the air at "
"you!%^RESET%^");
     who->set_temporary_blinded(1,"You can't see past the cloud of scattered petals!");
   }
   return 0;
}
