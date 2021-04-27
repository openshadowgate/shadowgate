#include <std.h>
inherit OBJECT;

void create(){
   ::create();
   set_name("golden lotus blossom");
   set_id(({"lotus","flower","golden lotus","blossom","lotus blossom","lotus of insight","Lotus of Insight"}));
   set_short("%^BOLD%^%^WHITE%^Lot%^MAGENTA%^u%^WHITE%^s of %^CYAN%^I%^RESET%^%^CYAN%^n%^BOLD%^sig%^GREEN%^h%^CYAN%^t%^RESET%^");
   set_obvious_short("%^RESET%^%^MAGENTA%^a %^YELLOW%^go%^RESET%^%^ORANGE%^ld%^YELLOW%^en %^RESET%^%^MAGENTA%^lotus blossom%^RESET%^");
   set_long("%^RESET%^%^MAGENTA%^The artistry of this %^ORANGE%^s%^RED%^im%^ORANGE%^pl%^RED%^e%^MAGENTA%^, yet %^CYAN%^e"
"%^BOLD%^l%^RESET%^%^CYAN%^eg%^GREEN%^a%^CYAN%^nt%^MAGENTA%^, piece is almost breathtaking.  Shaped as a %^BOLD%^"
"%^WHITE%^lot%^MAGENTA%^u%^WHITE%^s blossom %^RESET%^%^MAGENTA%^settled upon a %^GREEN%^b%^BOLD%^r%^RESET%^%^GREEN%^oad "
"le%^BOLD%^a%^RESET%^%^GREEN%^f%^MAGENTA%^, the flower is easily as big as a human hand and is crafted of solid "
"%^YELLOW%^g%^RESET%^%^ORANGE%^ol%^YELLOW%^d%^RESET%^%^MAGENTA%^, burnished to a lustrous sheen.  It is deceptively "
"lightweight to hold, which seems at odd with the size and substance of which it is made.  Bearing perfect radial "
"symmetry, each %^RESET%^p%^BOLD%^e%^RESET%^t%^BOLD%^a%^RESET%^l %^MAGENTA%^has been picked out in exquisite detail, "
"like a living blossom %^BOLD%^%^CYAN%^fr%^RESET%^%^CYAN%^oz%^BOLD%^en %^RESET%^%^MAGENTA%^in time.  All eight of its "
"petals are folded inwards to the centre, as if simply awaiting a chance to bloom.%^RESET%^");
   set_lore("%^BOLD%^%^WHITE%^Uncommon to this part of the realms, in the far west the lotus blossom is a symbol of "
"purity, spiritual perfection, and the feminine aspect.  They usually carry eight petals, a number that is oft repeated "
"throughout religion and spirituality in the regions it is found.  Most often, it is used to represent either the paths "
"to enlightenment, or the schools of arcane magic, with each petal representing a dedication.  The color of the lotus "
"often indicates its intended symbolism; whether that be the blue of arcanistry, the white of purity, the purple of "
"enlightenment, or the pink of divinity.%^RESET%^");
   set_property("lore difficulty",20);
   set_weight(5);
   set_value(0);
}

int isMagic(){ return 1; }

