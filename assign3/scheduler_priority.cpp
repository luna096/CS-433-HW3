#include "scheduler_priority.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Constructor: Initializes the Priority Scheduler
SchedulerPriority::SchedulerPriority() {}

// Destructor: Cleans up resources (if any)
SchedulerPriority::~SchedulerPriority() {}

// Initialize the scheduler with the given list of processes
void SchedulerPriority::init(std::vector<PCB>& process_list) {
    processes = process_list;

    // Sort processes by priority (higher priority first)
    sort(processes.begin(), processes.end(), [](const PCB &a, const PCB &b) {
        return a.priority > b.priority; // Higher priority values get scheduled first
    });
}

// Simulate the Priority scheduling algorithm
void SchedulerPriority::simulate() {
    int current_time = 0; // Tracks the current time in the CPU

    // Iterate through processes in order of priority (pre-sorted in `init()`)
    for (auto& process : processes) {
        process.waiting_time = current_time; // Waiting time is the current time before execution
        process.turnaround_time = current_time + process.burst_time; // Turnaround time = waiting + execution time
        current_time += process.burst_time; // Move the time forward by burst time
    }
}

// Print the results of the Priority scheduling simulation
void SchedulerPriority::print_results() {
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
