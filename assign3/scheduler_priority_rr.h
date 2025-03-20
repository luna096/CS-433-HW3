#ifndef ASSIGN3_SCHEDULER_PRIORITY_RR_H
#define ASSIGN3_SCHEDULER_PRIORITY_RR_H

#include "scheduler.h"
#include <vector>
#include <queue>
#include <map>

/**
 * @class SchedulerPriorityRR
 * @brief Implements the Priority Round-Robin (RR) Scheduling Algorithm.
 *
 * This scheduling algorithm first sorts processes based on priority, 
 * then applies Round-Robin scheduling within each priority level.
 * - Higher priority processes (higher numerical values) execute first.
 * - If multiple processes share the same priority, they are scheduled 
 *   using Round-Robin with a fixed time quantum.
 */
class SchedulerPriorityRR : public Scheduler {
private:
    std::map<int, std::queue<PCB*>> priority_queues; ///< Map of priority levels to process queues
    int time_quantum; ///< Time quantum for Round-Robin execution

public:
    /**
     * @brief Construct a new SchedulerPriorityRR object with a specified time quantum.
     * @param time_quantum The time slice for Round-Robin execution within priority levels.
     */
    SchedulerPriorityRR(int time_quantum = 10);

    /**
     * @brief Destroy the SchedulerPriorityRR object.
     */
    ~SchedulerPriorityRR() override;

    /**
     * @brief Initializes the scheduler with a list of processes.
     *        Organizes processes into different priority queues.
     * @param process_list The list of processes in the simulation.
     */
    void init(std::vector<PCB>& process_list) override;

    /**
     * @brief Simulates the Priority Round-Robin Scheduling Algorithm.
     *        - Processes execute in order of priority.
     *        - Within the same priority level, Round-Robin is applied.
     */
    void simulate() override;

    /**
     * @brief Prints the results of the scheduling simulation.
     *        Outputs the turnaround time and waiting time for each process,
     *        as well as the average turnaround and waiting times.
     */
    void print_results() override;
};

#endif // ASSIGN3_SCHEDULER_PRIORITY_RR_H
