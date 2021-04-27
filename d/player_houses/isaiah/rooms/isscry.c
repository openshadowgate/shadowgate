//Coded by Diego//

#include <std.h>
#include <daemons.h>
#include "../isaiah.h"
inherit "/std/lab";

void create(){
	object ob;
    	::create();
   set_terrain(BRANCHES);
   set_travel(STAIRWAY);

    	set_short("Scrying Room");
/*    	set_long(
    		"%^RESET%^%^GREEN%^"+
    		"You have stumbled upon a place of "+
		"%^BOLD%^%^BLUE%^f%^MAGENTA%^a%^BLUE%^i%^MAGENTA%^r%^BLUE%^y "+
		"%^MAGENTA%^m%^BLUE%^a%^MAGENTA%^g%^BLUE%^i%^MAGENTA%^c%^RESET%^%^GREEN%^.  "+
		"%^ORANGE%^Branches %^GREEN%^covered with leaves snake their way toward the "+
		"sky.  From here one can view the %^BOLD%^%^BLUE%^heavens "+
		"%^RESET%^%^GREEN%^unimpeded by any of the limbs of nearby trees.  Hanging "+
		"from the limbs in the area are "+
		"%^BOLD%^%^YELLOW%^c%^BLUE%^o%^RED%^l%^YELLOW%^o%^BLUE%^r%^RED%^f"+
		"%^YELLOW%^u%^BLUE%^l "+
		"%^RED%^p%^YELLOW%^o%^BLUE%^t%^RED%^i%^YELLOW%^o%^BLUE%^n%^RED%^s "+
		"%^RESET%^%^GREEN%^and other "+
		"%^BOLD%^%^BLUE%^m%^MAGENTA%^a%^BLUE%^g%^MAGENTA%^i%^BLUE%^c%^MAGENTA%^a"+
		"%^BLUE%^l %^RESET%^%^GREEN%^items always just out of your reach.  You see "+
		"a large %^BOLD%^%^BLUE%^ornate mirror %^RESET%^%^GREEN%^that appears to be "+
		"grown into one of the thickest branches of the tree near to the trunk.  "+
		"Several tiny %^YELLOW%^l%^MAGENTA%^ights %^YELLOW%^f%^MAGENTA%^lit "+
		"%^RESET%^%^GREEN%^about this area providing an "+
		"%^MAGENTA%^eerie%^RESET%^%^GREEN%^, yet %^MAGENTA%^enchanting"+
		"%^RESET%^%^GREEN%^, atmosphere.\n"+
    		"%^RESET%^"
    		);*/
      set_long((:TO,"long_desc":));
    	set_property("indoors",0);
    	set_property("light",2);
    	set_smell("default","The pleasant smells of the greenery fill the area.");
    	set_listen("default","Aside from the sounds drifting up from the forest a "+
    		"lilting sound, somewhat like singing, can be heard coming from the mirror.");
     	set_items(([
        	"mirror" : "The mirror seems to be a part of the tree.  It is finely made "+
        		"and the surface is flawless, almost liquid in appearance.\n",
        	({"lights","tiny lights"}) : "The little lights move about flitting from "+
        		"branch to branch, leaf to leaf.  With their constant motion you are "+
			"unable to tell whether they are little fairy spirits or just bugs.  "+
			"Whatever they are they are no less wondrous for your lack of "+
			"information.\n",
		({"potions","potion","items","item","magical Items","magical item"}) : "These "+
			"items seem to be hanging within your grasp, but as you reach out for "+
			"them they appear to be a little further away teasing you with their "+
			"closeness and their elusiveness.\n",
		({"branches","branch"}) : "The branches reach to the sky, but something "+
			"looks different about them in this light.\n"
      ]));
      ob = new("/d/magic/obj/mirror");
      ob->move(TO);

	set_search("branches","The branches reach skyward and all look as you would "+
		"expect except for one branch that is near the mirror.  This branch "+
		"stands alone and is a little lighter in color.\n");
	set_search("branch","This branch is different upon closer examination.  Near the "+
		"base is is a light color than the rest of the branch.  It looks as if it "+
		"has been rubbed, but not rubbed so hard it has been damaged, more like "+
		"polished.\n");
        setOwner("isaiah");
        setLabId("isaiah");
}
void init() {
  	::init();
 	add_action("open_em","open");
 	add_action("close_em","close");
 	add_action("rub_em","rub");
}
int close_em(string str) {
    	if(!str) {
        	tell_object(TP,"Close what?");
        	return 1;
    	}
  	if((str == "trapdoor") || (str=="trap door")){
      	if(member_array("down",TO->query_exits()) != -1) {
     			tell_object(TP,"You pull up the trap door upward and latch it closed!\n");
     			tell_room(ETP,""+TPQCN+" pulls the trap door up and latches it "+
     				"closed.\n",TP);
     			remove_exit("down");
     			(IROOMS+"iscom")->remove_exit("up");
            	return 1;
            }
     		tell_object(TP,"The trap door is already closed!\n");
    		return 1;
     }
}
int open_em(string str) {
    	if(!str) {
        	tell_object(TP,"Open what?");
        	return 1;
    	}
  	if((str == "trapdoor") || (str=="trap door")){
     		if(member_array("down",TO->query_exits()) != -1) {
        		tell_object(TP,"The trap door is already open! \n");
            	return 1;
            }
     		tell_object(TP,"You unlatch and let the trap door fall open.\n");
     		tell_room(ETP,""+TPQCN+" unlatches the trap door and lets it fall open.\n",TP);
     		add_exit(IROOMS+"iscom","down");
     		(IROOMS+"iscom")->add_exit(IROOMS+"isscry","up");
     		return 1;
     }
}
int rub_em(string str) {
    	if(!str) {
        	tell_object(TP,"Rub what???");
        	return 1;
    	}
    	if(str == "branch"){
    		tell_object(TP,"The branch tries to move away from your rough handling!\n");
    		tell_room(ETP,"the branch visibly moves away from "+TPQCN+"'s touch!\n",TP);
    		return 1;
    	}
  	if(str == "branch gently"){
     		tell_object(TP,"You rub the branch softly and tenderly as if coaxing the "+
     			"wood to surrender to you.\n");
     		tell_room(ETP,""+TPQCN+" starts to gently rub on the lone branch of wood "+
     			"as if caressing it and cajoling it to do his bidding.\n",TP);
     		tell_object(TP,"The wood shudders under your touch as though it knows you and "+
     			"as if your touch comforts it.  After a moment a wooden key drops to the "+
     			"ground at your feet.\n");
     		tell_room(ETP,"The branch quivers under "+TPQCN+"'s touch and after a bit an "+
     			"object drops to the ground at "+TPQCN+"'s feet.\n",TP);
     		new(ISTUFF+"woodkey")->move(TO);
		TP->force_me("get key");
     		return 1;
     	}
}

