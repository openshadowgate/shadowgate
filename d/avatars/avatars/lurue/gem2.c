#include <std.h>

#define QUERY_NAME query_cap_name
inherit OBJECT;
int uses;
void init() {
    ::init();
    add_action("view_func","view");
}
void create() {
    ::create();
set_id(({"blue topaz","gem","gem of true seeing"}));
    set_name("Gem of true seeing");
set_obvious_short("%^BOLD%^%^BLUE%^a %^CYAN%^s%^WHITE%^a%^BLUE%^p%^CYAN%^ph%^WHITE%^i%^BLUE%^r%^CYAN%^e %^BLUE%^blue gem%^RESET%^");
set_short("%^BOLD%^%^CYAN%^G%^BLUE%^e%^CYAN%^m %^WHITE%^o%^BLUE%^f %^CYAN%^R%^WHITE%^e%^BLUE%^v%^CYAN%^eal%^WHITE%^i%^BLUE%^n%^CYAN%^g%^RESET%^");
set_long("%^BOLD%^%^BLUE%^This %^CYAN%^s%^WHITE%^a%^BLUE%^p%^CYAN%^ph%"+
"^WHITE%^i%^BLUE%^r%^CYAN%^e %^BLUE%^blue gem is quite large,"+
" nearly the size of a man's fist, and yet, it has been cut in"+
" such a way that it is easy to hold in the palm of one's fist. "+
"Glowing with an subtle %^CYAN%^i%^WHITE%^n%^BLUE%^n%^CYAN%^er "+
"l%^WHITE%^i%^BLUE%^g%^CYAN%^ht %^BLUE%^that appear to reveal "+
"the world as it really is, the gem could probably help someone"+
" %^CYAN%^<%^WHITE%^view%^CYAN%^>%^BLUE%^ an area or even "+
"%^CYAN%^<%^WHITE%^view %^CYAN%^[%^WHITE%^direction%^CYAN%^"+
"]>%^BLUE%^.%^RESET%^");
   set_weight(10);
   set_value(1200);
  uses = 12;
}
int view_func(string str) {
    int i,x,FLAG;
    object locale,*inv,*exits;
    string desc,where;
	
   uses--;
    if (!str) {
        locale = environment(TP);
        desc = (string)locale->query_long()+"\n";
        inv = all_inventory(locale);
        for(i=0; i<sizeof(inv); i++) {
           if(avatarp(inv[i]) && (inv[i]->query_true_invis())) continue;
            if(inv[i]->query_property("no detect")) continue;
            if(inv[i]->query_invis()) {
	        desc += "(";
	        desc += (string)inv[i]->QUERY_NAME()+")\n";
	    } else {
                desc += (string)inv[i]->query_short()+"\n";
            }
        }
        write(
            "%^CYAN%^You concentrate while peering through the gem."
            "\n%^MAGENTA%^"+desc+"%^RESET%^"
        );
        say(
            "%^CYAN%^"+TPQCN+" peers through a gem.%^RESET%^"
        ,TP);
     if(uses < 1) call_out("remove",1);
        return 1;
    }
    where = str;
    exits = environment(TP)->query_exits();
    if(member_array(where, exits) == -1){
        FLAG = 0;
    } else {
        FLAG = 1;
        locale = environment(TP)->query_exit(where);	
        locale = find_object_or_load(locale);
    }
    if(FLAG == 0) {
	write(
	    "%^CYAN%^You cannot view anything there!%^RESET%^"
	);
      if(uses < 1) call_out("remove",1);
        return 1;
    } else {
        desc = (string)locale->query_long()+"\n";
        inv = all_inventory(locale);
        for(i=0; i<sizeof(inv); i++) {
           if(avatarp(inv[i]) && (inv[i]->query_true_invis())) continue;
            if(inv[i]->query_property("no detect")) continue;
            if(inv[i]->query_invis()) {
	        desc += "(";
	        desc += (string)inv[i]->QUERY_NAME()+")\n";
	    } else {
                desc += (string)inv[i]->query_short()+"\n";
            }
        }
        write(
            "%^CYAN%^You concentrate while peering through the gem."
            "\n%^MAGENTA%^"+desc+"%^RESET%^"
        );
        say(
            "%^CYAN%^"+TPQCN+" peers through a gem.%^RESET%^"
        ,TP);
      if(uses < 1) call_out("remove",1);
        return 1;
    }       
}	
