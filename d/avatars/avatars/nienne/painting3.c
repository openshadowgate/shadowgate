#include <std.h>
inherit OBJECT;

void create(){
        ::create();
        set_name("painting");
        set_id(({"painting"}));
        set_short("%^RESET%^%^BLUE%^A detailed %^MAGENTA%^oil %^BLUE%^painting%^RESET%^");
        set_long("%^BOLD%^%^BLUE%^(This is a painting done in a mix of oils with a fine brush and deliberate "
"strokes. The visual is done in a landscape style, from side to side of this piece. The canvas appears to be "
"altered velvet perhaps, yet still sturdy enough to hold the oils without chipping when the painting is rolled "
"up. A constant, yet subtle, mix of %^RED%^Rose%^BOLD%^%^BLUE%^, %^BLACK%^n%^BLUE%^i%^MAGENTA%^g%^BLACK%^h"
"%^BLUE%^t%^MAGENTA%^s%^BLACK%^h%^BLUE%^a%^MAGENTA%^d%^BLACK%^e%^BLUE%^, and rare %^CYAN%^orchid%^BLUE%^, "
"rises from the oils).%^RESET%^\n\n"
"%^BOLD%^%^BLUE%^A lush forest of mighty oak trees forms the backdrop of this piece. No wild %^GREEN%^life "
"%^BLUE%^rests within the trees and no %^CYAN%^wind %^BLUE%^blows through this forest. %^BLACK%^Dar%^BLUE%^kn"
"%^BLACK%^ess %^BLUE%^and Sh%^BLACK%^ad%^BLUE%^ow enshroud everything visible. The branches reach ever upward "
"toward a light that never seems to penetrate the leaves. The only light visible being a subtle %^RESET%^"
"%^RED%^dark red %^BOLD%^%^BLUE%^in the sky from either a distant yet potent %^MAGENTA%^dusk%^BLUE%^, or a "
"raging %^RED%^i%^BLACK%^n%^RED%^f%^BLACK%^e%^YELLOW%^r%^BLACK%^n%^RED%^o%^BLUE%^.\n\n"
"%^BOLD%^%^BLUE%^Within the largest of the visible trees, a small and slender girl stands.  She is young, "
"looking in her middle teens, with brilliant %^CYAN%^s%^BLUE%^a%^RESET%^%^BLUE%^p%^CYAN%^p%^BLUE%^h%^BOLD%^"
"%^WHITE%^i%^BLUE%^r%^CYAN%^e %^BLUE%^eyes that hold a sharp intellect beyond her years. Delicate Elven "
"features and sharply pointed ears reveal her ancestry to be other than human. Her %^WHITE%^pale %^BLUE%^skin "
"contrasts with the endless shadows that weave around her, along with %^BLACK%^da%^RESET%^%^MAGENTA%^r%^BOLD%^"
"%^BLUE%^k s%^BLUE%^ab%^BLACK%^le %^BLUE%^curls that frame her face. Ornate hair combs holds back many of "
"these locks loosely. Her hands are covered in long silken gloves. A single tiny %^MAGENTA%^violet %^BLUE%^"
"bead rests above her brow. The rest of her body is %^WHITE%^bare%^BLUE%^, however, she reveals little as "
"%^RESET%^%^ORANGE%^branches%^BOLD%^%^BLUE%^, %^GREEN%^leaves%^BLUE%^, and the occasional %^BLACK%^shadow "
"%^BLUE%^conceal her more intimate curves."
"%^BOLD%^%^BLUE%^She holds herself with pride and self assurance. Poised on a single foot, on a slightly bent "
"branch, she poses as if in the midst of %^RESET%^%^CYAN%^dancing%^BOLD%^%^BLUE%^. Her left arm is extended "
"toward the Da%^BLACK%^rkn%^BLUE%^ess ahead, as if beckoning it toward her. Those wide %^CYAN%^s%^BLUE%^a"
"%^RESET%^%^BLUE%^p%^CYAN%^p%^BLUE%^h%^BOLD%^%^WHITE%^i%^BLUE%^r%^CYAN%^e %^BLUE%^orbs stare to something "
"hidden in her right hand, concealed by a mix of shadows and nature. An expression of am%^MAGENTA%^usem"
"%^BLUE%^ent, perhaps, plays across her lips.\n\n"
"%^BOLD%^%^BLUE%^Below, on the %^RESET%^%^ORANGE%^dirt %^BOLD%^%^BLUE%^ground are three silhouettes of people "
"pleading, kneeling, and begging to her.  Vague outlines are all that remain, consumed by the shadows. The "
"details of their existence are lost. Their %^YELLOW%^pleas %^BLUE%^go unheard or are simply ignored by the "
"dancing Elven maiden.\n\n"
"%^BOLD%^%^BLUE%^Within the darkness nearest the young Elven maiden, another figure lies. Slender pointed ears "
"denote his heritage, but his details are also obscured leaving only vague features. Soft glowing %^RED%^r"
"%^RESET%^%^RED%^e%^BOLD%^d %^BLUE%^eyes peer from the shadows while a thick near mane of hair falls to his "
"waist. Traces of %^RESET%^%^RED%^red %^BOLD%^%^BLUE%^are visible throughout the shadows around this "
"particular figure. \n\n"
"         %^BOLD%^%^BLUE%^Beauty and Brilliance given form,\n"
"     %^BOLD%^%^BLUE%^Possessing strength greater than any storm\n"
"      %^BOLD%^%^BLUE%^Shrouded in darkness, protected from pain\n"
"     %^BOLD%^%^BLUE%^Deny her nothing. Her wish, will she gain.\n"
"   %^BOLD%^%^BLUE%^Harbinger of loss, reducing the weak to a husk,\n"
"        %^BOLD%^%^BLUE%^My Little Night, the Daughter of Dusk\n"
"                       %^BOLD%^%^BLUE%^A%^RED%^.%^BLUE%^M%^RED%^.%^BLUE%^A%^RESET%^\n\n"
"                %^BOLD%^%^CYAN%^The Rising Night%^RESET%^\n\n");
        set_value(3000);
        set_weight(1);
        set_lore("%^WHITE%^%^BOLD%^A painting crafted by the hand of the drow Arbaal, upon the 10th of "
"Growingdays, 672 common reckoning.%^RESET%^");
        set_property("lore difficulty",20);
}
