#include "scheduler_rr.h"
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Constructor
SchedulerRR::SchedulerRR(int quantum) : time_quantum(quantum) {}

// Destructor
SchedulerRR::~SchedulerRR() {}

// Initialize the scheduler with the given list of processes
void SchedulerRR::init(std::vector<PCB>& process_list) {
    processes = process_list;
}

// Simulate the Round-Robin scheduling algorithm
void SchedulerRR::simulate() {
    queue<PCB*> ready_queue;
    for (auto& process : processes) {
        ready_queue.push(&process);
    }

    int current_time = 0;
    vector<int> remaining_time(processes.size());

    // Initialize remaining burst times
    for (size_t i = 0; i < processes.size(); i++) {
        remaining_time[i] = processes[i].burst_time;
    }

    while (!ready_queue.empty()) {
        PCB* process = ready_queue.front();
        ready_queue.pop();

        int process_index = process->id; // Identify the correct process index

        int exec_time = min(time_quantum, remaining_time[process_index]);
        remaining_time[process_index] -= exec_time;
        current_time += exec_time;

        // If the process is finished, update turnaround time
        if (remaining_time[process_index] == 0) {
            process->turnaround_time = current_time;
            process->waiting_time = process->turnaround_time - process->burst_time;
        } else {
            // Otherwise, put it back in the queue
            ready_queue.push(process);
        }
    }
}

// Print the results of the simulation
void SchedulerRR::print_results() {
    int total_turnaround = 0, total_waiting = 0;
    int num_processes = processes.size();

    for (const auto& process : processes) {
        cout << process.name << " turn-around time = " << process.turnaround_time
             << ", waiting time = " << process.waiting_time << endl;
        total_turnaround += process.turnaround_time;
        total_waiting += process.waiting_time;
    }

    if (num_processes > 0) {
        cout << "Average turn-around time = " << (double)total_turnaround / num_processes
             << ", Average waiting time = " << (double)total_waiting / num_processes << endl;
    } else {
        cout << "No processes to calculate averages.\n";
    }
}