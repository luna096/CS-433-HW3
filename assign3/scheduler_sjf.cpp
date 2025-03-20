#include "scheduler_sjf.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Constructor: Initializes the Shortest Job First (SJF) scheduler
SchedulerSJF::SchedulerSJF() {}

// Destructor: Cleans up resources (if any)
SchedulerSJF::~SchedulerSJF() {}

/**
 * @brief Initializes the scheduler with a list of processes.
 *        - Stores the processes for scheduling.
 *        - Sorts processes by burst time (shortest first) to implement SJF.
 * @param process_list The list of processes in the simulation.
 */
void SchedulerSJF::init(std::vector<PCB>& process_list) {
    processes = process_list;

    // Sort processes in ascending order based on burst time (Shortest Job First)
    sort(processes.begin(), processes.end(), [](const PCB &a, const PCB &b) {
        return a.burst_time < b.burst_time; // Shortest burst time comes first
    });
}

/**
 * @brief Simulates the Shortest Job First (SJF) scheduling algorithm.
 *        - The process with the shortest burst time is executed first.
 *        - Turnaround and waiting times are calculated for each process.
 */
void SchedulerSJF::simulate() {
    int current_time = 0; // Tracks the current execution time

    // Execute processes in order of shortest burst time first
    for (auto& process : processes) {
        process.waiting_time = current_time; // Waiting time = time spent waiting before execution
        process.turnaround_time = current_time + process.burst_time; // Turnaround time = completion time
        current_time += process.burst_time; // Move the time forward by the process's burst time
    }
}

/**
 * @brief Prints the results of the scheduling simulation.
 *        Outputs turnaround time and waiting time for each process,
 *        as well as the average turnaround and waiting times.
 */
void SchedulerSJF::print_results() {
    int total_turnaround = 0, total_waiting = 0;
    int num_processes = processes.size();

    // Display turnaround and waiting time for each process
    for (const auto& process : processes) {
        cout << process.name << " turn-around time = " << process.turnaround_time
             << ", waiting time = " << process.waiting_time << endl;
        total_turnaround += process.turnaround_time; // Sum turnaround times for average calculation
        total_waiting += process.waiting_time; // Sum waiting times for average calculation
    }

    // Calculate and print average turnaround and waiting times
    cout << "Average turn-around time = " << (double)total_turnaround / num_processes
         << ", Average waiting time = " << (double)total_waiting / num_processes << endl;
}
