#include "scheduler_sjf.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Constructor
SchedulerSJF::SchedulerSJF() {}

// Destructor
SchedulerSJF::~SchedulerSJF() {}

// Initialize the scheduler with the given list of processes
void SchedulerSJF::init(std::vector<PCB>& process_list) {
    processes = process_list;
    sort(processes.begin(), processes.end(), [](const PCB &a, const PCB &b) {
        return a.burst_time < b.burst_time;
    });
}

// Simulate the SJF scheduling algorithm
void SchedulerSJF::simulate() {
    int current_time = 0;
    for (auto& process : processes) {
        process.waiting_time = current_time;
        process.turnaround_time = current_time + process.burst_time;
        current_time += process.burst_time;
    }
}

// Print the results of the simulation
void SchedulerSJF::print_results() {
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