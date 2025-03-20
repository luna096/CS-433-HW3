#include "scheduler_fcfs.h"
#include <iostream>
#include <vector>

using namespace std;

// Constructor: Initializes the FCFS scheduler
SchedulerFCFS::SchedulerFCFS() {}

// Destructor: Cleans up resources (if any)
SchedulerFCFS::~SchedulerFCFS() {}

// Initialize the scheduler with the given list of processes
void SchedulerFCFS::init(std::vector<PCB>& process_list) {
    processes = process_list; // Store the list of processes in the scheduler
}

// Simulate the First-Come, First-Served (FCFS) scheduling algorithm
void SchedulerFCFS::simulate() {
    int current_time = 0; // Track the current time in the CPU

    // Iterate through each process in the order they arrive
    for (auto& process : processes) {
        process.waiting_time = current_time; // Waiting time is the current time before execution
        process.turnaround_time = current_time + process.burst_time; // Turnaround time is total time from arrival
        current_time += process.burst_time; // Move time forward by the process's burst duration
    }
}

// Print the results of the FCFS scheduling simulation
void SchedulerFCFS::print_results() {
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
