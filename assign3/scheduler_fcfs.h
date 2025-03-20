#ifndef ASSIGN3_SCHEDULER_FCFS_H
#define ASSIGN3_SCHEDULER_FCFS_H

#include "scheduler.h"
#include <vector>

class SchedulerFCFS : public Scheduler {
private:
    std::vector<PCB> processes; // List to store processes

public:
    /**
     * @brief Construct a new SchedulerFCFS object
     */
    SchedulerFCFS();
    /**
     * @brief Destroy the SchedulerFCFS object
     */
    ~SchedulerFCFS() override;

    /**
     * @brief Initialize the scheduler with a list of processes.
     * @param process_list The list of processes in the simulation.
     */
    void init(std::vector<PCB>& process_list) override;

    /**
     * @brief Simulates FCFS scheduling.
     */
    void simulate() override;

    /**
     * @brief Prints the results after the simulation.
     */
    void print_results() override;
};

#endif //ASSIGN3_SCHEDULER_FCFS_H