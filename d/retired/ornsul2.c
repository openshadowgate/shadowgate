//dragon form of ornsul
#include <std.h>
#include <daemons.h>
#include <magic.h>
inherit MONSTER;

//Attack interval to perform these moves
#define SWIPE_COUNT  5  //Every X claws is a swipe
#define SWEEP_COUNT  5  //Every X tails is a sweep
#define BREATH_COUNT 8  //Every X bites is a breath
#define DEATH_COUNT  9

int breath_count,
    swipe_count,
    sweep_count,
    death_count;
void create(){
    ::create();
    set_id(({"ornsul","dragon","obsidian dragon","druid"}));
    set_name("Ornsul");
    set_short("Ornsul, a hulking deadly obsidian dragon");
    set_long("A long desc for a dagron.");
    set_class("druid");
    set_class("primeval_champion");
    set_guild_level("druid",40);
    set_mlevel("druid",40);
    set_guild_level("primeval_champion",10);
    set_mlevel("primeval_champion",10);
    set_max_hp(3000);
    set_hp(3000);
    set_overall_ac(-10);
    set_stats("strength",22);
    set_stats("intelligence",13);
    set_stats("wisdom",30);
    set_stats("dexterity",23);
    set_stats("constitution",16);
    set_stats("charisma",11);
    set_property("full attacks",1);
    set_base_damage_type("slashing");
    set_attacks_num(7);
    set_damage(3, 8);
    set_alignment(5);
    set_skill("perception",50);  
    add_limb("maw", "right claw", "left claw", "tail", 0);
    set_attack_limbs(({"maw", "right claw", "left claw", "tail"}));
    set_hit_funcs(([ "maw" : (:TO,"bite_attack":), "right claw" : (:TO,"claw_attack":), "left claw" : (:TO,"claw_attack":), "tail" : (:TO,"tail_attack":) ]));
    set_property("damage resistance",20);
    set_property("no hold", 1);
    set_property("no tripped", 1);
    set_property("no paralyze", 1);
    new("/d/retired/obj/orn_badge")->move(TO);
}


string * query_subraces() {
    return ({ "dragon" });
}

int bite_attack(object target)
{  
     if(!target)
        return 0;

    add_hp(10 + roll_dice(50, 4));
       
    breath_count++;
    death_count++;
    
    if(breath_count >= BREATH_COUNT)
        breath_attack(TO, target, 50 * 2);
    if(death_count >= DEATH_COUNT)
        death_attack(TO, target, 50);
        
    
    return roll_dice(1 + (50 / 3), 6);   
}

int claw_attack( object target)
{

    add_hp(10 + roll_dice(50, 4));
   
    swipe_count++;
    
    if(swipe_count >= SWIPE_COUNT)
        swipe_attack(TO, target, 50);
    
    return roll_dice(1 + (50 / 3), 6);
}

int tail_attack(object target)
{
    object room;
           

    add_hp(10 + roll_dice(50, 4));
   
    
    sweep_count++;
    
    if(sweep_count >= SWEEP_COUNT)
        sweep_attack(TO, target, 50);
    
    return roll_dice(1 + (50 / 3), 6);
}

