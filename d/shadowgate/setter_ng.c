#include <std.h>

// string *setter_chain = ({"class", "race", "subrace", "template", "stats", "hair_color", "eye_color", "height", "weight", "body_type", "age", "alignment", "class_special", "language", "deity"});

string *setter_chain = ({"class", "race", "subrace",});
mapping setter_info = ([]);

string stage = "class";

string *selection_cache;

overview()
{
    string k;

    /* foreach(k in setter_chain) { */
    /*     if (!call_other(TO, "display_" + k)) */
    /*         write(capitalize(replace_string(k, "_", "")) + ": " + setter_info[k]); */
    /*     } */
    /* } */
}

show_selection(string *slc)
{
    string * tmp = slc;
    map(tmp, (:"  " + capitalize($1):));
    write(implode(tmp, "\n"));
}

edit_class(string args)
{
    if (!sizeof(selection_cache))
    {
        string *possible_classes;
        possible_classes = get_dir("/std/class/*.c");
        possible_classes = map(possible_classes, (:"/std/class/" + $1:));
        possible_classes = filter_array(possible_classes, (:!$1->is_prestige_class():));
        possible_classes = filter_array(possible_classes, (:!$1->is_locked_class():));
        possible_classes = replace_string(possible_classes, ".c", "");
        possible_classes = replace_string(possible_classes, "/std/class/", "");
        selection_cache = possible_classes;
    }
}
