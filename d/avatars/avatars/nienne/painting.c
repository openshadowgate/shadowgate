#include <std.h>
inherit OBJECT;

void create(){
        ::create();
        set_name("painting");
        set_id(({"painting"}));
        set_short("%^BOLD%^%^BLUE%^A detailed %^RESET%^%^CYAN%^oil %^BOLD%^%^BLUE%^painting%^RESET%^");
        set_long("%^BOLD%^%^BLUE%^(This is a painting done in a mix of oils with a fine brush and deliberate "
"strokes. The canvas appears to be altered velvet perhaps, yet still sturdy enough to hold the oils without "
"chipping when the painting is rolled up)%^RESET%^\n\n"
"  %^BOLD%^%^BLUE%^Atop %^WHITE%^snow capped %^RESET%^%^ORANGE%^mountains%^BOLD%^%^BLUE%^, i%^CYAN%^c%^BLUE%^y "
"%^RESET%^%^CYAN%^winds %^BOLD%^%^BLUE%^blow. The partially cloudy sky continues to bless the lands with "
"falling snow, even though the rising %^YELLOW%^Sun's r%^RED%^a%^YELLOW%^ys %^BLUE%^battle each flake. A very "
"light, nearly invisible crown of %^WHITE%^white %^BLUE%^and %^CYAN%^light blues %^BLUE%^hangs atop the skies, "
"within the clouds.\n"
"  %^BOLD%^%^BLUE%^Just off center, to the left, stands a proud figure of femininity. Slender and toned, this "
"%^RESET%^%^MAGENTA%^dark figure %^BOLD%^%^BLUE%^is a personification of Elven beauty, but with a smooth "
"%^BLACK%^ebony %^BLUE%^surface. Slender long arms, graceful fingers, waist length %^WHITE%^white %^BLUE%^hair,"
" and long legs with sharp arches and curves make up this maiden's admirable and %^RESET%^%^RED%^s%^MAGENTA%^e"
"%^BLUE%^n%^RED%^s%^MAGENTA%^u%^BLUE%^a%^RED%^l %^BOLD%^%^BLUE%^physique. A victorious smile of perfectly "
"white teeth, matching that of the falling snow, draws attention to this very fit creature's face.\n"
"  %^BOLD%^%^BLUE%^Encircled by thick, dark lashes, her catlike %^MAGENTA%^violet eyes %^BLUE%^stand out "
"against the dark symmetry of her angular face. High, ebony cheekbones, dark as the %^WHITE%^mo%^YELLOW%^onl"
"%^WHITE%^ess %^RESET%^%^BLUE%^night %^BOLD%^angle up towards long, pointed ears while the set of pale blue "
"lips beneath her pert nose combined with the %^CYAN%^bluish tint %^BLUE%^of her cheeks and eyelids makes her "
"look as though she is on the verge of %^CYAN%^fre%^WHITE%^ez%^CYAN%^ing%^BLUE%^.\n"
"  %^BOLD%^%^BLUE%^This elven silhouette stands with her back to the rising %^YELLOW%^S%^RED%^u%^YELLOW%^n"
"%^BLUE%^, looking at what is ahead of her. Long %^WHITE%^sil%^CYAN%^v%^WHITE%^ery hair %^BLUE%^with "
"deliberately placed light %^CYAN%^blue i%^WHITE%^ci%^CYAN%^cl%^WHITE%^es%^BLUE%^, flow in the wind and "
"curling about her while adding a touch of modesty to her %^BLACK%^flawless %^BLUE%^unclothed %^BLACK%^body"
"%^BLUE%^. Small flakes of snow rest upon her unmarred %^BLACK%^o%^RESET%^%^BLUE%^ny%^BOLD%^%^BLACK%^x "
"%^BLUE%^colored flesh. Her left hand is behind her, hiding away whatever secrets are held there for only "
"those following her to see. She is motioning ahead, her right hand pointing in a casual yet commanding way. "
"She appears accustomed to authority. A pairing of armbands crafted from a crystalline %^WHITE%^white "
"%^BLUE%^and %^RESET%^%^BLUE%^blue %^BOLD%^are the only adornment upon her toned yet visually delicate form.\n"
"  %^BOLD%^%^BLUE%^S%^BLACK%^ha%^BLUE%^do%^BLACK%^ws %^BLUE%^dance around this detailed figure with purpose. "
"Her own shadow reaches out extinguishing many of the %^YELLOW%^S%^RED%^u%^YELLOW%^n's rays %^BLUE%^that "
"attempt to touch her dark skin and perfectly %^WHITE%^white snow flakes%^BLUE%^. A multitude of caves become "
"more readily apparent in the background, all possessing slight %^RED%^red orbs %^BLUE%^that wait for "
"something.%^RESET%^\n\n"
"       %^BOLD%^%^BLUE%^To she that reminds me why I left\n"
"         %^BOLD%^%^BLUE%^And what I always return for\n"
"           %^BOLD%^%^BLUE%^A glimpse into the future\n"
"              %^BOLD%^%^BLUE%^Of your aspirations\n"
"                  %^BOLD%^%^BLUE%^May success\n"
"                   %^BOLD%^%^BLUE%^Be yours\n"
"                     %^BOLD%^%^BLUE%^With,\n"
"                      %^BOLD%^%^BLUE%^Me\n\n"
"                    %^BOLD%^%^BLUE%^A%^RED%^.%^BLUE%^M%^RED%^.%^BLUE%^A%^RESET%^\n\n");
        set_value(3000);
        set_weight(1);
        set_lore("%^WHITE%^%^BOLD%^A painting crafted by the hand of the drow Arbaal, upon the 21st of "
"Sundays, 671 common reckoning.%^RESET%^");
        set_property("lore difficulty",20);
}
