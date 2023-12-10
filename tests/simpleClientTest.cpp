#include "cpp-statsd-client/StatsdClient.hpp"

#include <thread>
#include <chrono>

using namespace Statsd;

int main() {
    // Define the client on localhost, with port 8080 and using a prefix
    StatsdClient client{"localhost", 8125, "myPrefix"};

    for (int i = 0; i < 100; i++) {
        // Increment the metric "coco"
        client.increment("coco");

        // Decrement the metric "kiki"
        client.decrement("kiki");

        // Adjusts "toto" by +3
        client.count("toto", 2, 0.1f);

        // Record a gauge "titi" to 3.2 with tags
        client.gauge("titi", 3.2, 0.1f, {"foo", "bar"});

        // Record a timing of 2ms for "myTiming"
        client.timing("myTiming", 2, 0.1f);

        // Record a count of unique occurences of "tutu"
        client.set("tutu", 4, 2.0f);

        std::this_thread::sleep_for(std::chrono::microseconds(1000));

    }
    exit(0);
}
