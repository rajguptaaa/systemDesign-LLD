/*
The Observer Design Pattern defines a one-to-many(1->*) relationship between objects. When the state of one object (the Subject or Observable) changes, all its dependents (Observers) are automatically notified and updated.

Uses:
    -Notification Services: Sending alerts to users when a specific event occurs, such as a YouTube channel uploading a new video
    -Social Media Feeds: Notifying followers or friends when a user posts a new photo or status update on platforms like Facebook or Instagram.
    -Event Handling: In front-end development, "Event Listeners" use this pattern to execute code whenever a user interacts with an element (like clicking a button).
    -Stock Market/Weather Updates: Automatically updating multiple display dashboards or apps whenever the price of a stock or weather data changes.
*/

/*
* Interface = pure abstract = only virtual functions
* Observable notifies obervers
*/
#include <iostream>
#include <vector>
#include <algorithm>   // FIX: required for std::find
using namespace std;

// interface - only pure virtual functions
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

// Concrete Channel
class Channel : public IChannel {
private:
    vector<ISubscriber*> subscribers;
    string name;
    string latestVideo;

public:
    Channel(const string& name) : name(name) {}

    // Add subscriber (avoid duplicates)
    void subscribe(ISubscriber* subscriber) override {
        if (find(subscribers.begin(), subscribers.end(), subscriber) == subscribers.end()) {
            subscribers.push_back(subscriber);
        }
    }

    // Remove subscriber
    void unsubscribe(ISubscriber* subscriber) override {
        auto it = find(subscribers.begin(), subscribers.end(), subscriber);
        if (it != subscribers.end()) {
            subscribers.erase(it);
        }
    }

    // Notify all subscribers
    void notifySubscribers() override {
        for (auto* sub : subscribers) {
            sub->update();
        }
    }

    // Upload new video
    void uploadVideo(const string& title) {
        latestVideo = title;
        cout << "\n[" << name << " uploaded \"" << title << "\"]\n";
        notifySubscribers();
    }

    // FIX: const correctness
    string getVideoData() const {
        return "\nCheckout our new Video : " + latestVideo + "\n";
    }
};

// Concrete Subscriber
class Subscriber : public ISubscriber {
private:
    string name;
    Channel* channel;

public:
    Subscriber(const string& name, Channel* channel)
        : name(name), channel(channel) {}

    void update() override {
        cout << "Hey " << name << "," << channel->getVideoData();
    }
};

int main() {
    Channel* channel = new Channel("CoderArmy");

    Subscriber* subs1 = new Subscriber("Varun", channel);
    Subscriber* subs2 = new Subscriber("Tarun", channel);

    channel->subscribe(subs1);
    channel->subscribe(subs2);

    channel->uploadVideo("Observer Pattern Tutorial");

    channel->unsubscribe(subs1);

    channel->uploadVideo("Decorator Pattern Tutorial");

    // (Optional but correct) cleanup
    delete subs1;
    delete subs2;
    delete channel;

    return 0;
}