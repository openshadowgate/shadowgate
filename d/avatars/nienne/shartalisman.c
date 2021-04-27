inherit "/std/armour";

void create() {
    ::create();
    set_name("amulet");
    set_id(({ "chain","talisman","pendant","silver chain","amethyst pendant","talisman of the traveller" }));
    set_short("%^RESET%^%^CYAN%^Tal%^MAGENTA%^i%^CYAN%^sman of the Travel%^MAGENTA%^l%^CYAN%^er%^RESET%^");
    set_obvious_short("%^RESET%^%^CYAN%^a %^RESET%^silver %^CYAN%^chain bearing an %^MAGENTA%^amethyst %^CYAN%^pendant%^RESET%^");
    set_long("%^CYAN%^This amulet is set upon a %^RESET%^sturdy silver chain%^CYAN%^, the links of metal finely wrought so as to curl about each other with ease. The chain bears a single, fairly heavy pendant which consists of two hands also crafted from %^RESET%^silver%^CYAN%^. The gleaming hands curl about either side of a large %^MAGENTA%^amethyst %^CYAN%^gemstone, protectively holding it within their grasp.%^RESET%^\n");
    set_lore("The Talisman of the Traveller was once a cursed amulet, given by an unnamed Sharran priestess to perpetually ensnare a dangerous foe of the faith. Enmarrani of the West Winds, a powerful elven ranger of Shaundakul, accepted the gift which was enchanted to turn his love of travel against him - when invoked, it would snatch him away from wherever he stood to Sigil, the City of Doors. Once there, he was faced with the endless portals leading across the planes. "
"It is said that the centuries of his life were whittled away trying to find his way home to his friends and family, turning his love of travel into an obsession as he invoked the amulet's power again and again in an attempt to try another door. In sad finality to his tale, it is said that he eventually did find his way back to the prime material plane, only to at last meet his end within the underdark before he could find his way home.");
    set_weight(1);
    set_value(5404);
    set_type("ring");
    set_limbs( ({ "neck" }) );
    set_ac(0);
}
