#include "scheduler_priority_rr.h"
#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

// Constructor
SchedulerPriorityRR::SchedulerPriorityRR(int quantum) : time_quantum(quantum) {}

// Destructor
SchedulerPriorityRR::~SchedulerPriorityRR() {}

// Initialize the scheduler with the given list of processes
void SchedulerPriorityRR::init(std::vector<PCB>& process_list) {
    for (auto& process : process_list) {
        priority_queues[process.priority].push(&process);
    }
}

// Simulate the Priority Round-Robin scheduling algorithm
void SchedulerPriorityRR::simulate() {
    int current_time = 0;

    for (auto it = priority_queues.rbegin(); it != priority_queues.rend(); ++it) {
        queue<PCB*> process_queue = it->second;
        vector<PCB*> process_list;

        // Extract processes into a vector and initialize remaining times
        vector<int> remaining_time;
        while (!process_queue.empty()) {
            PCB* process = process_queue.front();
            process_queue.pop();
            process_list.push_back(process);
            remaining_time.push_back(process->burst_time);
        }

        int total_processes = process_list.size();
        bool done;

        do {
            done = true;
            for (int i = 0; i < total_processes; i++) {
                PCB* process = process_list[i];

                if (remaining_time[i] > 0) {
                    done = false;
                    int exec_time = min(time_quantum, remaining_time[i]);
                    remaining_time[i] -= exec_time;
                    current_time += exec_time;

                    if (remaining_time[i] == 0) {
                        process->turnaround_time = current_time;
                        process->waiting_time = process->turnaround_time - process->burst_time;
                    }
                }
            }
        } while (!done);

        // Push the completed processes back into the queue
        for (auto& process : process_list) {
            priority_queues[it->first].push(process);
        }
    }
}

// Print the results of the simulation
void SchedulerPriorityRR::print_results() {
    int total_turnaround = 0, total_waiting = 0;
    int num_processes = 0;

    for (auto it = priority_queues.rbegin(); it != priority_queues.rend(); ++it) {
        queue<PCB*> process_queue = it->second;

        while (!process_queue.empty()) {
            PCB* process = process_queue.front();
            process_queue.pop();

            cout << process->name << " turn-around time = " << process->turnaround_time
                 << ", waiting time = " << process->waiting_time << endl;

            total_turnaround += process->turnaround_time;
            total_waiting += process->waiting_time;
            num_processes++;
        }
    }

    // Fix: Prevent division by zero
    if (num_processes > 0) {
        cout << "Average turn-around time = " << (double)total_turnaround / num_processes
             << ", Average waiting time = " << (double)total_waiting / num_processes << endl;
    } else {
        cout << "Error: No processes available for calculating averages.\n";
    }
}