#ifndef ASSIGN3_SCHEDULER_SJF_H
#define ASSIGN3_SCHEDULER_SJF_H

#include "scheduler.h"
#include <vector>
#include <algorithm>

class SchedulerSJF : public Scheduler {
private:
    std::vector<PCB> processes; // List to store processes

public:
    SchedulerSJF();
    ~SchedulerSJF() override;

    void init(std::vector<PCB>& process_list) override;
    void simulate() override;
    void print_results() override;
};

#endif //ASSIGN3_SCHEDULER_SJF_H