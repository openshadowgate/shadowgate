{
    object* listeners;
    object listener;
    listeners = all_inventory(ETO);
    listeners = filter_array(listeners, (: $1->is_living() :));
    listeners = filter_array(listeners, query_property("detecting_thoughts"));
    if (sizeof(listeners)) {
        foreach(listener in listeners)
        {
            tell_object(listener, "%^BOLD%^%^RED%^TP->QCN tells Someone%^RESET%^: " + msg);
            if (listener->query_property("detecting_thoughts") < TP->query_skill("perception")) {
                tell_object(TP, "%^BOLD%^%^RED%^You sense someone is listening to your thoughts.%^RESET%^");
            }
        }
    }
}
