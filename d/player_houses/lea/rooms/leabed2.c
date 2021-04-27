//Coded by Diego//

#include <std.h>
#include "../lea.h"
inherit VAULT;

void create(){
    ::create();
    set_short("Master Bedroom");
    set_long(
    	"%^CYAN%^"+
	"The room is decorated predominantly in %^BOLD%^%^GREEN%^green%^RESET%^.  "+
	"%^CYAN%^The walls are painted %^WHITE%^white%^CYAN%^.  Off in the far corner "+
	"of the room is a manikin with a beautiful gown draped over it.  There is a large "+
	"four poster bed sitting in the middle of the room covered with a "+
	"%^BOLD%^%^GREEN%^green %^RESET%^%^CYAN%^beadspread that is decorated with "+
	"%^YELLOW%^daisies%^RESET%^%^CYAN%^.  Next to the bed is a night table with an oil "+
	"lamp sitting on it.  At the foot of the bed is a large chest.  Off to one side is a "+
	"chiffonier that has been intricately carved from %^ORANGE%^wood%^CYAN%^.  The "+
	"%^ORANGE%^hardwood %^CYAN%^floor is polished to a glossy shine and there is a "+
	"beautifully braided throw %^GREEN%^r%^YELLOW%^u%^WHITE%^g %^RESET%^%^CYAN%^on the "+
	"floor near the bed.  The curtains on the windows match the bedspread. \n"+
	"%^RESET%^"
    );
    set_property("indoors",1);
    set_property("light",2);
    set_smell("default","The room smells clean and fresh with the hint of lamp oil in "+
    		"the air.");
    set_listen("default","The room is quiet.");
    set_items(([
   	"chiffonier" :"\n%^RESET%^This is a narrow, high chest of drawers with a mirror "+
		"attached to the top. \n",
      "rug" : "\n%^RESET%^The %^GREEN%^green %^RESET%^braided rug has sparse patches of "+
		"%^YELLOW%^yellow%^RESET%^ and %^BOLD%^%^WHITE%^white%^RESET%^. \n",
	"gown" : "\n%^RESET%^The front of the gown is a beautiful %^BOLD%^%^BLUE%^blue "+
		"%^RESET%^and %^BOLD%^%^YELLOW%^golden %^RESET%^hand woven silk brocade "+
		"covered with a fine layer of transparent ethereal silk georgette crepe "+
		"flowing over it.  The material covering the breasts is made of beaded and "+
		"embroidered %^BOLD%^%^BLUE%^blue %^RESET%^silk.  The gown itself is made of "+
		"a soft %^BOLD%^%^CYAN%^blue %^RESET%^colored crushed velvet.  The sleeves "+
		"repeat the same pattern having puffed georgette crepe over silk brocade with "+
		"the georgette crepe caressing the bare arms where the sleeves would end.  "+
		"This dress has a graceful, slimming, open laced up back which like the "+
		"borders of the attached overdress are finished in delicate lace trimmings.  "+
		"There is a detachable silk georgette crepe train which adds a fairy like "+
		"quality to this dress.  The dress is decorated with delicate little "+
		"%^BOLD%^%^WHITE%^ivory %^RESET%^braids, laces, and %^BOLD%^%^YELLOW%^gold "+
		"%^RESET%^and %^BOLD%^%^WHITE%^pearl %^RESET%^antique buttons.  All told "+
		"this looks to be a wedding dress. \n",
	"bed" : "\n%^RESET%^This ia a large four poster bed that has been carved from the "+
		"finest %^ORANGE%^oak%^RESET%^.  There is a fancy braided macrame design on "+
		"the headboard and the footboard.  Draped along the top and on the sides is a "+
		"sheer white cotton cloth that reaches the floor.  The bedspread has tiny "+
		"%^BOLD%^%^YELLOW%^daisies%^RESET%^ embroidered into it.  The drapes are "+
		"tied back with a white ribbon that has a macrame design embroidered into it "+
		"as well.  Four large goosedown pillows covered with crisp white linen pillow "+
		"cases adorn the head of the bed.  The bedspread is "+
		"%^BOLD%^%^GREEN%^green%^RESET%^ with tiny white and "+
		"%^BOLD%^%^YELLOW%^yellow%^RESET%^ daisies sewn into the fabric.\n",
      "floor" : "\n%^RESET%^The floor is %^ORANGE%^wooden %^RESET%^and has been buffed "+
      	"and polished to a bright shine.  There is a braided throw rug near the bed.\n",
      "table" : "\n%^RESET%^This is a nightstand and it sits next to the bed.  There are "+
		"fancy designs, matching the macrame designs on the bed, carved into the front "+
		"of the table.\n",
	"lamp" : "\n%^RESET%^A glass oil lamp sits on the table beside the bed.  It appears "+
		"to be placed in such a way as to give off light to illuminate the head of "+
		"the bed.\n",
	"window" : "\n%^RESET%^The curtains sway slightly with the passing of mountain "+
		"breezes through the window.  There are %^BOLD%^%^YELLOW%^yellow%^RESET%^ "+
		"ties holding back the %^BOLD%^%^GREEN%^green%^RESET%^ curtains with "+
		"%^BOLD%^%^YELLOW%^daisy%^RESET%^ embroidery.\n"
        ]));
    
    set_door("east door",LROOMS+"leauphall","west","brass key");
    set_open("east door",1);
    set_string("east door","open","The door swings open to the second floor "+
			"hallway.\n");

    set_exits(([
	"west" : LROOMS+"leauphall"
	]));
}