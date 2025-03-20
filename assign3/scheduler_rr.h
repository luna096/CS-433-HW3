#ifndef ASSIGN3_SCHEDULER_RR_H
#define ASSIGN3_SCHEDULER_RR_H

#include "scheduler.h"
#include <vector>
#include <queue>

class SchedulerRR : public Scheduler {
private:
    std::vector<PCB> processes;
    int time_quantum;

public:
    SchedulerRR(int time_quantum = 10);
    ~SchedulerRR() override;

    void init(std::vector<PCB>& process_list) override;
    void simulate() override;
    void print_results() override;
};

#endif //ASSIGN3_SCHEDULER_RR_H