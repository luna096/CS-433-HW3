#ifndef ASSIGN3_SCHEDULER_PRIORITY_H
#define ASSIGN3_SCHEDULER_PRIORITY_H

#include "scheduler.h"
#include <vector>
#include <algorithm>

class SchedulerPriority : public Scheduler {
private:
    std::vector<PCB> processes;

public:
    SchedulerPriority();
    ~SchedulerPriority() override;

    void init(std::vector<PCB>& process_list) override;
    void simulate() override;
    void print_results() override;
};

#endif //ASSIGN3_SCHEDULER_PRIORITY_H