// druid flight form in testing. N, 3/15.
#include <std.h>
#include <daemons.h>
inherit FEAT;

int help();

void create() {
    ::create();
    feat_type("premanent");
    feat_category("WildernessLore");
    feat_name("wild shape bird");
    permanent(1);
    allow_blind(1);
}

int allow_shifted() { return 1; }

int prerequisites(object ob) {
    return 0; // hopefully stops the kids from adding it on their own before it's ready!
    if(!objectp(ob)) { return 0; }
    if(!ob->is_class("druid")) {
        dest_effect();
        return 0;
    }
    if(!FEATS_D->has_feat(ob,"shapeshift")) {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}


void execute_feat() {
    ::execute_feat();
    dest_effect();
}

void permanent_effects(object ob) {
    ::permanent_effects(ob);
    dest_effect();
    return;
}

void reverse_permanent_effects(object ob) {
    ::reverse_permanent_effects(ob);
    dest_effect();
    return;
}

void dest_effect() {
    ::dest_effect();
    remove_feat(TO);
    return;
}

int help() {
    write("%^RESET%^%^BOLD%^Name:           Wild Shape, Bird\n"
          "%^RESET%^%^BOLD%^Type:           %^GREEN%^Permanent\n"
          "%^RESET%^%^BOLD%^Syntax:         %^RESET%^see <help shapeshift>\n"
          "%^RESET%^%^BOLD%^Prerequisites:  %^RESET%^n/a - currently inactive\n\n"
        "%^RESET%^%^BOLD%^\tHaving this feat will allow the character access to the "
        "shapeshift feat.  The shapeshift feat is used to change into animal form.  "
        "<shapeshift bird> will transform the user into a bird.  While in bird form "
        "the character will not be given to particular skills in combat, but will be "
        "able to take flight, moving without leaving a trail.  The shifter will also "
        "be able to travel long distances via the <wing> command.\n\n"
        "%^YELLOW%^Variant forms: raven, owl, hawk, crow, vulture, eagle, falcon.%^RESET%^");
    return 1;
}