#ifndef CODE_PROFILER_STATS_PUBLISHER_H_
#define CODE_PROFILER_STATS_PUBLISHER_H_

#include <string>
#include <map>
#include <ros/publisher.h>

#include "profiling/Timer.h"

class StatsPublisher {

public:

    StatsPublisher();

    virtual ~StatsPublisher();

    void initialize();

    void startTimer(const std::string& label);

    void stopTimer(const std::string& label);

    void publish() const;

protected:

    ros::Publisher pub_stats_;

    std::map<std::string, Timer> timers_;

};

#endif
