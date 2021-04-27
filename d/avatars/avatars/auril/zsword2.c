#include <std.h>

inherit "/d/common/obj/weapon/longsword";

void create(){
	::create();
	set_name("crimson sabre");
	set_id(({ "sabre", "blade", "sword", "crimson sabre",
    "weapon" }));
	set_short("%^RESET%^%^BLUE%^T%^RESET%^%^RED%^he "+
    "Bl%^RESET%^%^BLUE%^o%^RESET%^%^RED%^od %^RESET%^of "+
    "%^RESET%^%^BLUE%^Heroes%^RESET%^");
	set_obvious_short("A %^RESET%^%^RED%^crimson %^RESET%^sabre "+
    "with a %^BOLD%^%^BLUE%^je%^BOLD%^%^RED%^well%^RESET%^"+
    "%^GREEN%^ed %^RESET%^handle");

	set_long("%^RESET%^%^RED%^This long, curved sword is "+
    "fashioned of a strange crimson material that gives the "+
    "blade an almost fluid quality.  The hilt and crosspiece "+
    "are fashioned much like a heavily jeweled sabre, "+
    "giving the appearance that the blade was snapped off "+
    "at one point and replaced by the strange red material.  "+
    "A fierce red glow comes from the crismon blade, and "+
    "the whole sword hums with magical energy.%^RESET%^");

	set_value(1000);

    set_lore("The legends that descend through the centuries "+
    "about this weapon suggest that is has a very bloody "+
    "beginning.  Carried into battle against an overwhelming "+
    "horde of enemies by a brave warrior, its was snapped "+
    "off in the mortal wound of a fallen enemy.  Legend says "+
    "that the warrior fell to his knees and shouted for "+
    "help, all his friends slain around him, all hope "+
    "semmed lost, but miracously their very blood quickly "+
    "encompassed the broken weapon and formed what is "+
    "now its crimson blade.");

	set_property("enchantment",4);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
	tell_room(EETO,ETOQCN+" appears "+
    "rallied when "+ETO->QS+" grasps the crimson blade.",ETO);
	tell_object(ETO,"%^BOLD%^%^RED%^Your spirit is "+
    "lifted by the battlecries of the fallen as you "+
    "wield the crimson sword!%^RESET%^");
	return 1;
}
int unwield_func(){
	tell_room(EETO,ETOQCN+" seems to calm down after releasing "+
    "the crimson sword.",ETO);
	tell_object(ETO,"%^BOLD%^%^CYAN%^The cries of the "+
    "fallen linger in your thoughts for a moment as you "+
    "release the crimson sword.%^RESET%^");
	return 1;
}

