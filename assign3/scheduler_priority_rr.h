#ifndef ASSIGN3_SCHEDULER_PRIORITY_RR_H
#define ASSIGN3_SCHEDULER_PRIORITY_RR_H

#include "scheduler.h"
#include <vector>
#include <queue>
#include <map>

class SchedulerPriorityRR : public Scheduler {
private:
    std::map<int, std::queue<PCB*>> priority_queues;
    int time_quantum;

public:
    SchedulerPriorityRR(int time_quantum = 10);
    ~SchedulerPriorityRR() override;

    void init(std::vector<PCB>& process_list) override;
    void simulate() override;
    void print_results() override;
};

#endif //ASSIGN3_SCHEDULER_PRIORITY_RR_H