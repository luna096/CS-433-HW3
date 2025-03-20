#include "scheduler_fcfs.h"
#include <iostream>
#include <vector>

using namespace std;

// Constructor
SchedulerFCFS::SchedulerFCFS() {}

// Destructor
SchedulerFCFS::~SchedulerFCFS() {}

// Initialize the scheduler with the given list of processes
void SchedulerFCFS::init(std::vector<PCB>& process_list) {
    processes = process_list; // Store the processes
}

// Simulate the FCFS scheduling algorithm
void SchedulerFCFS::simulate() {
    int current_time = 0;
    for (auto& process : processes) {
        process.waiting_time = current_time;
        process.turnaround_time = current_time + process.burst_time;
        current_time += process.burst_time;
    }
}

// Print the results of the simulation
void SchedulerFCFS::print_results() {
    int total_turnaround = 0, total_waiting = 0;
    int num_processes = processes.size();

    for (const auto& process : processes) {
        cout << process.name << " turn-around time = " << process.turnaround_time
             << ", waiting time = " << process.waiting_time << endl;
        total_turnaround += process.turnaround_time;
        total_waiting += process.waiting_time;
    }

    cout << "Average turn-around time = " << (double)total_turnaround / num_processes
         << ", Average waiting time = " << (double)total_waiting / num_processes << endl;
}