void set_desc(int state) {
   string shortnum;
   shortnum = "";
   if(state && state < 8) {
     switch(state) {
       case 1: shortnum = "One"; break;
       case 2: shortnum = "Two"; break;
       case 3: shortnum = "Three"; break;
       case 4: shortnum = "Four"; break;
       case 5: shortnum = "Five"; break;
       case 6: shortnum = "Six"; break;
       case 7: shortnum = "Seven"; break;
     }
   }
   if(!state)
     set_long("%^RESET%^%^MAGENTA%^The artistry of this %^ORANGE%^s%^RED%^im%^ORANGE%^pl%^RED%^e%^MAGENTA%^, yet "
"%^CYAN%^e%^BOLD%^l%^RESET%^%^CYAN%^eg%^GREEN%^a%^CYAN%^nt%^MAGENTA%^, piece is almost breathtaking.  Shaped as a %^BOLD%^"
"%^WHITE%^lot%^MAGENTA%^u%^WHITE%^s blossom %^RESET%^%^MAGENTA%^settled upon a %^GREEN%^b%^BOLD%^r%^RESET%^%^GREEN%^oad le"
"%^BOLD%^a%^RESET%^%^GREEN%^f%^MAGENTA%^, the flower is easily as big as a human hand and is crafted of solid %^YELLOW%^g"
"%^RESET%^%^ORANGE%^ol%^YELLOW%^d%^RESET%^%^MAGENTA%^, burnished to a lustrous sheen.  It is deceptively lightweight to "
"hold, which seems at odd with the size and substance of which it is made.  Bearing perfect radial symmetry, each "
"%^RESET%^p%^BOLD%^e%^RESET%^t%^BOLD%^a%^RESET%^l %^MAGENTA%^has been picked out in exquisite detail, like a living "
"blossom %^BOLD%^%^CYAN%^fr%^RESET%^%^CYAN%^oz%^BOLD%^en %^RESET%^%^MAGENTA%^in time.  All eight of its petals are "
"unfolded, to reveal a %^RED%^g%^BOLD%^l%^RESET%^%^RED%^ow%^BOLD%^i%^RESET%^%^RED%^ng %^MAGENTA%^centre.%^RESET%^");
   if(state && state < 8)
     set_long("%^RESET%^%^MAGENTA%^The artistry of this %^ORANGE%^s%^RED%^im%^ORANGE%^pl%^RED%^e%^MAGENTA%^, yet "
"%^CYAN%^e%^BOLD%^l%^RESET%^%^CYAN%^eg%^GREEN%^a%^CYAN%^nt%^MAGENTA%^, piece is almost breathtaking.  Shaped as a %^BOLD%^"
"%^WHITE%^lot%^MAGENTA%^u%^WHITE%^s blossom %^RESET%^%^MAGENTA%^settled upon a %^GREEN%^b%^BOLD%^r%^RESET%^%^GREEN%^oad le"
"%^BOLD%^a%^RESET%^%^GREEN%^f%^MAGENTA%^, the flower is easily as big as a human hand and is crafted of solid %^YELLOW%^g"
"%^RESET%^%^ORANGE%^ol%^YELLOW%^d%^RESET%^%^MAGENTA%^, burnished to a lustrous sheen.  It is deceptively lightweight to "
"hold, which seems at odd with the size and substance of which it is made.  Bearing perfect radial symmetry, each "
"%^RESET%^p%^BOLD%^e%^RESET%^t%^BOLD%^a%^RESET%^l %^MAGENTA%^has been picked out in exquisite detail, like a living "
"blossom %^BOLD%^%^CYAN%^fr%^RESET%^%^CYAN%^oz%^BOLD%^en %^RESET%^%^MAGENTA%^in time.  "+shortnum+" of its eight petals "
"are folded inwards to the centre, as if simply awaiting a chance to bloom, while the rest spread fan-like around its "
"perimeter.  Upon the outer surface of the uppermost folded petal, a few lines of delicate %^CYAN%^s%^GREEN%^c%^CYAN%^r"
"%^GREEN%^i%^CYAN%^p%^GREEN%^t %^MAGENTA%^have been etched.%^RESET%^%^RESET%^");
   if(state == 8)
     set_long("%^RESET%^%^MAGENTA%^The artistry of this %^ORANGE%^s%^RED%^im%^ORANGE%^pl%^RED%^e%^MAGENTA%^, yet %^CYAN%^e"
"%^BOLD%^l%^RESET%^%^CYAN%^eg%^GREEN%^a%^CYAN%^nt%^MAGENTA%^, piece is almost breathtaking.  Shaped as a %^BOLD%^"
"%^WHITE%^lot%^MAGENTA%^u%^WHITE%^s blossom %^RESET%^%^MAGENTA%^settled upon a %^GREEN%^b%^BOLD%^r%^RESET%^%^GREEN%^oad "
"le%^BOLD%^a%^RESET%^%^GREEN%^f%^MAGENTA%^, the flower is easily as big as a human hand and is crafted of solid "
"%^YELLOW%^g%^RESET%^%^ORANGE%^ol%^YELLOW%^d%^RESET%^%^MAGENTA%^, burnished to a lustrous sheen.  It is deceptively "
"lightweight to hold, which seems at odd with the size and substance of which it is made.  Bearing perfect radial "
"symmetry, each %^RESET%^p%^BOLD%^e%^RESET%^t%^BOLD%^a%^RESET%^l %^MAGENTA%^has been picked out in exquisite detail, "
"like a living blossom %^BOLD%^%^CYAN%^fr%^RESET%^%^CYAN%^oz%^BOLD%^en %^RESET%^%^MAGENTA%^in time.  All eight of its "
"petals are folded inwards to the centre, as if simply awaiting a chance to bloom.  Upon the outer surface of the "
"uppermost folded petal, a few lines of delicate %^CYAN%^s%^GREEN%^c%^CYAN%^r%^GREEN%^i%^CYAN%^p%^GREEN%^t %^MAGENTA%^"
"have been etched.%^RESET%^%^RESET%^%^RESET%^");
   if(state > 8)
     set_long("%^RESET%^%^MAGENTA%^The artistry of this %^ORANGE%^s%^RED%^im%^ORANGE%^pl%^RED%^e%^MAGENTA%^, yet %^CYAN%^e"
"%^BOLD%^l%^RESET%^%^CYAN%^eg%^GREEN%^a%^CYAN%^nt%^MAGENTA%^, piece is almost breathtaking.  Shaped as a %^BOLD%^"
"%^WHITE%^lot%^MAGENTA%^u%^WHITE%^s blossom %^RESET%^%^MAGENTA%^settled upon a %^GREEN%^b%^BOLD%^r%^RESET%^%^GREEN%^oad "
"le%^BOLD%^a%^RESET%^%^GREEN%^f%^MAGENTA%^, the flower is easily as big as a human hand and is crafted of solid "
"%^YELLOW%^g%^RESET%^%^ORANGE%^ol%^YELLOW%^d%^RESET%^%^MAGENTA%^, burnished to a lustrous sheen.  It is deceptively "
"lightweight to hold, which seems at odd with the size and substance of which it is made.  Bearing perfect radial "
"symmetry, each %^RESET%^p%^BOLD%^e%^RESET%^t%^BOLD%^a%^RESET%^l %^MAGENTA%^has been picked out in exquisite detail, "
"like a living blossom %^BOLD%^%^CYAN%^fr%^RESET%^%^CYAN%^oz%^BOLD%^en %^RESET%^%^MAGENTA%^in time.  All eight of its "
"petals are folded inwards to the centre, as if simply awaiting a chance to bloom.%^RESET%^");
}