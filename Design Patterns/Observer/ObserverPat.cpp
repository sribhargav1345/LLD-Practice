#include<bits/stdc++.h>
using namespace std;

class ISubscriber {
public:
    virtual void update() = 0;
    virtual ~ISubscriber() {}
};

class IChannel {
public:
    virtual void subscribe(ISubscriber* subscriber) = 0;
    virtual void unsubscribe(ISubscriber* subscriber) = 0;
    virtual void notifySubscribers() = 0;
    virtual ~IChannel() {}
};

class Channel: public IChannel {
private:
    vector<ISubscriber*> subscribers;   // list of subs
    string name;
    string latestVideo;                 // latest video title

public:
    Channel(const string& name) {
        this -> name = name;
    }

    void subscribe(ISubscriber* subscriber) override {
        if(find(subscribers.begin(), subscribers.end(), subscriber) == subscribers.end()) {
            subscribers.push_back(subscriber);
        }
    }

    void unsubscribe(ISubscriber* subscriber) override {
        auto it = find(subscribers.begin(), subscribers.end(), subscriber);
        if (it != subscribers.end()) {
            subscribers.erase(it);
        }
    }

    void notifySubscribers() override {
        for (ISubscriber* sub: subscribers) {
            sub -> update();
        }
    }

    void uploadVideo(const string& title) {
        latestVideo = title;
        cout<<"Video uploaded: "<< title<< endl;
        notifySubscribers();
    }

    string getVideoData() {
        return "Checkout our new Video:" + latestVideo + "\n" ;
    }
};

class Subscriber: public ISubscriber {
private:
    string name;
    Channel* channel;

public:
    Subscriber(const string& name, Channel* channel) {
        this -> name = name;
        this -> channel = channel;
    }

    void update() override {
        cout<<"Hey" << name<< "," << this -> channel -> getVideoData();
    }
};


int main() {
    Channel* channel = new Channel("filmymoji");

    Subscriber* sub1 = new Subscriber("Varun", channel);
    Subscriber* sub2 = new Subscriber("Tarun", channel);

    channel -> subscribe(sub1);
    channel -> subscribe(sub2);

    channel -> uploadVideo("Observer Pattern video");
    
    channel -> unsubscribe(sub1);
    channel -> uploadVideo("Decorator Pattern video");

    return 0;
}