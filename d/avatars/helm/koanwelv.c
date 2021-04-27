#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("manuscript");
	set_id(({ "manuscript" }));
	set_short("%^RESET%^%^ORANGE%^an old manuscript%^RESET%^");
	set_obvious_short("%^RESET%^%^ORANGE%^an old manuscript%^RESET%^");
	set_long(
@AVATAR
This is an old manuscript written in the common tongue with the flourish and touch of a skilled writer. The paper has yellowed with age but it has been kept in a remarkably good condition and it is still fully readable.

AVATAR
	);
	set("read",
@AVATAR
%^ORANGE%^The story of Sir Koandar Welvarn


%^ORANGE%^Koandar Welvarn was born in the small kingdom of Tabor in the year of the Headless Snake 422 SG.

%^ORANGE%^House Welvarn was rich and owned large properties in Tabor and Tharis. Thus Koandar Welvarn was brought up in relative safety and luxury among the other young nobles in Tabor. Following his eighteenth birthday he was knighted and given the trust to hold a southern outpost of Tabor against the Tsarvani Empire that had recently developed a more expansive strategy.

%^ORANGE%^Koandar Welvarn was brave but foolish and the Tsarvani Empire soon took the outpost, thus laying the ground for the settlement we today know as Imperial Azha. 

%^ORANGE%^They captured Sir Welvarn and imprisoned him together with the other survivors. 

%^ORANGE%^During his years in the Tsarvani Empire Koandar Welvarn came in touch with the faith of Torm though his enforced contact with other prisoners from across the distant lands of the Empire.  In particular he spent a great deal of time speaking with a young priest who visited the prison compound regularly to offer a chance of salvation to all there.  The knightly virtues preached by the young man appealed to sir Welvarn's noble upbringing, and the priests conviction and unshakeable faith carried great weight.

%^ORANGE%^When the Empire found itself under attack by brigands and bandits along its borders, many prisoners including Koandar Welvarn were given the opportunity to win back their freedom through loyal and brave service to the Emperor to ensure the safety and well being of the citizens in the border towns and villages.

%^ORANGE%^This was the final step for sir Welvarn, having seen the Tormish virtues he had seen preached over the past years put into practice as the men and women around him fought bravely to protect the lives of innocent civilians. Upon leaving the prison compound that had been his home he forestalled his journey homeward and travelled directly to the temple of Torm in the heart of the Tsarvani empire and there swore a sacred oath to dedicate himself to Torm's service.

%^ORANGE%^When he was able to leave the Empire once again a free man he pledged that he would serve his Lord Torm and ensure that the people of his homeland would have a place to worhip and study the faith.  He travelled north though the lands of the Empire for many months until he reached the site the outpost he had defended years earlier.  Thus Sir Welvarn thrust his blade into the rich soil and claimed the area in the name of the Lord of Duty. Later in 453SG he commissioned the building of a temple on the very same place on the border of vast Tsarvani Empire and the lands of Shadow's Gate.

%^ORANGE%^It is belived that it was following several meetings with Sir Welvarn that the esteemed elven scholar Sualvi Arahyshuosa first composed his essay on Knighthood and Paladinhood from which extracts of his 'Commandments of Knighthood' have been translated into many different languages.


%^ORANGE%^The Commandments of Knighthood:

%^ORANGE%^1. Thou shalt believe all that the church teaches you and obey all of the churches commandments
%^ORANGE%^2. Thou shalt defend the church
%^ORANGE%^3. Thou shalt respect all innocents and shall constiturte thyself defender of them
%^ORANGE%^4. Thou shalt love the country in which thou wast born
%^ORANGE%^5. Thou shalt not recoil before thine enemy
%^ORANGE%^6. Thou shalt make war against the darkness without cessation
%^ORANGE%^7. Thou shalt perform scrupulously the thine religious and social duties
%^ORANGE%^8. Thou shalt never lie, and shalt remain faithful to thine pledged word

%^ORANGE%^9. Thou shalt be generous, and give largesse to everyone
%^ORANGE%^10. Thou shalt be everywhere and always the champion of the Right and the Good against injustice and evil

AVATAR
	);
     set("langage","str");	set_weight(1);
	set_value(0);
}