string long_desc() {
   switch(season(time())) {
     case "spring":
     return("%^GREEN%^This place of fairy magic has begun to sprout new leaves with spring.  Bud covered "
"%^MAGENTA%^branches %^GREEN%^snake twoards the sky.  Tiny new leaves are unfurling with each day, warming "
"under the light of the spring sun. There are many tiny %^MAGENTA%^lights%^GREEN%^ that float about "
"strangely.  Many %^MAGENTA%^potions%^GREEN%^ and other strange %^MAGENTA%^items%^GREEN%^ hang on the ends of "
"the branches.  A small part of the canopy is open to the sky above, like a window framed by leaves.  A large "
"%^MAGENTA%^ornate mirror%^GREEN%^ stands to one side, circled by full blooming leaves.  The first leaves to "
"mature this year.%^RESET%^\n");
     break;
     case "summer":
     return("%^BOLD%^%^GREEN%^The fairy magic has complemented this maple tree in its summer glory.  Leaf "
"covered %^YELLOW%^branches %^GREEN%^snake towards the sky.  The maple leaves fully grown now all but block "
"out the view of the surrounding terrain  There are many tiny %^YELLOW%^lights%^GREEN%^ that float about "
"strangely.  Many %^YELLOW%^potions%^GREEN%^ and other strange %^YELLOW%^items%^GREEN%^ hang on the ends of "
"branches.  A small part of the canopy is open to the sky above, like a window framed by leaves.  A large "
"%^YELLOW%^ornate mirror%^GREEN%^ stands to one side, circled by full thick leaves.%^RESET%^\n");
     break;
     case "autumn":
     case "fall":
     return("%^ORANGE%^Though fall is causing the leaves to fall, this place of fairy magic still leaves one "
"in awe.  The %^GREEN%^branches%^ORANGE%^ are bare save for some golden leaves that remain.  With the cold "
"coming, all but a few leaves have fallen.  Many %^GREEN%^potions %^ORANGE%^and other strange %^GREEN%^items"
"%^ORANGE%^ hang on the ends of branches.  There are many tiny %^GREEN%^lights%^ORANGE%^ that float about "
"strangely.  A small part of the canopy is open to the sky above, like a window framed by branches.  A large "
"%^GREEN%^ornate mirror%^ORANGE%^ stands to one side, circled by wilting leaves.%^RESET%^\n");
     break;
     case "winter":
     return("%^CYAN%^Though winter leaves the tree's %^WHITE%^branches%^CYAN%^ bare of leaves, this place of "
"fairy magic still leaves one in awe.  With the cold here all of the leaves have fallen to the ground.  Many "
"%^WHITE%^potions%^CYAN%^ and other strange %^WHITE%^items%^CYAN%^ hang on the ends of branches.  There are "
"many tiny %^WHITE%^lights%^CYAN%^ that float about strangely.  A small part of the canopy is open to the sky "
"above, like a window framed by branches.  It is not rare for the tree to have frost on it or to be coated in "
"snow.  A large %^WHITE%^ornate mirror%^CYAN%^ stands to one side, circled by wilted leaves.%^RESET%^\n");
     break;
     default:
     return("%^GREEN%^Something is wrong with the seasons in this room, please contact a wiz.%^RESET%^\n");
     break;
   }
}

