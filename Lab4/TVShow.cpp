#include "TVShow.h"

//Constructor initialization - This also initializes the dynamic 2D array based on the arguments
TVShow::TVShow(string title, string description, int seasonCount, int episodeCount)
	: Show(title, description), seasonCount(seasonCount), episodeCount(episodeCount) {

	seasons = new Episode* [seasonCount];
	for (int i = 0; i < seasonCount; i++) {
		seasons[i] = new Episode[episodeCount];
	}
}

//Destructor - Deallocates the memory created by the dynamix 2D array
TVShow::~TVShow() {

	for (int i = 0; i < seasonCount; i++) {
		delete[] seasons[i];
	}
	delete[] seasons;
}

//Overriden Play function - Allows the user to Play or add an episode
void TVShow::Play() {

    int choice, seasonNumber, episodeNumber;
    string summary;
    bool keepPlaying = true;

    while (keepPlaying) {


        cout << "\nDo you want to (1) Play an episode, (2) Add a new episode, or (3) Exit? (Enter 1, 2, or 3): ";
        cin >> choice;

        switch (choice) {
        case 1: { 
            cout << "\nSelect a Season and Episode to watch!\n" << endl;

            cout << "Season Number (1-" << seasonCount << "): ";
            cin >> seasonNumber;

            cout << "Episode Number (1-" << episodeCount << "): ";
            cin >> episodeNumber;

            if (seasonNumber - 1 < seasonCount && episodeNumber - 1 < episodeCount) {
                cout << "\nSummary: " << seasons[seasonNumber - 1][episodeNumber - 1].summary << endl;
            }
            else {
                cout << "Invalid season or episode number" << endl;
            }
            break;
        }
        case 2: { 
            cout << "\nSelect a Season and Episode to add:\n" << endl;

            cout << "Season Number (1-" << seasonCount << "): ";
            cin >> seasonNumber;

            cout << "Episode Number (1-" << episodeCount << "): ";
            cin >> episodeNumber;

            cin.ignore();

            cout << "\nEnter the summary for this episode: ";
            getline(cin, summary);

            addEpisode(seasonNumber - 1, episodeNumber - 1, summary);
            cout << "Episode added successfully!" << endl;
            break;
        }
        case 3: { 
            keepPlaying = false;
            cout << "Exiting the Play menu." << endl;
            break;
        }
        default: {
            cout << "Invalid choice. Please enter 1, 2, or 3." << endl;
            break;
        }
        }
    }
}

//Details function = Outputs the title, description, and number of seasons in the TVShow
void TVShow::Details() const{

	cout << "\nTitle: " << title 
		 << "\nDescription: " << description 
		 << "\nSeasons: " << seasonCount << "\n" << endl;

}

//Allows the user to add an episdoe to the 2D array along with a description of the episode
void TVShow::addEpisode(int season, int episode, string summary) {

	if (season < seasonCount && episode < episodeCount) {
		seasons[season][episode].summary = summary;
	}
	else {
		cout << "Invalid season or episode number" << endl;
	}

}

