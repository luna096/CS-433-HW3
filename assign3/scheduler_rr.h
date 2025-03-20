#ifndef ASSIGN3_SCHEDULER_RR_H
#define ASSIGN3_SCHEDULER_RR_H

#include "scheduler.h"
#include <vector>
#include <queue>

/**
 * @class SchedulerRR
 * @brief Implements the Round-Robin (RR) Scheduling Algorithm.
 *
 * This scheduling algorithm assigns a fixed time quantum to each process.
 * - Processes execute in a cyclic order.
 * - If a process does not complete within its quantum, it is placed back into the queue.
 * - The algorithm continues until all processes are completed.
 */
class SchedulerRR : public Scheduler {
private:
    std::vector<PCB> processes; ///< Stores the list of processes in the scheduler
    int time_quantum; ///< Time slice (quantum) allocated to each process before switching

public:
    /**
     * @brief Construct a new SchedulerRR object with a specified time quantum.
     * @param time_quantum The time slice for Round-Robin execution.
     */
    SchedulerRR(int time_quantum = 10);

    /**
     * @brief Destroy the SchedulerRR object.
     */
    ~SchedulerRR() override;

    /**
     * @brief Initializes the scheduler with a list of processes.
     *        Stores processes for scheduling.
     * @param process_list The list of processes in the simulation.
     */
    void init(std::vector<PCB>& process_list) override;

    /**
     * @brief Simulates the Round-Robin Scheduling Algorithm.
     *        - Each process gets a time slice (quantum).
     *        - If a process does not finish within its quantum, it is placed back in the queue.
     *        - Processes are executed in a cyclic order until all are completed.
     */
    void simulate() override;

    /**
     * @brief Prints the results of the scheduling simulation.
     *        Outputs the turnaround time and waiting time for each process,
     *        as well as the average turnaround and waiting times.
     */
    void print_results() override;
};

#endif // ASSIGN3_SCHEDULER_RR_H
