#include "TVShow.h"
#include "Movie.h"
#include "Show.h"

//Calls the functions for a specific instance
void testShow(Show* s) {
    s->Details();
    s->Play();
}

int main() {
    int choice;
    bool keepRunning = true;

    while (keepRunning) {

        cout << "\nPress 1 for an instance of Movie." << endl;
        cout << "Press 2 for an instance of TV Show." << endl;
        cout << "Press 3 for an instance of a Movie declared as a Show." << endl;
        cout << "Press 4 for an instance of a TV Show declared as a Show." << endl;
        cout << "Press 5 to exit." << endl;

        cin >> choice;

        switch (choice) {
        case 1: { //Instance of a Movie


            string title, description;
            int rating;

            cout << "Enter Movie Title: ";
            cin.ignore();
            getline(cin, title);
            cout << "\nEnter Movie Description: ";
            getline(cin, description);
            cout << "\nEnter Movie Rating (1-10): ";
            cin >> rating;

            Movie* movie = new Movie(title, description, rating);

            testShow(movie);

            delete movie;

            break;
        }
        case 2: { //Instance of a TV Show

            string title, description;
            int seasonCount, episodeCount;

            cout << "\nEnter TV Show Title: ";
            cin.ignore();
            getline(cin, title);
            cout << "\nEnter TV Show Description: ";
            getline(cin, description);
            cout << "\nEnter Number of Seasons: ";
            cin >> seasonCount;
            cout << "\nEnter Number of Episodes per Season: ";
            cin >> episodeCount;

            TVShow* tvShow = new TVShow(title, description, seasonCount, episodeCount);
            testShow(tvShow);

            delete tvShow;

            break;
        }
        case 3: { //Instance of a Movie declared as a Show
            string title, description;
            int rating;

            cout << "\nEnter Movie Title: ";
            cin.ignore();
            getline(cin, title); 
            cout << "\nEnter Movie Description: ";
            getline(cin, description);
            cout << "\nEnter Movie Rating (1-10): ";
            cin >> rating;

            Show* show = new Movie(title, description, rating);

            testShow(show);

            delete show;

            break;
        }
        case 4: { //Instance of a TV Show declared as a Show
            string title, description;
            int seasonCount, episodeCount;

            cout << "\nEnter TV Show Title: ";
            cin.ignore();
            getline(cin, title); 
            cout << "\nEnter TV Show Description: ";
            getline(cin, description);
            cout << "\nEnter Number of Seasons: ";
            cin >> seasonCount;
            cout << "\nEnter Number of Episodes per Season: ";
            cin >> episodeCount;

            Show* show = new TVShow(title, description, seasonCount, episodeCount);
            
            testShow(show);

            delete show;

            break;
        }
        case 5:

            keepRunning = false;
            break;

        default:

            cout << "\nInvalid choice. Try again." << endl;
            break;

        }
    }

    return 0;
}
