#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>

using namespace std;

class Subscriber {
    public:
    virtual void update(string video) = 0;
};

class YoutubeChannel {
    public:
    virtual void addSubscriber(shared_ptr<Subscriber> sb)= 0;
    virtual void removeSubscriber(shared_ptr<Subscriber> sb) = 0;
    virtual void upload(string video) = 0;
    virtual void notifySubscribers() = 0;
};

class YoutubeChannelImpl: public YoutubeChannel {
    string channelName;
    vector<string> videoTitles;
    vector<shared_ptr<Subscriber>> sbs;

    public:
    YoutubeChannelImpl(string n) {
        channelName = n;
    }
    void addSubscriber(shared_ptr<Subscriber> sb) {
        sbs.push_back(sb);
    }

    void removeSubscriber(shared_ptr<Subscriber> sb) {
        sbs.erase(std::remove(sbs.begin(), sbs.end(), sb), sbs.end());
    }


    void upload(string video) {
        videoTitles.push_back(video);
        notifySubscribers();
    }

    void notifySubscribers() {
        for (auto sb: sbs) {
            sb->update(videoTitles[videoTitles.size()-1]);
        }
    }
};

class YoutubeSubscriber: public Subscriber {
    string name;
    public:
    YoutubeSubscriber(string n) {
        name = n;
    }
    void update(string video) {
        cout << "Username : " << name << endl;
        cout << "New video with title: \"" << video << "\" uploaded" << endl << endl;
    }
};

int main() {
    cout << "Start application\n";

    shared_ptr<YoutubeChannel> channel = make_shared<YoutubeChannelImpl>("RajaTechVideos");

    shared_ptr<Subscriber> sb1 = make_shared<YoutubeSubscriber>("raja0001");
    shared_ptr<Subscriber> sb2 = make_shared<YoutubeSubscriber>("ss");
    channel->addSubscriber(sb1);
    channel->addSubscriber(sb2);
    while (true) 
    {
        cout << "1. upload video\n2.Exit\n";
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;
        switch(choice) {
            case 1: channel->upload("py and java");
            break;
            default:
            cout << "Exit\n";
            return 0;
        }
    }
    
}