int hit_func(object targ){
    string limb;
    if(!objectp(targ) return random(5) + 2;
	if(random(1000) < 250) {
    switch(random(23)) {
        case 0..4: 
	        tell_room(EETO,"%^BOLD%^%^CYAN%^Roaring violently, "+
            ETOQCN+"%^BOLD%^%^CYAN%^ rushes toward "+targ->QCN+
            "%^BOLD%^%^CYAN%^ and slashes deftly, cutting %^RESET%^"+
            "%^RED%^deep%^BOLD%^%^CYAN%^.%^RESET%^",({ETO,targ}));

	        tell_object(ETO,"%^BOLD%^%^YELLOW%^The power of the "+
            "fallen warriors of the past flow through you as you "+
            "cut deep into "+targ->QCN+"%^BOLD%^%^YELLOW%^!%^RESET%^");

	        tell_object(targ,"%^BOLD%^%^CYAN%^Roaring violently, "+
            ETOQCN+"%^BOLD%^%^CYAN%^ rushes towards you and slashes "+
            "deftly, cutting %^RESET%^%^RED%^deep%^BOLD%^%^CYAN%^."+
            "%^RESET%^");
        	return roll_dice(1,10);
            break;
        case 5..7:
            tell_room(EETO,ETO->QCN+"%^BOLD%^%^GREEN%^ suddenly "+
            "spins to the left and slashes "+targ->QCN+
            "%^BOLD%^%^GREEN%^!%^RESET%^",({targ,ETO}));

            tell_object(ETO,"%^BOLD%^%^GREEN%^You spin to the "+
            "left and slash "+targ->QCN+"%^BOLD%^%^GREEN%^!"+
            "%^RESET%^");

            tell_object(targ,ETO->QCN+"%^BOLD%^%^GREEN%^ suddenly "+
            "spins to the left and slashes "+targ->QCN+
            "%^BOLD%^%^GREEN%^!%^RESET%^");
            ETO->set_property("magic",1);
            targ->do_damage(targ->return_target_limb(),roll_dice(2,6));
            ETO->set_property("magic",-1);
            break;
        case 8..10:
            tell_room(EETO,ETO->QCN+"%^RED%^'s eye flash "+
            "with a sudden %^YELLOW%^rage%^RESET%^%^RED%^ "+
            "and "+ETO->QS+" ferociously attacks "+targ->QCN+
            "%^RED%^!%^RESET%^",({targ,ETO}));

            tell_object(ETO,"%^RED%^You are suddenly enraged "+
            "and ferociously attack "+targ->QCN+"%^RED%^!%^RESET%^");

            tell_object(targ,ETO->QCN+"%^RED%^'s eyes flash "+
            "with a sudden rage and "+ETO->QS+" ferociously "+
            "attacks you!%^RESET%^");

            targ->set_paralyzed(12 + random(5),"%^RED%^You have "+
            "been thrown off balance by the fierceness of that "+
            "last attack!%^RESET%^");

            return roll_dice(2,4) + random(4);
            break;
        case 11..13:
            limb = targ->return_target_limb();

            tell_room(EETO,ETO->QCN+"%^BOLD%^%^BlACK%^ shouts "+
            "a loud battle cry as "+ETO->QS+" slashes deep into "+
            targ->QCN+"%^BOLD%^%^BLACK%^'s "+limb+
            "%^BOLD%^%^BLACK%^!%^RESET%^",({targ,ETO}));

            tell_object(ETO,"%^BOLD%^%^BLACK%^You shout a loud "+
            "battle cry as you slash deep into "+targ->QCN+
            "%^BOLD%^%^BLACK%^'s "+limb+"%^BOLD%^%^BLACK%^!"+
            "%^RESET%^");

            tell_object(targ,ETO->QCN+"%^BOLD%^%^BLACK%^ shouts "+
            "a loud battle cry as "+ETO->QS+" slashes deep "+
            "into your "+limb+"%^BOLD%^%^BLACK%^!%^RESET%^");
            
            ETO->set_property("magic",1);
            targ->do_damage(limb,roll_dice(2,6));
            ETO->set_property("magic",-1);
            break;
        case 14..17: 
            tell_room(EETO,ETO->QCN+"%^RED%^ strikes "+
            targ->QCN+"%^RED%^ and appears strangely refreshed!",
            ({targ,ETO}));
            
            tell_object(ETO,"%^RED%^You strike "+targ->QCN+" and "+
            "are refreshed by "+targ->QP+" blood!%^RESET%^");

            tell_object(targ,ETO->QCN+"%^RED%^ strikes you and "+
            "appears strangely refreshed!%^RESET%^");

            ETO->add_hp(roll_dice(2,5));
            return roll_dice(2,8) + random(4);
            break;
        case 18..21:
            tell_room(EETO,ETO->QCN+"%^BLUE%^'s crimson sword "+
            "hums loudly as it comes into contact with "+
            targ->QCN+"%^BLUE%^'s flesh!%^RESET%^",({targ,ETO}));

            tell_object(ETO,"%^BLUE%^Your crimson sword "+
            "hums loudly as it comes into contact with "+
            targ->QCN+"%^BLUE%^'s flesh!%^RESET%^");

            tell_object(targ,ETO->QCN+"%^BLUE%^'s crimson sword "+
            "hums loudly as its blade sears your flesh!%^RESET%^");

            ETO->set_property("magic",1);
            targ->do_damage(targ->return_target_limb(),roll_dice(2,5));
            ETO->set_property("magic",-1);
            break;
        case 22:
            tell_room(EETO,ETO->QCN+"%^MAGENTA%^ suddenly spins "+
            "to the right and strikes "+targ->QCN+"%^MAGENTA%^, "+
            "before spinning back to the left for a second "+
            "attack!%^RESET%^",({targ,ETO}));
            
            tell_object(ETO,"%^MAGENTA%^You suddenly spin "+
            "to the right and strike "+targ->QCN+"%^MAGENTA%^, "+
            "then spin back to the left for another attack!"+
            "%^RESET%^");
            
            tell_object(targ,ETO->QCN+"%^MAGENTA%^ suddenly spins "+
            "to the right and strikes you, then spins back "+
            "to the left for another attack!%^RESET%^");
            
            ETO->execute_attack();

            return roll_dice(1,8) + random(4);
            break;
        }
    }
}
