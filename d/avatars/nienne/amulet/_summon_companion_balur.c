// Balur spell copy - warlock, can't summon a minion anymoar for arpees! N, 12/16
inherit "/cmds/spells/s/_summon_companion";

void create() {
    ::create();
    set_spell_name("summon companion balur");
    set_spell_level(([ "warlock" : 1 ]));
}

void spell_effect(int prof) {
   new("/d/avatars/nienne/amulet/scompanionbalur")->move(caster);
   dest_effect();
}