void breath_attack(object player, object target, int clevel)
{
    object room,
           *attackers;
           
    int dam;
    
    if(!player || !target)
        return;
    
    room = environment(player);
    
    if(room != environment(target))
        return;
    
    breath_count = 0;
    
    tell_object(player,"%^ORANGE%^You inhale a deep breath of air, feeling the spark of ignition deep inside of you!");
    tell_room(room,"%^ORANGE%^"+player->QCN+"'s chest swells with a deep breath of air!",player);
    tell_object(player,"%^RED%^You open your mouth and unleash the fury of dragon fire on your foes!");
    tell_room(room,"%^RED%^"+player->QCN+"'s mouth opens and a withering torrent of fire pours forth!",player);
    
    attackers = player->query_attackers();
    attackers = shuffle(attackers);
    attackers = sizeof(attackers) > 8 ? attackers[0..7] : attackers; 
    
    dam = roll_dice(clevel, 10);  
    
    foreach(object ob in attackers)
    {
        if(ob->reflex_save(clevel))
        {
            tell_object(player,"%^MAGENTA%^"+ob->QCN+" is able to dive away at the last instant, avoiding most of the flames!");
            tell_object(ob,"%^MAGENTA%^You dive away at the last instant, avoiding most of the flames!");
            tell_room(room,"%^MAGENTA%^"+ob->QCN+" dives away at the last instant, avoiding most of the flames!",({ player, ob }));
            ob->cause_typed_damage(ob,ob->return_target_limb(),dam/2,"fire");
        }
        else
        {
            tell_object(player,"%^BOLD%^%^RED%^"+ob->QCN+" is seared horribly by the flames!");
            tell_object(ob,"%^BOLD%^%^RED%^You are seared horribly by the flames!");
            tell_room(room,"%^BOLD%^%^RED%^"+ob->QCN+" is seared horribly by the flames!",({ player, ob}));
            ob->cause_typed_damage(ob,ob->return_target_limb(),dam,"fire");
        }
    }
}

void death_attack(object player, object target, int clevel)
{
    object room,
           head;
           
    int dam;
    

    if(!player || !target)
        return;
    
    room = environment(player);
    
    if(room != environment(target))
        return;
    
    death_count = 0;
    
    if(!target->query_property("no death") && !target->fort_save(clevel) && target->query_level() < ( player->query_level() + 10 ))
    {
        head = new("/std/obj/body_part.c");
        head->set_limb(target->query("short"),"head");
        head->move(room);

        tell_object(player,"%^BOLD%^%^BLUE%^You clamp your razor-like jaws onto "+target->QCN+"'s head and grab onto "+target->QO+" with both powerful clawed fists!");
        tell_object(target,"%^BOLD%^%^BLUE%^"+player->QCN+" clamps "+player->QP+" jaws onto your head and grabs your body in "+player->QP+" powerful claws!");
        tell_room(room,"%^BOLD%^%^BLUE%^"+player->QCN+" clamps "+player->QP+" jaws onto "+target->QCN+"'s head and grabs "+target->QP+" body in "+player->QP+" powerful claws!",({ player,target }));

        tell_object(player,"%^RESET%^%^BOLD%^With a mighty heave, you draw your muscular neck back.  You can hear the sound of popping tendons and cracking bones as you %^RED%^pull "
        ""+target->QCN+"'s head free of "+target->QP+" neck%^RESET%^%^BOLD%^!");
        tell_object(target,"%^RESET%^%^BOLD%^You realize in horror as "+player->QCN+" begins to wrench "+player->QP+" neck back, that there's nothing you can do!");
        tell_object(target,"%^RESET%^%^BOLD%^%^RED%^You feel incredible agony in your neck as your spine breaks, and then the world fades into blackness, your life snuffed out!");
        tell_room(room,"%^RESET%^%^BOLD%^You can hear the sound of popping tendons and cracking bones as "+player->QCN+" draws "+player->QP+" powerful neck back, %^RED%^pulling "+target->QCN+"'s "
        "head off of "+target->QP+" shoulders!%^RESET%^",({ player, target }));                                   
        tell_object(player,"%^RESET%^%^BOLD%^%^GREEN%^You toss "+target->QCN+"'s lifeless body aside and crunch the head one final time before spitting it onto the ground!");
        tell_room(room,"%^RESET%^%^BOLD%^%^GREEN%^"+player->QCN+" tosses "+target->QCN+"'s lifeless body aside and crunches "+target->QP+" head before spitting it out on the ground!",({ player, target }));
        target->cause_typed_damage(target,target->return_target_limb(),target->query_max_hp()+400,"untyped");
        target->die();
    }
    else
    {
        tell_object(player,"%^BLUE%^You snap your powerful jaws down at "+target->QCN+"'s head, but "+target->QS+" dodges aside at the last instant, you hit "+target->QP+" shoulder instead!");
        tell_object(target,"%^BLUE%^"+player->QCN+" snaps "+player->QP+" powerful jaws down at your head but you dodge aside at the last instant and "+player->QS+" hits your shoulder instead!");
        tell_room(room,"%^BLUE%^"+player->QCN+" snaps "+player->QP+" powerful jaws down at "+target->QCN+"'s head, but "+target->QS+" dodges aside at the last instant and "+player->QS+" hits "+target->QP+" shoulder instead!",({ player, target }));
        target->cause_typed_damage(target,target->return_target_limb(),roll_dice(clevel,10),"slashing");                    
    }
}