int is_human(object ob) {
   if((string)ob->query_race() == "human") return 1;
   else return 0;
}

void reset() {
   object *stuff, *keeping, thetarget;
   int i;
   ::reset();
   if(random(100) > 50) {
     stuff = all_living(TO);
     if(sizeof(stuff)) keeping = filter_array(stuff,"is_human",TO);
     if(sizeof(keeping)) {
       thetarget = keeping[random(sizeof(keeping))];
       i = roll_dice(1,20);
       switch(random(100)) {
         case 0..24:
           if(i > (int)thetarget->query_stats("dexterity") || i == 20) {
             tell_object(thetarget,"%^ORANGE%^The %^CYAN%^wind %^ORANGE%^picks "
"up and the tree creaks, limbs waving in the breeze. Suddenly and violently, "
"the %^RED%^branch %^ORANGE%^beneath your feet shifts and you find yourself "
"falling!%^RESET%^");
             tell_room(TO,"%^ORANGE%^The %^CYAN%^wind %^ORANGE%^picks up and "
"the tree creaks, limbs waving in the breeze. Suddenly and violently, the "
"%^RED%^branch %^ORANGE%^beneath "+thetarget->QCN+"%^RESET%^%^ORANGE%^'s feet "
"shifts and "+thetarget->QS+" tumbles from view!%^RESET%^",thetarget);
             tell_object(thetarget,"%^BOLD%^%^GREEN%^You tumble down the rock "
"face bouncing and cursing all the way!%^RESET%^");
             thetarget->do_damage("torso",roll_dice(6,6));
             thetarget->move("/d/dagger/derro/rooms/a1");
           }
           else {
             tell_object(thetarget,"%^ORANGE%^The %^CYAN%^wind %^ORANGE%^picks "
"up and the tree creaks, limbs waving in the breeze. Suddenly and violently, "
"the %^RED%^branch %^ORANGE%^beneath your feet shifts and you barely manage to "
"catch yourself to avoid falling!%^RESET%^");
             tell_room(TO,"%^ORANGE%^The %^CYAN%^wind %^ORANGE%^picks up and "
"the tree creaks, limbs waving in the breeze. Suddenly and violently, the "
"%^RED%^branch %^ORANGE%^beneath "+thetarget->QCN+"%^RESET%^%^ORANGE%^'s feet "
"shifts and "+thetarget->QS+" barely manages to catch "+thetarget->QO+"self to "
"avoid falling!%^RESET%^",thetarget);
           }
         break;

         case 25..49:
           if(i > (int)thetarget->query_stats("wisdom") || i == 20) {
             tell_object(thetarget,"%^BLUE%^A light creak is all the warning "
"given before a shower of %^GREEN%^leaves %^BLUE%^and debris rains down on "
"you from above, leaving you coated in chips of %^RED%^bark %^BLUE%^and "
"%^ORANGE%^sticky tree sap%^BLUE%^.%^RESET%^");
             tell_room(TO,"%^BLUE%^A light creak is all the warning given "
"before a shower of %^GREEN%^leaves %^BLUE%^and debris rains down on "
+thetarget->QCN+"%^BLUE%^ from above, leaving "+thetarget->QO+" coated in "
"chips of %^RED%^bark %^BLUE%^and %^ORANGE%^sticky tree "
"sap%^BLUE%^.%^RESET%^",thetarget);
             thetarget->set_paralyzed(11,"You're still trying to get free of "
"the twigs and tree-sap!");
           }
           else {
             tell_object(thetarget,"%^BLUE%^You notice a light creak in the "
"branches above your head, and step out of the way as a shower of "
"%^GREEN%^leaves %^BLUE%^and debris rains down from above.%^RESET%^");
             tell_room(TO,"%^BLUE%^You notice a light creak in the branches "
"above your head, and "+thetarget->QCN+"%^RESET%^%^BLUE%^ steps out of the "
"way as a shower of %^GREEN%^leaves %^BLUE%^and debris rains down from "
"above.%^RESET%^",thetarget);
           }
         break;

         case 50..74:
           if(i > (int)thetarget->query_stats("dexterity") || i == 20) {
             tell_object(thetarget,"%^CYAN%^A %^ORANGE%^sturdy branch "
"%^CYAN%^snaps out in the wind and whistles through the air, collecting you as "
"it swings past and sending you sprawling!%^RESET%^");
             tell_room(TO,"%^CYAN%^A %^ORANGE%^sturdy branch "
"%^CYAN%^snaps out in the wind and whistles through the air, collecting "
+thetarget->QCN+" as it swings past and sending "+thetarget->QO+
" sprawling!%^RESET%^",thetarget);
             thetarget->do_damage("torso",roll_dice(6,6));
             thetarget->set_tripped(2,"You're still trying to get back on your "
"feet.");
           }
           else {
             tell_object(thetarget,"%^CYAN%^A %^ORANGE%^sturdy branch "
"%^CYAN%^snaps out in the wind and whistles through the air, nearly collecting "
"you as it swings past!%^RESET%^");
             tell_room(TO,"%^CYAN%^A %^ORANGE%^sturdy branch "
"%^CYAN%^snaps out in the wind and whistles through the air, nearly collecting "
+thetarget->QCN+" as it swings past!%^RESET%^",thetarget);
           }
         break;

         case 75..99:
           if(i > (int)thetarget->query_stats("strength") || i == 20) {
             tell_object(thetarget,"%^GREEN%^Looking down, you realise your leg has become entangled in a nearby branch.  You're not sure quite how it got there, but it is now quite %^RED%^stuck%^GREEN%^!%^RESET%^");
             tell_room(TO,"%^GREEN%^Looking down, you realise "+thetarget->QCN+
"'s leg has become entangled in a nearby branch, and it is now quite "
"%^RED%^stuck%^GREEN%^!%^RESET%^",thetarget);
             thetarget->set_tripped(3,"You're still trying to pull your leg "
"free of the branch.");
           }
           else {
             tell_object(thetarget,"%^GREEN%^Looking down, you realise your "
"leg has become entangled in a nearby branch.  You're not sure quite how it "
"got there, but fortunately you are able to pull it free without much "
"trouble.%^RESET%^");
             tell_room(TO,"%^GREEN%^Looking down, you realise "+thetarget->QCN+
"'s leg has become entangled in a nearby branch.  Fortunately, "+thetarget->QS+ " is able to pull it free without much trouble.%^RESET%^",thetarget);
           }
         break;
       }
     }
   }

   if(query_night() && !present("butterfly")) {
     for(i=0;i<(random(5)+2);i++) 
       new("/d/player_houses/mons/shry_butterfly")->move(TO);
   }
}
