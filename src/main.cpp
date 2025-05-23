#include "../headers/functions.h"

// Game Settings
int intro_sequence = 1;
int music_setting = 1;
int music_vol = 100;
int music_track = 1;

//Battle Seq
int crit_result = 0;

int exit_mode = 0;

/////////////////////////////
//// ADVENTURE MENU /////////
/////////////////////////////
void adventure()
{
    exit_mode = 0;
    int i = 0;
    string ans = "";
    while (i==0) 
    {
        if (exit_mode == 1) { return; }
        
        std::cout << "[2J[H";

        print_village();

        //Print Statbar
        show_statbar();

        // Print Menu Options
        cout << "("; Color(6); cout << "1"; Color(7); cout << ") The Circle of Stones" << endl;
        cout << "("; Color(6); cout << "2"; Color(7); cout << ") The Castle" << endl;
        cout << "("; Color(6); cout << "3"; Color(7); cout << ") The Temple" << endl;
        cout << "("; Color(6); cout << "4"; Color(7); cout << ") The Blacksmith" << endl;
        cout << "("; Color(6); cout << "5"; Color(7); cout << ") The Mystic" << endl;
        cout << "("; Color(6); cout << "6"; Color(7); cout << ") The Inn" << endl << endl;
        //cout << "("; Color(6); cout << "7"; Color(7); cout << ") Quit to Main Menu" << endl << endl;
        cout << "("; Color(6); cout << "ESC"; Color(7); cout << ") Menu" << endl;

        // Input Selection
        ShowConsoleCursor(false);
        ans = _getch();

        if (ans == "1")
        {   
            int i = 0;
            while (i==0) 
            {    
                print_stones();
                show_statbar();
                i = circleofstones(i);
            }
        }

        if (ans == "2")
        { 
            int i = 0;
            while (i==0) 
            {    
                i = castle(i);
            } 
        }

        if (ans == "3")
        { 
            int i = 0;
            while (i==0) 
            {    
                print_temple();
                show_statbar();
                i = temple(i);
            } 
        }

        if (ans == "4")
        { 
            int i = 0;
            while (i==0) 
            {    
                
                i = blacksmith(i);
            } 
        }

        if (ans == "5")
        { 
            int i = 0;
            while (i==0) 
            {    
                
                i = mystic(i);
            } 
        }

           if (ans == "6")
        { 
            int i = 0;
            while (i==0) 
            {    
                i = inn(i);
            } 
        }

        //if (ans == "7") 
        //{ 
        //   cout << "\nReturning to Main Menu!" << endl; usleep(1 * 1000); i = 1;
        //}

        if (ans == "\033")
        {
            info_screen();
        }

     

    }
}

/////////////////////////////
//// MAIN ///////////////////
/////////////////////////////
int main() 
{
    // Loads Game
    load_game();

    // Check for Sound Enabled or Disabled
    if (music_setting == 1) 
    { 
        stream_music(music_track);
        
    }
    
    // Check for Intro Enabled or Disabled
    if (intro_sequence == 1) { intro(); }
        
    int i = 0;
    string ans = "";
    while (i==0) 
    {

        print_title();

        // Print Choices
        if (hero_player.name != "Player") 
        {
            cout << "("; Color(6); cout << "1"; Color(7); cout << ") Play Game ["; Color(2); cout << hero_player.name; Color(7); cout << "]" << endl;
        }
        cout << "("; Color(6); cout << "2"; Color(7); cout << ") New Game" << endl; //To be NewGame
        cout << "("; Color(6); cout << "3"; Color(7); cout << ") Game Options" << endl;
        cout << "("; Color(6); cout << "4"; Color(7); cout << ") Quit & Save Game" << endl;
        ShowConsoleCursor(false);
        ans = _getch();
        
        if (ans == "1" and hero_player.name != "Player")
        { 
            adventure(); 
        }

        if (ans == "2") 
        { 
            
            print_createhero();
            CreateHero();
            
        }

        if (ans == "3")
        { 
            int i = 0;
            while (i==0) 
            {    
                print_options();
                cout << endl;
                i = options(i);
            } 
        }

        if (ans == "4") 
        { 
            save_game();
            i=1; 
        }

        if (ans == "*") { debug_screens(); }
    }

    i = 0;

    std::cout << "[2J[H";
    string test = "Thank you for playing The Oblivion Cycle!";
    typer(test,25); cout << endl;
    ShowConsoleCursor(true);
    usleep(2000 * 1000);
    return 0; // EXIT CODE

}

void debug_screens()
{
    int i = 0;
    while (i == 0)
    {
        std::cout << "[2J[H";
        cout << "Debug Screens" << endl;
        cout << "---------------------------" << endl;
        cout << "(1) Random Monster Gate 1" << endl;
        cout << "(2) Random Monster Gate 2" << endl;
        cout << "(3) Random Monster Gate 3" << endl;
        cout << "---------------------------" << endl;

        cout << endl;
        cout << "[ESC] Exit";
        string ans;
        ans = _getch();

        hero_player.hp = hero_player.hp_max;
        if (ans == "\033") { i = 1; }
        if (ans == "1") { battle_sim(monster_generator(hero_player.level, 1),1); }
        if (ans == "2") { battle_sim(monster_generator(hero_player.level, 2), 2); }
        if (ans == "3") { battle_sim(monster_generator(hero_player.level, 3), 3); }

    }
}