void swipe_attack(object player, object target, int clevel)
{
    object room,
           *attackers;
           
    int dam;
    
    if(!player || !target)
        return;
    
    room = environment(player);
    
    if(room != environment(target))
        return;
    
    swipe_count = 0;
        
    tell_object(player,"%^BOLD%^%^GREEN%^You rake your large claw across, swiping a large arc at your enemies!");
    tell_room(room,"%^BOLD%^%^GREEN%^"+player->QCN+" rakes "+player->QP+" large claw in a wide arc, striking at "+player->QP+" enemies!",player);

    attackers = player->query_attackers();
    attackers = shuffle(attackers);
    attackers = sizeof(attackers) > 8 ? attackers[0..7] : attackers;
    
    dam = roll_dice(clevel, 6);
    
    foreach(object ob in attackers)
    {
        if(ob->reflex_save(clevel))
            tell_object(ob,"%^ORANGE%^"+player->QCN+"'s claw narrowly misses you!");
        else
        {
            tell_object(ob,"%^BOLD%^"+player->QCN+"'s claw strikes you on the way by!");
            ob->cause_typed_damage(ob,ob->return_target_limb(), dam,"slashing");
        }
    }
}

void sweep_attack(object player, object target, int clevel)
{
    object room,
           *attackers;
           
    int dam;
    
    if(!player || !target)
        return;
    
    room = environment(player);
    
    if(room != environment(target))
        return;
    
    sweep_count = 0;
        
    tell_object(player,"%^ORANGE%^You whip your tail around, trying to sweep the feet from under your enemies!");
    tell_room(room,"%^ORANGE%^"+player->QCN+" whips "+player->QP+" tail around, trying to sweep the feet from under "+player->QP+" enemies!",player);

    attackers = player->query_attackers();
    attackers = shuffle(attackers);
    attackers = sizeof(attackers) > 8 ? attackers[0..7] : attackers;
    
    dam = roll_dice(clevel, 8);
    
    foreach(object ob in attackers)
    {
        if(ob->reflex_save(clevel))
        {
            tell_object(player,"%^ORANGE%^Your tail barely misses "+ob->QCN+" on the way by!");
            tell_object(ob,"%^ORANGE%^"+player->QCN+"'s tail barely misses you on the way by!");
            tell_room(room,"%^ORANGE%^"+player->QCN+"'s tail barely misses "+ob->QCN+" on the way by!",({player,ob}));
        }
        else
        {
            tell_object(player,"%^YELLOW%^You catch "+ob->QCN+" with your tail, knocking "+ob->QO+" from "+ob->QP+" feet!");
            tell_object(ob,"%^YELLOW%^"+player->QCN+" catches you with "+player->QP+" tail, knocking you from your feet!");
            tell_room(room,"%^YELLOW%^"+player->QCN+" catches "+ob->QCN+" with "+player->QP+" tail, knocking "+ob->QO+" from "+ob->QP+" feet!",({player,ob}));
            ob->cause_typed_damage(ob,ob->return_target_limb(), dam,"slashing");
            ob->set_tripped(roll_dice(1,6),"%^RESET%^%^YELLOW%^You are struggling to get your feet back under you!");
        }
    }
}
    