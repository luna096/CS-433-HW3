#pragma once
#include <iostream>
#include <string>
using namespace std;

/**
 * @brief A process control block (PCB) representing a process in the system.
 */
class PCB {
public:
    // Name of the process
    string name;
    // Unique process ID
    unsigned int id;
    // Priority (higher number = higher priority)
    unsigned int priority;
    // CPU burst time
    unsigned int burst_time;
    // Arrival time
    unsigned int arrival_time;
    // **Newly added**: Turnaround time
    unsigned int turnaround_time;
    // **Newly added**: Waiting time
    unsigned int waiting_time;

    /**
     * @brief Construct a new PCB object
     * @param name: process name
     * @param id: process ID
     * @param priority: priority value (1-50, higher means higher priority)
     * @param burst_time: CPU burst time
     */
    PCB(string name, unsigned int id = 0, unsigned int priority = 1, unsigned int burst_time = 0)
        : name(name), id(id), priority(priority), burst_time(burst_time), arrival_time(0),
          turnaround_time(0), waiting_time(0) {}

    /**
     * @brief Destroy the PCB object.
     */
    ~PCB() {}

    /**
     * @brief Print the PCB object.
     */
    void print() {
        cout << "Process " << id << ": " << name << " has priority " << priority 
             << " and burst time " << burst_time << endl;
    }
};