#ifndef ASSIGN3_SCHEDULER_PRIORITY_H
#define ASSIGN3_SCHEDULER_PRIORITY_H

#include "scheduler.h"
#include <vector>
#include <algorithm>

/**
 * @class SchedulerPriority
 * @brief Implements the Priority Scheduling algorithm.
 *
 * In this scheduling algorithm, processes are assigned a priority,
 * and the CPU executes processes based on priority order. Higher priority 
 * numbers represent higher priority. If multiple processes have the same 
 * priority, they are executed in the order they arrive.
 */
class SchedulerPriority : public Scheduler {
private:
    std::vector<PCB> processes; ///< Stores the list of processes to be scheduled.

public:
    /**
     * @brief Construct a new SchedulerPriority object.
     */
    SchedulerPriority();

    /**
     * @brief Destroy the SchedulerPriority object.
     */
    ~SchedulerPriority() override;

    /**
     * @brief Initializes the scheduler with a list of processes.
     *        This function is responsible for sorting processes by priority.
     * @param process_list The list of processes in the simulation.
     */
    void init(std::vector<PCB>& process_list) override;

    /**
     * @brief Simulates the Priority Scheduling algorithm.
     *        Processes are executed in order of priority.
     */
    void simulate() override;

    /**
     * @brief Prints the results of the scheduling simulation.
     *        Outputs turnaround time and waiting time for each process,
     *        as well as the average turnaround and waiting times.
     */
    void print_results() override;
};

#endif // ASSIGN3_SCHEDULER_PRIORITY_H
