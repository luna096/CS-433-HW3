#ifndef ASSIGN3_SCHEDULER_SJF_H
#define ASSIGN3_SCHEDULER_SJF_H

#include "scheduler.h"
#include <vector>
#include <algorithm>

/**
 * @class SchedulerSJF
 * @brief Implements the Shortest Job First (SJF) Scheduling Algorithm.
 *
 * This scheduling algorithm selects the process with the shortest CPU burst time first.
 * - Processes are sorted based on burst time before execution.
 * - The algorithm minimizes average waiting time by executing shorter processes first.
 * - It is a non-preemptive scheduling approach.
 */
class SchedulerSJF : public Scheduler {
private:
    std::vector<PCB> processes; ///< List of processes to be scheduled

public:
    /**
     * @brief Construct a new SchedulerSJF object.
     */
    SchedulerSJF();

    /**
     * @brief Destroy the SchedulerSJF object.
     */
    ~SchedulerSJF() override;

    /**
     * @brief Initializes the scheduler with a list of processes.
     *        Sorts processes by burst time in ascending order.
     * @param process_list The list of processes in the simulation.
     */
    void init(std::vector<PCB>& process_list) override;

    /**
     * @brief Simulates the Shortest Job First Scheduling Algorithm.
     *        - Processes are executed in order of shortest burst time first.
     *        - Turnaround and waiting times are calculated for each process.
     */
    void simulate() override;

    /**
     * @brief Prints the results of the scheduling simulation.
     *        Outputs turnaround time and waiting time for each process,
     *        as well as the average turnaround and waiting times.
     */
    void print_results() override;
};

#endif // ASSIGN3_SCHEDULER_SJF_H
