#include "scheduler_rr.h"
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Constructor: Initializes the Round-Robin scheduler with a given time quantum.
SchedulerRR::SchedulerRR(int quantum) : time_quantum(quantum) {}

// Destructor: Cleans up resources (if any)
SchedulerRR::~SchedulerRR() {}

/**
 * @brief Initializes the scheduler with a list of processes.
 *        Stores the processes for scheduling.
 * @param process_list The list of processes in the simulation.
 */
void SchedulerRR::init(std::vector<PCB>& process_list) {
    processes = process_list;
}

/**
 * @brief Simulates the Round-Robin (RR) scheduling algorithm.
 *        - Each process gets a time slice (quantum).
 *        - If a process does not finish within its quantum, it is placed back in the queue.
 *        - Processes are executed in a cyclic order until all are completed.
 */
void SchedulerRR::simulate() {
    queue<PCB*> ready_queue;

    // Add all processes to the ready queue
    for (auto& process : processes) {
        ready_queue.push(&process);
    }

    int current_time = 0; // Tracks the current execution time
    vector<int> remaining_time(processes.size());

    // Initialize remaining burst times for each process
    for (size_t i = 0; i < processes.size(); i++) {
        remaining_time[i] = processes[i].burst_time;
    }

    // Execute processes in a Round-Robin fashion
    while (!ready_queue.empty()) {
        PCB* process = ready_queue.front(); // Get the process at the front of the queue
        ready_queue.pop(); // Remove it from the queue

        int process_index = process->id; // Identify the correct process index

        // Determine execution time: either full quantum or remaining burst time
        int exec_time = min(time_quantum, remaining_time[process_index]);
        remaining_time[process_index] -= exec_time;
        current_time += exec_time; // Update the global execution time

        // If the process has completed execution, calculate turnaround & waiting times
        if (remaining_time[process_index] == 0) {
            process->turnaround_time = current_time;
            process->waiting_time = process->turnaround_time - process->burst_time;
        } else {
            // If not finished, put it back into the queue for the next cycle
            ready_queue.push(process);
        }
    }
}

/**
 * @brief Prints the results of the scheduling simulation.
 *        Outputs the turnaround time and waiting time for each process,
 *        as well as the average turnaround and waiting times.
 */
void SchedulerRR::print_results() {
    int total_turnaround = 0, total_waiting = 0;
    int num_processes = processes.size();

    // Print individual turnaround and waiting times
    for (const auto& process : processes) {
        cout << process.name << " turn-around time = " << process.turnaround_time
             << ", waiting time = " << process.waiting_time << endl;
        total_turnaround += process.turnaround_time;
        total_waiting += process.waiting_time;
    }

    // Calculate and print averages, ensuring no division by zero
    if (num_processes > 0) {
        cout << "Average turn-around time = " << (double)total_turnaround / num_processes
             << ", Average waiting time = " << (double)total_waiting / num_processes << endl;
    } else {
        cout << "No processes to calculate averages.\n";
    }
}
