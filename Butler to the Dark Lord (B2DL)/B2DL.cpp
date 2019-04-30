/*
    B2DL.cpp
    Brandon George, CISP360
    10/28/18
 */

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//  Specification A2 - No Global Variables
//  Specification B5 - Function Prototype
int A1(), A100(), A167(), A232(), A13(bool diplomat), A290(), A159(),
    A161(), A173(), A212(), display(), menu(bool one, bool two, bool three);

/*
 Materials cited:
 Bowring, Sam. Butler to the Dark Lord: A Grim Choices Gamebook
 (Kindle Locations 36-49). Sam Bowring. Kindle Edition.
 */

int main () {
    
    //  Program Greeting
    cout << "Butler to the Dark Lord" << endl;
    cout << "-----------------------" << endl;
    cout << "The choose your own adventure game." << endl;
    cout << "Let's begin!" << endl << endl;
    
    //  Specification A4 - Alternative Ending
    bool restart = 1;
    while (restart == 1) {
        bool altEnding = 0, intimidator = 0, diplomat = 0,
             dirtyChair = 0, gratefulHaiken = 0;
        int menuSelect;
        
        //  Functions relating to variables
        bool a1 = 0, a100 = 0, a167 = 0, a232 = 0, a13 = 0,
             a290 = 0, a159 = 0, a161 = 0, a173 = 0, a212 = 0;
        
        menuSelect = A1();
        a1 = 1;
        if (menuSelect == 1) {
            menuSelect = A100();
            a100 = 1;
            intimidator = 1;
        } else if (menuSelect == 2) {
            menuSelect = A167();
            a167 = 1;
            diplomat = 1;
        }
        menuSelect = A232();
        a232 = 1;
        if (menuSelect == 1) {
            menuSelect = A13(diplomat);
            a13 = 1;
            if (menuSelect == 1) {
                menuSelect = A212();
                a212 = 1;
                gratefulHaiken = 1;
                menuSelect = A161();
                a161 = 1;
                dirtyChair = 1;
            } else if (menuSelect == 2) {
                menuSelect = A159();
                a159 = 1;
            } else if (menuSelect == 3) {
                menuSelect = A173();
                a173 = 1;
            }
        } else if (menuSelect == 2) {
            menuSelect = A290();
            a290 = 1;
            menuSelect = A161();
            a161 = 1;
            dirtyChair = 1;
        }
        
        //  Specification B1 - Booleans
        cout << "------" << endl;
        cout << "Score:" << endl;
        cout << "------" << endl;
        cout << "Intimidator: " << intimidator << endl;
        cout << "Diplomat: " << diplomat << endl;
        cout << "Chair is Dirty: " << dirtyChair << endl;
        cout << "Haiken is Grateful: " << gratefulHaiken << endl << endl;
        
        //  Specification B2 - Paths
        cout << "-----" << endl;
        cout << "Path: " << endl;
        cout << "-----" << endl;
        
        //  Specification D3 - Coded Without Functions, Just If Statements
        if (a1) {
            cout << "A1";
        }
        if (a100) {
            cout << "A100";
        }
        if (a167) {
            cout << "A167";
        }
        if (a232) {
            cout << "A232";
        }
        if (a13) {
            cout << "A13";
        }
        if (a290) {
            cout << "A290";
        }
        if (a212) {
            cout << "A212";
        }
        if (a159) {
            cout << "A159";
        }
        if (a173) {
            cout << "A173";
        }
        if (a161) {
            cout << "A161";
        }
        cout << endl << endl;
        
        //  Specification A4 - Alternative Ending
        display();
        if (a290) {
            cout << "Would you like to see what would've happened if you served Captain Haiken 1st?" << endl;
        } else {
            cout << "Would you like to see what would've happened if you served master Malacandros 1st?" << endl;
        }
        cout << "Enter 1 to see alternate ending or 0 to finish game: ";
        cin >> altEnding;
        
        while (restart != 1 && restart != 0) {
            cout << "Select 1 or 0 to continue: ";
            cin >> altEnding;
        }
        cout << endl << endl;
        
        if (altEnding == 1) {
            if (a290) {
                menuSelect = A13(diplomat);
                a13 = 1;
                if (menuSelect == 1) {
                    A212();
                    a212 = 1;
                    gratefulHaiken = 1;
                    A161();
                    a161 = 1;
                    dirtyChair = 1;
                } else if (menuSelect == 2) {
                    A159();
                    a159 = 1;
                } else if (menuSelect == 3) {
                    A173();
                    a173 = 1;
                }
            } else {
                menuSelect = A290();
                a290 = 1;
                menuSelect = A161();
                a161 = 1;
                dirtyChair = 1;
            }
    }
        //  Specification A3 - Game Loop
        cout << "Restart game?" << endl;
        cout << "Choose 1 to restart or 0 to end the game: ";
        cin >> restart;
        
        while (restart != 1 && restart != 0) {
            cout << "Select 1 or 0 to continue: ";
            cin >> restart;
            cout << endl << endl;
        }
    }
        return 0;
}
    //  Specification C2 - Simple Menu
    //  Specification B4 - General Menu
    int menu(bool one, bool two, bool three) {
        if (one == 1 && two == 0 and three == 0) {
            
            //  A1 Choices
            int choices = 0;
            cout << "What is your reply?" << endl;
            cout << "1. \"It's you who'll get a rare cut accross that corpulent neck of yours if you don't speed things along, you feckless blob of festering lard.\"" << endl;
            cout << "2. \"Surely in such an industrious kitchen, there must be a starter or two ready to send along and sate His Abhorentness's appetite?\"" << endl << endl;
            cout << "What will you say? (1 or 2): ";
            cin >> choices;
            
            //  Specification A1 - Input Validation
            while (choices != 1 && choices !=2) {
                cout << "What will you say? (1 or 2): ";
                cin >> choices;
            }
            cout << endl << endl;
            return choices;
          
        //  Specification B4 - Valid Choices Only
        } else if (one == 1 && two == 1 and three == 0) {
            
            //  A232 Choices
            int choices = 0;
            cout << "Who will you serve first?" << endl;
            cout << "1. The enthusiastic Captain Haiken?" << endl;
            cout << "2. Or your master, Malacandros?" << endl << endl;
            cout << "What will you do? (1 or 2): ";
            cin >> choices;
        
        while (choices != 1 && choices != 2) {
            cout << "What will you do? (1 or 2): ";
            cin >> choices;
        }
        cout << endl << endl;
        return choices;
        } else if (one == 1 && two == 1 and three == 1) {
            
            //  A13 Choices (Not Diplomat)
            int choices = 0;
            cout << "2. Do you simply inform him which is the proper rat-head-eating fork?" << endl;
            cout << "3. Or do you let him flounder?" << endl << endl;
            cout << "What will you do? (2 or 3): ";
            cin >> choices;
        
        while (choices != 2 && choices != 3) {
            cout << "What will you do? (2 or 3): ";
            cin >> choices;
        }
        cout << endl << endl;
        return choices;
    } else if (one == 1 && two == 0 and three == 1) {
        
        //  A13 Choices (Diplomat)
        int choices = 0;
        cout << "1. Are you a DIPLOMAT?" << endl << endl;
        cout << "What will you say? (1): ";
        cin >> choices;
        
        while (choices != 1) {
            cout << "What will you say? (1): ";
            cin >> choices;
        }
        cout << endl << endl;
        return choices;
    } else if (one == 0 && two == 0 and three == 0) {
        
        //  Only One Choice
        int choices = 0;
        cout << "What will you say? (1): ";
        cin >> choices;
        
        while (choices != 1) {
            cout << "What will you say (1): ";
            cin >> choices;
        }
        cout << endl << endl;
        return choices;
    } else if (one == 0 && two == 0 and three == 1) {
        
        //  A173 Choices
        int choices = 0;
        cout << "1. Do you attempt to intercede on Peedy's behalf?" << endl;
        cout << "2. Or do you abandon him to his miserable fate?" << endl << endl;
        cout << "What will you do? (1 or 2): ";
        cin >> choices;
        
        while (choices != 1 && choices != 2) {
            cout << "What will you do (1 or 2): ";
            cin >> choices;
        }
        cout << endl << endl;
        return choices;
    }
        return 0;
}
//  Specification C1 - Individual Functions
int A1() {
    cout << "\"Well, Mr Artanon, look at you. Who would have thought that the son of a lowly spider farmer could rise to such esteemed heights? Yet here you are, standing in the kitchens of Cayfax Castle, dressed in the finest livery onyx can buy. For you, sir, are butler to Malacandros, Dark Lord of all Nocturnia. The flames of fireplaces tickle suspended pots, which thicken the air with competing scents. Workers along stone benches busily chop and kill ingredients nothing but the best for his lordship, of course. In the centre of the chamber a great oven blazes, its cracked chimney oozing smoke. ’Ah, Mr Artanon,’ simpers Repugnis, the head cook. He’s a fat goblin who samples too many of his own creations, as evidenced by his bulging belly and the delta of stains down his apron. ’I’m roasting his Horrendousness a prime briar beast basted in snake oil. Mmmmmm! The intestines are stuffed with rotten apple and breadcrumb, and I’ve shoved a carrot up its arse.\" You arch an eyebrow, for Mal is already situated upstairs in the dining hall. With midday waning, he will be growing hungry. \"And just how long,\" you ask, \"do you intend to keep his lordship staring at an empty plate?\" Repugnis titters nervously, and glances towards the oven. \"Good sir, a roast takes as long as a roast takes. If I stoke the flames any hotter the skin will crisp to charcoal. At best I could aim for a rare cut?\"" << endl << endl;
    return menu(1,0,0);
}
int A100() {
    cout << "'Repugnis turns a paler shade of green, and gulps. \"I beg you, Mr Artanon, stay your hand. I’m sure that something must be ready.\" The cook glances around and spots a bench at which several trays are being assembled. \"Ah!\" he says. \"How about some pickled rat heads and carpaccio of slug?\" You scowl, long enough to make Repugnis quiver, then turn and snap at some lurking footmen. \"Get those trays up to his lordship without delay!\" The footmen spring into action, seizing the trays and heading for the door. \"Thank you, sir,\" says Repugnis. \"The roast will not be far behind, I promise.\" \"See that it isn’t,\" you reply, \"or the next item on the menu might be goblin stew.\" It seems you are an INTIMIDATOR." << endl << endl;
    cout << "1. Onwards, Mr. Artanon." << endl << endl;
    return menu(0,0,0);
}
int A167() {
    cout << "Repugnis nods eagerly, which ripples his many chins. \"Yes sir, of course! Let me see now...\" He glances around and spots a bench where several platters are being assembled. \"Ah! How about some pickled rat heads and delectable carpaccio of slug?\" \"Very good,\" you say. \"I am told that Captain Haiken is particularly partial to rat. But see that you hurry along now, Repugnis. I don’t need to remind you that his lordship’s patience is virtually nonexistent.\" \"Of course, sir, of course.\" You click your fingers at some waiting footmen and they leap to action, seizing the platters and heading for the door. It seems you are a DIPLOMAT." << endl << endl;
    cout << "1. Onwards Mr. Artanon." << endl << endl;
    return menu(0,0,0);
}
int A232() {
    cout << "You overtake the footmen along a corridor lit by stuttering candles, and lead them through a wide archway into the airy dining hall. Great windows stand open along one wall, looking out upon a pleasant view of circling lizard-birds cannibalizing their young. Down the length of the hall runs an immense marble table, at the head of which the Dark Lord Malacandros reclines in a chair of elaborately carved dragon bone. He is a gaunt man with darting eyes and sharp features, currently dressed in a very tasteful grey robe (which you helped him get into this morning), his black hair clasped in a ponytail down his back. To his right sits Captain Haiken, one of his favored brutes, a well muscled orc in polished steel. \"Ah, Mr Artanon,\" says Mal, \"I was beginning to worry we’d been forgotten.\" He gives you a thin smile, which warns you he is very close to becoming irked. You bow deeply. \"My humble apologies, oh Intolerant One. Repugnis is putting the final touches on today’s main course, and you know what a perfectionist he is. In the meantime,\" you whisk a platter from one of the footmen, here are some starters to whet your appetites.\" As you move toward the head of the table, Haiken licks his lips. \"Rat heads!\" he exclaims. \"My favorite.\"" << endl << endl;
    return menu(1,1,0);
}
int A13(bool aDiplomat) {
    cout << "\"Feeling dangerous, Mr Artanon?\" You move past Mal to Captain Haiken and, using a pair of tongs fashioned to look like crow’s claws, start placing rat heads onto his plate. As you do, you glance surreptitiously at Mal, wondering if you have irritated him by serving his guest first he is not exactly known for his good manners but he does not seem to have noticed. At any rate, your first footman, Kalag - a young man who shows much promise - hops to action, to lay slivers of slug meat on Mal’s plate. \"Er...\" says Haiken, his meaty hand skimming the tableware. You realize he is uncertain about what, amongst the array of cutlery laid out on either side of his plate, is the correct implement to use for rat heads." << endl << endl;
    if (aDiplomat) {
        return menu(1,0,1);
    } else {
        return menu (1,1,1);
    }
}
int A290() {
    cout << "As is only fitting, you serve your master first. As you place the largest and juiciest rat heads before him, your first footman Kalag a young fellow who shows much promise moves to Haiken and starts laying slug meat on his plate. \"Er,\" says Haiken, \"not too much slug for me, thank you I have an allergy.\" Mal, who is in midchew, scoffs, and shoots a shard of half chewed rat skull out of his nostril to ping off a wine glass. \"Rut me, Haiken,\" he says. \"I’ve seen you rip the throat from a charging horse, yet you can’t stomach a little slug?\" Haiken seems embarrassed. \"They give me hives, my lord.\" \"Ha! Well, better get over there with some of his precious rat heads, Mr Artanon.\" You do as you are bid, and place the remaining rat heads on Haiken’s plate. They are a little on the smaller side, and you notice a wistful look in Haiken’s eye as Mal lifts another plump one to his mouth. With your lords served, you move back from the table to remain in waiting." << endl << endl;
    cout << "1. Excellent posture, Mr. Artanon." << endl << endl;
    return menu(0,0,0);
}
int A159(){
    cout << "You clear your throat and speak softly. \"That little one there is your rat-head-eating-fork, my lord.\" Despite your attempt to be subtle, Mal registers the exchange and chortles. Haiken, embarrassed to be found ignorant, frowns. \"I know what fork to use, you stupid butler! Begone before I stab you in the eye with it.\" With your lords served, you move back from the table to remain in waiting. Somehow you doubt Haiken’s bedclothes will be properly turned." << endl << endl;
    cout << "1. Done" << endl << endl;
    return menu(0,0,0);
}
int A161() {
    cout << "You move away from Haiken, whose hand still hovers uncertainly over the cutlery, to serve Mal rat heads. Finally Haiken makes a decision and picks up a carapace-cracking-spork. Mal chuckles at his ignorance. \"By Stygias, Captain have you been in the field so long that you’ve forgotten the basic functions of tableware?\" Haiken grimaces. \"Pardon me, your Pettiness. I may have had a noble birth, yet life as a soldier puts me out of touch with certain niceties. We tend to eat with our hands.\" Mal laughs. \"Well, let us not stand on ceremony, Captain! I am happy to do it your way!\" Mal picks up a rat head with his hand and shovels it into his mouth. Haiken happily follows suit, munching and cracking skulls with his teeth. Inwardly, you give a sigh. No doubt with such messy fingers, Mal will stain the dragon bone. Why, you have often wondered, would anyone fashion a dining chair out of such easily blemished material as bleached porous bone? Just as you fear, Mal leans back to rest his grubby mitts upon the armrests. The CHAIR IS DIRTY. You move back to the wall while your lords eat, to remain in waiting. A butler’s work is never done." << endl << endl;
    cout << "1. Done" << endl << endl;
    return menu(0,0,0);
}
int A173() {
    cout << "As they gnash away, Mal and Haiken discuss the Captain’s recent raid on the town of Greenflower. \"Honestly,\" says Haiken, \"those wretched Brightlanders are so easily slaughtered, sometimes I almost feel bad for them.\" Mal laughs at this hilarious joke. \"Ha! That’s a good one, Captain. But tell me, what of your primary objective?\" \"I am pleased to report success, my lord.' 'You have brought me a virgin?\" \"She languishes in your dungeon even now lovely, virtuous and ripe for sacrifice.\" \"Excellent. My skywatchers predict a full moon in three nights time perfect conditions for the ceremony.\" Footsteps sound at the dining hall entrance, and a goblin messenger, whom you recognize as Peedy, enters wearing a feathered hat and carrying a scroll. Mal’s gaze slides to him. \"What is it?\" Peedy clears his throat. \"Apologies for the interruption, Your Atrociousness. I bring you word from Vorganis Castle.\" \"Oh?\" Mal’s tone is so instantly cold that the very temperature of the room seems to drop. \"Er... yes, my lord. Lord Nefarian accepts your kind invitation to attend the Stygias Ceremony, and intends to arrive tomorrow morning.\" Mal’s eyes narrow. You know he does not care for his cousin Nefarian, not least because the man is next in line to the throne. Nefarian’s presence at the ceremony, however, must be tolerated, for he is a powerful lord in his own right, with many allies amongst Nocturnia’s nobility a fact which Mal does not enjoy being reminded of. \"Why bring me such news at lunch?\" he growls. \"It has put a foul taste in my mouth and sullied my food.\" He drums his fingers on the dragon bone armrest, and fiery sparks flare at his fingertips. Peedy quails, for he knows that Mal is prone to taking out his anger on the bearers of bad news. It would be a shame, however (and a staffing issue), to lose a competent messenger to a moment of ill temper over something that really isn’t his fault." << endl << endl;
    return menu(0,0,1);
}
int A212() {
    cout << "You clear your throat very slightly, and Haiken glances up at you. As you move your hand back from his plate, you let your finger rest momentarily on the appropriate rat-head-eating fork. Haiken understands, and gives you a relieved look. Mal is too busy shoveling slug meat into his gullet to notice the exchange, so HAIKEN IS GRATEFUL. You add some rat heads to Mal’s plate and move back from the table to take a place in waiting." << endl << endl;
    cout << "1. Nicely done, Mr. Artanon." << endl << endl;
    return menu(0,0,0);
}
int display() {
    cout << "---------" << endl;
    cout << "GAME OVER" << endl;
    cout << "---------" << endl << endl;
    return 0;
}
