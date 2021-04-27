#include <std.h>
inherit "/d/common/obj/clothing/magerobe";

void create(){
        int placeholder, *placeholder2;
        ::create();
        set_property("creator","mithras");
        set_property("quality",18);
        set_size(2);
        set_name("coat");
        set_id(({ "overcoat","thin leather overcoat","coat","leather coat","leather overcoat","black coat","black overcoat" }));
        set_short("%^BOLD%^%^BLACK%^slim black leather overcoat%^RESET%^");
        set_long("%^BOLD%^%^BLACK%^Soft thin leather was used in the creation of this tailored black overcoat.  The front of the overcoat features an unbroken silhouette, shaped to wrap "
"closely around a slim torso.  The coat comes to a stop at ones ankles, offering plenty of protection from the elements.  From the waist down the excess fabric of the coat falls about in soft "
"folds.  The long narrow sleeves on the overcoat would keep anyone dry in the worst rains, and the cuffs are %^RESET%^%^RED%^e%^RESET%^%^WHITE%^m%^BOLD%^%^BLACK%^b%^RESET%^%^WHITE%^r%^RED%^o"
"%^BOLD%^%^BLACK%^i%^RESET%^%^WHITE%^d%^RED%^e%^BOLD%^%^BLACK%^r%^RESET%^%^WHITE%^e%^RED%^d %^BOLD%^%^BLACK%^with swirling designs in %^RESET%^%^WHITE%^si%^BOLD%^l%^RESET%^ver %^BOLD%^%^BLACK%^"
"and %^RESET%^%^RED%^red %^BOLD%^%^BLACK%^threads.  Along each side are a row of hidden %^RESET%^%^WHITE%^silver hooks%^BOLD%^%^BLACK%^, allowing one to close the coat without breaking its "
"smooth lines.  The coat has a monastic quality to it, but the leather and small details help to shatter that image somewhat.  Two pockets are hidden in the seams of the coat on either hip"
".%^RESET%^\n\nMastercrafted");
        set_max_internal_encumbrance(21);
}